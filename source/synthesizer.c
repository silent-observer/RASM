#include "synthesizer.h"

#define DEFAULT_SIZE 500
#define MEMORY_DEPTH "1024"

static const char *header = "DEPTH = " MEMORY_DEPTH ";\n"
                            "WIDTH = 16;\n"
                            "ADDRESS_RADIX = HEX;\n"
                            "DATA_RADIX = HEX;\n"
                            "CONTENT\n"
                            "BEGIN\n";
static const char *end =    "END;";

unsigned short synthArg(bool isIType, Argument arg) {
    switch (arg.type) {
        case A_ZERO: return 0;
        case A_REGISTER:
            if (arg.rType != REG_SP || isIType)
                return arg.rType;
            else {
                printf("Cannot use SP in not I-type instruction!\n");
                exit(1);
            }
        case A_CONSTANT: return 4;
        case A_ABSOLUTE: return 5;
        case A_ADDRESSED: return 6;
        case A_STACK: return 7;
        case A_STRING: printf("Cannot use strings as arguments in not DW instruction!\n");
                       exit(1);
        case A_MACRO_ARG: printf("Strange error, addresser didn't catch macro parameter.\n"); exit(2);
        case A_ID_HIGH:
        case A_ID_LOW:
        case A_IDENTIFIER: printf("Very Strange Error. How identifier even got here?..\n");
                           exit(2);
        case A_SUM_HIGH:
        case A_SUM_LOW:
        case A_SUM:
        case A_INDEX:   printf("Very Strange Error. How sum even got here?..\n");
                        exit(2);
        case A_FASTMEM: printf("Very Strange Error. synthArg shouldn't be used on fastmem argument\n");
                        exit(2);
    }
    return 0;
}

unsigned short synthArgShort(Argument arg) {
    if (arg.type != A_ZERO && arg.type != A_REGISTER) {
        printf("Cannot use non-register and not-zero argument "
               "in A-type instruction as second operand!\n");
        exit(1);
    }
    if (arg.type == A_REGISTER)
        if (arg.rType != REG_SP)
            return arg.rType;
        else {
            printf("Cannot use SP in not I-type instruction!\n");
            exit(1);
        }
    else
        return 0;
}

DString synthesize(InstructionList list) {
    DString result = newDArray(DString)(DEFAULT_SIZE);
    daAppendN(DString)(&result, header, strlen(header));
    char buffer[10];
    char *lastFilename = NULL;
    for (InstructionListNode *n = list.start; n; n = n->next) {
        Instruction instr = n->data;
        if (lastFilename != instr.filename) {
            lastFilename = instr.filename;
            daAppendN(DString)(&result, "-- \"", 4);
            daAppendN(DString)(&result, lastFilename, strlen(lastFilename));
            daAppendN(DString)(&result, "\"\n", 2);
        }
        int startSize = result.size;
        sprintf(buffer, "%03lx: ", instr.address/2);
        daAppendN(DString)(&result, buffer, strlen(buffer));
        unsigned short val;
        bool synth[3] = {true, true, true};
        if (instr.isMacro && instr.mType == M_DW) {
            if (instr.args.data[0].type == A_CONSTANT || instr.args.data[0].type == A_ZERO)
                val = instr.args.data[0].iVal;
            else {
                bool secondC = false;
                val = 0;
                for (char *c = instr.args.data[0].text+1; *c && *c != '\"'; c++) {
                    if (*c != '\\') {
                        if (!secondC)
                            val = *c;
                        else
                            val |= *c << 8;
                    } else {
                        unsigned char escape = 0;
                        switch (*++c) {
                            case '\\': escape = '\\'; break;
                            case '\"': escape = '\"'; break;
                            case 'a': escape = '\a'; break;
                            case 'b': escape = '\b'; break;
                            case 'n': escape = '\n'; break;
                            case 't': escape = '\t'; break;
                            case 'v': escape = '\v'; break;
                            case '0': escape = '\0'; break;
                            case 'x': {
                                unsigned int value = 0;
                                c++;
                                while ((*c >= '0' && *c <= '9') ||
                                       (*c >= 'a' && *c <= 'f') ||
                                       (*c >= 'A' && *c <= 'F')) {
                                    value *= 16;
                                    if (*c >= '0' && *c <= '9')
                                        value += *c++ - '0';
                                    else if (*c >= 'a' && *c <= 'f')
                                        value += *c++ - 'a' + 10;
                                    else if (*c >= 'A' && *c <= 'F')
                                        value += *c++ - 'A' + 10;
                                }
                                escape = value & 0xFF;
                                c--;
                                break;
                            }
                            default: break;
                        }
                        if (!secondC)
                            val = escape;
                        else
                            val |= escape << 8;

                    }
                    if (secondC) {
                        sprintf(buffer, "%04x ", val);
                        daAppendN(DString)(&result, buffer, strlen(buffer));
                    }
                    secondC = !secondC;
                }
                if (!secondC)
                    val = '\0';
            }
        } else if (instr.iType >= I_ADD && instr.iType <= I_XOR) {
            val = 0x0000;
            val |= synthArg(false, instr.args.data[0]) << 9;
            val |= (instr.iType - I_ADD) << 5;
            val |= synthArgShort(instr.args.data[1]) << 3;
            val |= synthArg(false, instr.args.data[2]);
        } else if (instr.iType == I_NOT) {
            val = 0x0000;
            val |= synthArg(false, instr.args.data[0]) << 9;
            val |= (I_NOT - I_ADD) << 5;
            val |= synthArg(false, instr.args.data[1]);
        } else if (instr.iType >= I_MOV8LL && instr.iType <= I_MOV8HH) {
            val = 0x8000;
            val |= synthArg(false, instr.args.data[0]) << 9;
            val |= ((instr.iType - I_MOV8LL) / 2) << 8;
            val |= synthArg(false, instr.args.data[1]) << 5;
            val |= ((instr.iType - I_MOV8LL) % 2) << 4;
        } else if (instr.iType == I_JMP) {
            val = 0xC000 | ((instr.args.data[0].iVal >> 1) & 0x1FFF);
            synth[0] = false;
        } else if (instr.iType == I_JMR) {
            val = 0x9000;
            val |= synthArg(false, instr.args.data[0]) << 9;
        } else if (instr.iType >= I_ADDI && instr.iType <= I_XORI) {
            if (instr.args.data[0].type != instr.args.data[2].type) {
                printf("Cannot use source and destination of different types in I-type instruction!\n");
                exit(1);
            }
            val = 0x4000;
            val |= ((instr.iType - I_ADDI) & 0x3) << 12;
            val |= synthArg(true, instr.args.data[0]) << 9;
            val |= ((instr.iType - I_ADDI) >> 2) << 8;
            val |= instr.args.data[1].iVal & 0x00FF;
            synth[1] = false;
        } else if (instr.iType == I_LDI) {
            val = 0x4000;
            val |= ((instr.iType - I_ADDI) & 0x6) << 12;
            val |= synthArg(true, instr.args.data[1]) << 9;
            val |= ((instr.iType - I_ADDI) & 0x1) << 8;
            val |= instr.args.data[0].iVal & 0x00FF;
            synth[0] = false;
        } else if (instr.iType >= I_LSHI && instr.iType <= I_RRTI) {
            val = 0x1000;
            val |= synthArg(false, instr.args.data[0]) << 9;
            val |= (instr.iType - I_LSHI) << 7;
            val |= synthArg(false, instr.args.data[2]) << 4;
            val |= instr.args.data[1].iVal & 0x000F;
            synth[1] = false;
        } else if (instr.iType == I_JFC) {
            val = 0x2000;
            val |= (instr.args.data[1].iVal & 0x0003) << 9;
            val |= (instr.args.data[0].iVal >> 1) & 0x00FF;
            synth[0] = false;
            synth[1] = false;
        } else if (instr.iType == I_JFS) {
            val = 0x2800;
            val |= (instr.args.data[1].iVal & 0x0003) << 9;
            val |= (instr.args.data[0].iVal >> 1) & 0x00FF;
            synth[0] = false;
            synth[1] = false;
        } else if (instr.iType == I_LOAD) {
            val = 0x2100;
            val |= synthArg(false, instr.args.data[1]) << 9;
            val |= instr.args.data[0].iVal & 0x007F;
            synth[0] = false;
        } else if (instr.iType == I_SAVE) {
            val = 0x2180;
            val |= synthArg(false, instr.args.data[0]) << 9;
            val |= instr.args.data[1].iVal & 0x007F;
            synth[1] = false;
        } else if (instr.iType == I_PUSH || instr.iType == I_POP) {
            val = 0x3000;
            val |= synthArg(false, instr.args.data[0]) << 9;
            val |= (instr.iType - I_PUSH) << 7;
        } else if (instr.iType == I_SVPC) {
            val = 0x3000;
            val |= (instr.iType - I_PUSH) << 7;
            val |= instr.args.data[0].iVal & 0x007F;
            synth[0] = false;
        } else if (instr.iType == I_RET) {
            val = 0x3000;
            val |= (instr.iType - I_PUSH) << 7;
        }
        sprintf(buffer, "%04x ", val);
        daAppendN(DString)(&result, buffer, strlen(buffer));
        for (int i = 0; i < instr.args.size; i++) {
            if (synth[i] && instr.args.data[i].type == A_ABSOLUTE) {
                sprintf(buffer, "%04lx ", (instr.args.data[i].iVal & 0xFFFF0000) >> 16);
                daAppendN(DString)(&result, buffer, strlen(buffer));
            }
            if (synth[i] && !(instr.isMacro == true && instr.mType == M_DW) &&
                (instr.args.data[i].type == A_CONSTANT ||
                 instr.args.data[i].type == A_ABSOLUTE ||
                 instr.args.data[i].type == A_STACK)) {
                sprintf(buffer, "%04lx ", instr.args.data[i].iVal & 0xFFFF);
                daAppendN(DString)(&result, buffer, strlen(buffer));
            }
        }
        daAppendN(DString)(&result, ";", 1);
        if (result.size - startSize < 30) {
            daAppendN(DString)(&result, "                              ", 30 - (result.size - startSize));
        }
        daAppendN(DString)(&result, " -- ", 4);
        sprintf(buffer, "%3d: ", instr.line);
        daAppendN(DString)(&result, buffer, strlen(buffer));
        daAppendN(DString)(&result, instr.source, strlen(instr.source));
    }
    daAppendN(DString)(&result, end, strlen(end));
    daAppend(DString)(&result, "");
    return result;
}

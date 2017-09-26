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
        case A_NO_ARG: case A_ZERO: return 0;
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
        case A_IDENTIFIER: printf("Very Strange Error. How identifier even got here?..\n");
                           exit(2);
    }
    return 0;
}

unsigned short synthArgShort(Argument arg) {
    if (arg.type != A_NO_ARG && arg.type != A_ZERO && arg.type != A_REGISTER) {
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
    for (InstructionListNode *n = list.start; n; n = n->next) {
        Instruction instr = n->data;
		sprintf(buffer, "%03x: ", instr.address);
		daAppendN(DString)(&result, buffer, strlen(buffer));
        unsigned short val;
        bool synth[3] = {true, true, true};
        if (instr.isMacro && instr.mType == M_DW) {
            if (instr.args[0].type == A_CONSTANT)
                val = instr.args[0].iVal;
            else {
                for (char *c = instr.args[0].text+1; *c && *c != '\"'; c++)
                    if (*c != '\\') {
                        sprintf(buffer, "%04x ", *c);
                        daAppendN(DString)(&result, buffer, strlen(buffer));
                    } else {
                        switch (*++c) {
                            case '\\': sprintf(buffer, "%04x ", '\\'); break;
                            case '\"': sprintf(buffer, "%04x ", '\"'); break;
                            case 'a': sprintf(buffer, "%04x ", '\a'); break;
                            case 'b': sprintf(buffer, "%04x ", '\b'); break;
                            case 'n': sprintf(buffer, "%04x ", '\n'); break;
                            case 't': sprintf(buffer, "%04x ", '\t'); break;
                            case 'v': sprintf(buffer, "%04x ", '\v'); break;
                            case '0': sprintf(buffer, "%04x ", '\0'); break;
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
                                sprintf(buffer, "%04x ", value & 0xFF);
                                c--;
                                break;
                            }
                            default: break;
                        }
                        daAppendN(DString)(&result, buffer, strlen(buffer));
                    }
                val = '\0';
            }
        } else if (instr.iType >= I_ADD && instr.iType <= I_XOR) {
            val = 0x0000;
            val |= synthArg(false, instr.args[0]) << 9;
            val |= (instr.iType - I_ADD) << 5;
            val |= synthArgShort(instr.args[1]) << 3;
            val |= synthArg(false, instr.args[2]);
        } else if (instr.iType == I_NOT) {
            val = 0x0000;
            val |= synthArg(false, instr.args[0]) << 9;
            val |= (I_NOT - I_ADD) << 5;
            val |= synthArg(false, instr.args[1]);
        } else if (instr.iType == I_JMP) {
            val = 0x8000 | (instr.args[0].iVal & 0x7FFF);
            synth[0] = false;
        } else if (instr.iType >= I_ADDI && instr.iType <= I_LDI) {
            val = 0x4000;
            val |= ((instr.iType - I_ADDI) & 0x6) << 12;
            val |= synthArg(true, instr.args[0]) << 9;
            val |= ((instr.iType - I_ADDI) & 0x1) << 8;
            val |= instr.args[1].iVal & 0x00FF;
            synth[1] = false;
        } else if (instr.iType >= I_LSHI && instr.iType <= I_RRTI) {
            val = 0x1000;
            val |= synthArg(false, instr.args[0]) << 9;
            val |= (instr.iType - I_LSHI) << 7;
            val |= synthArg(false, instr.args[2]) << 4;
            val |= instr.args[1].iVal & 0x000F;
            synth[1] = false;
        } else if (instr.iType >= I_JFC && instr.iType <= I_JFS) {
            val = 0x2000;
            val |= (instr.iType - I_JFC) << 10;
            val |= (instr.args[1].iVal & 0x0003) << 8;
            val |= instr.args[0].iVal & 0x00FF;
            synth[0] = false;
            synth[1] = false;
        } else if (instr.iType >= I_FLC && instr.iType <= I_FLS) {
            val = 0x2000;
            val |= (instr.iType - I_JFC) << 10;
            val |= (instr.args[0].iVal & 0x0003) << 8;
            synth[0] = false;
        } else if (instr.iType >= I_PUSH && instr.iType <= I_RET) {
            val = 0x3000;
            val |= synthArg(false, instr.args[0]) << 9;
            val |= (instr.iType - I_PUSH) << 7;
        }
        sprintf(buffer, "%04x ", val);
        daAppendN(DString)(&result, buffer, strlen(buffer));
        for (int i = 0; i < 3; i++) {
			if (synth[i] && instr.args[i].type == A_ABSOLUTE) {
                sprintf(buffer, "%04lx ", (instr.args[i].iVal & 0xFFFF0000) >> 16);
                daAppendN(DString)(&result, buffer, strlen(buffer));
            }
            if (synth[i] &&
                (instr.args[i].type == A_CONSTANT ||
                 instr.args[i].type == A_ABSOLUTE ||
                 instr.args[i].type == A_STACK)) {
                sprintf(buffer, "%04lx ", instr.args[i].iVal & 0xFFFF);
                daAppendN(DString)(&result, buffer, strlen(buffer));
            }
        }
		daAppendN(DString)(&result, ";\n", 2);
    }
    daAppendN(DString)(&result, end, strlen(end));
    daAppend(DString)(&result, "");
    return result;
}

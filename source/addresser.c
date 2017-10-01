#include "ast.h"
#include "cmpAndDstrFuncs.h"

static unsigned int getArgSize(Argument arg) {
    switch (arg.type) {
        case A_ZERO:
        case A_ADDRESSED:
        case A_REGISTER: return 0;
        case A_STACK:
        case A_ID_HIGH:
        case A_ID_LOW:
        case A_CONSTANT: return 1;
        case A_ABSOLUTE: return 2;
        case A_IDENTIFIER: printf("Cannot use identifier '%s' as argument, use '%s.h' or '%s.l' instead.\n", 
            arg.text, arg.text, arg.text); exit(1);
        case A_STRING: printf("Cannot use string %s in not DW instruction.\n", arg.text); exit(1);
        case A_MACRO_ARG: printf("Macro definition is not supported yet.\n"); exit(3);
    }
    printf("I don't understand how control can reach here.\nNevermind.\n"); 
    exit(1);
}

static unsigned int getInstrSize(Instruction instr) {
    unsigned int size = 1;
    if (!instr.isMacro)
        switch(instr.iType) {
            case I_ADD: case I_ADC: case I_SUB: case I_SBC: // A-type
            case I_MUL: case I_MLL: case I_SGN: case I_RAS:
            case I_LSH: case I_RSH: case I_LRT: case I_RRT:
            case I_AND: case I_OR:  case I_XOR:
                size += getArgSize(instr.args.data[0]);
                size += getArgSize(instr.args.data[2]);
                break;
            case I_NOT:
                size += getArgSize(instr.args.data[0]);
                size += getArgSize(instr.args.data[1]);
                break;
            case I_JMP: // J-type
                break;
            case I_ADDI: case I_ADCI: case I_SUBI: case I_SBCI: // I-type
            case I_ANDI: case I_ORI:  case I_XORI:
                size += getArgSize(instr.args.data[0]);
                size += getArgSize(instr.args.data[2]);
                break;
            case I_LDI:
                size += getArgSize(instr.args.data[1]);
                break;
            case I_LSHI: case I_RSHI: case I_LRTI: case I_RRTI: // SI-type
                size += getArgSize(instr.args.data[0]);
                size += getArgSize(instr.args.data[2]);
                break;
            case I_JFC: case I_JFS: case I_FLC: case I_FLS: // F-type
                break;
            case I_PUSH: case I_POP: // SP-type
                size += getArgSize(instr.args.data[0]);
                break;
            case I_SVPC: case I_RET:
                break;
        }
    else
        switch (instr.mType) {
            case M_MOV:
                size += getArgSize(instr.args.data[0]);
                size += getArgSize(instr.args.data[1]);
                break;
            case M_JVC: case M_JVS: case M_JNE: case M_JEQ:
            case M_JGE: case M_JLT: case M_JCC: case M_JCS:
                break;
            case M_CALL:
                size++;
                break;
            case M_HALT:
                break;
            case M_DW: 
            {
                if (instr.args.data[0].type != A_STRING)
                    break;
                for (char *c = instr.args.data[0].text; *c;) {
                    if (*c == '\\') {
                        c++;
                        if (*c++ != 'x')
                            size++;
                        else {
                            while ((*c >= '0' && *c <= '9') ||
                                    (*c >= 'A' && *c <= 'F') ||
                                    (*c >= 'a' && *c <= 'f'))
                                c++;
                            size++;
                        }
                    } else { 
                        size++; c++;
                    }
                }
                size -= 2;
                break;
            }
            case M_LABEL: case M_LABEL_ASSIGN:
                size = 0;
                break;
            case M_USER_MACRO: case M_INCLUDE: printf("Macro definition is not supported yet.\n"); exit(2);
        }
    return size;
}

LabelTable addAddresses(InstructionList *list) {
    LabelTable labels = newRBT(LabelTable)(&cmpStr, &dstrLabelTableEntry);
    unsigned long int currAddr = 0x00000000;
    for (InstructionListNode *n = list->start; n;) {
        n->data.address = currAddr;
        currAddr += getInstrSize(n->data);
        if (n->data.isMacro && (n->data.mType == M_LABEL || 
                                n->data.mType == M_LABEL_ASSIGN)) {
            if (n->data.mType == M_LABEL)
                rbtSet(LabelTable)(&labels, strdup(n->data.args.data[0].text), currAddr);
            else
                rbtSet(LabelTable)(&labels, strdup(n->data.args.data[0].text), n->data.args.data[1].iVal);
            if (n->next) {
                n = n->next;
                llRemove(InstructionList)(list, n->prev);
            }
            else break;
        } else n = n->next;
    }
    return labels;
}
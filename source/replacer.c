#include "ast.h"
#include "error.h"

static Argument replaceLabel(Instruction instr, Argument arg, LabelTable labels) {
    if (arg.type == A_SUM || arg.type == A_SUM_HIGH || arg.type == A_SUM_LOW || arg.type == A_INDEX) {
        long int value = 0;
        for (int i = 0; i < arg.sum->size; i++)
            if (arg.sum->data[i].type == A_IDENTIFIER ||
                arg.sum->data[i].type == A_ID_HIGH ||
                arg.sum->data[i].type == A_ID_LOW)
                value += replaceLabel(instr, arg.sum->data[i], labels).iVal;
            else
                value += arg.sum->data[i].iVal;
        arg.iVal = value;
        if (arg.type == A_SUM_HIGH) arg.iVal = (arg.iVal & 0xFFFF0000) >> 16;
        else if (arg.type == A_SUM_LOW) arg.iVal &= 0xFFFF;

        if (arg.type == A_SUM || arg.type == A_SUM_HIGH || arg.type == A_SUM_LOW) arg.type = A_CONSTANT;
        else arg.type = A_ABSOLUTE;
        return arg;
    }
    LabelTableEntry entry = rbtGet(LabelTable)(labels, arg.text);
    test(!entry, "Unknown identifier %s!\n", arg.text);
    free(arg.text);
    if (instr.iType == I_JFC || instr.iType == I_JFS || instr.iType == I_JMP)
        arg.iVal = entry->value - (instr.address+1);
    else
        arg.iVal = entry->value;
    if (arg.type == A_ID_HIGH)
        arg.iVal = (arg.iVal & 0xFFFF0000) >> 16;
    else if (arg.type == A_ID_LOW)
        arg.iVal &= 0xFFFF;
    if (arg.type == A_IDENTIFIER ||
        arg.type == A_ID_HIGH ||
        arg.type == A_ID_LOW)
        arg.type = A_CONSTANT;
    if (arg.iVal == 0)
        arg.type = A_ZERO;
    return arg;
}

static void replaceMacro(InstructionList *list, InstructionListNode *n) {
    n->data.isMacro = false;
    if (n->data.mType == M_NOP) {
        daSetSize(ArgumentDArray)(&n->data.args, 3);
        n->data.iType = I_ADD;
        n->data.args.data[0].type = A_ZERO;
        n->data.args.data[0].iVal = 0;
        n->data.args.data[1].type = A_ZERO;
        n->data.args.data[1].iVal = 0;
        n->data.args.data[2].type = A_ZERO;
        n->data.args.data[2].iVal = 0;
    } else if (n->data.mType == M_MOV) {
        daSetSize(ArgumentDArray)(&n->data.args, 3);
        n->data.iType = I_ADD;
        n->data.args.data[2] = n->data.args.data[1];
        n->data.args.data[1].type = A_ZERO;
        n->data.args.data[1].iVal = 0;
    } else if (n->data.mType >= M_JVC && n->data.mType <= M_JCS) {
        daSetSize(ArgumentDArray)(&n->data.args, 2);
        n->data.args.data[1].type = A_CONSTANT;
        switch (n->data.mType) {
            case M_JVC: case M_JVS:
                n->data.args.data[1].iVal = 0; break;
            case M_JNE: case M_JEQ:
                n->data.args.data[1].iVal = 1; break;
            case M_JGE: case M_JLT:
                n->data.args.data[1].iVal = 2; break;
            case M_JCC: case M_JCS:
                n->data.args.data[1].iVal = 3; break;
            default: break;
        }
        switch (n->data.mType) {
            case M_JVC: case M_JNE: case M_JGE: case M_JCC:
                n->data.iType = I_JFC; break;
            case M_JVS: case M_JEQ: case M_JLT: case M_JCS:
                n->data.iType = I_JFS; break;
            default: break;
        }
    } else if (n->data.mType == M_CALL) {
        Instruction instr;
        instr.source = strdup(n->data.source);
        instr.filename = n->data.filename;
        instr.line = n->data.line;
        instr.isMacro = false;
        instr.iType = I_JMP;
        instr.args = newDArray(ArgumentDArray)(1);
        daAppend(ArgumentDArray)(&instr.args, &n->data.args.data[0]);
        instr.address = n->data.address + 2;
        n->data.iType = I_SVPC;
        n->data.args.data[0].type = A_CONSTANT;
        n->data.args.data[0].iVal = 1;
        llInsertAfter(InstructionList)(list, n, instr);
    } else if (n->data.mType == M_HALT) {
        n->data.iType = I_JMP;
        n->data.args.data[0].type = A_CONSTANT;
        n->data.args.data[0].iVal = -1;
    } else if (n->data.mType == M_DW) {
        n->data.isMacro = true;
    }
}

void replaceLabelsAndMacros(InstructionList *list, LabelTable labels) {
    for (InstructionListNode *n = list->start; n; n = n->next) {
        if (n->data.isMacro)
            replaceMacro(list, n);
        for (int i = 0; i < n->data.args.size; i++) {
            if (n->data.args.data[i].type == A_IDENTIFIER ||
                n->data.args.data[i].type == A_ID_HIGH ||
                n->data.args.data[i].type == A_ID_LOW ||
                n->data.args.data[i].type == A_ABSOLUTE ||
                n->data.args.data[i].type == A_SUM ||
                n->data.args.data[i].type == A_SUM_HIGH ||
                n->data.args.data[i].type == A_SUM_LOW ||
                n->data.args.data[i].type == A_INDEX) {
                n->data.args.data[i] = replaceLabel(n->data, n->data.args.data[i], labels);
            }
        }
    }
}

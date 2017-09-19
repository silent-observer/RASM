#include "ast.h"
#include "error.h"

static Argument replaceLabel(Instruction instr, Argument arg, LabelTable labels) {
    LabelTableEntry entry = rbtGet(LabelTable)(labels, arg.text);
    test(!entry, "Unknown identifier %s!\n", arg.text);
    free(arg.text);
    if (instr.iType == I_JFC || instr.iType == I_JFS)
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
    return arg;
}

static void replaceMacro(InstructionList *list, InstructionListNode *n) {
    n->data.isMacro = false;
    if (n->data.mType == M_MOV) {
        n->data.iType = I_ADD;
        n->data.args[2] = n->data.args[1];
        n->data.args[1].type = A_ZERO;
        n->data.args[1].iVal = 0;
    } else if (n->data.mType >= M_JVC && n->data.mType <= M_JCS) {
        n->data.args[1].type = A_CONSTANT;
        switch (n->data.mType) {
            case M_JVC: case M_JVS:
                n->data.args[1].iVal = 0; break;
            case M_JNE: case M_JEQ:
                n->data.args[1].iVal = 1; break;
            case M_JGE: case M_JLT:
                n->data.args[1].iVal = 2; break;
            case M_JCC: case M_JCS:
                n->data.args[1].iVal = 3; break;
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
        instr.isMacro = false;
        instr.iType = I_JMP;
        instr.args[0] = n->data.args[0];
        memset(&instr.args[1], 0, sizeof(Argument)*2);
        instr.address = n->data.address + 1;
        n->data.iType = I_SVPC;
        memset(&n->data.args[0], 0, sizeof(Argument));
        llInsertAfter(InstructionList)(list, n, instr);
    } else if (n->data.mType == M_HALT) {
        n->data.iType = I_JMP;
        n->data.args[0].type = A_CONSTANT;
        n->data.args[0].iVal = n->data.address;
    } else if (n->data.mType == M_DW) {
        n->data.isMacro = true;
    }
}

void replaceLabelsAndMacros(InstructionList *list, LabelTable labels) {
    for (InstructionListNode *n = list->start; n; n = n->next) {
        if (n->data.isMacro)
            replaceMacro(list, n);
        for (int i = 0; i < 3; i++)
            if (n->data.args[i].type == A_IDENTIFIER ||
                n->data.args[i].type == A_ID_HIGH ||
                n->data.args[i].type == A_ID_LOW ||
                n->data.args[i].type == A_ABSOLUTE)
                n->data.args[i] = replaceLabel(n->data, n->data.args[i], labels);
    }
}

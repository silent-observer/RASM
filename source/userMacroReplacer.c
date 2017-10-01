#include "ast.h"
#include "error.h"

void replaceUserMacros(InstructionList *list, UserMacroTable userMacros);

static Instruction duplicateInstruction(Instruction instr) {
    ArgumentDArray args = newDArray(ArgumentDArray)(instr.args.size);
    for (int i = 0; i < instr.args.size; i++) {
        Argument a = instr.args.data[i];
        if (a.type == A_ABSOLUTE ||
            a.type == A_STRING ||
            a.type == A_IDENTIFIER ||
            a.type == A_ID_HIGH ||
            a.type == A_ID_LOW)
            a.text = strdup(a.text);
        daAppend(ArgumentDArray)(&args, &a);
    }
    instr.args = args;
    return instr;
}

static InstructionListNode *replaceUserMacro(InstructionList *list, InstructionListNode *n, 
        UserMacroTable userMacros) {
    if(n->data.args.size == 0 || n->data.args.data[0].type != A_IDENTIFIER) { 
        printf("Strange error which involves missing user macro name where it should be\n");
        exit(2);
    }
    UserMacroTableEntry entry = rbtGet(UserMacroTable)(userMacros, n->data.args.data[0].text);
    test(!entry, "Cannot find user macro $%s!\n", n->data.args.data[0].text);
    test(entry->value.paramTypes.size != n->data.args.size-1, 
        "Expected %d arguments in user macro $%s, but found %d.\n", 
        entry->value.paramTypes.size, entry->key, n->data.args.size-1);
    for (int i = 0; i < entry->value.paramTypes.size; i++) {
        bool isReg =    n->data.args.data[i+1].type == A_REGISTER;
        bool isMem =    n->data.args.data[i+1].type == A_ADDRESSED || 
                        n->data.args.data[i+1].type == A_ABSOLUTE ||
                        n->data.args.data[i+1].type == A_STACK;
        bool isImm =    n->data.args.data[i+1].type == A_CONSTANT ||
                        n->data.args.data[i+1].type == A_ZERO ||
                        n->data.args.data[i+1].type == A_IDENTIFIER ||
                        n->data.args.data[i+1].type == A_ID_HIGH ||
                        n->data.args.data[i+1].type == A_ID_LOW;
        bool canBeReg = entry->value.paramTypes.data[i] == P_REG ||
                        entry->value.paramTypes.data[i] == P_REG_MEM ||
                        entry->value.paramTypes.data[i] == P_REG_MEM_IMM;
        bool canBeMem = entry->value.paramTypes.data[i] == P_REG_MEM ||
                        entry->value.paramTypes.data[i] == P_REG_MEM_IMM;
        bool canBeImm = entry->value.paramTypes.data[i] == P_IMM ||
                        entry->value.paramTypes.data[i] == P_REG_MEM_IMM;
        bool isValid =  (isReg && canBeReg) ||
                        (isMem && canBeMem) ||
                        (isImm && canBeImm);
        test(!isValid, "Invalid argument %d type in macro %s.", i+1, entry->key);
    }
    InstructionList replacement = llDuplicate(InstructionList)(entry->value.instrs, &duplicateInstruction);
    for (InstructionListNode *node = replacement.start; node; node = node->next) {
        for (int i = 0; i < node->data.args.size; i++) {
            Argument *arg = &node->data.args.data[i];
            if (arg->type == A_MACRO_ARG)
                *arg = n->data.args.data[arg->iVal];
        }
    }
    replaceUserMacros(&replacement, userMacros);
    llInsertBeforeL(InstructionList)(list, n, replacement);
    InstructionListNode *result = n->next;
    llRemove(InstructionList)(list, n);
    return result;
}

void replaceUserMacros(InstructionList *list, UserMacroTable userMacros) {
    for (InstructionListNode *n = list->start; n; n = n->next) {
        if (n->data.isMacro && n->data.mType == M_USER_MACRO)
            n = replaceUserMacro(list, n, userMacros);
    }
}

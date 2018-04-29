#include <stdio.h>
#include "ast.h"
#include "y.tab.h"
#include "replacer.h"
#include "synthesizer.h"
#include "addresser.h"
#include "cmpAndDstrFuncs.h"
#include "userMacroReplacer.h"
#include "includeReplacer.h"

extern FILE* yyin;
extern int yylex();
extern int yyparse(InstructionList *list, UserMacroTable *userMacros, char *filename);
extern LabelTable labels;
//extern YYSTYPE yylval;
extern char *yytext;

void printLabel(LabelTableEntry entry) {
    printf("%s = %04lX\n", entry->key, entry->value);
}

void printArg(Argument a, bool isReplaced) {
    switch (a.type) {
        case A_REGISTER: switch (a.rType) {
                case REG_A: printf("A"); break;
                case REG_B: printf("B"); break;
                case REG_C: printf("C"); break;
                case REG_SP: printf("SP"); break;
            } break;
        case A_CONSTANT: printf(a.iVal < 1000? "%ld" : "%08lXh", a.iVal); break;
        case A_ADDRESSED: printf("*A"); break;
        case A_ABSOLUTE:    if (!isReplaced)
                                printf("*%s", a.text);
                            else
                                printf("*%08lXh", a.iVal);
                            break;
        case A_STACK: printf("[%ld]", a.iVal); break;
        case A_ZERO: printf("0"); break;
        case A_STRING: printf("%s", a.text); break;
        case A_IDENTIFIER: printf("%s", a.text); break;
        case A_ID_HIGH: printf("%s.h", a.text); break;
        case A_ID_LOW: printf("%s.l", a.text); break;
        case A_MACRO_ARG: printf("$%ld", a.iVal); break;
        case A_SUM_HIGH:
        case A_SUM_LOW: printf("(");
        case A_SUM: {
            for (int i = 0; i < a.sum->size; i++) {
                if (i != 0) printf("+");
                printArg(a.sum->data[i], isReplaced);
            }
            if (a.type == A_SUM_HIGH) printf(").h");
            else if (a.type == A_SUM_LOW) printf(").l");
            break;
        }
        case A_INDEX: {
            printArg(a.sum->data[a.sum->size-1], isReplaced); printf("[");
            for (int i = 0; i < a.sum->size-1; i++) {
                if (i != 0) printf("+");
                printArg(a.sum->data[i], isReplaced);
            }
            printf("]");
            break;
        }
        case A_FASTMEM: printf("@%ld", a.iVal); break;
    }
}

void printArgs(ArgumentDArray args, bool isReplaced) {
    for (int i = 0; i < args.size; i++) {
        printf(" ");
        printArg(args.data[i], isReplaced);
    }
}

void printInstr(Instruction instr, bool isReplaced) {
    printf("%04lX:", instr.address);
    if (instr.isMacro)
        switch (instr.mType) {
            case M_NOP: printf("NOP"); break;
            case M_MOV: printf("MOV"); break;
            case M_JVC: printf("JVC"); break;
            case M_JVS: printf("JVS"); break;
            case M_JNE: printf("JNE"); break;
            case M_JEQ: printf("JEQ"); break;
            case M_JGE: printf("JGE"); break;
            case M_JLT: printf("JLT"); break;
            case M_JCC: printf("JCC"); break;
            case M_JCS: printf("JCS"); break;
            case M_CALL: printf("CALL"); break;
            case M_HALT: printf("HALT"); break;
            case M_DW: printf("DW"); break;
            case M_LABEL: printf("LABEL"); break;
            case M_LABEL_ASSIGN: printf("LABEL ="); break;
            case M_USER_MACRO: printf("$"); break;
            case M_INCLUDE: printf("#include"); break;
        }
    else
        switch (instr.iType) {
            case I_ADD: printf("ADD"); break;
            case I_ADC: printf("ADC"); break;
            case I_SUB: printf("SUB"); break;
            case I_SBC: printf("SBC"); break;
            case I_MUL: printf("MUL"); break;
            case I_MLL: printf("MLL"); break;
            case I_SGN: printf("SGN"); break;
            case I_RAS: printf("RAS"); break;
            case I_LSH: printf("LSH"); break;
            case I_RSH: printf("RSH"); break;
            case I_LRT: printf("LRT"); break;
            case I_RRT: printf("RRT"); break;
            case I_AND: printf("AND"); break;
            case I_OR: printf("OR"); break;
            case I_XOR: printf("XOR"); break;
            case I_NOT: printf("NOT"); break;
            case I_MOV8LL: printf("MOV8LL"); break;
            case I_MOV8LH: printf("MOV8LH"); break;
            case I_MOV8HL: printf("MOV8HL"); break;
            case I_MOV8HH: printf("MOV8HH"); break;
            case I_JMP: printf("JMP"); break;
            case I_JMR: printf("JMR"); break;
            case I_ADDI: printf("ADDI"); break;
            case I_ADCI: printf("ADCI"); break;
            case I_SUBI: printf("SUBI"); break;
            case I_SBCI: printf("SBCI"); break;
            case I_ANDI: printf("ANDI"); break;
            case I_ORI: printf("ORI"); break;
            case I_XORI: printf("XORI"); break;
            case I_LDI: printf("LDI"); break;
            case I_LSHI: printf("LSHI"); break;
            case I_RSHI: printf("RSHI"); break;
            case I_LRTI: printf("LRTI"); break;
            case I_RRTI: printf("RRTI"); break;
            case I_JFC: printf("JFC"); break;
            case I_JFS: printf("JFS"); break;
            case I_LOAD: printf("LOAD"); break;
            case I_SAVE: printf("SAVE"); break;
            case I_PUSH: printf("PUSH"); break;
            case I_POP: printf("POP"); break;
            case I_SVPC: printf("SVPC"); break;
            case I_RET: printf("RET"); break;
        }
    printArgs(instr.args, isReplaced);
    printf("\n");
}

void printUserMacroTableEntry(UserMacroTableEntry entry) {
    printf("%s [", entry->key);
    for(int i = 0; i < entry->value.paramTypes.size; i++) {
        switch(entry->value.paramTypes.data[i]) {
            case P_REG: printf("REG"); break;
            case P_REG_MEM: printf("REGMEM"); break;
            case P_REG_MEM_IMM: printf("REGMEMIMM"); break;
            case P_IMM: printf("IMM"); break;
        }
        if (i != entry->value.paramTypes.size-1)
            printf(", ");
    }
    printf("] {\n");
    for (InstructionListNode *n = entry->value.instrs.start; n; n = n->next)
        printInstr(n->data, false);
    printf("}\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: rasm <input.rcpu> <output.mif>\n");
        exit(1);
    }
    InstructionList list;
    UserMacroTable userMacros;
    parseProgram(argv[1], &list, &userMacros);
    yyin = fopen(argv[1], "r");

    printf("    USER MACROS:\n");
    foreachRBT(UserMacroTable)(userMacros, &printUserMacroTableEntry);

    printf("    INSTRUCTIONS:\n");
    for (InstructionListNode *n = list.start; n; n = n->next)
        printInstr(n->data, false);

    replaceUserMacros(&list, userMacros);

    printf("    REPLACED USER MACROS:\n");
    for (InstructionListNode *n = list.start; n; n = n->next)
        printInstr(n->data, false);

    LabelTable labels = addAddresses(&list);

    printf("    LABELS:\n");
    foreachRBT(LabelTable)(labels, &printLabel);

    printf("    ADDRESSES:\n");
    for (InstructionListNode *n = list.start; n; n = n->next)
        printInstr(n->data, false);

    replaceLabelsAndMacros(&list, labels);

    printf("    REPLACED MACROS AND LABELS:\n");
    for (InstructionListNode *n = list.start; n; n = n->next)
        printInstr(n->data, true);

    DString str = synthesize(list);
    FILE *out = fopen(argv[2], "w");
    fprintf(out, "%s\n", str.data);
    fclose(yyin);
    fclose(out);
    deleteLList(InstructionList)(list);
    free(str.data);
}

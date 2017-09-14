#include <stdio.h>
#include "ast.h"
#include "y.tab.h"
#include "replacer.h"
#include "synthesizer.h"

extern FILE* yyin;
extern int yylex();
extern LabelTable labels;
//extern YYSTYPE yylval;
extern char *yytext;

/*void printLabel(LabelTableEntry entry) {
    printf("%s = %04lx\n", entry->key, entry->value);
}

void printArgs(Argument *args) {
    for (int i = 0; i < 3; i++) {
        Argument a = args[i];
        switch (a.type) {
            case A_NO_ARG: break;
            case A_REGISTER: switch (a.rType) {
                    case REG_A: printf(" A"); break;
                    case REG_B: printf(" B"); break;
                    case REG_C: printf(" C"); break;
                    case REG_SP: printf(" SP"); break;
                } break;
            case A_CONSTANT: printf(" %ld", a.iVal); break;
            case A_ADDRESSED: printf(" *A"); break;
            case A_ABSOLUTE: printf(" *%ld", a.iVal); break;
            case A_STACK: printf(" [%ld]", a.iVal); break;
            case A_ZERO: printf(" 0"); break;
            case A_STRING: printf(" \"%s\"", a.text); break;
            case A_IDENTIFIER: printf(" %s", a.text); break;
        }
    }
}

void printInstr(Instruction instr) {
    printf("%04x:", instr.address);
    if (instr.isMacro)
        switch (instr.mType) {
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
            case I_JMP: printf("JMP"); break;
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
            case I_FLC: printf("FLC"); break;
            case I_FLS: printf("FLS"); break;
            case I_PUSH: printf("PUSH"); break;
            case I_POP: printf("POP"); break;
            case I_SVPC: printf("SVPC"); break;
            case I_RET: printf("RET"); break;
        }
    printArgs(instr.args);
    printf("\n");
}*/

int main(int argc, char *argv[]) {
	if (argc != 3) {
		printf("Usage: rasm <input.rcpu> <output.mif>\n");
		exit(1);
	}
    yyin = fopen(argv[1], "r");
    //yydebug = 1;
    /*for (int i = yylex(); i; i = yylex()) {
        printf("(%d, %s)\n", i, yytext);
    }*/
    InstructionList list;
    if (yyparse(&list))
        exit(1);
    //printf("    INSTRUCTIONS:\n");
    //for (InstructionListNode *n = list.start; n; n = n->next)
    //    printInstr(n->data);
    //printf("    LABELS:\n");
    //foreachRBT(LabelTable)(labels, &printLabel);
    replaceLabelsAndMacros(&list, labels);
    //printf("    REPLACED:\n");
    //for (InstructionListNode *n = list.start; n; n = n->next)
    //    printInstr(n->data);
    DString str = synthesize(list);
    FILE *out = fopen(argv[2], "w");
    fprintf(out, "%s\n", str.data);
    deleteLList(InstructionList)(list);
    free(str.data);
}

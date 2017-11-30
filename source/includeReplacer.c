#include <stdio.h>
#include "ast.h"
#include "y.tab.h"
#include "cmpAndDstrFuncs.h"
#include "error.h"

extern FILE* yyin;
extern int lineno;
extern int character;
extern int yylex();
extern int yyparse(InstructionList *list, UserMacroTable *userMacros, char *filename);

void replaceIncludes(InstructionList *list, UserMacroTable *userMacros);

void parseProgram(char *filename, InstructionList *list, UserMacroTable *userMacros) {
    yyin = fopen(filename, "r");
    if (!yyin) {
        printf("Cannot read file \"%s\"!\n", filename);
        exit(1);
    }
    *userMacros = newRBT(UserMacroTable)(&cmpStr, &dstrUserMacroTableEntry);
    lineno = 1;
    character = 1;
    if (yyparse(list, userMacros, filename))
        exit(1);
    rewind(yyin);
    int line = 1;
    for (InstructionListNode *n = list->start; n; n = n->next) {
        Instruction instr = n->data;
        char *source = (char *) malloc(128 * sizeof(char));
        while (instr.line >= line) {
            fgets(source, 128, yyin);
            line++;
        }
        n->data.source = source;
    }
    fclose(yyin);
    replaceIncludes(list, userMacros);
}

static UserMacroTable* newUserMacros;

static void moveUserMacroTableEntry(UserMacroTableEntry entry) {
    rbtSet(UserMacroTable)(newUserMacros, entry->key, entry->value);
    free(entry);
}

static InstructionListNode *replaceInclude(InstructionList *list, InstructionListNode *n, 
        UserMacroTable *userMacros) {
    if(n->data.args.size != 1 || n->data.args.data[0].type != A_STRING) { 
        printf("Strange error which involves missing include filename where it should be\n");
        exit(2);
    }
    InstructionList additionalList;
    UserMacroTable additionalUserMacros;

    char *filename = calloc(strlen(n->data.args.data[0].text)-1, sizeof(char));
    strncpy(filename, n->data.args.data[0].text + 1, strlen(n->data.args.data[0].text)-2);
    parseProgram(filename, &additionalList, &additionalUserMacros);
    free(filename);

    llInsertBeforeL(InstructionList)(list, n, additionalList);
    n = n->prev;
    llRemove(InstructionList)(list, n->next);

    newUserMacros = userMacros;
    foreachRBT(UserMacroTable)(additionalUserMacros, &moveUserMacroTableEntry);

    return n;
}

void replaceIncludes(InstructionList *list, UserMacroTable *userMacros) {
    for (InstructionListNode *n = list->start; n; n = n->next) {
        if (n->data.isMacro && n->data.mType == M_INCLUDE)
            n = replaceInclude(list, n, userMacros);
    }
}
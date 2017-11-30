#include <stdio.h>
#include "ast.h"
#include "y.tab.h"
#include "cmpAndDstrFuncs.h"
#include "error.h"

extern FILE* yyin;
extern int yylineno;
extern int yylex();
extern int yyparse(InstructionList *list, UserMacroTable *userMacros);

void replaceIncludes(InstructionList *list, UserMacroTable *userMacros);

void parseProgram(char *filename, InstructionList *list, UserMacroTable *userMacros) {
    yyin = fopen(filename, "r");
    if (!yyin) {
        printf("Cannot read file \"%s\"!\n", filename);
        exit(1);
    }
    *userMacros = newRBT(UserMacroTable)(&cmpStr, &dstrUserMacroTableEntry);
    yylineno = 1;
    if (yyparse(list, userMacros))
        exit(1);
    replaceIncludes(list, userMacros);
    fclose(yyin);
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
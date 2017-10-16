#ifndef INCLUDE_REPLACER
#define INCLUDE_REPLACER

#include "ast.h"
void replaceIncludes(InstructionList *list, UserMacroTable *userMacros);
void parseProgram(char *filename, InstructionList *list, UserMacroTable *userMacros);

#endif
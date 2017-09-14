#ifndef CMP_AND_DSTR_FUNCS
#define CMP_AND_DSTR_FUNCS

#include <string.h>
#include "ast.h"

int cmpStr(char *a, char *b);
void dstrLabelTableEntry(LabelTableEntry entry);
void dstrInstr(InstructionListNode *n);

#endif

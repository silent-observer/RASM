#include <string.h>
#include <stdlib.h>
#include "ast.h"

int cmpStr(char *a, char *b) {
    return strcmp(a, b);
}
void dstrLabelTableEntry(LabelTableEntry entry) {
    free(entry->key);
    free(entry);
}
void dstrInstr(InstructionListNode *n) {
    for (int i = 0; i < 3; i++)
        if (n->data.args[i].type == A_STRING ||
            n->data.args[i].type == A_IDENTIFIER)
            free(n->data.args[i].text);
    free(n);
}

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
    for (int i = 0; i < n->data.args.size; i++) {
        if (n->data.args.data[i].type == A_STRING ||
            n->data.args.data[i].type == A_IDENTIFIER)
            free(n->data.args.data[i].text);
    }
    free(n);
    free(n->data.args.data);
}

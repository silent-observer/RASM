#ifndef SYNTHESIZER
#define SYNTHESIZER

#include "ast.h"
#include "data_structures/dynamicarray_g.h"

#ifndef DSTRING
    #define DSTRING
    defineDArray(DString, char);
#endif

DString synthesize(InstructionList list);

#endif

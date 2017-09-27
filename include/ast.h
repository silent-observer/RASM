#ifndef TOKEN
#define TOKEN

#include "data_structures/linkedlist_g.h"
#include "data_structures/redblacktree_g.h"
#include <stdbool.h>

enum instrType {
    // A-type
    I_ADD, I_ADC, I_SUB, I_SBC,
    I_MUL, I_MLL, I_SGN, I_RAS,
    I_LSH, I_RSH, I_LRT, I_RRT,
    I_AND, I_OR,  I_XOR, I_NOT,
    // J-type
    I_JMP,
    // I-type
    I_ADDI, I_ADCI, I_SUBI, I_SBCI,
    I_ANDI, I_ORI,  I_XORI, I_LDI,
    // SI-type
    I_LSHI, I_RSHI, I_LRTI, I_RRTI,
    // F-type
    I_JFC, I_JFS, I_FLC, I_FLS,
    // SP-type
    I_PUSH, I_POP, I_SVPC, I_RET
};

enum argType {
    A_NO_ARG,
    A_REGISTER,
    A_CONSTANT,
    A_ADDRESSED,
    A_ABSOLUTE,
    A_STACK,
    A_ZERO,
    A_STRING,
    A_IDENTIFIER,
    A_ID_HIGH,
    A_ID_LOW
};
enum registerType {
    REG_SP,
    REG_A, REG_B, REG_C
};

enum macroType {
    M_MOV,
    M_JVC, M_JVS, M_JNE, M_JEQ,
    M_JGE, M_JLT, M_JCC, M_JCS,
    M_CALL, M_HALT, M_DW,
    M_LABEL, M_LABEL_ASSIGN
};

typedef struct {
    enum argType type;
    union {
        enum registerType rType;
        char *text;
        long int iVal;
    };
} Argument;

typedef struct {
    unsigned long int address;
    bool isMacro;
    union {
        enum instrType iType;
        enum macroType mType;
    };
    Argument args[3];
} Instruction;

#ifndef LABEL_TABLE
    #define LABEL_TABLE
    typedef char *charptr;
    typedef unsigned long int ulong;
    defineRBT(LabelTable, charptr, ulong)
#endif

#ifndef INSTRUCTION_LIST
    #define INSTRUCTION_LIST
    defineLList(InstructionList, Instruction)
#endif


#endif

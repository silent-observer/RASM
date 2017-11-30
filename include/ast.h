#ifndef TOKEN
#define TOKEN

#include "data_structures/dynamicarray_g.h"
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
    I_JFC, I_JFS, 
    // LS-type
    I_LOAD, I_SAVE,
    // SP-type
    I_PUSH, I_POP, I_SVPC, I_RET
};

enum argType {
    A_REGISTER,
    A_CONSTANT,
    A_ADDRESSED,
    A_ABSOLUTE,
    A_STACK,
    A_ZERO,
    A_STRING,
    A_IDENTIFIER,
    A_ID_HIGH,
    A_ID_LOW,
    A_MACRO_ARG,
    A_SUM,
    A_INDEX, 
    A_SUM_HIGH,
    A_SUM_LOW,
    A_FASTMEM
};
enum registerType {
    REG_SP,
    REG_A, REG_B, REG_C
};

enum macroType {
    M_NOP,
    M_MOV,
    M_JVC, M_JVS, M_JNE, M_JEQ,
    M_JGE, M_JLT, M_JCC, M_JCS,
    M_CALL, M_HALT, M_DW,
    M_LABEL, M_LABEL_ASSIGN,
    M_INCLUDE, M_USER_MACRO
};

struct DArray_ArgumentDArray;

typedef struct Argument{
    enum argType type;
    union {
        enum registerType rType;
        char *text;
        long int iVal;
        struct DArray_ArgumentDArray *sum;
    };
} Argument;

#ifndef ARGUMENT_DARRAY
    #define ARGUMENT_DARRAY
    defineDArray(ArgumentDArray, Argument)
#endif

typedef struct {
    unsigned long int address;
    unsigned int line;
    char *filename;
    bool isMacro;
    union {
        enum instrType iType;
        enum macroType mType;
    };
    ArgumentDArray args;
    char *source;
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

enum paramType {
    P_REG,
    P_REG_MEM,
    P_REG_MEM_IMM,
    P_IMM
};

#ifndef PARAM_TYPE_DARRAY
    #define PARAM_TYPE_DARRAY
    typedef enum paramType paramType;
    defineDArray(ParamTypeDArray, paramType)
#endif

typedef struct {
    ParamTypeDArray paramTypes;
    InstructionList instrs;
} UserMacro;

#ifndef USERMACRO_TABLE
    #define USERMACRO_TABLE
    typedef char *charptr;
    defineRBT(UserMacroTable, charptr, UserMacro)
#endif

#endif

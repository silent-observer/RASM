%{
    #include "ast.h"
    #include "cmpAndDstrFuncs.h"
    static Instruction i;
    static Argument a;
    int yylex();
    void yyerror(InstructionList *result, const char *s);
    int calcLength (char *str);
    int yylineno;
%}

%parse-param {InstructionList *result}
//%define parse.error verbose
%locations

%union {
    InstructionList iList;
    Instruction instr;
    Argument arg;
    enum instrType iType;
    enum macroType mType;
    char *text;
    long int iVal;
}

%token ADD ADC SUB SBC
%token MUL MLL SGN RAS
%token LSH RSH LRT RRT
%token AND OR  XOR NOT
%token JMP
%token ADDI ADCI SUBI SBCI
%token ANDI ORI XORI LDI
%token LSHI RSHI LRTI RRTI
%token JFC JFS FLC FLS
%token PUSH POP SVPC RET

%token MOV
%token JVC JVS JNE JEQ
%token JGE JLT JCC JCS
%token CALL HALT DW

%token DEFMACRO ENDDEF INCLUDE
%token REG REGMEM REGMEMIMM IMM

%token A B C SP
%token HIGH LOW

%token <text> IDENTIFIER STRING
%token <iVal> HEX BINARY DECIMAL CHAR

%type <iList> instruction_list
%type <instr> instruction simple_instr macro_instr label user_macro
%type <iType> a_type i_type si_type jfg_type flg_type
%type <mType> jfg_macro

%type <arg> reg reg_without_macro_arg
%type <arg> mem
%type <arg> imm imm_without_macro_arg
%type <arg> dest dest_without_macro_arg dest_sp
%type <arg> reg_mem_imm reg_mem_imm_without_macro_arg
%type <arg> absolute addressed stack

%start program

%%

program : instruction_list {*result = $1;}
        ;

instruction_list : instruction_list {memset(&i, 0, sizeof i);} instruction
                    {
                        llAppend(InstructionList)(&$1, $3);
                        $$ = $1;
                    }
                | instruction_list {memset(&i, 0, sizeof i);} label
                    {
                        $3.isMacro = true; 
                        llAppend(InstructionList)(&$1, $3);
                        $$ = $1;
                    }
                | instruction_list '\n'
                    {$$ = $1;}
                | instruction_list macro_definition
                | instruction_list include_directive
                |
                    {
                        $$ = newLList(InstructionList)(&dstrInstr);
                    }
                ;

label   : IDENTIFIER ':' '\n'
            {
                i.mType = M_LABEL;
                i.args = newDArray(ArgumentDArray)(1);
                a.type = A_IDENTIFIER; 
                a.text = $1;
                daAppend(ArgumentDArray)(&i.args, &a);
                $$ = i;
            }
        | IDENTIFIER '=' imm '\n'
            {
                i.mType = M_LABEL_ASSIGN;
                i.args = newDArray(ArgumentDArray)(2);
                a.type = A_IDENTIFIER; 
                a.text = $1;
                daAppend(ArgumentDArray)(&i.args, &a);
                daAppend(ArgumentDArray)(&i.args, &$3);
                $$ = i;
            }
        ;

macro_definition : '#' DEFMACRO IDENTIFIER '[' parameter_list ']' '\n' instruction_list ENDDEF '\n'
                 ;

include_directive : '#' INCLUDE STRING '\n'
                  ;

parameter_list  :
                | param_type
                | parameter_list ',' param_type
                ;

param_type  : REG
            | REGMEM
            | REGMEMIMM
            | IMM
            ;


instruction : simple_instr '\n' {$1.isMacro = false; $$ = $1;}
            | macro_instr  '\n' {$1.isMacro = true; $$ = $1;}
            | user_macro   '\n' {$1.isMacro = true; $1.mType = M_USER_MACRO; $$ = $1;}
            ;
simple_instr    : a_type reg_mem_imm ',' reg ',' dest
                    {
                        i.iType = $1;
                        i.args = newDArray(ArgumentDArray)(3);
                        daAppend(ArgumentDArray)(&i.args, &$2);
                        daAppend(ArgumentDArray)(&i.args, &$4);
                        daAppend(ArgumentDArray)(&i.args, &$6);
                        $$ = i;
                    }
                | NOT reg_mem_imm ',' dest
                    {
                        i.iType = I_NOT;
                        i.args = newDArray(ArgumentDArray)(2);
                        daAppend(ArgumentDArray)(&i.args, &$2);
                        daAppend(ArgumentDArray)(&i.args, &$4);
                        $$ = i;
                    }
                | JMP imm
                    {
                        i.iType = I_JMP;
                        i.args = newDArray(ArgumentDArray)(1);
                        daAppend(ArgumentDArray)(&i.args, &$2);
                        $$ = i;
                    }
                | i_type dest_sp ',' imm ',' dest_sp
                    {
                        i.iType = $1;
                        i.args = newDArray(ArgumentDArray)(3);
                        daAppend(ArgumentDArray)(&i.args, &$2);
                        daAppend(ArgumentDArray)(&i.args, &$4);
                        daAppend(ArgumentDArray)(&i.args, &$6);
                        $$ = i;
                    }
                | LDI imm ',' dest_sp
                    {
                        i.iType = I_LDI;
                        i.args = newDArray(ArgumentDArray)(2);
                        daAppend(ArgumentDArray)(&i.args, &$2);
                        daAppend(ArgumentDArray)(&i.args, &$4);
                        $$ = i;
                    }
                | si_type reg_mem_imm ',' imm ',' dest
                    {
                        i.iType = $1;
                        i.args = newDArray(ArgumentDArray)(3);
                        daAppend(ArgumentDArray)(&i.args, &$2);
                        daAppend(ArgumentDArray)(&i.args, &$4);
                        daAppend(ArgumentDArray)(&i.args, &$6);
                        $$ = i;
                    }
                | jfg_type imm ',' imm
                    {
                        i.iType = $1;
                        i.args = newDArray(ArgumentDArray)(2);
                        daAppend(ArgumentDArray)(&i.args, &$2);
                        daAppend(ArgumentDArray)(&i.args, &$4);
                        $$ = i;
                    }
                | flg_type imm
                    {
                        i.iType = $1;
                        i.args = newDArray(ArgumentDArray)(1);
                        daAppend(ArgumentDArray)(&i.args, &$2);
                        $$ = i;
                    }
                | PUSH reg_mem_imm
                    {
                        i.iType = I_PUSH;
                        i.args = newDArray(ArgumentDArray)(1);
                        daAppend(ArgumentDArray)(&i.args, &$2);
                        $$ = i;
                    }
                | POP dest
                    {
                        i.iType = I_POP;
                        i.args = newDArray(ArgumentDArray)(1);
                        daAppend(ArgumentDArray)(&i.args, &$2);
                        $$ = i;
                    }
                | SVPC 
                    {
                        i.iType = I_SVPC; 
                        i.args = newDArray(ArgumentDArray)(0); 
                        $$ = i;
                    }
                | RET  
                    {
                        i.iType = I_RET; 
                        i.args = newDArray(ArgumentDArray)(0); 
                        $$ = i;
                    }
                ;
macro_instr : MOV reg_mem_imm ',' dest
                {
                    i.mType = M_MOV;
                    i.args = newDArray(ArgumentDArray)(2);
                    daAppend(ArgumentDArray)(&i.args, &$2);
                    daAppend(ArgumentDArray)(&i.args, &$4);
                    $$ = i;
                }
            | jfg_macro imm
                {
                    i.mType = $1;
                    i.args = newDArray(ArgumentDArray)(1);
                    daAppend(ArgumentDArray)(&i.args, &$2);
                    $$ = i;
                }
            | CALL IDENTIFIER
                {
                    i.mType = M_CALL;
                    a.type = A_IDENTIFIER;
                    a.text = $2;
                    i.args = newDArray(ArgumentDArray)(1);
                    daAppend(ArgumentDArray)(&i.args, &a);
                    $$ = i;
                }
            | HALT   
                {
                    i.mType = M_HALT; 
                    i.args = newDArray(ArgumentDArray)(1);
                    $$ = i;
                }
            | DW imm
                {
                    i.mType = M_DW;
                    i.args = newDArray(ArgumentDArray)(1);
                    daAppend(ArgumentDArray)(&i.args, &$2);
                    $$ = i;
                }
            | DW STRING
                {
                    i.mType = M_DW;
                    a.type = A_STRING;
                    a.text = $2;
                    i.args = newDArray(ArgumentDArray)(1);
                    daAppend(ArgumentDArray)(&i.args, &a);
                    $$ = i;
                }
            ;

user_macro  : '$' IDENTIFIER 
                {
                    i.args = newDArray(ArgumentDArray)(1);
                    a.type = A_IDENTIFIER;
                    a.text = $2;
                    daAppend(ArgumentDArray)(&i.args, &a);
                    $$ = i;
                }
            | '$' IDENTIFIER reg_mem_imm
                {
                    i.args = newDArray(ArgumentDArray)(4);
                    a.type = A_IDENTIFIER;
                    a.text = $2;
                    daAppend(ArgumentDArray)(&i.args, &a);
                    daAppend(ArgumentDArray)(&i.args, &$3);
                    $$ = i;
                }
            | user_macro ',' reg_mem_imm
                {
                    daAppend(ArgumentDArray)(&$1.args, &$3);
                    $$ = $1;
                }

a_type  : ADD {$$ = I_ADD;}
        | ADC {$$ = I_ADC;}
        | SUB {$$ = I_SUB;}
        | SBC {$$ = I_SBC;}
        | MUL {$$ = I_MUL;}
        | MLL {$$ = I_MLL;}
        | SGN {$$ = I_SGN;}
        | RAS {$$ = I_RAS;}
        | LSH {$$ = I_LSH;}
        | RSH {$$ = I_RSH;}
        | LRT {$$ = I_LRT;}
        | RRT {$$ = I_RRT;}
        | AND {$$ = I_AND;}
        | OR  {$$ = I_OR;}
        | XOR {$$ = I_XOR;}
        ;

i_type  : ADDI {$$ = I_ADDI;}
        | ADCI {$$ = I_ADCI;}
        | SUBI {$$ = I_SUBI;}
        | SBCI {$$ = I_SBCI;}
        | ANDI {$$ = I_ANDI;}
        | ORI  {$$ = I_ORI;}
        | XORI {$$ = I_XORI;}
        ;

si_type : LSHI {$$ = I_LSHI;}
        | RSHI {$$ = I_RSHI;}
        | LRTI {$$ = I_LRTI;}
        | RRTI {$$ = I_RRTI;}
        ;

jfg_type    : JFC {$$ = I_JFC;}
            | JFS {$$ = I_JFS;}
            ;
flg_type    : FLC {$$ = I_FLC;}
            | FLS {$$ = I_FLS;}
            ;

jfg_macro   : JVC {$$ = M_JVC;}
            | JVS {$$ = M_JVS;}
            | JNE {$$ = M_JNE;}
            | JEQ {$$ = M_JEQ;}
            | JGE {$$ = M_JGE;}
            | JLT {$$ = M_JLT;}
            | JCC {$$ = M_JCC;}
            | JCS {$$ = M_JCS;}
            ;

reg_mem_imm_without_macro_arg   : reg_without_macro_arg {$$ = $1;}
                                | mem {$$ = $1;}
                                | imm_without_macro_arg {$$ = $1;}
                                ;
reg_mem_imm : reg_mem_imm_without_macro_arg {$$ = $1;}
            | '$' DECIMAL {a.type = A_MACRO_ARG; a.iVal = $2; $$ = a;}
            ;

dest_without_macro_arg  : reg_without_macro_arg {$$ = $1;}
                        | mem {$$ = $1;}
                        | '0' {a.type = A_ZERO; a.iVal = 0; $$ = a;}
                        ;
dest    : dest_without_macro_arg {$$ = $1;}
        | '$' DECIMAL {a.type = A_MACRO_ARG; a.iVal = $2; $$ = a;}
        ;
dest_sp     : dest {$$ = $1;}
            | SP {a.type = A_REGISTER; a.rType = REG_SP; $$ = a;}
            ;

reg_without_macro_arg   : A {a.type = A_REGISTER; a.rType = REG_A; $$ = a;}
                        | B {a.type = A_REGISTER; a.rType = REG_B; $$ = a;}
                        | C {a.type = A_REGISTER; a.rType = REG_C; $$ = a;}
                        ;
reg : reg_without_macro_arg {$$ = $1;}
    | '$' DECIMAL {a.type = A_MACRO_ARG; a.iVal = $2; $$ = a;}
    ;

mem : absolute {$1.type = A_ABSOLUTE; $$ = $1;}
    | addressed {$1.type = A_ADDRESSED; $$ = $1;}
    | stack {$1.type = A_STACK; $$ = $1;}
    ;

imm_without_macro_arg   : HEX {a.type = A_CONSTANT; a.iVal = $1; $$ = a;}
                        | BINARY {a.type = A_CONSTANT; a.iVal = $1; $$ = a;}
                        | DECIMAL {a.type = A_CONSTANT; a.iVal = $1; $$ = a;}
                        | CHAR {a.type = A_CONSTANT; a.iVal = $1; $$ = a;}
                        | '0' {a.type = A_ZERO; a.iVal = 0; $$ = a;}
                        | IDENTIFIER {a.type = A_IDENTIFIER; a.text = $1; $$ = a;}
                        | IDENTIFIER HIGH {a.type = A_ID_HIGH; a.text = $1; $$ = a;}
                        | IDENTIFIER LOW {a.type = A_ID_LOW; a.text = $1; $$ = a;}
                        ;
imm : imm_without_macro_arg {$$ = $1;}
    | '$' DECIMAL {a.type = A_MACRO_ARG; a.iVal = $2; $$ = a;}
    ;



absolute    : '*' IDENTIFIER {a.text = $2; $$ = a;}
addressed   : '*' A {a.rType = REG_A; $$ = a;}
stack       : '[' imm ']' {a.iVal = $2.iVal; $$ = a;}

%%


void yyerror (InstructionList *result, char const *s)
{
  fprintf (stderr, "%d:%s\n", yylineno, s);
}

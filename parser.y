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

%token A B C SP
%token HIGH LOW

%token <text> IDENTIFIER STRING
%token <iVal> HEX BINARY DECIMAL CHAR

%type <iList> instructionList
%type <instr> instruction simple_instr macro_instr label
%type <iType> a_type i_type si_type jfg_type flg_type
%type <mType> jfg_macro
%type <arg> reg_mem_imm dest dest_sp reg mem imm embedded_imm reg_sp
%type <arg> absolute addressed stack

%start program

%%

program : instructionList {*result = $1;}

instructionList : instructionList {memset(&i, 0, sizeof i);} instruction
                    {
                        llAppend(InstructionList)(&$1, $3);
                        $$ = $1;
                    }
                | instructionList {memset(&i, 0, sizeof i);} label
                    {
                        $3.isMacro = true; 
                        llAppend(InstructionList)(&$1, $3);
                        $$ = $1;
                    }
                | instructionList '\n'
                    {$$ = $1;}
                |
                    {
                        $$ = newLList(InstructionList)(&dstrInstr);
                    }
                ;

label   : IDENTIFIER ':' '\n'
            {
                i.mType = M_LABEL; 
                i.args[0].type = A_IDENTIFIER; 
                i.args[0].text = $1;
                $$ = i;
            }
        | IDENTIFIER '=' imm '\n'
            {
                i.mType = M_LABEL_ASSIGN; 
                i.args[0].type = A_IDENTIFIER; 
                i.args[0].text = $1;
                i.args[1] = $3;
                $$ = i;
            }
        ;
instruction : simple_instr '\n' {$1.isMacro = false; $$ = $1;}
            | macro_instr  '\n' {$1.isMacro = true; $$ = $1;}
            ;
simple_instr    : a_type reg_mem_imm ',' reg ',' dest
                    {
                        i.iType = $1;
                        i.args[0] = $2;
                        i.args[1] = $4;
                        i.args[2] = $6;
                        $$ = i;
                    }
                | NOT reg_mem_imm ',' dest
                    {
                        i.iType = I_NOT;
                        i.args[0] = $2;
                        i.args[1] = $4;
                        $$ = i;
                    }
                | JMP embedded_imm
                    {
                        i.iType = I_JMP;
                        i.args[0] = $2;
                        $$ = i;
                    }
                | i_type dest_sp ',' embedded_imm ',' dest_sp
                    {
                        i.iType = $1;
                        i.args[0] = $2;
                        i.args[1] = $4;
                        i.args[2] = $6;
                        $$ = i;
                    }
                | LDI embedded_imm ',' dest_sp
                    {
                        i.iType = I_LDI;
                        i.args[0] = $2;
                        i.args[1] = $4;
                        $$ = i;
                    }
                | si_type reg_mem_imm ',' embedded_imm ',' dest
                    {
                        i.iType = $1;
                        i.args[0] = $2;
                        i.args[1] = $4;
                        i.args[2] = $6;
                        $$ = i;
                    }
                | jfg_type embedded_imm ',' embedded_imm
                    {
                        i.iType = $1;
                        i.args[0] = $2;
                        i.args[1] = $4;
                        $$ = i;
                    }
                | flg_type embedded_imm
                    {
                        i.iType = $1;
                        i.args[0] = $2;
                        $$ = i;
                    }
                | PUSH reg_mem_imm
                    {
                        i.iType = I_PUSH;
                        i.args[0] = $2;
                        $$ = i;
                    }
                | POP dest
                    {
                        i.iType = I_POP;
                        i.args[0] = $2;
                        $$ = i;
                    }
                | SVPC {i.iType = I_SVPC; $$ = i;}
                | RET  {i.iType = I_RET; $$ = i;}
                ;
macro_instr : MOV reg_mem_imm ',' dest
                {
                    i.mType = M_MOV;
                    i.args[0] = $2;
                    i.args[1] = $4;
                    $$ = i;
                }
            | jfg_macro embedded_imm
                {
                    i.mType = $1;
                    i.args[0] = $2;
                    $$ = i;
                }
            | CALL IDENTIFIER
                {
                    i.mType = M_CALL;
                    i.args[0].type = A_IDENTIFIER;
                    i.args[0].text = $2;
                    $$ = i;
                }
            | HALT   {i.mType = M_HALT; $$ = i;}
            | DW imm
                {
                    i.mType = M_DW;
                    i.args[0] = $2;
                    $$ = i;
                }
            | DW STRING
                {
                    i.mType = M_DW;
                    i.args[0].type = A_STRING;
                    i.args[0].text = $2;
                    $$ = i;
                }
            ;

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

reg_mem_imm : reg {$$ = $1;}
            | mem {$$ = $1;}
            | imm {$$ = $1;}
            ;
dest    : reg {$$ = $1;}
        | mem {$$ = $1;}
        | '0' {a.type = A_ZERO; a.iVal = 0; $$ = a;}
        ;
dest_sp     : reg_sp {$$ = $1;}
            | mem {$$ = $1;}
            ;
reg_sp  : reg {$$ = $1;}
        | SP {a.type = A_REGISTER; a.rType = REG_SP; $$ = a;}
        ;

reg : A {a.type = A_REGISTER; a.rType = REG_A; $$ = a;}
    | B {a.type = A_REGISTER; a.rType = REG_B; $$ = a;}
    | C {a.type = A_REGISTER; a.rType = REG_C; $$ = a;}
    ;
mem : absolute {$1.type = A_ABSOLUTE; $$ = $1;}
    | addressed {$1.type = A_ADDRESSED; $$ = $1;}
    | stack {$1.type = A_STACK; $$ = $1;}
    ;
embedded_imm    : HEX {a.type = A_CONSTANT; a.iVal = $1; $$ = a;}
                | BINARY {a.type = A_CONSTANT; a.iVal = $1; $$ = a;}
                | DECIMAL {a.type = A_CONSTANT; a.iVal = $1; $$ = a;}
                | CHAR {a.type = A_CONSTANT; a.iVal = $1; $$ = a;}
                | '0' {a.type = A_CONSTANT; a.iVal = 0; $$ = a;}
				| IDENTIFIER {a.type = A_IDENTIFIER; a.text = $1; $$ = a;}
                | IDENTIFIER HIGH {a.type = A_ID_HIGH; a.text = $1; $$ = a;}
                | IDENTIFIER LOW {a.type = A_ID_LOW; a.text = $1; $$ = a;}
                ;
imm : HEX {a.type = A_CONSTANT; a.iVal = $1; $$ = a;}
    | BINARY {a.type = A_CONSTANT; a.iVal = $1; $$ = a;}
    | DECIMAL {a.type = A_CONSTANT; a.iVal = $1; $$ = a;}
    | CHAR {a.type = A_CONSTANT; a.iVal = $1; $$ = a;}
    | '0' {a.type = A_ZERO; a.iVal = 0; $$ = a;}
	| IDENTIFIER {a.type = A_IDENTIFIER; a.text = $1; $$ = a;}
    | IDENTIFIER HIGH {a.type = A_ID_HIGH; a.text = $1; $$ = a;}
    | IDENTIFIER LOW {a.type = A_ID_LOW; a.text = $1; $$ = a;}
    ;

absolute    : '*' IDENTIFIER {a.text = $2; $$ = a;}
addressed   : '*' A {a.rType = REG_A; $$ = a;}
stack       : '[' embedded_imm ']' {a.iVal = $2.iVal; $$ = a;}

%%


void yyerror (InstructionList *result, char const *s)
{
  fprintf (stderr, "%d:%s\n", yylineno, s);
}

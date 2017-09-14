%{
#include <stdio.h>
#include <string.h>
#include "ast.h"
#include "y.tab.h"

void count();
char parseEscapeSeq(char *str);

unsigned int line = 1;
unsigned int character = 1;
%}
%option noyywrap
%option yylineno

%%

[\t ]           count();

";"[^\n]*$      count();
%{
    // Instructions
    // A-type
%}
ADD|add         { count(); return ADD;}
ADC|adc         { count(); return ADC;}
SUB|sub         { count(); return SUB;}
SBC|sbc         { count(); return SBC;}
MUL|mul         { count(); return MUL;}
MLL|mll         { count(); return MLL;}
SGN|sgn         { count(); return SGN;}
RAS|ras         { count(); return RAS;}
LSH|lsh         { count(); return LSH;}
RSH|rsh         { count(); return RSH;}
LRT|lrt         { count(); return LRT;}
RRT|rrt         { count(); return RRT;}
AND|and         { count(); return AND;}
OR|or           { count(); return OR; }
XOR|xor         { count(); return XOR;}
NOT|not         { count(); return NOT;}
%{
    // J-type
%}
JMP|jmp         { count(); return JMP;}
%{
    // I-type
%}
ADDI|addi       { count(); return ADDI;}
ADCI|adci       { count(); return ADCI;}
SUBI|subi       { count(); return SUBI;}
SBCI|sbci       { count(); return SBCI;}
ANDI|andi       { count(); return ANDI;}
ORI|ori         { count(); return ORI;}
XORI|xori       { count(); return XORI;}
LDI|ldi         { count(); return LDI;}
%{
    // SI-type
%}
LSHI|lshi       { count(); return LSHI;}
RSHI|rshi       { count(); return RSHI;}
LRTI|lrti       { count(); return LRTI;}
RRTI|rrti       { count(); return RRTI;}
%{
    // F-type
%}
JFC|jfc         { count(); return JFC;}
JFS|jfs         { count(); return JFS;}
FLC|flc         { count(); return FLC;}
FLS|fls         { count(); return FLS;}
%{
    // SP-type
%}
PUSH|push       { count(); return PUSH;}
POP|pop         { count(); return POP;}
SVPC|svpc       { count(); return SVPC;}
RET|ret         { count(); return RET;}
%{
    // Macros
%}
MOV|mov         { count(); return MOV;}
JVC|jvc         { count(); return JVC;}
JVS|jvs         { count(); return JVS;}
JNE|jne|JNZ|jnz { count(); return JNE;}
JEQ|jeq|JEZ|jez { count(); return JEQ;}
JGE|jge         { count(); return JGE;}
JLT|jlt         { count(); return JLT;}
JCC|jcc         { count(); return JCC;}
JCS|jcs         { count(); return JCS;}
CALL|call       { count(); return CALL;}
HALT|halt       { count(); return HALT;}
DW|dw           { count(); return DW;}
%{
    // Register
%}
A|a   { count(); return A;}
B|b   { count(); return B;}
C|c   { count(); return C;}
SP|sp { count(); return SP;}

\"(\\.|[^\\"])*\" { count(); yylval.text = strdup(yytext); return STRING;}
'(\\.|.)' { count(); yylval.iVal = parseEscapeSeq(yytext); return CHAR;}
[a-zA-Z_][a-zA-Z0-9_]* { count(); yylval.text = strdup(yytext); return IDENTIFIER;}
[+-]?0*[1-9A-Fa-f][0-9a-fA-F]*h { count(); yylval.iVal = strtol(yytext, NULL, 16); return HEX;}
[+-]?0*[0-1]+b { count(); yylval.iVal = strtol(yytext, NULL, 2); return BINARY;}
[+-]?[1-9][0-9]* { count(); yylval.iVal = strtol(yytext, NULL, 10); return DECIMAL;}
[\[\]*,:=\n0] { count(); return yytext[0];}

. {}

%%

void count() {
    //if(!strcmp(yytext, "\n"))
    //    line++;
    //character += yyleng;
}

char parseEscapeSeq(char *str) {
    if (str[1] != '\\')
        return str[1];
    switch (str[2]) {
        case 'a': return '\a';
        case 'b': return '\b';
        case 'n': return '\n';
        case 't': return '\t';
        case 'v': return '\v';
        case '0': return '\0';
        default: return str[2];
    }
}

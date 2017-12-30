%{
#include <stdio.h>
#include <string.h>
#include "ast.h"
#include "y.tab.h"

char parseEscapeSeq(char *str);

unsigned int lineno = 1;
unsigned int character = 1;
%}
%option noyywrap

%%

[\t ]           character++;

";"[^\n]*$      character++;
%{
    // Instructions
    // A-type
%}
ADD|add         { character++; return ADD;}
ADC|adc         { character++; return ADC;}
SUB|sub         { character++; return SUB;}
SBC|sbc         { character++; return SBC;}
MUL|mul         { character++; return MUL;}
MLL|mll         { character++; return MLL;}
SGN|sgn         { character++; return SGN;}
RAS|ras         { character++; return RAS;}
LSH|lsh         { character++; return LSH;}
RSH|rsh         { character++; return RSH;}
LRT|lrt         { character++; return LRT;}
RRT|rrt         { character++; return RRT;}
AND|and         { character++; return AND;}
OR|or           { character++; return OR; }
XOR|xor         { character++; return XOR;}
NOT|not         { character++; return NOT;}
%{
    // J-type
%}
JMP|jmp         { character++; return JMP;}
%{
    // JR-type
%}
JMR|jmr         { character++; return JMR;}
%{
    // I-type
%}
ADDI|addi       { character++; return ADDI;}
ADCI|adci       { character++; return ADCI;}
SUBI|subi       { character++; return SUBI;}
SBCI|sbci       { character++; return SBCI;}
ANDI|andi       { character++; return ANDI;}
ORI|ori         { character++; return ORI;}
XORI|xori       { character++; return XORI;}
LDI|ldi         { character++; return LDI;}
%{
    // SI-type
%}
LSHI|lshi       { character++; return LSHI;}
RSHI|rshi       { character++; return RSHI;}
LRTI|lrti       { character++; return LRTI;}
RRTI|rrti       { character++; return RRTI;}
%{
    // F-type
%}
JFC|jfc         { character++; return JFC;}
JFS|jfs         { character++; return JFS;}
%{
    // LS-type
%}
LOAD|load       { character++; return LOAD;}
SAVE|save       { character++; return SAVE;}
%{
    // SP-type
%}
PUSH|push       { character++; return PUSH;}
POP|pop         { character++; return POP;}
SVPC|svpc       { character++; return SVPC;}
RET|ret         { character++; return RET;}
%{
    // Macros
%}
NOP|nop         { character++; return NOP;}
MOV|mov         { character++; return MOV;}
JVC|jvc         { character++; return JVC;}
JVS|jvs         { character++; return JVS;}
JNE|jne|JNZ|jnz { character++; return JNE;}
JEQ|jeq|JEZ|jez { character++; return JEQ;}
JGE|jge         { character++; return JGE;}
JLT|jlt         { character++; return JLT;}
JCC|jcc         { character++; return JCC;}
JCS|jcs         { character++; return JCS;}
CALL|call       { character++; return CALL;}
HALT|halt       { character++; return HALT;}
DW|dw           { character++; return DW;}
%{
    // Directives
%}
#DEFMACRO|#defmacro { character++; return DEFMACRO;}
ENDDEF|enddef     { character++; return ENDDEF;}
#INCLUDE|#include   { character++; return INCLUDE;}
%{
    // Argument types
%}
R|r     { character++; return REG;}
RM|rm   { character++; return REGMEM;}
RMI|rmi { character++; return REGMEMIMM;}
I|i     { character++; return IMM;}
%{
    // Register
%}
A|a   { character++; return A;}
B|b   { character++; return B;}
C|c   { character++; return C;}
SP|sp { character++; return SP;}
%{
    // High and low bytes
%}
".h"|".H" { character++; return HIGH;}
".l"|".L" { character++; return LOW;}

\"(\\.|[^\\"])*\" { character++; yylval.text = strdup(yytext); return STRING;}
'(\\.|.)' { character++; yylval.iVal = parseEscapeSeq(yytext); return CHAR;}
[+-]?0*[1-9A-Fa-f][0-9a-fA-F]*h { character++; yylval.iVal = strtoul(yytext, NULL, 16) & 0xFFFFFFFF; return HEX;}
[+-]?0*[0-1]+b { character++; yylval.iVal = strtoul(yytext, NULL, 2) & 0xFFFFFFFF; return BINARY;}
[+-]?[1-9][0-9]* { character++; yylval.iVal = strtol(yytext, NULL, 10) & 0xFFFFFFFF; return DECIMAL;}
[a-zA-Z_][a-zA-Z0-9_]* { character++; yylval.text = strdup(yytext); return IDENTIFIER;}
[\[\]*,:=0$+()@] { character++; return yytext[0];}
"\n" { character = 1; lineno++; return '\n';}

. {}

%%

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

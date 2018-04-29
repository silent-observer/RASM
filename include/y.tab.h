/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_INCLUDE_Y_TAB_H_INCLUDED
# define YY_YY_INCLUDE_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ADD = 258,
    ADC = 259,
    SUB = 260,
    SBC = 261,
    MUL = 262,
    MLL = 263,
    SGN = 264,
    RAS = 265,
    LSH = 266,
    RSH = 267,
    LRT = 268,
    RRT = 269,
    AND = 270,
    OR = 271,
    XOR = 272,
    NOT = 273,
    MOV8 = 274,
    JMP = 275,
    JMR = 276,
    ADDI = 277,
    ADCI = 278,
    SUBI = 279,
    SBCI = 280,
    ANDI = 281,
    ORI = 282,
    XORI = 283,
    LDI = 284,
    LSHI = 285,
    RSHI = 286,
    LRTI = 287,
    RRTI = 288,
    JFC = 289,
    JFS = 290,
    LOAD = 291,
    SAVE = 292,
    PUSH = 293,
    POP = 294,
    SVPC = 295,
    RET = 296,
    NOP = 297,
    MOV = 298,
    JVC = 299,
    JVS = 300,
    JNE = 301,
    JEQ = 302,
    JGE = 303,
    JLT = 304,
    JCC = 305,
    JCS = 306,
    CALL = 307,
    HALT = 308,
    DW = 309,
    DEFMACRO = 310,
    ENDDEF = 311,
    INCLUDE = 312,
    REG = 313,
    REGMEM = 314,
    REGMEMIMM = 315,
    IMM = 316,
    A = 317,
    B = 318,
    C = 319,
    SP = 320,
    HIGH = 321,
    LOW = 322,
    HIGHB = 323,
    LOWB = 324,
    IDENTIFIER = 325,
    STRING = 326,
    HEX = 327,
    BINARY = 328,
    DECIMAL = 329,
    CHAR = 330
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 20 "parser.y" /* yacc.c:1909  */

    InstructionList iList;
    Instruction instr;
    Argument arg;
    ParamTypeDArray paramTypes;
    enum instrType iType;
    enum macroType mType;
    enum paramType pType;
    char *text;
    long int iVal;

#line 142 "include/y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (InstructionList *result, UserMacroTable *userMacros, char *filename);

#endif /* !YY_YY_INCLUDE_Y_TAB_H_INCLUDED  */

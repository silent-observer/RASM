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
    JMP = 274,
    ADDI = 275,
    ADCI = 276,
    SUBI = 277,
    SBCI = 278,
    ANDI = 279,
    ORI = 280,
    XORI = 281,
    LDI = 282,
    LSHI = 283,
    RSHI = 284,
    LRTI = 285,
    RRTI = 286,
    JFC = 287,
    JFS = 288,
    FLC = 289,
    FLS = 290,
    PUSH = 291,
    POP = 292,
    SVPC = 293,
    RET = 294,
    MOV = 295,
    JVC = 296,
    JVS = 297,
    JNE = 298,
    JEQ = 299,
    JGE = 300,
    JLT = 301,
    JCC = 302,
    JCS = 303,
    CALL = 304,
    HALT = 305,
    DW = 306,
    A = 307,
    B = 308,
    C = 309,
    SP = 310,
    HIGH = 311,
    LOW = 312,
    IDENTIFIER = 313,
    STRING = 314,
    HEX = 315,
    BINARY = 316,
    DECIMAL = 317,
    CHAR = 318
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 19 "parser.y" /* yacc.c:1909  */

    InstructionList iList;
    Instruction instr;
    Argument arg;
    enum instrType iType;
    enum macroType mType;
    char *text;
    long int iVal;

#line 128 "include/y.tab.h" /* yacc.c:1909  */
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
int yyparse (InstructionList *result);

#endif /* !YY_YY_INCLUDE_Y_TAB_H_INCLUDED  */

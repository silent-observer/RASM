
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
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
     JMR = 275,
     ADDI = 276,
     ADCI = 277,
     SUBI = 278,
     SBCI = 279,
     ANDI = 280,
     ORI = 281,
     XORI = 282,
     LDI = 283,
     LSHI = 284,
     RSHI = 285,
     LRTI = 286,
     RRTI = 287,
     JFC = 288,
     JFS = 289,
     LOAD = 290,
     SAVE = 291,
     PUSH = 292,
     POP = 293,
     SVPC = 294,
     RET = 295,
     NOP = 296,
     MOV = 297,
     JVC = 298,
     JVS = 299,
     JNE = 300,
     JEQ = 301,
     JGE = 302,
     JLT = 303,
     JCC = 304,
     JCS = 305,
     CALL = 306,
     HALT = 307,
     DW = 308,
     DEFMACRO = 309,
     ENDDEF = 310,
     INCLUDE = 311,
     REG = 312,
     REGMEM = 313,
     REGMEMIMM = 314,
     IMM = 315,
     A = 316,
     B = 317,
     C = 318,
     SP = 319,
     HIGH = 320,
     LOW = 321,
     IDENTIFIER = 322,
     STRING = 323,
     HEX = 324,
     BINARY = 325,
     DECIMAL = 326,
     CHAR = 327
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 20 "parser.y"

    InstructionList iList;
    Instruction instr;
    Argument arg;
    ParamTypeDArray paramTypes;
    enum instrType iType;
    enum macroType mType;
    enum paramType pType;
    char *text;
    long int iVal;



/* Line 1676 of yacc.c  */
#line 138 "include/y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif

extern YYLTYPE yylloc;


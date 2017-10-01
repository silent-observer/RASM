
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
     DEFMACRO = 307,
     ENDDEF = 308,
     INCLUDE = 309,
     REG = 310,
     REGMEM = 311,
     REGMEMIMM = 312,
     IMM = 313,
     A = 314,
     B = 315,
     C = 316,
     SP = 317,
     HIGH = 318,
     LOW = 319,
     IDENTIFIER = 320,
     STRING = 321,
     HEX = 322,
     BINARY = 323,
     DECIMAL = 324,
     CHAR = 325
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 16 "parser.y"

    InstructionList iList;
    Instruction instr;
    Argument arg;
    enum instrType iType;
    enum macroType mType;
    char *text;
    long int iVal;



/* Line 1676 of yacc.c  */
#line 134 "include/y.tab.h"
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


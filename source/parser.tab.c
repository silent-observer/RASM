
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "parser.y"

    #include "ast.h"
    #include "cmpAndDstrFuncs.h"
    static Instruction i;
    static Argument a;
    static bool isInUserMacroDef;
    static UserMacro currUserMacro;
    int yylex();
    void yyerror(InstructionList *result, UserMacroTable *userMacros, char *filename, const char *s);
    int calcLength (char *str);
    extern int lineno;


/* Line 189 of yacc.c  */
#line 87 "source/parser.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


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

/* Line 214 of yacc.c  */
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



/* Line 214 of yacc.c  */
#line 209 "source/parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

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


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 234 "source/parser.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   247

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  86
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  128
/* YYNRULES -- Number of states.  */
#define YYNSTATES  206

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   327

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      73,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    79,     2,     2,     2,
      82,    83,    85,    84,    78,     2,     2,     2,    80,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    74,     2,
       2,    75,     2,     2,    81,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    76,     2,    77,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,    10,    11,    15,    18,    21,
      22,    26,    27,    31,    36,    37,    48,    52,    53,    55,
      59,    61,    63,    65,    67,    70,    73,    76,    83,    88,
      91,    94,   101,   106,   113,   118,   123,   128,   131,   134,
     137,   139,   144,   147,   150,   152,   154,   157,   160,   163,
     167,   171,   173,   175,   177,   179,   181,   183,   185,   187,
     189,   191,   193,   195,   197,   199,   201,   203,   205,   207,
     209,   211,   213,   215,   217,   219,   221,   223,   225,   227,
     229,   231,   233,   235,   237,   239,   241,   243,   245,   247,
     249,   251,   254,   256,   258,   260,   262,   265,   267,   269,
     271,   273,   275,   277,   280,   282,   284,   286,   288,   291,
     294,   296,   298,   300,   302,   304,   306,   309,   312,   314,
     316,   321,   326,   330,   332,   335,   338,   343,   346
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      87,     0,    -1,    88,    -1,    -1,    88,    89,    98,    -1,
      -1,    88,    90,    92,    -1,    88,    73,    -1,    88,    93,
      -1,    -1,    88,    91,    95,    -1,    -1,    67,    74,    73,
      -1,    67,    75,   119,    73,    -1,    -1,    54,    67,    76,
      96,    77,    73,    94,    88,    55,    73,    -1,    56,    68,
      73,    -1,    -1,    97,    -1,    96,    78,    97,    -1,    57,
      -1,    58,    -1,    59,    -1,    60,    -1,    99,    73,    -1,
     100,    73,    -1,   101,    73,    -1,   102,   108,    78,   113,
      78,   110,    -1,    18,   108,    78,   110,    -1,    19,   119,
      -1,    20,   110,    -1,   103,   111,    78,   119,    78,   111,
      -1,    28,   119,    78,   111,    -1,   104,   108,    78,   119,
      78,   110,    -1,   105,   119,    78,   119,    -1,    35,   115,
      78,   110,    -1,    36,   108,    78,   115,    -1,    37,   108,
      -1,    38,   110,    -1,    39,   119,    -1,    40,    -1,    42,
     108,    78,   110,    -1,   106,   119,    -1,    51,    67,    -1,
      52,    -1,    41,    -1,    53,   119,    -1,    53,    68,    -1,
      79,    67,    -1,    79,    67,   108,    -1,   101,    78,   108,
      -1,     3,    -1,     4,    -1,     5,    -1,     6,    -1,     7,
      -1,     8,    -1,     9,    -1,    10,    -1,    11,    -1,    12,
      -1,    13,    -1,    14,    -1,    15,    -1,    16,    -1,    17,
      -1,    21,    -1,    22,    -1,    23,    -1,    24,    -1,    25,
      -1,    26,    -1,    27,    -1,    29,    -1,    30,    -1,    31,
      -1,    32,    -1,    33,    -1,    34,    -1,    43,    -1,    44,
      -1,    45,    -1,    46,    -1,    47,    -1,    48,    -1,    49,
      -1,    50,    -1,   112,    -1,   114,    -1,   117,    -1,   107,
      -1,    79,    71,    -1,   112,    -1,   114,    -1,    80,    -1,
     109,    -1,    79,    71,    -1,   110,    -1,    64,    -1,    61,
      -1,    62,    -1,    63,    -1,   112,    -1,    79,    71,    -1,
     120,    -1,   121,    -1,   122,    -1,   123,    -1,    81,    71,
      -1,    81,    80,    -1,    69,    -1,    70,    -1,    71,    -1,
      72,    -1,    80,    -1,    67,    -1,    67,    65,    -1,    67,
      66,    -1,   116,    -1,   118,    -1,    82,   118,    83,    65,
      -1,    82,   118,    83,    66,    -1,   116,    84,   119,    -1,
     117,    -1,    79,    71,    -1,    85,    67,    -1,    67,    76,
     119,    77,    -1,    85,    61,    -1,    76,   119,    77,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    79,    79,    82,    82,    89,    89,    96,    98,    99,
      99,   106,   112,   121,   134,   133,   146,   157,   158,   159,
     162,   163,   164,   165,   169,   170,   171,   173,   182,   190,
     197,   204,   213,   221,   230,   238,   246,   254,   261,   268,
     275,   282,   290,   297,   306,   312,   318,   325,   336,   344,
     353,   359,   360,   361,   362,   363,   364,   365,   366,   367,
     368,   369,   370,   371,   372,   373,   376,   377,   378,   379,
     380,   381,   382,   385,   386,   387,   388,   391,   392,   395,
     396,   397,   398,   399,   400,   401,   402,   405,   406,   407,
     409,   410,   413,   414,   415,   417,   418,   420,   421,   424,
     425,   426,   428,   429,   432,   433,   434,   435,   438,   439,
     441,   442,   443,   444,   445,   446,   447,   448,   450,   451,
     452,   453,   455,   470,   471,   476,   477,   491,   492
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ADD", "ADC", "SUB", "SBC", "MUL", "MLL",
  "SGN", "RAS", "LSH", "RSH", "LRT", "RRT", "AND", "OR", "XOR", "NOT",
  "JMP", "JMR", "ADDI", "ADCI", "SUBI", "SBCI", "ANDI", "ORI", "XORI",
  "LDI", "LSHI", "RSHI", "LRTI", "RRTI", "JFC", "JFS", "LOAD", "SAVE",
  "PUSH", "POP", "SVPC", "RET", "NOP", "MOV", "JVC", "JVS", "JNE", "JEQ",
  "JGE", "JLT", "JCC", "JCS", "CALL", "HALT", "DW", "DEFMACRO", "ENDDEF",
  "INCLUDE", "REG", "REGMEM", "REGMEMIMM", "IMM", "A", "B", "C", "SP",
  "HIGH", "LOW", "IDENTIFIER", "STRING", "HEX", "BINARY", "DECIMAL",
  "CHAR", "'\\n'", "':'", "'='", "'['", "']'", "','", "'$'", "'0'", "'@'",
  "'('", "')'", "'+'", "'*'", "$accept", "program", "instruction_list",
  "$@1", "$@2", "$@3", "label", "macro_definition", "$@4",
  "include_directive", "parameter_list", "param_type", "instruction",
  "simple_instr", "macro_instr", "user_macro", "a_type", "i_type",
  "si_type", "f_type", "jfg_macro", "reg_mem_imm_without_macro_arg",
  "reg_mem_imm", "dest_without_macro_arg", "dest", "dest_sp",
  "reg_without_macro_arg", "reg", "mem", "fastmem", "imm_sum_component",
  "imm_without_macro_arg", "imm_sum", "imm", "absolute", "index",
  "addressed", "stack", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,    10,    58,    61,    91,    93,    44,    36,
      48,    64,    40,    41,    43,    42
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    86,    87,    89,    88,    90,    88,    88,    88,    91,
      88,    88,    92,    92,    94,    93,    95,    96,    96,    96,
      97,    97,    97,    97,    98,    98,    98,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,   100,   100,   100,   100,   100,   100,   100,   101,   101,
     101,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   103,   103,   103,   103,
     103,   103,   103,   104,   104,   104,   104,   105,   105,   106,
     106,   106,   106,   106,   106,   106,   106,   107,   107,   107,
     108,   108,   109,   109,   109,   110,   110,   111,   111,   112,
     112,   112,   113,   113,   114,   114,   114,   114,   115,   115,
     116,   116,   116,   116,   116,   116,   116,   116,   117,   117,
     117,   117,   118,   119,   119,   120,   121,   122,   123
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     3,     0,     3,     2,     2,     0,
       3,     0,     3,     4,     0,    10,     3,     0,     1,     3,
       1,     1,     1,     1,     2,     2,     2,     6,     4,     2,
       2,     6,     4,     6,     4,     4,     4,     2,     2,     2,
       1,     4,     2,     2,     1,     1,     2,     2,     2,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     1,     1,     2,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     2,     2,     1,     1,
       4,     4,     3,     1,     2,     2,     4,     2,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      11,     0,     3,     1,     0,     7,     0,     0,     0,     8,
       0,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,     0,     0,     0,    66,
      67,    68,    69,    70,    71,    72,     0,    73,    74,    75,
      76,    77,    78,     0,     0,     0,     0,     0,    40,    45,
       0,    79,    80,    81,    82,    83,    84,    85,    86,     0,
      44,     0,     0,     4,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     6,     0,    10,    17,    99,   100,   101,
     115,   110,   111,   112,   113,     0,     0,   114,     0,     0,
      90,     0,    87,    88,   118,    89,   119,   104,   105,   106,
     107,   115,     0,   123,    29,     0,     0,    94,    95,    30,
      92,    93,     0,     0,     0,     0,    37,    38,    39,     0,
      43,    47,    46,    48,    24,    25,    26,     0,     0,    98,
      97,     0,     0,     0,    42,     0,     0,     0,    20,    21,
      22,    23,     0,    18,   116,   117,     0,     0,    91,     0,
       0,   127,   125,     0,     0,   124,    96,     0,   108,   109,
       0,     0,     0,    49,    50,     0,     0,     0,     0,    12,
       0,    16,     0,     0,     0,   128,     0,    28,   122,    32,
      35,    36,    41,     0,   102,     0,     0,     0,    34,    13,
      14,    19,   126,   120,   121,   103,     0,     0,     0,    11,
      27,    31,    33,     3,     0,    15
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     6,     7,     8,    73,     9,   199,    75,
     142,   143,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    90,    91,   108,   130,   131,   110,   185,   111,   114,
      94,   103,    96,   104,    97,    98,    99,   100
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -150
static const yytype_int16 yypact[] =
{
    -150,     4,     3,  -150,   -65,  -150,   168,   -43,    -7,  -150,
     -23,  -150,  -150,  -150,  -150,  -150,  -150,  -150,  -150,  -150,
    -150,  -150,  -150,  -150,  -150,  -150,     2,   155,    66,  -150,
    -150,  -150,  -150,  -150,  -150,  -150,   155,  -150,  -150,  -150,
    -150,  -150,  -150,   -14,     2,     2,    66,   155,  -150,  -150,
       2,  -150,  -150,  -150,  -150,  -150,  -150,  -150,  -150,    -5,
    -150,    85,     1,  -150,     6,     7,   -12,     2,    32,     2,
     155,   155,   -52,  -150,     9,  -150,    90,  -150,  -150,  -150,
     -55,  -150,  -150,  -150,  -150,   155,    12,  -150,   161,   -16,
    -150,    -3,  -150,  -150,     8,  -150,  -150,  -150,  -150,  -150,
    -150,   -19,    15,  -150,  -150,    14,    17,  -150,  -150,  -150,
    -150,  -150,    13,   -37,    19,    22,  -150,  -150,  -150,    23,
    -150,  -150,  -150,     2,  -150,  -150,  -150,     2,    25,  -150,
    -150,    26,    29,    31,  -150,    40,   155,    43,  -150,  -150,
    -150,  -150,   -40,  -150,  -150,  -150,   155,    42,  -150,     8,
      41,  -150,  -150,    66,   155,  -150,  -150,    32,  -150,  -150,
      66,   -14,    66,  -150,  -150,    59,   155,   155,   155,  -150,
      53,  -150,    57,    90,    54,  -150,   -10,  -150,  -150,  -150,
    -150,  -150,  -150,    68,  -150,    63,    65,    80,  -150,  -150,
    -150,  -150,  -150,  -150,  -150,  -150,    66,    32,    66,  -150,
    -150,  -150,  -150,   -41,    71,  -150
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -150,  -150,   -39,  -150,  -150,  -150,  -150,  -150,  -150,  -150,
    -150,   -11,  -150,  -150,  -150,  -150,  -150,  -150,  -150,  -150,
    -150,  -150,   -38,  -150,   -28,  -149,   -25,  -150,   -17,    -2,
      73,    -9,    75,   -31,  -150,  -150,  -150,  -150
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -10
static const yytype_int16 yytable[] =
{
     109,    92,    10,    -2,     3,   112,   115,   116,   179,    93,
     144,   145,   119,     4,   204,    -9,   118,    95,   117,    92,
      92,   146,   135,   136,    72,    92,    -5,    93,    93,   128,
     122,   132,     5,    93,   158,    95,    95,   172,   173,   133,
     134,    95,    92,   159,    92,   151,   144,   145,   201,    74,
      93,   152,    93,    76,   147,   193,   194,     4,    95,    -9,
      95,   126,   120,    77,    78,    79,   127,   113,   123,    80,
      -5,    81,    82,    83,    84,   153,     5,   137,    85,   124,
     125,    86,    87,   148,    88,   163,   155,    89,   156,   164,
     146,   157,   154,    77,    78,    79,   129,   160,    92,   105,
     161,   162,    92,   165,   166,   170,    93,   167,    85,   168,
      93,   106,   107,   169,    95,   174,   171,    89,    95,   175,
      77,    78,    79,   178,   176,   177,   189,    77,    78,    79,
     190,   192,   180,   105,   182,   186,   187,   188,   183,   195,
     184,   196,    85,   197,   205,   106,   107,   138,   139,   140,
     141,    89,   101,   121,    81,    82,    83,    84,   198,   181,
     203,   149,   191,   150,   102,    87,     0,    88,   200,     0,
     202,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,   101,     0,    81,    82,    83,    84,   101,     0,
      81,    82,    83,    84,   102,    87,     0,    88,     0,     0,
       0,    87,     0,     0,     0,     0,     0,    62
};

static const yytype_int16 yycheck[] =
{
      28,    26,    67,     0,     0,    36,    44,    45,   157,    26,
      65,    66,    50,    54,    55,    56,    47,    26,    46,    44,
      45,    76,    74,    75,    67,    50,    67,    44,    45,    67,
      61,    69,    73,    50,    71,    44,    45,    77,    78,    70,
      71,    50,    67,    80,    69,    61,    65,    66,   197,    56,
      67,    67,    69,    76,    85,    65,    66,    54,    67,    56,
      69,    73,    67,    61,    62,    63,    78,    81,    67,    67,
      67,    69,    70,    71,    72,    78,    73,    68,    76,    73,
      73,    79,    80,    71,    82,   123,    71,    85,    71,   127,
      76,    78,    84,    61,    62,    63,    64,    78,   123,    67,
      78,    78,   127,    78,    78,   136,   123,    78,    76,    78,
     127,    79,    80,    73,   123,   146,    73,    85,   127,    77,
      61,    62,    63,   154,    83,   153,    73,    61,    62,    63,
      73,    77,   160,    67,   162,   166,   167,   168,    79,    71,
     165,    78,    76,    78,    73,    79,    80,    57,    58,    59,
      60,    85,    67,    68,    69,    70,    71,    72,    78,   161,
     199,    88,   173,    88,    79,    80,    -1,    82,   196,    -1,
     198,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    67,    -1,    69,    70,    71,    72,    67,    -1,
      69,    70,    71,    72,    79,    80,    -1,    82,    -1,    -1,
      -1,    80,    -1,    -1,    -1,    -1,    -1,    79
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    87,    88,     0,    54,    73,    89,    90,    91,    93,
      67,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    79,    98,    99,   100,   101,   102,   103,   104,
     105,   106,    67,    92,    56,    95,    76,    61,    62,    63,
      67,    69,    70,    71,    72,    76,    79,    80,    82,    85,
     107,   108,   112,   114,   116,   117,   118,   120,   121,   122,
     123,    67,    79,   117,   119,    67,    79,    80,   109,   110,
     112,   114,   119,    81,   115,   108,   108,   110,   119,   108,
      67,    68,   119,    67,    73,    73,    73,    78,   108,    64,
     110,   111,   108,   119,   119,    74,    75,    68,    57,    58,
      59,    60,    96,    97,    65,    66,    76,   119,    71,   116,
     118,    61,    67,    78,    84,    71,    71,    78,    71,    80,
      78,    78,    78,   108,   108,    78,    78,    78,    78,    73,
     119,    73,    77,    78,   119,    77,    83,   110,   119,   111,
     110,   115,   110,    79,   112,   113,   119,   119,   119,    73,
      73,    97,    77,    65,    66,    71,    78,    78,    78,    94,
     110,   111,   110,    88,    55,    73
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (result, userMacros, filename, YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location, result, userMacros, filename); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, InstructionList *result, UserMacroTable *userMacros, char *filename)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, result, userMacros, filename)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    InstructionList *result;
    UserMacroTable *userMacros;
    char *filename;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
  YYUSE (result);
  YYUSE (userMacros);
  YYUSE (filename);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, InstructionList *result, UserMacroTable *userMacros, char *filename)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp, result, userMacros, filename)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    InstructionList *result;
    UserMacroTable *userMacros;
    char *filename;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, result, userMacros, filename);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, InstructionList *result, UserMacroTable *userMacros, char *filename)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule, result, userMacros, filename)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
    InstructionList *result;
    UserMacroTable *userMacros;
    char *filename;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       , result, userMacros, filename);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule, result, userMacros, filename); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, InstructionList *result, UserMacroTable *userMacros, char *filename)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp, result, userMacros, filename)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
    InstructionList *result;
    UserMacroTable *userMacros;
    char *filename;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (result);
  YYUSE (userMacros);
  YYUSE (filename);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (InstructionList *result, UserMacroTable *userMacros, char *filename);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (InstructionList *result, UserMacroTable *userMacros, char *filename)
#else
int
yyparse (result, userMacros, filename)
    InstructionList *result;
    UserMacroTable *userMacros;
    char *filename;
#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[2];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;

#if YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 1;
#endif

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 79 "parser.y"
    {*result = (yyvsp[(1) - (1)].iList);;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 82 "parser.y"
    {memset(&i, 0, sizeof i);;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 83 "parser.y"
    {
                        (yyvsp[(3) - (3)].instr).line = lineno-1;
                        printf("%d!\n", (yyvsp[(3) - (3)].instr).line);
                        llAppend(InstructionList)(&(yyvsp[(1) - (3)].iList), (yyvsp[(3) - (3)].instr));
                        (yyval.iList) = (yyvsp[(1) - (3)].iList);
                    ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 89 "parser.y"
    {memset(&i, 0, sizeof i);;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 90 "parser.y"
    {
                        (yyvsp[(3) - (3)].instr).line = lineno-1;
                        (yyvsp[(3) - (3)].instr).isMacro = true; 
                        llAppend(InstructionList)(&(yyvsp[(1) - (3)].iList), (yyvsp[(3) - (3)].instr));
                        (yyval.iList) = (yyvsp[(1) - (3)].iList);
                    ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 97 "parser.y"
    {(yyval.iList) = (yyvsp[(1) - (2)].iList);;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 99 "parser.y"
    {memset(&i, 0, sizeof i);;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 100 "parser.y"
    {
                        (yyvsp[(3) - (3)].instr).line = lineno-1;
                        llAppend(InstructionList)(&(yyvsp[(1) - (3)].iList), (yyvsp[(3) - (3)].instr));
                        (yyval.iList) = (yyvsp[(1) - (3)].iList);
                    ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 106 "parser.y"
    {
                        (yyval.iList) = newLList(InstructionList)(&dstrInstr);
                        isInUserMacroDef = false;
                    ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 113 "parser.y"
    {
                i.mType = M_LABEL;
                i.args = newDArray(ArgumentDArray)(1);
                a.type = A_IDENTIFIER; 
                a.text = (yyvsp[(1) - (3)].text);
                daAppend(ArgumentDArray)(&i.args, &a);
                (yyval.instr) = i;
            ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 122 "parser.y"
    {
                i.mType = M_LABEL_ASSIGN;
                i.args = newDArray(ArgumentDArray)(2);
                a.type = A_IDENTIFIER; 
                a.text = (yyvsp[(1) - (4)].text);
                daAppend(ArgumentDArray)(&i.args, &a);
                daAppend(ArgumentDArray)(&i.args, &(yyvsp[(3) - (4)].arg));
                (yyval.instr) = i;
            ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 134 "parser.y"
    {
                        isInUserMacroDef = true;
                        currUserMacro.paramTypes = (yyvsp[(4) - (6)].paramTypes);
                    ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 139 "parser.y"
    {
                        isInUserMacroDef = false;
                        currUserMacro.instrs = (yyvsp[(8) - (10)].iList);
                        rbtSet(UserMacroTable)(userMacros, (yyvsp[(2) - (10)].text), currUserMacro);
                    ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 146 "parser.y"
    {
                        i.isMacro = true; 
                        i.mType = M_INCLUDE; 
                        i.args = newDArray(ArgumentDArray)(1);
                        a.type = A_STRING;
                        a.text = (yyvsp[(2) - (3)].text);
                        daAppend(ArgumentDArray)(&i.args, &a);
                        (yyval.instr) = i;
                    ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 157 "parser.y"
    {(yyval.paramTypes) = newDArray(ParamTypeDArray)(0);;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 158 "parser.y"
    {(yyval.paramTypes) = newDArray(ParamTypeDArray)(3); daAppend(ParamTypeDArray)(&(yyval.paramTypes), &(yyvsp[(1) - (1)].pType));;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 159 "parser.y"
    {daAppend(ParamTypeDArray)(&(yyvsp[(1) - (3)].paramTypes), &(yyvsp[(3) - (3)].pType)); (yyval.paramTypes) = (yyvsp[(1) - (3)].paramTypes);;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 162 "parser.y"
    {(yyval.pType) = P_REG;;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 163 "parser.y"
    {(yyval.pType) = P_REG_MEM;;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 164 "parser.y"
    {(yyval.pType) = P_REG_MEM_IMM;;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 165 "parser.y"
    {(yyval.pType) = P_IMM;;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 169 "parser.y"
    {(yyvsp[(1) - (2)].instr).isMacro = false; (yyval.instr) = (yyvsp[(1) - (2)].instr);;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 170 "parser.y"
    {(yyvsp[(1) - (2)].instr).isMacro = true; (yyval.instr) = (yyvsp[(1) - (2)].instr);;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 171 "parser.y"
    {(yyvsp[(1) - (2)].instr).isMacro = true; (yyvsp[(1) - (2)].instr).mType = M_USER_MACRO; (yyval.instr) = (yyvsp[(1) - (2)].instr);;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 174 "parser.y"
    {
                        i.iType = (yyvsp[(1) - (6)].iType);
                        i.args = newDArray(ArgumentDArray)(3);
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[(2) - (6)].arg));
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[(4) - (6)].arg));
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[(6) - (6)].arg));
                        (yyval.instr) = i;
                    ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 183 "parser.y"
    {
                        i.iType = I_NOT;
                        i.args = newDArray(ArgumentDArray)(2);
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[(2) - (4)].arg));
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[(4) - (4)].arg));
                        (yyval.instr) = i;
                    ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 191 "parser.y"
    {
                        i.iType = I_JMP;
                        i.args = newDArray(ArgumentDArray)(1);
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[(2) - (2)].arg));
                        (yyval.instr) = i;
                    ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 198 "parser.y"
    {
                        i.iType = I_JMR;
                        i.args = newDArray(ArgumentDArray)(1);
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[(2) - (2)].arg));
                        (yyval.instr) = i;
                    ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 205 "parser.y"
    {
                        i.iType = (yyvsp[(1) - (6)].iType);
                        i.args = newDArray(ArgumentDArray)(3);
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[(2) - (6)].arg));
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[(4) - (6)].arg));
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[(6) - (6)].arg));
                        (yyval.instr) = i;
                    ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 214 "parser.y"
    {
                        i.iType = I_LDI;
                        i.args = newDArray(ArgumentDArray)(2);
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[(2) - (4)].arg));
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[(4) - (4)].arg));
                        (yyval.instr) = i;
                    ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 222 "parser.y"
    {
                        i.iType = (yyvsp[(1) - (6)].iType);
                        i.args = newDArray(ArgumentDArray)(3);
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[(2) - (6)].arg));
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[(4) - (6)].arg));
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[(6) - (6)].arg));
                        (yyval.instr) = i;
                    ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 231 "parser.y"
    {
                        i.iType = (yyvsp[(1) - (4)].iType);
                        i.args = newDArray(ArgumentDArray)(2);
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[(2) - (4)].arg));
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[(4) - (4)].arg));
                        (yyval.instr) = i;
                    ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 239 "parser.y"
    {
                        i.iType = I_LOAD;
                        i.args = newDArray(ArgumentDArray)(2);
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[(2) - (4)].arg));
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[(4) - (4)].arg));
                        (yyval.instr) = i;
                    ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 247 "parser.y"
    {
                        i.iType = I_SAVE;
                        i.args = newDArray(ArgumentDArray)(2);
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[(2) - (4)].arg));
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[(4) - (4)].arg));
                        (yyval.instr) = i;
                    ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 255 "parser.y"
    {
                        i.iType = I_PUSH;
                        i.args = newDArray(ArgumentDArray)(1);
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[(2) - (2)].arg));
                        (yyval.instr) = i;
                    ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 262 "parser.y"
    {
                        i.iType = I_POP;
                        i.args = newDArray(ArgumentDArray)(1);
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[(2) - (2)].arg));
                        (yyval.instr) = i;
                    ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 269 "parser.y"
    {
                        i.iType = I_SVPC; 
                        i.args = newDArray(ArgumentDArray)(1); 
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[(2) - (2)].arg));
                        (yyval.instr) = i;
                    ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 276 "parser.y"
    {
                        i.iType = I_RET; 
                        i.args = newDArray(ArgumentDArray)(0); 
                        (yyval.instr) = i;
                    ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 283 "parser.y"
    {
                    i.mType = M_MOV;
                    i.args = newDArray(ArgumentDArray)(2);
                    daAppend(ArgumentDArray)(&i.args, &(yyvsp[(2) - (4)].arg));
                    daAppend(ArgumentDArray)(&i.args, &(yyvsp[(4) - (4)].arg));
                    (yyval.instr) = i;
                ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 291 "parser.y"
    {
                    i.mType = (yyvsp[(1) - (2)].mType);
                    i.args = newDArray(ArgumentDArray)(1);
                    daAppend(ArgumentDArray)(&i.args, &(yyvsp[(2) - (2)].arg));
                    (yyval.instr) = i;
                ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 298 "parser.y"
    {
                    i.mType = M_CALL;
                    a.type = A_IDENTIFIER;
                    a.text = (yyvsp[(2) - (2)].text);
                    i.args = newDArray(ArgumentDArray)(1);
                    daAppend(ArgumentDArray)(&i.args, &a);
                    (yyval.instr) = i;
                ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 307 "parser.y"
    {
                    i.mType = M_HALT; 
                    i.args = newDArray(ArgumentDArray)(1);
                    (yyval.instr) = i;
                ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 313 "parser.y"
    {
                    i.mType = M_NOP; 
                    i.args = newDArray(ArgumentDArray)(3);
                    (yyval.instr) = i;
                ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 319 "parser.y"
    {
                    i.mType = M_DW;
                    i.args = newDArray(ArgumentDArray)(1);
                    daAppend(ArgumentDArray)(&i.args, &(yyvsp[(2) - (2)].arg));
                    (yyval.instr) = i;
                ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 326 "parser.y"
    {
                    i.mType = M_DW;
                    a.type = A_STRING;
                    a.text = (yyvsp[(2) - (2)].text);
                    i.args = newDArray(ArgumentDArray)(1);
                    daAppend(ArgumentDArray)(&i.args, &a);
                    (yyval.instr) = i;
                ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 337 "parser.y"
    {
                    i.args = newDArray(ArgumentDArray)(1);
                    a.type = A_IDENTIFIER;
                    a.text = (yyvsp[(2) - (2)].text);
                    daAppend(ArgumentDArray)(&i.args, &a);
                    (yyval.instr) = i;
                ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 345 "parser.y"
    {
                    i.args = newDArray(ArgumentDArray)(4);
                    a.type = A_IDENTIFIER;
                    a.text = (yyvsp[(2) - (3)].text);
                    daAppend(ArgumentDArray)(&i.args, &a);
                    daAppend(ArgumentDArray)(&i.args, &(yyvsp[(3) - (3)].arg));
                    (yyval.instr) = i;
                ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 354 "parser.y"
    {
                    daAppend(ArgumentDArray)(&(yyvsp[(1) - (3)].instr).args, &(yyvsp[(3) - (3)].arg));
                    (yyval.instr) = (yyvsp[(1) - (3)].instr);
                ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 359 "parser.y"
    {(yyval.iType) = I_ADD;;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 360 "parser.y"
    {(yyval.iType) = I_ADC;;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 361 "parser.y"
    {(yyval.iType) = I_SUB;;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 362 "parser.y"
    {(yyval.iType) = I_SBC;;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 363 "parser.y"
    {(yyval.iType) = I_MUL;;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 364 "parser.y"
    {(yyval.iType) = I_MLL;;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 365 "parser.y"
    {(yyval.iType) = I_SGN;;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 366 "parser.y"
    {(yyval.iType) = I_RAS;;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 367 "parser.y"
    {(yyval.iType) = I_LSH;;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 368 "parser.y"
    {(yyval.iType) = I_RSH;;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 369 "parser.y"
    {(yyval.iType) = I_LRT;;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 370 "parser.y"
    {(yyval.iType) = I_RRT;;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 371 "parser.y"
    {(yyval.iType) = I_AND;;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 372 "parser.y"
    {(yyval.iType) = I_OR;;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 373 "parser.y"
    {(yyval.iType) = I_XOR;;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 376 "parser.y"
    {(yyval.iType) = I_ADDI;;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 377 "parser.y"
    {(yyval.iType) = I_ADCI;;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 378 "parser.y"
    {(yyval.iType) = I_SUBI;;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 379 "parser.y"
    {(yyval.iType) = I_SBCI;;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 380 "parser.y"
    {(yyval.iType) = I_ANDI;;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 381 "parser.y"
    {(yyval.iType) = I_ORI;;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 382 "parser.y"
    {(yyval.iType) = I_XORI;;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 385 "parser.y"
    {(yyval.iType) = I_LSHI;;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 386 "parser.y"
    {(yyval.iType) = I_RSHI;;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 387 "parser.y"
    {(yyval.iType) = I_LRTI;;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 388 "parser.y"
    {(yyval.iType) = I_RRTI;;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 391 "parser.y"
    {(yyval.iType) = I_JFC;;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 392 "parser.y"
    {(yyval.iType) = I_JFS;;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 395 "parser.y"
    {(yyval.mType) = M_JVC;;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 396 "parser.y"
    {(yyval.mType) = M_JVS;;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 397 "parser.y"
    {(yyval.mType) = M_JNE;;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 398 "parser.y"
    {(yyval.mType) = M_JEQ;;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 399 "parser.y"
    {(yyval.mType) = M_JGE;;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 400 "parser.y"
    {(yyval.mType) = M_JLT;;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 401 "parser.y"
    {(yyval.mType) = M_JCC;;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 402 "parser.y"
    {(yyval.mType) = M_JCS;;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 405 "parser.y"
    {(yyval.arg) = (yyvsp[(1) - (1)].arg);;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 406 "parser.y"
    {(yyval.arg) = (yyvsp[(1) - (1)].arg);;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 407 "parser.y"
    {(yyval.arg) = (yyvsp[(1) - (1)].arg);;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 409 "parser.y"
    {(yyval.arg) = (yyvsp[(1) - (1)].arg);;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 410 "parser.y"
    {a.type = A_MACRO_ARG; a.iVal = (yyvsp[(2) - (2)].iVal); (yyval.arg) = a;;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 413 "parser.y"
    {(yyval.arg) = (yyvsp[(1) - (1)].arg);;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 414 "parser.y"
    {(yyval.arg) = (yyvsp[(1) - (1)].arg);;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 415 "parser.y"
    {a.type = A_ZERO; a.iVal = 0; (yyval.arg) = a;;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 417 "parser.y"
    {(yyval.arg) = (yyvsp[(1) - (1)].arg);;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 418 "parser.y"
    {a.type = A_MACRO_ARG; a.iVal = (yyvsp[(2) - (2)].iVal); (yyval.arg) = a;;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 420 "parser.y"
    {(yyval.arg) = (yyvsp[(1) - (1)].arg);;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 421 "parser.y"
    {a.type = A_REGISTER; a.rType = REG_SP; (yyval.arg) = a;;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 424 "parser.y"
    {a.type = A_REGISTER; a.rType = REG_A; (yyval.arg) = a;;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 425 "parser.y"
    {a.type = A_REGISTER; a.rType = REG_B; (yyval.arg) = a;;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 426 "parser.y"
    {a.type = A_REGISTER; a.rType = REG_C; (yyval.arg) = a;;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 428 "parser.y"
    {(yyval.arg) = (yyvsp[(1) - (1)].arg);;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 429 "parser.y"
    {a.type = A_MACRO_ARG; a.iVal = (yyvsp[(2) - (2)].iVal); (yyval.arg) = a;;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 432 "parser.y"
    {(yyvsp[(1) - (1)].arg).type = A_ABSOLUTE; (yyval.arg) = (yyvsp[(1) - (1)].arg);;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 433 "parser.y"
    {(yyvsp[(1) - (1)].arg).type = A_INDEX; (yyval.arg) = (yyvsp[(1) - (1)].arg);;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 434 "parser.y"
    {(yyvsp[(1) - (1)].arg).type = A_ADDRESSED; (yyval.arg) = (yyvsp[(1) - (1)].arg);;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 435 "parser.y"
    {(yyvsp[(1) - (1)].arg).type = A_STACK; (yyval.arg) = (yyvsp[(1) - (1)].arg);;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 438 "parser.y"
    {a.type = A_FASTMEM; a.iVal = (yyvsp[(2) - (2)].iVal); (yyval.arg) = a;;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 439 "parser.y"
    {a.type = A_FASTMEM; a.iVal = 0; (yyval.arg) = a;;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 441 "parser.y"
    {a.type = A_CONSTANT; a.iVal = (yyvsp[(1) - (1)].iVal); (yyval.arg) = a;;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 442 "parser.y"
    {a.type = A_CONSTANT; a.iVal = (yyvsp[(1) - (1)].iVal); (yyval.arg) = a;;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 443 "parser.y"
    {a.type = A_CONSTANT; a.iVal = (yyvsp[(1) - (1)].iVal); (yyval.arg) = a;;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 444 "parser.y"
    {a.type = A_CONSTANT; a.iVal = (yyvsp[(1) - (1)].iVal); (yyval.arg) = a;;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 445 "parser.y"
    {a.type = A_ZERO; a.iVal = 0; (yyval.arg) = a;;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 446 "parser.y"
    {a.type = A_IDENTIFIER; a.text = (yyvsp[(1) - (1)].text); (yyval.arg) = a;;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 447 "parser.y"
    {a.type = A_ID_HIGH; a.text = (yyvsp[(1) - (2)].text); (yyval.arg) = a;;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 448 "parser.y"
    {a.type = A_ID_LOW; a.text = (yyvsp[(1) - (2)].text); (yyval.arg) = a;;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 450 "parser.y"
    {(yyval.arg) = (yyvsp[(1) - (1)].arg);;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 451 "parser.y"
    {(yyval.arg) = (yyvsp[(1) - (1)].arg);;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 452 "parser.y"
    {(yyvsp[(2) - (4)].arg).type = A_SUM_HIGH; (yyval.arg) = (yyvsp[(2) - (4)].arg);;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 453 "parser.y"
    {(yyvsp[(2) - (4)].arg).type = A_SUM_LOW; (yyval.arg) = (yyvsp[(2) - (4)].arg);;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 456 "parser.y"
    {
                    if ((yyvsp[(3) - (3)].arg).type == A_SUM) {
                        daAppend(ArgumentDArray)((yyvsp[(3) - (3)].arg).sum, &(yyvsp[(1) - (3)].arg));
                        (yyval.arg) = (yyvsp[(3) - (3)].arg);
                    } else {
                        a.type = A_SUM;
                        a.sum = (ArgumentDArray*) malloc(sizeof(ArgumentDArray));
                        *a.sum = newDArray(ArgumentDArray)(2);
                        daAppend(ArgumentDArray)(a.sum, &(yyvsp[(1) - (3)].arg));
                        daAppend(ArgumentDArray)(a.sum, &(yyvsp[(3) - (3)].arg));
                        (yyval.arg) = a;
                    }
                ;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 470 "parser.y"
    {(yyval.arg) = (yyvsp[(1) - (1)].arg);;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 471 "parser.y"
    {a.type = A_MACRO_ARG; a.iVal = (yyvsp[(2) - (2)].iVal); (yyval.arg) = a;;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 476 "parser.y"
    {a.text = (yyvsp[(2) - (2)].text); (yyval.arg) = a;;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 478 "parser.y"
    {
                    a.text = (yyvsp[(1) - (4)].text);
                    a.type = A_IDENTIFIER;
                    if ((yyvsp[(3) - (4)].arg).type == A_SUM) {
                        daAppend(ArgumentDArray)((yyvsp[(3) - (4)].arg).sum, &a);
                        (yyval.arg) = (yyvsp[(3) - (4)].arg);
                    } else {
                        (yyval.arg).sum = (ArgumentDArray*) malloc(sizeof(ArgumentDArray));
                        *(yyval.arg).sum = newDArray(ArgumentDArray)(2);
                        daAppend(ArgumentDArray)((yyval.arg).sum, &(yyvsp[(3) - (4)].arg));
                        daAppend(ArgumentDArray)((yyval.arg).sum, &a);
                    }
                ;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 491 "parser.y"
    {a.rType = REG_A; (yyval.arg) = a;;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 492 "parser.y"
    {a.iVal = (yyvsp[(2) - (3)].arg).iVal; (yyval.arg) = a;;}
    break;



/* Line 1455 of yacc.c  */
#line 2782 "source/parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (result, userMacros, filename, YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (result, userMacros, filename, yymsg);
	  }
	else
	  {
	    yyerror (result, userMacros, filename, YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, &yylloc, result, userMacros, filename);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[0] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp, result, userMacros, filename);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (result, userMacros, filename, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc, result, userMacros, filename);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp, result, userMacros, filename);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 494 "parser.y"



void yyerror (InstructionList *result, UserMacroTable *userMacros, char *filename, char const *s)
{
  fprintf (stderr, "%d in %s:%s\n", lineno, filename, s);
}


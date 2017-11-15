
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
    void yyerror(InstructionList *result, UserMacroTable *userMacros, const char *s);
    int calcLength (char *str);
    int yylineno;


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

/* Line 214 of yacc.c  */
#line 19 "parser.y"

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
#line 207 "source/parser.tab.c"
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
#line 232 "source/parser.tab.c"

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
#define YYLAST   229

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  83
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  124
/* YYNRULES -- Number of states.  */
#define YYNSTATES  194

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   325

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      71,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    77,     2,     2,     2,
      79,    80,    82,    81,    76,     2,     2,     2,    78,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    72,     2,
       2,    73,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    74,     2,    75,     2,     2,     2,     2,     2,     2,
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
      65,    66,    67,    68,    69,    70
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,    10,    11,    15,    18,    21,
      22,    26,    27,    31,    36,    37,    48,    52,    53,    55,
      59,    61,    63,    65,    67,    70,    73,    76,    83,    88,
      91,    98,   103,   110,   115,   118,   121,   124,   126,   128,
     133,   136,   139,   141,   144,   147,   150,   154,   158,   160,
     162,   164,   166,   168,   170,   172,   174,   176,   178,   180,
     182,   184,   186,   188,   190,   192,   194,   196,   198,   200,
     202,   204,   206,   208,   210,   212,   214,   216,   218,   220,
     222,   224,   226,   228,   230,   232,   234,   236,   238,   240,
     242,   245,   247,   249,   251,   253,   256,   258,   260,   262,
     264,   266,   268,   271,   273,   275,   277,   279,   281,   283,
     285,   287,   289,   291,   294,   297,   299,   304,   309,   313,
     315,   318,   321,   326,   329
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      84,     0,    -1,    85,    -1,    -1,    85,    86,    95,    -1,
      -1,    85,    87,    89,    -1,    85,    71,    -1,    85,    90,
      -1,    -1,    85,    88,    92,    -1,    -1,    65,    72,    71,
      -1,    65,    73,   115,    71,    -1,    -1,    52,    65,    74,
      93,    75,    71,    91,    85,    53,    71,    -1,    54,    66,
      71,    -1,    -1,    94,    -1,    93,    76,    94,    -1,    55,
      -1,    56,    -1,    57,    -1,    58,    -1,    96,    71,    -1,
      97,    71,    -1,    98,    71,    -1,    99,   106,    76,   111,
      76,   108,    -1,    18,   106,    76,   108,    -1,    19,   115,
      -1,   100,   109,    76,   115,    76,   109,    -1,    27,   115,
      76,   109,    -1,   101,   106,    76,   115,    76,   108,    -1,
     102,   115,    76,   115,    -1,   103,   115,    -1,    36,   106,
      -1,    37,   108,    -1,    38,    -1,    39,    -1,    40,   106,
      76,   108,    -1,   104,   115,    -1,    49,    65,    -1,    50,
      -1,    51,   115,    -1,    51,    66,    -1,    77,    65,    -1,
      77,    65,   106,    -1,    98,    76,   106,    -1,     3,    -1,
       4,    -1,     5,    -1,     6,    -1,     7,    -1,     8,    -1,
       9,    -1,    10,    -1,    11,    -1,    12,    -1,    13,    -1,
      14,    -1,    15,    -1,    16,    -1,    17,    -1,    20,    -1,
      21,    -1,    22,    -1,    23,    -1,    24,    -1,    25,    -1,
      26,    -1,    28,    -1,    29,    -1,    30,    -1,    31,    -1,
      32,    -1,    33,    -1,    34,    -1,    35,    -1,    41,    -1,
      42,    -1,    43,    -1,    44,    -1,    45,    -1,    46,    -1,
      47,    -1,    48,    -1,   110,    -1,   112,    -1,   113,    -1,
     105,    -1,    77,    69,    -1,   110,    -1,   112,    -1,    78,
      -1,   107,    -1,    77,    69,    -1,   108,    -1,    62,    -1,
      59,    -1,    60,    -1,    61,    -1,   110,    -1,    77,    69,
      -1,   116,    -1,   117,    -1,   118,    -1,   119,    -1,    67,
      -1,    68,    -1,    69,    -1,    70,    -1,    78,    -1,    65,
      -1,    65,    63,    -1,    65,    64,    -1,   114,    -1,    79,
     114,    80,    63,    -1,    79,   114,    80,    64,    -1,   113,
      81,   115,    -1,   113,    -1,    77,    69,    -1,    82,    65,
      -1,    65,    74,   115,    75,    -1,    82,    59,    -1,    74,
     115,    75,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    75,    75,    78,    78,    83,    83,    89,    91,    92,
      92,    98,   104,   113,   126,   125,   138,   149,   150,   151,
     154,   155,   156,   157,   161,   162,   163,   165,   174,   182,
     189,   198,   206,   215,   223,   230,   237,   244,   250,   257,
     265,   272,   281,   287,   294,   305,   313,   322,   328,   329,
     330,   331,   332,   333,   334,   335,   336,   337,   338,   339,
     340,   341,   342,   345,   346,   347,   348,   349,   350,   351,
     354,   355,   356,   357,   360,   361,   363,   364,   367,   368,
     369,   370,   371,   372,   373,   374,   377,   378,   379,   381,
     382,   385,   386,   387,   389,   390,   392,   393,   396,   397,
     398,   400,   401,   404,   405,   406,   407,   410,   411,   412,
     413,   414,   415,   416,   417,   418,   419,   420,   422,   437,
     438,   443,   444,   458,   459
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ADD", "ADC", "SUB", "SBC", "MUL", "MLL",
  "SGN", "RAS", "LSH", "RSH", "LRT", "RRT", "AND", "OR", "XOR", "NOT",
  "JMP", "ADDI", "ADCI", "SUBI", "SBCI", "ANDI", "ORI", "XORI", "LDI",
  "LSHI", "RSHI", "LRTI", "RRTI", "JFC", "JFS", "FLC", "FLS", "PUSH",
  "POP", "SVPC", "RET", "MOV", "JVC", "JVS", "JNE", "JEQ", "JGE", "JLT",
  "JCC", "JCS", "CALL", "HALT", "DW", "DEFMACRO", "ENDDEF", "INCLUDE",
  "REG", "REGMEM", "REGMEMIMM", "IMM", "A", "B", "C", "SP", "HIGH", "LOW",
  "IDENTIFIER", "STRING", "HEX", "BINARY", "DECIMAL", "CHAR", "'\\n'",
  "':'", "'='", "'['", "']'", "','", "'$'", "'0'", "'('", "')'", "'+'",
  "'*'", "$accept", "program", "instruction_list", "$@1", "$@2", "$@3",
  "label", "macro_definition", "$@4", "include_directive",
  "parameter_list", "param_type", "instruction", "simple_instr",
  "macro_instr", "user_macro", "a_type", "i_type", "si_type", "jfg_type",
  "flg_type", "jfg_macro", "reg_mem_imm_without_macro_arg", "reg_mem_imm",
  "dest_without_macro_arg", "dest", "dest_sp", "reg_without_macro_arg",
  "reg", "mem", "imm_without_macro_arg", "imm_sum", "imm", "absolute",
  "index", "addressed", "stack", 0
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
     325,    10,    58,    61,    91,    93,    44,    36,    48,    40,
      41,    43,    42
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    83,    84,    86,    85,    87,    85,    85,    85,    88,
      85,    85,    89,    89,    91,    90,    92,    93,    93,    93,
      94,    94,    94,    94,    95,    95,    95,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    97,
      97,    97,    97,    97,    97,    98,    98,    98,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,   100,   100,   100,   100,   100,   100,   100,
     101,   101,   101,   101,   102,   102,   103,   103,   104,   104,
     104,   104,   104,   104,   104,   104,   105,   105,   105,   106,
     106,   107,   107,   107,   108,   108,   109,   109,   110,   110,
     110,   111,   111,   112,   112,   112,   112,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   114,   115,
     115,   116,   117,   118,   119
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     3,     0,     3,     2,     2,     0,
       3,     0,     3,     4,     0,    10,     3,     0,     1,     3,
       1,     1,     1,     1,     2,     2,     2,     6,     4,     2,
       6,     4,     6,     4,     2,     2,     2,     1,     1,     4,
       2,     2,     1,     2,     2,     2,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     1,     1,     1,     2,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     1,     4,     4,     3,     1,
       2,     2,     4,     2,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      11,     0,     3,     1,     0,     7,     0,     0,     0,     8,
       0,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,     0,     0,    63,    64,
      65,    66,    67,    68,    69,     0,    70,    71,    72,    73,
      74,    75,    76,    77,     0,     0,    37,    38,     0,    78,
      79,    80,    81,    82,    83,    84,    85,     0,    42,     0,
       0,     4,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     6,     0,    10,    17,    98,    99,   100,   112,
     107,   108,   109,   110,     0,     0,   111,     0,     0,    89,
       0,    86,    87,    88,   115,   103,   104,   105,   106,   112,
       0,   119,    29,     0,    35,     0,     0,    93,    94,    36,
      91,    92,     0,    41,    44,    43,    45,    24,    25,    26,
       0,     0,    97,    96,     0,     0,     0,    34,    40,     0,
       0,     0,    20,    21,    22,    23,     0,    18,   113,   114,
       0,     0,    90,     0,   115,   123,   121,     0,     0,   120,
       0,    95,     0,    46,    47,     0,     0,     0,     0,    12,
       0,    16,     0,     0,     0,   124,     0,    28,   118,    31,
      39,     0,   101,     0,     0,     0,    33,    13,    14,    19,
     122,   116,   117,   102,     0,     0,     0,    11,    27,    30,
      32,     3,     0,    15
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     6,     7,     8,    72,     9,   187,    74,
     136,   137,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    89,    90,   108,   123,   124,   110,   173,   111,
     101,    94,   102,    95,    96,    97,    98
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -141
static const yytype_int16 yypact[] =
{
    -141,    47,     4,  -141,   -57,  -141,   139,   -21,     1,  -141,
     -17,  -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,
    -141,  -141,  -141,  -141,  -141,  -141,   132,    50,  -141,  -141,
    -141,  -141,  -141,  -141,  -141,    50,  -141,  -141,  -141,  -141,
    -141,  -141,  -141,  -141,   132,   -43,  -141,  -141,   132,  -141,
    -141,  -141,  -141,  -141,  -141,  -141,  -141,    -4,  -141,    44,
      11,  -141,     7,     9,   -65,   132,     5,   132,    50,    50,
      50,   -40,  -141,    19,  -141,    48,  -141,  -141,  -141,    10,
    -141,  -141,  -141,  -141,    50,    17,  -141,   150,   -44,  -141,
      12,  -141,  -141,    13,  -141,  -141,  -141,  -141,  -141,   -10,
      20,    13,  -141,    14,  -141,    25,    24,  -141,  -141,  -141,
    -141,  -141,    55,  -141,  -141,  -141,   132,  -141,  -141,  -141,
     132,    56,  -141,  -141,    57,    58,    59,  -141,  -141,    29,
      50,    65,  -141,  -141,  -141,  -141,   -16,  -141,  -141,  -141,
      50,    62,  -141,    13,    60,  -141,  -141,   -43,    50,  -141,
       5,  -141,   -43,  -141,  -141,   -47,    50,    50,    50,  -141,
      67,  -141,   123,    48,   120,  -141,     8,  -141,  -141,  -141,
    -141,   127,  -141,   122,   128,   129,  -141,  -141,  -141,  -141,
    -141,  -141,  -141,  -141,   -43,     5,   -43,  -141,  -141,  -141,
    -141,    -3,   136,  -141
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -141,  -141,    16,  -141,  -141,  -141,  -141,  -141,  -141,  -141,
    -141,    45,  -141,  -141,  -141,  -141,  -141,  -141,  -141,  -141,
    -141,  -141,  -141,   -39,  -141,   -45,  -140,   -25,  -141,   -19,
     -24,   125,   -32,  -141,  -141,  -141,  -141
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -10
static const yytype_int16 yytable[] =
{
     109,    91,    93,   103,    -2,   104,   119,    92,    10,   112,
     169,   120,    76,    77,    78,   145,    76,    77,    78,    91,
      93,   146,   105,    91,    93,    92,   121,   115,   125,    92,
     171,    84,   129,   130,   106,   107,   126,   127,   128,    88,
      91,    93,    91,    93,    71,   189,    92,     3,    92,     4,
     192,    -9,   141,   138,   139,    73,     4,    75,    -9,   162,
     163,   113,    -5,   143,    76,    77,    78,   122,     5,    -5,
     105,   181,   182,   138,   139,     5,   116,   153,   117,    84,
     118,   154,   106,   107,   140,   131,   142,    88,   147,   149,
     150,    91,    93,   151,   148,    91,    93,    92,   160,   140,
     159,    92,   167,   132,   133,   134,   135,   170,   164,    99,
     114,    80,    81,    82,    83,    99,   168,    80,    81,    82,
      83,   100,    86,    87,   174,   175,   176,   100,    86,    87,
     172,   152,   155,   156,   157,   158,   161,   165,   177,   188,
     166,   190,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    76,    77,    78,   178,   180,   183,    79,   184,    80,
      81,    82,    83,   191,   185,   186,    84,   193,   179,    85,
      86,    87,   144,     0,    88,    99,    60,    80,    81,    82,
      83,     0,     0,     0,     0,     0,     0,     0,    86,    87
};

static const yytype_int16 yycheck[] =
{
      45,    26,    26,    35,     0,    44,    71,    26,    65,    48,
     150,    76,    59,    60,    61,    59,    59,    60,    61,    44,
      44,    65,    65,    48,    48,    44,    65,    59,    67,    48,
      77,    74,    72,    73,    77,    78,    68,    69,    70,    82,
      65,    65,    67,    67,    65,   185,    65,     0,    67,    52,
      53,    54,    84,    63,    64,    54,    52,    74,    54,    75,
      76,    65,    65,    87,    59,    60,    61,    62,    71,    65,
      65,    63,    64,    63,    64,    71,    65,   116,    71,    74,
      71,   120,    77,    78,    74,    66,    69,    82,    76,    69,
      76,   116,   116,    69,    81,   120,   120,   116,   130,    74,
      71,   120,   147,    55,    56,    57,    58,   152,   140,    65,
      66,    67,    68,    69,    70,    65,   148,    67,    68,    69,
      70,    77,    78,    79,   156,   157,   158,    77,    78,    79,
     155,    76,    76,    76,    76,    76,    71,    75,    71,   184,
      80,   186,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    59,    60,    61,    71,    75,    69,    65,    76,    67,
      68,    69,    70,   187,    76,    76,    74,    71,   163,    77,
      78,    79,    87,    -1,    82,    65,    77,    67,    68,    69,
      70,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    84,    85,     0,    52,    71,    86,    87,    88,    90,
      65,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      77,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,    65,    89,    54,    92,    74,    59,    60,    61,    65,
      67,    68,    69,    70,    74,    77,    78,    79,    82,   105,
     106,   110,   112,   113,   114,   116,   117,   118,   119,    65,
      77,   113,   115,   115,   106,    65,    77,    78,   107,   108,
     110,   112,   106,    65,    66,   115,    65,    71,    71,    71,
      76,   106,    62,   108,   109,   106,   115,   115,   115,    72,
      73,    66,    55,    56,    57,    58,    93,    94,    63,    64,
      74,   115,    69,   113,   114,    59,    65,    76,    81,    69,
      76,    69,    76,   106,   106,    76,    76,    76,    76,    71,
     115,    71,    75,    76,   115,    75,    80,   108,   115,   109,
     108,    77,   110,   111,   115,   115,   115,    71,    71,    94,
      75,    63,    64,    69,    76,    76,    76,    91,   108,   109,
     108,    85,    53,    71
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
      yyerror (result, userMacros, YY_("syntax error: cannot back up")); \
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
		  Type, Value, Location, result, userMacros); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, InstructionList *result, UserMacroTable *userMacros)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, result, userMacros)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    InstructionList *result;
    UserMacroTable *userMacros;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
  YYUSE (result);
  YYUSE (userMacros);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, InstructionList *result, UserMacroTable *userMacros)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp, result, userMacros)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
    InstructionList *result;
    UserMacroTable *userMacros;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, result, userMacros);
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
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, InstructionList *result, UserMacroTable *userMacros)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule, result, userMacros)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
    InstructionList *result;
    UserMacroTable *userMacros;
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
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       , result, userMacros);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule, result, userMacros); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, InstructionList *result, UserMacroTable *userMacros)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp, result, userMacros)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
    InstructionList *result;
    UserMacroTable *userMacros;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (result);
  YYUSE (userMacros);

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
int yyparse (InstructionList *result, UserMacroTable *userMacros);
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
yyparse (InstructionList *result, UserMacroTable *userMacros)
#else
int
yyparse (result, userMacros)
    InstructionList *result;
    UserMacroTable *userMacros;
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
#line 75 "parser.y"
    {*result = (yyvsp[(1) - (1)].iList);;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 78 "parser.y"
    {memset(&i, 0, sizeof i);;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 79 "parser.y"
    {
                        llAppend(InstructionList)(&(yyvsp[(1) - (3)].iList), (yyvsp[(3) - (3)].instr));
                        (yyval.iList) = (yyvsp[(1) - (3)].iList);
                    ;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 83 "parser.y"
    {memset(&i, 0, sizeof i);;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 84 "parser.y"
    {
                        (yyvsp[(3) - (3)].instr).isMacro = true; 
                        llAppend(InstructionList)(&(yyvsp[(1) - (3)].iList), (yyvsp[(3) - (3)].instr));
                        (yyval.iList) = (yyvsp[(1) - (3)].iList);
                    ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 90 "parser.y"
    {(yyval.iList) = (yyvsp[(1) - (2)].iList);;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 92 "parser.y"
    {memset(&i, 0, sizeof i);;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 93 "parser.y"
    {
                        llAppend(InstructionList)(&(yyvsp[(1) - (3)].iList), (yyvsp[(3) - (3)].instr));
                        (yyval.iList) = (yyvsp[(1) - (3)].iList);
                    ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 98 "parser.y"
    {
                        (yyval.iList) = newLList(InstructionList)(&dstrInstr);
                        isInUserMacroDef = false;
                    ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 105 "parser.y"
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
#line 114 "parser.y"
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
#line 126 "parser.y"
    {
                        isInUserMacroDef = true;
                        currUserMacro.paramTypes = (yyvsp[(4) - (6)].paramTypes);
                    ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 131 "parser.y"
    {
                        isInUserMacroDef = false;
                        currUserMacro.instrs = (yyvsp[(8) - (10)].iList);
                        rbtSet(UserMacroTable)(userMacros, (yyvsp[(2) - (10)].text), currUserMacro);
                    ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 138 "parser.y"
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
#line 149 "parser.y"
    {(yyval.paramTypes) = newDArray(ParamTypeDArray)(0);;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 150 "parser.y"
    {(yyval.paramTypes) = newDArray(ParamTypeDArray)(3); daAppend(ParamTypeDArray)(&(yyval.paramTypes), &(yyvsp[(1) - (1)].pType));;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 151 "parser.y"
    {daAppend(ParamTypeDArray)(&(yyvsp[(1) - (3)].paramTypes), &(yyvsp[(3) - (3)].pType)); (yyval.paramTypes) = (yyvsp[(1) - (3)].paramTypes);;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 154 "parser.y"
    {(yyval.pType) = P_REG;;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 155 "parser.y"
    {(yyval.pType) = P_REG_MEM;;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 156 "parser.y"
    {(yyval.pType) = P_REG_MEM_IMM;;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 157 "parser.y"
    {(yyval.pType) = P_IMM;;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 161 "parser.y"
    {(yyvsp[(1) - (2)].instr).isMacro = false; (yyval.instr) = (yyvsp[(1) - (2)].instr);;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 162 "parser.y"
    {(yyvsp[(1) - (2)].instr).isMacro = true; (yyval.instr) = (yyvsp[(1) - (2)].instr);;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 163 "parser.y"
    {(yyvsp[(1) - (2)].instr).isMacro = true; (yyvsp[(1) - (2)].instr).mType = M_USER_MACRO; (yyval.instr) = (yyvsp[(1) - (2)].instr);;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 166 "parser.y"
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
#line 175 "parser.y"
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
#line 183 "parser.y"
    {
                        i.iType = I_JMP;
                        i.args = newDArray(ArgumentDArray)(1);
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[(2) - (2)].arg));
                        (yyval.instr) = i;
                    ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 190 "parser.y"
    {
                        i.iType = (yyvsp[(1) - (6)].iType);
                        i.args = newDArray(ArgumentDArray)(3);
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[(2) - (6)].arg));
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[(4) - (6)].arg));
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[(6) - (6)].arg));
                        (yyval.instr) = i;
                    ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 199 "parser.y"
    {
                        i.iType = I_LDI;
                        i.args = newDArray(ArgumentDArray)(2);
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[(2) - (4)].arg));
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[(4) - (4)].arg));
                        (yyval.instr) = i;
                    ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 207 "parser.y"
    {
                        i.iType = (yyvsp[(1) - (6)].iType);
                        i.args = newDArray(ArgumentDArray)(3);
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[(2) - (6)].arg));
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[(4) - (6)].arg));
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[(6) - (6)].arg));
                        (yyval.instr) = i;
                    ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 216 "parser.y"
    {
                        i.iType = (yyvsp[(1) - (4)].iType);
                        i.args = newDArray(ArgumentDArray)(2);
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[(2) - (4)].arg));
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[(4) - (4)].arg));
                        (yyval.instr) = i;
                    ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 224 "parser.y"
    {
                        i.iType = (yyvsp[(1) - (2)].iType);
                        i.args = newDArray(ArgumentDArray)(1);
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[(2) - (2)].arg));
                        (yyval.instr) = i;
                    ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 231 "parser.y"
    {
                        i.iType = I_PUSH;
                        i.args = newDArray(ArgumentDArray)(1);
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[(2) - (2)].arg));
                        (yyval.instr) = i;
                    ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 238 "parser.y"
    {
                        i.iType = I_POP;
                        i.args = newDArray(ArgumentDArray)(1);
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[(2) - (2)].arg));
                        (yyval.instr) = i;
                    ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 245 "parser.y"
    {
                        i.iType = I_SVPC; 
                        i.args = newDArray(ArgumentDArray)(0); 
                        (yyval.instr) = i;
                    ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 251 "parser.y"
    {
                        i.iType = I_RET; 
                        i.args = newDArray(ArgumentDArray)(0); 
                        (yyval.instr) = i;
                    ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 258 "parser.y"
    {
                    i.mType = M_MOV;
                    i.args = newDArray(ArgumentDArray)(2);
                    daAppend(ArgumentDArray)(&i.args, &(yyvsp[(2) - (4)].arg));
                    daAppend(ArgumentDArray)(&i.args, &(yyvsp[(4) - (4)].arg));
                    (yyval.instr) = i;
                ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 266 "parser.y"
    {
                    i.mType = (yyvsp[(1) - (2)].mType);
                    i.args = newDArray(ArgumentDArray)(1);
                    daAppend(ArgumentDArray)(&i.args, &(yyvsp[(2) - (2)].arg));
                    (yyval.instr) = i;
                ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 273 "parser.y"
    {
                    i.mType = M_CALL;
                    a.type = A_IDENTIFIER;
                    a.text = (yyvsp[(2) - (2)].text);
                    i.args = newDArray(ArgumentDArray)(1);
                    daAppend(ArgumentDArray)(&i.args, &a);
                    (yyval.instr) = i;
                ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 282 "parser.y"
    {
                    i.mType = M_HALT; 
                    i.args = newDArray(ArgumentDArray)(1);
                    (yyval.instr) = i;
                ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 288 "parser.y"
    {
                    i.mType = M_DW;
                    i.args = newDArray(ArgumentDArray)(1);
                    daAppend(ArgumentDArray)(&i.args, &(yyvsp[(2) - (2)].arg));
                    (yyval.instr) = i;
                ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 295 "parser.y"
    {
                    i.mType = M_DW;
                    a.type = A_STRING;
                    a.text = (yyvsp[(2) - (2)].text);
                    i.args = newDArray(ArgumentDArray)(1);
                    daAppend(ArgumentDArray)(&i.args, &a);
                    (yyval.instr) = i;
                ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 306 "parser.y"
    {
                    i.args = newDArray(ArgumentDArray)(1);
                    a.type = A_IDENTIFIER;
                    a.text = (yyvsp[(2) - (2)].text);
                    daAppend(ArgumentDArray)(&i.args, &a);
                    (yyval.instr) = i;
                ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 314 "parser.y"
    {
                    i.args = newDArray(ArgumentDArray)(4);
                    a.type = A_IDENTIFIER;
                    a.text = (yyvsp[(2) - (3)].text);
                    daAppend(ArgumentDArray)(&i.args, &a);
                    daAppend(ArgumentDArray)(&i.args, &(yyvsp[(3) - (3)].arg));
                    (yyval.instr) = i;
                ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 323 "parser.y"
    {
                    daAppend(ArgumentDArray)(&(yyvsp[(1) - (3)].instr).args, &(yyvsp[(3) - (3)].arg));
                    (yyval.instr) = (yyvsp[(1) - (3)].instr);
                ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 328 "parser.y"
    {(yyval.iType) = I_ADD;;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 329 "parser.y"
    {(yyval.iType) = I_ADC;;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 330 "parser.y"
    {(yyval.iType) = I_SUB;;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 331 "parser.y"
    {(yyval.iType) = I_SBC;;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 332 "parser.y"
    {(yyval.iType) = I_MUL;;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 333 "parser.y"
    {(yyval.iType) = I_MLL;;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 334 "parser.y"
    {(yyval.iType) = I_SGN;;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 335 "parser.y"
    {(yyval.iType) = I_RAS;;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 336 "parser.y"
    {(yyval.iType) = I_LSH;;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 337 "parser.y"
    {(yyval.iType) = I_RSH;;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 338 "parser.y"
    {(yyval.iType) = I_LRT;;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 339 "parser.y"
    {(yyval.iType) = I_RRT;;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 340 "parser.y"
    {(yyval.iType) = I_AND;;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 341 "parser.y"
    {(yyval.iType) = I_OR;;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 342 "parser.y"
    {(yyval.iType) = I_XOR;;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 345 "parser.y"
    {(yyval.iType) = I_ADDI;;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 346 "parser.y"
    {(yyval.iType) = I_ADCI;;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 347 "parser.y"
    {(yyval.iType) = I_SUBI;;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 348 "parser.y"
    {(yyval.iType) = I_SBCI;;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 349 "parser.y"
    {(yyval.iType) = I_ANDI;;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 350 "parser.y"
    {(yyval.iType) = I_ORI;;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 351 "parser.y"
    {(yyval.iType) = I_XORI;;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 354 "parser.y"
    {(yyval.iType) = I_LSHI;;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 355 "parser.y"
    {(yyval.iType) = I_RSHI;;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 356 "parser.y"
    {(yyval.iType) = I_LRTI;;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 357 "parser.y"
    {(yyval.iType) = I_RRTI;;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 360 "parser.y"
    {(yyval.iType) = I_JFC;;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 361 "parser.y"
    {(yyval.iType) = I_JFS;;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 363 "parser.y"
    {(yyval.iType) = I_FLC;;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 364 "parser.y"
    {(yyval.iType) = I_FLS;;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 367 "parser.y"
    {(yyval.mType) = M_JVC;;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 368 "parser.y"
    {(yyval.mType) = M_JVS;;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 369 "parser.y"
    {(yyval.mType) = M_JNE;;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 370 "parser.y"
    {(yyval.mType) = M_JEQ;;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 371 "parser.y"
    {(yyval.mType) = M_JGE;;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 372 "parser.y"
    {(yyval.mType) = M_JLT;;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 373 "parser.y"
    {(yyval.mType) = M_JCC;;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 374 "parser.y"
    {(yyval.mType) = M_JCS;;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 377 "parser.y"
    {(yyval.arg) = (yyvsp[(1) - (1)].arg);;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 378 "parser.y"
    {(yyval.arg) = (yyvsp[(1) - (1)].arg);;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 379 "parser.y"
    {(yyval.arg) = (yyvsp[(1) - (1)].arg);;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 381 "parser.y"
    {(yyval.arg) = (yyvsp[(1) - (1)].arg);;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 382 "parser.y"
    {a.type = A_MACRO_ARG; a.iVal = (yyvsp[(2) - (2)].iVal); (yyval.arg) = a;;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 385 "parser.y"
    {(yyval.arg) = (yyvsp[(1) - (1)].arg);;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 386 "parser.y"
    {(yyval.arg) = (yyvsp[(1) - (1)].arg);;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 387 "parser.y"
    {a.type = A_ZERO; a.iVal = 0; (yyval.arg) = a;;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 389 "parser.y"
    {(yyval.arg) = (yyvsp[(1) - (1)].arg);;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 390 "parser.y"
    {a.type = A_MACRO_ARG; a.iVal = (yyvsp[(2) - (2)].iVal); (yyval.arg) = a;;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 392 "parser.y"
    {(yyval.arg) = (yyvsp[(1) - (1)].arg);;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 393 "parser.y"
    {a.type = A_REGISTER; a.rType = REG_SP; (yyval.arg) = a;;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 396 "parser.y"
    {a.type = A_REGISTER; a.rType = REG_A; (yyval.arg) = a;;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 397 "parser.y"
    {a.type = A_REGISTER; a.rType = REG_B; (yyval.arg) = a;;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 398 "parser.y"
    {a.type = A_REGISTER; a.rType = REG_C; (yyval.arg) = a;;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 400 "parser.y"
    {(yyval.arg) = (yyvsp[(1) - (1)].arg);;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 401 "parser.y"
    {a.type = A_MACRO_ARG; a.iVal = (yyvsp[(2) - (2)].iVal); (yyval.arg) = a;;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 404 "parser.y"
    {(yyvsp[(1) - (1)].arg).type = A_ABSOLUTE; (yyval.arg) = (yyvsp[(1) - (1)].arg);;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 405 "parser.y"
    {(yyvsp[(1) - (1)].arg).type = A_INDEX; (yyval.arg) = (yyvsp[(1) - (1)].arg);;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 406 "parser.y"
    {(yyvsp[(1) - (1)].arg).type = A_ADDRESSED; (yyval.arg) = (yyvsp[(1) - (1)].arg);;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 407 "parser.y"
    {(yyvsp[(1) - (1)].arg).type = A_STACK; (yyval.arg) = (yyvsp[(1) - (1)].arg);;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 410 "parser.y"
    {a.type = A_CONSTANT; a.iVal = (yyvsp[(1) - (1)].iVal); (yyval.arg) = a;;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 411 "parser.y"
    {a.type = A_CONSTANT; a.iVal = (yyvsp[(1) - (1)].iVal); (yyval.arg) = a;;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 412 "parser.y"
    {a.type = A_CONSTANT; a.iVal = (yyvsp[(1) - (1)].iVal); (yyval.arg) = a;;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 413 "parser.y"
    {a.type = A_CONSTANT; a.iVal = (yyvsp[(1) - (1)].iVal); (yyval.arg) = a;;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 414 "parser.y"
    {a.type = A_ZERO; a.iVal = 0; (yyval.arg) = a;;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 415 "parser.y"
    {a.type = A_IDENTIFIER; a.text = (yyvsp[(1) - (1)].text); (yyval.arg) = a;;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 416 "parser.y"
    {a.type = A_ID_HIGH; a.text = (yyvsp[(1) - (2)].text); (yyval.arg) = a;;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 417 "parser.y"
    {a.type = A_ID_LOW; a.text = (yyvsp[(1) - (2)].text); (yyval.arg) = a;;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 418 "parser.y"
    {(yyval.arg) = (yyvsp[(1) - (1)].arg);;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 419 "parser.y"
    {(yyvsp[(2) - (4)].arg).type = A_SUM_HIGH; (yyval.arg) = (yyvsp[(2) - (4)].arg);;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 420 "parser.y"
    {(yyvsp[(2) - (4)].arg).type = A_SUM_LOW; (yyval.arg) = (yyvsp[(2) - (4)].arg);;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 423 "parser.y"
    {
                    if ((yyvsp[(1) - (3)].arg).type == A_SUM) {
                        daAppend(ArgumentDArray)((yyvsp[(1) - (3)].arg).sum, &(yyvsp[(3) - (3)].arg));
                        (yyval.arg) = (yyvsp[(1) - (3)].arg);
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

  case 119:

/* Line 1455 of yacc.c  */
#line 437 "parser.y"
    {(yyval.arg) = (yyvsp[(1) - (1)].arg);;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 438 "parser.y"
    {a.type = A_MACRO_ARG; a.iVal = (yyvsp[(2) - (2)].iVal); (yyval.arg) = a;;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 443 "parser.y"
    {a.text = (yyvsp[(2) - (2)].text); (yyval.arg) = a;;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 445 "parser.y"
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

  case 123:

/* Line 1455 of yacc.c  */
#line 458 "parser.y"
    {a.rType = REG_A; (yyval.arg) = a;;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 459 "parser.y"
    {a.iVal = (yyvsp[(2) - (3)].arg).iVal; (yyval.arg) = a;;}
    break;



/* Line 1455 of yacc.c  */
#line 2715 "source/parser.tab.c"
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
      yyerror (result, userMacros, YY_("syntax error"));
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
	    yyerror (result, userMacros, yymsg);
	  }
	else
	  {
	    yyerror (result, userMacros, YY_("syntax error"));
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
		      yytoken, &yylval, &yylloc, result, userMacros);
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
		  yystos[yystate], yyvsp, yylsp, result, userMacros);
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
  yyerror (result, userMacros, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc, result, userMacros);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp, result, userMacros);
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
#line 461 "parser.y"



void yyerror (InstructionList *result, UserMacroTable *userMacros, char const *s)
{
  fprintf (stderr, "%d:%s\n", yylineno, s);
}


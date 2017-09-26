/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

    #include "ast.h"
    #include "cmpAndDstrFuncs.h"
    LabelTable labels;
    static unsigned long int currAddress = 0;
    static unsigned long int nextAddress = 0;
    static Instruction i;
    static Argument a;
    int yylex();
    void yyerror(InstructionList *result, const char *s);
    int calcLength (char *str);
    int yylineno;

#line 80 "source/parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 19 "parser.y" /* yacc.c:355  */

    InstructionList iList;
    Instruction instr;
    Argument arg;
    enum instrType iType;
    enum macroType mType;
    char *text;
    long int iVal;

#line 194 "source/parser.tab.c" /* yacc.c:355  */
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

/* Copy the second part of user declarations.  */

#line 225 "source/parser.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   165

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  72
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  25
/* YYNRULES -- Number of rules.  */
#define YYNRULES  102
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  141

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   318

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      64,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    69,     2,    67,     2,     2,     2,    68,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    65,     2,
       2,    66,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    70,     2,    71,     2,     2,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    62,    62,    64,    64,    71,    73,    76,    83,    85,
      88,    89,    91,    99,   106,   112,   119,   127,   134,   140,
     146,   152,   153,   155,   162,   168,   176,   177,   183,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   210,   211,   212,   213,   214,   215,
     216,   217,   220,   221,   222,   223,   226,   227,   229,   230,
     233,   234,   235,   236,   237,   238,   239,   240,   243,   244,
     245,   247,   248,   249,   251,   252,   254,   255,   258,   259,
     260,   262,   263,   264,   266,   267,   268,   269,   270,   271,
     272,   273,   275,   276,   277,   278,   279,   280,   281,   282,
     285,   286,   287
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ADD", "ADC", "SUB", "SBC", "MUL", "MLL",
  "SGN", "RAS", "LSH", "RSH", "LRT", "RRT", "AND", "OR", "XOR", "NOT",
  "JMP", "ADDI", "ADCI", "SUBI", "SBCI", "ANDI", "ORI", "XORI", "LDI",
  "LSHI", "RSHI", "LRTI", "RRTI", "JFC", "JFS", "FLC", "FLS", "PUSH",
  "POP", "SVPC", "RET", "MOV", "JVC", "JVS", "JNE", "JEQ", "JGE", "JLT",
  "JCC", "JCS", "CALL", "HALT", "DW", "A", "B", "C", "SP", "HIGH", "LOW",
  "IDENTIFIER", "STRING", "HEX", "BINARY", "DECIMAL", "CHAR", "'\\n'",
  "':'", "'='", "','", "'0'", "'*'", "'['", "']'", "$accept", "program",
  "instructionList", "$@1", "label", "instruction", "simple_instr",
  "macro_instr", "a_type", "i_type", "si_type", "jfg_type", "flg_type",
  "jfg_macro", "reg_mem_imm", "dest", "dest_sp", "reg_sp", "reg", "mem",
  "embedded_imm", "imm", "absolute", "addressed", "stack", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,    10,    58,    61,    44,    48,    42,
      91,    93
};
# endif

#define YYPACT_NINF -81

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-81)))

#define YYTABLE_NINF -3

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -81,    10,     6,   -81,   -57,   -81,    94,   -81,   -52,    11,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -38,    97,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -38,   -17,   -81,   -81,   -38,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -45,   -81,    88,   -81,
     -47,   -35,   -38,   -14,   -38,    97,    97,    97,   -81,   -13,
     -81,   -81,   -81,   -81,   -81,   -30,   -81,   -81,   -81,   -25,
      97,   -18,   -81,   -81,   -81,   -81,   -81,   -81,     3,   -81,
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
      -5,   -81,   -81,   -81,   -81,   -81,    -4,   -81,     1,   -81,
     -81,   -81,     8,     9,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -10,   -17,   -81,   -81,   -17,    -6,    97,    97,    97,
     -81,   -81,   -81,    17,   -81,    18,   -81,   -17,   -17,   -81,
     -81
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       7,     0,     3,     1,     0,     6,     0,     5,     0,     0,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,     0,     0,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,     0,     0,    21,    22,     0,    60,    61,
      62,    63,    64,    65,    66,    67,     0,    26,     0,     4,
       0,     0,     0,     0,     0,     0,     0,     0,     8,    97,
      92,    93,    94,    95,    96,     0,    78,    79,    80,     0,
       0,     0,    68,    69,    70,    81,    82,    83,    89,    84,
      85,    86,    87,    88,    14,    19,    73,    20,    71,    72,
       0,    25,    28,    27,    10,    11,     0,    77,     0,    74,
      76,    75,     0,     0,    18,    24,    98,    99,     9,   101,
     100,     0,     0,    90,    91,     0,     0,     0,     0,     0,
     102,    13,    23,     0,    15,     0,    17,     0,     0,    12,
      16
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -36,   -80,   -81,   -81,   -44,   -42,
     -62,    -8,   -81,   -81,   -81
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     2,     6,     7,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    81,    97,   108,   109,    82,    83,
      94,    84,    85,    86,    87
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      98,    75,    99,   113,   114,   115,    -2,    95,     8,     9,
       3,   100,    68,   101,    76,    77,    78,   104,   121,   110,
      69,   111,    70,    71,    72,    73,   106,   119,   112,   105,
      74,    79,    80,   120,   118,    76,    77,    78,    76,    77,
      78,   107,   131,   116,   117,   132,    76,    77,    78,   122,
     103,    96,    79,    80,     0,    79,    80,   139,   140,   123,
     124,   130,   125,   126,     4,   134,   135,   136,   127,    69,
       5,    70,    71,    72,    73,   128,   129,     0,    98,    74,
      99,    98,   133,    99,   137,   138,     0,     0,     0,     0,
       0,     0,     0,    98,    98,    99,    99,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    69,   102,    70,    71,
      72,    73,     0,     0,     0,    88,    74,    89,    90,    91,
      92,     0,     0,     0,     0,    93
};

static const yytype_int16 yycheck[] =
{
      44,     9,    44,    65,    66,    67,     0,    43,    65,    66,
       0,    47,    64,    58,    52,    53,    54,    64,    80,    63,
      58,    63,    60,    61,    62,    63,    62,    52,    64,    64,
      68,    69,    70,    58,    64,    52,    53,    54,    52,    53,
      54,    55,   122,    56,    57,   125,    52,    53,    54,    67,
      58,    68,    69,    70,    -1,    69,    70,   137,   138,    56,
      57,    71,    67,    67,    58,   127,   128,   129,    67,    58,
      64,    60,    61,    62,    63,    67,    67,    -1,   122,    68,
     122,   125,   126,   125,    67,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   137,   138,   137,   138,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    58,    59,    60,    61,
      62,    63,    -1,    -1,    -1,    58,    68,    60,    61,    62,
      63,    -1,    -1,    -1,    -1,    68
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    73,    74,     0,    58,    64,    75,    76,    65,    66,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    64,    58,
      60,    61,    62,    63,    68,    93,    52,    53,    54,    69,
      70,    86,    90,    91,    93,    94,    95,    96,    58,    60,
      61,    62,    63,    68,    92,    86,    68,    87,    90,    91,
      86,    58,    59,    93,    64,    64,    86,    55,    88,    89,
      90,    91,    86,    92,    92,    92,    56,    57,    64,    52,
      58,    92,    67,    56,    57,    67,    67,    67,    67,    67,
      71,    87,    87,    90,    92,    92,    92,    67,    67,    87,
      87
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    72,    73,    75,    74,    74,    74,    74,    76,    76,
      77,    77,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    79,    79,    79,    79,    79,    79,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    81,    81,    81,    81,    81,    81,
      81,    81,    82,    82,    82,    82,    83,    83,    84,    84,
      85,    85,    85,    85,    85,    85,    85,    85,    86,    86,
      86,    87,    87,    87,    88,    88,    89,    89,    90,    90,
      90,    91,    91,    91,    92,    92,    92,    92,    92,    92,
      92,    92,    93,    93,    93,    93,    93,    93,    93,    93,
      94,    95,    96
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     3,     2,     2,     0,     3,     4,
       2,     2,     6,     4,     2,     4,     6,     4,     2,     2,
       2,     1,     1,     4,     2,     2,     1,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     1,     1,     1,     1,     1,     1,     2,     2,
       2,     2,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (result, YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location, result); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, InstructionList *result)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  YYUSE (result);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, InstructionList *result)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, result);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, InstructionList *result)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       , result);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, result); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, InstructionList *result)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (result);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (InstructionList *result)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
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
     '$$ = $1'.

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
#line 62 "parser.y" /* yacc.c:1646  */
    {*result = (yyvsp[0].iList);}
#line 1518 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 64 "parser.y" /* yacc.c:1646  */
    {memset(&i, 0, sizeof i);}
#line 1524 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 65 "parser.y" /* yacc.c:1646  */
    {
                        (yyvsp[0].instr).address = currAddress;
                        currAddress = ++nextAddress;
                        llAppend(InstructionList)(&(yyvsp[-2].iList), (yyvsp[0].instr));
                        (yyval.iList) = (yyvsp[-2].iList);
                    }
#line 1535 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 72 "parser.y" /* yacc.c:1646  */
    {nextAddress = currAddress; (yyval.iList) = (yyvsp[-1].iList);}
#line 1541 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 74 "parser.y" /* yacc.c:1646  */
    {(yyval.iList) = (yyvsp[-1].iList);}
#line 1547 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 76 "parser.y" /* yacc.c:1646  */
    {
                        labels = newRBT(LabelTable)(&cmpStr,
                            &dstrLabelTableEntry);
                        (yyval.iList) = newLList(InstructionList)(&dstrInstr);
                    }
#line 1557 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 84 "parser.y" /* yacc.c:1646  */
    {rbtSet(LabelTable)(&labels, (yyvsp[-2].text), currAddress); }
#line 1563 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 86 "parser.y" /* yacc.c:1646  */
    {rbtSet(LabelTable)(&labels, (yyvsp[-3].text), (yyvsp[-1].arg).iVal); }
#line 1569 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 88 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-1].instr).isMacro = false; (yyval.instr) = (yyvsp[-1].instr);}
#line 1575 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 89 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-1].instr).isMacro = true; (yyval.instr) = (yyvsp[-1].instr);}
#line 1581 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 92 "parser.y" /* yacc.c:1646  */
    {
                        i.iType = (yyvsp[-5].iType);
                        i.args[0] = (yyvsp[-4].arg);
                        i.args[1] = (yyvsp[-2].arg);
                        i.args[2] = (yyvsp[0].arg);
                        (yyval.instr) = i;
                    }
#line 1593 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 100 "parser.y" /* yacc.c:1646  */
    {
                        i.iType = I_NOT;
                        i.args[0] = (yyvsp[-2].arg);
                        i.args[1] = (yyvsp[0].arg);
                        (yyval.instr) = i;
                    }
#line 1604 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 107 "parser.y" /* yacc.c:1646  */
    {
                        i.iType = I_JMP;
                        i.args[0] = (yyvsp[0].arg);
                        (yyval.instr) = i;
                    }
#line 1614 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 113 "parser.y" /* yacc.c:1646  */
    {
                        i.iType = (yyvsp[-3].iType);
                        i.args[0] = (yyvsp[-2].arg);
                        i.args[1] = (yyvsp[0].arg);
                        (yyval.instr) = i;
                    }
#line 1625 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 120 "parser.y" /* yacc.c:1646  */
    {
                        i.iType = (yyvsp[-5].iType);
                        i.args[0] = (yyvsp[-4].arg);
                        i.args[1] = (yyvsp[-2].arg);
                        i.args[2] = (yyvsp[0].arg);
                        (yyval.instr) = i;
                    }
#line 1637 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 128 "parser.y" /* yacc.c:1646  */
    {
                        i.iType = (yyvsp[-3].iType);
                        i.args[0] = (yyvsp[-2].arg);
                        i.args[1] = (yyvsp[0].arg);
                        (yyval.instr) = i;
                    }
#line 1648 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 135 "parser.y" /* yacc.c:1646  */
    {
                        i.iType = (yyvsp[-1].iType);
                        i.args[0] = (yyvsp[0].arg);
                        (yyval.instr) = i;
                    }
#line 1658 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 141 "parser.y" /* yacc.c:1646  */
    {
                        i.iType = I_PUSH;
                        i.args[0] = (yyvsp[0].arg);
                        (yyval.instr) = i;
                    }
#line 1668 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 147 "parser.y" /* yacc.c:1646  */
    {
                        i.iType = I_POP;
                        i.args[0] = (yyvsp[0].arg);
                        (yyval.instr) = i;
                    }
#line 1678 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 152 "parser.y" /* yacc.c:1646  */
    {i.iType = I_SVPC; (yyval.instr) = i;}
#line 1684 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 153 "parser.y" /* yacc.c:1646  */
    {i.iType = I_RET; (yyval.instr) = i;}
#line 1690 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 156 "parser.y" /* yacc.c:1646  */
    {
                    i.mType = M_MOV;
                    i.args[0] = (yyvsp[-2].arg);
                    i.args[1] = (yyvsp[0].arg);
                    (yyval.instr) = i;
                }
#line 1701 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 163 "parser.y" /* yacc.c:1646  */
    {
                    i.mType = (yyvsp[-1].mType);
                    i.args[0] = (yyvsp[0].arg);
                    (yyval.instr) = i;
                }
#line 1711 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 169 "parser.y" /* yacc.c:1646  */
    {
                    i.mType = M_CALL;
                    i.args[0].type = A_IDENTIFIER;
                    i.args[0].text = (yyvsp[0].text);
                    nextAddress++;
                    (yyval.instr) = i;
                }
#line 1723 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 176 "parser.y" /* yacc.c:1646  */
    {i.mType = M_HALT; (yyval.instr) = i;}
#line 1729 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 178 "parser.y" /* yacc.c:1646  */
    {
                    i.mType = M_DW;
                    i.args[0] = (yyvsp[0].arg);
                    (yyval.instr) = i;
                }
#line 1739 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 184 "parser.y" /* yacc.c:1646  */
    {
                    i.mType = M_DW;
                    i.args[0].type = A_STRING;
                    i.args[0].text = (yyvsp[0].text);
                    nextAddress += calcLength((yyvsp[0].text))-2;
                    (yyval.instr) = i;
                }
#line 1751 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 193 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_ADD;}
#line 1757 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 194 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_ADC;}
#line 1763 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 195 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_SUB;}
#line 1769 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 196 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_SBC;}
#line 1775 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 197 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_MUL;}
#line 1781 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 198 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_MLL;}
#line 1787 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 199 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_SGN;}
#line 1793 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 200 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_RAS;}
#line 1799 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 201 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_LSH;}
#line 1805 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 202 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_RSH;}
#line 1811 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 203 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_LRT;}
#line 1817 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 204 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_RRT;}
#line 1823 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 205 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_AND;}
#line 1829 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 206 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_OR;}
#line 1835 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 207 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_XOR;}
#line 1841 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 210 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_ADDI;}
#line 1847 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 211 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_ADCI;}
#line 1853 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 212 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_SUBI;}
#line 1859 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 213 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_SBCI;}
#line 1865 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 214 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_ANDI;}
#line 1871 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 215 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_ORI;}
#line 1877 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 216 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_XORI;}
#line 1883 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 217 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_LDI;}
#line 1889 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 220 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_LSHI;}
#line 1895 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 221 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_RSHI;}
#line 1901 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 222 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_LRTI;}
#line 1907 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 223 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_RRTI;}
#line 1913 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 226 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_JFC;}
#line 1919 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 227 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_JFS;}
#line 1925 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 229 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_FLC;}
#line 1931 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 230 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_FLS;}
#line 1937 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 233 "parser.y" /* yacc.c:1646  */
    {(yyval.mType) = M_JVC;}
#line 1943 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 234 "parser.y" /* yacc.c:1646  */
    {(yyval.mType) = M_JVS;}
#line 1949 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 235 "parser.y" /* yacc.c:1646  */
    {(yyval.mType) = M_JNE;}
#line 1955 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 236 "parser.y" /* yacc.c:1646  */
    {(yyval.mType) = M_JEQ;}
#line 1961 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 237 "parser.y" /* yacc.c:1646  */
    {(yyval.mType) = M_JGE;}
#line 1967 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 238 "parser.y" /* yacc.c:1646  */
    {(yyval.mType) = M_JLT;}
#line 1973 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 239 "parser.y" /* yacc.c:1646  */
    {(yyval.mType) = M_JCC;}
#line 1979 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 240 "parser.y" /* yacc.c:1646  */
    {(yyval.mType) = M_JCS;}
#line 1985 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 243 "parser.y" /* yacc.c:1646  */
    {(yyval.arg) = (yyvsp[0].arg);}
#line 1991 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 244 "parser.y" /* yacc.c:1646  */
    {(yyval.arg) = (yyvsp[0].arg);}
#line 1997 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 245 "parser.y" /* yacc.c:1646  */
    {(yyval.arg) = (yyvsp[0].arg);}
#line 2003 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 247 "parser.y" /* yacc.c:1646  */
    {(yyval.arg) = (yyvsp[0].arg);}
#line 2009 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 248 "parser.y" /* yacc.c:1646  */
    {(yyval.arg) = (yyvsp[0].arg);}
#line 2015 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 249 "parser.y" /* yacc.c:1646  */
    {a.type = A_ZERO; a.iVal = 0; (yyval.arg) = a;}
#line 2021 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 251 "parser.y" /* yacc.c:1646  */
    {(yyval.arg) = (yyvsp[0].arg);}
#line 2027 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 252 "parser.y" /* yacc.c:1646  */
    {(yyval.arg) = (yyvsp[0].arg);}
#line 2033 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 254 "parser.y" /* yacc.c:1646  */
    {(yyval.arg) = (yyvsp[0].arg);}
#line 2039 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 255 "parser.y" /* yacc.c:1646  */
    {a.type = A_REGISTER; a.rType = REG_SP; (yyval.arg) = a;}
#line 2045 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 258 "parser.y" /* yacc.c:1646  */
    {a.type = A_REGISTER; a.rType = REG_A; (yyval.arg) = a;}
#line 2051 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 259 "parser.y" /* yacc.c:1646  */
    {a.type = A_REGISTER; a.rType = REG_B; (yyval.arg) = a;}
#line 2057 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 260 "parser.y" /* yacc.c:1646  */
    {a.type = A_REGISTER; a.rType = REG_C; (yyval.arg) = a;}
#line 2063 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 262 "parser.y" /* yacc.c:1646  */
    {(yyvsp[0].arg).type = A_ABSOLUTE; (yyval.arg) = (yyvsp[0].arg);}
#line 2069 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 263 "parser.y" /* yacc.c:1646  */
    {(yyvsp[0].arg).type = A_ADDRESSED; (yyval.arg) = (yyvsp[0].arg);}
#line 2075 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 264 "parser.y" /* yacc.c:1646  */
    {(yyvsp[0].arg).type = A_STACK; (yyval.arg) = (yyvsp[0].arg);}
#line 2081 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 266 "parser.y" /* yacc.c:1646  */
    {a.type = A_CONSTANT; a.iVal = (yyvsp[0].iVal); (yyval.arg) = a;}
#line 2087 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 267 "parser.y" /* yacc.c:1646  */
    {a.type = A_CONSTANT; a.iVal = (yyvsp[0].iVal); (yyval.arg) = a;}
#line 2093 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 268 "parser.y" /* yacc.c:1646  */
    {a.type = A_CONSTANT; a.iVal = (yyvsp[0].iVal); (yyval.arg) = a;}
#line 2099 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 269 "parser.y" /* yacc.c:1646  */
    {a.type = A_CONSTANT; a.iVal = (yyvsp[0].iVal); (yyval.arg) = a;}
#line 2105 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 270 "parser.y" /* yacc.c:1646  */
    {a.type = A_CONSTANT; a.iVal = 0; (yyval.arg) = a;}
#line 2111 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 271 "parser.y" /* yacc.c:1646  */
    {a.type = A_IDENTIFIER; a.text = (yyvsp[0].text); (yyval.arg) = a;}
#line 2117 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 272 "parser.y" /* yacc.c:1646  */
    {a.type = A_ID_HIGH; a.text = (yyvsp[-1].text); (yyval.arg) = a;}
#line 2123 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 273 "parser.y" /* yacc.c:1646  */
    {a.type = A_ID_LOW; a.text = (yyvsp[-1].text); (yyval.arg) = a;}
#line 2129 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 275 "parser.y" /* yacc.c:1646  */
    {a.type = A_CONSTANT; a.iVal = (yyvsp[0].iVal); nextAddress++; (yyval.arg) = a;}
#line 2135 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 276 "parser.y" /* yacc.c:1646  */
    {a.type = A_CONSTANT; a.iVal = (yyvsp[0].iVal); nextAddress++; (yyval.arg) = a;}
#line 2141 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 277 "parser.y" /* yacc.c:1646  */
    {a.type = A_CONSTANT; a.iVal = (yyvsp[0].iVal); nextAddress++; (yyval.arg) = a;}
#line 2147 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 278 "parser.y" /* yacc.c:1646  */
    {a.type = A_CONSTANT; a.iVal = (yyvsp[0].iVal); nextAddress++; (yyval.arg) = a;}
#line 2153 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 279 "parser.y" /* yacc.c:1646  */
    {a.type = A_ZERO; a.iVal = 0; (yyval.arg) = a;}
#line 2159 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 280 "parser.y" /* yacc.c:1646  */
    {a.type = A_IDENTIFIER; a.text = (yyvsp[0].text); nextAddress++; (yyval.arg) = a;}
#line 2165 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 281 "parser.y" /* yacc.c:1646  */
    {a.type = A_ID_HIGH; a.text = (yyvsp[-1].text); nextAddress++; (yyval.arg) = a;}
#line 2171 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 282 "parser.y" /* yacc.c:1646  */
    {a.type = A_ID_LOW; a.text = (yyvsp[-1].text); nextAddress++; (yyval.arg) = a;}
#line 2177 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 285 "parser.y" /* yacc.c:1646  */
    {a.text = (yyvsp[0].text); nextAddress += 2; (yyval.arg) = a;}
#line 2183 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 286 "parser.y" /* yacc.c:1646  */
    {a.rType = REG_A; (yyval.arg) = a;}
#line 2189 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 287 "parser.y" /* yacc.c:1646  */
    {a.iVal = (yyvsp[-1].arg).iVal; nextAddress++; (yyval.arg) = a;}
#line 2195 "source/parser.tab.c" /* yacc.c:1646  */
    break;


#line 2199 "source/parser.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (result, YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (result, yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc, result);
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

  yyerror_range[1] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp, result);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (result, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, result);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp, result);
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
  return yyresult;
}
#line 289 "parser.y" /* yacc.c:1906  */



void yyerror (InstructionList *result, char const *s)
{
  fprintf (stderr, "%d:%s\n", yylineno, s);
}

int calcLength (char *str) {
    int len = 0;
    for (char *c = str; *c;) {
        if (*c == '\\') {
            c++;
            if (*c++ != 'x')
                len++;
            else {
                while ((*c >= '0' && *c <= '9') ||
                        (*c >= 'A' && *c <= 'F') ||
                        (*c >= 'a' && *c <= 'f'))
                    c++;
                len++;
            }
        } else { 
            len++; c++;
        }
    }
    return len;
}

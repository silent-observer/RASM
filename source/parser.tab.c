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
    static Instruction i;
    static Argument a;
    static bool isInUserMacroDef;
    static UserMacro currUserMacro;
    int yylex();
    void yyerror(InstructionList *result, UserMacroTable *userMacros, char *filename, const char *s);
    int calcLength (char *str);
    extern int lineno;

#line 79 "source/parser.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
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
#line 20 "parser.y" /* yacc.c:355  */

    InstructionList iList;
    Instruction instr;
    Argument arg;
    ParamTypeDArray paramTypes;
    enum instrType iType;
    enum macroType mType;
    enum paramType pType;
    char *text;
    long int iVal;

#line 207 "source/parser.tab.c" /* yacc.c:355  */
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

/* Copy the second part of user declarations.  */

#line 238 "source/parser.tab.c" /* yacc.c:358  */

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
#define YYLAST   256

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  89
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  131
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  214

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   330

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      76,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    82,     2,     2,     2,
      85,    86,    88,    87,    81,     2,     2,     2,    83,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    77,     2,
       2,    78,     2,     2,    84,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    79,     2,    80,     2,     2,     2,     2,     2,     2,
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
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    83,    83,    86,    86,    93,    93,   100,   102,   103,
     103,   110,   116,   125,   138,   137,   150,   161,   162,   163,
     166,   167,   168,   169,   173,   174,   175,   177,   186,   194,
     208,   215,   222,   231,   239,   248,   256,   264,   272,   279,
     286,   293,   300,   308,   315,   324,   330,   336,   343,   354,
     362,   371,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   394,   395,   396,
     397,   398,   399,   400,   403,   404,   405,   406,   409,   410,
     413,   414,   415,   416,   417,   418,   419,   420,   423,   424,
     425,   427,   428,   431,   432,   433,   435,   436,   438,   439,
     442,   443,   444,   446,   447,   450,   451,   452,   453,   456,
     457,   459,   460,   461,   462,   463,   464,   465,   466,   468,
     469,   470,   471,   473,   488,   489,   494,   495,   509,   510,
     512,   513
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ADD", "ADC", "SUB", "SBC", "MUL", "MLL",
  "SGN", "RAS", "LSH", "RSH", "LRT", "RRT", "AND", "OR", "XOR", "NOT",
  "MOV8", "JMP", "JMR", "ADDI", "ADCI", "SUBI", "SBCI", "ANDI", "ORI",
  "XORI", "LDI", "LSHI", "RSHI", "LRTI", "RRTI", "JFC", "JFS", "LOAD",
  "SAVE", "PUSH", "POP", "SVPC", "RET", "NOP", "MOV", "JVC", "JVS", "JNE",
  "JEQ", "JGE", "JLT", "JCC", "JCS", "CALL", "HALT", "DW", "DEFMACRO",
  "ENDDEF", "INCLUDE", "REG", "REGMEM", "REGMEMIMM", "IMM", "A", "B", "C",
  "SP", "HIGH", "LOW", "HIGHB", "LOWB", "IDENTIFIER", "STRING", "HEX",
  "BINARY", "DECIMAL", "CHAR", "'\\n'", "':'", "'='", "'['", "']'", "','",
  "'$'", "'0'", "'@'", "'('", "')'", "'+'", "'*'", "$accept", "program",
  "instruction_list", "$@1", "$@2", "$@3", "label", "macro_definition",
  "$@4", "include_directive", "parameter_list", "param_type",
  "instruction", "simple_instr", "macro_instr", "user_macro", "a_type",
  "i_type", "si_type", "f_type", "jfg_macro",
  "reg_mem_imm_without_macro_arg", "reg_mem_imm", "dest_without_macro_arg",
  "dest", "dest_sp", "reg_without_macro_arg", "reg", "mem", "fastmem",
  "imm_sum_component", "imm_without_macro_arg", "imm_sum", "imm",
  "absolute", "index", "addressed", "stack", "highb_lowb", YY_NULLPTR
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
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,    10,    58,    61,    91,
      93,    44,    36,    48,    64,    40,    41,    43,    42
};
# endif

#define YYPACT_NINF -159

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-159)))

#define YYTABLE_NINF -10

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -159,    32,     3,  -159,   -53,  -159,   174,   -21,   -19,  -159,
     -28,  -159,  -159,  -159,  -159,  -159,  -159,  -159,  -159,  -159,
    -159,  -159,  -159,  -159,  -159,  -159,    20,    20,   165,    87,
    -159,  -159,  -159,  -159,  -159,  -159,  -159,   165,  -159,  -159,
    -159,  -159,  -159,  -159,   -31,    20,    20,    87,   165,  -159,
    -159,    20,  -159,  -159,  -159,  -159,  -159,  -159,  -159,  -159,
     -13,  -159,   159,   -11,  -159,   -15,     2,   -47,    20,    65,
      20,   165,   165,   -64,  -159,    -6,  -159,    16,  -159,  -159,
    -159,   -60,  -159,  -159,  -159,  -159,   165,     7,  -159,    -3,
     -14,  -159,     5,  -159,  -159,     4,  -159,  -159,  -159,  -159,
    -159,  -159,    28,    22,    24,  -159,  -159,    35,    27,  -159,
    -159,  -159,  -159,  -159,    34,   -59,    36,    37,  -159,  -159,
    -159,    38,  -159,  -159,  -159,    20,  -159,  -159,  -159,    20,
      39,  -159,  -159,    41,    42,    50,  -159,    56,   165,    57,
    -159,  -159,  -159,  -159,    29,  -159,  -159,  -159,   165,    54,
    -159,     4,    51,  -159,  -159,    87,   165,  -159,  -159,    62,
    -159,  -159,    65,  -159,  -159,    87,   -31,    87,  -159,  -159,
     -27,   165,   165,   165,  -159,    76,  -159,    78,    16,    79,
    -159,    46,  -159,  -159,    87,  -159,  -159,  -159,  -159,    82,
    -159,    77,    80,    81,  -159,  -159,  -159,  -159,  -159,  -159,
    -159,    28,  -159,    87,    65,    87,  -159,  -159,  -159,  -159,
    -159,   -45,    84,  -159
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      11,     0,     3,     1,     0,     7,     0,     0,     0,     8,
       0,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,     0,     0,     0,     0,
      67,    68,    69,    70,    71,    72,    73,     0,    74,    75,
      76,    77,    78,    79,     0,     0,     0,     0,     0,    41,
      46,     0,    80,    81,    82,    83,    84,    85,    86,    87,
       0,    45,     0,     0,     4,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     6,     0,    10,    17,   100,   101,
     102,   116,   111,   112,   113,   114,     0,     0,   115,     0,
       0,    91,     0,    88,    89,   119,    90,   120,   105,   106,
     107,   108,     0,   116,     0,   124,    30,     0,     0,    95,
      96,    31,    93,    94,     0,     0,     0,     0,    38,    39,
      40,     0,    44,    48,    47,    49,    24,    25,    26,     0,
       0,    99,    98,     0,     0,     0,    43,     0,     0,     0,
      20,    21,    22,    23,     0,    18,   117,   118,     0,     0,
      92,     0,     0,   128,   126,     0,     0,   130,   131,     0,
     125,    97,     0,   109,   110,     0,     0,     0,    50,    51,
       0,     0,     0,     0,    12,     0,    16,     0,     0,     0,
     129,     0,    28,   123,     0,    33,    36,    37,    42,     0,
     103,     0,     0,     0,    35,    13,    14,    19,   127,   121,
     122,     0,   104,     0,     0,     0,    11,    29,    27,    32,
      34,     3,     0,    15
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -159,  -159,   -43,  -159,  -159,  -159,  -159,  -159,  -159,  -159,
    -159,   -10,  -159,  -159,  -159,  -159,  -159,  -159,  -159,  -159,
    -159,  -159,    17,  -159,   -29,  -158,   -25,  -159,   -18,    -2,
      83,    -4,   147,   -32,  -159,  -159,  -159,  -159,   -36
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     6,     7,     8,    74,     9,   206,    76,
     144,   145,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    91,    92,   110,   132,   133,   112,   191,   113,   116,
      95,   105,    97,   106,    98,    99,   100,   101,   159
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     111,    93,    93,    -2,   185,   114,   146,   147,    94,    94,
       4,   212,    -9,   137,   138,   163,   120,    10,   119,   148,
      93,    93,    96,    96,   164,    -5,    93,    94,    94,   128,
     124,     5,     3,    94,   129,    78,    79,    80,    75,   135,
     136,    96,    96,    93,   102,    93,   209,    96,   153,    73,
      94,    77,    94,   115,   149,   189,   154,   122,     4,   125,
      -9,   126,   117,   118,    96,   139,    96,   103,   121,    82,
      83,    84,    85,    -5,   140,   141,   142,   143,   127,     5,
      88,   150,    78,    79,    80,   130,   155,   134,   146,   147,
      81,   156,    82,    83,    84,    85,   157,   158,   160,    86,
      93,   161,    87,    88,    93,    89,   175,    94,    90,   177,
     178,    94,   199,   200,   148,   162,   179,   165,   166,   167,
     170,    96,   171,   172,   183,    96,   182,    78,    79,    80,
     131,   173,   174,   176,   180,   107,   186,   181,   188,   192,
     193,   194,   168,   184,    86,   190,   169,   108,   109,    78,
      79,    80,   195,    90,   196,   201,   202,   107,   203,   198,
     213,   204,   205,   211,   187,   207,    86,     0,   197,   108,
     109,     0,   151,     0,   208,    90,   210,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,   103,
     123,    82,    83,    84,    85,   103,   152,    82,    83,    84,
      85,   104,    88,     0,    89,     0,     0,   104,    88,     0,
      89,     0,     0,     0,     0,     0,    63
};

static const yytype_int16 yycheck[] =
{
      29,    26,    27,     0,   162,    37,    66,    67,    26,    27,
      55,    56,    57,    77,    78,    74,    48,    70,    47,    79,
      45,    46,    26,    27,    83,    70,    51,    45,    46,    76,
      62,    76,     0,    51,    81,    62,    63,    64,    57,    71,
      72,    45,    46,    68,    27,    70,   204,    51,    62,    70,
      68,    79,    70,    84,    86,    82,    70,    70,    55,    70,
      57,    76,    45,    46,    68,    71,    70,    70,    51,    72,
      73,    74,    75,    70,    58,    59,    60,    61,    76,    76,
      83,    74,    62,    63,    64,    68,    81,    70,    66,    67,
      70,    87,    72,    73,    74,    75,    68,    69,    74,    79,
     125,    74,    82,    83,   129,    85,   138,   125,    88,    80,
      81,   129,    66,    67,    79,    81,   148,    81,    81,    81,
      81,   125,    81,    81,   156,   129,   155,    62,    63,    64,
      65,    81,    76,    76,    80,    70,   165,    86,   167,   171,
     172,   173,   125,    81,    79,   170,   129,    82,    83,    62,
      63,    64,    76,    88,    76,   184,    74,    70,    81,    80,
      76,    81,    81,   206,   166,   201,    79,    -1,   178,    82,
      83,    -1,    89,    -1,   203,    88,   205,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    70,
      71,    72,    73,    74,    75,    70,    89,    72,    73,    74,
      75,    82,    83,    -1,    85,    -1,    -1,    82,    83,    -1,
      85,    -1,    -1,    -1,    -1,    -1,    82
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    90,    91,     0,    55,    76,    92,    93,    94,    96,
      70,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    82,   101,   102,   103,   104,   105,   106,
     107,   108,   109,    70,    95,    57,    98,    79,    62,    63,
      64,    70,    72,    73,    74,    75,    79,    82,    83,    85,
      88,   110,   111,   115,   117,   119,   120,   121,   123,   124,
     125,   126,   111,    70,    82,   120,   122,    70,    82,    83,
     112,   113,   115,   117,   122,    84,   118,   111,   111,   113,
     122,   111,    70,    71,   122,    70,    76,    76,    76,    81,
     111,    65,   113,   114,   111,   122,   122,    77,    78,    71,
      58,    59,    60,    61,    99,   100,    66,    67,    79,   122,
      74,   119,   121,    62,    70,    81,    87,    68,    69,   127,
      74,    74,    81,    74,    83,    81,    81,    81,   111,   111,
      81,    81,    81,    81,    76,   122,    76,    80,    81,   122,
      80,    86,   113,   122,    81,   114,   113,   118,   113,    82,
     115,   116,   122,   122,   122,    76,    76,   100,    80,    66,
      67,   113,    74,    81,    81,    81,    97,   127,   113,   114,
     113,    91,    56,    76
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    89,    90,    92,    91,    93,    91,    91,    91,    94,
      91,    91,    95,    95,    97,    96,    98,    99,    99,    99,
     100,   100,   100,   100,   101,   101,   101,   102,   102,   102,
     102,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   103,   103,   103,   103,   103,   103,   103,   104,
     104,   104,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   105,   105,   105,   106,   106,   106,
     106,   106,   106,   106,   107,   107,   107,   107,   108,   108,
     109,   109,   109,   109,   109,   109,   109,   109,   110,   110,
     110,   111,   111,   112,   112,   112,   113,   113,   114,   114,
     115,   115,   115,   116,   116,   117,   117,   117,   117,   118,
     118,   119,   119,   119,   119,   119,   119,   119,   119,   120,
     120,   120,   120,   121,   122,   122,   123,   124,   125,   126,
     127,   127
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     3,     0,     3,     2,     2,     0,
       3,     0,     3,     4,     0,    10,     3,     0,     1,     3,
       1,     1,     1,     1,     2,     2,     2,     6,     4,     6,
       2,     2,     6,     4,     6,     4,     4,     4,     2,     2,
       2,     1,     4,     2,     2,     1,     1,     2,     2,     2,
       3,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     2,
       2,     1,     1,     1,     1,     1,     1,     2,     2,     1,
       1,     4,     4,     3,     1,     2,     2,     4,     2,     3,
       1,     1
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
      yyerror (result, userMacros, filename, YY_("syntax error: cannot back up")); \
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
                  Type, Value, Location, result, userMacros, filename); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, InstructionList *result, UserMacroTable *userMacros, char *filename)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
  YYUSE (result);
  YYUSE (userMacros);
  YYUSE (filename);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, InstructionList *result, UserMacroTable *userMacros, char *filename)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp, result, userMacros, filename);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule, InstructionList *result, UserMacroTable *userMacros, char *filename)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       , result, userMacros, filename);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, result, userMacros, filename); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, InstructionList *result, UserMacroTable *userMacros, char *filename)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (result);
  YYUSE (userMacros);
  YYUSE (filename);
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
yyparse (InstructionList *result, UserMacroTable *userMacros, char *filename)
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
#line 83 "parser.y" /* yacc.c:1646  */
    {*result = (yyvsp[0].iList);}
#line 1594 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 86 "parser.y" /* yacc.c:1646  */
    {memset(&i, 0, sizeof i);}
#line 1600 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 87 "parser.y" /* yacc.c:1646  */
    {
                        (yyvsp[0].instr).line = lineno-1;
                        printf("%d!\n", (yyvsp[0].instr).line);
                        llAppend(InstructionList)(&(yyvsp[-2].iList), (yyvsp[0].instr));
                        (yyval.iList) = (yyvsp[-2].iList);
                    }
#line 1611 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 93 "parser.y" /* yacc.c:1646  */
    {memset(&i, 0, sizeof i);}
#line 1617 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 94 "parser.y" /* yacc.c:1646  */
    {
                        (yyvsp[0].instr).line = lineno-1;
                        (yyvsp[0].instr).isMacro = true;
                        llAppend(InstructionList)(&(yyvsp[-2].iList), (yyvsp[0].instr));
                        (yyval.iList) = (yyvsp[-2].iList);
                    }
#line 1628 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 101 "parser.y" /* yacc.c:1646  */
    {(yyval.iList) = (yyvsp[-1].iList);}
#line 1634 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 103 "parser.y" /* yacc.c:1646  */
    {memset(&i, 0, sizeof i);}
#line 1640 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 104 "parser.y" /* yacc.c:1646  */
    {
                        (yyvsp[0].instr).line = lineno-1;
                        llAppend(InstructionList)(&(yyvsp[-2].iList), (yyvsp[0].instr));
                        (yyval.iList) = (yyvsp[-2].iList);
                    }
#line 1650 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 110 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.iList) = newLList(InstructionList)(&dstrInstr);
                        isInUserMacroDef = false;
                    }
#line 1659 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 117 "parser.y" /* yacc.c:1646  */
    {
                i.mType = M_LABEL;
                i.args = newDArray(ArgumentDArray)(1);
                a.type = A_IDENTIFIER;
                a.text = (yyvsp[-2].text);
                daAppend(ArgumentDArray)(&i.args, &a);
                (yyval.instr) = i;
            }
#line 1672 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 126 "parser.y" /* yacc.c:1646  */
    {
                i.mType = M_LABEL_ASSIGN;
                i.args = newDArray(ArgumentDArray)(2);
                a.type = A_IDENTIFIER;
                a.text = (yyvsp[-3].text);
                daAppend(ArgumentDArray)(&i.args, &a);
                daAppend(ArgumentDArray)(&i.args, &(yyvsp[-1].arg));
                (yyval.instr) = i;
            }
#line 1686 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 138 "parser.y" /* yacc.c:1646  */
    {
                        isInUserMacroDef = true;
                        currUserMacro.paramTypes = (yyvsp[-2].paramTypes);
                    }
#line 1695 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 143 "parser.y" /* yacc.c:1646  */
    {
                        isInUserMacroDef = false;
                        currUserMacro.instrs = (yyvsp[-2].iList);
                        rbtSet(UserMacroTable)(userMacros, (yyvsp[-8].text), currUserMacro);
                    }
#line 1705 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 150 "parser.y" /* yacc.c:1646  */
    {
                        i.isMacro = true;
                        i.mType = M_INCLUDE;
                        i.args = newDArray(ArgumentDArray)(1);
                        a.type = A_STRING;
                        a.text = (yyvsp[-1].text);
                        daAppend(ArgumentDArray)(&i.args, &a);
                        (yyval.instr) = i;
                    }
#line 1719 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 161 "parser.y" /* yacc.c:1646  */
    {(yyval.paramTypes) = newDArray(ParamTypeDArray)(0);}
#line 1725 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 162 "parser.y" /* yacc.c:1646  */
    {(yyval.paramTypes) = newDArray(ParamTypeDArray)(3); daAppend(ParamTypeDArray)(&(yyval.paramTypes), &(yyvsp[0].pType));}
#line 1731 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 163 "parser.y" /* yacc.c:1646  */
    {daAppend(ParamTypeDArray)(&(yyvsp[-2].paramTypes), &(yyvsp[0].pType)); (yyval.paramTypes) = (yyvsp[-2].paramTypes);}
#line 1737 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 166 "parser.y" /* yacc.c:1646  */
    {(yyval.pType) = P_REG;}
#line 1743 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 167 "parser.y" /* yacc.c:1646  */
    {(yyval.pType) = P_REG_MEM;}
#line 1749 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 168 "parser.y" /* yacc.c:1646  */
    {(yyval.pType) = P_REG_MEM_IMM;}
#line 1755 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 169 "parser.y" /* yacc.c:1646  */
    {(yyval.pType) = P_IMM;}
#line 1761 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 173 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-1].instr).isMacro = false; (yyval.instr) = (yyvsp[-1].instr);}
#line 1767 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 174 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-1].instr).isMacro = true; (yyval.instr) = (yyvsp[-1].instr);}
#line 1773 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 175 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-1].instr).isMacro = true; (yyvsp[-1].instr).mType = M_USER_MACRO; (yyval.instr) = (yyvsp[-1].instr);}
#line 1779 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 178 "parser.y" /* yacc.c:1646  */
    {
                        i.iType = (yyvsp[-5].iType);
                        i.args = newDArray(ArgumentDArray)(3);
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[-4].arg));
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[-2].arg));
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[0].arg));
                        (yyval.instr) = i;
                    }
#line 1792 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 187 "parser.y" /* yacc.c:1646  */
    {
                        i.iType = I_NOT;
                        i.args = newDArray(ArgumentDArray)(2);
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[-2].arg));
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[0].arg));
                        (yyval.instr) = i;
                    }
#line 1804 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 195 "parser.y" /* yacc.c:1646  */
    {
                        i.args = newDArray(ArgumentDArray)(2);
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[-4].arg));
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[-1].arg));
                        switch (((yyvsp[-3].iVal) << 1) | (yyvsp[0].iVal)) {
                            case 0: i.iType = I_MOV8LL; break;
                            case 1: i.iType = I_MOV8LH; break;
                            case 2: i.iType = I_MOV8HL; break;
                            case 3: i.iType = I_MOV8HH; break;
                            default: i.iType = I_MOV8LL; break;
                        }
                        (yyval.instr) = i;
                    }
#line 1822 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 209 "parser.y" /* yacc.c:1646  */
    {
                        i.iType = I_JMP;
                        i.args = newDArray(ArgumentDArray)(1);
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[0].arg));
                        (yyval.instr) = i;
                    }
#line 1833 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 216 "parser.y" /* yacc.c:1646  */
    {
                        i.iType = I_JMR;
                        i.args = newDArray(ArgumentDArray)(1);
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[0].arg));
                        (yyval.instr) = i;
                    }
#line 1844 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 223 "parser.y" /* yacc.c:1646  */
    {
                        i.iType = (yyvsp[-5].iType);
                        i.args = newDArray(ArgumentDArray)(3);
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[-4].arg));
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[-2].arg));
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[0].arg));
                        (yyval.instr) = i;
                    }
#line 1857 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 232 "parser.y" /* yacc.c:1646  */
    {
                        i.iType = I_LDI;
                        i.args = newDArray(ArgumentDArray)(2);
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[-2].arg));
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[0].arg));
                        (yyval.instr) = i;
                    }
#line 1869 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 240 "parser.y" /* yacc.c:1646  */
    {
                        i.iType = (yyvsp[-5].iType);
                        i.args = newDArray(ArgumentDArray)(3);
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[-4].arg));
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[-2].arg));
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[0].arg));
                        (yyval.instr) = i;
                    }
#line 1882 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 249 "parser.y" /* yacc.c:1646  */
    {
                        i.iType = (yyvsp[-3].iType);
                        i.args = newDArray(ArgumentDArray)(2);
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[-2].arg));
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[0].arg));
                        (yyval.instr) = i;
                    }
#line 1894 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 257 "parser.y" /* yacc.c:1646  */
    {
                        i.iType = I_LOAD;
                        i.args = newDArray(ArgumentDArray)(2);
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[-2].arg));
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[0].arg));
                        (yyval.instr) = i;
                    }
#line 1906 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 265 "parser.y" /* yacc.c:1646  */
    {
                        i.iType = I_SAVE;
                        i.args = newDArray(ArgumentDArray)(2);
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[-2].arg));
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[0].arg));
                        (yyval.instr) = i;
                    }
#line 1918 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 273 "parser.y" /* yacc.c:1646  */
    {
                        i.iType = I_PUSH;
                        i.args = newDArray(ArgumentDArray)(1);
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[0].arg));
                        (yyval.instr) = i;
                    }
#line 1929 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 280 "parser.y" /* yacc.c:1646  */
    {
                        i.iType = I_POP;
                        i.args = newDArray(ArgumentDArray)(1);
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[0].arg));
                        (yyval.instr) = i;
                    }
#line 1940 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 287 "parser.y" /* yacc.c:1646  */
    {
                        i.iType = I_SVPC;
                        i.args = newDArray(ArgumentDArray)(1);
                        daAppend(ArgumentDArray)(&i.args, &(yyvsp[0].arg));
                        (yyval.instr) = i;
                    }
#line 1951 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 294 "parser.y" /* yacc.c:1646  */
    {
                        i.iType = I_RET;
                        i.args = newDArray(ArgumentDArray)(0);
                        (yyval.instr) = i;
                    }
#line 1961 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 301 "parser.y" /* yacc.c:1646  */
    {
                    i.mType = M_MOV;
                    i.args = newDArray(ArgumentDArray)(2);
                    daAppend(ArgumentDArray)(&i.args, &(yyvsp[-2].arg));
                    daAppend(ArgumentDArray)(&i.args, &(yyvsp[0].arg));
                    (yyval.instr) = i;
                }
#line 1973 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 309 "parser.y" /* yacc.c:1646  */
    {
                    i.mType = (yyvsp[-1].mType);
                    i.args = newDArray(ArgumentDArray)(1);
                    daAppend(ArgumentDArray)(&i.args, &(yyvsp[0].arg));
                    (yyval.instr) = i;
                }
#line 1984 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 316 "parser.y" /* yacc.c:1646  */
    {
                    i.mType = M_CALL;
                    a.type = A_IDENTIFIER;
                    a.text = (yyvsp[0].text);
                    i.args = newDArray(ArgumentDArray)(1);
                    daAppend(ArgumentDArray)(&i.args, &a);
                    (yyval.instr) = i;
                }
#line 1997 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 325 "parser.y" /* yacc.c:1646  */
    {
                    i.mType = M_HALT;
                    i.args = newDArray(ArgumentDArray)(1);
                    (yyval.instr) = i;
                }
#line 2007 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 331 "parser.y" /* yacc.c:1646  */
    {
                    i.mType = M_NOP;
                    i.args = newDArray(ArgumentDArray)(3);
                    (yyval.instr) = i;
                }
#line 2017 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 337 "parser.y" /* yacc.c:1646  */
    {
                    i.mType = M_DW;
                    i.args = newDArray(ArgumentDArray)(1);
                    daAppend(ArgumentDArray)(&i.args, &(yyvsp[0].arg));
                    (yyval.instr) = i;
                }
#line 2028 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 344 "parser.y" /* yacc.c:1646  */
    {
                    i.mType = M_DW;
                    a.type = A_STRING;
                    a.text = (yyvsp[0].text);
                    i.args = newDArray(ArgumentDArray)(1);
                    daAppend(ArgumentDArray)(&i.args, &a);
                    (yyval.instr) = i;
                }
#line 2041 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 355 "parser.y" /* yacc.c:1646  */
    {
                    i.args = newDArray(ArgumentDArray)(1);
                    a.type = A_IDENTIFIER;
                    a.text = (yyvsp[0].text);
                    daAppend(ArgumentDArray)(&i.args, &a);
                    (yyval.instr) = i;
                }
#line 2053 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 363 "parser.y" /* yacc.c:1646  */
    {
                    i.args = newDArray(ArgumentDArray)(4);
                    a.type = A_IDENTIFIER;
                    a.text = (yyvsp[-1].text);
                    daAppend(ArgumentDArray)(&i.args, &a);
                    daAppend(ArgumentDArray)(&i.args, &(yyvsp[0].arg));
                    (yyval.instr) = i;
                }
#line 2066 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 372 "parser.y" /* yacc.c:1646  */
    {
                    daAppend(ArgumentDArray)(&(yyvsp[-2].instr).args, &(yyvsp[0].arg));
                    (yyval.instr) = (yyvsp[-2].instr);
                }
#line 2075 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 377 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_ADD;}
#line 2081 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 378 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_ADC;}
#line 2087 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 379 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_SUB;}
#line 2093 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 380 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_SBC;}
#line 2099 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 381 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_MUL;}
#line 2105 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 382 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_MLL;}
#line 2111 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 383 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_SGN;}
#line 2117 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 384 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_RAS;}
#line 2123 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 385 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_LSH;}
#line 2129 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 386 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_RSH;}
#line 2135 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 387 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_LRT;}
#line 2141 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 388 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_RRT;}
#line 2147 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 389 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_AND;}
#line 2153 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 390 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_OR;}
#line 2159 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 391 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_XOR;}
#line 2165 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 394 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_ADDI;}
#line 2171 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 395 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_ADCI;}
#line 2177 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 396 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_SUBI;}
#line 2183 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 397 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_SBCI;}
#line 2189 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 398 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_ANDI;}
#line 2195 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 399 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_ORI;}
#line 2201 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 400 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_XORI;}
#line 2207 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 403 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_LSHI;}
#line 2213 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 404 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_RSHI;}
#line 2219 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 405 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_LRTI;}
#line 2225 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 406 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_RRTI;}
#line 2231 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 409 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_JFC;}
#line 2237 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 410 "parser.y" /* yacc.c:1646  */
    {(yyval.iType) = I_JFS;}
#line 2243 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 413 "parser.y" /* yacc.c:1646  */
    {(yyval.mType) = M_JVC;}
#line 2249 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 414 "parser.y" /* yacc.c:1646  */
    {(yyval.mType) = M_JVS;}
#line 2255 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 415 "parser.y" /* yacc.c:1646  */
    {(yyval.mType) = M_JNE;}
#line 2261 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 416 "parser.y" /* yacc.c:1646  */
    {(yyval.mType) = M_JEQ;}
#line 2267 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 417 "parser.y" /* yacc.c:1646  */
    {(yyval.mType) = M_JGE;}
#line 2273 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 418 "parser.y" /* yacc.c:1646  */
    {(yyval.mType) = M_JLT;}
#line 2279 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 419 "parser.y" /* yacc.c:1646  */
    {(yyval.mType) = M_JCC;}
#line 2285 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 420 "parser.y" /* yacc.c:1646  */
    {(yyval.mType) = M_JCS;}
#line 2291 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 423 "parser.y" /* yacc.c:1646  */
    {(yyval.arg) = (yyvsp[0].arg);}
#line 2297 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 424 "parser.y" /* yacc.c:1646  */
    {(yyval.arg) = (yyvsp[0].arg);}
#line 2303 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 425 "parser.y" /* yacc.c:1646  */
    {(yyval.arg) = (yyvsp[0].arg);}
#line 2309 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 427 "parser.y" /* yacc.c:1646  */
    {(yyval.arg) = (yyvsp[0].arg);}
#line 2315 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 428 "parser.y" /* yacc.c:1646  */
    {a.type = A_MACRO_ARG; a.iVal = (yyvsp[0].iVal); (yyval.arg) = a;}
#line 2321 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 431 "parser.y" /* yacc.c:1646  */
    {(yyval.arg) = (yyvsp[0].arg);}
#line 2327 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 432 "parser.y" /* yacc.c:1646  */
    {(yyval.arg) = (yyvsp[0].arg);}
#line 2333 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 433 "parser.y" /* yacc.c:1646  */
    {a.type = A_ZERO; a.iVal = 0; (yyval.arg) = a;}
#line 2339 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 435 "parser.y" /* yacc.c:1646  */
    {(yyval.arg) = (yyvsp[0].arg);}
#line 2345 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 436 "parser.y" /* yacc.c:1646  */
    {a.type = A_MACRO_ARG; a.iVal = (yyvsp[0].iVal); (yyval.arg) = a;}
#line 2351 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 438 "parser.y" /* yacc.c:1646  */
    {(yyval.arg) = (yyvsp[0].arg);}
#line 2357 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 439 "parser.y" /* yacc.c:1646  */
    {a.type = A_REGISTER; a.rType = REG_SP; (yyval.arg) = a;}
#line 2363 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 442 "parser.y" /* yacc.c:1646  */
    {a.type = A_REGISTER; a.rType = REG_A; (yyval.arg) = a;}
#line 2369 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 443 "parser.y" /* yacc.c:1646  */
    {a.type = A_REGISTER; a.rType = REG_B; (yyval.arg) = a;}
#line 2375 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 444 "parser.y" /* yacc.c:1646  */
    {a.type = A_REGISTER; a.rType = REG_C; (yyval.arg) = a;}
#line 2381 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 446 "parser.y" /* yacc.c:1646  */
    {(yyval.arg) = (yyvsp[0].arg);}
#line 2387 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 447 "parser.y" /* yacc.c:1646  */
    {a.type = A_MACRO_ARG; a.iVal = (yyvsp[0].iVal); (yyval.arg) = a;}
#line 2393 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 450 "parser.y" /* yacc.c:1646  */
    {(yyvsp[0].arg).type = A_ABSOLUTE; (yyval.arg) = (yyvsp[0].arg);}
#line 2399 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 451 "parser.y" /* yacc.c:1646  */
    {(yyvsp[0].arg).type = A_INDEX; (yyval.arg) = (yyvsp[0].arg);}
#line 2405 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 452 "parser.y" /* yacc.c:1646  */
    {(yyvsp[0].arg).type = A_ADDRESSED; (yyval.arg) = (yyvsp[0].arg);}
#line 2411 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 453 "parser.y" /* yacc.c:1646  */
    {(yyvsp[0].arg).type = A_STACK; (yyval.arg) = (yyvsp[0].arg);}
#line 2417 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 456 "parser.y" /* yacc.c:1646  */
    {a.type = A_FASTMEM; a.iVal = (yyvsp[0].iVal); (yyval.arg) = a;}
#line 2423 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 457 "parser.y" /* yacc.c:1646  */
    {a.type = A_FASTMEM; a.iVal = 0; (yyval.arg) = a;}
#line 2429 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 459 "parser.y" /* yacc.c:1646  */
    {a.type = A_CONSTANT; a.iVal = (yyvsp[0].iVal); (yyval.arg) = a;}
#line 2435 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 460 "parser.y" /* yacc.c:1646  */
    {a.type = A_CONSTANT; a.iVal = (yyvsp[0].iVal); (yyval.arg) = a;}
#line 2441 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 461 "parser.y" /* yacc.c:1646  */
    {a.type = A_CONSTANT; a.iVal = (yyvsp[0].iVal); (yyval.arg) = a;}
#line 2447 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 462 "parser.y" /* yacc.c:1646  */
    {a.type = A_CONSTANT; a.iVal = (yyvsp[0].iVal); (yyval.arg) = a;}
#line 2453 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 463 "parser.y" /* yacc.c:1646  */
    {a.type = A_ZERO; a.iVal = 0; (yyval.arg) = a;}
#line 2459 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 464 "parser.y" /* yacc.c:1646  */
    {a.type = A_IDENTIFIER; a.text = (yyvsp[0].text); (yyval.arg) = a;}
#line 2465 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 465 "parser.y" /* yacc.c:1646  */
    {a.type = A_ID_HIGH; a.text = (yyvsp[-1].text); (yyval.arg) = a;}
#line 2471 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 466 "parser.y" /* yacc.c:1646  */
    {a.type = A_ID_LOW; a.text = (yyvsp[-1].text); (yyval.arg) = a;}
#line 2477 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 468 "parser.y" /* yacc.c:1646  */
    {(yyval.arg) = (yyvsp[0].arg);}
#line 2483 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 469 "parser.y" /* yacc.c:1646  */
    {(yyval.arg) = (yyvsp[0].arg);}
#line 2489 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 470 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-2].arg).type = A_SUM_HIGH; (yyval.arg) = (yyvsp[-2].arg);}
#line 2495 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 471 "parser.y" /* yacc.c:1646  */
    {(yyvsp[-2].arg).type = A_SUM_LOW; (yyval.arg) = (yyvsp[-2].arg);}
#line 2501 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 474 "parser.y" /* yacc.c:1646  */
    {
                    if ((yyvsp[0].arg).type == A_SUM) {
                        daAppend(ArgumentDArray)((yyvsp[0].arg).sum, &(yyvsp[-2].arg));
                        (yyval.arg) = (yyvsp[0].arg);
                    } else {
                        a.type = A_SUM;
                        a.sum = (ArgumentDArray*) malloc(sizeof(ArgumentDArray));
                        *a.sum = newDArray(ArgumentDArray)(2);
                        daAppend(ArgumentDArray)(a.sum, &(yyvsp[-2].arg));
                        daAppend(ArgumentDArray)(a.sum, &(yyvsp[0].arg));
                        (yyval.arg) = a;
                    }
                }
#line 2519 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 488 "parser.y" /* yacc.c:1646  */
    {(yyval.arg) = (yyvsp[0].arg);}
#line 2525 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 489 "parser.y" /* yacc.c:1646  */
    {a.type = A_MACRO_ARG; a.iVal = (yyvsp[0].iVal); (yyval.arg) = a;}
#line 2531 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 494 "parser.y" /* yacc.c:1646  */
    {a.text = (yyvsp[0].text); (yyval.arg) = a;}
#line 2537 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 496 "parser.y" /* yacc.c:1646  */
    {
                    a.text = (yyvsp[-3].text);
                    a.type = A_IDENTIFIER;
                    if ((yyvsp[-1].arg).type == A_SUM) {
                        daAppend(ArgumentDArray)((yyvsp[-1].arg).sum, &a);
                        (yyval.arg) = (yyvsp[-1].arg);
                    } else {
                        (yyval.arg).sum = (ArgumentDArray*) malloc(sizeof(ArgumentDArray));
                        *(yyval.arg).sum = newDArray(ArgumentDArray)(2);
                        daAppend(ArgumentDArray)((yyval.arg).sum, &(yyvsp[-1].arg));
                        daAppend(ArgumentDArray)((yyval.arg).sum, &a);
                    }
                }
#line 2555 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 509 "parser.y" /* yacc.c:1646  */
    {a.rType = REG_A; (yyval.arg) = a;}
#line 2561 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 510 "parser.y" /* yacc.c:1646  */
    {a.iVal = (yyvsp[-1].arg).iVal; (yyval.arg) = a;}
#line 2567 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 512 "parser.y" /* yacc.c:1646  */
    {(yyval.iVal) = 1;}
#line 2573 "source/parser.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 513 "parser.y" /* yacc.c:1646  */
    {(yyval.iVal) = 0;}
#line 2579 "source/parser.tab.c" /* yacc.c:1646  */
    break;


#line 2583 "source/parser.tab.c" /* yacc.c:1646  */
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
      yyerror (result, userMacros, filename, YY_("syntax error"));
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
        yyerror (result, userMacros, filename, yymsgp);
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
                  yystos[yystate], yyvsp, yylsp, result, userMacros, filename);
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
  yyerror (result, userMacros, filename, YY_("memory exhausted"));
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
                  yytoken, &yylval, &yylloc, result, userMacros, filename);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 515 "parser.y" /* yacc.c:1906  */



void yyerror (InstructionList *result, UserMacroTable *userMacros, char *filename, char const *s)
{
  fprintf (stderr, "%d in %s:%s\n", lineno, filename, s);
}

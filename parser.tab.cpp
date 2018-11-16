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
#line 1 "parser.ypp" /* yacc.c:339  */

	#include <bits/stdc++.h>
	#include "PostfixVisitor.h"
	extern FILE *yyin;
	extern char* yytext;
	extern "C" int yylex();
	extern int yyparse();
	extern FILE *yyin;
	extern int line_num;
	extern int errors;
	void yyerror(const char *s);
	int errors=0;
	class ProgramASTnode* start = NULL;

#line 81 "parser.tab.cpp" /* yacc.c:339  */

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
   by #include "parser.tab.hpp".  */
#ifndef YY_YY_PARSER_TAB_HPP_INCLUDED
# define YY_YY_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    END = 0,
    EOL = 258,
    CLASS = 259,
    PROGRAM = 260,
    COMMENT = 261,
    VOID = 262,
    L_FLO = 263,
    R_FLO = 264,
    L_SQ = 265,
    R_SQ = 266,
    L_P = 267,
    R_P = 268,
    EQ = 269,
    PE = 270,
    ME = 271,
    COMMA = 272,
    SEMI = 273,
    ID = 274,
    BOOLEAN = 275,
    INT = 276,
    INTEGER_LIT = 277,
    HEX_LIT = 278,
    ADD = 279,
    SUB = 280,
    MUL = 281,
    DIV = 282,
    MOD = 283,
    LT = 284,
    GT = 285,
    NOT = 286,
    CHAR_LIT = 287,
    TRUE = 288,
    FALSE = 289,
    NE = 290,
    DO = 291,
    GE = 292,
    DA = 293,
    LE = 294,
    DE = 295,
    CALLOUT = 296,
    STRING_LIT = 297,
    RETURN = 298,
    BREAK = 299,
    CONTINUE = 300,
    IF = 301,
    ELSE = 302,
    FOR = 303
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 16 "parser.ypp" /* yacc.c:355  */

    class ProgramASTnode*		astnode;
    class FieldDec* 		field;
	class FieldDecList* 	fields;
	class Variable*		var_decl;
	class Variables*		var_decls;
	class Lit*   	literal_type;
	class Expr*   	expr_type;
	class integerLit*   	intliteral;
	class charLit*   	charliteral;
	class boolLit*   	boolliteral;
	class stringLit*   	stringliteral;
	char* value;
	class Block*	block_type;
	class meth_args*	meth_args_type;
	class meth_dec*	meth_dec_type;
	class meth_decs* meth_decs_type;
	class var_dec*	var_dec_type;
	class var_decs*	var_decs_type;
	class string_list* string_list_type;
	class Parameters* parameters_type;
	class meth_call* meth_call_type;
	class Statements* statements_type;
	class Statement* statement_type;
	class calloutArgs* callout_args_type;
	class calloutArg* callout_arg_type;
	class breakState* break_type;
	class continueState* continue_type;
	class ifElseState* if_block_type;
	class forState* for_block_type;
	class returnState* return_type;
	class Location*	location_type;
	class Assign*	assign_type;
	class UnExpr* unaryexp_type;
  

#line 208 "parser.tab.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 225 "parser.tab.cpp" /* yacc.c:358  */

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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   375

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  167

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   146,   146,   147,   148,   149,   151,   152,   154,   154,
     156,   157,   159,   160,   162,   162,   164,   165,   168,   169,
     171,   172,   174,   175,   177,   178,   180,   181,   182,   183,
     186,   187,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   199,   200,   201,   203,   205,   206,   209,   210,   211,
     213,   214,   216,   217,   219,   221,   222,   224,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   243,   244,   246,   247,   250,
     251,   252,   254,   255,   257,   258,   260,   262,   263
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "END", "error", "$undefined", "EOL", "CLASS", "PROGRAM", "COMMENT",
  "VOID", "L_FLO", "R_FLO", "L_SQ", "R_SQ", "L_P", "R_P", "EQ", "PE", "ME",
  "COMMA", "SEMI", "ID", "BOOLEAN", "INT", "INTEGER_LIT", "HEX_LIT", "ADD",
  "SUB", "MUL", "DIV", "MOD", "LT", "GT", "NOT", "CHAR_LIT", "TRUE",
  "FALSE", "NE", "DO", "GE", "DA", "LE", "DE", "CALLOUT", "STRING_LIT",
  "RETURN", "BREAK", "CONTINUE", "IF", "ELSE", "FOR", "$accept", "line",
  "field_decl_list", "field_decl", "decl_list", "decl", "type", "intlit",
  "method_decl_list", "method_decl", "method_args_block", "type_id_list",
  "block", "statement_list", "statement", "assign_op", "for_block",
  "if_block", "method_call", "callout_args", "callout_arg", "method_name",
  "expr_list", "expr", "unaryexp", "location", "literal", "bool_lit",
  "var_dec_list", "var_dec", "id_list", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303
};
# endif

#define YYPACT_NINF -68

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-68)))

#define YYTABLE_NINF -55

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      21,     2,    30,    28,   -68,   156,   -68,    51,   -68,   -68,
     -68,   293,   -68,    55,    14,   -68,    32,   -68,   -68,    69,
      35,    81,   -68,   -68,    63,   -68,    -8,    41,   -68,   -13,
      41,    95,   -68,    32,   -68,   108,    15,    64,   -68,   -68,
     -68,    43,   -68,    94,   -68,   -68,   -68,    80,   -68,    67,
      76,    -4,   111,   116,   126,   120,   121,   -68,    78,   -68,
     -68,   -68,   130,   137,    37,    72,   -68,   -68,   131,   211,
     139,   211,   -68,   -68,   -68,   211,   145,   -68,    85,   -68,
     -68,   -68,   207,   -68,   -68,   -68,   211,   -68,    87,   -68,
     -68,   211,   -68,   211,   211,   -68,   -68,   -68,   -68,   158,
     -68,   -68,   -68,   -68,   -68,    20,   -68,   308,   178,   233,
     211,   141,   -68,   -68,    25,   308,   291,   -68,   251,   323,
     -68,   -68,   211,   211,   211,   211,   211,   211,   211,   211,
     211,   211,   211,   211,   211,   -68,   139,   148,    41,   268,
     -68,   -68,   211,   -68,   -68,   323,   323,   335,   335,   335,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,
     127,   211,   308,    41,   117,   -68,   -68
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     9,     0,     4,    15,
      14,     0,     6,     0,     0,    18,     0,     2,     7,     0,
      12,     0,    10,     5,     0,    19,     0,     0,     3,     0,
       0,     0,     8,     0,    23,     0,     0,     0,    21,    17,
      16,     0,    20,    12,    11,    24,    22,     0,    26,    77,
       0,     0,     0,     0,     0,     0,     0,    40,     0,    30,
      36,    35,     0,     0,     0,     0,    84,    13,     0,     0,
       0,     0,    38,    33,    34,     0,     0,    87,     0,    29,
      31,    32,     0,    41,    42,    43,     0,    27,     0,    85,
      25,     0,    79,     0,     0,    81,    82,    83,    71,     0,
      74,    73,    72,    80,    53,     0,    51,    52,     0,     0,
       0,     0,    86,    47,     0,    55,     0,    28,     0,    75,
      76,    78,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    49,     0,     0,     0,     0,
      88,    48,     0,    39,    57,    58,    59,    60,    61,    62,
      65,    66,    67,    70,    64,    69,    63,    68,    50,    37,
      45,     0,    56,     0,     0,    46,    44
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -68,   -68,   -68,   157,   -68,   136,     3,   -68,   164,    -3,
     162,   -68,   -27,   114,   -57,   -68,   -68,   -68,   -19,   -68,
      54,   -68,   -68,   -67,   -68,   -17,   -68,   -68,   -68,   134,
     -68
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,    11,    12,    21,    22,    13,    41,    14,    15,
      30,    36,    57,    58,    59,    86,    60,    61,    98,   105,
     106,    63,   114,   107,   100,   101,   102,   103,    65,    66,
      78
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      38,    80,    99,    42,   108,    34,    71,     3,   109,    39,
      40,    25,     9,    10,    72,   115,    25,    24,    62,   116,
      64,     7,    24,    23,   118,     1,   119,   120,    46,    35,
       4,    80,    47,   135,     9,    10,     5,   136,   141,    62,
      56,    64,   142,   139,    26,    29,    62,    26,    64,    37,
      68,    83,    84,    85,    67,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,    56,    62,
      16,    64,    37,    48,    20,   162,     7,    69,    28,   -54,
      37,    87,    33,    49,     9,    10,    37,    79,    70,     9,
      10,    49,     9,    10,   164,    37,   117,    49,    31,    32,
       9,    10,   111,   112,    29,    50,    49,    51,    52,    53,
      54,   160,    55,    50,    43,    51,    52,    53,    54,    50,
      55,    51,    52,    53,    54,    37,    55,    45,    50,    73,
      51,    52,    53,    54,    74,    55,   165,   166,    75,    76,
      77,   122,   123,   124,   125,   126,   127,   128,    81,    82,
      90,    91,   129,   130,   131,   132,   133,   134,    49,   110,
     140,    92,     6,     7,    93,     8,   159,    44,    18,   121,
      94,    95,    96,    97,   163,    19,     9,    10,    27,    88,
      50,   104,   122,   123,   124,   125,   126,   127,   128,   137,
     158,     0,     0,   129,   130,   131,   132,   133,   134,    89,
       0,     0,   122,   123,   124,   125,   126,   127,   128,     0,
       0,     0,     0,   129,   130,   131,   132,   133,   134,    91,
     113,     0,     0,    91,     0,     0,    49,     0,     0,    92,
      49,     0,    93,    92,     0,     0,    93,     0,    94,    95,
      96,    97,    94,    95,    96,    97,   138,     0,    50,     0,
       0,     0,    50,     0,     0,     0,     0,   122,   123,   124,
     125,   126,   127,   128,   144,     0,     0,     0,   129,   130,
     131,   132,   133,   134,     0,   122,   123,   124,   125,   126,
     127,   128,     0,     0,     0,   161,   129,   130,   131,   132,
     133,   134,   122,   123,   124,   125,   126,   127,   128,     6,
       7,     0,    17,   129,   130,   131,   132,   133,   134,   143,
       0,     0,     0,     9,    10,   122,   123,   124,   125,   126,
     127,   128,     0,     0,     0,     0,   129,   130,   131,   132,
     133,   134,   122,   123,   124,   125,   126,   127,   128,     0,
       0,     0,     0,   129,   130,   131,   132,   133,   134,   124,
     125,   126,   127,   128,     0,     0,     0,     0,   129,   130,
     131,   132,   133,   134,   127,   128,     0,     0,     0,     0,
     129,   130,   131,   132,   133,   134
};

static const yytype_int16 yycheck[] =
{
      27,    58,    69,    30,    71,    13,    10,     5,    75,    22,
      23,    14,    20,    21,    18,    82,    19,    14,    37,    86,
      37,     7,    19,     9,    91,     4,    93,    94,    13,    26,
       0,    88,    17,    13,    20,    21,     8,    17,    13,    58,
      37,    58,    17,   110,    12,    10,    65,    12,    65,     8,
      47,    14,    15,    16,    11,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,    65,    88,
      19,    88,     8,     9,    19,   142,     7,    10,     9,    12,
       8,     9,    19,    19,    20,    21,     8,     9,    12,    20,
      21,    19,    20,    21,   161,     8,     9,    19,    17,    18,
      20,    21,    17,    18,    10,    41,    19,    43,    44,    45,
      46,   138,    48,    41,    19,    43,    44,    45,    46,    41,
      48,    43,    44,    45,    46,     8,    48,    19,    41,    18,
      43,    44,    45,    46,    18,    48,   163,   164,    12,    19,
      19,    24,    25,    26,    27,    28,    29,    30,    18,    12,
      19,    12,    35,    36,    37,    38,    39,    40,    19,    14,
      19,    22,     6,     7,    25,     9,    18,    31,    11,    11,
      31,    32,    33,    34,    47,    11,    20,    21,    16,    65,
      41,    42,    24,    25,    26,    27,    28,    29,    30,    11,
     136,    -1,    -1,    35,    36,    37,    38,    39,    40,    65,
      -1,    -1,    24,    25,    26,    27,    28,    29,    30,    -1,
      -1,    -1,    -1,    35,    36,    37,    38,    39,    40,    12,
      13,    -1,    -1,    12,    -1,    -1,    19,    -1,    -1,    22,
      19,    -1,    25,    22,    -1,    -1,    25,    -1,    31,    32,
      33,    34,    31,    32,    33,    34,    13,    -1,    41,    -1,
      -1,    -1,    41,    -1,    -1,    -1,    -1,    24,    25,    26,
      27,    28,    29,    30,    13,    -1,    -1,    -1,    35,    36,
      37,    38,    39,    40,    -1,    24,    25,    26,    27,    28,
      29,    30,    -1,    -1,    -1,    17,    35,    36,    37,    38,
      39,    40,    24,    25,    26,    27,    28,    29,    30,     6,
       7,    -1,     9,    35,    36,    37,    38,    39,    40,    18,
      -1,    -1,    -1,    20,    21,    24,    25,    26,    27,    28,
      29,    30,    -1,    -1,    -1,    -1,    35,    36,    37,    38,
      39,    40,    24,    25,    26,    27,    28,    29,    30,    -1,
      -1,    -1,    -1,    35,    36,    37,    38,    39,    40,    26,
      27,    28,    29,    30,    -1,    -1,    -1,    -1,    35,    36,
      37,    38,    39,    40,    29,    30,    -1,    -1,    -1,    -1,
      35,    36,    37,    38,    39,    40
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    50,     5,     0,     8,     6,     7,     9,    20,
      21,    51,    52,    55,    57,    58,    19,     9,    52,    57,
      19,    53,    54,     9,    55,    58,    12,    59,     9,    10,
      59,    17,    18,    19,    13,    55,    60,     8,    61,    22,
      23,    56,    61,    19,    54,    19,    13,    17,     9,    19,
      41,    43,    44,    45,    46,    48,    55,    61,    62,    63,
      65,    66,    67,    70,    74,    77,    78,    11,    55,    10,
      12,    10,    18,    18,    18,    12,    19,    19,    79,     9,
      63,    18,    12,    14,    15,    16,    64,     9,    62,    78,
      19,    12,    22,    25,    31,    32,    33,    34,    67,    72,
      73,    74,    75,    76,    42,    68,    69,    72,    72,    72,
      14,    17,    18,    13,    71,    72,    72,     9,    72,    72,
      72,    11,    24,    25,    26,    27,    28,    29,    30,    35,
      36,    37,    38,    39,    40,    13,    17,    11,    13,    72,
      19,    13,    17,    18,    13,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    69,    18,
      61,    17,    72,    47,    72,    61,    61
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    50,    50,    50,    51,    51,    52,    52,
      53,    53,    54,    54,    55,    55,    56,    56,    57,    57,
      58,    58,    59,    59,    60,    60,    61,    61,    61,    61,
      62,    62,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    64,    64,    64,    65,    66,    66,    67,    67,    67,
      68,    68,    69,    69,    70,    71,    71,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    73,    73,    74,    74,    75,
      75,    75,    76,    76,    77,    77,    78,    79,    79
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     6,     4,     5,     1,     2,     3,     1,
       1,     3,     1,     4,     1,     1,     1,     1,     1,     2,
       4,     4,     3,     2,     2,     4,     2,     3,     4,     3,
       1,     2,     2,     2,     2,     1,     1,     5,     2,     4,
       1,     1,     1,     1,     7,     5,     7,     3,     4,     4,
       3,     1,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     1,     2,     2,     1,     4,     1,
       1,     1,     1,     1,     1,     2,     3,     1,     3
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
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
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
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

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

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

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
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 146 "parser.ypp" /* yacc.c:1646  */
    { (yyval.astnode) = new ProgramASTnode("Program Decl", (yyvsp[-1].fields), new meth_decs() ); start = (yyval.astnode);}
#line 1461 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 147 "parser.ypp" /* yacc.c:1646  */
    { (yyval.astnode) = new ProgramASTnode("Program Decl", (yyvsp[-2].fields), (yyvsp[-1].meth_decs_type)); start = (yyval.astnode);}
#line 1467 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 148 "parser.ypp" /* yacc.c:1646  */
    { (yyval.astnode) = new ProgramASTnode("Program"); start = (yyval.astnode);}
#line 1473 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 149 "parser.ypp" /* yacc.c:1646  */
    { (yyval.astnode) = new ProgramASTnode("Program", new FieldDecList() , (yyvsp[-1].meth_decs_type)); start = (yyval.astnode);}
#line 1479 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 151 "parser.ypp" /* yacc.c:1646  */
    { (yyval.fields) = new FieldDecList(); 					(yyval.fields)->push_back((yyvsp[0].field));}
#line 1485 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 152 "parser.ypp" /* yacc.c:1646  */
    {(yyval.fields)->push_back((yyvsp[0].field));}
#line 1491 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 154 "parser.ypp" /* yacc.c:1646  */
    {(yyval.field) = new FieldDec(std::string((yyvsp[-2].value)), (yyvsp[-1].var_decls));}
#line 1497 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 154 "parser.ypp" /* yacc.c:1646  */
    {(yyval.field) = new FieldDec();}
#line 1503 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 156 "parser.ypp" /* yacc.c:1646  */
    {(yyval.var_decls) = new Variables(); (yyval.var_decls)->push_back((yyvsp[0].var_decl));}
#line 1509 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 157 "parser.ypp" /* yacc.c:1646  */
    {(yyval.var_decls)->push_back((yyvsp[0].var_decl));}
#line 1515 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 159 "parser.ypp" /* yacc.c:1646  */
    { (yyval.var_decl) = new Variable(string((yyvsp[0].value)));}
#line 1521 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 160 "parser.ypp" /* yacc.c:1646  */
    {(yyval.var_decl) = new Variable(string((yyvsp[-3].value)),(yyvsp[-1].intliteral)->getValue());}
#line 1527 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 164 "parser.ypp" /* yacc.c:1646  */
    {(yyval.intliteral) = (yyvsp[0].intliteral);}
#line 1533 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 165 "parser.ypp" /* yacc.c:1646  */
    {(yyval.intliteral) = (yyvsp[0].intliteral);}
#line 1539 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 168 "parser.ypp" /* yacc.c:1646  */
    { (yyval.meth_decs_type) = new meth_decs(); 					(yyval.meth_decs_type)->push_back((yyvsp[0].meth_dec_type));}
#line 1545 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 169 "parser.ypp" /* yacc.c:1646  */
    {(yyval.meth_decs_type)->push_back((yyvsp[0].meth_dec_type));}
#line 1551 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 171 "parser.ypp" /* yacc.c:1646  */
    {(yyval.meth_dec_type) = new meth_dec(std::string((yyvsp[-3].value)), (yyvsp[-2].value),(yyvsp[-1].meth_args_type), (yyvsp[0].block_type));}
#line 1557 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 172 "parser.ypp" /* yacc.c:1646  */
    {(yyval.meth_dec_type) = new meth_dec(std::string((yyvsp[-3].value)), (yyvsp[-2].value),(yyvsp[-1].meth_args_type), (yyvsp[0].block_type));}
#line 1563 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 174 "parser.ypp" /* yacc.c:1646  */
    {(yyval.meth_args_type) = (yyvsp[-1].meth_args_type);}
#line 1569 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 175 "parser.ypp" /* yacc.c:1646  */
    {(yyval.meth_args_type) = new meth_args();}
#line 1575 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 177 "parser.ypp" /* yacc.c:1646  */
    {(yyval.meth_args_type) = new meth_args();(yyval.meth_args_type)->push_back(new meth_arg(string((yyvsp[-1].value)), string((yyvsp[0].value))));}
#line 1581 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 178 "parser.ypp" /* yacc.c:1646  */
    {(yyval.meth_args_type)->push_back(new meth_arg(string((yyvsp[-1].value)), string((yyvsp[0].value))));}
#line 1587 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 180 "parser.ypp" /* yacc.c:1646  */
    {(yyval.block_type) = new Block(new var_decs(), new Statements());}
#line 1593 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 181 "parser.ypp" /* yacc.c:1646  */
    {(yyval.block_type) = new Block((yyvsp[-1].var_decs_type), new Statements());}
#line 1599 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 182 "parser.ypp" /* yacc.c:1646  */
    {(yyval.block_type) = new Block((yyvsp[-2].var_decs_type),(yyvsp[-1].statements_type));}
#line 1605 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 183 "parser.ypp" /* yacc.c:1646  */
    {(yyval.block_type) = new Block(new var_decs(),(yyvsp[-1].statements_type));}
#line 1611 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 186 "parser.ypp" /* yacc.c:1646  */
    {(yyval.statements_type) = new Statements(); (yyval.statements_type)->push_back((yyvsp[0].statement_type));}
#line 1617 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 187 "parser.ypp" /* yacc.c:1646  */
    {(yyval.statements_type)->push_back((yyvsp[0].statement_type));}
#line 1623 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 189 "parser.ypp" /* yacc.c:1646  */
    {(yyval.statement_type) = (yyvsp[-1].meth_call_type);}
#line 1629 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 190 "parser.ypp" /* yacc.c:1646  */
    {(yyval.statement_type) = new breakState();}
#line 1635 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 191 "parser.ypp" /* yacc.c:1646  */
    {(yyval.statement_type) = new continueState();}
#line 1641 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 192 "parser.ypp" /* yacc.c:1646  */
    {(yyval.statement_type) = (yyvsp[0].if_block_type);}
#line 1647 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 193 "parser.ypp" /* yacc.c:1646  */
    {(yyval.statement_type) = (yyvsp[0].for_block_type);}
#line 1653 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 194 "parser.ypp" /* yacc.c:1646  */
    {(yyval.statement_type) = new returnState((yyvsp[-2].expr_type));}
#line 1659 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 195 "parser.ypp" /* yacc.c:1646  */
    {(yyval.statement_type) = new returnState();}
#line 1665 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 196 "parser.ypp" /* yacc.c:1646  */
    {(yyval.statement_type) = new Assign((yyvsp[-3].location_type), (yyvsp[-2].value), (yyvsp[-1].expr_type));}
#line 1671 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 197 "parser.ypp" /* yacc.c:1646  */
    {(yyval.statement_type) = (yyvsp[0].block_type);}
#line 1677 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 199 "parser.ypp" /* yacc.c:1646  */
    {(yyval.value) = (yyvsp[0].value);}
#line 1683 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 200 "parser.ypp" /* yacc.c:1646  */
    {(yyval.value) = (yyvsp[0].value);}
#line 1689 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 201 "parser.ypp" /* yacc.c:1646  */
    {(yyval.value) = (yyvsp[0].value);}
#line 1695 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 203 "parser.ypp" /* yacc.c:1646  */
    {(yyval.for_block_type) = new forState((yyvsp[-5].value), (yyvsp[-3].expr_type), (yyvsp[-1].expr_type), (yyvsp[0].block_type)); }
#line 1701 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 205 "parser.ypp" /* yacc.c:1646  */
    {(yyval.if_block_type) = new ifElseState((yyvsp[-2].expr_type), (yyvsp[0].block_type));}
#line 1707 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 206 "parser.ypp" /* yacc.c:1646  */
    {(yyval.if_block_type) = new ifElseState((yyvsp[-4].expr_type), (yyvsp[-2].block_type), (yyvsp[0].block_type));}
#line 1713 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 209 "parser.ypp" /* yacc.c:1646  */
    {(yyval.meth_call_type) = new meth_call(string((yyvsp[-2].value)), new Parameters());}
#line 1719 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 210 "parser.ypp" /* yacc.c:1646  */
    {(yyval.meth_call_type) = new meth_call(string((yyvsp[-3].value)), (yyvsp[-1].parameters_type));}
#line 1725 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 211 "parser.ypp" /* yacc.c:1646  */
    {(yyval.meth_call_type) = new callout_call((yyvsp[-1].callout_args_type));}
#line 1731 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 213 "parser.ypp" /* yacc.c:1646  */
    {(yyval.callout_args_type)->push_back((yyvsp[0].callout_arg_type));}
#line 1737 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 214 "parser.ypp" /* yacc.c:1646  */
    {(yyval.callout_args_type) = new calloutArgs(); (yyval.callout_args_type)->push_back((yyvsp[0].callout_arg_type));}
#line 1743 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 216 "parser.ypp" /* yacc.c:1646  */
    {(yyval.callout_arg_type) = new calloutArg((yyvsp[0].expr_type));}
#line 1749 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 217 "parser.ypp" /* yacc.c:1646  */
    {(yyval.callout_arg_type) = new calloutArg((yyvsp[0].stringliteral));}
#line 1755 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 219 "parser.ypp" /* yacc.c:1646  */
    {(yyval.value) = (yyvsp[0].value);}
#line 1761 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 221 "parser.ypp" /* yacc.c:1646  */
    {(yyval.parameters_type) = new Parameters(); (yyval.parameters_type)->push_back((yyvsp[0].expr_type));}
#line 1767 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 222 "parser.ypp" /* yacc.c:1646  */
    {(yyval.parameters_type)->push_back((yyvsp[0].expr_type));}
#line 1773 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 224 "parser.ypp" /* yacc.c:1646  */
    {(yyval.expr_type) = new EncExpr((yyvsp[-1].expr_type)); (yyval.expr_type)->updateEdata((yyvsp[-1].expr_type)->getEdata());}
#line 1779 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 225 "parser.ypp" /* yacc.c:1646  */
    {(yyval.expr_type) = new BinExpr((yyvsp[-2].expr_type), (yyvsp[0].expr_type), string((yyvsp[-1].value))); (yyval.expr_type)->updateEdata((yyvsp[-2].expr_type)->getEdata()); (yyval.expr_type)->updateEdata((yyvsp[0].expr_type)->getEdata());}
#line 1785 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 226 "parser.ypp" /* yacc.c:1646  */
    {(yyval.expr_type) = new BinExpr((yyvsp[-2].expr_type), (yyvsp[0].expr_type), string((yyvsp[-1].value))); (yyval.expr_type)->updateEdata((yyvsp[-2].expr_type)->getEdata()); (yyval.expr_type)->updateEdata((yyvsp[0].expr_type)->getEdata()); }
#line 1791 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 227 "parser.ypp" /* yacc.c:1646  */
    {(yyval.expr_type) = new BinExpr((yyvsp[-2].expr_type), (yyvsp[0].expr_type), string((yyvsp[-1].value))); (yyval.expr_type)->updateEdata((yyvsp[-2].expr_type)->getEdata()); (yyval.expr_type)->updateEdata((yyvsp[0].expr_type)->getEdata());}
#line 1797 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 228 "parser.ypp" /* yacc.c:1646  */
    {(yyval.expr_type) = new BinExpr((yyvsp[-2].expr_type), (yyvsp[0].expr_type), string((yyvsp[-1].value))); (yyval.expr_type)->updateEdata((yyvsp[-2].expr_type)->getEdata()); (yyval.expr_type)->updateEdata((yyvsp[0].expr_type)->getEdata());}
#line 1803 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 229 "parser.ypp" /* yacc.c:1646  */
    {(yyval.expr_type) = new BinExpr((yyvsp[-2].expr_type), (yyvsp[0].expr_type), string((yyvsp[-1].value))); (yyval.expr_type)->updateEdata((yyvsp[-2].expr_type)->getEdata()); (yyval.expr_type)->updateEdata((yyvsp[0].expr_type)->getEdata());}
#line 1809 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 230 "parser.ypp" /* yacc.c:1646  */
    {(yyval.expr_type) = new BinExpr((yyvsp[-2].expr_type), (yyvsp[0].expr_type), string((yyvsp[-1].value))); (yyval.expr_type)->updateEdata((yyvsp[-2].expr_type)->getEdata()); (yyval.expr_type)->updateEdata((yyvsp[0].expr_type)->getEdata());}
#line 1815 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 231 "parser.ypp" /* yacc.c:1646  */
    {(yyval.expr_type) = new BinExpr((yyvsp[-2].expr_type), (yyvsp[0].expr_type), string((yyvsp[-1].value))); (yyval.expr_type)->updateEdata((yyvsp[-2].expr_type)->getEdata()); (yyval.expr_type)->updateEdata((yyvsp[0].expr_type)->getEdata());}
#line 1821 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 232 "parser.ypp" /* yacc.c:1646  */
    {(yyval.expr_type) = new BinExpr((yyvsp[-2].expr_type), (yyvsp[0].expr_type), string((yyvsp[-1].value))); (yyval.expr_type)->updateEdata((yyvsp[-2].expr_type)->getEdata()); (yyval.expr_type)->setEdata(1);}
#line 1827 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 233 "parser.ypp" /* yacc.c:1646  */
    {(yyval.expr_type) = new BinExpr((yyvsp[-2].expr_type), (yyvsp[0].expr_type), string((yyvsp[-1].value))); (yyval.expr_type)->updateEdata((yyvsp[-2].expr_type)->getEdata()); (yyval.expr_type)->setEdata(1);}
#line 1833 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 234 "parser.ypp" /* yacc.c:1646  */
    {(yyval.expr_type) = new BinExpr((yyvsp[-2].expr_type), (yyvsp[0].expr_type), string((yyvsp[-1].value))); (yyval.expr_type)->updateEdata((yyvsp[-2].expr_type)->getEdata()); (yyval.expr_type)->setEdata(1);}
#line 1839 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 235 "parser.ypp" /* yacc.c:1646  */
    {(yyval.expr_type) = new BinExpr((yyvsp[-2].expr_type), (yyvsp[0].expr_type), string((yyvsp[-1].value))); (yyval.expr_type)->updateEdata((yyvsp[-2].expr_type)->getEdata()); (yyval.expr_type)->setEdata(1);}
#line 1845 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 236 "parser.ypp" /* yacc.c:1646  */
    {(yyval.expr_type) = new BinExpr((yyvsp[-2].expr_type), (yyvsp[0].expr_type), string((yyvsp[-1].value))); (yyval.expr_type)->updateEdata((yyvsp[-2].expr_type)->getEdata()); (yyval.expr_type)->setEdata(1);}
#line 1851 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 237 "parser.ypp" /* yacc.c:1646  */
    {(yyval.expr_type) = new BinExpr((yyvsp[-2].expr_type), (yyvsp[0].expr_type), string((yyvsp[-1].value))); (yyval.expr_type)->updateEdata((yyvsp[-2].expr_type)->getEdata()); (yyval.expr_type)->setEdata(1);}
#line 1857 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 238 "parser.ypp" /* yacc.c:1646  */
    {(yyval.expr_type) = (yyvsp[0].meth_call_type); (yyval.expr_type)->updateEdata(::integer);}
#line 1863 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 239 "parser.ypp" /* yacc.c:1646  */
    {(yyval.expr_type) = (yyvsp[0].literal_type); (yyval.expr_type)->updateEdata((yyvsp[0].literal_type)->getLitType()); }
#line 1869 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 240 "parser.ypp" /* yacc.c:1646  */
    {(yyval.expr_type) = (yyvsp[0].location_type); (yyval.expr_type)->updateEdata(::integer);}
#line 1875 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 241 "parser.ypp" /* yacc.c:1646  */
    {(yyval.expr_type) = (yyvsp[0].unaryexp_type); (yyval.expr_type)->updateEdata(::integer);}
#line 1881 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 243 "parser.ypp" /* yacc.c:1646  */
    {(yyval.unaryexp_type) = new UnExpr((yyvsp[-1].value), (yyvsp[0].expr_type));}
#line 1887 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 244 "parser.ypp" /* yacc.c:1646  */
    {(yyval.unaryexp_type) = new UnExpr((yyvsp[-1].value), (yyvsp[0].expr_type));}
#line 1893 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 246 "parser.ypp" /* yacc.c:1646  */
    {(yyval.location_type) = new Location((yyvsp[0].value));}
#line 1899 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 247 "parser.ypp" /* yacc.c:1646  */
    {(yyval.location_type) = new Location((yyvsp[-3].value), (yyvsp[-1].expr_type));}
#line 1905 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 250 "parser.ypp" /* yacc.c:1646  */
    {(yyval.literal_type) = (yyvsp[0].intliteral);}
#line 1911 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 251 "parser.ypp" /* yacc.c:1646  */
    {(yyval.literal_type) = (yyvsp[0].boolliteral);}
#line 1917 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 252 "parser.ypp" /* yacc.c:1646  */
    {(yyval.literal_type) = (yyvsp[0].charliteral);}
#line 1923 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 254 "parser.ypp" /* yacc.c:1646  */
    {(yyval.boolliteral)=(yyvsp[0].boolliteral);}
#line 1929 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 255 "parser.ypp" /* yacc.c:1646  */
    {(yyval.boolliteral)=(yyvsp[0].boolliteral);}
#line 1935 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 257 "parser.ypp" /* yacc.c:1646  */
    {(yyval.var_decs_type) = new var_decs(); (yyval.var_decs_type)->push_back((yyvsp[0].var_dec_type));}
#line 1941 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 258 "parser.ypp" /* yacc.c:1646  */
    {(yyval.var_decs_type)->push_back((yyvsp[0].var_dec_type));}
#line 1947 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 260 "parser.ypp" /* yacc.c:1646  */
    {(yyval.var_dec_type) = new var_dec(string((yyvsp[-2].value)), (yyvsp[-1].string_list_type));}
#line 1953 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 262 "parser.ypp" /* yacc.c:1646  */
    {(yyval.string_list_type) = new string_list(); (yyval.string_list_type)->push_back(string((yyvsp[0].value)));}
#line 1959 "parser.tab.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 263 "parser.ypp" /* yacc.c:1646  */
    {(yyval.string_list_type)->push_back(string((yyvsp[0].value)));}
#line 1965 "parser.tab.cpp" /* yacc.c:1646  */
    break;


#line 1969 "parser.tab.cpp" /* yacc.c:1646  */
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
      yyerror (YY_("syntax error"));
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
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



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
                      yytoken, &yylval);
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


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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
  yyerror (YY_("memory exhausted"));
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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
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
#line 266 "parser.ypp" /* yacc.c:1906  */


main(int argc, char **argv)
{
	if(argc == 1)
    {
		fprintf(stderr, "Correct usage: parser filename\n");
		exit(1);
	}
	if(argc > 2)
    {
		fprintf(stderr, "Passing more arguments than necessary.\n");
		fprintf(stderr, "Correct usage: parser filename\n");
	}
	yyin = fopen(argv[1], "r");
	yyparse();
	PostFixVisitor* dfs;
	dfs=new PostFixVisitor();
	start->accept(*dfs);
	printf("Parsing Over\n");
}

void yyerror(const char *s)
{
	fprintf(stderr, "error: %s\n", s);
}


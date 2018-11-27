/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
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
     IDEN = 274,
     BOOLEAN = 275,
     INT = 276,
     INTEGER_LIT = 277,
     HEX_LIT = 278,
     ADD = 279,
     SUB = 280,
     MUL = 281,
     DIV = 282,
     MOD = 283,
     LTHAN = 284,
     GT = 285,
     NOT = 286,
     CHAR_LIT = 287,
     TRUE = 288,
     FALSE = 289,
     NE = 290,
     DO = 291,
     GE = 292,
     DA = 293,
     LEQ = 294,
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
/* Tokens.  */
#define END 0
#define EOL 258
#define CLASS 259
#define PROGRAM 260
#define COMMENT 261
#define VOID 262
#define L_FLO 263
#define R_FLO 264
#define L_SQ 265
#define R_SQ 266
#define L_P 267
#define R_P 268
#define EQ 269
#define PE 270
#define ME 271
#define COMMA 272
#define SEMI 273
#define IDEN 274
#define BOOLEAN 275
#define INT 276
#define INTEGER_LIT 277
#define HEX_LIT 278
#define ADD 279
#define SUB 280
#define MUL 281
#define DIV 282
#define MOD 283
#define LTHAN 284
#define GT 285
#define NOT 286
#define CHAR_LIT 287
#define TRUE 288
#define FALSE 289
#define NE 290
#define DO 291
#define GE 292
#define DA 293
#define LEQ 294
#define DE 295
#define CALLOUT 296
#define STRING_LIT 297
#define RETURN 298
#define BREAK 299
#define CONTINUE 300
#define IF 301
#define ELSE 302
#define FOR 303




/* Copy the first part of user declarations.  */
#line 1 "parser.ypp"

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


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 16 "parser.ypp"
{
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
  }
/* Line 193 of yacc.c.  */
#line 245 "parser.tab.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 258 "parser.tab.cpp"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

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
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   424

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNRULES -- Number of states.  */
#define YYNSTATES  168

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     9,    16,    21,    27,    29,    32,    36,
      38,    40,    44,    46,    51,    53,    55,    57,    59,    61,
      64,    69,    74,    78,    81,    84,    89,    92,    96,   101,
     105,   107,   110,   113,   116,   119,   121,   123,   127,   130,
     135,   137,   139,   141,   143,   151,   157,   165,   169,   174,
     181,   186,   190,   192,   194,   196,   198,   200,   204,   208,
     212,   216,   220,   224,   228,   232,   236,   240,   244,   248,
     252,   256,   260,   262,   264,   266,   268,   271,   274,   276,
     281,   283,   285,   287,   289,   291,   293,   296,   300,   302
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      50,     0,    -1,     4,     5,     8,    51,     9,    -1,     4,
       5,     8,    51,    57,     9,    -1,     4,     5,     8,     9,
      -1,     4,     5,     8,    57,     9,    -1,    52,    -1,    51,
      52,    -1,    55,    53,    18,    -1,     6,    -1,    54,    -1,
      53,    17,    54,    -1,    19,    -1,    19,    10,    56,    11,
      -1,    21,    -1,    20,    -1,    23,    -1,    22,    -1,    58,
      -1,    57,    58,    -1,    55,    19,    59,    61,    -1,     7,
      19,    59,    61,    -1,    12,    60,    13,    -1,    12,    13,
      -1,    55,    19,    -1,    60,    17,    55,    19,    -1,     8,
       9,    -1,     8,    77,     9,    -1,     8,    77,    62,     9,
      -1,     8,    62,     9,    -1,    63,    -1,    62,    63,    -1,
      67,    18,    -1,    44,    18,    -1,    45,    18,    -1,    66,
      -1,    65,    -1,    43,    72,    18,    -1,    43,    18,    -1,
      74,    64,    72,    18,    -1,    61,    -1,    14,    -1,    15,
      -1,    16,    -1,    48,    19,    14,    72,    17,    72,    61,
      -1,    46,    12,    72,    13,    61,    -1,    46,    12,    72,
      13,    61,    47,    61,    -1,    70,    12,    13,    -1,    70,
      12,    71,    13,    -1,    41,    12,    42,    17,    68,    13,
      -1,    41,    12,    42,    13,    -1,    68,    17,    69,    -1,
      69,    -1,    72,    -1,    42,    -1,    19,    -1,    72,    -1,
      71,    17,    72,    -1,    12,    72,    13,    -1,    72,    24,
      72,    -1,    72,    25,    72,    -1,    72,    26,    72,    -1,
      72,    27,    72,    -1,    72,    28,    72,    -1,    72,    39,
      72,    -1,    72,    37,    72,    -1,    72,    29,    72,    -1,
      72,    30,    72,    -1,    72,    35,    72,    -1,    72,    40,
      72,    -1,    72,    38,    72,    -1,    72,    36,    72,    -1,
      67,    -1,    75,    -1,    74,    -1,    73,    -1,    25,    72,
      -1,    31,    72,    -1,    19,    -1,    19,    10,    72,    11,
      -1,    22,    -1,    76,    -1,    32,    -1,    33,    -1,    34,
      -1,    78,    -1,    77,    78,    -1,    55,    79,    18,    -1,
      19,    -1,    79,    17,    19,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   146,   146,   147,   148,   149,   151,   152,   154,   154,
     156,   157,   159,   160,   162,   162,   164,   165,   168,   169,
     171,   172,   174,   175,   177,   178,   180,   181,   182,   183,
     186,   187,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   199,   200,   201,   203,   205,   206,   209,   210,   211,
     212,   214,   215,   217,   218,   220,   222,   223,   225,   226,
     227,   228,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   242,   244,   245,   247,   248,
     251,   252,   253,   255,   256,   258,   259,   261,   263,   264
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "END", "error", "$undefined", "EOL", "CLASS", "PROGRAM", "COMMENT",
  "VOID", "L_FLO", "R_FLO", "L_SQ", "R_SQ", "L_P", "R_P", "EQ", "PE", "ME",
  "COMMA", "SEMI", "IDEN", "BOOLEAN", "INT", "INTEGER_LIT", "HEX_LIT",
  "ADD", "SUB", "MUL", "DIV", "MOD", "LTHAN", "GT", "NOT", "CHAR_LIT",
  "TRUE", "FALSE", "NE", "DO", "GE", "DA", "LEQ", "DE", "CALLOUT",
  "STRING_LIT", "RETURN", "BREAK", "CONTINUE", "IF", "ELSE", "FOR",
  "$accept", "line", "field_decl_list", "field_decl", "decl_list", "decl",
  "type", "intlit", "method_decl_list", "method_decl", "method_args_block",
  "type_id_list", "block", "statement_list", "statement", "assign_op",
  "for_block", "if_block", "method_call", "callout_args", "callout_arg",
  "method_name", "expr_list", "expr", "unaryexp", "location", "literal",
  "bool_lit", "var_dec_list", "var_dec", "id_list", 0
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
     295,   296,   297,   298,   299,   300,   301,   302,   303
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    50,    50,    50,    51,    51,    52,    52,
      53,    53,    54,    54,    55,    55,    56,    56,    57,    57,
      58,    58,    59,    59,    60,    60,    61,    61,    61,    61,
      62,    62,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    64,    64,    64,    65,    66,    66,    67,    67,    67,
      67,    68,    68,    69,    69,    70,    71,    71,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    73,    73,    74,    74,
      75,    75,    75,    76,    76,    77,    77,    78,    79,    79
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     6,     4,     5,     1,     2,     3,     1,
       1,     3,     1,     4,     1,     1,     1,     1,     1,     2,
       4,     4,     3,     2,     2,     4,     2,     3,     4,     3,
       1,     2,     2,     2,     2,     1,     1,     3,     2,     4,
       1,     1,     1,     1,     7,     5,     7,     3,     4,     6,
       4,     3,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     1,     1,     1,     1,     2,     2,     1,     4,
       1,     1,     1,     1,     1,     1,     2,     3,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     9,     0,     4,    15,
      14,     0,     6,     0,     0,    18,     0,     2,     7,     0,
      12,     0,    10,     5,     0,    19,     0,     0,     3,     0,
       0,     0,     8,     0,    23,     0,     0,     0,    21,    17,
      16,     0,    20,    12,    11,    24,    22,     0,    26,    78,
       0,     0,     0,     0,     0,     0,     0,    40,     0,    30,
      36,    35,     0,     0,     0,     0,    85,    13,     0,     0,
       0,     0,    38,    80,     0,     0,    82,    83,    84,    72,
       0,    75,    74,    73,    81,    33,    34,     0,     0,    88,
       0,    29,    31,    32,     0,    41,    42,    43,     0,    27,
       0,    86,    25,     0,     0,     0,    76,    77,    37,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    87,    47,     0,    56,     0,
      28,    79,    50,     0,    58,    59,    60,    61,    62,    63,
      66,    67,    68,    71,    65,    70,    64,    69,     0,     0,
      89,    48,     0,    39,    54,     0,    52,    53,    45,     0,
      57,    49,     0,     0,     0,    51,    46,    44
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,    11,    12,    21,    22,    13,    41,    14,    15,
      30,    36,    57,    58,    59,    98,    60,    61,    79,   155,
     156,    63,   127,   157,    81,    82,    83,    84,    65,    66,
      90
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -55
static const yytype_int16 yypact[] =
{
      16,    17,    26,    39,   -55,     9,   -55,    23,   -55,   -55,
     -55,    74,   -55,    53,    34,   -55,    46,   -55,   -55,    77,
      24,    82,   -55,   -55,    57,   -55,    -7,    71,   -55,   -14,
      71,    63,   -55,    46,   -55,    72,    10,    69,   -55,   -55,
     -55,    85,   -55,    91,   -55,   -55,   -55,   118,   -55,    75,
      94,   210,    93,    98,   112,   107,   115,   -55,    99,   -55,
     -55,   -55,   113,   123,    36,    84,   -55,   -55,   122,   237,
     104,   237,   -55,   -55,   237,   237,   -55,   -55,   -55,   -55,
     317,   -55,   -55,   -55,   -55,   -55,   -55,   237,   135,   -55,
     102,   -55,   -55,   -55,   214,   -55,   -55,   -55,   237,   -55,
     114,   -55,   -55,   181,    18,   259,   372,   -55,   -55,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   277,   237,   131,   -55,   -55,    32,   357,   340,
     -55,   -55,   -55,   162,   -55,   372,   372,   384,   384,   384,
     -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,    71,   294,
     -55,   -55,   237,   -55,   -55,    40,   -55,   357,   105,   237,
     357,   -55,   162,    71,   140,   -55,   -55,   -55
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -55,   -55,   -55,   142,   -55,   120,    -9,   -55,   143,   -12,
     145,   -55,   -27,   106,   -54,   -55,   -55,   -55,   -26,   -55,
      -6,   -55,   -55,   -50,   -55,   -25,   -55,   -55,   -55,   108,
     -55
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -56
static const yytype_int16 yytable[] =
{
      38,    80,    25,    42,    92,    24,    34,    25,    39,    40,
      24,    62,    64,     9,    10,     6,     7,    35,     8,   103,
       1,   105,     3,    46,   106,   107,     4,    47,    56,     9,
      10,   132,    62,    64,    29,   133,    26,   122,    68,    62,
      64,     7,    16,    23,   128,   151,    92,     5,   129,   152,
      95,    96,    97,   161,     9,    10,    56,   162,    26,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,    20,   149,    62,    64,    33,    37,    48,    37,
       6,     7,    43,    17,     7,    69,    28,   -55,    49,     9,
      10,    45,    37,    99,     9,    10,    67,     9,    10,    31,
      32,    29,   160,    49,     9,    10,    70,    37,    91,   164,
      50,    85,    51,    52,    53,    54,    86,    55,    49,   124,
     125,   158,    37,   130,    87,    50,    88,    51,    52,    53,
      54,    93,    55,    49,    89,    94,   166,   167,     9,    10,
      50,   102,    51,    52,    53,    54,   104,    55,    37,   123,
     150,    44,   163,    18,    19,    50,   165,    51,    52,    53,
      54,    27,    55,     0,   109,   110,   111,   112,   113,   114,
     115,   100,     0,   101,    71,   116,   117,   118,   119,   120,
     121,    49,     0,     0,    73,     0,     0,    74,     0,     0,
       0,     0,   131,    75,    76,    77,    78,     0,     0,     0,
       0,     0,     0,    50,   154,   109,   110,   111,   112,   113,
     114,   115,     0,     0,     0,     0,   116,   117,   118,   119,
     120,   121,    71,     0,     0,     0,    71,   126,    72,    49,
       0,     0,    73,    49,     0,    74,    73,     0,     0,    74,
       0,    75,    76,    77,    78,    75,    76,    77,    78,    71,
       0,    50,     0,     0,     0,    50,    49,     0,     0,    73,
       0,     0,    74,     0,     0,     0,     0,     0,    75,    76,
      77,    78,   134,     0,     0,     0,     0,     0,    50,     0,
       0,     0,     0,   109,   110,   111,   112,   113,   114,   115,
     148,     0,     0,     0,   116,   117,   118,   119,   120,   121,
       0,   109,   110,   111,   112,   113,   114,   115,     0,     0,
       0,   159,   116,   117,   118,   119,   120,   121,   109,   110,
     111,   112,   113,   114,   115,     0,     0,     0,     0,   116,
     117,   118,   119,   120,   121,   108,     0,     0,     0,     0,
       0,   109,   110,   111,   112,   113,   114,   115,     0,     0,
       0,     0,   116,   117,   118,   119,   120,   121,   153,     0,
       0,     0,     0,     0,   109,   110,   111,   112,   113,   114,
     115,     0,     0,     0,     0,   116,   117,   118,   119,   120,
     121,   109,   110,   111,   112,   113,   114,   115,     0,     0,
       0,     0,   116,   117,   118,   119,   120,   121,   111,   112,
     113,   114,   115,     0,     0,     0,     0,   116,   117,   118,
     119,   120,   121,   114,   115,     0,     0,     0,     0,   116,
     117,   118,   119,   120,   121
};

static const yytype_int16 yycheck[] =
{
      27,    51,    14,    30,    58,    14,    13,    19,    22,    23,
      19,    37,    37,    20,    21,     6,     7,    26,     9,    69,
       4,    71,     5,    13,    74,    75,     0,    17,    37,    20,
      21,    13,    58,    58,    10,    17,    12,    87,    47,    65,
      65,     7,    19,     9,    94,    13,   100,     8,    98,    17,
      14,    15,    16,    13,    20,    21,    65,    17,    12,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,    19,   123,   100,   100,    19,     8,     9,     8,
       6,     7,    19,     9,     7,    10,     9,    12,    19,    20,
      21,    19,     8,     9,    20,    21,    11,    20,    21,    17,
      18,    10,   152,    19,    20,    21,    12,     8,     9,   159,
      41,    18,    43,    44,    45,    46,    18,    48,    19,    17,
      18,   148,     8,     9,    12,    41,    19,    43,    44,    45,
      46,    18,    48,    19,    19,    12,   163,   164,    20,    21,
      41,    19,    43,    44,    45,    46,    42,    48,     8,    14,
      19,    31,    47,    11,    11,    41,   162,    43,    44,    45,
      46,    16,    48,    -1,    24,    25,    26,    27,    28,    29,
      30,    65,    -1,    65,    12,    35,    36,    37,    38,    39,
      40,    19,    -1,    -1,    22,    -1,    -1,    25,    -1,    -1,
      -1,    -1,    11,    31,    32,    33,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    41,    42,    24,    25,    26,    27,    28,
      29,    30,    -1,    -1,    -1,    -1,    35,    36,    37,    38,
      39,    40,    12,    -1,    -1,    -1,    12,    13,    18,    19,
      -1,    -1,    22,    19,    -1,    25,    22,    -1,    -1,    25,
      -1,    31,    32,    33,    34,    31,    32,    33,    34,    12,
      -1,    41,    -1,    -1,    -1,    41,    19,    -1,    -1,    22,
      -1,    -1,    25,    -1,    -1,    -1,    -1,    -1,    31,    32,
      33,    34,    13,    -1,    -1,    -1,    -1,    -1,    41,    -1,
      -1,    -1,    -1,    24,    25,    26,    27,    28,    29,    30,
      13,    -1,    -1,    -1,    35,    36,    37,    38,    39,    40,
      -1,    24,    25,    26,    27,    28,    29,    30,    -1,    -1,
      -1,    17,    35,    36,    37,    38,    39,    40,    24,    25,
      26,    27,    28,    29,    30,    -1,    -1,    -1,    -1,    35,
      36,    37,    38,    39,    40,    18,    -1,    -1,    -1,    -1,
      -1,    24,    25,    26,    27,    28,    29,    30,    -1,    -1,
      -1,    -1,    35,    36,    37,    38,    39,    40,    18,    -1,
      -1,    -1,    -1,    -1,    24,    25,    26,    27,    28,    29,
      30,    -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,
      40,    24,    25,    26,    27,    28,    29,    30,    -1,    -1,
      -1,    -1,    35,    36,    37,    38,    39,    40,    26,    27,
      28,    29,    30,    -1,    -1,    -1,    -1,    35,    36,    37,
      38,    39,    40,    29,    30,    -1,    -1,    -1,    -1,    35,
      36,    37,    38,    39,    40
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
      12,    12,    18,    22,    25,    31,    32,    33,    34,    67,
      72,    73,    74,    75,    76,    18,    18,    12,    19,    19,
      79,     9,    63,    18,    12,    14,    15,    16,    64,     9,
      62,    78,    19,    72,    42,    72,    72,    72,    18,    24,
      25,    26,    27,    28,    29,    30,    35,    36,    37,    38,
      39,    40,    72,    14,    17,    18,    13,    71,    72,    72,
       9,    11,    13,    17,    13,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    13,    72,
      19,    13,    17,    18,    42,    68,    69,    72,    61,    17,
      72,    13,    17,    47,    72,    69,    61,    61
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
      yyerror (YY_("syntax error: cannot back up")); \
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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
		  Type, Value); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

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
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

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
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 146 "parser.ypp"
    { (yyval.astnode) = new ProgramASTnode("Program Decl", (yyvsp[(4) - (5)].fields), new meth_decs() ); start = (yyval.astnode);;}
    break;

  case 3:
#line 147 "parser.ypp"
    { (yyval.astnode) = new ProgramASTnode("Program Decl", (yyvsp[(4) - (6)].fields), (yyvsp[(5) - (6)].meth_decs_type)); start = (yyval.astnode);;}
    break;

  case 4:
#line 148 "parser.ypp"
    { (yyval.astnode) = new ProgramASTnode("Program"); start = (yyval.astnode);;}
    break;

  case 5:
#line 149 "parser.ypp"
    { (yyval.astnode) = new ProgramASTnode("Program", new FieldDecList() , (yyvsp[(4) - (5)].meth_decs_type)); start = (yyval.astnode);;}
    break;

  case 6:
#line 151 "parser.ypp"
    { (yyval.fields) = new FieldDecList(); 					(yyval.fields)->push_back((yyvsp[(1) - (1)].field));;}
    break;

  case 7:
#line 152 "parser.ypp"
    {(yyval.fields)->push_back((yyvsp[(2) - (2)].field));;}
    break;

  case 8:
#line 154 "parser.ypp"
    {(yyval.field) = new FieldDec(std::string((yyvsp[(1) - (3)].value)), (yyvsp[(2) - (3)].var_decls));;}
    break;

  case 9:
#line 154 "parser.ypp"
    {(yyval.field) = new FieldDec();;}
    break;

  case 10:
#line 156 "parser.ypp"
    {(yyval.var_decls) = new Variables(); (yyval.var_decls)->push_back((yyvsp[(1) - (1)].var_decl));;}
    break;

  case 11:
#line 157 "parser.ypp"
    {(yyval.var_decls)->push_back((yyvsp[(3) - (3)].var_decl));;}
    break;

  case 12:
#line 159 "parser.ypp"
    { (yyval.var_decl) = new Variable(string((yyvsp[(1) - (1)].value)));;}
    break;

  case 13:
#line 160 "parser.ypp"
    {(yyval.var_decl) = new Variable(string((yyvsp[(1) - (4)].value)),(yyvsp[(3) - (4)].intliteral)->getValue());;}
    break;

  case 16:
#line 164 "parser.ypp"
    {(yyval.intliteral) = (yyvsp[(1) - (1)].intliteral);;}
    break;

  case 17:
#line 165 "parser.ypp"
    {(yyval.intliteral) = (yyvsp[(1) - (1)].intliteral);;}
    break;

  case 18:
#line 168 "parser.ypp"
    { (yyval.meth_decs_type) = new meth_decs(); 					(yyval.meth_decs_type)->push_back((yyvsp[(1) - (1)].meth_dec_type));;}
    break;

  case 19:
#line 169 "parser.ypp"
    {(yyval.meth_decs_type)->push_back((yyvsp[(2) - (2)].meth_dec_type));;}
    break;

  case 20:
#line 171 "parser.ypp"
    {(yyval.meth_dec_type) = new meth_dec(std::string((yyvsp[(1) - (4)].value)), (yyvsp[(2) - (4)].value),(yyvsp[(3) - (4)].meth_args_type), (yyvsp[(4) - (4)].block_type));;}
    break;

  case 21:
#line 172 "parser.ypp"
    {(yyval.meth_dec_type) = new meth_dec(std::string((yyvsp[(1) - (4)].value)), (yyvsp[(2) - (4)].value),(yyvsp[(3) - (4)].meth_args_type), (yyvsp[(4) - (4)].block_type));;}
    break;

  case 22:
#line 174 "parser.ypp"
    {(yyval.meth_args_type) = (yyvsp[(2) - (3)].meth_args_type);;}
    break;

  case 23:
#line 175 "parser.ypp"
    {(yyval.meth_args_type) = new meth_args();;}
    break;

  case 24:
#line 177 "parser.ypp"
    {(yyval.meth_args_type) = new meth_args();(yyval.meth_args_type)->push_back(new meth_arg(string((yyvsp[(1) - (2)].value)), string((yyvsp[(2) - (2)].value))));;}
    break;

  case 25:
#line 178 "parser.ypp"
    {(yyval.meth_args_type)->push_back(new meth_arg(string((yyvsp[(3) - (4)].value)), string((yyvsp[(4) - (4)].value))));;}
    break;

  case 26:
#line 180 "parser.ypp"
    {(yyval.block_type) = new Block(new var_decs(), new Statements());;}
    break;

  case 27:
#line 181 "parser.ypp"
    {(yyval.block_type) = new Block((yyvsp[(2) - (3)].var_decs_type), new Statements());;}
    break;

  case 28:
#line 182 "parser.ypp"
    {(yyval.block_type) = new Block((yyvsp[(2) - (4)].var_decs_type),(yyvsp[(3) - (4)].statements_type));;}
    break;

  case 29:
#line 183 "parser.ypp"
    {(yyval.block_type) = new Block(new var_decs(),(yyvsp[(2) - (3)].statements_type));;}
    break;

  case 30:
#line 186 "parser.ypp"
    {(yyval.statements_type) = new Statements(); (yyval.statements_type)->push_back((yyvsp[(1) - (1)].statement_type));;}
    break;

  case 31:
#line 187 "parser.ypp"
    {(yyval.statements_type)->push_back((yyvsp[(2) - (2)].statement_type));;}
    break;

  case 32:
#line 189 "parser.ypp"
    {(yyval.statement_type) = (yyvsp[(1) - (2)].meth_call_type);;}
    break;

  case 33:
#line 190 "parser.ypp"
    {(yyval.statement_type) = new breakState();;}
    break;

  case 34:
#line 191 "parser.ypp"
    {(yyval.statement_type) = new continueState();;}
    break;

  case 35:
#line 192 "parser.ypp"
    {(yyval.statement_type) = (yyvsp[(1) - (1)].if_block_type);;}
    break;

  case 36:
#line 193 "parser.ypp"
    {(yyval.statement_type) = (yyvsp[(1) - (1)].for_block_type);;}
    break;

  case 37:
#line 194 "parser.ypp"
    {(yyval.statement_type) = new returnState((yyvsp[(2) - (3)].expr_type));;}
    break;

  case 38:
#line 195 "parser.ypp"
    {(yyval.statement_type) = new returnState();;}
    break;

  case 39:
#line 196 "parser.ypp"
    {(yyval.statement_type) = new Assign((yyvsp[(1) - (4)].location_type), (yyvsp[(2) - (4)].value), (yyvsp[(3) - (4)].expr_type));;}
    break;

  case 40:
#line 197 "parser.ypp"
    {(yyval.statement_type) = (yyvsp[(1) - (1)].block_type);;}
    break;

  case 41:
#line 199 "parser.ypp"
    {(yyval.value) = (yyvsp[(1) - (1)].value);;}
    break;

  case 42:
#line 200 "parser.ypp"
    {(yyval.value) = (yyvsp[(1) - (1)].value);;}
    break;

  case 43:
#line 201 "parser.ypp"
    {(yyval.value) = (yyvsp[(1) - (1)].value);;}
    break;

  case 44:
#line 203 "parser.ypp"
    {(yyval.for_block_type) = new forState((yyvsp[(2) - (7)].value), (yyvsp[(4) - (7)].expr_type), (yyvsp[(6) - (7)].expr_type), (yyvsp[(7) - (7)].block_type)); ;}
    break;

  case 45:
#line 205 "parser.ypp"
    {(yyval.if_block_type) = new ifElseState((yyvsp[(3) - (5)].expr_type), (yyvsp[(5) - (5)].block_type));;}
    break;

  case 46:
#line 206 "parser.ypp"
    {(yyval.if_block_type) = new ifElseState((yyvsp[(3) - (7)].expr_type), (yyvsp[(5) - (7)].block_type), (yyvsp[(7) - (7)].block_type));;}
    break;

  case 47:
#line 209 "parser.ypp"
    {(yyval.meth_call_type) = new meth_call(string((yyvsp[(1) - (3)].value)), new Parameters());;}
    break;

  case 48:
#line 210 "parser.ypp"
    {(yyval.meth_call_type) = new meth_call(string((yyvsp[(1) - (4)].value)), (yyvsp[(3) - (4)].parameters_type));;}
    break;

  case 49:
#line 211 "parser.ypp"
    {(yyval.meth_call_type) = new callout_call((yyvsp[(3) - (6)].stringliteral)->value,(yyvsp[(5) - (6)].callout_args_type));;}
    break;

  case 50:
#line 212 "parser.ypp"
    {(yyval.meth_call_type) = new callout_call((yyvsp[(3) - (4)].stringliteral)->value,new calloutArgs());;}
    break;

  case 51:
#line 214 "parser.ypp"
    {(yyval.callout_args_type)->push_back((yyvsp[(3) - (3)].callout_arg_type));;}
    break;

  case 52:
#line 215 "parser.ypp"
    {(yyval.callout_args_type) = new calloutArgs(); (yyval.callout_args_type)->push_back((yyvsp[(1) - (1)].callout_arg_type));;}
    break;

  case 53:
#line 217 "parser.ypp"
    {(yyval.callout_arg_type) = new calloutArg((yyvsp[(1) - (1)].expr_type));;}
    break;

  case 54:
#line 218 "parser.ypp"
    {(yyval.callout_arg_type) = new calloutArg((yyvsp[(1) - (1)].stringliteral));;}
    break;

  case 55:
#line 220 "parser.ypp"
    {(yyval.value) = (yyvsp[(1) - (1)].value);;}
    break;

  case 56:
#line 222 "parser.ypp"
    {(yyval.parameters_type) = new Parameters(); (yyval.parameters_type)->push_back((yyvsp[(1) - (1)].expr_type));;}
    break;

  case 57:
#line 223 "parser.ypp"
    {(yyval.parameters_type)->push_back((yyvsp[(3) - (3)].expr_type));;}
    break;

  case 58:
#line 225 "parser.ypp"
    {(yyval.expr_type) = new EncExpr((yyvsp[(2) - (3)].expr_type)); (yyval.expr_type)->updateEdata((yyvsp[(2) - (3)].expr_type)->getEdata());;}
    break;

  case 59:
#line 226 "parser.ypp"
    {(yyval.expr_type) = new BinExpr((yyvsp[(1) - (3)].expr_type), (yyvsp[(3) - (3)].expr_type), string((yyvsp[(2) - (3)].value))); (yyval.expr_type)->updateEdata((yyvsp[(1) - (3)].expr_type)->getEdata()); (yyval.expr_type)->updateEdata((yyvsp[(3) - (3)].expr_type)->getEdata());;}
    break;

  case 60:
#line 227 "parser.ypp"
    {(yyval.expr_type) = new BinExpr((yyvsp[(1) - (3)].expr_type), (yyvsp[(3) - (3)].expr_type), string((yyvsp[(2) - (3)].value))); (yyval.expr_type)->updateEdata((yyvsp[(1) - (3)].expr_type)->getEdata()); (yyval.expr_type)->updateEdata((yyvsp[(3) - (3)].expr_type)->getEdata()); ;}
    break;

  case 61:
#line 228 "parser.ypp"
    {(yyval.expr_type) = new BinExpr((yyvsp[(1) - (3)].expr_type), (yyvsp[(3) - (3)].expr_type), string((yyvsp[(2) - (3)].value))); (yyval.expr_type)->updateEdata((yyvsp[(1) - (3)].expr_type)->getEdata()); (yyval.expr_type)->updateEdata((yyvsp[(3) - (3)].expr_type)->getEdata());;}
    break;

  case 62:
#line 229 "parser.ypp"
    {(yyval.expr_type) = new BinExpr((yyvsp[(1) - (3)].expr_type), (yyvsp[(3) - (3)].expr_type), string((yyvsp[(2) - (3)].value))); (yyval.expr_type)->updateEdata((yyvsp[(1) - (3)].expr_type)->getEdata()); (yyval.expr_type)->updateEdata((yyvsp[(3) - (3)].expr_type)->getEdata());;}
    break;

  case 63:
#line 230 "parser.ypp"
    {(yyval.expr_type) = new BinExpr((yyvsp[(1) - (3)].expr_type), (yyvsp[(3) - (3)].expr_type), string((yyvsp[(2) - (3)].value))); (yyval.expr_type)->updateEdata((yyvsp[(1) - (3)].expr_type)->getEdata()); (yyval.expr_type)->updateEdata((yyvsp[(3) - (3)].expr_type)->getEdata());;}
    break;

  case 64:
#line 231 "parser.ypp"
    {(yyval.expr_type) = new BinExpr((yyvsp[(1) - (3)].expr_type), (yyvsp[(3) - (3)].expr_type), string((yyvsp[(2) - (3)].value))); (yyval.expr_type)->updateEdata((yyvsp[(1) - (3)].expr_type)->getEdata()); (yyval.expr_type)->updateEdata((yyvsp[(3) - (3)].expr_type)->getEdata());;}
    break;

  case 65:
#line 232 "parser.ypp"
    {(yyval.expr_type) = new BinExpr((yyvsp[(1) - (3)].expr_type), (yyvsp[(3) - (3)].expr_type), string((yyvsp[(2) - (3)].value))); (yyval.expr_type)->updateEdata((yyvsp[(1) - (3)].expr_type)->getEdata()); (yyval.expr_type)->updateEdata((yyvsp[(3) - (3)].expr_type)->getEdata());;}
    break;

  case 66:
#line 233 "parser.ypp"
    {(yyval.expr_type) = new BinExpr((yyvsp[(1) - (3)].expr_type), (yyvsp[(3) - (3)].expr_type), string((yyvsp[(2) - (3)].value))); (yyval.expr_type)->updateEdata((yyvsp[(1) - (3)].expr_type)->getEdata()); (yyval.expr_type)->setEdata(1);;}
    break;

  case 67:
#line 234 "parser.ypp"
    {(yyval.expr_type) = new BinExpr((yyvsp[(1) - (3)].expr_type), (yyvsp[(3) - (3)].expr_type), string((yyvsp[(2) - (3)].value))); (yyval.expr_type)->updateEdata((yyvsp[(1) - (3)].expr_type)->getEdata()); (yyval.expr_type)->setEdata(1);;}
    break;

  case 68:
#line 235 "parser.ypp"
    {(yyval.expr_type) = new BinExpr((yyvsp[(1) - (3)].expr_type), (yyvsp[(3) - (3)].expr_type), string((yyvsp[(2) - (3)].value))); (yyval.expr_type)->updateEdata((yyvsp[(1) - (3)].expr_type)->getEdata()); (yyval.expr_type)->setEdata(1);;}
    break;

  case 69:
#line 236 "parser.ypp"
    {(yyval.expr_type) = new BinExpr((yyvsp[(1) - (3)].expr_type), (yyvsp[(3) - (3)].expr_type), string((yyvsp[(2) - (3)].value))); (yyval.expr_type)->updateEdata((yyvsp[(1) - (3)].expr_type)->getEdata()); (yyval.expr_type)->setEdata(1);;}
    break;

  case 70:
#line 237 "parser.ypp"
    {(yyval.expr_type) = new BinExpr((yyvsp[(1) - (3)].expr_type), (yyvsp[(3) - (3)].expr_type), string((yyvsp[(2) - (3)].value))); (yyval.expr_type)->updateEdata((yyvsp[(1) - (3)].expr_type)->getEdata()); (yyval.expr_type)->setEdata(1);;}
    break;

  case 71:
#line 238 "parser.ypp"
    {(yyval.expr_type) = new BinExpr((yyvsp[(1) - (3)].expr_type), (yyvsp[(3) - (3)].expr_type), string((yyvsp[(2) - (3)].value))); (yyval.expr_type)->updateEdata((yyvsp[(1) - (3)].expr_type)->getEdata()); (yyval.expr_type)->setEdata(1);;}
    break;

  case 72:
#line 239 "parser.ypp"
    {(yyval.expr_type) = (yyvsp[(1) - (1)].meth_call_type); (yyval.expr_type)->updateEdata(::integer);;}
    break;

  case 73:
#line 240 "parser.ypp"
    {(yyval.expr_type) = (yyvsp[(1) - (1)].literal_type); (yyval.expr_type)->updateEdata((yyvsp[(1) - (1)].literal_type)->getLitType()); ;}
    break;

  case 74:
#line 241 "parser.ypp"
    {(yyval.expr_type) = (yyvsp[(1) - (1)].location_type); (yyval.expr_type)->updateEdata(::integer);;}
    break;

  case 75:
#line 242 "parser.ypp"
    {(yyval.expr_type) = (yyvsp[(1) - (1)].unaryexp_type); (yyval.expr_type)->updateEdata(::integer);;}
    break;

  case 76:
#line 244 "parser.ypp"
    {(yyval.unaryexp_type) = new UnExpr((yyvsp[(1) - (2)].value), (yyvsp[(2) - (2)].expr_type));;}
    break;

  case 77:
#line 245 "parser.ypp"
    {(yyval.unaryexp_type) = new UnExpr((yyvsp[(1) - (2)].value), (yyvsp[(2) - (2)].expr_type));;}
    break;

  case 78:
#line 247 "parser.ypp"
    {(yyval.location_type) = new Location((yyvsp[(1) - (1)].value));;}
    break;

  case 79:
#line 248 "parser.ypp"
    {(yyval.location_type) = new Location((yyvsp[(1) - (4)].value), (yyvsp[(3) - (4)].expr_type));;}
    break;

  case 80:
#line 251 "parser.ypp"
    {(yyval.literal_type) = (yyvsp[(1) - (1)].intliteral);;}
    break;

  case 81:
#line 252 "parser.ypp"
    {(yyval.literal_type) = (yyvsp[(1) - (1)].boolliteral);;}
    break;

  case 82:
#line 253 "parser.ypp"
    {(yyval.literal_type) = (yyvsp[(1) - (1)].charliteral);;}
    break;

  case 83:
#line 255 "parser.ypp"
    {(yyval.boolliteral)=(yyvsp[(1) - (1)].boolliteral);;}
    break;

  case 84:
#line 256 "parser.ypp"
    {(yyval.boolliteral)=(yyvsp[(1) - (1)].boolliteral);;}
    break;

  case 85:
#line 258 "parser.ypp"
    {(yyval.var_decs_type) = new var_decs(); (yyval.var_decs_type)->push_back((yyvsp[(1) - (1)].var_dec_type));;}
    break;

  case 86:
#line 259 "parser.ypp"
    {(yyval.var_decs_type)->push_back((yyvsp[(2) - (2)].var_dec_type));;}
    break;

  case 87:
#line 261 "parser.ypp"
    {(yyval.var_dec_type) = new var_dec(string((yyvsp[(1) - (3)].value)), (yyvsp[(2) - (3)].string_list_type));;}
    break;

  case 88:
#line 263 "parser.ypp"
    {(yyval.string_list_type) = new string_list(); (yyval.string_list_type)->push_back(string((yyvsp[(1) - (1)].value)));;}
    break;

  case 89:
#line 264 "parser.ypp"
    {(yyval.string_list_type)->push_back(string((yyvsp[(3) - (3)].value)));;}
    break;


/* Line 1267 of yacc.c.  */
#line 2086 "parser.tab.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


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
      yyerror (YY_("syntax error"));
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
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 267 "parser.ypp"


int main(int argc, char **argv)
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
	printf("\n");
	yyparse();
	PostFixVisitor* dfs;
	dfs=new PostFixVisitor();
	start->accept(*dfs);
	start->Codegen();
	cout << "Errors during IR Generation: " << errors_IR << endl;
	if(!errors_IR)
		start->generateCodeDump();	
	printf("\nParsing Over\n");
}

void yyerror(const char *s)
{
	fprintf(stderr, "error: %s\n", s);
}



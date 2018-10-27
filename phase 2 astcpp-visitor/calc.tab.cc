/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison LALR(1) parsers in C++

   Copyright (C) 2002, 2003, 2004, 2005, 2006 Free Software Foundation, Inc.

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

// Take the name prefix into account.
#define yylex   decaflex

#include "calc.tab.hh"

/* User implementation prologue.  */
#line 67 "calc.yy"


#include "driver.h"
#include "scanner.h"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex



/* Line 317 of lalr1.cc.  */
#line 57 "calc.tab.cc"

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* FIXME: INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#define YYUSE(e) ((void) (e))

/* A pseudo ostream that takes yydebug_ into account.  */
# define YYCDEBUG							\
  for (bool yydebugcond_ = yydebug_; yydebugcond_; yydebugcond_ = false)	\
    (*yycdebug_)

/* Enable debugging if requested.  */
#if YYDEBUG

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)	\
do {							\
  if (yydebug_)						\
    {							\
      *yycdebug_ << Title << ' ';			\
      yy_symbol_print_ ((Type), (Value), (Location));	\
      *yycdebug_ << std::endl;				\
    }							\
} while (false)

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug_)				\
    yy_reduce_print_ (Rule);		\
} while (false)

# define YY_STACK_PRINT()		\
do {					\
  if (yydebug_)				\
    yystack_print_ ();			\
} while (false)

#else /* !YYDEBUG */

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_REDUCE_PRINT(Rule)
# define YY_STACK_PRINT()

#endif /* !YYDEBUG */

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab

namespace decaf
{
#if YYERROR_VERBOSE

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  Parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
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
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

#endif

  /// Build a parser object.
  Parser::Parser (class Driver& driver_yyarg)
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
      driver (driver_yyarg)
  {
  }

  Parser::~Parser ()
  {
  }

#if YYDEBUG
  /*--------------------------------.
  | Print this symbol on YYOUTPUT.  |
  `--------------------------------*/

  inline void
  Parser::yy_symbol_value_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yyvaluep);
    switch (yytype)
      {
         default:
	  break;
      }
  }


  void
  Parser::yy_symbol_print_ (int yytype,
			   const semantic_type* yyvaluep, const location_type* yylocationp)
  {
    *yycdebug_ << (yytype < yyntokens_ ? "token" : "nterm")
	       << ' ' << yytname_[yytype] << " ("
	       << *yylocationp << ": ";
    yy_symbol_value_print_ (yytype, yyvaluep, yylocationp);
    *yycdebug_ << ')';
  }
#endif /* ! YYDEBUG */

  void
  Parser::yydestruct_ (const char* yymsg,
			   int yytype, semantic_type* yyvaluep, location_type* yylocationp)
  {
    YYUSE (yylocationp);
    YYUSE (yymsg);
    YYUSE (yyvaluep);

    YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

    switch (yytype)
      {
  
	default:
	  break;
      }
  }

  void
  Parser::yypop_ (unsigned int n)
  {
    yystate_stack_.pop (n);
    yysemantic_stack_.pop (n);
    yylocation_stack_.pop (n);
  }

  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }


  int
  Parser::parse ()
  {
    /// Look-ahead and look-ahead in internal form.
    int yychar = yyempty_;
    int yytoken = 0;

    /* State.  */
    int yyn;
    int yylen = 0;
    int yystate = 0;

    /* Error handling.  */
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// Semantic value of the look-ahead.
    semantic_type yylval;
    /// Location of the look-ahead.
    location_type yylloc;
    /// The locations where the error started and ended.
    location yyerror_range[2];

    /// $$.
    semantic_type yyval;
    /// @$.
    location_type yyloc;

    int yyresult;

    YYCDEBUG << "Starting parse" << std::endl;


    /* User initialization code.  */
    #line 41 "calc.yy"
{
    // initialize the initial location object
    yylloc.begin.filename = yylloc.end.filename = &driver.streamname;
}
  /* Line 555 of yacc.c.  */
#line 294 "calc.tab.cc"
    /* Initialize the stacks.  The initial state will be pushed in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystate_stack_ = state_stack_type (0);
    yysemantic_stack_ = semantic_stack_type (0);
    yylocation_stack_ = location_stack_type (0);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* New state.  */
  yynewstate:
    yystate_stack_.push (yystate);
    YYCDEBUG << "Entering state " << yystate << std::endl;
    goto yybackup;

    /* Backup.  */
  yybackup:

    /* Try to take a decision without look-ahead.  */
    yyn = yypact_[yystate];
    if (yyn == yypact_ninf_)
      goto yydefault;

    /* Read a look-ahead token.  */
    if (yychar == yyempty_)
      {
	YYCDEBUG << "Reading a token: ";
	yychar = yylex (&yylval, &yylloc);
      }


    /* Convert token to internal form.  */
    if (yychar <= yyeof_)
      {
	yychar = yytoken = yyeof_;
	YYCDEBUG << "Now at end of input." << std::endl;
      }
    else
      {
	yytoken = yytranslate_ (yychar);
	YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
      }

    /* If the proper action on seeing token YYTOKEN is to reduce or to
       detect an error, take that action.  */
    yyn += yytoken;
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yytoken)
      goto yydefault;

    /* Reduce or error.  */
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
	if (yyn == 0 || yyn == yytable_ninf_)
	goto yyerrlab;
	yyn = -yyn;
	goto yyreduce;
      }

    /* Accept?  */
    if (yyn == yyfinal_)
      goto yyacceptlab;

    /* Shift the look-ahead token.  */
    YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

    /* Discard the token being shifted unless it is eof.  */
    if (yychar != yyeof_)
      yychar = yyempty_;

    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yylloc);

    /* Count tokens shifted since error; after three, turn off error
       status.  */
    if (yyerrstatus_)
      --yyerrstatus_;

    yystate = yyn;
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystate];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    /* If YYLEN is nonzero, implement the default value of the action:
       `$$ = $1'.  Otherwise, use the top of the stack.

       Otherwise, the following line sets YYVAL to garbage.
       This behavior is undocumented and Bison
       users should not rely upon it.  */
    if (yylen)
      yyval = yysemantic_stack_[yylen - 1];
    else
      yyval = yysemantic_stack_[0];

    {
      slice<location_type, location_stack_type> slice (yylocation_stack_, yylen);
      YYLLOC_DEFAULT (yyloc, slice, yylen);
    }
    YY_REDUCE_PRINT (yyn);
    switch (yyn)
      {
	  case 2:
#line 135 "calc.yy"
    { std::cout << "Hello" << std::endl;;}
    break;


    /* Line 675 of lalr1.cc.  */
#line 416 "calc.tab.cc"
	default: break;
      }
    YY_SYMBOL_PRINT ("-> $$ =", yyr1_[yyn], &yyval, &yyloc);

    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();

    yysemantic_stack_.push (yyval);
    yylocation_stack_.push (yyloc);

    /* Shift the result of the reduction.  */
    yyn = yyr1_[yyn];
    yystate = yypgoto_[yyn - yyntokens_] + yystate_stack_[0];
    if (0 <= yystate && yystate <= yylast_
	&& yycheck_[yystate] == yystate_stack_[0])
      yystate = yytable_[yystate];
    else
      yystate = yydefgoto_[yyn - yyntokens_];
    goto yynewstate;

  /*------------------------------------.
  | yyerrlab -- here on detecting error |
  `------------------------------------*/
  yyerrlab:
    /* If not already recovering from an error, report this error.  */
    if (!yyerrstatus_)
      {
	++yynerrs_;
	error (yylloc, yysyntax_error_ (yystate, yytoken));
      }

    yyerror_range[0] = yylloc;
    if (yyerrstatus_ == 3)
      {
	/* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

	if (yychar <= yyeof_)
	  {
	  /* Return failure if at end of input.  */
	  if (yychar == yyeof_)
	    YYABORT;
	  }
	else
	  {
	    yydestruct_ ("Error: discarding", yytoken, &yylval, &yylloc);
	    yychar = yyempty_;
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
    if (false)
      goto yyerrorlab;

    yyerror_range[0] = yylocation_stack_[yylen - 1];
    /* Do not reclaim the symbols of the rule which action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    yystate = yystate_stack_[0];
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;	/* Each real token shifted decrements this.  */

    for (;;)
      {
	yyn = yypact_[yystate];
	if (yyn != yypact_ninf_)
	{
	  yyn += yyterror_;
	  if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
	    {
	      yyn = yytable_[yyn];
	      if (0 < yyn)
		break;
	    }
	}

	/* Pop the current state because it cannot handle the error token.  */
	if (yystate_stack_.height () == 1)
	YYABORT;

	yyerror_range[0] = yylocation_stack_[0];
	yydestruct_ ("Error: popping",
		     yystos_[yystate],
		     &yysemantic_stack_[0], &yylocation_stack_[0]);
	yypop_ ();
	yystate = yystate_stack_[0];
	YY_STACK_PRINT ();
      }

    if (yyn == yyfinal_)
      goto yyacceptlab;

    yyerror_range[1] = yylloc;
    // Using YYLLOC is tempting, but would change the location of
    // the look-ahead.  YYLOC is available though.
    YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
    yysemantic_stack_.push (yylval);
    yylocation_stack_.push (yyloc);

    /* Shift the error token.  */
    YY_SYMBOL_PRINT ("Shifting", yystos_[yyn],
		   &yysemantic_stack_[0], &yylocation_stack_[0]);

    yystate = yyn;
    goto yynewstate;

    /* Accept.  */
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    /* Abort.  */
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (yychar != yyeof_ && yychar != yyempty_)
      yydestruct_ ("Cleanup: discarding lookahead", yytoken, &yylval, &yylloc);

    /* Do not reclaim the symbols of the rule which action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (yystate_stack_.height () != 1)
      {
	yydestruct_ ("Cleanup: popping",
		   yystos_[yystate_stack_[0]],
		   &yysemantic_stack_[0],
		   &yylocation_stack_[0]);
	yypop_ ();
      }

    return yyresult;
  }

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (int yystate, int tok)
  {
    std::string res;
    YYUSE (yystate);
#if YYERROR_VERBOSE
    int yyn = yypact_[yystate];
    if (yypact_ninf_ < yyn && yyn <= yylast_)
      {
	/* Start YYX at -YYN if negative to avoid negative indexes in
	   YYCHECK.  */
	int yyxbegin = yyn < 0 ? -yyn : 0;

	/* Stay within bounds of both yycheck and yytname.  */
	int yychecklim = yylast_ - yyn + 1;
	int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
	int count = 0;
	for (int x = yyxbegin; x < yyxend; ++x)
	  if (yycheck_[x + yyn] == x && x != yyterror_)
	    ++count;

	// FIXME: This method of building the message is not compatible
	// with internationalization.  It should work like yacc.c does it.
	// That is, first build a string that looks like this:
	// "syntax error, unexpected %s or %s or %s"
	// Then, invoke YY_ on this string.
	// Finally, use the string as a format to output
	// yytname_[tok], etc.
	// Until this gets fixed, this message appears in English only.
	res = "syntax error, unexpected ";
	res += yytnamerr_ (yytname_[tok]);
	if (count < 5)
	  {
	    count = 0;
	    for (int x = yyxbegin; x < yyxend; ++x)
	      if (yycheck_[x + yyn] == x && x != yyterror_)
		{
		  res += (!count++) ? ", expecting " : " or ";
		  res += yytnamerr_ (yytname_[x]);
		}
	  }
      }
    else
#endif
      res = YY_("syntax error");
    return res;
  }


  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
  const signed char Parser::yypact_ninf_ = -66;
  const short int
  Parser::yypact_[] =
  {
         5,    13,    31,    58,   -66,    76,   -66,   -66,   -66,    70,
      28,   -66,    52,   -66,    65,   -66,    71,    18,   -66,    82,
      19,   -66,    86,     9,    87,   -66,   107,    52,   -66,    -7,
     119,   119,    86,   -66,   -66,   131,   -66,   -66,   124,    -1,
      24,   -66,   -66,   -66,   -66,   -66,    21,   -66,    83,   132,
      -3,   135,   136,   144,   138,   140,   -66,    66,   -66,    72,
     -66,   -66,   -66,    62,   142,   149,   143,   205,   126,   205,
     -66,   -66,   -66,   205,   155,   -66,   114,   -66,   -66,    80,
     -66,   -66,   -66,   -66,   -66,   205,   -66,   201,   -66,   205,
     -66,   205,   205,   -66,   -66,   -66,   -66,   -66,   152,   -66,
     -66,   -66,    34,   172,   227,   205,   151,   -66,   -66,   285,
     -66,    88,   302,   245,   317,   -66,   -66,   205,   205,   205,
     205,   205,   205,   205,   205,   205,   205,   205,   205,   205,
     -66,   133,   153,   119,   262,   -66,   -66,   -66,   205,   -66,
     317,   317,   329,   329,   329,   -66,   -66,   -66,   -66,   -66,
     -66,   -66,   -66,   -66,    91,   -66,   302,   -66,   125,   205,
     302,   -66,   133,   119,   111,   -66,   -66,   -66
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  Parser::yydefact_[] =
  {
         0,     0,     0,     0,     1,     0,     8,    14,    13,     0,
       4,     5,     0,     2,     0,     6,     0,     3,    17,    11,
       0,     9,     0,    11,     0,    18,     0,     0,     7,     0,
       0,     0,     0,    16,    15,     0,    10,    22,     0,     0,
       0,    20,    19,    12,    23,    21,     0,    26,    48,     0,
       0,     0,     0,     0,     0,     0,    44,     0,    29,     0,
      34,    38,    39,     0,     0,     0,     0,     0,     0,     0,
      41,    42,    43,     0,     0,    32,     0,    25,    30,     0,
      27,    35,    50,    51,    52,     0,    37,     0,    24,     0,
      84,     0,     0,    86,    87,    88,    79,    78,     0,    81,
      80,    85,     0,     0,     0,     0,     0,    31,    28,     0,
      53,     0,    58,     0,    82,    83,    49,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      55,     0,     0,     0,     0,    33,    36,    54,     0,    64,
      65,    66,    67,    68,    69,    72,    73,    74,    77,    71,
      76,    70,    75,    63,     0,    61,    62,    40,    45,     0,
      59,    56,     0,     0,     0,    60,    46,    47
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Parser::yypgoto_[] =
  {
       -66,   -66,   -66,   -66,   163,   -66,   157,     0,   -66,   -66,
     168,   164,   -66,   -30,   -66,   137,   -66,   146,   -56,   -66,
     -66,   -29,   -66,    43,   -66,   -66,   -66,    33,   -65,   -66,
     -66,   -66
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const short int
  Parser::yydefgoto_[] =
  {
        -1,     2,     9,    10,    11,    20,    21,    55,    35,    17,
      18,    31,    39,    56,    57,    58,    76,    59,    60,    61,
      62,    96,    85,    97,    65,   111,   154,   155,   156,    99,
     100,   101
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char Parser::yytable_ninf_ = -58;
  const short int
  Parser::yytable_[] =
  {
        41,    42,    98,    81,   103,    12,    37,    69,   104,     1,
      16,    63,    45,     7,     8,    70,    46,    24,     3,    26,
     109,    29,   112,    81,   113,    14,   114,   115,    63,    38,
      63,     4,    40,    47,     6,    14,    27,    28,     7,     8,
     134,     7,     8,    48,     7,     8,    66,   130,     7,     8,
      63,   131,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,    49,     5,    50,    51,    52,
      53,    19,    54,   160,    40,    77,    82,    83,    84,    13,
      40,    80,     6,    64,    22,    48,     7,     8,    40,   108,
      23,    48,    26,    67,   164,   -57,     7,     8,    29,    48,
      64,   137,    64,   158,   161,   138,    32,    49,   162,    50,
      51,    52,    53,    49,    54,    50,    51,    52,    53,    40,
      54,    49,    64,    50,    51,    52,    53,    40,    54,    33,
      34,   106,   107,   166,   167,   117,   118,   119,   120,   121,
     122,   123,    43,    44,    68,    89,   124,   125,   126,   127,
     128,   129,    48,    71,    72,    90,    73,    74,    91,    75,
      86,    87,    88,   116,    92,    93,    94,    95,   102,   105,
     135,   157,   163,    15,    49,   153,   117,   118,   119,   120,
     121,   122,   123,   132,    36,    25,    30,   124,   125,   126,
     127,   128,   129,     0,    78,   165,   117,   118,   119,   120,
     121,   122,   123,    79,     0,     0,     0,   124,   125,   126,
     127,   128,   129,    89,   110,     0,     0,    89,     0,     0,
      48,     0,     0,    90,    48,     0,    91,    90,     0,     0,
      91,     0,    92,    93,    94,    95,    92,    93,    94,    95,
     133,     0,    49,     0,     0,     0,    49,     0,     0,     0,
       0,   117,   118,   119,   120,   121,   122,   123,   139,     0,
       0,     0,   124,   125,   126,   127,   128,   129,     0,   117,
     118,   119,   120,   121,   122,   123,     0,     0,     0,   159,
     124,   125,   126,   127,   128,   129,   117,   118,   119,   120,
     121,   122,   123,     0,     0,     0,     0,   124,   125,   126,
     127,   128,   129,   136,     0,     0,     0,     0,     0,   117,
     118,   119,   120,   121,   122,   123,     0,     0,     0,     0,
     124,   125,   126,   127,   128,   129,   117,   118,   119,   120,
     121,   122,   123,     0,     0,     0,     0,   124,   125,   126,
     127,   128,   129,   119,   120,   121,   122,   123,     0,     0,
       0,     0,   124,   125,   126,   127,   128,   129,   122,   123,
       0,     0,     0,     0,   124,   125,   126,   127,   128,   129
  };

  /* YYCHECK.  */
  const short int
  Parser::yycheck_[] =
  {
        30,    31,    67,    59,    69,     5,    13,    10,    73,     4,
      10,    40,    13,    20,    21,    18,    17,    17,     5,    10,
      85,    12,    87,    79,    89,     7,    91,    92,    57,    29,
      59,     0,     8,     9,     6,     7,    17,    18,    20,    21,
     105,    20,    21,    19,    20,    21,    46,    13,    20,    21,
      79,    17,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,    41,     8,    43,    44,    45,
      46,    19,    48,   138,     8,     9,    14,    15,    16,     9,
       8,     9,     6,    40,    19,    19,    20,    21,     8,     9,
      19,    19,    10,    10,   159,    12,    20,    21,    12,    19,
      57,    13,    59,   133,    13,    17,    19,    41,    17,    43,
      44,    45,    46,    41,    48,    43,    44,    45,    46,     8,
      48,    41,    79,    43,    44,    45,    46,     8,    48,    22,
      23,    17,    18,   163,   164,    24,    25,    26,    27,    28,
      29,    30,    11,    19,    12,    12,    35,    36,    37,    38,
      39,    40,    19,    18,    18,    22,    12,    19,    25,    19,
      18,    12,    19,    11,    31,    32,    33,    34,    42,    14,
      19,    18,    47,    10,    41,    42,    24,    25,    26,    27,
      28,    29,    30,    11,    27,    17,    22,    35,    36,    37,
      38,    39,    40,    -1,    57,   162,    24,    25,    26,    27,
      28,    29,    30,    57,    -1,    -1,    -1,    35,    36,    37,
      38,    39,    40,    12,    13,    -1,    -1,    12,    -1,    -1,
      19,    -1,    -1,    22,    19,    -1,    25,    22,    -1,    -1,
      25,    -1,    31,    32,    33,    34,    31,    32,    33,    34,
      13,    -1,    41,    -1,    -1,    -1,    41,    -1,    -1,    -1,
      -1,    24,    25,    26,    27,    28,    29,    30,    13,    -1,
      -1,    -1,    35,    36,    37,    38,    39,    40,    -1,    24,
      25,    26,    27,    28,    29,    30,    -1,    -1,    -1,    17,
      35,    36,    37,    38,    39,    40,    24,    25,    26,    27,
      28,    29,    30,    -1,    -1,    -1,    -1,    35,    36,    37,
      38,    39,    40,    18,    -1,    -1,    -1,    -1,    -1,    24,
      25,    26,    27,    28,    29,    30,    -1,    -1,    -1,    -1,
      35,    36,    37,    38,    39,    40,    24,    25,    26,    27,
      28,    29,    30,    -1,    -1,    -1,    -1,    35,    36,    37,
      38,    39,    40,    26,    27,    28,    29,    30,    -1,    -1,
      -1,    -1,    35,    36,    37,    38,    39,    40,    29,    30,
      -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,    40
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  Parser::yystos_[] =
  {
         0,     4,    50,     5,     0,     8,     6,    20,    21,    51,
      52,    53,    56,     9,     7,    53,    56,    58,    59,    19,
      54,    55,    19,    19,    56,    59,    10,    17,    18,    12,
      60,    60,    19,    22,    23,    57,    55,    13,    56,    61,
       8,    62,    62,    11,    19,    13,    17,     9,    19,    41,
      43,    44,    45,    46,    48,    56,    62,    63,    64,    66,
      67,    68,    69,    70,    72,    73,    56,    10,    12,    10,
      18,    18,    18,    12,    19,    19,    65,     9,    64,    66,
       9,    67,    14,    15,    16,    71,    18,    12,    19,    12,
      22,    25,    31,    32,    33,    34,    70,    72,    77,    78,
      79,    80,    42,    77,    77,    14,    17,    18,     9,    77,
      13,    74,    77,    77,    77,    77,    11,    24,    25,    26,
      27,    28,    29,    30,    35,    36,    37,    38,    39,    40,
      13,    17,    11,    13,    77,    19,    18,    13,    17,    13,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    42,    75,    76,    77,    18,    62,    17,
      77,    13,    17,    47,    77,    76,    62,    62
  };

#if YYDEBUG
  /* TOKEN_NUMBER_[YYLEX-NUM] -- Internal symbol number corresponding
     to YYLEX-NUM.  */
  const unsigned short int
  Parser::yytoken_number_[] =
  {
         0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303
  };
#endif

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
  const unsigned char
  Parser::yyr1_[] =
  {
         0,    49,    50,    51,    51,    52,    52,    53,    53,    54,
      54,    55,    55,    56,    56,    57,    57,    58,    58,    59,
      59,    60,    60,    61,    61,    62,    62,    62,    62,    63,
      63,    64,    65,    65,    66,    66,    67,    67,    67,    67,
      67,    67,    67,    67,    67,    68,    68,    69,    70,    70,
      71,    71,    71,    72,    72,    72,    72,    73,    74,    74,
      75,    75,    76,    76,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    78,    78,    79,    79,    79,    80,    80
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  Parser::yyr2_[] =
  {
         0,     2,     5,     2,     1,     1,     2,     3,     1,     1,
       3,     1,     4,     1,     1,     1,     1,     1,     2,     4,
       4,     3,     2,     2,     4,     3,     2,     3,     4,     1,
       2,     3,     1,     3,     1,     2,     4,     2,     1,     1,
       5,     2,     2,     2,     1,     5,     7,     7,     1,     4,
       1,     1,     1,     3,     4,     4,     6,     1,     1,     3,
       3,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     1,     2,     2,     1,     1,     1,     1,     1
  };

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
  /* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
     First, the terminals, then, starting at \a yyntokens_, nonterminals.  */
  const char*
  const Parser::yytname_[] =
  {
    "END", "error", "$undefined", "EOL", "CLASS", "PROGRAM", "COMMENT",
  "VOID", "L_FLO", "R_FLO", "L_SQ", "R_SQ", "L_P", "R_P", "EQ", "PE", "ME",
  "COMMA", "SEMI", "ID", "BOOLEAN", "INT", "INTEGER_LIT", "HEX_LIT", "ADD",
  "SUB", "MUL", "DIV", "MOD", "LT", "GT", "NOT", "CHAR_LIT", "TRUE",
  "FALSE", "NE", "DO", "GE", "DA", "LE", "DE", "CALLOUT", "STRING_LIT",
  "RETURN", "BREAK", "CONTINUE", "IF", "ELSE", "FOR", "$accept", "line",
  "progs", "field_decl_list", "field_decl", "decl_list", "decl", "type",
  "intlit", "method_decl_list", "method_decl", "method_args_block",
  "type_id_list", "block", "var_dec_list", "var_dec", "id_list",
  "statement_list", "statement", "if_block", "for_block", "location",
  "assign_op", "method_call", "method_name", "expr_list", "callout_args",
  "callout_arg", "expr", "unaryexp", "literal", "bool_lit", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const Parser::rhs_number_type
  Parser::yyrhs_[] =
  {
        50,     0,    -1,     4,     5,     8,    51,     9,    -1,    52,
      58,    -1,    52,    -1,    53,    -1,    52,    53,    -1,    56,
      54,    18,    -1,     6,    -1,    55,    -1,    54,    17,    55,
      -1,    19,    -1,    19,    10,    57,    11,    -1,    21,    -1,
      20,    -1,    23,    -1,    22,    -1,    59,    -1,    58,    59,
      -1,    56,    19,    60,    62,    -1,     7,    19,    60,    62,
      -1,    12,    61,    13,    -1,    12,    13,    -1,    56,    19,
      -1,    61,    17,    56,    19,    -1,     8,    63,     9,    -1,
       8,     9,    -1,     8,    66,     9,    -1,     8,    63,    66,
       9,    -1,    64,    -1,    63,    64,    -1,    56,    65,    18,
      -1,    19,    -1,    65,    17,    19,    -1,    67,    -1,    66,
      67,    -1,    70,    71,    77,    18,    -1,    72,    18,    -1,
      68,    -1,    69,    -1,    43,    10,    77,    11,    18,    -1,
      43,    18,    -1,    44,    18,    -1,    45,    18,    -1,    62,
      -1,    46,    12,    77,    13,    62,    -1,    46,    12,    77,
      13,    62,    47,    62,    -1,    48,    19,    14,    77,    17,
      77,    62,    -1,    19,    -1,    19,    10,    77,    11,    -1,
      14,    -1,    15,    -1,    16,    -1,    73,    12,    13,    -1,
      73,    12,    74,    13,    -1,    41,    12,    42,    13,    -1,
      41,    12,    42,    17,    75,    13,    -1,    19,    -1,    77,
      -1,    74,    17,    77,    -1,    75,    17,    76,    -1,    76,
      -1,    77,    -1,    42,    -1,    12,    77,    13,    -1,    77,
      24,    77,    -1,    77,    25,    77,    -1,    77,    26,    77,
      -1,    77,    27,    77,    -1,    77,    28,    77,    -1,    77,
      39,    77,    -1,    77,    37,    77,    -1,    77,    29,    77,
      -1,    77,    30,    77,    -1,    77,    35,    77,    -1,    77,
      40,    77,    -1,    77,    38,    77,    -1,    77,    36,    77,
      -1,    72,    -1,    70,    -1,    79,    -1,    78,    -1,    25,
      77,    -1,    31,    77,    -1,    22,    -1,    80,    -1,    32,
      -1,    33,    -1,    34,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  Parser::yyprhs_[] =
  {
         0,     0,     3,     9,    12,    14,    16,    19,    23,    25,
      27,    31,    33,    38,    40,    42,    44,    46,    48,    51,
      56,    61,    65,    68,    71,    76,    80,    83,    87,    92,
      94,    97,   101,   103,   107,   109,   112,   117,   120,   122,
     124,   130,   133,   136,   139,   141,   147,   155,   163,   165,
     170,   172,   174,   176,   180,   185,   190,   197,   199,   201,
     205,   209,   211,   213,   215,   219,   223,   227,   231,   235,
     239,   243,   247,   251,   255,   259,   263,   267,   271,   273,
     275,   277,   279,   282,   285,   287,   289,   291,   293
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned char
  Parser::yyrline_[] =
  {
         0,   135,   135,   137,   137,   139,   139,   141,   141,   143,
     143,   145,   145,   147,   147,   149,   149,   151,   151,   153,
     153,   155,   155,   157,   157,   159,   159,   159,   159,   161,
     161,   163,   165,   165,   167,   167,   169,   169,   169,   169,
     169,   169,   169,   169,   169,   171,   171,   173,   175,   175,
     177,   177,   177,   179,   179,   179,   179,   181,   183,   183,
     185,   185,   187,   187,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   210,   210,   212,   212,   212,   214,   214
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (state_stack_type::const_iterator i = yystate_stack_.begin ();
	 i != yystate_stack_.end (); ++i)
      *yycdebug_ << ' ' << *i;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    /* Print the symbols being reduced, and their result.  */
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
	       << " (line " << yylno << "), ";
    /* The symbols being reduced.  */
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
		       yyrhs_[yyprhs_[yyrule] + yyi],
		       &(yysemantic_stack_[(yynrhs) - (yyi + 1)]),
		       &(yylocation_stack_[(yynrhs) - (yyi + 1)]));
  }
#endif // YYDEBUG

  /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
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
    if ((unsigned int) t <= yyuser_token_number_max_)
      return translate_table[t];
    else
      return yyundef_token_;
  }

  const int Parser::yyeof_ = 0;
  const int Parser::yylast_ = 369;
  const int Parser::yynnts_ = 32;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 4;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 49;

  const unsigned int Parser::yyuser_token_number_max_ = 303;
  const Parser::token_number_type Parser::yyundef_token_ = 2;

} // namespace decaf

#line 217 "calc.yy"


void decaf::Parser::error(const Parser::location_type& l,
			    const std::string& m)
{
    driver.error(l, m);
}


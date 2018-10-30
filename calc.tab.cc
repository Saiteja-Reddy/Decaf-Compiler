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
#line 96 "calc.yy"


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
#line 199 "calc.yy"
    { (yyval.astnode) = new ProgramASTnode("Program Decl", (yysemantic_stack_[(5) - (4)].fields), new meth_decs() ); driver.ast.root = (yyval.astnode);;}
    break;

  case 3:
#line 200 "calc.yy"
    { (yyval.astnode) = new ProgramASTnode("Program Decl", (yysemantic_stack_[(6) - (4)].fields), (yysemantic_stack_[(6) - (5)].meth_decs_type)); driver.ast.root = (yyval.astnode);;}
    break;

  case 4:
#line 201 "calc.yy"
    { (yyval.astnode) = new ProgramASTnode("Program"); driver.ast.root = (yyval.astnode);;}
    break;

  case 5:
#line 202 "calc.yy"
    { (yyval.astnode) = new ProgramASTnode("Program", new FieldDecList() , (yysemantic_stack_[(5) - (4)].meth_decs_type)); driver.ast.root = (yyval.astnode);;}
    break;

  case 6:
#line 204 "calc.yy"
    { (yyval.fields) = new FieldDecList(); 					(yyval.fields)->push_back((yysemantic_stack_[(1) - (1)].field));}
    break;

  case 7:
#line 205 "calc.yy"
    {(yyval.fields)->push_back((yysemantic_stack_[(2) - (2)].field));;}
    break;

  case 8:
#line 207 "calc.yy"
    {(yyval.field) = new FieldDec(std::string((yysemantic_stack_[(3) - (1)].value)), (yysemantic_stack_[(3) - (2)].var_decls));;}
    break;

  case 9:
#line 209 "calc.yy"
    {(yyval.var_decls) = new Variables(); (yyval.var_decls)->push_back((yysemantic_stack_[(1) - (1)].var_decl));;}
    break;

  case 10:
#line 210 "calc.yy"
    {(yyval.var_decls)->push_back((yysemantic_stack_[(3) - (3)].var_decl));;}
    break;

  case 11:
#line 212 "calc.yy"
    { (yyval.var_decl) = new Variable(string((yysemantic_stack_[(1) - (1)].value)));;}
    break;

  case 12:
#line 213 "calc.yy"
    {(yyval.var_decl) = new Variable(string((yysemantic_stack_[(4) - (1)].value)),(yysemantic_stack_[(4) - (3)].intliteral)->getValue());;}
    break;

  case 15:
#line 217 "calc.yy"
    {(yyval.intliteral) = (yysemantic_stack_[(1) - (1)].intliteral);;}
    break;

  case 16:
#line 218 "calc.yy"
    {(yyval.intliteral) = (yysemantic_stack_[(1) - (1)].intliteral);;}
    break;

  case 17:
#line 221 "calc.yy"
    { (yyval.meth_decs_type) = new meth_decs(); 					(yyval.meth_decs_type)->push_back((yysemantic_stack_[(1) - (1)].meth_dec_type));}
    break;

  case 18:
#line 222 "calc.yy"
    {(yyval.meth_decs_type)->push_back((yysemantic_stack_[(2) - (2)].meth_dec_type));;}
    break;

  case 19:
#line 224 "calc.yy"
    {(yyval.meth_dec_type) = new meth_dec(std::string((yysemantic_stack_[(4) - (1)].value)), (yysemantic_stack_[(4) - (2)].value),(yysemantic_stack_[(4) - (3)].meth_args_type), (yysemantic_stack_[(4) - (4)].block_type));;}
    break;

  case 20:
#line 225 "calc.yy"
    {(yyval.meth_dec_type) = new meth_dec(std::string((yysemantic_stack_[(4) - (1)].value)), (yysemantic_stack_[(4) - (2)].value),(yysemantic_stack_[(4) - (3)].meth_args_type), (yysemantic_stack_[(4) - (4)].block_type));;}
    break;

  case 21:
#line 227 "calc.yy"
    {(yyval.meth_args_type) = (yysemantic_stack_[(3) - (2)].meth_args_type);}
    break;

  case 22:
#line 228 "calc.yy"
    {(yyval.meth_args_type) = new meth_args();;}
    break;

  case 23:
#line 230 "calc.yy"
    {(yyval.meth_args_type) = new meth_args();(yyval.meth_args_type)->push_back(new meth_arg(string((yysemantic_stack_[(2) - (1)].value)), string((yysemantic_stack_[(2) - (2)].value))));;}
    break;

  case 24:
#line 231 "calc.yy"
    {(yyval.meth_args_type)->push_back(new meth_arg(string((yysemantic_stack_[(4) - (3)].value)), string((yysemantic_stack_[(4) - (4)].value))));;}
    break;

  case 25:
#line 233 "calc.yy"
    {(yyval.block_type) = new Block(new var_decs(), new Statements());;}
    break;

  case 26:
#line 234 "calc.yy"
    {(yyval.block_type) = new Block((yysemantic_stack_[(3) - (2)].var_decs_type), new Statements());;}
    break;

  case 27:
#line 235 "calc.yy"
    {(yyval.block_type) = new Block((yysemantic_stack_[(4) - (2)].var_decs_type),(yysemantic_stack_[(4) - (3)].statements_type));;}
    break;

  case 28:
#line 236 "calc.yy"
    {(yyval.block_type) = new Block(new var_decs(),(yysemantic_stack_[(3) - (2)].statements_type));;}
    break;

  case 29:
#line 239 "calc.yy"
    {(yyval.statements_type) = new Statements(); (yyval.statements_type)->push_back((yysemantic_stack_[(1) - (1)].statement_type));;}
    break;

  case 30:
#line 240 "calc.yy"
    {(yyval.statements_type)->push_back((yysemantic_stack_[(2) - (2)].statement_type));;}
    break;

  case 31:
#line 242 "calc.yy"
    {(yyval.statement_type) = (yysemantic_stack_[(2) - (1)].meth_call_type);;}
    break;

  case 32:
#line 243 "calc.yy"
    {(yyval.statement_type) = new breakState();;}
    break;

  case 33:
#line 244 "calc.yy"
    {(yyval.statement_type) = new continueState();;}
    break;

  case 34:
#line 245 "calc.yy"
    {(yyval.statement_type) = (yysemantic_stack_[(1) - (1)].if_block_type);;}
    break;

  case 35:
#line 246 "calc.yy"
    {(yyval.statement_type) = (yysemantic_stack_[(1) - (1)].for_block_type);;}
    break;

  case 36:
#line 247 "calc.yy"
    {(yyval.statement_type) = new returnState((yysemantic_stack_[(5) - (3)].expr_type));;}
    break;

  case 37:
#line 248 "calc.yy"
    {(yyval.statement_type) = new returnState();;}
    break;

  case 38:
#line 249 "calc.yy"
    {(yyval.statement_type) = new Assign((yysemantic_stack_[(4) - (1)].location_type), (yysemantic_stack_[(4) - (2)].value), (yysemantic_stack_[(4) - (3)].expr_type));}
    break;

  case 39:
#line 251 "calc.yy"
    {(yyval.value) = (yysemantic_stack_[(1) - (1)].value);}
    break;

  case 40:
#line 252 "calc.yy"
    {(yyval.value) = (yysemantic_stack_[(1) - (1)].value);}
    break;

  case 41:
#line 253 "calc.yy"
    {(yyval.value) = (yysemantic_stack_[(1) - (1)].value);}
    break;

  case 42:
#line 255 "calc.yy"
    {(yyval.for_block_type) = new forState((yysemantic_stack_[(7) - (2)].value), (yysemantic_stack_[(7) - (4)].expr_type), (yysemantic_stack_[(7) - (6)].expr_type), (yysemantic_stack_[(7) - (7)].block_type)); ;}
    break;

  case 43:
#line 257 "calc.yy"
    {(yyval.if_block_type) = new ifElseState((yysemantic_stack_[(5) - (3)].expr_type), (yysemantic_stack_[(5) - (5)].block_type), new Block());;}
    break;

  case 44:
#line 258 "calc.yy"
    {(yyval.if_block_type) = new ifElseState((yysemantic_stack_[(7) - (3)].expr_type), (yysemantic_stack_[(7) - (5)].block_type), (yysemantic_stack_[(7) - (7)].block_type));;}
    break;

  case 45:
#line 261 "calc.yy"
    {(yyval.meth_call_type) = new meth_call(string((yysemantic_stack_[(3) - (1)].value)), new Parameters());;}
    break;

  case 46:
#line 262 "calc.yy"
    {(yyval.meth_call_type) = new meth_call(string((yysemantic_stack_[(4) - (1)].value)), (yysemantic_stack_[(4) - (3)].parameters_type));;}
    break;

  case 47:
#line 263 "calc.yy"
    {(yyval.meth_call_type) = new callout_call((yysemantic_stack_[(4) - (3)].callout_args_type));;}
    break;

  case 48:
#line 265 "calc.yy"
    {(yyval.callout_args_type)->push_back((yysemantic_stack_[(3) - (3)].callout_arg_type));;}
    break;

  case 49:
#line 266 "calc.yy"
    {(yyval.callout_args_type) = new calloutArgs(); (yyval.callout_args_type)->push_back((yysemantic_stack_[(1) - (1)].callout_arg_type));;}
    break;

  case 50:
#line 268 "calc.yy"
    {(yyval.callout_arg_type) = new calloutArg((yysemantic_stack_[(1) - (1)].expr_type));;}
    break;

  case 51:
#line 269 "calc.yy"
    {(yyval.callout_arg_type) = new calloutArg((yysemantic_stack_[(1) - (1)].stringliteral));;}
    break;

  case 52:
#line 271 "calc.yy"
    {(yyval.value) = (yysemantic_stack_[(1) - (1)].value);}
    break;

  case 53:
#line 273 "calc.yy"
    {(yyval.parameters_type) = new Parameters(); (yyval.parameters_type)->push_back((yysemantic_stack_[(1) - (1)].expr_type));;}
    break;

  case 54:
#line 274 "calc.yy"
    {(yyval.parameters_type)->push_back((yysemantic_stack_[(3) - (3)].expr_type));;}
    break;

  case 55:
#line 276 "calc.yy"
    {(yyval.expr_type) = new EncExpr((yysemantic_stack_[(3) - (2)].expr_type));;}
    break;

  case 56:
#line 277 "calc.yy"
    {(yyval.expr_type) = new BinExpr((yysemantic_stack_[(3) - (1)].expr_type), (yysemantic_stack_[(3) - (3)].expr_type), string((yysemantic_stack_[(3) - (2)].value)));;}
    break;

  case 57:
#line 278 "calc.yy"
    {(yyval.expr_type) = new BinExpr((yysemantic_stack_[(3) - (1)].expr_type), (yysemantic_stack_[(3) - (3)].expr_type), string((yysemantic_stack_[(3) - (2)].value)));;}
    break;

  case 58:
#line 279 "calc.yy"
    {(yyval.expr_type) = new BinExpr((yysemantic_stack_[(3) - (1)].expr_type), (yysemantic_stack_[(3) - (3)].expr_type), string((yysemantic_stack_[(3) - (2)].value)));;}
    break;

  case 59:
#line 280 "calc.yy"
    {(yyval.expr_type) = new BinExpr((yysemantic_stack_[(3) - (1)].expr_type), (yysemantic_stack_[(3) - (3)].expr_type), string((yysemantic_stack_[(3) - (2)].value)));;}
    break;

  case 60:
#line 281 "calc.yy"
    {(yyval.expr_type) = new BinExpr((yysemantic_stack_[(3) - (1)].expr_type), (yysemantic_stack_[(3) - (3)].expr_type), string((yysemantic_stack_[(3) - (2)].value)));;}
    break;

  case 61:
#line 282 "calc.yy"
    {(yyval.expr_type) = new BinExpr((yysemantic_stack_[(3) - (1)].expr_type), (yysemantic_stack_[(3) - (3)].expr_type), string((yysemantic_stack_[(3) - (2)].value)));;}
    break;

  case 62:
#line 283 "calc.yy"
    {(yyval.expr_type) = new BinExpr((yysemantic_stack_[(3) - (1)].expr_type), (yysemantic_stack_[(3) - (3)].expr_type), string((yysemantic_stack_[(3) - (2)].value)));;}
    break;

  case 63:
#line 284 "calc.yy"
    {(yyval.expr_type) = new BinExpr((yysemantic_stack_[(3) - (1)].expr_type), (yysemantic_stack_[(3) - (3)].expr_type), string((yysemantic_stack_[(3) - (2)].value)));;}
    break;

  case 64:
#line 285 "calc.yy"
    {(yyval.expr_type) = new BinExpr((yysemantic_stack_[(3) - (1)].expr_type), (yysemantic_stack_[(3) - (3)].expr_type), string((yysemantic_stack_[(3) - (2)].value)));;}
    break;

  case 65:
#line 286 "calc.yy"
    {(yyval.expr_type) = new BinExpr((yysemantic_stack_[(3) - (1)].expr_type), (yysemantic_stack_[(3) - (3)].expr_type), string((yysemantic_stack_[(3) - (2)].value)));;}
    break;

  case 66:
#line 287 "calc.yy"
    {(yyval.expr_type) = new BinExpr((yysemantic_stack_[(3) - (1)].expr_type), (yysemantic_stack_[(3) - (3)].expr_type), string((yysemantic_stack_[(3) - (2)].value)));;}
    break;

  case 67:
#line 288 "calc.yy"
    {(yyval.expr_type) = new BinExpr((yysemantic_stack_[(3) - (1)].expr_type), (yysemantic_stack_[(3) - (3)].expr_type), string((yysemantic_stack_[(3) - (2)].value)));;}
    break;

  case 68:
#line 289 "calc.yy"
    {(yyval.expr_type) = new BinExpr((yysemantic_stack_[(3) - (1)].expr_type), (yysemantic_stack_[(3) - (3)].expr_type), string((yysemantic_stack_[(3) - (2)].value)));;}
    break;

  case 69:
#line 290 "calc.yy"
    {(yyval.expr_type) = (yysemantic_stack_[(1) - (1)].meth_call_type);;}
    break;

  case 70:
#line 291 "calc.yy"
    {(yyval.expr_type) = (yysemantic_stack_[(1) - (1)].literal_type);;}
    break;

  case 71:
#line 292 "calc.yy"
    {(yyval.expr_type) = (yysemantic_stack_[(1) - (1)].location_type);;}
    break;

  case 72:
#line 294 "calc.yy"
    {(yyval.location_type) = new Location((yysemantic_stack_[(1) - (1)].value));;}
    break;

  case 73:
#line 295 "calc.yy"
    {(yyval.location_type) = new Location((yysemantic_stack_[(4) - (1)].value), (yysemantic_stack_[(4) - (3)].expr_type));;}
    break;

  case 74:
#line 298 "calc.yy"
    {(yyval.literal_type) = (yysemantic_stack_[(1) - (1)].intliteral);;}
    break;

  case 75:
#line 299 "calc.yy"
    {(yyval.literal_type) = (yysemantic_stack_[(1) - (1)].boolliteral);;}
    break;

  case 76:
#line 300 "calc.yy"
    {(yyval.literal_type) = (yysemantic_stack_[(1) - (1)].charliteral);;}
    break;

  case 77:
#line 302 "calc.yy"
    {(yyval.boolliteral)=(yysemantic_stack_[(1) - (1)].boolliteral);;}
    break;

  case 78:
#line 303 "calc.yy"
    {(yyval.boolliteral)=(yysemantic_stack_[(1) - (1)].boolliteral);;}
    break;

  case 79:
#line 305 "calc.yy"
    {(yyval.var_decs_type) = new var_decs(); (yyval.var_decs_type)->push_back((yysemantic_stack_[(1) - (1)].var_dec_type));;}
    break;

  case 80:
#line 306 "calc.yy"
    {(yyval.var_decs_type)->push_back((yysemantic_stack_[(2) - (2)].var_dec_type));;}
    break;

  case 81:
#line 308 "calc.yy"
    {(yyval.var_dec_type) = new var_dec(string((yysemantic_stack_[(3) - (1)].value)), (yysemantic_stack_[(3) - (2)].string_list_type));;}
    break;

  case 82:
#line 310 "calc.yy"
    {(yyval.string_list_type) = new string_list(); (yyval.string_list_type)->push_back(string((yysemantic_stack_[(1) - (1)].value)));;}
    break;

  case 83:
#line 311 "calc.yy"
    {(yyval.string_list_type)->push_back(string((yysemantic_stack_[(3) - (3)].value)));;}
    break;


    /* Line 675 of lalr1.cc.  */
#line 811 "calc.tab.cc"
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
  const signed char Parser::yypact_ninf_ = -67;
  const short int
  Parser::yypact_[] =
  {
        16,    20,    34,    23,   -67,     1,    49,   -67,   -67,   -67,
      21,   -67,    62,    58,   -67,    26,   -67,   -67,   115,    75,
     -12,   -67,   -67,    67,   -67,     6,    81,   -67,    24,    81,
      86,   -67,    26,   -67,    94,    -2,    55,   -67,   -67,   -67,
      83,   -67,   111,   -67,   -67,   -67,    50,   -67,    85,   106,
      19,   105,   112,   117,   113,   114,    71,   -67,   -67,   -67,
     119,   127,    77,    63,   -67,   -67,   121,   220,   148,   220,
     -67,   -67,   -67,   220,   124,   -67,   108,   -67,   -67,   -67,
     216,   -67,   -67,   -67,   220,   -67,   101,   -67,   -67,   220,
     -67,   -67,   -67,   -67,   -67,   167,   -67,   -67,   -67,   -67,
      31,   -67,   313,   187,   238,   220,   122,   -67,   -67,    60,
     313,   296,   -67,   256,   -67,   220,   220,   220,   220,   220,
     220,   220,   220,   220,   220,   220,   220,   220,   -67,   148,
     125,    81,   273,   -67,   -67,   220,   -67,   -67,   328,   328,
     340,   340,   340,   -67,   -67,   -67,   -67,   -67,   -67,   -67,
     -67,   -67,   -67,    84,   220,   313,    81,   126,   -67,   -67
  };

  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
     doesn't specify something else to do.  Zero means the default is an
     error.  */
  const unsigned char
  Parser::yydefact_[] =
  {
         0,     0,     0,     0,     1,     0,     0,     4,    14,    13,
       0,     6,     0,     0,    17,     0,     2,     7,     0,    11,
       0,     9,     5,     0,    18,     0,     0,     3,     0,     0,
       0,     8,     0,    22,     0,     0,     0,    20,    16,    15,
       0,    19,    11,    10,    23,    21,     0,    25,    72,     0,
       0,     0,     0,     0,     0,     0,     0,    29,    35,    34,
       0,     0,     0,     0,    79,    12,     0,     0,     0,     0,
      37,    32,    33,     0,     0,    82,     0,    28,    30,    31,
       0,    39,    40,    41,     0,    26,     0,    80,    24,     0,
      74,    76,    77,    78,    69,     0,    71,    70,    75,    51,
       0,    49,    50,     0,     0,     0,     0,    81,    45,     0,
      53,     0,    27,     0,    73,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    47,     0,
       0,     0,     0,    83,    46,     0,    38,    55,    56,    57,
      58,    59,    60,    63,    64,    65,    68,    62,    67,    61,
      66,    48,    36,    43,     0,    54,     0,     0,    44,    42
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Parser::yypgoto_[] =
  {
       -67,   -67,   -67,   138,   -67,   128,    -1,   -67,   147,    -9,
     144,   -67,   -29,   109,   -54,   -67,   -67,   -67,   -23,   -67,
      39,   -67,   -67,   -66,   -20,   -67,   -67,   -67,   110,   -67
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const signed char
  Parser::yydefgoto_[] =
  {
        -1,     2,    10,    11,    20,    21,    12,    40,    13,    14,
      29,    35,    37,    56,    57,    84,    58,    59,    94,   100,
     101,    61,   109,   102,    96,    97,    98,    63,    64,    76
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char Parser::yytable_ninf_ = -53;
  const short int
  Parser::yytable_[] =
  {
        41,    95,    78,   103,    24,    30,    31,   104,     6,    24,
       7,    45,    23,    60,   110,    46,    62,    23,   111,    33,
       1,     8,     9,   113,    34,     3,     8,     9,     6,    69,
      16,     5,    78,    60,     4,    55,    62,    70,    25,   132,
      60,     8,     9,    62,   128,    66,    38,    39,   129,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,    55,    60,    47,     6,    62,    22,    15,   155,
       8,     9,    85,   134,    48,     8,     9,   135,     8,     9,
      77,    19,    48,     8,     9,    28,    32,    25,   157,    36,
      48,    81,    82,    83,    65,    67,    49,   -52,    50,    51,
      52,    53,   153,    54,    49,    42,    50,    51,    52,    53,
     112,    54,    49,    44,    50,    51,    52,    53,    68,    54,
      48,    28,     6,    71,    27,   106,   107,   158,   159,    73,
      72,   156,    74,    75,    36,     8,     9,    79,   105,    80,
      88,   133,    49,   152,    50,    51,    52,    53,    17,    54,
     115,   116,   117,   118,   119,   120,   121,    18,    43,    26,
      89,   122,   123,   124,   125,   126,   127,    48,   151,     0,
      90,     0,    86,    87,     0,     0,     0,     0,   114,     0,
      91,    92,    93,     0,     0,     0,     0,     0,     0,    49,
      99,   115,   116,   117,   118,   119,   120,   121,   130,     0,
       0,     0,   122,   123,   124,   125,   126,   127,     0,     0,
       0,   115,   116,   117,   118,   119,   120,   121,     0,     0,
       0,     0,   122,   123,   124,   125,   126,   127,    89,   108,
       0,     0,    89,     0,     0,    48,     0,     0,    90,    48,
       0,     0,    90,     0,     0,     0,     0,     0,    91,    92,
      93,   131,    91,    92,    93,     0,     0,    49,     0,     0,
       0,    49,   115,   116,   117,   118,   119,   120,   121,   137,
       0,     0,     0,   122,   123,   124,   125,   126,   127,     0,
     115,   116,   117,   118,   119,   120,   121,     0,     0,     0,
     154,   122,   123,   124,   125,   126,   127,   115,   116,   117,
     118,   119,   120,   121,     0,     0,     0,     0,   122,   123,
     124,   125,   126,   127,   136,     0,     0,     0,     0,     0,
     115,   116,   117,   118,   119,   120,   121,     0,     0,     0,
       0,   122,   123,   124,   125,   126,   127,   115,   116,   117,
     118,   119,   120,   121,     0,     0,     0,     0,   122,   123,
     124,   125,   126,   127,   117,   118,   119,   120,   121,     0,
       0,     0,     0,   122,   123,   124,   125,   126,   127,   120,
     121,     0,     0,     0,     0,   122,   123,   124,   125,   126,
     127
  };

  /* YYCHECK.  */
  const short int
  Parser::yycheck_[] =
  {
        29,    67,    56,    69,    13,    17,    18,    73,     7,    18,
       9,    13,    13,    36,    80,    17,    36,    18,    84,    13,
       4,    20,    21,    89,    25,     5,    20,    21,     7,    10,
       9,     8,    86,    56,     0,    36,    56,    18,    12,   105,
      63,    20,    21,    63,    13,    46,    22,    23,    17,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,    63,    86,     9,     7,    86,     9,    19,   135,
      20,    21,     9,    13,    19,    20,    21,    17,    20,    21,
       9,    19,    19,    20,    21,    10,    19,    12,   154,     8,
      19,    14,    15,    16,    11,    10,    41,    12,    43,    44,
      45,    46,   131,    48,    41,    19,    43,    44,    45,    46,
       9,    48,    41,    19,    43,    44,    45,    46,    12,    48,
      19,    10,     7,    18,     9,    17,    18,   156,   157,    12,
      18,    47,    19,    19,     8,    20,    21,    18,    14,    12,
      19,    19,    41,    18,    43,    44,    45,    46,    10,    48,
      24,    25,    26,    27,    28,    29,    30,    10,    30,    15,
      12,    35,    36,    37,    38,    39,    40,    19,   129,    -1,
      22,    -1,    63,    63,    -1,    -1,    -1,    -1,    11,    -1,
      32,    33,    34,    -1,    -1,    -1,    -1,    -1,    -1,    41,
      42,    24,    25,    26,    27,    28,    29,    30,    11,    -1,
      -1,    -1,    35,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    24,    25,    26,    27,    28,    29,    30,    -1,    -1,
      -1,    -1,    35,    36,    37,    38,    39,    40,    12,    13,
      -1,    -1,    12,    -1,    -1,    19,    -1,    -1,    22,    19,
      -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    32,    33,
      34,    13,    32,    33,    34,    -1,    -1,    41,    -1,    -1,
      -1,    41,    24,    25,    26,    27,    28,    29,    30,    13,
      -1,    -1,    -1,    35,    36,    37,    38,    39,    40,    -1,
      24,    25,    26,    27,    28,    29,    30,    -1,    -1,    -1,
      17,    35,    36,    37,    38,    39,    40,    24,    25,    26,
      27,    28,    29,    30,    -1,    -1,    -1,    -1,    35,    36,
      37,    38,    39,    40,    18,    -1,    -1,    -1,    -1,    -1,
      24,    25,    26,    27,    28,    29,    30,    -1,    -1,    -1,
      -1,    35,    36,    37,    38,    39,    40,    24,    25,    26,
      27,    28,    29,    30,    -1,    -1,    -1,    -1,    35,    36,
      37,    38,    39,    40,    26,    27,    28,    29,    30,    -1,
      -1,    -1,    -1,    35,    36,    37,    38,    39,    40,    29,
      30,    -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,
      40
  };

  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
  const unsigned char
  Parser::yystos_[] =
  {
         0,     4,    50,     5,     0,     8,     7,     9,    20,    21,
      51,    52,    55,    57,    58,    19,     9,    52,    57,    19,
      53,    54,     9,    55,    58,    12,    59,     9,    10,    59,
      17,    18,    19,    13,    55,    60,     8,    61,    22,    23,
      56,    61,    19,    54,    19,    13,    17,     9,    19,    41,
      43,    44,    45,    46,    48,    55,    62,    63,    65,    66,
      67,    70,    73,    76,    77,    11,    55,    10,    12,    10,
      18,    18,    18,    12,    19,    19,    78,     9,    63,    18,
      12,    14,    15,    16,    64,     9,    62,    77,    19,    12,
      22,    32,    33,    34,    67,    72,    73,    74,    75,    42,
      68,    69,    72,    72,    72,    14,    17,    18,    13,    71,
      72,    72,     9,    72,    11,    24,    25,    26,    27,    28,
      29,    30,    35,    36,    37,    38,    39,    40,    13,    17,
      11,    13,    72,    19,    13,    17,    18,    13,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    69,    18,    61,    17,    72,    47,    72,    61,    61
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
         0,    49,    50,    50,    50,    50,    51,    51,    52,    53,
      53,    54,    54,    55,    55,    56,    56,    57,    57,    58,
      58,    59,    59,    60,    60,    61,    61,    61,    61,    62,
      62,    63,    63,    63,    63,    63,    63,    63,    63,    64,
      64,    64,    65,    66,    66,    67,    67,    67,    68,    68,
      69,    69,    70,    71,    71,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    73,    73,    74,    74,    74,    75,    75,    76,
      76,    77,    78,    78
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  Parser::yyr2_[] =
  {
         0,     2,     5,     6,     4,     5,     1,     2,     3,     1,
       3,     1,     4,     1,     1,     1,     1,     1,     2,     4,
       4,     3,     2,     2,     4,     2,     3,     4,     3,     1,
       2,     2,     2,     2,     1,     1,     5,     2,     4,     1,
       1,     1,     7,     5,     7,     3,     4,     4,     3,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     1,     1,     4,     1,     1,     1,     1,     1,     1,
       2,     3,     1,     3
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
  "field_decl_list", "field_decl", "decl_list", "decl", "type", "intlit",
  "method_decl_list", "method_decl", "method_args_block", "type_id_list",
  "block", "statement_list", "statement", "assign_op", "for_block",
  "if_block", "method_call", "callout_args", "callout_arg", "method_name",
  "expr_list", "expr", "location", "literal", "bool_lit", "var_dec_list",
  "var_dec", "id_list", 0
  };
#endif

#if YYDEBUG
  /* YYRHS -- A `-1'-separated list of the rules' RHS.  */
  const Parser::rhs_number_type
  Parser::yyrhs_[] =
  {
        50,     0,    -1,     4,     5,     8,    51,     9,    -1,     4,
       5,     8,    51,    57,     9,    -1,     4,     5,     8,     9,
      -1,     4,     5,     8,    57,     9,    -1,    52,    -1,    51,
      52,    -1,    55,    53,    18,    -1,    54,    -1,    53,    17,
      54,    -1,    19,    -1,    19,    10,    56,    11,    -1,    21,
      -1,    20,    -1,    23,    -1,    22,    -1,    58,    -1,    57,
      58,    -1,    55,    19,    59,    61,    -1,     7,    19,    59,
      61,    -1,    12,    60,    13,    -1,    12,    13,    -1,    55,
      19,    -1,    60,    17,    55,    19,    -1,     8,     9,    -1,
       8,    76,     9,    -1,     8,    76,    62,     9,    -1,     8,
      62,     9,    -1,    63,    -1,    62,    63,    -1,    67,    18,
      -1,    44,    18,    -1,    45,    18,    -1,    66,    -1,    65,
      -1,    43,    10,    72,    11,    18,    -1,    43,    18,    -1,
      73,    64,    72,    18,    -1,    14,    -1,    15,    -1,    16,
      -1,    48,    19,    14,    72,    17,    72,    61,    -1,    46,
      12,    72,    13,    61,    -1,    46,    12,    72,    13,    61,
      47,    61,    -1,    70,    12,    13,    -1,    70,    12,    71,
      13,    -1,    41,    12,    68,    13,    -1,    68,    17,    69,
      -1,    69,    -1,    72,    -1,    42,    -1,    19,    -1,    72,
      -1,    71,    17,    72,    -1,    12,    72,    13,    -1,    72,
      24,    72,    -1,    72,    25,    72,    -1,    72,    26,    72,
      -1,    72,    27,    72,    -1,    72,    28,    72,    -1,    72,
      39,    72,    -1,    72,    37,    72,    -1,    72,    29,    72,
      -1,    72,    30,    72,    -1,    72,    35,    72,    -1,    72,
      40,    72,    -1,    72,    38,    72,    -1,    72,    36,    72,
      -1,    67,    -1,    74,    -1,    73,    -1,    19,    -1,    19,
      10,    72,    11,    -1,    22,    -1,    75,    -1,    32,    -1,
      33,    -1,    34,    -1,    77,    -1,    76,    77,    -1,    55,
      78,    18,    -1,    19,    -1,    78,    17,    19,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned short int
  Parser::yyprhs_[] =
  {
         0,     0,     3,     9,    16,    21,    27,    29,    32,    36,
      38,    42,    44,    49,    51,    53,    55,    57,    59,    62,
      67,    72,    76,    79,    82,    87,    90,    94,    99,   103,
     105,   108,   111,   114,   117,   119,   121,   127,   130,   135,
     137,   139,   141,   149,   155,   163,   167,   172,   177,   181,
     183,   185,   187,   189,   191,   195,   199,   203,   207,   211,
     215,   219,   223,   227,   231,   235,   239,   243,   247,   251,
     253,   255,   257,   259,   264,   266,   268,   270,   272,   274,
     276,   279,   283,   285
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Parser::yyrline_[] =
  {
         0,   199,   199,   200,   201,   202,   204,   205,   207,   209,
     210,   212,   213,   215,   215,   217,   218,   221,   222,   224,
     225,   227,   228,   230,   231,   233,   234,   235,   236,   239,
     240,   242,   243,   244,   245,   246,   247,   248,   249,   251,
     252,   253,   255,   257,   258,   261,   262,   263,   265,   266,
     268,   269,   271,   273,   274,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,   286,   287,   288,   289,   290,
     291,   292,   294,   295,   298,   299,   300,   302,   303,   305,
     306,   308,   310,   311
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
  const int Parser::yylast_ = 380;
  const int Parser::yynnts_ = 30;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 4;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 49;

  const unsigned int Parser::yyuser_token_number_max_ = 303;
  const Parser::token_number_type Parser::yyundef_token_ = 2;

} // namespace decaf

#line 315 "calc.yy"


void decaf::Parser::error(const Parser::location_type& l,
			    const std::string& m)
{
    driver.error(l, m);
}


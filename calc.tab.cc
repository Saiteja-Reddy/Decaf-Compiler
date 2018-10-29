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
#line 89 "calc.yy"


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
#line 187 "calc.yy"
    { (yyval.astnode) = new ProgramASTnode("Program Decl", (yysemantic_stack_[(5) - (4)].fields), new meth_decs() ); driver.ast.root = (yyval.astnode);;}
    break;

  case 3:
#line 188 "calc.yy"
    { (yyval.astnode) = new ProgramASTnode("Program Decl", (yysemantic_stack_[(6) - (4)].fields), (yysemantic_stack_[(6) - (5)].meth_decs_type)); driver.ast.root = (yyval.astnode);;}
    break;

  case 4:
#line 189 "calc.yy"
    { (yyval.astnode) = new ProgramASTnode("Program"); driver.ast.root = (yyval.astnode);;}
    break;

  case 5:
#line 190 "calc.yy"
    { (yyval.astnode) = new ProgramASTnode("Program", new FieldDecList() , (yysemantic_stack_[(5) - (4)].meth_decs_type)); driver.ast.root = (yyval.astnode);;}
    break;

  case 6:
#line 192 "calc.yy"
    { (yyval.fields) = new FieldDecList(); 					(yyval.fields)->push_back((yysemantic_stack_[(1) - (1)].field));}
    break;

  case 7:
#line 193 "calc.yy"
    {(yyval.fields)->push_back((yysemantic_stack_[(2) - (2)].field));;}
    break;

  case 8:
#line 195 "calc.yy"
    {(yyval.field) = new FieldDec(std::string((yysemantic_stack_[(3) - (1)].value)), (yysemantic_stack_[(3) - (2)].var_decls));;}
    break;

  case 9:
#line 197 "calc.yy"
    {(yyval.var_decls) = new Variables(); (yyval.var_decls)->push_back((yysemantic_stack_[(1) - (1)].var_decl));;}
    break;

  case 10:
#line 198 "calc.yy"
    {(yyval.var_decls)->push_back((yysemantic_stack_[(3) - (3)].var_decl));;}
    break;

  case 11:
#line 200 "calc.yy"
    { (yyval.var_decl) = new Variable(string((yysemantic_stack_[(1) - (1)].value)));;}
    break;

  case 12:
#line 201 "calc.yy"
    {(yyval.var_decl) = new Variable(string((yysemantic_stack_[(4) - (1)].value)),(yysemantic_stack_[(4) - (3)].intliteral)->getValue());;}
    break;

  case 15:
#line 205 "calc.yy"
    {(yyval.intliteral) = (yysemantic_stack_[(1) - (1)].intliteral);;}
    break;

  case 16:
#line 206 "calc.yy"
    {(yyval.intliteral) = (yysemantic_stack_[(1) - (1)].intliteral);;}
    break;

  case 17:
#line 209 "calc.yy"
    { (yyval.meth_decs_type) = new meth_decs(); 					(yyval.meth_decs_type)->push_back((yysemantic_stack_[(1) - (1)].meth_dec_type));}
    break;

  case 18:
#line 210 "calc.yy"
    {(yyval.meth_decs_type)->push_back((yysemantic_stack_[(2) - (2)].meth_dec_type));;}
    break;

  case 19:
#line 212 "calc.yy"
    {(yyval.meth_dec_type) = new meth_dec(std::string((yysemantic_stack_[(4) - (1)].value)), (yysemantic_stack_[(4) - (2)].value),(yysemantic_stack_[(4) - (3)].meth_args_type), (yysemantic_stack_[(4) - (4)].block_type));;}
    break;

  case 20:
#line 213 "calc.yy"
    {(yyval.meth_dec_type) = new meth_dec(std::string((yysemantic_stack_[(4) - (1)].value)), (yysemantic_stack_[(4) - (2)].value),(yysemantic_stack_[(4) - (3)].meth_args_type), (yysemantic_stack_[(4) - (4)].block_type));;}
    break;

  case 21:
#line 215 "calc.yy"
    {(yyval.meth_args_type) = (yysemantic_stack_[(3) - (2)].meth_args_type);}
    break;

  case 22:
#line 216 "calc.yy"
    {(yyval.meth_args_type) = new meth_args();;}
    break;

  case 23:
#line 218 "calc.yy"
    {(yyval.meth_args_type) = new meth_args();(yyval.meth_args_type)->push_back(new meth_arg(string((yysemantic_stack_[(2) - (1)].value)), string((yysemantic_stack_[(2) - (2)].value))));;}
    break;

  case 24:
#line 219 "calc.yy"
    {(yyval.meth_args_type)->push_back(new meth_arg(string((yysemantic_stack_[(4) - (3)].value)), string((yysemantic_stack_[(4) - (4)].value))));;}
    break;

  case 25:
#line 221 "calc.yy"
    {(yyval.block_type) = new Block();;}
    break;

  case 26:
#line 222 "calc.yy"
    {(yyval.block_type) = new Block((yysemantic_stack_[(3) - (2)].var_decs_type), new Statements());;}
    break;

  case 27:
#line 223 "calc.yy"
    {(yyval.block_type) = new Block((yysemantic_stack_[(4) - (2)].var_decs_type),(yysemantic_stack_[(4) - (3)].statements_type));;}
    break;

  case 28:
#line 224 "calc.yy"
    {(yyval.block_type) = new Block(new var_decs(),(yysemantic_stack_[(3) - (2)].statements_type));;}
    break;

  case 29:
#line 227 "calc.yy"
    {(yyval.statements_type) = new Statements(); (yyval.statements_type)->push_back((yysemantic_stack_[(1) - (1)].statement_type));;}
    break;

  case 30:
#line 228 "calc.yy"
    {(yyval.statements_type)->push_back((yysemantic_stack_[(2) - (2)].statement_type));;}
    break;

  case 31:
#line 230 "calc.yy"
    {(yyval.statement_type) = (yysemantic_stack_[(2) - (1)].meth_call_type);;}
    break;

  case 32:
#line 232 "calc.yy"
    {(yyval.meth_call_type) = new meth_call(string((yysemantic_stack_[(3) - (1)].value)), new Parameters());;}
    break;

  case 33:
#line 233 "calc.yy"
    {(yyval.meth_call_type) = new meth_call(string((yysemantic_stack_[(4) - (1)].value)), (yysemantic_stack_[(4) - (3)].parameters_type));;}
    break;

  case 34:
#line 234 "calc.yy"
    {(yyval.meth_call_type) = new callout_call((yysemantic_stack_[(4) - (3)].callout_args_type));;}
    break;

  case 35:
#line 236 "calc.yy"
    {(yyval.callout_args_type)->push_back((yysemantic_stack_[(3) - (3)].callout_arg_type));;}
    break;

  case 36:
#line 237 "calc.yy"
    {(yyval.callout_args_type) = new calloutArgs(); (yyval.callout_args_type)->push_back((yysemantic_stack_[(1) - (1)].callout_arg_type));;}
    break;

  case 37:
#line 239 "calc.yy"
    {(yyval.callout_arg_type) = new calloutArg((yysemantic_stack_[(1) - (1)].expr_type));;}
    break;

  case 38:
#line 240 "calc.yy"
    {(yyval.callout_arg_type) = new calloutArg((yysemantic_stack_[(1) - (1)].stringliteral));;}
    break;

  case 39:
#line 242 "calc.yy"
    {(yyval.value) = (yysemantic_stack_[(1) - (1)].value);}
    break;

  case 40:
#line 244 "calc.yy"
    {(yyval.parameters_type) = new Parameters(); (yyval.parameters_type)->push_back((yysemantic_stack_[(1) - (1)].expr_type));;}
    break;

  case 41:
#line 245 "calc.yy"
    {(yyval.parameters_type)->push_back((yysemantic_stack_[(3) - (3)].expr_type));;}
    break;

  case 42:
#line 247 "calc.yy"
    {(yyval.expr_type) = new EncExpr((yysemantic_stack_[(3) - (2)].expr_type));;}
    break;

  case 43:
#line 248 "calc.yy"
    {(yyval.expr_type) = new BinExpr((yysemantic_stack_[(3) - (1)].expr_type), (yysemantic_stack_[(3) - (3)].expr_type), string((yysemantic_stack_[(3) - (2)].value)));;}
    break;

  case 44:
#line 249 "calc.yy"
    {(yyval.expr_type) = new BinExpr((yysemantic_stack_[(3) - (1)].expr_type), (yysemantic_stack_[(3) - (3)].expr_type), string((yysemantic_stack_[(3) - (2)].value)));;}
    break;

  case 45:
#line 250 "calc.yy"
    {(yyval.expr_type) = new BinExpr((yysemantic_stack_[(3) - (1)].expr_type), (yysemantic_stack_[(3) - (3)].expr_type), string((yysemantic_stack_[(3) - (2)].value)));;}
    break;

  case 46:
#line 251 "calc.yy"
    {(yyval.expr_type) = new BinExpr((yysemantic_stack_[(3) - (1)].expr_type), (yysemantic_stack_[(3) - (3)].expr_type), string((yysemantic_stack_[(3) - (2)].value)));;}
    break;

  case 47:
#line 252 "calc.yy"
    {(yyval.expr_type) = new BinExpr((yysemantic_stack_[(3) - (1)].expr_type), (yysemantic_stack_[(3) - (3)].expr_type), string((yysemantic_stack_[(3) - (2)].value)));;}
    break;

  case 48:
#line 253 "calc.yy"
    {(yyval.expr_type) = new BinExpr((yysemantic_stack_[(3) - (1)].expr_type), (yysemantic_stack_[(3) - (3)].expr_type), string((yysemantic_stack_[(3) - (2)].value)));;}
    break;

  case 49:
#line 254 "calc.yy"
    {(yyval.expr_type) = new BinExpr((yysemantic_stack_[(3) - (1)].expr_type), (yysemantic_stack_[(3) - (3)].expr_type), string((yysemantic_stack_[(3) - (2)].value)));;}
    break;

  case 50:
#line 255 "calc.yy"
    {(yyval.expr_type) = new BinExpr((yysemantic_stack_[(3) - (1)].expr_type), (yysemantic_stack_[(3) - (3)].expr_type), string((yysemantic_stack_[(3) - (2)].value)));;}
    break;

  case 51:
#line 256 "calc.yy"
    {(yyval.expr_type) = new BinExpr((yysemantic_stack_[(3) - (1)].expr_type), (yysemantic_stack_[(3) - (3)].expr_type), string((yysemantic_stack_[(3) - (2)].value)));;}
    break;

  case 52:
#line 257 "calc.yy"
    {(yyval.expr_type) = new BinExpr((yysemantic_stack_[(3) - (1)].expr_type), (yysemantic_stack_[(3) - (3)].expr_type), string((yysemantic_stack_[(3) - (2)].value)));;}
    break;

  case 53:
#line 258 "calc.yy"
    {(yyval.expr_type) = new BinExpr((yysemantic_stack_[(3) - (1)].expr_type), (yysemantic_stack_[(3) - (3)].expr_type), string((yysemantic_stack_[(3) - (2)].value)));;}
    break;

  case 54:
#line 259 "calc.yy"
    {(yyval.expr_type) = new BinExpr((yysemantic_stack_[(3) - (1)].expr_type), (yysemantic_stack_[(3) - (3)].expr_type), string((yysemantic_stack_[(3) - (2)].value)));;}
    break;

  case 55:
#line 260 "calc.yy"
    {(yyval.expr_type) = new BinExpr((yysemantic_stack_[(3) - (1)].expr_type), (yysemantic_stack_[(3) - (3)].expr_type), string((yysemantic_stack_[(3) - (2)].value)));;}
    break;

  case 56:
#line 261 "calc.yy"
    {(yyval.expr_type) = (yysemantic_stack_[(1) - (1)].meth_call_type);;}
    break;

  case 57:
#line 262 "calc.yy"
    {(yyval.expr_type) = (yysemantic_stack_[(1) - (1)].literal_type);;}
    break;

  case 58:
#line 264 "calc.yy"
    {(yyval.literal_type) = (yysemantic_stack_[(1) - (1)].intliteral);;}
    break;

  case 59:
#line 265 "calc.yy"
    {(yyval.literal_type) = (yysemantic_stack_[(1) - (1)].boolliteral);;}
    break;

  case 60:
#line 266 "calc.yy"
    {(yyval.literal_type) = (yysemantic_stack_[(1) - (1)].charliteral);;}
    break;

  case 61:
#line 268 "calc.yy"
    {(yyval.boolliteral)=(yysemantic_stack_[(1) - (1)].boolliteral);;}
    break;

  case 62:
#line 269 "calc.yy"
    {(yyval.boolliteral)=(yysemantic_stack_[(1) - (1)].boolliteral);;}
    break;

  case 63:
#line 271 "calc.yy"
    {(yyval.var_decs_type) = new var_decs(); (yyval.var_decs_type)->push_back((yysemantic_stack_[(1) - (1)].var_dec_type));;}
    break;

  case 64:
#line 272 "calc.yy"
    {(yyval.var_decs_type)->push_back((yysemantic_stack_[(2) - (2)].var_dec_type));;}
    break;

  case 65:
#line 274 "calc.yy"
    {(yyval.var_dec_type) = new var_dec(string((yysemantic_stack_[(3) - (1)].value)), (yysemantic_stack_[(3) - (2)].string_list_type));;}
    break;

  case 66:
#line 276 "calc.yy"
    {(yyval.string_list_type) = new string_list(); (yyval.string_list_type)->push_back(string((yysemantic_stack_[(1) - (1)].value)));;}
    break;

  case 67:
#line 277 "calc.yy"
    {(yyval.string_list_type)->push_back(string((yysemantic_stack_[(3) - (3)].value)));;}
    break;


    /* Line 675 of lalr1.cc.  */
#line 731 "calc.tab.cc"
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
  const signed char Parser::yypact_ninf_ = -49;
  const short int
  Parser::yypact_[] =
  {
         0,    -4,     9,    20,   -49,    88,     2,   -49,   -49,   -49,
      91,   -49,    12,   146,   -49,    48,   -49,   -49,   156,    27,
      57,   -49,   -49,    61,   -49,    52,    58,   -49,    47,    58,
      66,   -49,    48,   -49,    77,    13,    -6,   -49,   -49,   -49,
      65,   -49,    89,   -49,   -49,   -49,    68,   -49,   -49,    95,
      82,    -3,   -49,    84,    98,    -1,   -49,   -49,   102,    45,
     -49,    75,   -49,   -49,   -49,    49,   -49,    15,   -49,   -49,
      72,   -49,   -49,   -49,   -49,   -49,   -49,    19,   -49,   107,
     -49,   -49,   103,   -49,   -49,    46,   107,   -49,    90,   -49,
      45,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,   -49,   -49,    72,   -49,   -49,   122,
     122,   143,   143,   143,   -49,   -49,   -49,   -49,   -49,   -49,
     -49,   -49,   107
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
       0,    19,    11,    10,    23,    21,     0,    25,    39,     0,
       0,     0,    29,     0,     0,     0,    63,    12,     0,     0,
      66,     0,    28,    30,    31,     0,    26,     0,    64,    24,
       0,    58,    60,    61,    62,    38,    56,     0,    36,    37,
      57,    59,     0,    65,    32,     0,    40,    27,     0,    34,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    67,    33,     0,    42,    35,    43,
      44,    45,    46,    47,    50,    51,    52,    55,    49,    54,
      48,    53,    41
  };

  /* YYPGOTO[NTERM-NUM].  */
  const short int
  Parser::yypgoto_[] =
  {
       -49,   -49,   -49,   113,   -49,    94,   -13,   -49,   128,   -11,
     124,   -49,   111,    86,   -40,   -26,   -49,    64,   -49,   -49,
     -48,   -49,   -49,   -49,   101,   -49
  };

  /* YYDEFGOTO[NTERM-NUM].  */
  const signed char
  Parser::yydefgoto_[] =
  {
        -1,     2,    10,    11,    20,    21,    12,    40,    13,    14,
      29,    35,    37,    51,    52,    76,    77,    78,    54,    85,
      79,    80,    81,    55,    56,    61
  };

  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule which
     number is the opposite.  If zero, do what YYDEFACT says.  */
  const signed char Parser::yytable_ninf_ = -1;
  const unsigned char
  Parser::yytable_[] =
  {
        23,     3,    24,    47,     1,    23,    62,    24,    66,     4,
      53,    63,    34,    48,     8,     9,    48,    86,    48,     8,
       9,    15,    88,    50,    87,    53,    45,    63,     5,    53,
      46,    19,    89,    58,    48,    49,    90,    28,    49,    25,
      49,    53,    50,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,    49,    70,   122,   105,
      25,    70,    84,   106,    48,    33,    36,    71,    48,    38,
      39,    71,     8,     9,    30,    31,    57,    72,    73,    74,
      32,    72,    73,    74,    70,    42,    49,    75,     8,     9,
      49,    48,    82,    83,    71,     6,    44,     7,     6,    28,
      16,    60,    64,   107,    72,    73,    74,    59,     8,     9,
      65,     8,     9,    49,    91,    92,    93,    94,    95,    96,
      97,    69,   104,    17,    43,    98,    99,   100,   101,   102,
     103,    91,    92,    93,    94,    95,    96,    97,    18,    26,
      41,    67,    98,    99,   100,   101,   102,   103,    93,    94,
      95,    96,    97,     6,   108,    22,    68,    98,    99,   100,
     101,   102,   103,     6,     0,    27,     8,     9,     0,     0,
       0,     0,    96,    97,     0,     0,     8,     9,    98,    99,
     100,   101,   102,   103
  };

  /* YYCHECK.  */
  const signed char
  Parser::yycheck_[] =
  {
        13,     5,    13,     9,     4,    18,     9,    18,     9,     0,
      36,    51,    25,    19,    20,    21,    19,    65,    19,    20,
      21,    19,    70,    36,     9,    51,    13,    67,     8,    55,
      17,    19,    13,    46,    19,    41,    17,    10,    41,    12,
      41,    67,    55,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,    41,    12,   106,    13,
      12,    12,    13,    17,    19,    13,     8,    22,    19,    22,
      23,    22,    20,    21,    17,    18,    11,    32,    33,    34,
      19,    32,    33,    34,    12,    19,    41,    42,    20,    21,
      41,    19,    17,    18,    22,     7,    19,     9,     7,    10,
       9,    19,    18,    13,    32,    33,    34,    12,    20,    21,
      12,    20,    21,    41,    24,    25,    26,    27,    28,    29,
      30,    19,    19,    10,    30,    35,    36,    37,    38,    39,
      40,    24,    25,    26,    27,    28,    29,    30,    10,    15,
      29,    55,    35,    36,    37,    38,    39,    40,    26,    27,
      28,    29,    30,     7,    90,     9,    55,    35,    36,    37,
      38,    39,    40,     7,    -1,     9,    20,    21,    -1,    -1,
      -1,    -1,    29,    30,    -1,    -1,    20,    21,    35,    36,
      37,    38,    39,    40
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
      55,    62,    63,    64,    67,    72,    73,    11,    55,    12,
      19,    74,     9,    63,    18,    12,     9,    62,    73,    19,
      12,    22,    32,    33,    34,    42,    64,    65,    66,    69,
      70,    71,    17,    18,    13,    68,    69,     9,    69,    13,
      17,    24,    25,    26,    27,    28,    29,    30,    35,    36,
      37,    38,    39,    40,    19,    13,    17,    13,    66,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69
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
      62,    63,    64,    64,    64,    65,    65,    66,    66,    67,
      68,    68,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    69,    69,    69,    70,    70,
      70,    71,    71,    72,    72,    73,    74,    74
  };

  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
  const unsigned char
  Parser::yyr2_[] =
  {
         0,     2,     5,     6,     4,     5,     1,     2,     3,     1,
       3,     1,     4,     1,     1,     1,     1,     1,     2,     4,
       4,     3,     2,     2,     4,     2,     3,     4,     3,     1,
       2,     2,     3,     4,     4,     3,     1,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     3,     1,     3
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
  "block", "statement_list", "statement", "method_call", "callout_args",
  "callout_arg", "method_name", "expr_list", "expr", "literal", "bool_lit",
  "var_dec_list", "var_dec", "id_list", 0
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
       8,    72,     9,    -1,     8,    72,    62,     9,    -1,     8,
      62,     9,    -1,    63,    -1,    62,    63,    -1,    64,    18,
      -1,    67,    12,    13,    -1,    67,    12,    68,    13,    -1,
      41,    12,    65,    13,    -1,    65,    17,    66,    -1,    66,
      -1,    69,    -1,    42,    -1,    19,    -1,    69,    -1,    68,
      17,    69,    -1,    12,    69,    13,    -1,    69,    24,    69,
      -1,    69,    25,    69,    -1,    69,    26,    69,    -1,    69,
      27,    69,    -1,    69,    28,    69,    -1,    69,    39,    69,
      -1,    69,    37,    69,    -1,    69,    29,    69,    -1,    69,
      30,    69,    -1,    69,    35,    69,    -1,    69,    40,    69,
      -1,    69,    38,    69,    -1,    69,    36,    69,    -1,    64,
      -1,    70,    -1,    22,    -1,    71,    -1,    32,    -1,    33,
      -1,    34,    -1,    73,    -1,    72,    73,    -1,    55,    74,
      18,    -1,    19,    -1,    74,    17,    19,    -1
  };

  /* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
     YYRHS.  */
  const unsigned char
  Parser::yyprhs_[] =
  {
         0,     0,     3,     9,    16,    21,    27,    29,    32,    36,
      38,    42,    44,    49,    51,    53,    55,    57,    59,    62,
      67,    72,    76,    79,    82,    87,    90,    94,    99,   103,
     105,   108,   111,   115,   120,   125,   129,   131,   133,   135,
     137,   139,   143,   147,   151,   155,   159,   163,   167,   171,
     175,   179,   183,   187,   191,   195,   199,   201,   203,   205,
     207,   209,   211,   213,   215,   218,   222,   224
  };

  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
  const unsigned short int
  Parser::yyrline_[] =
  {
         0,   187,   187,   188,   189,   190,   192,   193,   195,   197,
     198,   200,   201,   203,   203,   205,   206,   209,   210,   212,
     213,   215,   216,   218,   219,   221,   222,   223,   224,   227,
     228,   230,   232,   233,   234,   236,   237,   239,   240,   242,
     244,   245,   247,   248,   249,   250,   251,   252,   253,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   264,   265,
     266,   268,   269,   271,   272,   274,   276,   277
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
  const int Parser::yylast_ = 183;
  const int Parser::yynnts_ = 26;
  const int Parser::yyempty_ = -2;
  const int Parser::yyfinal_ = 4;
  const int Parser::yyterror_ = 1;
  const int Parser::yyerrcode_ = 256;
  const int Parser::yyntokens_ = 49;

  const unsigned int Parser::yyuser_token_number_max_ = 303;
  const Parser::token_number_type Parser::yyundef_token_ = 2;

} // namespace decaf

#line 281 "calc.yy"


void decaf::Parser::error(const Parser::location_type& l,
			    const std::string& m)
{
    driver.error(l, m);
}


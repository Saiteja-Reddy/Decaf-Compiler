/* $Id$ -*- mode: c++ -*- */
/** \file parser.yy Contains the example Bison parser source */

%{ /*** C/C++ Declarations ***/

#include <stdio.h>
#include <string>
#include <vector>

#include "ast.h"

%}

/*** yacc/bison Declarations ***/

/* Require bison 2.3 or later */
%require "2.3"

/* add debug output code to generated parser. disable this for release
 * versions. */
%debug

/* start symbol is named "start" */
%start line

/* write out a header file containing the token defines */
%defines

/* use newer C++ skeleton file */
%skeleton "lalr1.cc"

/* namespace to enclose parser in */
%name-prefix="decaf"

/* set the parser's class identifier */
%define "parser_class_name" "Parser"

/* keep track of the current position within the input */
%locations
%initial-action
{
    // initialize the initial location object
    @$.begin.filename = @$.end.filename = &driver.streamname;
};

/* The driver is passed by reference to the parser and to the scanner. This
 * provides a simple but effective pure interface, not relying on global
 * variables. */
%parse-param { class Driver& driver }

/* verbose error messages */
%error-verbose

/*** BEGIN EXAMPLE - Change the example grammar's tokens below ***/

%union {
	int  			integerVal;
    ASTnode*		astnode;
}

%type <astnode>	line expr 

//%destructor { delete $$; } expr

 /*** END EXAMPLE - Change the example grammar's tokens above ***/

%{

#include "driver.h"
#include "scanner.h"

/* this "connects" the bison parser in the driver to the flex scanner class
 * object. it defines the yylex() function call to pull the next token from the
 * current lexer object of the driver context. */
#undef yylex
#define yylex driver.lexer->lex

%}

%token END 0
%token EOL
%token <integerVal> INT_LITERAL
%left '?'
%left '+' '-'
%left '*' '/'


%%


line :	EOL				{ $$ = NULL; driver.ast.root = NULL;}
		|  expr ';' 		{ $$ = $1; driver.ast.root = $1; }
		;

expr : '(' expr ')'			{ $$ = $2 ; }
	 |  expr '+' expr       { $$ = new BinaryASTnode("+", $1, $3); }
	 |  expr '-' expr       { $$ = new BinaryASTnode("-", $1, $3); }
	 |  expr '*' expr       { $$ = new BinaryASTnode("*", $1, $3); }
	 |  expr '/' expr       { $$ = new BinaryASTnode("/", $1, $3); }
	 |  expr '?' expr ':' expr  
	 	{ $$ = new TernaryASTnode($1, $3, $5); }

	 |  INT_LITERAL         { $$ = new IntLitASTnode($1); }
	 ;	

%%

void decaf::Parser::error(const Parser::location_type& l,
			    const std::string& m)
{
    driver.error(l, m);
}

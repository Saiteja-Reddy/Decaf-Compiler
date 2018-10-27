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

%type <astnode>	line  

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
%token CLASS
%token PROGRAM
%token COMMENT
%token VOID
%token L_FLO
%token R_FLO
%token L_SQ
%token R_SQ
%token L_P
%token R_P
%token EQ
%token PE
%token ME
%token COMMA
%token SEMI
%token ID
%token BOOLEAN
%token INT
%token INTEGER_LIT
%token HEX_LIT
%token ADD
%token SUB
%token MUL
%token DIV
%token MOD
%token LT
%token GT
%token NOT
%token CHAR_LIT
%token TRUE
%token FALSE
%token NE
%token DO
%token GE
%token DA
%token LE
%token DE
%token CALLOUT
%token STRING_LIT
%token RETURN
%token BREAK
%token CONTINUE
%token IF
%token ELSE
%token FOR

%left ADD SUB
%left MUL DIV MOD
%left LE GE LT GT DE NE DA DO
%right NOT

%%

line :  CLASS PROGRAM L_FLO progs R_FLO { std::cout << "Hello" << std::endl;}

progs :  field_decl_list method_decl_list | field_decl_list

field_decl_list : field_decl | field_decl_list field_decl

field_decl : type decl_list SEMI | COMMENT

decl_list : decl | decl_list  COMMA decl

decl : ID | ID L_SQ intlit R_SQ

type : INT | BOOLEAN;

intlit : HEX_LIT | INTEGER_LIT

method_decl_list : method_decl |  method_decl_list method_decl 

method_decl :  type ID method_args_block block | VOID ID method_args_block block 

method_args_block : L_P  type_id_list R_P | L_P R_P 

type_id_list : type ID | type_id_list COMMA type ID 

block : L_FLO var_dec_list R_FLO | L_FLO  R_FLO |L_FLO statement_list R_FLO |L_FLO var_dec_list statement_list R_FLO

var_dec_list : var_dec | var_dec_list var_dec  

var_dec : type id_list SEMI

id_list : ID | id_list COMMA ID 

statement_list : statement | statement_list statement

statement : location assign_op expr SEMI | method_call SEMI | if_block | for_block | RETURN L_SQ expr R_SQ SEMI | RETURN SEMI | BREAK SEMI | CONTINUE SEMI | block

if_block : IF L_P expr R_P block |  IF L_P expr R_P block ELSE block

for_block : FOR ID EQ expr COMMA expr block

location : ID | ID L_SQ expr R_SQ

assign_op : EQ | PE | ME

method_call : method_name L_P R_P | method_name L_P expr_list R_P  | CALLOUT L_P STRING_LIT R_P | CALLOUT L_P STRING_LIT COMMA callout_args R_P

method_name : ID

expr_list : expr | expr_list COMMA expr  

callout_args : callout_args COMMA callout_arg | callout_arg

callout_arg : expr | STRING_LIT

expr : L_P expr R_P
	| expr ADD expr 
	|  expr SUB expr 
	|  expr MUL expr 
	|  expr DIV expr 
	|  expr MOD expr 
	|  expr LE expr 
	|  expr GE expr 
	|  expr LT expr 
	|  expr GT expr 
	|  expr NE expr 
	|  expr DE expr 
	|  expr DA expr 
	|  expr DO expr  
	| method_call 
	| location 
	| literal 
	| unaryexp

unaryexp : SUB expr | NOT expr 

literal : INTEGER_LIT | bool_lit | CHAR_LIT 

bool_lit : TRUE | FALSE	


%%

void decaf::Parser::error(const Parser::location_type& l,
			    const std::string& m)
{
    driver.error(l, m);
}

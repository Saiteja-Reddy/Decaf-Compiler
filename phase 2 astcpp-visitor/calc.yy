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
    ASTnode*		astnode;
    FieldDec* 		field;
	FieldDecList* 	fields;
	Variable*		var_decl;
	Variables*		var_decls;
	integerLit*   	intliteral;
	char* value;
	Block*	block_type;
	meth_args*	meth_args_type;
	meth_dec*	meth_dec_type;
	meth_decs* meth_decs_type;
}


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
%token <value> VOID
%token L_FLO
%token R_FLO
%token L_SQ
%token R_SQ
%token L_P
%token R_P
%token <value> EQ
%token <value> PE
%token <value> ME
%token COMMA
%token SEMI
%token <value> ID
%token <value> BOOLEAN
%token <value> INT
%token <intliteral> INTEGER_LIT
%token <intliteral> HEX_LIT
%token <value> ADD
%token <value> SUB
%token <value> MUL
%token <value> DIV
%token <value> MOD
%token <value> LT
%token <value> GT
%token <value> NOT
%token CHAR_LIT
%token TRUE
%token FALSE
%token <value> NE
%token <value> DO
%token <value> GE
%token <value> DA
%token <value> LE
%token <value> DE
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

%type <astnode>	line  
%type <fields> field_decl_list
%type <field> field_decl
%type <var_decls> decl_list
%type <var_decl> decl
%type <intliteral> intlit;

%type <meth_decs_type> method_decl_list;
%type <meth_dec_type> method_decl;
%type <meth_args_type> method_args_block;
%type <meth_args_type> type_id_list;
%type <block_type> block;
%type <value> type;



%%

line :  CLASS PROGRAM L_FLO field_decl_list R_FLO { $$ = new ProgramASTnode("Program Decl", $4, new meth_decs() ); driver.ast.root = $$;}
	| CLASS PROGRAM L_FLO field_decl_list method_decl_list R_FLO { $$ = new ProgramASTnode("Program Decl", $4, $5); driver.ast.root = $$;}
	| 	CLASS PROGRAM L_FLO R_FLO { $$ = new ProgramASTnode("Program"); driver.ast.root = $$;}
	| 	CLASS PROGRAM L_FLO method_decl_list R_FLO { $$ = new ProgramASTnode("Program", new FieldDecList() , $4); driver.ast.root = $$;}

field_decl_list :  field_decl { $$ = new FieldDecList(); 					$$->push_back($1)}
		 | field_decl_list field_decl {$$->push_back($2);}

field_decl : type decl_list SEMI {$$ = new FieldDec(std::string($1), $2);} 

decl_list : decl {$$ = new Variables(); $$->push_back($1);} 
		  | decl_list  COMMA decl {$$->push_back($3);}

decl : ID { $$ = new Variable(string($1));}
	 | ID L_SQ intlit R_SQ {$$ = new Variable(string($1),$3->getValue());}

type : INT | BOOLEAN;

intlit : HEX_LIT {$$ = $1;}  
		| INTEGER_LIT {$$ = $1;}


method_decl_list : method_decl { $$ = new meth_decs(); 					$$->push_back($1)}
			 |  method_decl_list method_decl {$$->push_back($2);}

method_decl :  type ID method_args_block block {$$ = new meth_dec(std::string($1), $2,$3, $4);}
			| VOID ID method_args_block block {$$ = new meth_dec(std::string($1), $2,$3, $4);}

method_args_block : L_P  type_id_list R_P {$$ = $2}
			| L_P R_P {$$ = new meth_args();}

type_id_list : type ID {$$ = new meth_args();$$->push_back(new meth_arg(string($1), string($2)));}
			| type_id_list COMMA type ID {$$->push_back(new meth_arg(string($3), string($4)));}

block : L_FLO  R_FLO {$$ = new Block();}



%%

void decaf::Parser::error(const Parser::location_type& l,
			    const std::string& m)
{
    driver.error(l, m);
}

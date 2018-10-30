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
	Lit*   	literal_type;
	Expr*   	expr_type;
	integerLit*   	intliteral;
	charLit*   	charliteral;
	boolLit*   	boolliteral;
	stringLit*   	stringliteral;
	char* value;
	Block*	block_type;
	meth_args*	meth_args_type;
	meth_dec*	meth_dec_type;
	meth_decs* meth_decs_type;
	var_dec*	var_dec_type;
	var_decs*	var_decs_type;
	string_list* string_list_type;
	Parameters* parameters_type;
	meth_call* meth_call_type;
	Statements* statements_type;
	Statement* statement_type;
	calloutArgs* callout_args_type;
	calloutArg* callout_arg_type;
	breakState* break_type;
	continueState* continue_type;
	ifElseState* if_block_type;
	forState* for_block_type;
	returnState* return_type;
	Location*	location_type;
	Assign*	assign_type;
	UnExpr* unaryexp_type;
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
%token <charliteral> CHAR_LIT
%token <boolliteral> TRUE
%token <boolliteral> FALSE
%token <value> NE
%token <value> DO
%token <value> GE
%token <value> DA
%token <value> LE
%token <value> DE
%token CALLOUT
%token <stringliteral> STRING_LIT
%token RETURN
%token <value> BREAK
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

%type <var_decs_type> var_dec_list;
%type <var_dec_type> var_dec;
%type <string_list_type> id_list;

%type <statements_type> statement_list;
%type <statement_type> statement;
%type <meth_call_type> method_call;
%type <value> method_name;
%type <parameters_type> expr_list;
%type <expr_type> expr;
%type <literal_type> literal;
%type <boolliteral> bool_lit;

%type <callout_arg_type> callout_arg
%type <callout_args_type> callout_args

%type <if_block_type> if_block
%type <for_block_type> for_block
%type <location_type> location
%type <value> assign_op
%type <unaryexp_type> unaryexp

%%

line :  CLASS PROGRAM L_FLO field_decl_list R_FLO { $$ = new ProgramASTnode("Program Decl", $4, new meth_decs() ); driver.ast.root = $$;}
	| CLASS PROGRAM L_FLO field_decl_list method_decl_list R_FLO { $$ = new ProgramASTnode("Program Decl", $4, $5); driver.ast.root = $$;}
	| 	CLASS PROGRAM L_FLO R_FLO { $$ = new ProgramASTnode("Program"); driver.ast.root = $$;}
	| 	CLASS PROGRAM L_FLO method_decl_list R_FLO { $$ = new ProgramASTnode("Program", new FieldDecList() , $4); driver.ast.root = $$;}

field_decl_list :  field_decl { $$ = new FieldDecList(); 					$$->push_back($1)}
		 | field_decl_list field_decl {$$->push_back($2);}

field_decl : type decl_list SEMI {$$ = new FieldDec(std::string($1), $2);} | COMMENT {$$ = new FieldDec();}

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

block : L_FLO  R_FLO {$$ = new Block(new var_decs(), new Statements());}
	  |	L_FLO var_dec_list R_FLO {$$ = new Block($2, new Statements());}
	  | L_FLO var_dec_list statement_list R_FLO {$$ = new Block($2,$3);}
	  | L_FLO statement_list R_FLO {$$ = new Block(new var_decs(),$2);}


statement_list : statement {$$ = new Statements(); $$->push_back($1);}
			 | statement_list statement {$$->push_back($2);}

statement : method_call SEMI {$$ = $1;}
			| BREAK SEMI {$$ = new breakState();}
			| CONTINUE SEMI {$$ = new continueState();}
			| if_block {$$ = $1;}
			| for_block {$$ = $1;}
			| RETURN L_SQ expr R_SQ SEMI {$$ = new returnState($3);}
			| RETURN SEMI {$$ = new returnState();}
			| location assign_op expr SEMI {$$ = new Assign($1, $2, $3)}
			| block {$$ = $1}

assign_op : EQ {$$ = $1}
		  | PE {$$ = $1}
		  | ME {$$ = $1}		

for_block : FOR ID EQ expr COMMA expr block {$$ = new forState($2, $4, $6, $7); }			

if_block : IF L_P expr R_P block {$$ = new ifElseState($3, $5);}
		 |  IF L_P expr R_P block ELSE block {$$ = new ifElseState($3, $5, $7);}


method_call : method_name L_P R_P {$$ = new meth_call(string($1), new Parameters());}
			| method_name L_P expr_list R_P {$$ = new meth_call(string($1), $3);}
			| CALLOUT L_P callout_args R_P {$$ = new callout_call($3);}

callout_args : callout_args COMMA callout_arg {$$->push_back($3);}
			 | callout_arg {$$ = new calloutArgs(); $$->push_back($1);}

callout_arg : expr {$$ = new calloutArg($1);}
			 | STRING_LIT {$$ = new calloutArg($1);}

method_name : ID {$$ = $1}

expr_list : expr {$$ = new Parameters(); $$->push_back($1);}
		 | expr_list COMMA expr  {$$->push_back($3);}

expr : L_P expr R_P {$$ = new EncExpr($2);}
	| expr ADD expr {$$ = new BinExpr($1, $3, string($2));}
	|  expr SUB expr {$$ = new BinExpr($1, $3, string($2));}
	|  expr MUL expr {$$ = new BinExpr($1, $3, string($2));}
	|  expr DIV expr {$$ = new BinExpr($1, $3, string($2));}
	|  expr MOD expr {$$ = new BinExpr($1, $3, string($2));}
	|  expr LE expr {$$ = new BinExpr($1, $3, string($2));}
	|  expr GE expr {$$ = new BinExpr($1, $3, string($2));}
	|  expr LT expr {$$ = new BinExpr($1, $3, string($2));}
	|  expr GT expr {$$ = new BinExpr($1, $3, string($2));}
	|  expr NE expr {$$ = new BinExpr($1, $3, string($2));}
	|  expr DE expr {$$ = new BinExpr($1, $3, string($2));}
	|  expr DA expr {$$ = new BinExpr($1, $3, string($2));}
	|  expr DO expr  {$$ = new BinExpr($1, $3, string($2));}
	| method_call {$$ = $1;}
	| literal {$$ = $1;}
	| location {$$ = $1;}
	| unaryexp {$$ = $1;} 

unaryexp : SUB expr {$$ = new UnExpr($1, $2);}
		| NOT expr 	{$$ = new UnExpr($1, $2);}

location : ID {$$ = new Location($1);}
		| ID L_SQ expr R_SQ {$$ = new Location($1, $3);}


literal : INTEGER_LIT {$$ = $1;}
		 | bool_lit {$$ = $1;}
		 | CHAR_LIT {$$ = $1;}

bool_lit : TRUE {$$=$1;}
		 | FALSE {$$=$1;}

var_dec_list : var_dec {$$ = new var_decs(); $$->push_back($1);}
			| var_dec_list var_dec  {$$->push_back($2);}

var_dec : type id_list SEMI {$$ = new var_dec(string($1), $2);}

id_list : ID {$$ = new string_list(); $$->push_back(string($1));}
		| id_list COMMA ID {$$->push_back(string($3));}



%%

void decaf::Parser::error(const Parser::location_type& l,
			    const std::string& m)
{
    driver.error(l, m);
}

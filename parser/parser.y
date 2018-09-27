%{
#include <stdio.h>	
int yylex();
int yyerror();
%}

%token ID
%token INTEGER_LIT
%token STRING_LIT
%token HEX_LIT
%token CLASS
%token PROGRAM
%token INT
%token BOOLEAN
%token VOID
%token BREAK
%token CONTINUE
%token RETURN
%token CALLOUT
%token IF
%token ELSE
%token FOR
%token EQ
%token PE
%token ME
%left '+' '-'
%left '*' '/'

%%

program : CLASS PROGRAM '{' progs '}'  | CLASS PROGRAM '{'  '}'

progs : field_decl_list method_decl_list | field_decl_list 

field_decl_list : field_decl | field_decl_list field_decl  

field_decl : type decl_list ';'

decl_list : decl | decl_list  ',' decl

decl : ID | ID '[' intlit ']'

method_decl_list : method_decl |  method_decl_list method_decl

method_decl :  type ID method_args_block block | VOID ID method_args_block block 

method_args_block : '(' ')' | '('  type_id_list ')' 

type_id_list : type ID | type_id_list ',' type ID 

block : '{' var_dec_list '}' | '{'  '}' |'{' statement_list '}' |'{' var_dec_list statement_list '}'

var_dec_list : var_dec | var_dec_list var_dec  

var_dec : type id_list ';'

id_list : ID | id_list ',' ID 

statement_list : statement | statement_list statement

statement : location assign_op expr ';' | method_call ';' | if_block | for_block | RETURN '[' expr ']' ';' | BREAK ';' | CONTINUE ';' | block

method_call : method_name '(' expr_list ')' | method_name '(' ')' | CALLOUT '(' STRING_LIT ')' | CALLOUT '(' STRING_LIT ',' callout_args')'

callout_args : callout_args ',' callout_arg | callout_arg

callout_arg : expr | STRING_LIT

if_block : IF '(' expr ')' block |  IF '(' expr ')' block ELSE block

for_block : FOR ID EQ expr ',' expr block

expr_list : expr | expr_list ',' expr  

method_name : ID

location : ID | ID '[' expr ']'

assign_op : EQ | PE | ME

intlit : HEX_LIT | INTEGER_LIT

type : INT | BOOLEAN;

expr : '(' expr ')'
	 |  expr '+' expr
	 |  expr '-' expr
	 |  expr '*' expr
	 |  expr '/' expr
	 |  ID
	 | INTEGER_LIT
	 ;	

%%

int main(int argc, char **argv)
{
		yyparse();
		printf("Parsing Over\n");
		return 0;
}


int yyerror(char *s)
{
	fprintf(stderr, "error: %s\n", s);
	return 0;
}
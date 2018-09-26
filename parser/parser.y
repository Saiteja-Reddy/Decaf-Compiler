%{
#include <stdio.h>	
%}

%token ID
%token INTEGER_LIT
%token HEX_LIT
%token CLASS
%token PROGRAM
%token INT
%token BOOLEAN
%token VOID
%left '+' '-'
%left '*' '/'

%%

program : CLASS PROGRAM '{' field_decl_list method_decl_list '}' 

field_decl_list : field_decl | field_decl_list field_decl  

field_decl : type decl_list ';'

decl_list : decl | decl_list  ',' decl

decl : ID | ID '[' intlit ']'

method_decl_list : method_decl |  method_decl_list method_decl

method_decl :  type ID method_args_block block | VOID ID method_args_block block 

method_args_block : '(' ')'

block : '{' '}'

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

main(int argc, char **argv)
{
		yyparse();
		printf("Parsing Over\n");
}


yyerror(char *s)
{
	fprintf(stderr, "error: %s\n", s);
}
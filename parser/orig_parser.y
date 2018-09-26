%{
#include <stdio.h>	
%}

%token ID
%token NUMBER
%left '+' '-'
%left '*' '/'

%%

expr : '(' expr ')'
	 |  expr '+' expr
	 |  expr '-' expr
	 |  expr '*' expr
	 |  expr '/' expr
	 |  ID
	 | NUMBER
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
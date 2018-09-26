%{
#include "parser.tab.h"
int lineno = 0;
%}

%%
[a-zA-Z][a-zA-Z]*	{return ID;}
"+"					{return '+';}
"-"					{return '-';}
"*"					{return '*';}
"/"					{return '/';}
"("					{return '(';}
")"					{return ')';}
[ \t]				{ }
\n		     		{++lineno;}
[0-9].[0-9]+		{yylval = atoi(yytext); return NUMBER;}
.					{ printf("Line No %d: Unrecognized Character\n", lineno); }

%%


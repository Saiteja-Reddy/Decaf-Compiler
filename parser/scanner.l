%{
#include "parser.tab.h"
int lineno = 0;
%}

%%
"class"				{return CLASS;}
"Program"			{return PROGRAM;}
"void"			{return VOID;}
"int"			{return INT;}
"boolean"			{return BOOLEAN;}
"break"			{return BREAK;}
[a-zA-Z][a-zA-Z]*	{return ID;}
"+"					{return '+';}
"="					{return EQ;}
"+="					{return PE;}
"-="					{return ME;}
"-"					{return '-';}
"*"					{return '*';}
"/"					{return '/';}
"("					{return '(';}
")"					{return ')';}
"{"					{return '{';}
"}"					{return '}';}
"["					{return '[';}
"]"					{return ']';}
";"					{return ';';}
","					{return ',';}
[ \t]				{ }
\n		     		{++lineno;}
0[xX][0-9a-fA-F]+ {yylval = atoi(yytext); return HEX_LIT;}
[0-9]+		{yylval = atoi(yytext); return INTEGER_LIT;}


.					{ printf("Line No %d: Unrecognized Character\n", lineno); }

%%


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
"true"			{return TRUE;}
"false"			{return FALSE;}
"break"			{return BREAK;}
"continue"			{return CONTINUE;}
"return"			{return RETURN;}
"callout"			{return CALLOUT;}
"if"			{return IF;}
"else"			{return ELSE;}
"for"			{return FOR;}
[a-zA-Z][a-zA-Z0-9]*	{return ID;}

"+="					{return PE;}
"-="					{return ME;}
"<="					{return LE;}
">="					{return GE;}
"!="					{return DE;}
"=="					{return NE;}
"&&"					{return DA;}
"||"					{return NE;}
"+"					{return '+';}
"="					{return EQ;}

"<"					{return '<';}
">"					{return '>';}
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
"!"					{return '!';}
[ \t]				{ }
\n		     		{++lineno;}
\'.\'		{return CHAR_LIT;}

0[xX][0-9a-fA-F]+ {yylval = atoi(yytext); return HEX_LIT;}
[0-9]+		{yylval = atoi(yytext); return INTEGER_LIT;}
\"[a-zA-Z]+\"		{return STRING_LIT;}


.					{ printf("Line No %d: Unrecognized Character\n", lineno); }

%%


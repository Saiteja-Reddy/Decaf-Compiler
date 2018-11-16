%{
#include <bits/stdc++.h>
#include "ast.h"
#include "parser.tab.hpp"
#define YY_DECL extern "C" int yylex()
/*extern union Node yylval;*/
using namespace std;
int lineno = 0;
%}

%%

"//".*      {return COMMENT;}
"class"             {return CLASS;}
"Program"           {return PROGRAM;}
"int"           {yylval.value = strdup(yytext); return INT;}
"boolean"           {yylval.value = strdup(yytext); return BOOLEAN;}
"void"           {yylval.value = strdup(yytext);return VOID;}
"true"          {yylval.boolliteral = new boolLit(yytext);return TRUE;}
"false"         {yylval.boolliteral = new boolLit(yytext);return FALSE;}
"callout"         {return CALLOUT;}
"return"         {return RETURN;}
"break"         {return BREAK;}
"continue"         {return CONTINUE;}
"if"         {return IF;}
"else"         {return ELSE;}
"for"         {return FOR;}

[a-zA-Z_][a-zA-Z0-9]*   {yylval.value = strdup(yytext);return ID;}

0[xX][0-9a-fA-F]+ {yylval.intliteral = new integerLit(atoi(yytext)); return HEX_LIT;}

-?[0-9]+      {yylval.intliteral = new integerLit(atoi(yytext)); return INTEGER_LIT;}

"+="                {yylval.value = strdup(yytext);return PE;}
"-="                {yylval.value = strdup(yytext);return ME;}
"="                 {yylval.value = strdup(yytext);return EQ;}

"+"                 {yylval.value = strdup(yytext);return ADD;}
"-"                 {yylval.value = strdup(yytext);return SUB;}
"*"                 {yylval.value = strdup(yytext);return MUL;}
"/"                 {yylval.value = strdup(yytext);return DIV;}
"%"                 {yylval.value = strdup(yytext);return MOD;}
"<"                 {yylval.value = strdup(yytext);return LT;}
">"                 {yylval.value = strdup(yytext);return GT;}
"!"                 {yylval.value = strdup(yytext);return NOT;}

"{"                 {return L_FLO;}
"}"                 {return R_FLO;}
"["                 {return L_SQ;}
"]"                 {return R_SQ;}
"("                 {return L_P;}
")"                 {return R_P;}
","                 {return COMMA;}
";"                 {return SEMI;}

"!="                 {yylval.value = strdup(yytext);return NE; }
"||"                 {yylval.value = strdup(yytext);return DO; }
">="                 {yylval.value = strdup(yytext);return GE; }
"&&"                 {yylval.value = strdup(yytext);return DA; }
"<="                 {yylval.value = strdup(yytext);return LE; }
"=="                 {yylval.value = strdup(yytext);return DE; }

\'.\'       {yylval.charliteral = new charLit(yytext);return CHAR_LIT;}
[ \t\r]+ 	{}
[\n]+ 		{++lineno;}
\".*+\"     {yylval.stringliteral = new stringLit(yytext);return STRING_LIT;}


%%


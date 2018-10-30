/* $Id$ -*- mode: c++ -*- */
/** \file scanner.ll Define the example Flex lexical scanner */

%{ /*** C/C++ Declarations ***/

#include <string>

#include "scanner.h"

/* import the parser's token type into a local typedef */
typedef decaf::Parser::token token;
typedef decaf::Parser::token_type token_type;

/* By default yylex returns int, we use token_type. Unfortunately yyterminate
 * by default returns 0, which is not of token_type. */
#define yyterminate() return token::END

/* This disables inclusion of unistd.h, which is not available under Visual C++
 * on Win32. The C++ scanner uses STL streams instead. */
#define YY_NO_UNISTD_H

%}

/*** Flex Declarations and Options ***/

/* enable c++ scanner class generation */
%option c++

/* change the name of the scanner class. results in "decafFlexLexer" */
%option prefix="decaf"

/* the manual says "somewhat more optimized" */
%option batch

/* enable scanner to generate debug output. disable this for release
 * versions. */
%option debug

/* no support for include files is planned */
%option yywrap nounput 

/* enables the use of start condition stacks */
%option stack

/* The following paragraph suffices to track locations accurately. Each time
 * yylex is invoked, the begin position is moved onto the end position. */
%{
#define YY_USER_ACTION  yylloc->columns(yyleng);
%}

%% /*** Regular Expressions Part ***/

 /* code to place at the beginning of yylex() */
%{
    // reset location
    yylloc->step();
%}

"//".*      {return token::COMMENT;}
"class"             {return token::CLASS;}
"Program"           {return token::PROGRAM;}
"int"           {yylval->value = strdup(yytext); return token::INT;}
"boolean"           {yylval->value = strdup(yytext); return token::BOOLEAN;}
"void"           {yylval->value = strdup(yytext);return token::VOID;}
"true"          {yylval->boolliteral = new boolLit(yytext);return token::TRUE;}
"false"         {yylval->boolliteral = new boolLit(yytext);return token::FALSE;}
"callout"         {return token::CALLOUT;}
"return"         {return token::RETURN;}
"break"         {return token::BREAK;}
"continue"         {return token::CONTINUE;}
"if"         {return token::IF;}
"else"         {return token::ELSE;}
"for"         {return token::FOR;}

[a-zA-Z_][a-zA-Z0-9]*   {yylval->value = strdup(yytext);return token::ID;}

0[xX][0-9a-fA-F]+ {yylval->intliteral = new integerLit(atoi(yytext)); return token::HEX_LIT;}

[0-9]+      {yylval->intliteral = new integerLit(atoi(yytext)); return token::INTEGER_LIT;}

"+="                {yylval->value = strdup(yytext);return token::PE;}
"-="                {yylval->value = strdup(yytext);return token::ME;}
"="                 {yylval->value = strdup(yytext);return token::EQ;}

"+"                 {yylval->value = strdup(yytext);return token::ADD;}
"-"                 {yylval->value = strdup(yytext);return token::SUB;}
"*"                 {yylval->value = strdup(yytext);return token::MUL;}
"/"                 {yylval->value = strdup(yytext);return token::DIV;}
"%"                 {yylval->value = strdup(yytext);return token::MOD;}
"<"                 {yylval->value = strdup(yytext);return token::LT;}
">"                 {yylval->value = strdup(yytext);return token::GT;}
"!"                 {yylval->value = strdup(yytext);return token::NOT;}

"{"                 {return token::L_FLO;}
"}"                 {return token::R_FLO;}
"["                 {return token::L_SQ;}
"]"                 {return token::R_SQ;}
"("                 {return token::L_P;}
")"                 {return token::R_P;}
","                 {return token::COMMA;}
";"                 {return token::SEMI;}

"!="                 {yylval->value = strdup(yytext);return token::NE; }
"||"                 {yylval->value = strdup(yytext);return token::DO; }
">="                 {yylval->value = strdup(yytext);return token::GE; }
"&&"                 {yylval->value = strdup(yytext);return token::DA; }
"<="                 {yylval->value = strdup(yytext);return token::LE; }
"=="                 {yylval->value = strdup(yytext);return token::DE; }



\'.\'       {yylval->charliteral = new charLit(yytext);return token::CHAR_LIT;}




 /* gobble up white-spaces ( Added \n here ********) */
[ \t\r\n]+ {
    yylloc->step();
}

\".*+\"     {yylval->stringliteral = new stringLit(yytext);return token::STRING_LIT;}


 /* pass all other characters up to bison */
. {
    return static_cast<token_type>(*yytext);
}


%% /*** Additional Code ***/

namespace decaf {

Scanner::Scanner(std::istream* in,
		 std::ostream* out)
    : decafFlexLexer(in, out)
{
}

Scanner::~Scanner()
{
}

void Scanner::set_debug(bool b)
{
    yy_flex_debug = b;
}

}

/* This implementation of DecafFlexLexer::yylex() is required to fill the
 * vtable of the class DecafFlexLexer. We define the scanner's main yylex
 * function via YY_DECL to reside in the Scanner class instead. */

#ifdef yylex
#undef yylex
#endif

int decafFlexLexer::yylex()
{
    std::cerr << "in decafFlexLexer::yylex() !" << std::endl;
    return 0;
}

/* When the scanner receives an end-of-file indication from YY_INPUT, it then
 * checks the yywrap() function. If yywrap() returns false (zero), then it is
 * assumed that the function has gone ahead and set up `yyin' to point to
 * another input file, and scanning continues. If it returns true (non-zero),
 * then the scanner terminates, returning 0 to its caller. */

int decafFlexLexer::yywrap()
{
    return 1;
}


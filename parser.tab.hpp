/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PARSER_TAB_HPP_INCLUDED
# define YY_YY_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    END = 0,
    EOL = 258,
    CLASS = 259,
    PROGRAM = 260,
    COMMENT = 261,
    VOID = 262,
    L_FLO = 263,
    R_FLO = 264,
    L_SQ = 265,
    R_SQ = 266,
    L_P = 267,
    R_P = 268,
    EQ = 269,
    PE = 270,
    ME = 271,
    COMMA = 272,
    SEMI = 273,
    ID = 274,
    BOOLEAN = 275,
    INT = 276,
    INTEGER_LIT = 277,
    HEX_LIT = 278,
    ADD = 279,
    SUB = 280,
    MUL = 281,
    DIV = 282,
    MOD = 283,
    LT = 284,
    GT = 285,
    NOT = 286,
    CHAR_LIT = 287,
    TRUE = 288,
    FALSE = 289,
    NE = 290,
    DO = 291,
    GE = 292,
    DA = 293,
    LE = 294,
    DE = 295,
    CALLOUT = 296,
    STRING_LIT = 297,
    RETURN = 298,
    BREAK = 299,
    CONTINUE = 300,
    IF = 301,
    ELSE = 302,
    FOR = 303
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 16 "parser.ypp" /* yacc.c:1909  */

    class ProgramASTnode*		astnode;
    class FieldDec* 		field;
	class FieldDecList* 	fields;
	class Variable*		var_decl;
	class Variables*		var_decls;
	class Lit*   	literal_type;
	class Expr*   	expr_type;
	class integerLit*   	intliteral;
	class charLit*   	charliteral;
	class boolLit*   	boolliteral;
	class stringLit*   	stringliteral;
	char* value;
	class Block*	block_type;
	class meth_args*	meth_args_type;
	class meth_dec*	meth_dec_type;
	class meth_decs* meth_decs_type;
	class var_dec*	var_dec_type;
	class var_decs*	var_decs_type;
	class string_list* string_list_type;
	class Parameters* parameters_type;
	class meth_call* meth_call_type;
	class Statements* statements_type;
	class Statement* statement_type;
	class calloutArgs* callout_args_type;
	class calloutArg* callout_arg_type;
	class breakState* break_type;
	class continueState* continue_type;
	class ifElseState* if_block_type;
	class forState* for_block_type;
	class returnState* return_type;
	class Location*	location_type;
	class Assign*	assign_type;
	class UnExpr* unaryexp_type;
  

#line 141 "parser.tab.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_HPP_INCLUDED  */

/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
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
/* Tokens.  */
#define END 0
#define EOL 258
#define CLASS 259
#define PROGRAM 260
#define COMMENT 261
#define VOID 262
#define L_FLO 263
#define R_FLO 264
#define L_SQ 265
#define R_SQ 266
#define L_P 267
#define R_P 268
#define EQ 269
#define PE 270
#define ME 271
#define COMMA 272
#define SEMI 273
#define ID 274
#define BOOLEAN 275
#define INT 276
#define INTEGER_LIT 277
#define HEX_LIT 278
#define ADD 279
#define SUB 280
#define MUL 281
#define DIV 282
#define MOD 283
#define LT 284
#define GT 285
#define NOT 286
#define CHAR_LIT 287
#define TRUE 288
#define FALSE 289
#define NE 290
#define DO 291
#define GE 292
#define DA 293
#define LE 294
#define DE 295
#define CALLOUT 296
#define STRING_LIT 297
#define RETURN 298
#define BREAK 299
#define CONTINUE 300
#define IF 301
#define ELSE 302
#define FOR 303




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 16 "parser.ypp"
{
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
  }
/* Line 1529 of yacc.c.  */
#line 183 "parser.tab.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;


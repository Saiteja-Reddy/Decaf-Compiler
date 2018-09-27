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
     ID = 258,
     INTEGER_LIT = 259,
     STRING_LIT = 260,
     CHAR_LIT = 261,
     COMMENT = 262,
     HEX_LIT = 263,
     CLASS = 264,
     PROGRAM = 265,
     INT = 266,
     BOOLEAN = 267,
     TRUE = 268,
     FALSE = 269,
     VOID = 270,
     BREAK = 271,
     CONTINUE = 272,
     RETURN = 273,
     CALLOUT = 274,
     IF = 275,
     ELSE = 276,
     FOR = 277,
     EQ = 278,
     PE = 279,
     ME = 280,
     LE = 281,
     GE = 282,
     DE = 283,
     NE = 284,
     DA = 285,
     DO = 286
   };
#endif
/* Tokens.  */
#define ID 258
#define INTEGER_LIT 259
#define STRING_LIT 260
#define CHAR_LIT 261
#define COMMENT 262
#define HEX_LIT 263
#define CLASS 264
#define PROGRAM 265
#define INT 266
#define BOOLEAN 267
#define TRUE 268
#define FALSE 269
#define VOID 270
#define BREAK 271
#define CONTINUE 272
#define RETURN 273
#define CALLOUT 274
#define IF 275
#define ELSE 276
#define FOR 277
#define EQ 278
#define PE 279
#define ME 280
#define LE 281
#define GE 282
#define DE 283
#define NE 284
#define DA 285
#define DO 286




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;


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
     HEX_LIT = 262,
     CLASS = 263,
     PROGRAM = 264,
     INT = 265,
     BOOLEAN = 266,
     TRUE = 267,
     FALSE = 268,
     VOID = 269,
     BREAK = 270,
     CONTINUE = 271,
     RETURN = 272,
     CALLOUT = 273,
     IF = 274,
     ELSE = 275,
     FOR = 276,
     EQ = 277,
     PE = 278,
     ME = 279,
     LE = 280,
     GE = 281,
     DE = 282,
     NE = 283,
     DA = 284,
     DO = 285
   };
#endif
/* Tokens.  */
#define ID 258
#define INTEGER_LIT 259
#define STRING_LIT 260
#define CHAR_LIT 261
#define HEX_LIT 262
#define CLASS 263
#define PROGRAM 264
#define INT 265
#define BOOLEAN 266
#define TRUE 267
#define FALSE 268
#define VOID 269
#define BREAK 270
#define CONTINUE 271
#define RETURN 272
#define CALLOUT 273
#define IF 274
#define ELSE 275
#define FOR 276
#define EQ 277
#define PE 278
#define ME 279
#define LE 280
#define GE 281
#define DE 282
#define NE 283
#define DA 284
#define DO 285




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;


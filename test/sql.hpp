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
     NAME = 258,
     STRING = 259,
     INTNUM = 260,
     APPROXNUM = 261,
     OR = 262,
     ANDOP = 263,
     NOT = 264,
     COMPARISON = 265,
     UMINUS = 266,
     AND = 267,
     CREATE = 268,
     DATABASE = 269,
     DATABASES = 270,
     DELETE = 271,
     DROP = 272,
     FLOAT = 273,
     FROM = 274,
     INDEX = 275,
     INSERT = 276,
     INT = 277,
     INTO = 278,
     KEY = 279,
     ON = 280,
     PRIMARY = 281,
     SELECT = 282,
     SHOW = 283,
     TABLE = 284,
     UNIQUE = 285,
     VALUES = 286,
     VARCHAR = 287,
     WHERE = 288
   };
#endif
/* Tokens.  */
#define NAME 258
#define STRING 259
#define INTNUM 260
#define APPROXNUM 261
#define OR 262
#define ANDOP 263
#define NOT 264
#define COMPARISON 265
#define UMINUS 266
#define AND 267
#define CREATE 268
#define DATABASE 269
#define DATABASES 270
#define DELETE 271
#define DROP 272
#define FLOAT 273
#define FROM 274
#define INDEX 275
#define INSERT 276
#define INT 277
#define INTO 278
#define KEY 279
#define ON 280
#define PRIMARY 281
#define SELECT 282
#define SHOW 283
#define TABLE 284
#define UNIQUE 285
#define VALUES 286
#define VARCHAR 287
#define WHERE 288




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 24 "sql.y"
{
 
  int intval;
  double floatval;
  char * strval;
  int subtok;
  bool boolval;

  std::string * str;

  std::vector<std::string> *string_list;
  std::vector< std::vector<std::string> > *string_vec;
  Parse_Node* node_p;

  std::vector<Parse_Node*> *node_list;

}
/* Line 1529 of yacc.c.  */
#line 133 "sql.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;


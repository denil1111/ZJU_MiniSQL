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
     SHIFT = 266,
     MOD = 267,
     UMINUS = 268,
     AND = 269,
     CREATE = 270,
     DATABASE = 271,
     DATABASES = 272,
     DELETE = 273,
     DROP = 274,
     FLOAT = 275,
     FROM = 276,
     INDEX = 277,
     INSERT = 278,
     INT = 279,
     INTO = 280,
     KEY = 281,
     ON = 282,
     PRIMARY = 283,
     SELECT = 284,
     SHOW = 285,
     TABLE = 286,
     UNIQUE = 287,
     VALUES = 288,
     VARCHAR = 289,
     WHERE = 290
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
#define SHIFT 266
#define MOD 267
#define UMINUS 268
#define AND 269
#define CREATE 270
#define DATABASE 271
#define DATABASES 272
#define DELETE 273
#define DROP 274
#define FLOAT 275
#define FROM 276
#define INDEX 277
#define INSERT 278
#define INT 279
#define INTO 280
#define KEY 281
#define ON 282
#define PRIMARY 283
#define SELECT 284
#define SHOW 285
#define TABLE 286
#define UNIQUE 287
#define VALUES 288
#define VARCHAR 289
#define WHERE 290




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 28 "sql.y"
{
 
  int intval;
  double floatval;
  char * strval;
  int subtok;

  SELECT_NODE * selece_node_p;
  std::vector<std::string> *string_list;

  node* node_p;
 
  //INT_NODE * int_node_p;
  //FLOAT_NODE * float_node_p;
  //NAME_NODE * name_node_p;
  //STRING_NODE * str_node_p;
  //FORMULA_NODE * formula_node_p;
  //vector <node> name_list;  
}
/* Line 1529 of yacc.c.  */
#line 139 "sql.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;


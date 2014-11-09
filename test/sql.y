/* Companion source code for "flex & bison", published by O'Reilly
 * Media, ISBN 978-0-596-15597-1
 * Copyright (c) 2009, Taughannock Networks. All rights reserved.
 * See the README file for license conditions and contact info.
 * $Header: /home/johnl/flnb/code/sql/RCS/pmysql.y,v 2.1 2009/11/08 02:53:39 johnl Exp $
 */
/*
 * Parser for mysql subset
 */

%{
extern int yylex();
void yyerror(char *s, ...);
void emit(char *s, ...);

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>  
#include <stdarg.h>
#include <string>
#include <vector>
#include <iostream>

#include "sqltree.hpp"
%}


%union {
 
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
  
  /* names and literal values */

%token <strval> NAME
%token <strval> STRING
%token <intval> INTNUM
%token <floatval> APPROXNUM


  /* operators and precedence levels */

%left OR
%left ANDOP
%left NOT '!'
%left <subtok> COMPARISON /* = <> < > <= >= <=> */
%left '|'
%left '&'
%left <subtok> SHIFT /* << >> */
%left '+' '-'
%left '*' '/' '%' MOD
%left '^'
%nonassoc UMINUS


%token AND
%token CREATE
%token DATABASE
%token DATABASES
%token DELETE
%token DROP
%token FLOAT
%token FROM
%token INDEX
%token INSERT
%token INT
%token INTO
%token KEY
%token NOT
%token ON
%token OR
%token PRIMARY
%token SELECT
%token SHOW
%token TABLE
%token UNIQUE
%token VALUES
%token VARCHAR
%token WHERE


%type <node_p> select_stmt
%type <string_list> select_expr_list
%type <node_p> expr
%type <node_p> opt_where


%type <intval> table_reference
%type <intval> insert_vals insert_vals_list
%type <intval> opt_length
%type <intval> column_atts data_type create_col_list column_list

%start stmt_list

%%
stmt_list: stmt ';'
  | stmt_list stmt ';'
  ;
   
/* statements: select statement */
stmt: select_stmt { 
        emit("STMT"); 
      }
   ;

select_stmt: SELECT select_expr_list
     FROM table_reference
     opt_where {$$=new SELECT_NODE;$$->select_list=*$2;free($2);} ;
;

opt_where: {$$=NULL;} /* nil */ 
   | WHERE expr {$$=new FORMULA_NODE;*$$=*$2;free($2);};

select_expr_list: NAME {$$=new std::vector<std::string>;$$->push_back($1);}
    | select_expr_list ',' NAME {$$->push_back($3);}
    ;

table_reference: NAME {emit("TABLE %s",$1);}
  | table_subquery { emit("SUBQUERYAS"); }
  ;

table_subquery: '(' select_stmt ')' { emit("SUBQUERY"); }
   ;


/* statements: delete statement */
stmt: delete_stmt { emit("STMT"); }
   ;


delete_stmt: DELETE FROM table_reference opt_where
            { emit("DELETEMULTI"); }

/* statements: insert statement */
stmt: insert_stmt { emit("STMT"); }
   ;

insert_stmt: INSERT opt_into table_reference VALUES insert_vals_list
    { emit("INSERTVALS"); }
   ;


opt_into: INTO | /* nil */
   ;

insert_vals_list: '(' insert_vals ')' { emit("VALUES %d", $2); $$ = 1; }
   | insert_vals_list ',' '(' insert_vals ')' { emit("VALUES %d", $4); $$ = $1 + 1; }
   ;

insert_vals: expr { $$ = 1; }
   | insert_vals ',' expr { $$ = $1 + 1; }
   ;



/** create database **/
stmt: create_database_stmt { emit("STMT"); }
   ;

create_database_stmt: 
     CREATE DATABASE NAME { emit("CREATEDATABASE"); }
   ;

/** create table **/
stmt: create_table_stmt { emit("STMT"); }
   ;

create_table_stmt: CREATE TABLE NAME
   '(' create_col_list ')' { emit("CREATETABLE %s %d", $3, $5);  }

create_col_list: create_definition { $$ = 1; }
    | create_col_list ',' create_definition { $$ = $1 + 1; }
    ;

create_definition: { emit("STARTCOL"); } NAME data_type column_atts
                   { emit("COLUMNDEF %d %s", $3, $2); free($2); }

    | PRIMARY KEY '(' column_list ')'    { emit("PRIKEY"); }
    | KEY '(' column_list ')'            { emit("KEY"); }
    | INDEX '(' column_list ')'          { emit("KEY"); }
    ;

column_atts: /* nil */ { $$ = 0; }
    | column_atts UNIQUE '(' column_list ')' { emit("ATTR UNIQUEKEY"); $$ = $1 + 1; }
    | column_atts UNIQUE KEY { emit("ATTR UNIQUEKEY"); $$ = $1 + 1; }
    | column_atts PRIMARY KEY { emit("ATTR PRIKEY"); $$ = $1 + 1; }
    | column_atts KEY { emit("ATTR PRIKEY"); $$ = $1 + 1; }
    ;

column_list: NAME { emit("COLUMN %s", $1); free($1); $$ = 1; }
  | column_list ',' NAME  { emit("COLUMN %s",$3); free($3); $$ = $1 + 1; }
  ;

opt_length: /* nil */ { $$ = 0; }
   | '(' INTNUM ')' { $$ = $2; }
   ;


data_type:
   | INT { $$ = 40000; }
   | FLOAT { $$ = 90000; }
   | VARCHAR opt_length { $$ = 130000; }
   ;

/**** expressions ****/
expr: NAME          {}
   | STRING        { emit("STRING %s", $1); free($1); }
   | INTNUM        { emit("NUMBER %d", $1); }
   | APPROXNUM     { emit("FLOAT %g", $1); }
   ;

expr: expr '+' expr { emit("ADD"); }
   | expr '-' expr { emit("SUB"); }
   | expr '*' expr { emit("MUL"); }
   | expr '/' expr { emit("DIV"); }
   | expr '%' expr { emit("MOD"); }
   | expr MOD expr { emit("MOD"); }
   | '-' expr %prec UMINUS { emit("NEG"); }
   | expr ANDOP expr { emit("AND"); }
   | expr OR expr { emit("OR"); }
   | expr COMPARISON expr { emit("CMP %d", $2); }
   | expr COMPARISON '(' select_stmt ')' { emit("CMPSELECT %d", $2); }
   | expr SHIFT expr { emit("SHIFT %s", $2==1?"left":"right"); }
   | NOT expr { emit("NOT"); }
   | '!' expr { emit("NOT"); }
   ;    

%%

void
emit(char *s, ...)
{
  extern int yylineno;

  va_list ap;
  va_start(ap, s);

  vfprintf(stdout, s, ap);
  printf("\n");
}

void
yyerror(char *s, ...)
{
  extern int yylineno;

  va_list ap;
  va_start(ap, s);

  fprintf(stderr, "%d: error: ", yylineno);
  vfprintf(stderr, s, ap);
  fprintf(stderr, "\n");
}
int
main(int ac, char **av)
{
  extern FILE *yyin;
 // extern int yydebug;
 // if(ac > 1 && !strcmp(av[1], "-d")) {
 //   yydebug = 1; ac--; av++;
 // }

  if(ac > 1 && (yyin = fopen(av[1], "r")) == NULL) {
    perror(av[1]);
    exit(1);
  }
  if(!yyparse())
    printf("SQL parse worked\n");
  else
    printf("SQL parse failed\n");
  return 0;
} /* main */

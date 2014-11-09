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
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>  
#include <stdarg.h>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "sqltree.hpp"


std::stringstream ss;
std::string all_s;

extern int yylex();
void yyerror(char *s, ...);
void emit(char *s, ...);
%}


%union {
 
  int intval;
  double floatval;
  char * strval;
  int subtok;

  std::string * str;

  std::vector<std::string> *string_list;
  std::vector< std::vector<std::string> > *string_vec;
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
%type <string_list> table_reference

%type <node_p> delete_stmt

%type <node_p> insert_stmt
%type <string_list> insert_vals 
%type <string_vec> insert_vals_list
%type <str> term

%type <node_p> create_database_stmt 
%type <node_p> create_index_stmt 
%type <node_p> create_table_stmt
%type <node_p> drop_table_stmt 
%type <node_p> drop_db_stmt 
%type <node_p> drop_index_stmt

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
     opt_where {
      $$=new SELECT_NODE;
      $$->select_list=*$2;
      free($2);

      //std::cout<<$$->select_list[0]<<std::endl;
      //std::cout<<$$->select_list[1]<<std::endl;
      //std::cout<<<<std::endl;

      //std::cout<<$4->select_tbl_list[0]<<std::endl;
      //std::cout<<$4->select_tbl_list[1]<<std::endl;

      $$->select_tbl_list=*$4;
      free($4);
      //std::cout<<$$->select_tbl_list[0]<<std::endl;
      //std::cout<<$$->select_tbl_list[1]<<std::endl;
      

      //std::cout<<$5->cmp<<std::endl;
      if($5==NULL){
        //std::cout<<"null"<<std::endl;
        $$->select_where_clause=NULL;
      }
      else{
        $$->select_where_clause=new FORMULA_NODE;//must new 
        *($$->select_where_clause)=*$5;
        free($5);
        //std::cout<<$$->select_where_clause->cmp<<std::endl;
        //std::cout<<$$->select_where_clause->l->name<<std::endl;
      } 
    }
    | SELECT select_expr_list
     FROM '(' select_stmt ')' 
     opt_where {
        $$=new SELECT_NODE;
        $$->select_list=*$2;
        free($2);

        //std::cout<<"begin"<<std::endl;
        $$->nested_tbl=new SELECT_NODE;
        *($$->nested_tbl)=*$5;
        //std::cout<<$$->nested_tbl->select_list[0]<<std::endl;
        free($5);

        if($7==NULL)
        {
            //std::cout<<"null"<<std::endl;
            $$->select_where_clause=NULL;
        }
        else
        {
            $$->select_where_clause=new FORMULA_NODE;//must new 
            *($$->select_where_clause)=*$7;
            free($7);
        }

     }
    ;

opt_where: {$$=NULL;} /* nil */ 
   | WHERE expr {$$=new FORMULA_NODE;*$$=*$2;free($2);
    //std::cout<<$$->cmp<<std::endl;
    }
    ;


select_expr_list: NAME {$$=new std::vector<std::string>;$$->push_back($1);}
    | select_expr_list ',' NAME {$$->push_back($3);}
    | '*' {$$=new std::vector<std::string>;$$->push_back("select_all_flag");}
    ;

table_reference: NAME {$$=new std::vector<std::string>;
    $$->push_back($1);}
  | table_reference ',' NAME {$$->push_back($3);}
  ;


/* statements: delete statement */
stmt: delete_stmt { emit("STMT"); }
   ;

delete_stmt: DELETE FROM table_reference opt_where
    {
      $$=new DELETE_NODE;

      $$->del_tbl_list=*$3;
      free($3);
      //std::cout<<$$->select_tbl_list[0]<<std::endl;
      //std::cout<<$$->select_tbl_list[1]<<std::endl;
      

      //std::cout<<$4->cmp<<std::endl;
      if($4==NULL){
        yyerror("expected where clause!");
      }
      else{
        $$->del_where_clause=new DELETE_NODE;//must new 
        *($$->del_where_clause)=*$4;
        free($4);
        //std::cout<<$$->del_where_clause->cmp<<std::endl;
        //std::cout<<$$->del_where_clause->l->name<<std::endl;
      }  
    }
    | DELETE '*' FROM table_reference {
        $$=new DELETE_NODE;

        $$->del_tbl_list=*$4;
        free($4);

        //std::cout<<$$->del_tbl_list[0]<<std::endl;

        $$->star_flag=1;
    }
    ;

/* statements: insert statement */
stmt: insert_stmt {}
   ;

insert_stmt: INSERT INTO table_reference VALUES insert_vals_list
    {
        $$=new INSERT_NODE;

        $$->insert_tbl_list=*$3;
        //std::cout<<$$->insert_tbl_list[0]<<std::endl;
        free($3);

        $$->insert_value_list=*$5;
        //std::cout<<$$->value_list[0][0]<<std::endl;
        //std::cout<<$$->value_list[1][0]<<std::endl;
        free($5);
    }
   ;

insert_vals_list: '(' insert_vals ')' {$$=new std::vector<std::vector<std::string> >;$$->push_back(*$2);delete $2;}
   | insert_vals_list ',' '(' insert_vals ')' {$$->push_back(*$4);free($4);}
   ;

insert_vals: term {$$=new std::vector<std::string>;
    $$->push_back(*$1);}
   | insert_vals ',' term {$$->push_back(*$3);}
   ;

term: NAME          {$$=new std::string($1);}
   | STRING        {$$=new std::string($1);}
   | INTNUM        {
    std::stringstream ss;
    $$=new std::string;
    ss<<$1;
    ss>>*$$;
    //std::cout<<*$$<<std::endl;
   }
   | APPROXNUM     {
    std::stringstream ss;
    $$=new std::string;
    ss<<$1;ss>>*$$;
    //std::cout<<*$$<<std::endl;
    }
   ;

/** create database **/
stmt: create_database_stmt { emit("STMT"); }
   ;

create_database_stmt: 
     CREATE DATABASE NAME {
        $$=new CREATE_DATABASE_NODE;
        $$->create_db_name=std::string($3);
        //std::cout<<$$->db_name<<std::endl;
        free($3);
    }
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

//create index
stmt: create_index_stmt { emit("STMT"); }
   ;

create_index_stmt:CREATE INDEX NAME ON NAME '(' NAME ')' {
        $$=new CREATE_INDEX_NODE;
        $$->create_index_name=std::string($3);
        $$->create_index_tbl=std::string($5);
        $$->create_index_attr=std::string($7);
        //dropstd::cout<<$$->create_index_name<<std::endl;
        free($3);
        free($5);
        free($7);
    }
    ; 

//drop table
stmt: drop_table_stmt { emit("STMT"); }
   ;

drop_table_stmt:DROP TABLE NAME {
        $$=new DROP_TABLE_NODE;
        $$->drop_tbl_name=std::string($3);
        //std::cout<<$$->drop_tbl_name<<std::endl;
        free($3);
    }
    ;  

//drop db
stmt: drop_db_stmt { emit("STMT"); }
   ;
drop_db_stmt:DROP DATABASE NAME {
        $$=new DROP_TABLE_NODE;
        $$->drop_db_name=std::string($3);
        //std::cout<<$$->drop_db_name<<std::endl;
        free($3);
    }
    ;  

//drop index
stmt: drop_index_stmt { emit("STMT"); }
   ;

drop_index_stmt:DROP INDEX NAME ON NAME {
        $$=new DROP_INDEX_NODE;
        $$->drop_index_name=std::string($3);
        $$->drop_index_tbl=std::string($5);
        //std::cout<<$$->drop_index_name<<std::endl;
    }
    ; 



/**** expressions ****/
expr: NAME          {std::string all_s($1);$$=new_name(all_s);
    //std::cout<<$$->name<<std::endl;
    }
   | STRING        {std::string all_s($1);$$=new_name(all_s);}
   | INTNUM        {$$=new_int($1);
    //std::cout<<$$->int_num<<std::endl;
    }
   | APPROXNUM     {$$=new_float($1);}
   ;

expr: expr '+' expr {$$=new_formula(7,$1,$3);}
   | expr '-' expr {$$=new_formula(8,$1,$3);}
   | expr '*' expr {$$=new_formula(9,$1,$3);}
   | expr '/' expr {$$=new_formula(10,$1,$3);}
   | expr '%' expr {$$=new_formula(11,$1,$3);}
   | expr MOD expr {$$=new_formula(11,$1,$3);}
   | '-' expr %prec UMINUS {$$=new_formula(12,$2,NULL);}
   | expr ANDOP expr {$$=new_formula(13,$1,$3);}
   | expr OR expr {$$=new_formula(14,$1,$3);}
   | expr COMPARISON expr {
    //$$=new FORMULA_NODE;//do not must
    $$=new_formula($2,$1,$3);
    //std::cout<<$$->cmp<<std::endl;
    //std::cout<<$$->l->name<<std::endl;
  }
   | NOT expr {$$=new_formula(15,$2,NULL);}
   | '!' expr {$$=new_formula(15,$2,NULL);}
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

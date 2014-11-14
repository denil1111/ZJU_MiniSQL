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
//#include "error.h"

Parse_Node * root_stmt;

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
  bool boolval;

  std::string * str;

  std::vector<std::string> *string_list;
  std::vector< std::vector<std::string> > *string_vec;
  Parse_Node* node_p;

  std::vector<Parse_Node*> *node_list;

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
%type <node_p> drop_table_stmt 
%type <node_p> drop_db_stmt 
%type <node_p> drop_index_stmt

%type <node_p> create_table_stmt
%type <node_list> create_sp_list
%type <node_p> create_sp
%type <string_list> column_list


%type <node_p> create_definition
%type <intval> opt_length
%type <intval> data_type
%type <boolval> column_atts 
%type <node_list> create_col_list 

%type <node_p> stmt
%type <node_list> stmt_list

%start stmt_list

%%

stmt_list: stmt ';' {root_stmt=$1;YYACCEPT;}
    ;

//statement
stmt: select_stmt {
        $$=new SELECT_NODE;*$$=*$1;
        //std::cout<<"in select stmt"<<std::endl;
        //std::cout<<$$->select_list[0]<<std::endl;
    }
   | delete_stmt {$$=new DELETE_NODE;*$$=*$1;}
   | insert_stmt {$$=new INSERT_NODE;*$$=*$1;}
   | create_database_stmt {$$=new CREATE_DATABASE_NODE;*$$=*$1;}
   | create_table_stmt {
        $$=new CREATE_TABLE_NODE;
        *$$=*$1;
        //std::cout<<$$->attr_list[0]->attr_name<<std::endl;
        //std::cout<<$$->attr_list[0]->char_length<<std::endl;
        //std::cout<<$$->sp_list[0]->key_type<<std::endl;
        //std::cout<<$$->sp_list[0]->key_attr[0]<<std::endl;
   }
   | create_index_stmt {$$=new CREATE_INDEX_NODE;*$$=*$1;}
   | drop_table_stmt {$$=new DROP_TABLE_NODE;*$$=*$1;}
   | drop_db_stmt {$$=new DROP_DATABASE_NODE;*$$=*$1;}
   | drop_index_stmt {$$=new DROP_INDEX_NODE;*$$=*$1;}
   ;
   
//select
select_stmt: SELECT select_expr_list
     FROM NAME
     opt_where {
      $$=new SELECT_NODE;
      $$->select_list=*$2;
      free($2);

      //std::cout<<$$->select_list[0]<<std::endl;
      //std::cout<<$$->select_list[1]<<std::endl;
      //std::cout<<<<std::endl;

      //std::cout<<$4->select_tbl_list[0]<<std::endl;
      //std::cout<<$4->select_tbl_list[1]<<std::endl;

      std::string all_s($4);NAME_NODE *n=new NAME_NODE(all_s);
      $$->select_from_clause.push_back(n);
      std::cout<<$$->select_from_clause[0]->kind<<std::endl;
      std::cout<<$$->select_from_clause[0]->name<<std::endl;
      free($4);
      //std::cout<<$$->select_tbl_list[0]<<std::endl;
      //std::cout<<$$->select_tbl_list[1]<<std::endl;
      

      //std::cout<<$5->cmp<<std::endl;
      if($5==NULL){
        //std::cout<<"null"<<std::endl;
        $$->select_where_clause=NULL;
      }
      else{
        $$->select_where_clause=$5;
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
        $$->select_from_clause.push_back($5);
        std::cout<<$$->select_from_clause[0]->kind<<std::endl;
        std::cout<<$$->select_from_clause[0]->select_list[0]<<std::endl;

        if($7==NULL)
        {
            //std::cout<<"null"<<std::endl;
            $$->select_where_clause=NULL;
        }
        else
        {
            $$->select_where_clause=$7;
        }

     }
    ;

opt_where: {$$=NULL;} /* nil */ 
   | WHERE expr {$$=$2;
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


//delete
delete_stmt: DELETE FROM NAME opt_where
    {
      $$=new DELETE_NODE;

      $$->del_tbl_name=std::string($3);
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
    | DELETE '*' FROM NAME {
        $$=new DELETE_NODE;

        $$->del_tbl_name=std::string($4);
        free($4);

        //std::cout<<$$->del_tbl_list[0]<<std::endl;

        $$->star_flag=true;
    }
    ;

//insert statement
insert_stmt: INSERT INTO NAME VALUES insert_vals_list
    {
        $$=new INSERT_NODE;

        $$->insert_tbl_name=std::string($3);
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

//create database
create_database_stmt: 
     CREATE DATABASE NAME {
        $$=new CREATE_DATABASE_NODE;
        $$->create_db_name=std::string($3);
        //std::cout<<$$->db_name<<std::endl;
        free($3);
    }
   ;

//create table
create_table_stmt: CREATE TABLE NAME
   '(' create_col_list ','create_sp_list ')'  
    {
        $$=new CREATE_TABLE_NODE; 
        $$->create_tbl_name=std::string($3);

        if($5->size()>32)
        {
          yyerror("More than 32 attributes!");
          exit(0);
        }
        $$->attr_list=*$5;
        //std::cout<<$$->attr_list[0]->attr_name<<std::endl;
        //std::cout<<$$->attr_list[0]->char_length<<std::endl;

        $$->sp_list=*$7;
        //std::cout<<$$->sp_list[0]->key_type<<std::endl;
        //std::cout<<$$->sp_list[0]->key_attr[0]<<std::endl;

        free($7);
        free($5);
    }
    | CREATE TABLE NAME '(' create_col_list ')'  
    {
        $$=new CREATE_TABLE_NODE; 
        $$->create_tbl_name=std::string($3);

        if($5->size()>32)
        {
          yyerror("More than 32 attributes!");
          exit(0);
        }
        $$->attr_list=*$5;
        //std::cout<<$$->attr_list[0]->attr_name<<std::endl;
        //std::cout<<$$->attr_list[0]->char_length<<std::endl;

        free($5);
    }
   ;

create_sp_list: create_sp 
        {
            $$=new std::vector<Parse_Node *>;
            $$->push_back($1);
        }
    | create_sp_list ',' create_sp {$$->push_back($3);}  
    ; 

create_sp: PRIMARY KEY '(' column_list ')'    
    {
        $$=new SPECIAL_ATTR_NODE;
        $$->key_type=0;
        $$->key_attr=*$4;
        emit("primary key %d",$$->key_attr.size());
        if($$->key_attr.size()>1)
        {
          yyerror("More than 2 primary keys");
          exit(0);
        }
        free($4);
    }
    | KEY '(' column_list ')'            
    {
        $$=new SPECIAL_ATTR_NODE;
        $$->key_type=1;
        $$->key_attr=*$3;
        free($3);
    }
    | INDEX '(' column_list ')'          
    {   
        $$=new SPECIAL_ATTR_NODE;
        $$->key_type=2;
        $$->key_attr=*$3;
        free($3);
    }
    ;

column_list: NAME {$$=new std::vector<std::string>;$$->push_back($1); }
  | column_list ',' NAME  {$$->push_back($3); }
  ;


create_col_list: create_definition 
    {
        $$=new std::vector<Parse_Node *>;
        $$->push_back($1);
    }
    | create_col_list ',' create_definition {$$->push_back($3);}
    ;

create_definition: NAME data_type opt_length column_atts
            {
                $$=new ATTR_NODE;
                $$->attr_name=std::string($1);
                $$->type=$2;
                $$->char_length=$3;
                $$->unique_flag=$4;
            }
    ;

column_atts:{$$=false;}
    | column_atts UNIQUE {$$=true;}
    ;

opt_length:{$$=0;}
   | '(' INTNUM ')' 
    {   
      if($2>=1&&$2<=255)
      {
        $$ = $2; 
      }
      else
      {
        yyerror("%d is out of char range(1~255)!",$2);
        exit(0);
        //Error error(6);
        //throw error;
      }
    }
   ;

data_type: INT { $$ = 0; }
   | FLOAT { $$ = 1; }
   | VARCHAR { $$ = 2; }
   ;



//create index
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

//drop db
drop_db_stmt:DROP DATABASE NAME {
        $$=new DROP_DATABASE_NODE;
        $$->drop_db_name=std::string($3);
        //std::cout<<$$->drop_db_name<<std::endl;
        free($3);
    }
    ; 

//drop table
drop_table_stmt:DROP TABLE NAME {
        $$=new DROP_TABLE_NODE;
        $$->drop_tbl_name=std::string($3);
        //std::cout<<$$->drop_tbl_name<<std::endl;
        free($3);
    }
    ;  

//drop index
drop_index_stmt:DROP INDEX NAME ON NAME {
        $$=new DROP_INDEX_NODE;
        $$->drop_index_name=std::string($3);
        $$->drop_index_tbl=std::string($5);
        //std::cout<<$$->drop_index_name<<std::endl;
    }
    ; 

//expressions
expr: NAME          {std::string all_s($1);$$=new NAME_NODE(all_s);
    //std::cout<<$$->name<<std::endl;
    }
   | STRING        {std::string all_s($1);$$=new NAME_NODE(all_s);}
   | INTNUM        {$$=new INT_NODE($1);
    //std::cout<<$$->int_num<<std::endl;
    }
   | APPROXNUM     {$$=new FLOAT_NODE($1);}
   ;

expr: expr '+' expr {$$=new FORMULA_NODE(7,$1,$3);}
   | expr '-' expr {$$=new FORMULA_NODE(8,$1,$3);}
   | expr '*' expr {$$=new FORMULA_NODE(9,$1,$3);}
   | expr '/' expr {$$=new FORMULA_NODE(10,$1,$3);}
   | expr '%' expr {$$=new FORMULA_NODE(11,$1,$3);}
   | expr MOD expr {$$=new FORMULA_NODE(11,$1,$3);}
   | '-' expr %prec UMINUS {$$=new FORMULA_NODE(12,$2,NULL);}
   | expr ANDOP expr {$$=new FORMULA_NODE(13,$1,$3);}
   | expr OR expr {$$=new FORMULA_NODE(14,$1,$3);}
   | expr COMPARISON expr {
    //$$=new FORMULA_NODE;//do not must
    $$=new FORMULA_NODE($2,$1,$3);
    //std::cout<<$$->cmp<<std::endl;
    //std::cout<<$$->l->name<<std::endl;
  }
   | NOT expr {$$=new FORMULA_NODE(15,$2,NULL);}
   | '!' expr {$$=new FORMULA_NODE(15,$2,NULL);}
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


Parse_Node *
yyy_parse()
{
  if(!yyparse())
    printf("SQL parse worked\n");
  else
    printf("SQL parse failed\n");
  return root_stmt;
}  

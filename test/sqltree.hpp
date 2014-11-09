//
//  main.cpp
//  test for c++
//
//  Created by 逸婷 李 on 14-9-17.
//  Copyright (c) 2014年 逸婷 李. All rights reserved.
//
#ifndef SQLTREE
#define SQLTREE
#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
// using namespace std;

enum nodekind{
    //    const node
    N_INT,
    N_FLOAT,
    N_STRING,
    N_NAME,
    
    N_FORMULA,
    
    N_SELECT,
    N_DELETE,
    N_INSERT,
    N_CREATE_DATABASE,
    N_DROP_DATABASE,
    N_DROP_TABLE,
    N_DROP_INDEX,
    N_CREATE_INDEX,

    N_NULL
};

struct node{
    nodekind kind;

    //int
    int int_num;

    //string
    std::string s;

    //name
    std::string name;

    //float
    float float_num;

    //formula
    int cmp;
    struct node * l;
    struct node * r;

    //delete
    std::vector <std::string> del_tbl_list;
    int star_flag=0;
    node * del_where_clause;

    //select
    std::vector <std::string> select_list;
    std::vector <std::string> select_tbl_list;
    node * nested_tbl;
    node * select_where_clause;

    //insert
    std::vector <std::vector<std::string> > insert_value_list;
    std::vector <std::string> insert_tbl_list;

    //create database
    std::string create_db_name;

    //drop database
    std::string drop_db_name;

    //drop table
    std::string drop_tbl_name;

    //drop index
    std::string drop_index_name;
    std::string drop_index_tbl;

    //create index
    std::string create_index_name;
    std::string create_index_tbl;
    std::string create_index_attr;



};

struct INT_NODE:public node{
    INT_NODE(){kind=N_INT;}
};

struct NAME_NODE:public node{
    NAME_NODE(){kind=N_NAME;}
};

struct STRING_NODE:public node{
    STRING_NODE(){kind=N_STRING;}
};

struct FLOAT_NODE:public node{
    FLOAT_NODE(){kind=N_FLOAT;}
};

/* query node */
struct SELECT_NODE:public node{
    SELECT_NODE(){kind=N_SELECT;}
};

/* delete node */
struct DELETE_NODE:public node{
    DELETE_NODE(){kind=N_DELETE;}
};

struct INSERT_NODE:public node{
    INSERT_NODE(){kind=N_INSERT;}
};

struct CREATE_DATABASE_NODE:public node{
    CREATE_DATABASE_NODE(){kind=N_CREATE_DATABASE;}
};

struct DROP_DATABASE_NODE:public node{
    DROP_DATABASE_NODE(){kind=N_DROP_DATABASE;}
};

struct DROP_TABLE_NODE:public node{
    DROP_TABLE_NODE(){kind=N_DROP_TABLE;}
};

struct DROP_INDEX_NODE:public node{
    DROP_INDEX_NODE(){kind=N_DROP_INDEX;}
};

struct CREATE_INDEX_NODE:public node{
    CREATE_INDEX_NODE(){kind=N_CREATE_INDEX;}
};


// struct ATTR_NODE{
//     string attr_name;
//     string type;
//     int char_length=0;
//     bool unique_flag=false;
//     bool key_index_flag=false;
//     bool primary_key=false;
// };

struct FORMULA_NODE:public node{
    FORMULA_NODE(){kind=N_FORMULA;}
};

FORMULA_NODE *
new_formula(int cmp, node *l, node *r);

INT_NODE*
new_int(int a);

NAME_NODE *
new_name(std::string s);

STRING_NODE *
new_string(std::string s);

FLOAT_NODE *
new_float(float a);

#endif
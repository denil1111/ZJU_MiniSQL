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
    N_ATTR,
    
    N_SELECT,
    N_DELETE,
    N_INSERT,
    N_SPECIAL_ATTR,
    N_CREATE_DATABASE,
    N_CREATE_TABLE,
    N_CREATE_INDEX,
    N_DROP_DATABASE,
    N_DROP_TABLE,
    N_DROP_INDEX,
    N_NULL
};

struct Parse_Node{
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
    struct Parse_Node * l;
    struct Parse_Node * r;

    //delete
    std::vector <std::string> del_tbl_list;
    bool star_flag=false;
    Parse_Node * del_where_clause;

    //select
    std::vector <std::string> select_list;
    std::vector <std::string> select_tbl_list;
    Parse_Node * nested_tbl;
    Parse_Node * select_where_clause;

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

    //create table
    std::string create_tbl_name;
    std::vector<Parse_Node *> attr_list;
    std::vector<Parse_Node *> sp_list;

    //attr
    std::string attr_name;
    std::string type;//int:1,float:2,varchar:3
    int char_length;
    bool unique_flag=false;

    //sp
    int key_type;
    std::vector<std::string> key_attr;

    ~Parse_Node();

};

struct INT_NODE:public Parse_Node
{
    INT_NODE(int a)
    {
        kind=N_INT;
        this->int_num=a;
    }
};

struct NAME_NODE:public Parse_Node
{
    NAME_NODE(std::string s)
    {
        kind=N_NAME;
        this->name=s;
    }
};

struct STRING_NODE:public Parse_Node
{
    STRING_NODE(std::string s)
    {
        kind=N_STRING;
        this->s=s;
    }
};

struct FLOAT_NODE:public Parse_Node
{
    FLOAT_NODE(float a)
    {
        kind=N_FLOAT;
        this->float_num=a;
    }
};

/* query node */
struct SELECT_NODE:public Parse_Node
{
    SELECT_NODE()
    {
        kind=N_SELECT;
    }
};

/* delete node */
struct DELETE_NODE:public Parse_Node
{
    DELETE_NODE()
    {
        kind=N_DELETE;
    }
};

struct INSERT_NODE:public Parse_Node
{
    INSERT_NODE()
    {
        kind=N_INSERT;
    }
};

struct CREATE_DATABASE_NODE:public Parse_Node
{
    CREATE_DATABASE_NODE()
    {
        kind=N_CREATE_DATABASE;
    }
};

struct DROP_DATABASE_NODE:public Parse_Node
{
    DROP_DATABASE_NODE()
    {
        kind=N_DROP_DATABASE;
    }
};

struct DROP_TABLE_NODE:public Parse_Node
{
    DROP_TABLE_NODE()
    {
        kind=N_DROP_TABLE;
    }
};

struct DROP_INDEX_NODE:public Parse_Node{
    DROP_INDEX_NODE()
    {
        kind=N_DROP_INDEX;
    }
};

struct CREATE_INDEX_NODE:public Parse_Node{
    CREATE_INDEX_NODE()
    {
        kind=N_CREATE_INDEX;
    }
};
struct ATTR_NODE:public Parse_Node{
    ATTR_NODE()
    {
        kind=N_ATTR;
    }
};

struct SPECIAL_ATTR_NODE:public Parse_Node{
    SPECIAL_ATTR_NODE()
    {
        kind=N_SPECIAL_ATTR;
    }
};

struct CREATE_TABLE_NODE:public Parse_Node{
    CREATE_TABLE_NODE()
    {
        kind=N_CREATE_TABLE;

    }
};



struct FORMULA_NODE:public Parse_Node{
    FORMULA_NODE(int cmp, Parse_Node *l, Parse_Node *r)
    {
        kind=N_FORMULA;
        this->cmp=cmp;
        this->l = l;
        this->r = r;
    }
};


class Interpreter
{  
private:
    Parse_Node * plan_tree;
public:
    Interpreter(){}
    void run_parser();
};

#endif
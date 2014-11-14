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
#include "catalog.h"
// using namespace std;

enum nodekind{
    //    const node
    N_INT,
    N_FLOAT,
    N_STRING,
    N_NAME,
    N_FORMULA,
    N_ATTR,
    N_SPECIAL_ATTR,

    N_SELECT,
    N_DELETE,
    N_INSERT,
    N_CREATE_DATABASE,
    N_CREATE_TABLE,
    N_CREATE_INDEX,
    N_DROP_DATABASE,
    N_DROP_TABLE,
    N_DROP_INDEX,
};

class Parse_Node{
public:
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
    class Parse_Node * expr_l;
    class Parse_Node * expr_r;

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
    std::string insert_tbl_name;

    //create database
    std::string create_db_name;

    //drop database
    std::string drop_db_name;

    //drop table
    std::string drop_tbl_name;

    //drop index
    std::string drop_index_attr;
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
    int type;//int:1,float:2,varchar:3
    int char_length;
    bool unique_flag=false;

    //sp
    int key_type;
    std::vector<std::string> key_attr;

    virtual void run();
    ~Parse_Node();

};

class INT_NODE:public Parse_Node
{
public:
    INT_NODE(int a)
    {
        kind=N_INT;
        this->int_num=a;
    }
};

class NAME_NODE:public Parse_Node
{
public:
    NAME_NODE(std::string s)
    {
        kind=N_NAME;
        this->name=s;
    }
};

class STRING_NODE:public Parse_Node
{
public:
    STRING_NODE(std::string s)
    {
        kind=N_STRING;
        this->s=s;
    }
};

class FLOAT_NODE:public Parse_Node
{
public:
    FLOAT_NODE(float a)
    {
        kind=N_FLOAT;
        this->float_num=a;
    }
};

class ATTR_NODE:public Parse_Node
{
public:
    ATTR_NODE()
    {
        kind=N_ATTR;
    }
};

class SPECIAL_ATTR_NODE:public Parse_Node
{
public:
    SPECIAL_ATTR_NODE()
    {
        kind=N_SPECIAL_ATTR;
    }
};


class FORMULA_NODE:public Parse_Node
{
public:
    FORMULA_NODE(int cmp, Parse_Node *l, Parse_Node *r)
    {
        kind=N_FORMULA;
        this->cmp=cmp;
        this->expr_l = l;
        this->expr_r = r;
    }
};

/* query node */
class SELECT_NODE:public Parse_Node
{
public:
    SELECT_NODE()
    {
        kind=N_SELECT;
    }
    // void run();
};

/* delete node */
class DELETE_NODE:public Parse_Node
{
public:
    DELETE_NODE()
    {
        kind=N_DELETE;
    }
    // void run();
};

class INSERT_NODE:public Parse_Node
{
public:
    INSERT_NODE()
    {
        kind=N_INSERT;
    }
    void run();
};

class CREATE_DATABASE_NODE:public Parse_Node
{
public:
    CREATE_DATABASE_NODE()
    {
        kind=N_CREATE_DATABASE;
    }
    // void run();
};

class CREATE_TABLE_NODE:public Parse_Node
{
public:
    CREATE_TABLE_NODE()
    {
        kind=N_CREATE_TABLE;
    }
    void run();
};

class CREATE_INDEX_NODE:public Parse_Node
{
public:
    CREATE_INDEX_NODE()
    {
        kind=N_CREATE_INDEX;
    }
    void run();
};

class DROP_DATABASE_NODE:public Parse_Node
{
public:
    DROP_DATABASE_NODE()
    {
        kind=N_DROP_DATABASE;
    }
    // void run();
};

class DROP_TABLE_NODE:public Parse_Node
{
public:
    DROP_TABLE_NODE()
    {
        kind=N_DROP_TABLE;
    }
    void run();
};

class DROP_INDEX_NODE:public Parse_Node
{
public:
    DROP_INDEX_NODE()
    {
        kind=N_DROP_INDEX;
    }
    void run();
};



class Interpreter
{  
private:
    Parse_Node * plan_tree;
public:
    Interpreter(){}
    void run_parser();
    void run_sql();
};

#endif
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
#include "tinyxml.h"
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

    static Catalog *catalog;

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
    std::string del_tbl_name;
    bool star_flag=false;
    Parse_Node * del_where_clause;

    //select
    std::vector <std::string> select_list;
    std::vector <Parse_Node *> select_from_clause;
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
    int type;//int:1,float:2,varchar:3
    int char_length;
    bool unique_flag=false;

    //sp
    int key_type;
    std::vector<std::string> key_attr;

    virtual void run();
    // virtual bool logic_calc();
    // virtual int arith_calc();
    // virtual void comp_calc();
    virtual ~Parse_Node(){}

};

class INT_NODE:public Parse_Node
{
public:
    INT_NODE(int a)
    {
        kind=N_INT;
        this->int_num=a;
        // catalog.read_file();
    }
};

class NAME_NODE:public Parse_Node
{
public:
    NAME_NODE(std::string s)
    {
        kind=N_NAME;
        this->name=s;
        // catalog.read_file();
    }
};

class STRING_NODE:public Parse_Node
{
public:
    STRING_NODE(std::string s)
    {
        kind=N_STRING;
        this->s=s;
        // catalog.read_file();
    }
};

class FLOAT_NODE:public Parse_Node
{
public:
    FLOAT_NODE(float a)
    {
        kind=N_FLOAT;
        this->float_num=a;
        // catalog.read_file();
    }
};

class ATTR_NODE:public Parse_Node
{
public:
    ATTR_NODE()
    {
        kind=N_ATTR;
        // catalog.read_file();
    }
};

class SPECIAL_ATTR_NODE:public Parse_Node
{
public:
    SPECIAL_ATTR_NODE()
    {
        kind=N_SPECIAL_ATTR;
        // catalog.read_file();
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
        // catalog.read_file();
    }
    ~FORMULA_NODE();
};

/* query node */
class SELECT_NODE:public Parse_Node
{
public:
    SELECT_NODE()
    {
        kind=N_SELECT;
        // catalog.read_file();
    }
    void run();
    ~SELECT_NODE(); 
};

/* delete node */
class DELETE_NODE:public Parse_Node
{
public:
    DELETE_NODE()
    {
        kind=N_DELETE;
        // catalog.read_file();
    }
    void run();
};

class INSERT_NODE:public Parse_Node
{
public:
    INSERT_NODE()
    {
        kind=N_INSERT;
        // catalog.read_file();
    }
    void run();
};

class CREATE_DATABASE_NODE:public Parse_Node
{
public:
    CREATE_DATABASE_NODE()
    {
        kind=N_CREATE_DATABASE;
        // catalog.read_file();
    }
    // void run();
};

class CREATE_TABLE_NODE:public Parse_Node
{
public:
    CREATE_TABLE_NODE()
    {
        kind=N_CREATE_TABLE;
        // catalog.read_file();
    }
    void run();
    ~CREATE_TABLE_NODE();
};

class CREATE_INDEX_NODE:public Parse_Node
{
public:
    CREATE_INDEX_NODE()
    {
        kind=N_CREATE_INDEX;
        // catalog.read_file();
    }
    void run();
};

class DROP_DATABASE_NODE:public Parse_Node
{
public:
    DROP_DATABASE_NODE()
    {
        kind=N_DROP_DATABASE;
        // catalog.read_file();
    }
    // void run();
};

class DROP_TABLE_NODE:public Parse_Node
{
public:
    DROP_TABLE_NODE()
    {
        kind=N_DROP_TABLE;
        // catalog.read_file();
    }
    void run();
};

class DROP_INDEX_NODE:public Parse_Node
{
public:
    DROP_INDEX_NODE()
    {
        kind=N_DROP_INDEX;
        // catalog.read_file();
    }
    void run();
};


class Interpreter
{  
private:
    Parse_Node * plan_tree;
public:
    Interpreter()
    {
    }
    void run_parser();
    void run_sql();
    ~Interpreter(){delete plan_tree;}
};

#endif
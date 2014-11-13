#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
#include "sqltree.hpp"
#include "sql.hpp"
#include "buffer.h"
#include "catalog.h"
#include "error.h"
#include "index.h"
#include "record.h"
#include "storage.h"

// using namespace std;
Parse_Node::~Parse_Node()
{
    for (int i=0;i<attr_list.size();i++){
            delete attr_list[i];
        }
        for (int i=0;i<sp_list.size();i++){
            delete sp_list[i];
        }
        delete select_where_clause;
        delete expr_l;
        delete expr_r;
}
void Interpreter::run_parser()
{
    Parse_Node *yyy_parse();
    plan_tree=yyy_parse();
    std::cout<<"in run_parser"<<std::endl;
    std::cout<<plan_tree->kind<<std::endl;
    std::cout<<plan_tree->attr_list[0]->attr_name<<std::endl;
}

void Interpreter::run_sql()
{
    plan_tree->run();
}

void CREATE_TABLE_NODE::run()
{
    std::cout<<"in CREATE_TABLE_NODE.run()"<<std::endl;
    Table_info table;
    table.table_name=create_tbl_name;
    table.database="zju";
    table.tuple_size=0;

    Attribute attribute;

    for(int i=0;i<attr_list.size();i++)
    {
        attribute.attribute_name=attr_list[i]->attr_name;

        std::cout<<attribute.attribute_name<<std::endl;

        attribute.type=(attr_list[i]->type==0?INT:(attr_list[i]->type==1?FLOAT:STRING));
        attribute.size=attribute.type==2?attr_list[i]->char_length:4;
        attribute.is_only=attr_list[i]->unique_flag;
        table.attribute_list.push_back(attribute);
        table.tuple_size+=attribute.size;
    }

    std::string pkey="";
    std::string key="";
    std::string index="";

    for(int i=0;i<sp_list.size();i++)
    {
        if(sp_list[0]->key_type==0)
        {
            pkey=sp_list[i]->key_attr[0];
        }
        if(sp_list[0]->key_type==1)
        {
            key=sp_list[i]->key_attr[0];
        }
        if(sp_list[0]->key_type==2)
        {
            index=sp_list[i]->key_attr[0];
        }  
    }

    std::cout<<pkey<<std::endl;

    if(!pkey.empty())
    {
        for(int i=0;i<table.attribute_list.size();i++)
        {
            if(pkey==table.attribute_list[i].attribute_name)
            {
                table.attribute_list[i].is_primary=1;
                table.attribute_list[i].has_index=1;
                table.attribute_list[i].is_only=1;
                break;
            }
        }
    }

    if(!key.empty())
    {
        for(int i=0;i<table.attribute_list.size();i++)
        {
            if(key==table.attribute_list[i].attribute_name)
            {
                table.attribute_list[i].has_index=1;
                table.attribute_list[i].is_only=1;
                break;
            }
        }
    }

    if(!index.empty())
    {
        for(int i=0;i<table.attribute_list.size();i++)
        {
            if(index==table.attribute_list[i].attribute_name)
            {
                table.attribute_list[i].has_index=1;
                table.attribute_list[i].is_only=1;
                break;
            }
        }
    }
    std::cout<<table.attribute_list[0].attribute_name<<std::endl;
    std::cout<<table.attribute_list[0].is_primary<<std::endl;
    std::cout<<"out of node"<<std::endl;
}


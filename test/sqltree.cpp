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
Catalog * Parse_Node::catalog;
// using namespace std;
FORMULA_NODE::~FORMULA_NODE()
{
    delete expr_l;
    delete expr_r;
}

SELECT_NODE::~SELECT_NODE()
{
    delete select_where_clause;
}

CREATE_TABLE_NODE::~CREATE_TABLE_NODE()
{
    for (int i=0;i<attr_list.size();i++)
    {
        delete attr_list[i];
    }
    for (int i=0;i<sp_list.size();i++)
    {
        delete sp_list[i];
    }
}

void Parse_Node::run()
{
    std::cout<<"In Parse_Node run()"<<std::endl;
}

void Interpreter::run_parser()
{
    Parse_Node *yyy_parse();
    plan_tree=yyy_parse();
    std::cout<<"in run_parser"<<std::endl;
    // std::cout<<plan_tree->kind<<std::endl;
    // std::cout<<plan_tree->attr_list[0]->attr_name<<std::endl;
}

void Interpreter::run_sql()
{
    plan_tree->run();
}

// void CREATE_DATABASE_NODE::run()
// {
//     if(!is_database(create_db_name))
//     {
//         Catalog catalog;
//         catalog->create_database(create_db_name);

//         //implement
//     }
//     else
//     {
//         Error error(4);
//         throw error;
//     }
// }

// void DROP_DATABASE_NODE::run()
// {
//     if(is_database(drop_db_name))
//     {
//         Catalog catalog;
//         catalog->drop_database(drop_db_name);

//         //implement
//     }
//     else
//     {
//         Error error(1);
//         throw error;
//     }
// }
void SELECT_NODE::run()
{
    if(select_from_clause[0]->kind==N_NAME)
    {
        if(catalog->is_table("ZJU",select_from_clause[0]->name))
        {
            std::cout<<"inside select"<<std::endl;

        }
        else
        {
            Error error(2);
            throw error;
        }
    }
    else//nested
    {
        std::cout<<"inside nested select"<<std::endl;
    }
    
}

void DELETE_NODE::run()
{
    if(catalog->is_table("ZJU",del_tbl_name))
    {
       if(star_flag)
        {
            Record record;
            Table_info table;
            table=catalog->get_table("ZJU",del_tbl_name);
            record.delete_all_tuple(table);
        } 
        else
        {
            std::cout<<"inside delete"<<std::endl;
        }
    }
    else
    {
        Error error(2);
        throw error;
    }
    
}

void CREATE_TABLE_NODE::run()
{

    std::cout<<"in CREATE_TABLE_NODE.run()"<<std::endl;

    if(!catalog->is_table("ZJU",create_tbl_name))
    {
        Table_info table;
        Record record;

        table.table_name=create_tbl_name;
        table.database="ZJU";
        table.tuple_size=0;

        Attribute attribute;

        for(int i=0;i<attr_list.size();i++)
        {
            attribute.attribute_name=attr_list[i]->attr_name;

            std::cout<<attribute.attribute_name<<std::endl;

            attribute.type=(attr_list[i]->type==0?SQL_INT:(attr_list[i]->type==1?SQL_FLOAT:SQL_STRING));
            attribute.size=attr_list[i]->type==2?attr_list[i]->char_length:4;
            attribute.is_only=attr_list[i]->unique_flag;
            table.attribute_list.push_back(attribute);
            table.tuple_size+=attribute.size;
        }

        std::cout<<table.tuple_size<<std::endl;

        if(!sp_list.empty())
        {
            std::string pkey="";
            std::string key="";
            std::string index="";
            int pkey_flag=0;

            for(int i=0;i<sp_list.size();i++)
            {
                if(sp_list[0]->key_type==0)
                {
                    pkey=sp_list[i]->key_attr[0];
                    pkey_flag++;
                    for(int i=0;i<table.attribute_list.size();i++)
                    {
                        if(pkey==table.attribute_list[i].attribute_name)
                        {
                            table.attribute_list[i].is_primary=1;
                        }
                    }
                }
            }

            if(pkey_flag>1)
            {
                //printf("error7\n");
                Error error(7);
                throw error;
                // std::cout<<"More than 2 primary keys"<<std::endl;
                // exit(0);
            }
        }
        
        // std::cout<<table.attribute_list[0].attribute_name<<std::endl;
        // std::cout<<table.attribute_list[0].is_primary<<std::endl;

        //implement
        catalog->create_table("ZJU",table);//change the catalog

        if(!sp_list.empty())
        {
            std::string pkey="";
            std::string key="";
            std::string index="";
            int pkey_flag=0;

            for(int i=0;i<sp_list.size();i++)
            {
                if(sp_list[0]->key_type==0)
                {
                    pkey=sp_list[i]->key_attr[0];
                    pkey_flag++;
                    for(int i=0;i<table.attribute_list.size();i++)
                    {
                        if(pkey==table.attribute_list[i].attribute_name)
                        {
                            Index_info index_info;
                            index_info.index_name=table.table_name+"_"+table.attribute_list[i].attribute_name;

                            std::cout<<index_info.index_name<<std::endl;

                            index_info.database_name="ZJU";
                            index_info.table_name=table.table_name;
                            index_info.attribute_name=table.attribute_list[i].attribute_name;
                            catalog->create_index(index_info);
                            //implement
                        }
                    }
                }
                if(sp_list[0]->key_type==1)
                {
                    key=sp_list[i]->key_attr[0];
                    for(int i=0;i<table.attribute_list.size();i++)
                    {
                        if(key==table.attribute_list[i].attribute_name)
                        {
                            Index_info index_info;
                            index_info.index_name=table.table_name+"_"+table.attribute_list[i].attribute_name;

                            std::cout<<index_info.index_name<<std::endl;

                            index_info.database_name="ZJU";
                            index_info.table_name=table.table_name;
                            index_info.attribute_name=table.attribute_list[i].attribute_name;
                            std::cout<<"befor create index"<<std::endl;
                            catalog->create_index(index_info);
                            //implement
                        }
                    }
                }
                if(sp_list[0]->key_type==2)
                {
                    index=sp_list[i]->key_attr[0];
                    for(int i=0;i<table.attribute_list.size();i++)
                    {
                        if(index==table.attribute_list[i].attribute_name)
                        {
                            Index_info index_info;
                            index_info.index_name=table.table_name+"_"+table.attribute_list[i].attribute_name;

                            std::cout<<index_info.index_name<<std::endl;

                            index_info.database_name="ZJU";
                            index_info.table_name=table.table_name;
                            index_info.attribute_name=table.attribute_list[i].attribute_name;
                            catalog->create_index(index_info);
                            //implement
                        }
                    }
                }  
            }
        }
        record.create_table(table);//change the storage
    }
    else
    {
        printf("error3\n");
        Error error(3);
        throw error;
    }
    
    //std::cout<<"out of node"<<std::endl;

    /*problem:1.调用函数lib error 2.catalog createtable 3.index 如何建立 4.index() index()写法可以么*/
}

void DROP_TABLE_NODE::run()
{
    if(catalog->is_table("ZJU",drop_tbl_name))
    {
        Record record;
        Table_info table;

        table=catalog->get_table("ZJU",drop_tbl_name);
        catalog->drop_table("ZJU",drop_tbl_name);

        //implement
        record.drop_table(table);
    }
    else
    {
        //printf("error2\n");
        Error error(2);
        throw error;
    } 
}

void CREATE_INDEX_NODE::run()
{
    int flag=0;
    if(catalog->is_table("ZJU",create_index_tbl))
    {
        Table_info table=catalog->get_table("ZJU",create_index_tbl);
        for (int i = 0; i < table.attribute_list.size(); i++)
        {
            if(create_index_attr==table.attribute_list[i].attribute_name)
            {
                if(table.attribute_list[i].is_only==1&&table.attribute_list[i].has_index==0)
                {
                    Index_info index_info;
                    index_info.database_name="ZJU";
                    index_info.index_name=create_index_name;
                    index_info.table_name=create_index_tbl;
                    index_info.attribute_name=create_index_attr;
                    catalog->create_index(index_info);
                    flag=1;
                    break;
                }
                else
                {
                    Error error(8);
                    throw error;
                }
            }
        }
        if(flag==0)
        {
            Error error(10);
            throw error;
        }
    }
    else
    {
        Error error(2);//"table does not exist"
        throw error;
    }
}

void DROP_INDEX_NODE::run()
{
    if(catalog->is_table("ZJU",drop_index_tbl))
    {
        if(catalog->is_index(drop_index_name))
        {
            std::cout<<drop_index_name<<std::endl;
            catalog->drop_index(drop_index_name);
        }
        else
        {
            Error error(9);
            throw error;
        }
    }
    else
    {
        Error error(2);//"table does not exist"
        throw error;
    }
}

void INSERT_NODE::run()
{
    std::cout<<"in INSERT_NODE.run()"<<std::endl;

    if(catalog->is_table("ZJU",insert_tbl_name))
    {
        Record record;
        Table_info table;
        Tuple_info tuple_info;
        table=catalog->get_table("ZJU",insert_tbl_name);

        // std::cout<<table.table_name<<std::endl;
        // std::cout<<table.tuple_size<<std::endl;
        // std::cout<<table.database<<std::endl;
        // for(int i=0;i<table.attribute_list.size();i++)
        // {
        //     std::cout<<table.attribute_list[i].attribute_name<<std::endl;
        //     std::cout<<table.attribute_list[i].type<<std::endl;
        //     std::cout<<table.attribute_list[i].size<<std::endl;

        // }


        for(int i=0;i<insert_value_list.size();i++)
        {
            tuple_info.info.clear();

            //std::cout<<"tuple_info_size:"<<tuple_info.info.size()<<std::endl;

            for(int j=0;j<insert_value_list[i].size();j++)
            {
                //std::cout<<insert_value_list[i][j]<<std::endl;
                tuple_info.info.push_back(insert_value_list[i][j]);
            }
            // for(int k=0;k<tuple_info.info.size();k++)
            // {
            //     std::cout<<tuple_info.info[k]<<std::endl;
            // }
            record.insert_tuple(table,tuple_info);
        }
    } 
    else                                                             
    {
        std::cout<<"Inside Error"<<std::endl;
        Error error(2);//"table does not exist"
        throw error;
    }
    //检查类型错误
}

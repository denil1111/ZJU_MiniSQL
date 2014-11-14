#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <uuid/uuid.h>
#include "sqltree.hpp"
#include "sql.hpp"
#include "buffer.h"
#include "catalog.h"
#include "error.h"
#include "index.h"
#include "record.h"
#include "storage.h"
enum type{C_NUM,C_STRING};

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

DELETE_NODE::~DELETE_NODE()
{
    delete del_where_clause;
}
// 
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
    if(select_from_clause[0]->kind!=N_SELECT)
    {
        if(catalog->is_table("ZJU",select_from_clause[0]->name))
        {
            int flag=0;
            bool select_flag=false;
            std::vector<int> v;
            Table_info table;
            Table_info temp_table;
            Address address;
            Record record;
            Tuple_info tuple_info;
            Tuple_info temp_tuple;

            uuid_t uu;
            uuid_generate( uu );
            printf("\n");
            uuid_string_t  strc;
            uuid_unparse_upper(uu,strc);

            temp_table.table_name=strc;

            std::cout<<"temp_table name:"<<temp_table.table_name<<std::endl;
            //std::cout<<<<std::endl;
            temp_table.tuple_size=0;
            temp_table.database="ZJU";

            table=catalog->get_table("ZJU",select_from_clause[0]->name);

            std::cout<<"select_from_clause[0]:"<<select_from_clause[0]->name<<std::endl;

            for (int i = 0; i <select_list.size(); i++)
            {
                //std::cout<<"wtf"<<std::endl;
                for(int j=0;i<table.attribute_list.size();j++)
                {
                    if(select_list[i]==table.attribute_list[j].attribute_name)
                    {
                        temp_table.attribute_list.push_back(table.attribute_list[i]);
                        std::cout<<"attribute:"<<table.attribute_list[i].attribute_name<<std::endl;
                        temp_table.tuple_size+=table.attribute_list[i].size;
                        v.push_back(j);
                        std::cout<<"list number:"<<j<<std::endl;
                        flag++;
                        break;
                    }
                }
            }

            //std::cout<<"temp_table size:"<<temp_table.tuple_size<<std::endl;
            
            if(flag!=select_list.size())
            {
                Error error(15);
                throw error;
            }

            record.create_table(temp_table);
            for(int i=0;i<temp_table.attribute_list.size();i++)
            {
                std::cout<<std::setw(10)<<temp_table.attribute_list[i].attribute_name;
            }
            std::cout<<"\n";

            record.get_first_tuple(table,&tuple_info,&address);

            if(select_where_clause!=NULL)
            {
                std::cout<<"in where clause"<<std::endl;
                // select_flag=select_where_clause->calc();
            }
            if(select_where_clause==NULL||select_flag==true)
            {
                for(int i=0;i<v.size();i++)
                {
                    std::cout<<std::setw(10)<<tuple_info.info[v[i]];    
                    temp_tuple.info.push_back(tuple_info.info[v[i]]);
                }
                std::cout<<"\n";
                record.insert_tuple(temp_table,temp_tuple);
            }

            while(address.address_int())
            {
                record.get_tuple(table,address,&tuple_info,&address);

                if(select_where_clause!=NULL)
                {
                    std::cout<<"in where clause"<<std::endl;
                    // select_flag=select_where_clause->calc();
                }
                if(select_where_clause==NULL||select_flag==true)
                {
                    for(int i=0;i<v.size();i++)
                    {
                        std::cout<<std::setw(10)<<tuple_info.info[v[i]];
                        temp_tuple.info.push_back(tuple_info.info[v[i]]);
                    }
                    std::cout<<"\n";
                    record.insert_tuple(temp_table,temp_tuple);
                }
            }

            record.drop_table(temp_table);
            std::cout<<"After drop temp_table"<<std::endl;
            // std::cout<<""<<std::endl;
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
    // Parse_Node * p=del_where_clause;

    if(catalog->is_table("ZJU",del_tbl_name))
    {
        Record record;
        Table_info table;
        table=catalog->get_table("ZJU",del_tbl_name);
        if(star_flag)
        {
            record.delete_all_tuple(table);
        } 
        else
        {
            std::cout<<"inside delete"<<std::endl;
            Tuple_info tuple_info;
            Address address;
            bool del_flag;

            record.get_first_tuple(table,&tuple_info,&address);

            // del_flag=del_where_clause->calc(table,tuple_info);

            if(del_flag==true)
            {
                record.delete_tuple(table,address);
            }

            while(address.address_int())
            {
                record.get_tuple(table,address,&tuple_info,&address);
                // del_flag=del_where_clause->calc(table,tuple_info);
                if(del_flag==true)
                {
                    record.delete_tuple(table,address);
                }
            }
        }
    }
    else
    {
        Error error(2);
        throw error;
    }
    
}

/*
bool FORMULA_NODE::calc()
{
    if(cmp<=14&&cmp>=12)//and or not
    {
        bool lb;
        bool rb;
        switch(cmp)
        {
            case 12:lb=expr_l->calc_bool();//and
                    rb=expr_r->calc_bool();
                    return (lb && rb);
            case 13:lb=expr_l->calc_bool();//or
                    rb=expr_r->calc_bool();
                    return (lb || rb);
            case 14:lb=expr_l->calc_bool();//not
                    return (!lb);
        }
    }
    else
    {
        if(cmp>=1&&cmp<=6)// < > <= >= != =
        {
            calc_bool();
        }
        else
        {
            Error error(13) //Invalid where clause
            throw error;
        }
    }
}

bool FLOMULA_NODE::calc_bool()
{
    type * t1;
    type * t2;

    std::stringstream ss;
    std::string s,ls,rs;

    ls=expr_l->calc_num(t1);
    rs=expr_r->calc_num(t2);

    float ln=0;
    float rn=0;

    if(cmp==3&&(*t1==*t2)&&(*t1=C_STRING))//string
    {
        return (ls==rs);
    }
    else//num
    {
        if((*t1==*t2)&&(*t1!=C_STRING))
        {
            ls>>ss;
            ss>>ln;
            rs>>ss;
            ss>>rn;
            switch(cmp):
            {
                case 1: return (ln < rn);
                case 2: return (ln > rn);
                case 3: return (ln == rn);
                case 4: return (ln != rn);
                case 5: return (ln <= rn);
                case 6: return (ln >= rn);
            }
        }
        else
        {
            Error error(14);
            throw error;
        }
    }
}

bool FLOAT_NODE::calc_bool()
{
    if(float_num!=0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool INT_NODE::calc_bool()
{
    if(int_num!=0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// bool NAME_NODE::calc_bool()
// {

// }

bool STRING_NODE::calc_bool()
{
    Error error(14);
    throw error;
}

std::string FORMULA_NODE::calc_num(type * t)
{
    std::stringstream ss;
    std::string s;

        type * t1;
        type * t2;

        std::string ls=expr_l->calc_num(t1);

        if (*t1!=C_STRING && cmp==11)
        {
            *t=C_NUM;
            (-ln)>>ss;
            ss>>s;
            return s
        }
        else
        {
            std::string rs=expr_r->calc_num(t2);

            if ((*t1==*t2)&&(*t1!=C_STRING))
            {
                float ln=0;
                float rn=0;
                ss<<ls;ss>>ln;
                ss<<rs;ss>>rn;
                *t=C_NUM;
                switch(cmp):
                {
                    case 7: 
                    {
                        (ln+rn)>>ss;
                        ss>>s;
                        return s;
                    }
                    case 8:
                    {
                        (ln-rn)>>ss;
                        ss>>s;
                        return s;
                    }
                    case 9:
                    {
                        (ln*rn)>>ss;
                        ss>>s;
                        return s;
                    }
                    case 10:
                    {
                        (ln/rn)>>ss;
                        ss>>s;
                        return s;
                    }
                }
            }
            else
            {
                Error error(12);
                throw error;
            }
        }
}
    
    
std::string INT_NODE::calc_num(type * t)
{
    std::stringstream ss;
    std::string s;
    *t=C_NUM;
    int_num>>ss;
    ss>>s;
    return s;
}

std::string FLOAT_NODE::calc_num(type * t)
{   
    std::stringstream ss;
    std::string s;
    *t=C_NUM;
    float_num>>ss;
    ss>>s;
    return s;
}

std::string STRING_NODE::calc_num(type * t)
{
    *t=C_STRING;
    return s;
}

std::string NAME_NODE::calc_num(type * t) 
{
    for(int i=0;i<table.attribute_list.size();i++)
    {
        if(name==table.attribute_list[i].attribute_name)
        {
            *t=(table.attribute_list[i].type==SQL_STRING?C_STRING:C_NUM);
            tuple_info.info[i]>>ss;
            ss>>s;
            return s;
        }
    }
}*/

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

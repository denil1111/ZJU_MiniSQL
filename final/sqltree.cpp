#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <uuid/uuid.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sstream>
#include "sqltree.hpp"
#include "buffer.h"
#include "catalog.h"
#include "error.h"
#include "record.h"
#include "storage.h"
#include "bptree.h"

Buffer * Parse_Node::buffer;
Catalog * Parse_Node::catalog;
std::string Parse_Node::now_db;

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
    // std::cout<<"In Parse_Node run()"<<std::endl;
}

bool Parse_Node::calc(Table_info,Tuple_info)
{
    // std::cout<<"In Parse_Node calc()"<<std::endl;
    Error error(14);
    throw error;
}

bool Parse_Node::calc_bool(Table_info,Tuple_info)
{
    // std::cout<<"In Parse_Node calc_bool()"<<std::endl;
    Error error(14);
    throw error;
}

std::string Parse_Node::calc_num(ptype&,Table_info,Tuple_info)
{
    // std::cout<<"In Parse_Node calc_num()"<<std::endl;
    Error error(14);
    throw error;
}

void Interpreter::run_parser(char *av)
{
    // std::cout<<"in run_parser"<<std::endl;
        Parse_Node *yyy_parse(char *);
        plan_tree=yyy_parse(av);
        if (plan_tree==NULL)
        {
            Error error(18);
            throw error;
        }
}

void Interpreter::run_sql()
{
    
    // std::cout<<"ready"<<std::endl;
    plan_tree->run();
    // std::cout<<"run ok"<<std::endl;
}

void USE_DATABASE_NODE::run()
{

}   

void SHOW_DATABASE_NODE::run()
{
    std::cout<<std::setw(18)<<"-------------------"<<std::endl;
    std::cout<<'|'<<std::setw(17)<<"DATABASES"<<'|'<<std::endl;
    std::cout<<std::setw(18)<<"-------------------"<<std::endl;
    std::vector<std::string> db_list;
    db_list=catalog->show_database();
    for(int i=0;i<db_list.size();i++)
    {
        std::cout<<'|'<<std::setw(17)<<db_list[i]<<'|'<<std::endl;
        std::cout<<std::setw(18)<<"-------------------"<<std::endl;
    }
    // std::cout<<std::setfill('_')<<std::setw(19)<<'_'<<std::endl;
}

void SHOW_TABLE_NODE::run()
{
    std::cout<<std::setw(18)<<"-------------------"<<std::endl;
    std::cout<<'|'<<std::setw(17)<<"TABLES"<<'|'<<std::endl;
    std::cout<<std::setw(18)<<"-------------------"<<std::endl;
    std::vector<std::string> tbl_list;
    tbl_list=catalog->show_table(now_db);
    for(int i=0;i<tbl_list.size();i++)
    {
        std::cout<<'|'<<std::setw(17)<<tbl_list[i]<<'|'<<std::endl;
        std::cout<<std::setw(18)<<"-------------------"<<std::endl;
    }
    //std::cout<<std::setfill('-')<<std::setw(19)<<'-'<<std::endl;
}

void CREATE_DATABASE_NODE::run()
{
    if(!catalog->is_database(create_db_name))
    {
        catalog->create_database(create_db_name);
        //implement
        int mdret;
        mdret=::mkdir(create_db_name.c_str(), 0755);
        if(mdret)
        {
            std::cout<<"Create Succeed"<<std::endl;
        }
        else
        {
            std::cout<<"Create Failed"<<std::endl;
        }
    }
    else
    {
        Error error(4);
        throw error;
    }
}

void DROP_DATABASE_NODE::run()
{
    if(catalog->is_database(drop_db_name))
    {
        catalog->drop_database(drop_db_name);
        if(drop_db_name==now_db)
        {
            now_db="";
        }
        //implement
        int mdret;
        mdret=rmdir(drop_db_name.c_str());
        if(mdret)
        {
            std::cout<<"Drop Succeed"<<std::endl;
        }
        else
        {
            std::cout<<"Drop Failed"<<std::endl;
        }

    }
    else
    {
        Error error(1);
        throw error;
    }
}

void SELECT_NODE::run()
{
    if(/*select_from_clause[0]->kind!=N_SELECT*/true)
    {
        bool qiantao_flag=false;
        // std::cout<<"run select"<<std::endl;
        Table_info table;
        Table_info temp_table;
        Address address;
        Record record;
        Tuple_info tuple_info;
        Tuple_info temp_tuple;
        int flag=0;
        bool select_flag=false;
        std::vector<int> v;

        uuid_t uu;
        uuid_generate( uu );
        // printf("\n");
        uuid_string_t  strc;
        uuid_unparse_upper(uu,strc);
        temp_table.table_name=strc;
        temp_table.database=now_db;
        temp_table.tuple_size=0;
        // std::cout<<print;
        if (select_from_clause[0]->kind==N_NAME)
        {
            if(catalog->is_table(now_db,select_from_clause[0]->name))
            {

                table=catalog->get_table(now_db,select_from_clause[0]->name);

            }
            else
            {
            
                Error error(2);
                throw error;
            }
        }
        else
        {
            qiantao_flag=true;
            // printf("qianttao\n");
            select_from_clause[0]->print=false;
            select_from_clause[0]->run();
            table=select_from_clause[0]->result_table;
            // std::cout<<table.table_name<<std::endl;
        }
        if(select_list[0]=="select_all_flag")//select *
        {
            temp_table.tuple_size=table.tuple_size;
            for(int j=0;j<table.attribute_list.size();j++)
            {
                v.push_back(j);
                Attribute attribute;
                attribute=table.attribute_list[j];
                attribute.has_index=0;
                attribute.is_primary=0;
                attribute.is_only=0;
                temp_table.attribute_list.push_back(attribute);
                // std::cout<<"attribute:"<<table.attribute_list[j].attribute_name<<std::endl;
            }
        }
        else
        {
            for (int i = 0; i <select_list.size(); i++)
            {
                for(int j=0;i<table.attribute_list.size();j++)
                {
                    if(select_list[i]==table.attribute_list[j].attribute_name)
                    {
                        temp_table.attribute_list.push_back(table.attribute_list[j]);
                        // std::cout<<"attribute:"<<table.attribute_list[j].attribute_name<<std::endl;
                        temp_table.tuple_size+=table.attribute_list[j].size;
                        v.push_back(j);
                        // std::cout<<"list number:"<<j<<std::endl;
                        flag++;
                        break;
                    }
                }
            }
            if(flag!=select_list.size())
            {
                // std::cout<<"bug"<<std::endl;
                Error error(15);
                throw error;
            }
        }
        if (!print)
        {
            catalog->create_table(now_db,temp_table);
            record.create_table(temp_table);
        }
        if (print)
        for(int i=0;i<temp_table.attribute_list.size();i++)
        {
            std::cout<<std::setw(10)<<temp_table.attribute_list[i].attribute_name;
        }
        std::cout<<"\n";
        
        
        {
           
            

            // std::cout<<"temp_table name:"<<temp_table.table_name<<std::endl;
            //std::cout<<<<std::endl;
            
            bool indexed=false;
            //table=catalog->get_table(now_db,select_from_clause[0]->name);
            if (select_where_clause!=NULL)
            {
                std::vector<Section> sections;
                for (int i=0;i<table.attribute_list.size();i++)
                {
                    Section section;
                    section.attribute=table.attribute_list[i];
                    sections.push_back(section);
                }
                bool can_section=select_where_clause->find_section(table, sections);
                if (can_section)
                {
                    if (print)
                    for (int i=0;i<table.attribute_list.size();i++)
                    {
                        // std::cout<<table.attribute_list[i].attribute_name<<":"<<std::endl;
                        for (int j=0;j<sections[i].section_list.size();j++)
                        {
                            if (sections[i].section_list[j].left_open)
                            {
                                std::cout<<"(";
                            }
                            else
                            {
                                std::cout<<"[";
                            }
                            std::cout<<sections[i].section_list[j].left;
                            std::cout<<",";
                            std::cout<<sections[i].section_list[j].right;
                            if (sections[i].section_list[j].right_open)
                            {
                                std::cout<<")";
                            }
                            else
                            {
                                std::cout<<"]";
                            }
                            std::cout<<"U";
                        }
                        std::cout<<std::endl;
                    }
                    int choosed_index=-1;
                    for (int i=0;i<table.attribute_list.size();i++)
                    {
                        if (table.attribute_list[i].has_index)
                        if (sections[i].section_list.size()!=0)
                        {
                            choosed_index=i;
                            break;
                        }
                    }
                    if (choosed_index!=-1)
                    {
                        // std::cout<<"zhaodaole index"<<std::endl;
                        Bptree bptree;
                        for (int i=0;i<sections[choosed_index].section_list.size();i++)
                        {
                            Single_section now_section=sections[choosed_index].section_list[i];
                            Address begin;
                            Address end;
                            bptree.search_section(table, table.attribute_list[choosed_index], now_section.left_open, now_section.left, now_section.right_open, now_section.right, &begin, &end);
                            int loop_address=begin.address_int();
                            for (int i=loop_address;i<end.address_int();i+=ADDRESS_SIZE)
                            {
                                Record record;
                                Tuple_info finded_tuple;
                                Address now(begin.database_name,begin.file_name,i);
                                Address_byte record_address;
                                Address nnext_address;
                                Block block;
                                // std::cout<<"read?"<<std::endl;
                                buffer->read_data(now,&block);
                                block.get_block_data(now.block_offset, ADDRESS_SIZE, record_address.byte);
                                Address record_add=Address(table.database,table.table_name,record_address.address);
                                // std::cout<<"address find"<<std::endl;
                                record.get_tuple(table, record_add, &finded_tuple, &nnext_address);
                                bool selected_flag=select_where_clause->calc(table,finded_tuple);
                                // std::cout<<finded_tuple.info[0]<<std::endl;
                                if(selected_flag==true)
                                {
                                    Tuple_info temp_tuple;
                                    for(int i=0;i<v.size();i++)
                                    {
                                        if (print)
                                        std::cout<<std::setw(10)<<finded_tuple.info[v[i]];
                                        temp_tuple.info.push_back(finded_tuple.info[v[i]]);
                                    }
                                    if (print)
                                    std::cout<<"\n";
                                    // std::cout<<"index insert record"<<std::endl;
                                    if (!print)
                                    record.insert_tuple(temp_table,temp_tuple);
                                }
                                // std::cout<<finded_tuple.info[0]<<std::endl;
                            }
                            // std::cout<<begin.file_name<<std::endl;
                            indexed=true;
                            buffer->remove_file(begin);

                        }
                    }
                    else
                    {
                        
                    }
                    
                }
            }
            // std::cout<<"select_from_clause[0]:"<<select_from_clause[0]->name<<std::endl;
            
            if (indexed) 
            {
                if (qiantao_flag)
                {
                    catalog->drop_table(now_db,table.table_name);
                    Record record;
                    record.drop_table(table);
                }
                // record.drop_table(temp_table);
                result_table=temp_table;
                return; 
            }
            record.get_first_address(table,&address);

            while(address.address_int())
            {
                record.get_tuple(table,address,&tuple_info,&address);

                if(select_where_clause!=NULL)
                {
                    // std::cout<<"in where clause"<<std::endl;
                    select_flag=select_where_clause->calc(table,tuple_info);
                }
                if(select_where_clause==NULL||select_flag==true)
                {
                    Tuple_info temp_tuple;
                    for(int i=0;i<v.size();i++)
                    {
                        if (print)
                        std::cout<<std::setw(10)<<tuple_info.info[v[i]];
                    if (!print)
                        temp_tuple.info.push_back(tuple_info.info[v[i]]);
                    }
                    if (print)
                    std::cout<<"\n";
                    // std::cout<<"???"<<std::endl;
                    if (!print)
                    record.insert_tuple(temp_table,temp_tuple);
                }
            }

            // record.drop_table(temp_table);
             if (qiantao_flag)
                {
                    catalog->drop_table(now_db,table.table_name);
                    Record record;
                    record.drop_table(table);
                }
                if (!print)
            result_table=temp_table;
            // std::cout<<"After drop temp_table"<<std::endl;
                //std::cout<<"temp_table size:"<<temp_table.tuple_size<<std::endl;
        }

        
        // std::cout<<""<<std::endl;
    
    }
    else//nested
    {
        // std::cout<<"inside nested select"<<std::endl;

    }
}

void DELETE_NODE::run()
{
    // Parse_Node * p=del_where_clause;

    if(catalog->is_table(now_db,del_tbl_name))
    {
        Record record;
        Table_info table;
        table=catalog->get_table(now_db,del_tbl_name);
        Tuple_info tuple_info;
        Address address,next_address;
        std::vector <int> v;
        bool del_flag;

        //std::cout<<"wtf"<<std::endl;

        for(int i = 0;i<table.attribute_list.size();i++)
        {
            if(table.attribute_list[i].has_index==1)
            {
                v.push_back(i);
                std::cout<<i<<std::endl;
            }
        }

        record.get_first_address(table,&address);

        while(address.address_int())
        {
            //std::cout<<"delete index1"<<std::endl;
            record.get_tuple(table,address,&tuple_info,&next_address);
            if(star_flag)
            {
                for(int i=0;i<v.size();i++)
                {
                    // std::cout<<"deletion index1"<<std::endl;
                    Bptree bptree;
                    bptree.deletion(table,table.attribute_list[v[i]],tuple_info.info[v[i]]);
                    // std::cout<<"deletion index2"<<std::endl;
                }
                record.delete_tuple(table,address);
                // std::cout<<"delete index2"<<std::endl;
            }
            else
            {
                del_flag=del_where_clause->calc(table,tuple_info);
                if(del_flag)
                {
                    for(int i=0;i<v.size();i++)
                    {
                        // std::cout<<"delete index1"<<std::endl;
                        Bptree bptree;
                        bptree.deletion(table,table.attribute_list[v[i]],tuple_info.info[v[i]]);
                        // std::cout<<"delete index2"<<std::endl;
                    }
                    record.delete_tuple(table,address);

                }
            }
            address=next_address;
        }
    }
    else
    {
        Error error(2);
        throw error;
    }
    
}

bool Single_section::in_section(std::string x,Attribute attribute)
{
    if (x=="inf")
        return false;
    Key_type *left_key,*right_key,*target;
    bool left_bool,right_bool;
    bool ret;
    if (left=="inf")  left_bool=false;
    else
    {
        left_bool=true;
        switch (attribute.type)
        {
            case SQL_INT:left_key=new Int_key;break;
            case SQL_FLOAT:left_key=new Float_key;break;
            case SQL_STRING:left_key=new String_key(attribute.size);break;
        }
        left_key->assign(left);
    }
    if (right=="inf") right_bool=false;
    else
    {
        right_bool=true;
        switch (attribute.type)
        {
            case SQL_INT:right_key=new Int_key;break;
            case SQL_FLOAT:right_key=new Float_key;break;
            case SQL_STRING:right_key=new String_key(attribute.size);break;
        }
        right_key->assign(right);
    }
    switch (attribute.type)
    {
        case SQL_INT:target=new Int_key;break;
        case SQL_FLOAT:target=new Float_key;break;
        case SQL_STRING:target=new String_key(attribute.size);break;
    }
    target->assign(x);
    
    ret=true;
    if (left_bool)
    {
        if (left_open)
        {
            if (target->not_bigger_than(left_key))
                ret=false;
        }
        else
        {
            if (!(left_key->not_bigger_than(target)))
                ret=false;
        }
        delete left_key;
    }
    if (right_bool)
    {
        if (right_open)
        {
            if (right_key->not_bigger_than(target))
                ret=false;
        }
        else
        {
            if (!(target->not_bigger_than(right_key)))
                ret=false;
        }
        delete right_key;
    }
    delete target;
    return ret;

}
bool Single_section::is_null(Attribute attribute)
{
    if (left=="inf" || right=="inf") return false;
    Single_section left_ready;
    left_ready.left=right;
    left_ready.left_open=1-right_open;
    left_ready.right="inf";
    if (left_ready.in_section(left,attribute))
        return true;
    return false;
}
void Section::and_merge(Single_section one)
{
    int i=0;
    Single_section ready=one,left_ready,right_ready;
    std::vector<Single_section>ret_section=section_list,result_section;
    ret_section.resize(0);
    for (int i=0;i<section_list.size();i++)
    {
        Single_section add_section=section_list[i];
        left_ready.left=section_list[i].left;
        left_ready.left_open=section_list[i].left_open;
        left_ready.right="inf";
        right_ready.right=section_list[i].right;
        right_ready.right_open=section_list[i].right_open;
        right_ready.left="inf";
        // std::cout<<ready.left<<"\n";
        // std::cout<<left_ready.left<<"\n";
        if (left_ready.in_section(ready.left,attribute))
        {
            add_section.left=ready.left;
            add_section.left_open=ready.left_open;
            // std::cout<<ready.left<<"\n";

        }
        // std::cout<<ready.right<<"\n";
        // std::cout<<right_ready.right<<"\n";
        if (right_ready.in_section(ready.right,attribute))
        {
            add_section.right=ready.right;
            add_section.right_open=ready.right_open;
            // std::cout<<ready.right<<"\n";
        }
        // std::cout<<add_section.left<<"\n";
        // std::cout<<add_section.right<<"\n";
        if (add_section.is_null(attribute)==false)
        {
            // std::cout<<"add!"<<std::endl;
            result_section.push_back(add_section);
        }

    }
    section_list=result_section;
}
void Section::print()
{
    for (int j=0;j<section_list.size();j++)
    {
        if (section_list[j].left_open)
        {
            std::cout<<"(";
        }
        else
        {
            std::cout<<"[";
        }
        std::cout<<section_list[j].left;
        std::cout<<",";
        std::cout<<section_list[j].right;
        if (section_list[j].right_open)
        {
            std::cout<<")";
        }
        else
        {
            std::cout<<"]";
        }
        std::cout<<"U";
    }
    std::cout<<std::endl;
}
void Section::and_merge(Section another)
{
    Section new_section=*this;
    Section new_section2=*this;
    new_section2.section_list.resize(0);

    for (int i=0;i<another.section_list.size();i++)
    {
        new_section=*this;
        new_section.and_merge(another.section_list[i]);
        new_section2.or_merge(new_section);
    }
    *this=new_section2;
}
void Section::or_merge(Single_section one)
{
    // int i=0;
    // Single_section ready=one,left_ready,right_ready;
    // std::vector<Single_section>ret_section=section_list;
    // ret_section.resize(0);
    // for (int i=0;i<section_list.size();i++)
    //     {
    //         for (int j=i+1;j<section_list.size();j++)
    //         {
    //             if (section_list[i].left>section_list[i].right)
    //             {
    //                 Single_section temp=section_list[i];
    //                 section_list[i]=section_list[j];
    //                 section_list[j]=temp;
    //             }
    //         }
    //     }
    // for (int i=0;i<section_list.size();i++)
    // {
    //     left_ready.right=section_list[i].left;
    //     left_ready.left_open=ready.left_open;
    //     left_ready.right="inf";
    //     right_ready.right=ready.right;
    //     right_ready.right_open=ready.right_open;
    //     right_ready.left="inf";
    // }
    // if (one.left=="inf")
    // {
    //     section_list[0].left="inf";
    // }
    // else
    // {
        
    // }
    
    // section_list=ret_section;
}
void Section::or_merge(Section another)
{
    Section new_section;
    section_list.insert(section_list.end(),another.section_list.begin(),another.section_list.end());
    // for (int i=0;i<another.section_list.size();i++)
    // {
    //     and_merge(another.section_list[i]);
    // }
    // section_list=another.section_list;
}
bool FORMULA_NODE::find_section(Table_info table,std::vector<Section>& sections)
{
    int n;
    if(cmp<=14&&cmp>=12)//and or not
    {
        bool lb;
        bool rb;
        std::vector<Section> section1=sections;
        std::vector<Section> section2=sections;
        lb=expr_l->find_section(table,section1);
        rb=expr_r->find_section(table,section2);
        if (!(lb&&rb))
        {
            return false;
        }
        for (int i=0;i<table.attribute_list.size();i++)
        {
            switch(cmp)
            {
                case 12:
                        section1[i].and_merge(section2[i]);
                        break;
                case 13:section1[i].or_merge(section2[i]);
                        break;
                //         return (lb | rb);
                // case 14:lb=expr_l->calc_bool(table,tuple_info);//not
                        // return (!lb);
            }
        }
        sections=section1;
        return true;
    }
    if(cmp>=1&&cmp<=6)
    {
        std::string target;
        Parse_Node *temp;
        if (expr_r->kind==N_NAME)
        {
            temp=expr_r;
            expr_r=expr_l;
            expr_l=temp;
            switch (cmp)
            {
                case 1:cmp=2;break;
                case 2:cmp=1;break;
                case 3:cmp=3;break;
                case 4:cmp=4;break;
                case 5:cmp=6;break;
                case 6:cmp=6;break;
            }
        }
        if (expr_l->kind==N_NAME)
        {
            for(int i=0;i<table.attribute_list.size();i++)
            {
                if(expr_l->name==table.attribute_list[i].attribute_name)
                {
                    n=i;
                    break;
                }
            }
            if(expr_r->kind==N_INT||expr_r->kind==N_FLOAT||expr_r->kind==N_STRING)
            {
                Tuple_info tuple;
                ptype t;
                target=expr_r->calc_num(t,table,tuple);
            }
            else
            {
                return false;
            }
            Single_section s_sections;
            switch(cmp)
            {
                case 1:
                    s_sections.right=target;
                    s_sections.right_open=true;
                    s_sections.left="inf";
                    sections[n].section_list.push_back(s_sections);
                    break;
                case 2: 
                    s_sections.left=target;
                    s_sections.left_open=true;
                    s_sections.right="inf";
                    sections[n].section_list.push_back(s_sections);
                    break;
                case 3: 
                    s_sections.right=target;
                    s_sections.right_open=true;
                    s_sections.left="inf";
                    sections[n].section_list.push_back(s_sections);
                    s_sections.left_open=true;
                    s_sections.left=target;
                    s_sections.right="inf";
                    sections[n].section_list.push_back(s_sections);
                    break;

                case 4:
                    s_sections.right=target;
                    s_sections.right_open=false;
                    s_sections.left_open=false;
                    s_sections.left=target;
                    sections[n].section_list.push_back(s_sections);
                    break;
                case 5: 
                    s_sections.right=target;
                    s_sections.right_open=false;
                    s_sections.left="inf";
                    sections[n].section_list.push_back(s_sections);
                    break;
                case 6: 
                    s_sections.left=target;
                    s_sections.left_open=false;
                    s_sections.right="inf";
                    sections[n].section_list.push_back(s_sections);
                    break;
            }
        }
        else
        {
            return false;
        }
       
        return true;
    }
    return true;
}
bool FORMULA_NODE::calc(Table_info table,Tuple_info tuple_info)
{
    if(cmp<=14&&cmp>=12)//and or not
    {
        // std::cout<<"compare"<<std::endl;
        bool lb;
        bool rb;
        switch(cmp)
        {
            case 12:lb=expr_l->calc(table,tuple_info);//and
                    rb=expr_r->calc(table,tuple_info);
                    // std::cout<<"lb:"<<lb<<" rb:"<<rb<<std::endl;
                    return (lb & rb);
            case 13:lb=expr_l->calc(table,tuple_info);//or
                    rb=expr_r->calc(table,tuple_info);
                    return (lb | rb);
            case 14:lb=expr_l->calc(table,tuple_info);//not
                    return (!lb);
        }
    }
    else
    {
        if(cmp>=1&&cmp<=6)// < > <= >= != =
        {
            return calc_bool(table,tuple_info);
        }
        else
        {
            Error error(13); //Invalid where clause
            throw error;
        }
    }
    return false;
}

bool FORMULA_NODE::calc_bool(Table_info table,Tuple_info tuple_info)
{
    ptype t1;
    ptype t2;

    std::string ls,rs;

    ls=expr_l->calc_num(t1,table,tuple_info);
    rs=expr_r->calc_num(t2,table,tuple_info);
    // std::cout<<"ls:"<<ls<<" rs:"<<rs<<std::endl;
    // std::cout<<"t1:"<<t1<<" t2:"<<t2<<std::endl;

    float ln=0;
    float rn=0;

    if((t1==t2)&&(t1==C_STRING))//string
    {
        // std::cout<<"com"<<ls<<"and"<<rs<<std::endl;
        switch(cmp)
        {
            case 1: return (ls < rs);
            case 2: return (ls > rs);
            case 3: return (ls != rs);
            case 4: return (ls == rs);
            case 5: return (ls <= rs);
            case 6: return (ls >= rs);
        }
        {
            Error error(14);
            throw error;
        }
    }
    else//num
    {
        if((t1==t2)&&(t1!=C_STRING))
        {
            std::stringstream ss;
            ss<<ls;
            ss>>ln;
            std::stringstream ss2;
            ss2<<rs;
            ss2>>rn;
            // std::cout<<"cmp:"<<cmp<<std::endl;
            // std::cout<<"ln:"<<ln<<" rn:"<<rn<<std::endl;
            switch(cmp)
            {
                case 1: return (ln < rn);
                case 2: return (ln > rn);
                case 3: return (ln != rn);
                case 4: return (ln == rn);
                case 5: return (ln <= rn);
                case 6: return (ln >= rn);
            }
        }
        {
            Error error(14);
            throw error;
        }
    }
    return false;
}

bool FLOAT_NODE::calc_bool(Table_info table,Tuple_info tuple_info)
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

bool INT_NODE::calc_bool(Table_info table,Tuple_info tuple_info)
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

bool NAME_NODE::calc_bool(Table_info table,Tuple_info tuple_info)
{
    std::stringstream ss;
    float n;
    for(int i=0;i<table.attribute_list.size();i++)
    {
        if(name==table.attribute_list[i].attribute_name)
        {
            if(table.attribute_list[i].type==SQL_STRING)
            {
                Error error(14);
                throw error;
            }
            else
            {
                ss<<tuple_info.info[i];
                ss>>n;
                return n==0?false:true;
            }
        }
    }
    Error error(15);
    throw error;
    return false;
}

bool STRING_NODE::calc_bool(Table_info table,Tuple_info tuple_info)
{
    Error error(14);
    throw error;
}

std::string FORMULA_NODE::calc_num(ptype& t,Table_info table,Tuple_info tuple_info)
{
    std::string s;

    ptype t1;
    ptype t2;

    std::string ls=expr_l->calc_num(t1,table,tuple_info);
    

    if (t1!=C_STRING && cmp==11)
    {
        float ln=0;
        std::stringstream ss;
        ss<<ls;ss>>ln;
        t=C_NUM;
        ss<<(-ln);
        ss>>s;
        return s;
    }
    else
    {
        std::string rs=expr_r->calc_num(t2,table,tuple_info);

        if ((t1==t2)&&(t1!=C_STRING))
        {
            float ln=0;
            float rn=0;
            std::stringstream ss1;
            ss1<<ls;
            ss1>>ln;
            std::stringstream ss2;
            ss2<<rs;
            ss2>>rn;
            t=C_NUM;
            switch(cmp)
            {
                case 7: 
                {
                    std::stringstream ss;
                    ss<<(ln+rn);
                    ss>>s;
                    return s;
                }
                case 8:
                {
                    std::stringstream ss;
                    ss<<(ln-rn);
                    ss>>s;
                    return s;
                }
                case 9:
                {
                    std::stringstream ss;
                    ss<<(ln*rn);
                    ss>>s;
                    return s;
                }
                case 10:
                {
                    std::stringstream ss;
                    ss<<(ln/rn);
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
    Error error(12);
    throw error;
}

    
std::string INT_NODE::calc_num(ptype& t,Table_info table,Tuple_info tuple_info)
{
    std::stringstream ss;
    std::string s;
    t=C_NUM;
    ss<<int_num;
    ss>>s;
    return s;
}


std::string FLOAT_NODE::calc_num(ptype& t,Table_info table,Tuple_info tuple_info)
{   
    std::stringstream ss;
    std::string s;
    t=C_NUM;
    ss<<float_num;
    ss>>s;
    return s;
}

std::string STRING_NODE::calc_num(ptype& t,Table_info table,Tuple_info tuple_info)
{
    t=C_STRING;
    return s;
}

std::string NAME_NODE::calc_num(ptype& t,Table_info table,Tuple_info tuple_info)
{
    for(int i=0;i<table.attribute_list.size();i++)
    {
        if(name==table.attribute_list[i].attribute_name)
        {
            t=(table.attribute_list[i].type==SQL_STRING?C_STRING:C_NUM);
            return t==C_STRING?("\""+tuple_info.info[i]+"\""):tuple_info.info[i];
        }
    }
    Error error(15,name);
    throw error;
}

void CREATE_TABLE_NODE::run()
{

    // std::cout<<"in CREATE_TABLE_NODE.run()"<<std::endl;

    if(!catalog->is_table(now_db,create_tbl_name))
    {
        Table_info table;
        Record record;

        table.table_name=create_tbl_name;
        table.database=now_db;
        table.tuple_size=0;

        Attribute attribute;

        std::vector <int> v;

        for(int i=0;i<attr_list.size();i++)
        {
            attribute.attribute_name=attr_list[i]->attr_name;
            attribute.is_primary=0;
            attribute.has_index=0;
            attribute.is_only=0;
            
            // std::cout<<attribute.attribute_name<<std::endl;

            attribute.type=(attr_list[i]->type==0?SQL_INT:(attr_list[i]->type==1?SQL_FLOAT:SQL_STRING));
            attribute.size=attr_list[i]->type==2?attr_list[i]->char_length:4;
            attribute.is_only=attr_list[i]->unique_flag;
            if(attribute.is_only)
            {
                v.push_back(i);
            }
            table.attribute_list.push_back(attribute);
            table.tuple_size+=attribute.size;
        }

        // std::cout<<table.tuple_size<<std::endl;

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
                            table.attribute_list[i].is_only=1;
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
        catalog->create_table(now_db,table);//change the catalog
        record.create_table(table);//change the storage

        if(!sp_list.empty())
        {
            std::string pkey="";
            std::string key="";
            std::string index="";

            for(int i=0;i<sp_list.size();i++)
            {
                if(sp_list[0]->key_type==0)
                {
                    pkey=sp_list[i]->key_attr[0];
                    for(int i=0;i<table.attribute_list.size();i++)
                    {
                        if(pkey==table.attribute_list[i].attribute_name)
                        {
                            Index_info index_info;
                            index_info.index_name=table.table_name+"_"+table.attribute_list[i].attribute_name;

                            // std::cout<<index_info.index_name<<std::endl;

                            index_info.database_name=now_db;
                            index_info.table_name=table.table_name;
                            index_info.attribute_name=table.attribute_list[i].attribute_name;
                            catalog->create_index(index_info);
                            Bptree bptree;
                            // std::cout<<"start create index"<<std::endl;
                            bptree.create(table,table.attribute_list[i]);
                            // std::cout<<"end create index"<<std::endl;
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

                            // std::cout<<index_info.index_name<<std::endl;

                            index_info.database_name=now_db;
                            index_info.table_name=table.table_name;
                            index_info.attribute_name=table.attribute_list[i].attribute_name;
                            // std::cout<<"befor create index"<<std::endl;
                            catalog->create_index(index_info);
                            Bptree bptree;
                            bptree.create(table,table.attribute_list[i]);
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

                            // std::cout<<index_info.index_name<<std::endl;

                            index_info.database_name=now_db;
                            index_info.table_name=table.table_name;
                            index_info.attribute_name=table.attribute_list[i].attribute_name;
                            catalog->create_index(index_info);
                            Bptree bptree;
                            bptree.create(table,table.attribute_list[i]);
                            //implement
                        }
                    }
                }  
            }
        }

        for(int i=0;i<v.size();i++)
        {
            Index_info index_info;
            index_info.index_name=table.table_name+"_"+table.attribute_list[v[i]].attribute_name;

            // std::cout<<index_info.index_name<<std::endl;

            index_info.database_name=now_db;
            index_info.table_name=table.table_name;
            index_info.attribute_name=table.attribute_list[v[i]].attribute_name;

            catalog->create_index(index_info);

            Bptree bptree;
            bptree.create(table,table.attribute_list[v[i]]);
            // std::cout<<"out"<<std::endl;
        }
        
    }
    else
    {
        //printf("error3\n");
        Error error(3);
        throw error;
    }
    
    //std::cout<<"out of node"<<std::endl;

    /*problem:1.调用函数lib error 2.catalog createtable 3.index 如何建立 4.index() index()写法可以么*/
}

void DROP_TABLE_NODE::run()
{
    if(catalog->is_table(now_db,drop_tbl_name))
    {
        Record record;
        Table_info table;

        table=catalog->get_table(now_db,drop_tbl_name);
        catalog->drop_table(now_db,drop_tbl_name);

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
    if(catalog->is_table(now_db,create_index_tbl))
    {
        Table_info table=catalog->get_table(now_db,create_index_tbl);
        for (int i = 0; i < table.attribute_list.size(); i++)
        {
            if(create_index_attr==table.attribute_list[i].attribute_name)
            {
                if(table.attribute_list[i].is_only==1&&table.attribute_list[i].has_index==0)
                {
                    Index_info index_info;
                    index_info.database_name=now_db;
                    index_info.index_name=create_index_name;
                    index_info.table_name=create_index_tbl;
                    index_info.attribute_name=create_index_attr;
                    catalog->create_index(index_info);
                    flag=1;
                    Bptree bptree;
                    bptree.create(table,table.attribute_list[i]);
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
    if(catalog->is_table(now_db,drop_index_tbl))
    {
        if(catalog->is_index(drop_index_name))
        {
            Attribute attribute;
            Table_info table;
            // std::cout<<drop_index_name<<std::endl;
            attribute=catalog->drop_index(drop_index_name);
            table=catalog->get_table(now_db,drop_index_tbl);

            Bptree bptree;
            bptree.drop(table,attribute);
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
    // std::cout<<"in INSERT_NODE.run()"<<std::endl;

    if(catalog->is_table(now_db,insert_tbl_name))
    {
        Record record;
        Table_info table;
        Tuple_info tuple_info;
        table=catalog->get_table(now_db,insert_tbl_name);

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
                
                if(insert_value_list[i].size()!=table.attribute_list.size())
                {
                    Error error(21);
                    throw error;
                }
                //std::cout<<insert_value_list[i][j]<<std::endl;
                tuple_info.info.push_back(insert_value_list[i][j]);
            }
            // for(int k=0;k<tuple_info.info.size();k++)
            // {
            //     std::cout<<tuple_info.info[k]<<std::endl;
            // }
            Address record_address=record.insert_tuple(table,tuple_info);

            for(int j=0;j<tuple_info.info.size();j++)
            {
                if(table.attribute_list[j].is_primary==1 ||table.attribute_list[j].has_index==1)
                {
                    try
                    {
                        Bptree bptree;   
                        bptree.insert(table,table.attribute_list[j],tuple_info.info[j],record_address);
                    }
                    catch(Error error)
                    {
                        record.delete_tuple(table,record_address);
                        error.print_error();
                    }
                    
                }
            }
        }
    } 
    else                                                             
    {
        // std::cout<<"Inside Error"<<std::endl;
        Error error(2);//"table does not exist"
        throw error;
    }
}

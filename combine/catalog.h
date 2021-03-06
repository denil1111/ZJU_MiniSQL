//
//  catalog.h
//  MiniSQL
//
//  Created by 冯喆￼ on 14-10-23.
//  Copyright (c) 2014年 冯喆￼. All rights reserved.
//

#ifndef __MiniSQL__catalog__
#define __MiniSQL__catalog__

#include <iostream>
#include <stdio.h>
#include <vector>
enum type_enum {SQL_INT,SQL_FLOAT,SQL_STRING};

//using namespace std;

struct Index_info
{
    std::string index_name;
    std::string database_name;
    std::string table_name;
    std::string attribute_name;
};

struct Attribute
{
    std::string attribute_name;
    type_enum type;
    int size;
    bool is_primary;
    bool is_only;
    bool has_index;
    std::string index_name;
};

struct Table_info
{
    std::string table_name;
    std::vector<Attribute> attribute_list;
    std::string database;
    int tuple_size;
};

struct Database_info
{
    std::string database_name;
    std::vector<Table_info> table_list;
};

class Catalog
{
public:
    std::vector<Database_info> database_list;
    //std::vector<Index_info> index_list;
    
    void read_file();
    void write_file();
    
    //创建
    void create_database(std::string);
    void create_table(std::string, Table_info);
    void create_index(Index_info);
    
    //判断是否存在
    bool is_table(std::string, std::string);
    bool is_index(std::string);
    bool is_database(std::string);
    
    //获取信息
    Table_info get_table(std::string, std::string);
    
    //删除
    void drop_database(std::string);
    void drop_table(std::string, std::string);
    Attribute drop_index(std::string);
    std::vector<std::string> show_database();
    std::vector<std::string> show_table(std::string database_name);
    ~Catalog()
    {
        write_file();
    }
};

#endif /* defined(__catalog__Table__) */

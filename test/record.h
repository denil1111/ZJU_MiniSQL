//
//  record.h
//  MiniSQL
//
//  Created by zyhc on 11/4/14.
//  Copyright (c) 2014 zyhc. All rights reserved.
//

#ifndef __MiniSQL__record__
#define __MiniSQL__record__

#include <stdio.h>
#include <string>
#include <vector>
#include "buffer.h"
#include "catalog.h"
#define ADDRESS_SIZE 4
#define MAX_RECORD_SIZE 256
union Address_byte
{
    unsigned int address;
    unsigned char byte[ADDRESS_SIZE];
};
//enum type_enum
//{
//    INT,
//    FLOAT,
//    STRING
//};
//struct Attribute
//{
//    std::string name;
//    type_enum type;
//    int size;
//    bool changed;
//    
//};
//struct Table_info
//{
//    std::vector<Attribute> attribute_list;
//    std::string table_name;
//    std::string database;
//    int tuple_size;
//};
struct Tuple_info
{
    std::vector<std::string> info;
    Tuple_info()
    {
    }
    Tuple_info(int size)
    {
        info.resize(size);
    }
};
struct Tuple_data
{
    int size;
    unsigned char* data;
    Tuple_data(int size)
    {
        data=new unsigned char[size];
        this->size=size;
    }
    ~Tuple_data()
    {
        delete [] data;
    }
};
class Record
{
private:
    Storage storage;
    void get_block_data(Block,int,int,unsigned char*);
    void fill_block_data(Block*,int,int,unsigned char*);
//    int cal_size(Table_info);
    
public:
    static Buffer *buffer;
    Address int_to_address(Table_info,unsigned int);
    unsigned int address_to_int(Address);
    void pack(Table_info, Tuple_info, Tuple_data*);
    void unpack(Table_info, Tuple_info*, const Tuple_data*);
    Record(){}
    void insert_tuple(Table_info, Tuple_info);
    void create_table(Table_info);
    void delete_tuple(Table_info,Address);
    void delete_all_tuple(Table_info);
    void drop_table(Table_info);
    void get_first_tuple(Table_info,Tuple_info*,Address*);
    void get_tuple(Table_info,Address,Tuple_info*,Address*);
    
};

#endif /* defined(__MiniSQL__record__) */

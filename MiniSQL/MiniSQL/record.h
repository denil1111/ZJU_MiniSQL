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
#define ADDRESS_SIZE 4
#define MAX_RECORD_SIZE 256
struct Attribute
{
    int type;
    int size;
    bool changed;
};
struct Table_info
{
    std::vector<Attribute> attribute_list;
    std::string table_name;
    std::string database;
    int tuple_size;
};
struct Tuple_info
{
    std::vector<std::string> info;
};
struct Tuple_data
{
    int size;
    char* data;
    Tuple_data(int size)
    {
        data=new char[size];
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
    Buffer buffer;
    
//    int cal_size(Table_info);
public:
    void pack(Table_info, Tuple_info, Tuple_data*);
    void unpack(Table_info, Tuple_info*, const Tuple_data*);
    Record()
    {
    }
    void insert(Table_info, Tuple_info);
    void remove(Table_info, Tuple_info);
    
};

#endif /* defined(__MiniSQL__record__) */

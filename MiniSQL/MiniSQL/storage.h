//
//  storage.h
//  MiniSQL
//
//  Created by zyhc on 10/27/14.
//  Copyright (c) 2014 zyhc. All rights reserved.
//

#ifndef __MiniSQL__storage__
#define __MiniSQL__storage__
#define BLOCK_SIZE (8*1024)

#include <string>
struct Block
{
    unsigned char data[BLOCK_SIZE];
    Block()
    {
        memset(data,0,sizeof(data));
    }
    void get_block_data(int seed,int size,unsigned char* data);
    void fill_block_data(int seed,int size,unsigned char* data);
    Block(unsigned char* data)
    {
        for (int i=0;i<BLOCK_SIZE;i++)
            this->data[i]=data[i];
    }
    void copy(Block data)
    {
        for (int i=0;i<BLOCK_SIZE;i++)
            this->data[i]=data[i];
    }
    unsigned char &operator [](const int index)
    {
        return data[index];
    }
    void copy(unsigned char*);
};
struct Address
{
    std::string database_name;
    std::string file_name;
    int file_offset;
    int block_offset;
    Address()
    {
        file_offset=0;
        block_offset=0;
    }
    Address(std::string database,std::string file_name,int address_int)
    {
        this->database_name=database;
        this->file_name=file_name;
        this->file_offset=address_int/BLOCK_SIZE;
        this->block_offset=address_int%BLOCK_SIZE;

    }
    unsigned int address_int()
    {
        return file_offset*BLOCK_SIZE+block_offset;
    }
    bool block_equal(Address another)
    {
        if (database_name==another.database_name)
            if (file_name==another.file_name)
                if (file_offset==another.file_offset)
                    return true;
        return false;
    }
};
class Storage
{
public:
    Storage(){}
    void read_data(Address,Block*);
    void write_data(Address,const Block*);
    void create_file(Address);
    void remove_file(Address);
};

#endif /* defined(__MiniSQL__storage__) */

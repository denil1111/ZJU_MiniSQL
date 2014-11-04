//
//  storage.h
//  MiniSQL
//
//  Created by zyhc on 10/27/14.
//  Copyright (c) 2014 zyhc. All rights reserved.
//

#ifndef __MiniSQL__storage__
#define __MiniSQL__storage__
#define BLOCK_SIZE 8*1024

#include <string>
struct Block
{
    unsigned char data[BLOCK_SIZE];
    Block(){
        
    }
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
    
};

#endif /* defined(__MiniSQL__storage__) */

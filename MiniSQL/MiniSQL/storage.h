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
    int offset;
};
class Storage
{
public:
    Storage(){}
    void read_data(Address,Block*);
    void write_data(Address,const Block*);
    
};

#endif /* defined(__MiniSQL__storage__) */

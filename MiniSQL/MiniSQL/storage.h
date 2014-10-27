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
class Block
{
public:
    unsigned char data[BLOCK_SIZE];
    Block(unsigned char[]);
    unsigned char &operator [](const int index)
    {
        return data[index];
    }
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
    Storage();
    Block read_data(Address);
    void write_data(Address,Block);
    
};

#endif /* defined(__MiniSQL__storage__) */

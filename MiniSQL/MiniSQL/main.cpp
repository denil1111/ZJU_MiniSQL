//
//  main.cpp
//  MiniSQL
//
//  Created by zyhc on 10/27/14.
//  Copyright (c) 2014 zyhc. All rights reserved.
//

#include <iostream>
#include "storage.h"
#include "error.h"
int main(int argc, const char * argv[])
{
    Block* data=new Block();
    Address address;
    address.database_name="zyh";
    address.file_name="friend";
    address.offset=8;
    Storage storage;
    try{
        storage.read_data(address,data);
        for (int i=0;i<8;i++)
        {
            std::cout << (*data)[i];
        }
    }
    catch( Error error)
    {
        error.print_error();
    }
    unsigned char newdata[BLOCK_SIZE];
    for (int i=0;i<BLOCK_SIZE;i++)
    {
        newdata[i]='s';
    }
    Block newblock(newdata);
    try{
        storage.write_data(address,&newblock);
    }
    catch( Error error)
    {
        error.print_error();
    }
    return 0;
}

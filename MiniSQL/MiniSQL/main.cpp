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
#include "buffer.h"
void storagetest()
{
    Block* data=new Block();
    Address address;
    address.database_name="zyh";
    address.file_name="friend";
    address.file_offset=8;
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

}
int main(int argc, const char * argv[])
{
    Block* data=new Block();
    Address address;
    address.database_name="zyh";
    address.file_name="friend";
    address.file_offset=8;
    Buffer buffer;
    unsigned char newdata[BLOCK_SIZE];
    for (int i=0;i<BLOCK_SIZE;i++)
    {
        newdata[i]='e';
    }
    Block newblock1(newdata);
    buffer.write_data(address,&newblock1);
    address.database_name="zyh";
    address.file_name="friend";
    address.file_offset=9;
    for (int i=0;i<BLOCK_SIZE;i++)
    {
        newdata[i]='9';
    }
    Block newblock2(newdata);
    buffer.write_data(address,&newblock2);
    address.database_name="zyh";
    address.file_name="friend";
    address.file_offset=10;
    for (int i=0;i<BLOCK_SIZE;i++)
    {
        newdata[i]='X';
    }
    Block newblock3(newdata);
    buffer.write_data(address,&newblock3);
    address.database_name="zyh";
    address.file_name="friend";
    address.file_offset=8;
    for (int i=0;i<BLOCK_SIZE;i++)
    {
        newdata[i]='8';
    }
    Block newblock4(newdata);
    buffer.write_data(address,&newblock4);
    Block readblock;
    buffer.read_data(address,&readblock);
    std::cout<<readblock[0]<<std::endl;
    address.database_name="zyh";
    address.file_name="friend";
    address.file_offset=11;
    for (int i=0;i<BLOCK_SIZE;i++)
    {
        newdata[i]='L';
    }
    Block newblock5(newdata);
    buffer.write_data(address,&newblock1);
    address.file_offset=9;
    buffer.read_data(address,&readblock);
    std::cout<<readblock[0]<<std::endl;
    address.database_name="zyh";
    address.file_name="friend";
    address.file_offset=8;
    for (int i=0;i<BLOCK_SIZE;i++)
    {
        newdata[i]='p';
    }
    Block newblocknew(newdata);
    buffer.write_data(address,&newblocknew);

    return 0;
}

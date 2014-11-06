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
#include "record.h"
void storage_test()
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
void buffer_test()
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
}
int main(int argc, const char * argv[])
{
    Record record;
    Table_info table;
    table.table_name="friend";
    table.database="zyh";
    Attribute attribute;
    Tuple_data tuple_data(90);
    Tuple_info tuple;
    attribute.type=1;
    attribute.size=4;
    table.attribute_list.push_back(attribute);
    attribute.type=3;
    attribute.size=6;
    table.attribute_list.push_back(attribute);
    attribute.type=3;
    attribute.size=4;
    table.attribute_list.push_back(attribute);
    attribute.type=3;
    attribute.size=3;
    table.attribute_list.push_back(attribute);
    attribute.type=2;
    attribute.size=4;
    table.attribute_list.push_back(attribute);
    tuple.info.push_back("44");
    tuple.info.push_back("abcde");
    tuple.info.push_back("ac");
    tuple.info.push_back("ac");
    tuple.info.push_back("44.4");
    Tuple_info tuple_unpack;
    for (int i=0;i<5;i++)
        tuple_unpack.info.push_back("");
    try
    {
        record.pack(table,tuple,&tuple_data);
    }
    catch (Error error)
    {
        error.print_error();
    }
    printf("before unpack\n");
      printf("\n");
    record.unpack(table,&tuple_unpack,&tuple_data);
    for (int i=0;i<5;i++)
        std::cout<<tuple_unpack.info[i]<<std::endl;
    for (int i=0;i<30;i++)
        printf("%X  ",tuple_data.data[i]);
    return 0;
}

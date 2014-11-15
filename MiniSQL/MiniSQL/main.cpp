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
#include "bptree.h"
#include <uuid/uuid.h>

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
    Buffer buffer;
    Storage disk;
    Record::buffer=&buffer;
    Bptree_node::buffer=&buffer;
    Bptree::buffer=&buffer;
    Record record;
    Table_info table;
    table.table_name="friendg";
    table.database="zyh";
    Attribute attribute;
    Tuple_data tuple_data(90);
    Tuple_info tuple;
    table.tuple_size=21;
    attribute.type=SQL_INT;
    attribute.size=4;
    table.attribute_list.push_back(attribute);
    attribute.type=SQL_STRING;
    attribute.size=6;
    table.attribute_list.push_back(attribute);
    attribute.type=SQL_STRING;
    attribute.size=4;
    table.attribute_list.push_back(attribute);
    attribute.type=SQL_STRING;
    attribute.size=3;
    table.attribute_list.push_back(attribute);
    attribute.attribute_name="result";
    attribute.type=SQL_FLOAT;
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
    printf("\n");
    Storage storage;
    record.create_table(table);
    record.insert_tuple(table, tuple_unpack);
    record.insert_tuple(table, tuple_unpack);
    record.insert_tuple(table, tuple_unpack);
    Address del_address;
    del_address=record.int_to_address(table, 12);
    record.delete_tuple(table, del_address);
    del_address=record.int_to_address(table, 41);
    record.delete_tuple(table, del_address);
    record.insert_tuple(table, tuple_unpack);
    Tuple_info new_tuple;
    new_tuple.info.push_back("55");
    new_tuple.info.push_back("qqqq");
    new_tuple.info.push_back("ac");
    new_tuple.info.push_back("ac");
    new_tuple.info.push_back("32.2");
    record.insert_tuple(table, new_tuple);
    Tuple_info get_tuple(5);
    Address next_address;
    record.get_first_tuple(table, &get_tuple, &next_address);
    while (!(next_address.block_offset==0 && next_address.file_offset==0))
    {
        for (int i=0;i<5;i++)
        {
            std::cout<<get_tuple.info[i]<<std::endl;
        }
        std::cout<<"next"<<std::endl;
        Address address=next_address;
        record.get_tuple(table, address,&get_tuple, &next_address);
    }
    for (int i=0;i<5;i++)
    {
        std::cout<<get_tuple.info[i]<<std::endl;
    }
    Bptree bptree;
    Table_info table2;
    table2.table_name="friendindex";
    table2.database="zyh";
    table2.tuple_size=2400;
    attribute.type=SQL_STRING;
    attribute.size=2400;
    table2.attribute_list.push_back(attribute);
//    Tuple_info tuple2;
//    Address add;
//    tuple2.info.push_back("a");
//    tuple2.info[0]="b";
//    Address finded;
//    Address nnext_address;
//    Tuple_info finded_tuple;
//    finded=bptree.search(table2, attribute, "b");
//    record.get_tuple(table2, finded, &finded_tuple, &nnext_address);
//    std::cout<<finded_tuple.info[0]<<std::endl;
    //1
    Tuple_info tuple2;
    tuple2.info.push_back("a");
    record.create_table(table2);
    Address add;
    add=record.insert_tuple(table2, tuple2);
    bptree.drop(table2, attribute);
    bptree.create(table2, attribute);
    bptree.insert(table2, attribute, "a", add);
    Address finded=bptree.search(table2, attribute, "a");
    Tuple_info finded_tuple;
    Address nnext_address;
    //2
    tuple2.info[0]="b";
    add=record.insert_tuple(table2, tuple2);
    record.get_tuple(table2, finded, &finded_tuple, &nnext_address);
    bptree.insert(table2, attribute, "b", add);
    finded=bptree.search(table2, attribute, "b");
    record.get_tuple(table2, finded, &finded_tuple, &nnext_address);
    std::cout<<finded_tuple.info[0]<<std::endl;
    //3
    tuple2.info[0]="c";
    add=record.insert_tuple(table2, tuple2);
    record.get_tuple(table2, finded, &finded_tuple, &nnext_address);
    bptree.insert(table2, attribute, "c", add);
    finded=bptree.search(table2, attribute, "c");
    record.get_tuple(table2, finded, &finded_tuple, &nnext_address);
    bptree.print(table2,attribute);

    std::cout<<finded_tuple.info[0]<<std::endl;
    //4
    tuple2.info[0]="d";
    add=record.insert_tuple(table2, tuple2);
    record.get_tuple(table2, finded, &finded_tuple, &nnext_address);
    bptree.insert(table2, attribute, "d", add);
    finded=bptree.search(table2, attribute, "d");
    record.get_tuple(table2, finded, &finded_tuple, &nnext_address);
    std::cout<<finded_tuple.info[0]<<std::endl;
    bptree.print(table2,attribute);
    //5
    tuple2.info[0]="f";
    add=record.insert_tuple(table2, tuple2);
    record.get_tuple(table2, finded, &finded_tuple, &nnext_address);
    bptree.insert(table2, attribute, "f", add);
    finded=bptree.search(table2, attribute, "f");
    record.get_tuple(table2, finded, &finded_tuple, &nnext_address);
    std::cout<<finded_tuple.info[0]<<std::endl;
    bptree.print(table2,attribute);
    //6
    tuple2.info[0]="e";
    add=record.insert_tuple(table2, tuple2);
    record.get_tuple(table2, finded, &finded_tuple, &nnext_address);
    bptree.insert(table2, attribute, "e", add);
    finded=bptree.search(table2, attribute, "e");
//    record.get_tuple(table2, add, &finded_tuple, &nnext_address);
//    std::cout<<finded_tuple.info[0]<<std::endl;
    record.get_tuple(table2, finded, &finded_tuple, &nnext_address);
    std::cout<<finded_tuple.info[0]<<std::endl;
    bptree.print(table2,attribute);
    //6
    tuple2.info[0]="g";
    add=record.insert_tuple(table2, tuple2);
    record.get_tuple(table2, finded, &finded_tuple, &nnext_address);
    bptree.insert(table2, attribute, "g", add);
    finded=bptree.search(table2, attribute, "g");
    record.get_tuple(table2, finded, &finded_tuple, &nnext_address);
    std::cout<<finded_tuple.info[0]<<std::endl;
    bptree.print(table2,attribute);
    //7
    tuple2.info[0]="q";
    add=record.insert_tuple(table2, tuple2);
    record.get_tuple(table2, finded, &finded_tuple, &nnext_address);
    bptree.insert(table2, attribute, "q", add);
    finded=bptree.search(table2, attribute, "q");
    record.get_tuple(table2, finded, &finded_tuple, &nnext_address);
    std::cout<<finded_tuple.info[0]<<std::endl;
    bptree.print(table2,attribute);
    //3
    tuple2.info[0]="h";
    add=record.insert_tuple(table2, tuple2);
    record.get_tuple(table2, finded, &finded_tuple, &nnext_address);
    bptree.insert(table2, attribute, "h", add);
    finded=bptree.search(table2, attribute, "h");
    record.get_tuple(table2, finded, &finded_tuple, &nnext_address);
    std::cout<<finded_tuple.info[0]<<std::endl;
    bptree.print(table2,attribute);
    //8
    tuple2.info[0]="z";
    add=record.insert_tuple(table2, tuple2);
    record.get_tuple(table2, finded, &finded_tuple, &nnext_address);
    bptree.insert(table2, attribute, "z", add);
//    bptree.print(table2,attribute);

    finded=bptree.search(table2, attribute, "z");
    record.get_tuple(table2, finded, &finded_tuple, &nnext_address);
    std::cout<<finded_tuple.info[0]<<std::endl;
    bptree.print(table2,attribute);
    //9
    tuple2.info[0]="y";
    add=record.insert_tuple(table2, tuple2);
    record.get_tuple(table2, finded, &finded_tuple, &nnext_address);
    bptree.insert(table2, attribute, "y", add);
    //    bptree.print(table2,attribute);
    
    finded=bptree.search(table2, attribute, "y");
    record.get_tuple(table2, finded, &finded_tuple, &nnext_address);
    std::cout<<finded_tuple.info[0]<<std::endl;
    bptree.print(table2,attribute);
//10
    tuple2.info[0]="w";
    add=record.insert_tuple(table2, tuple2);
    record.get_tuple(table2, finded, &finded_tuple, &nnext_address);
    bptree.insert(table2, attribute, "w", add);
    //    bptree.print(table2,attribute);
    
    finded=bptree.search(table2, attribute, "w");
    record.get_tuple(table2, finded, &finded_tuple, &nnext_address);
    std::cout<<finded_tuple.info[0]<<std::endl;
    bptree.print(table2,attribute);
//11
    tuple2.info[0]="u";
    add=record.insert_tuple(table2, tuple2);
    record.get_tuple(table2, finded, &finded_tuple, &nnext_address);
    bptree.insert(table2, attribute, "u", add);
    //    bptree.print(table2,attribute);
    
    finded=bptree.search(table2, attribute, "u");
    record.get_tuple(table2, finded, &finded_tuple, &nnext_address);
    std::cout<<finded_tuple.info[0]<<std::endl;
    bptree.print(table2,attribute);

//12
    tuple2.info[0]="v";
    add=record.insert_tuple(table2, tuple2);
    record.get_tuple(table2, finded, &finded_tuple, &nnext_address);
    bptree.insert(table2, attribute, "v", add);
    //    bptree.print(table2,attribute);
    
    finded=bptree.search(table2, attribute, "v");
    record.get_tuple(table2, finded, &finded_tuple, &nnext_address);
    std::cout<<finded_tuple.info[0]<<std::endl;
    bptree.print(table2,attribute);
    record.delete_tuple(table2, finded);
    bptree.deletion(table2, attribute, "v");
    add=bptree.search(table2, attribute, "v");
    add=record.insert_tuple(table2, tuple2);
    bptree.insert(table2, attribute, "v", add);
    record.get_tuple(table2, finded, &finded_tuple, &nnext_address);
    std::cout<<finded_tuple.info[0]<<std::endl;
    std::cout<<add.address_int()<<std::endl;
    Address begin,end;
    bptree.search_section(table2, attribute, false, "inf", false, "inf", &begin, &end);
    int loop_address=begin.address_int();
    for (int i=loop_address;i<end.address_int();i+=ADDRESS_SIZE)
    {
        Address now(begin.database_name,begin.file_name,i);
        Address_byte record_address;
        Block block;
        buffer.read_data(now,&block);
        block.get_block_data(now.block_offset, ADDRESS_SIZE, record_address.byte);
        Address record_add=Address(table2.database,table2.table_name,record_address.address);
        record.get_tuple(table2, record_add, &finded_tuple, &nnext_address);
        std::cout<<finded_tuple.info[0]<<std::endl;
    }
    if (end.address_int()>loop_address)
    {
        buffer.remove_file(begin);
    }
    
//        bptree.test(table,attribute);
//    record.drop_table(table);
//    uuid_t uu;
//    int i;
//    uuid_generate( uu );
//    
//    for(i=0;i<16;i++)
//    {
//        printf("%02X-",uu[i]);
//    }
//    printf("\n");
//    uuid_string_t strc;
//    uuid_unparse_upper(uu,strc);
//    std::cout<<strc<<std::endl;
    return 0;
}

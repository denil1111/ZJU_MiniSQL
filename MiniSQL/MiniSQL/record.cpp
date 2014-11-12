//
//  record.cpp
//  MiniSQL
//
//  Created by zyhc on 11/4/14.
//  Copyright (c) 2014 zyhc. All rights reserved.
//

#include "record.h"
#include "buffer.h"
#include "error.h"
#include <iostream>
#include <sstream>
void Record::pack(Table_info table,Tuple_info tuple,Tuple_data* tuple_data)
{
    int j=0;
    for (int i=0;i<table.attribute_list.size();i++)
    {
        std::stringstream ss(tuple.info[i]);
        int size=table.attribute_list[i].size;
        switch (table.attribute_list[i].type)
        {
            case INT:
                union
                {
                    char byte[4];
                    int data;
                }data_int;
                ss>>data_int.data;
                for (int i=0;i<4;i++)
                {
                    tuple_data->data[j]=data_int.byte[i];
                    j++;
                }
                break;
            case FLOAT:
                union
                {
                    char byte[4];
                    float data;
                }data_float;
                ss>>data_float.data;
                for (int i=0;i<size;i++)
                {
                    tuple_data->data[j]=data_float.byte[i];
                    j++;
                }
                break;
            case STRING:
                char *data_byte;
                data_byte=new char[size];
                ss>>data_byte;
                if (strlen(data_byte)>=size)
                {
                    Error error(1,"string is too long");
                    throw error;
                }
                for (int i=0;i<strlen(data_byte);i++)
                {
                    tuple_data->data[j]=data_byte[i];
                    j++;
                }
                for (int i=(int)strlen(data_byte);i<size;i++)
                {
                    tuple_data->data[j]=0;
                    j++;
                }
                delete  []data_byte;
                break;
        }
    }
}
void Record::unpack(Table_info table,Tuple_info *tuple,const Tuple_data *tuple_data)
{
    tuple->info.resize(table.attribute_list.size());
    int j=0;
    for (int i=0;i<table.attribute_list.size();i++)
    {
        std::stringstream ss("");
        int size=table.attribute_list[i].size;
        switch (table.attribute_list[i].type)
        {
            case INT:
                union
            {
                char byte[4];
                int data;
            }data_int;
                for (int i=0;i<4;i++)
                {
                    data_int.byte[i]=tuple_data->data[j];
                    j++;
                }
                ss<<data_int.data;
                ss>>tuple->info[i];
                break;
            case FLOAT:
                union
            {
                char byte[4];
                float data;
            }data_float;
                for (int i=0;i<size;i++)
                {
                    data_float.byte[i]=tuple_data->data[j];
                    j++;
                }
                ss<<data_float.data;
                ss>>tuple->info[i];
                break;
            case STRING:
                char *data_byte;
                data_byte=new char[size+1];
                for (int i=0;i<size;i++)
                {
                    data_byte[i]=tuple_data->data[j];
                    j++;
                }
                ss<<data_byte;
                ss>>tuple->info[i];
                delete  []data_byte;
                break;
        }
    }
}
Address Record::int_to_address(Table_info table,unsigned int address_int)
{
    Address newaddress;
    newaddress.database_name=table.database;
    newaddress.file_name=table.table_name;
    newaddress.file_offset=address_int/BLOCK_SIZE;
    newaddress.block_offset=address_int%BLOCK_SIZE;
    return newaddress;
}
unsigned int Record::address_to_int(Address address)
{
    return address.file_offset*BLOCK_SIZE+address.block_offset;
}
void Record::insert_tuple(Table_info table,Tuple_info tuple)
{
    Tuple_data tuple_data(table.tuple_size);
    pack(table,tuple,&tuple_data);
    Address header_address=int_to_address(table, 0);
    Block header;
    int full_tuple_size=tuple_data.size+2*ADDRESS_SIZE;
    buffer->read_data(header_address, &header);
    Address_byte deleted_address_data,new_address_data,next_address_data,begin_address_data,newer_address_data,inserted_address_data;
    /*header:
        [0:ADDRESS_SIZE-1]-->first deleted (no ->0)
        then new address
        then first address
     */
    for (int i=0;i<ADDRESS_SIZE;i++)
        deleted_address_data.byte[i]=header[i];
    for (int i=0;i<ADDRESS_SIZE;i++)
        new_address_data.byte[i]=header[i+ADDRESS_SIZE];
    for (int i=0;i<ADDRESS_SIZE;i++)
        begin_address_data.byte[i]=header[i+ADDRESS_SIZE*2];
    unsigned int deleted_address=deleted_address_data.address;
    unsigned int new_address=new_address_data.address;
    /* when there is deleted tuple*/
    Block data;
    Address address;
    if (deleted_address!=0)
    {
        Block filled_data;
        inserted_address_data.address=deleted_address;
        address=int_to_address(table, deleted_address);
        buffer->read_data(address, &filled_data);
        /* next deleted address */
        for (int i=0;i<ADDRESS_SIZE;i++)
            next_address_data.byte[i]=filled_data[i+address.block_offset];
        /*change deleted_address in header*/
        for (int i=0;i<ADDRESS_SIZE;i++)
        {
            header[i]=next_address_data.byte[i];
        }
        /*change begin_address in header*/
        for (int i=0;i<ADDRESS_SIZE;i++)
        {
            header[i+ADDRESS_SIZE*2]=deleted_address_data.byte[i];
        }
        buffer->write_data(header_address, &header);
    }
    else
    {
        inserted_address_data.address=new_address;
        address=int_to_address(table, new_address);
        /*change begin_address in header*/
        for (int i=0;i<ADDRESS_SIZE;i++)
        {
            header[i+ADDRESS_SIZE*2]=new_address_data.byte[i];
        }
        newer_address_data.address=new_address+full_tuple_size;
        for (int i=0;i<ADDRESS_SIZE;i++)
        {
            header[i+ADDRESS_SIZE]=newer_address_data.byte[i];
        }

        buffer->write_data(header_address, &header);

    }
    /* fill new tuple and write */
    buffer->read_data(address, &data);
    for (int i=0;i<tuple_data.size;i++)
    {
        data[i+address.block_offset]=tuple_data.data[i];
    }
    for (int i=0;i<ADDRESS_SIZE;i++)
    {
        data[i+address.block_offset+tuple_data.size]=begin_address_data.byte[i];
        
    }
    for (int i=0;i<ADDRESS_SIZE;i++)
    {
        data[i+address.block_offset+tuple_data.size+ADDRESS_SIZE]=0;
        
    }
    buffer->write_data(address, &data);
    if (begin_address_data.address!=0)
    {
        address.file_offset=begin_address_data.address/BLOCK_SIZE;
        address.block_offset=begin_address_data.address%BLOCK_SIZE;
        buffer->read_data(address, &data);
        for (int i=0;i<ADDRESS_SIZE;i++)
        {
            data[i+address.block_offset+tuple_data.size+ADDRESS_SIZE]=inserted_address_data.byte[i];
            
        }
        buffer->write_data(address, &data);
    }
}
void Record::create_table(Table_info table)
{
    Address header_address=int_to_address(table,0);
    storage.create_file(header_address);
    Block first_block;
    memset(first_block.data, 0, sizeof(first_block));
    union
    {
        unsigned char byte[ADDRESS_SIZE];
        unsigned int address;
    }new_address;
    new_address.address=ADDRESS_SIZE*3;
    for (int i=ADDRESS_SIZE;i<ADDRESS_SIZE*2;i++)
    {
        first_block.data[i]=new_address.byte[i-ADDRESS_SIZE];
    }
    buffer->write_data(header_address,&first_block);
}
void Record::get_block_data(Block block,int seed,int size,char* data)
{
    for (int i=seed;i<size+seed;i++)
    {
        data[i-seed]=block[i];
    }
}
void Record::fill_block_data(Block* block,int seed,int size,char* data)
{
    for (int i=seed;i<size+seed;i++)
    {
        (*block)[i]=data[i-seed];
    }
}
void Record::delete_tuple(Table_info table,Address address)
{
    Address_byte next,previous,deleted_address,now_address;
    Address header_address;
    header_address.database_name=table.database;
    header_address.file_name=table.table_name;
    header_address.file_offset=0;
    Block header;
    buffer->read_data(header_address, &header);
    //deal the free list
    get_block_data(header, 0, ADDRESS_SIZE, deleted_address.byte);
    now_address.address=address.file_offset*BLOCK_SIZE+address.block_offset;
    fill_block_data(&header, 0, ADDRESS_SIZE, now_address.byte);
    buffer->write_data(header_address, &header);
    Block block;
    buffer->read_data(address,&block);
    int size=table.tuple_size;
    get_block_data(block, address.block_offset+size, ADDRESS_SIZE, next.byte);
    get_block_data(block, address.block_offset+size+ADDRESS_SIZE, ADDRESS_SIZE, previous.byte);
    fill_block_data(&block, address.block_offset, ADDRESS_SIZE, deleted_address.byte);
    buffer->write_data(address, &block);
    //deal the real list
    if (previous.address==0)
    {
        buffer->read_data(header_address,&header);
        fill_block_data(&header, ADDRESS_SIZE*2, ADDRESS_SIZE, next.byte);
        buffer->write_data(header_address,&header);
    }
    else
    {
        Block pre_block;
        Address previous_address=int_to_address(table, previous.address);
        buffer->read_data(previous_address, &pre_block);
        fill_block_data(&pre_block, previous_address.block_offset+size, ADDRESS_SIZE, next.byte);
        buffer->write_data(previous_address, &pre_block);
    }
    Block next_block;
    Address next_address=int_to_address(table, next.address);
    buffer->read_data(next_address, &next_block);
    fill_block_data(&next_block, next_address.block_offset+size+ADDRESS_SIZE, ADDRESS_SIZE, previous.byte);
    buffer->write_data(next_address, &next_block);
    
}
void Record::delete_all_tuple(Table_info table)
{
    drop_table(table);
    create_table(table);
}
void Record::get_first_tuple(Table_info table, Tuple_info *tuple, Address *next_address)
{
    Address header_address=int_to_address(table, 0);
    Block header;
    buffer->read_data(header_address, &header);
    Address_byte begin_address;
    get_block_data(header, ADDRESS_SIZE*2, ADDRESS_SIZE, begin_address.byte);
    Address address=int_to_address(table, begin_address.address);
    get_tuple(table,address,tuple,next_address);
}
void Record::get_tuple(Table_info table,Address address,Tuple_info* tuple,Address* next_address)
{
    Block block;
    buffer->read_data(address, &block);
    Tuple_data tuple_data(table.tuple_size);
    get_block_data(block, address.block_offset, table.tuple_size, tuple_data.data);
    Address_byte next;
    get_block_data(block, address.block_offset+table.tuple_size, ADDRESS_SIZE, next.byte);
    (*next_address)=int_to_address(table, next.address);
    unpack(table, tuple, &tuple_data);

}
void Record::drop_table(Table_info table)
{
    Address address;
    address.database_name=table.database;
    address.file_name=table.table_name;
    buffer->remove_file(address);
}
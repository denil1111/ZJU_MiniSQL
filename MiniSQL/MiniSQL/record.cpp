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
            case 1:
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
            case 2:
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
            case 3:
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
    int j=0;
    for (int i=0;i<table.attribute_list.size();i++)
    {
        std::stringstream ss("");
        int size=table.attribute_list[i].size;
        switch (table.attribute_list[i].type)
        {
            case 1:
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
            case 2:
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
            case 3:
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

void Record::insert(Table_info table,Tuple_info tuple)
{
    Tuple_data tuple_data(table.tuple_size);
    pack(table,tuple,&tuple_data);
    Address header_address;
    header_address.database_name=table.database;
    header_address.file_name=table.table_name;
    header_address.file_offset=0;
    Block header;
    buffer.read_data(header_address, &header);
    union
    {
        unsigned char byte[ADDRESS_SIZE];
        unsigned int address;
    }deleted_address_data,new_address_data,next_address_data,begin_address_data;
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
    Address address=header_address;
    if (deleted_address!=0)
    {
        Block filled_data;
        address.file_offset=deleted_address/BLOCK_SIZE;
        address.block_offset=deleted_address%BLOCK_SIZE;
        buffer.read_data(address, &filled_data);
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
        buffer.write_data(header_address, &header);
    }
    else
    {
        address.file_offset=new_address/BLOCK_SIZE;
        address.block_offset=new_address%BLOCK_SIZE;
        /*change begin_address in header*/
        for (int i=0;i<ADDRESS_SIZE;i++)
        {
            header[i+ADDRESS_SIZE*2]=deleted_address_data.byte[i];
        }
        buffer.write_data(header_address, &header);

    }
    /* fill new tuple and write */
    for (int i=0;i<tuple_data.size;i++)
    {
        data[i+address.block_offset]=tuple_data.data[i];
    }
    for (int i=0;i<ADDRESS_SIZE;i++)
    {
        data[i+address.block_offset+tuple_data.size]=begin_address_data.byte[i];
        
    }
    buffer.write_data(address, &data);
}
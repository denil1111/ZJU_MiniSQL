//
//  storage.cpp
//  MiniSQL
//
//  Created by zyhc on 10/27/14.
//  Copyright (c) 2014 zyhc. All rights reserved.
//

#include "storage.h"
#include <string>
#include "error.h"
#include <stdio.h>
#include <iostream>
void Block::get_block_data(int seed,int size,unsigned char* data)
{
    for (int i=seed;i<size+seed;i++)
    {
        data[i-seed]=(*this)[i];
    }
}
void Block::fill_block_data(int seed,int size,unsigned char* data)
{
    for (int i=seed;i<size+seed;i++)
    {
        (*this)[i]=data[i-seed];
    }
}

void Block::copy(unsigned char* new_data)
{
    for (int i=0;i<BLOCK_SIZE;i++)
    {
        data[i]=new_data[i];
    }
}
void Storage::read_data(Address address,Block* block_data){
    std:: string full_path=address.database_name+"/"+address.file_name;
    FILE *file=fopen(full_path.c_str(),"rb+");
    if (file==NULL)
    {
        Error error(0);
        throw error;
    }
    fseek(file,address.file_offset*BLOCK_SIZE,SEEK_SET);
    unsigned char temp_data[BLOCK_SIZE];
    size_t res;
    res=fread(temp_data,BLOCK_SIZE,1,file);
    if (res==0)
    {
        Error error(0);
        throw error;
    }
    block_data->copy(temp_data);
    fclose(file);
}
void Storage::write_data(Address address,const Block* block_data)
{
    std:: string full_path=address.database_name+"/"+address.file_name;
    FILE *file=fopen(full_path.c_str(),"rb+");
    if (file==NULL)
    {
        Error error(0);
        throw error;
    }
    fseek(file,address.file_offset*BLOCK_SIZE,SEEK_SET);
    size_t res;
    res=fwrite(block_data->data,BLOCK_SIZE,1,file);
    if (res==0)
    {
        Error error(0);
        throw error;
    }
    fclose(file);
}
void Storage::create_file(Address address)
{
    std:: string full_path=address.database_name+"/"+address.file_name;
    FILE *file=fopen(full_path.c_str(),"w");
    fclose(file);
}
void Storage::remove_file(Address address)
{
    std:: string full_path=address.database_name+"/"+address.file_name;
    remove(full_path.c_str());
}
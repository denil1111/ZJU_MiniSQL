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
Block Storage::read_data(Address address){
    std:: string full_path=address.database_name+"/"+address.file_name;
    FILE *file=fopen(full_path.c_str(),"rb");
    if (file==NULL)
    {
        Error error(0);
        throw error;
    }
    unsigned char temp_data[BLOCK_SIZE];
    size_t res;
    res=fread(temp_data,BLOCK_SIZE,1,file);
    if (res==0)
    {
        Error error(0);
        throw error;
    }
    Block read_block(temp_data);
    return read_block;
}
void Storage::write_data(Address address,Block block_data){
    std:: string full_path=address.database_name+"/"+address.file_name;
    FILE *file=fopen(full_path.c_str(),"wb");
    if (file==NULL)
    {
        Error error(0);
        throw error;
    }
    size_t res;
    res=fwrite(block_data.data,BLOCK_SIZE,1,file);
    if (res==0)
    {
        Error error(0);
        throw error;
    }

}

//
//  buffer.cpp
//  MiniSQL
//
//  Created by zyhc on 10/28/14.
//  Copyright (c) 2014 zyhc. All rights reserved.
//

#include "buffer.h"
void Buffer::remove_block_when_full()
{
    if (buffer_list.size()==MAX_BUFFER_SIZE)
    {
        Buffer_info temp;
        temp=buffer_list[0];
        disk.write_data(temp.address,&temp.data);
        buffer_list.erase(buffer_list.begin());
    }

}
void Buffer::read_data(Address address, Block *data)
{
    bool in_buffer;
    in_buffer=false;
    /* check if the data is in Buffer*/
    for (int i=0;i<buffer_list.size();i++)
    {
        if (buffer_list[i].address.block_equal(address))
        {
            Buffer_info temp;
            temp=buffer_list[i];
            data->copy(temp.data);
            buffer_list.erase(buffer_list.begin()+i);
            buffer_list.push_back(temp);
            in_buffer=true;
            return;
        }
    }
    /*not in buffer*/
    if (!in_buffer)
    {
        remove_block_when_full();
        Buffer_info temp;
        temp.address=address;
        disk.read_data(address, &temp.data);
        data->copy(temp.data);
        buffer_list.push_back(temp);
    }
}
void Buffer::write_data(Address address,const Block* data)
{
    bool in_buffer;
    in_buffer=false;
    for (int i=0;i<buffer_list.size();i++)
    {
        if (buffer_list[i].address.block_equal(address))
        {
            Buffer_info temp;
            temp=buffer_list[i];
            buffer_list.erase(buffer_list.begin()+i);
            temp.data.copy(*data);
            buffer_list.push_back(temp);
            in_buffer=true;
            return;
        }
    }
    if (!in_buffer)
    {
        remove_block_when_full();
        Buffer_info temp;
        temp.address=address;
        temp.data.copy(*data);
        buffer_list.push_back(temp);
    }
}
Buffer::~Buffer()
{
    for (int i=0;i<buffer_list.size();i++)
    {
        disk.write_data(buffer_list[i].address, &buffer_list[i].data);
    }
}

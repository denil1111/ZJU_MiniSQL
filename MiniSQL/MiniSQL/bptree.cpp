//
//  bptree.cpp
//  MiniSQL
//
//  Created by zyhc on 11/9/14.
//  Copyright (c) 2014 zyhc. All rights reserved.
//

#include "bptree.h"
#include <sstream>
Buffer* Key_type::buffer;
Buffer* Bptree::buffer;
void String_key::assign(std::string data)
{
    std::stringstream ss;
    ss<<data;
    ss>>key.key_str;
}
void String_key::get_byte(char* bytes)
{
    for (int i=0;i<key.size;i++)
    {
        bytes[i]=key.key_str[i];
    }
}
void Int_key::assign(std::string data)
{
    std::stringstream ss;
    ss<<data;
    ss>>key.key_int;
}
void Int_key::get_byte(char* bytes)
{
    //use address byte because 32bit int
    Address_byte int32;
    int32.address=key.key_int;
    for (int i=0;i<key.size;i++)
    {
        bytes[i]=int32.byte[i];
    }
}
void Float_key::assign(std::string data)
{
    std::stringstream ss;
    ss<<data;
    ss>>key.key_float;
}
void Float_key::get_byte(char* bytes)
{
    //use address byte because 32bit int
    union
    {
        float data;
        unsigned char byte[32];
    }float32;
    float32.data=key.key_float;
    for (int i=0;i<key.size;i++)
    {
        bytes[i]=float32.byte[i];
    }
}

Bptree_node::Bptree_node(int count, type_enum type, int size)
{
    number=0;
    for (int i=0;i<count;i++)
    {
        Key_type* temp;
        switch (type) {
            case INT:
                temp=new Int_key();
                break;
            case FLOAT:
                temp=new Float_key();
            case STRING:
                temp=new String_key(size);
        }
        key.push_back(temp);
    }
    link=new Address[size+1];
}
void Bptree_node::write_back(Address address)
{
    Block block;
    block[0]=leaf;
    for (int i=0;i<size+1;i++)
    {
        
    }
    
}
void Bptree::create(Table_info table,Attribute attribute)
{
    
    max_branch_number=(BLOCK_SIZE-ADDRESS_SIZE-1)/(ADDRESS_SIZE+attribute.size);
    /*make the header block*/
    /*...*/
    root=new Bptree_node(max_branch_number,attribute.type,attribute.size);
    std::string filename="index_"+table.table_name+"_"+attribute.name;
    Address address;
    address.database_name=table.database;
    address.file_name=filename;
    disk.create_file(address);
    Address header_address(table.database,table.table_name,0);
    Block header;
    Address_byte initial;
    initial.address=1;
    header.fill_block_data(0, ADDRESS_SIZE, initial.byte);
    header.fill_block_data(ADDRESS_SIZE, ADDRESS_SIZE, initial.byte);
    buffer->write_data(header_address, &header);
    Block root;
    /*write the first root (NULL)*/
    /*write writ-back function of node*/
    
}
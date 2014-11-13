//
//  bptree.cpp
//  MiniSQL
//
//  Created by zyhc on 11/9/14.
//  Copyright (c) 2014 zyhc. All rights reserved.
//

#include "bptree.h"
#include <sstream>
Buffer* Bptree::buffer;
Buffer* Bptree_node::buffer;
//String key
void String_key::assign(std::string data)
{
    std::stringstream ss;
    ss<<data;
    ss>>key.key_str;
}
void String_key::get_byte(unsigned char* bytes)
{
    for (int i=0;i<key.size;i++)
    {
        bytes[i]=key.key_str[i];
    }
}
void String_key::read_byte(unsigned char* byte)
{
    for (int i=0;i<key.size;i++)
    {
        key.key_str[i]=byte[i];
    }
}
//Int key
void Int_key::assign(std::string data)
{
    std::stringstream ss;
    ss<<data;
    ss>>key.key_int;
}
void Int_key::get_byte(unsigned char* bytes)
{
    //use address byte because 32bit int
    Address_byte int32;
    int32.address=key.key_int;
    for (int i=0;i<key.size;i++)
    {
        bytes[i]=int32.byte[i];
    }
}
void Int_key::read_byte(unsigned char* byte)
{
    Address_byte int32;
    for (int i=0;i<key.size;i++)
    {
        int32.byte[i]=byte[i];
    }
    key.key_int=int32.address;
}

//Float key
void Float_key::assign(std::string data)
{
    std::stringstream ss;
    ss<<data;
    ss>>key.key_float;
}
void Float_key::get_byte(unsigned char* bytes)
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
void Float_key::read_byte(unsigned char* bytes)
{
    //use address byte because 32bit int
    union
    {
        float data;
        unsigned char byte[32];
    }float32;
   
    for (int i=0;i<key.size;i++)
    {
        float32.byte[i]=bytes[i];
    }
    key.key_float=float32.data;
}
//node
Bptree_node::Bptree_node(int count, type_enum type, int size)
{
    number=0;
    for (int i=0;i<count;i++)
    {
        Key_type* temp;
        switch (type) {
            case SQL_INT:
                temp=new Int_key();
                break;
            case SQL_FLOAT:
                temp=new Float_key();
                break;
            case SQL_STRING:
                temp=new String_key(size);
                break;
        }
        key.push_back(temp);
    }
    this->size=size;
    link=new Address[size+1];
}

void Bptree_node::write_back(Address address)
{
    Block block;
    block[0]=leaf;
    for (int i=0;i<size+1;i++)
    {
        Address_byte address_byte;
        address_byte.address=link[i].address_int();
        block.fill_block_data(i*ADDRESS_SIZE+1, ADDRESS_SIZE, address_byte.byte);
    }
    for (int i=0;i<size;i++)
    {
        unsigned char data[size];
        key[i]->get_byte(data);
        block.fill_block_data(size*ADDRESS_SIZE+1+i*size, size, data);
    }
    buffer->write_data(address,&block);
}

void Bptree_node::read_from(Address address)
{
    Block block;
    buffer->read_data(address, &block);
    leaf=block[0];
    for (int i=0;i<size+1;i++)
    {
        Address_byte address_byte;
        block.get_block_data(i*ADDRESS_SIZE+1, ADDRESS_SIZE, address_byte.byte);
        link[i]=Address(address.database_name,address.file_name,address_byte.address);
        if (address_byte.address==0)
        {
            number=0;
        }
    }
    for (int i=0;i<size;i++)
    {
        unsigned char data[size];
        block.get_block_data(size*ADDRESS_SIZE+1+i*size, size, data);
        key[i]->read_byte(data);
    }
}
//tree
void Bptree::create(Table_info table,Attribute attribute)
{
    this->attribute=attribute;
    Bptree_node *root=new_node();
    /*make the header block*/
    /*...*/
    filename="index_"+table.table_name+"_"+attribute.attribute_name;
    Address address;
    address.database_name=table.database;
    address.file_name=filename;
    disk.create_file(address);
    Address header_address(table.database,filename,0);
    Block header;
    Address_byte initial;
    initial.address=BLOCK_SIZE;
    header.fill_block_data(0, ADDRESS_SIZE, initial.byte);
    header.fill_block_data(ADDRESS_SIZE, ADDRESS_SIZE, initial.byte);
    buffer->write_data(header_address, &header);
    Address root_address(table.database,filename,BLOCK_SIZE);
    root->write_back(root_address);
    delete root;
    /*write the first root (NULL)*/
    /*write writ-back function of node*/
}

Bptree_node* Bptree::new_node()
{
    max_branch_number=(BLOCK_SIZE-ADDRESS_SIZE-1)/(ADDRESS_SIZE+attribute.size);
    return new Bptree_node(max_branch_number,attribute.type,attribute.size);
}

void Bptree::get_root(Table_info table, Attribute attribute)
{
    this->attribute=attribute;
    /*make the header block*/
    /*...*/
    root=new_node();
    filename="index_"+table.table_name+"_"+attribute.attribute_name;
    Address address;
    address.database_name=table.database;
    address.file_name=filename;
    address.block_offset=0;
    root->read_from(address);
}

Address Bptree::search(Table_info table,Attribute attribute,std::string value)
{
    get_root(table, attribute);
    bool flag=true;
    Bptree_node* now=root;
    Key_type *target;
    Address null_value(table.database,filename,0);
    switch (attribute.type)
    {
        case SQL_INT:target=new Int_key;break;
        case SQL_FLOAT:target=new Float_key;break;
        case SQL_STRING:target=new String_key(attribute.size);break;
    }
    while (flag)
    {
        if (now->leaf==0)
        {
            for (int i=0;i<now->number;i++)
            {
                if (now->key[i]->not_bigger_than(target))
                {
                    now->read_from(now->link[i]);
                    break;
                }
            }
        }
        else
        {
            for (int i=0;i<now->number;i++)
            {
                if (now->key[i]->equal(target))
                {
                    return now->link[i];
                }
            }
            return null_value;
        }
        
    }
    return null_value;
}

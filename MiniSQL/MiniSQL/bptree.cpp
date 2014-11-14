//
//  bptree.cpp
//  MiniSQL
//
//  Created by zyhc on 11/9/14.
//  Copyright (c) 2014 zyhc. All rights reserved.
//

#include "bptree.h"
#include "error.h"
#include <sstream>
Buffer* Bptree::buffer;
Buffer* Bptree_node::buffer;
//String key
std::string String_key::str()
{
    std::stringstream ss;
    std::string ret;
    ss<<key.key_str;
    ss>>ret;
    return ret;
}
void String_key::assign(std::string data)
{
    std::stringstream ss;
    ss<<data;
    ss>>key.key_str;
}
void String_key::get_byte(unsigned char* bytes)
{
    for (int i=0;i<size;i++)
    {
        bytes[i]=key.key_str[i];
    }
}
void String_key::read_byte(unsigned char* byte)
{
    for (int i=0;i<size;i++)
    {
        key.key_str[i]=byte[i];
    }
}
//Int key
std::string Int_key::str()
{
    std::stringstream ss;
    std::string ret;
    ss<<key.key_int;
    ss>>ret;
    return ret;
}
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
    for (int i=0;i<size;i++)
    {
        bytes[i]=int32.byte[i];
    }
}
void Int_key::read_byte(unsigned char* byte)
{
    Address_byte int32;
    for (int i=0;i<size;i++)
    {
        int32.byte[i]=byte[i];
    }
    key.key_int=int32.address;
}

//Float key
std::string Float_key::str()
{
    std::stringstream ss;
    std::string ret;
    ss<<key.key_float;
    ss>>ret;
    return ret;
}
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
    for (int i=0;i<size;i++)
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
   
    for (int i=0;i<size;i++)
    {
        float32.byte[i]=bytes[i];
    }
    key.key_float=float32.data;
}
//node
Bptree_node::Bptree_node(int count, type_enum type, int size)
{
    number=0;
    max_count=count;
    for (int i=0;i<=count;i++)
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
        deleted.push_back(false);
    }
    this->size=size;
    link=new Address[count+1];
}

void Bptree_node::write_back(Address address)
{
    Block block;
    block[0]=leaf;
    for (int i=0;i<max_count+1;i++)
    {
        Address_byte address_byte;
        address_byte.address=link[i].address_int();
        block.fill_block_data(i*ADDRESS_SIZE+1, ADDRESS_SIZE, address_byte.byte);
    }
    for (int i=0;i<max_count;i++)
    {
        unsigned char data[size];
        key[i]->get_byte(data);
        block.fill_block_data((max_count+1)*ADDRESS_SIZE+1+i*size, size, data);
    }
    for (int i=0;i<max_count;i++)/*only write number, keep other 0*/
    {
        union
        {
            bool tf;
            unsigned char data[1];
        }byte;
        byte.tf=deleted[i];
        block.fill_block_data((max_count+1)*ADDRESS_SIZE+1+max_count*size+i, 1, byte.data);
        
    }
    buffer->write_data(address,&block);
}

void Bptree_node::read_from(Address address)
{
    Block block;
    buffer->read_data(address, &block);
    leaf=block[0];
    number=max_count;
    bool flag=false;
    for (int i=0;i<max_count+1;i++)
    {
        Address_byte address_byte;
        block.get_block_data(i*ADDRESS_SIZE+1, ADDRESS_SIZE, address_byte.byte);
        link[i]=Address(address.database_name,address.file_name,address_byte.address);
        if (address_byte.address==0)
        {
            if (!flag)
            {
//                if (i==0)
//                    number=0;
//                else
                number=i-1;
                flag=true;
            }
        }
    }
    //now right link of leaf
    if (leaf && number<max_count)
    {
        number=number+1;
    }
    for (int i=0;i<max_count;i++)
    {
        unsigned char data[size];
        block.get_block_data((max_count+1)*ADDRESS_SIZE+1+i*size, size, data);
        key[i]->read_byte(data);
    }
    for (int i=0;i<max_count;i++)
    {
        union
        {
            bool deleted;
            unsigned char data[1];
        }bool_byte;
        block.get_block_data(max_count*ADDRESS_SIZE+1+max_count*size+i, 1, bool_byte.data);
        deleted[i]=bool_byte.deleted;
    }
}
//tree
void Bptree::create(Table_info table,Attribute attribute)
{
    this->attribute=attribute;
    root=new_node();
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
    initial.address=BLOCK_SIZE*2;
    header.fill_block_data(ADDRESS_SIZE, ADDRESS_SIZE, initial.byte);
    buffer->write_data(header_address, &header);
    root->leaf=true;
    Address root_address(table.database,filename,BLOCK_SIZE);
    root->write_back(root_address);
    /*write the first root (NULL)*/
    /*write writ-back function of node*/
}

Bptree_node* Bptree::new_node()
{
    max_branch_number=(BLOCK_SIZE-ADDRESS_SIZE-1)/(ADDRESS_SIZE+attribute.size+1);
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
    address.file_offset=0;
    Block header;
    buffer->read_data(address, &header);
    Address_byte address_byte;
    header.get_block_data(0, ADDRESS_SIZE, address_byte.byte);
    root_address.database_name=table.database;
    root_address.file_name=filename;
    root_address.file_offset=address_byte.address/BLOCK_SIZE;
    root->read_from(root_address);
}

void Bptree::deletion(Table_info table,Attribute attribute,std::string value)
{
    get_root(table, attribute);
    bool flag=true;
    Bptree_node* now=root;
    Key_type *target;
    switch (attribute.type)
    {
        case SQL_INT:target=new Int_key;break;
        case SQL_FLOAT:target=new Float_key;break;
        case SQL_STRING:target=new String_key(attribute.size);break;
    }
    Address null_value(table.database,filename,0);
    while (flag)
    {
        if (now->leaf==0)
        {
            for (int i=0;i<now->number;i++)
            {
                if (target->not_bigger_than(now->key[i]))
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
                if (target->equal(now->key[i]))
                {
                    if (now->deleted[i]==0)
                        now->deleted[i]=1;
                    else
                    {
                        Error error(5);
                        throw error;
                    }
                }
            }
            Error error(5);
            throw error;

        }
        
    }
}

Address Bptree::search(Table_info table,Attribute attribute,std::string value)
{
    get_root(table, attribute);
    bool flag=true;
    Bptree_node* now=root;
    Key_type *target;
    switch (attribute.type)
    {
        case SQL_INT:target=new Int_key;break;
        case SQL_FLOAT:target=new Float_key;break;
        case SQL_STRING:target=new String_key(attribute.size);break;
    }
    target->assign(value);
    Address null_value(table.database,filename,0);
    while (flag)
    {
        if (now->leaf==0)
        {
            for (int i=0;i<now->number;i++)
            {
                if (target->not_bigger_than(now->key[i]))
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
                if (target->equal(now->key[i]))
                {
                    if (now->deleted[i]==0)
                    {
                        now->link[i].file_name=table.table_name;
                        return now->link[i];
                    }
                    else
                        return null_value;
                }
            }
            return null_value;
        }
        
    }
    return null_value;
}

void Bptree::insert(Table_info table,Attribute attribute,std::string value,Address record_address)
{
    get_root(table, attribute);
    Address child_new_address;
    std::string child_new_value;
    bool splited=node_insert(root_address,value,record_address,&child_new_address,&child_new_value);
    if (splited)
    {
        Address new_root_address=new_block();
        Bptree_node *new_root=new_node();
        new_root->number=1;
        new_root->key[0]->assign(child_new_value);
        new_root->link[0]=root_address;
        new_root->link[1]=child_new_address;
        new_root->write_back(new_root_address);
        delete root;
        root=new_root;
        root_address=new_root_address;
        Address header_address(table.database,filename,0);
        Block header;
        buffer->read_data(header_address, &header);
        Address_byte root_address_byte;
        root_address_byte.address=new_root_address.address_int();
        header.fill_block_data(0, ADDRESS_SIZE, root_address_byte.byte);
        buffer->write_data(header_address, &header);
    }
}

Address Bptree::new_block()
{
    Address address(root_address.database_name,root_address.file_name,0);
    Block header;
    buffer->read_data(address,&header);
    Address_byte new_address_byte;
    header.get_block_data(ADDRESS_SIZE, ADDRESS_SIZE, new_address_byte.byte);
    Address ret(root_address.database_name,root_address.file_name,new_address_byte.address);
    new_address_byte.address+=BLOCK_SIZE;
    header.fill_block_data(ADDRESS_SIZE, ADDRESS_SIZE, new_address_byte.byte);
    buffer->write_data(address, &header);
    return ret;
}

bool Bptree::node_insert(Address current, std::string value, Address record_address, Address* new_address, std::string *new_value)
{
    Address null_value(root_address.database_name,filename,0);
    Bptree_node *now=root;
    now->read_from(current);
    bool flag=true;
    Key_type *target;
    switch (attribute.type)
    {
        case SQL_INT:target=new Int_key;break;
        case SQL_FLOAT:target=new Float_key;break;
        case SQL_STRING:target=new String_key(attribute.size);break;
    }
    target->assign(value);
    int loc = 0;
    for (loc=0;loc<now->number;loc++)
    {
        if (target->not_bigger_than(now->key[loc]))
        {
            break;
        }
    }
    while (flag)
    {
        if (now->leaf==1)
        {
            /*when equal, if deleted?not?*/
            if (target->equal(now->key[loc]))
            {
                if (now->deleted[loc]==1)
                {
                    now->link[loc]=record_address;
                    now->deleted[loc]=0;
                    now->write_back(current);
                }
                else
                {
                    Error error(5);
                    throw error;
                }
            }
            if (now->number<max_branch_number)
            {
                //not split
                for (int i=max_branch_number-1;i>loc;i--)
                {
                    now->key[i]->assign(now->key[i-1]->str());
                    now->link[i]=now->link[i-1];
                }
                now->key[loc]->assign(value);
                now->link[loc]=record_address;
                now->number++;
                now->write_back(current);
                return false;
            }
            else
            {
                //split

                Bptree_node *right=new_node();
                int j=0;
                for (int i=max_branch_number-1;i>loc;i--)
                {
                    now->key[i]->assign(now->key[i-1]->str());
                    now->link[i]=now->link[i-1];
                }
                now->key[loc]->assign(value);
                now->link[loc]=record_address;
                now->number++;
                for (int i=now->number/2;i<max_branch_number;i++)
                {
                    right->key[j]->assign(now->key[i]->str());
                    right->link[j]=now->link[i];
                    right->deleted[j]=now->deleted[i];
                    now->deleted[i]=false;
                    now->link[i]=null_value;
                    j++;
                }
                int all=now->number;
                *new_value=now->key[all/2]->str();
                now->number=all/2;
                right->number=all-all/2;
                right->link[max_branch_number]=now->link[max_branch_number];
                Address right_address=new_block();
                *new_address=right_address;
                now->link[max_branch_number]=right_address;
                right->write_back(right_address);
                now->write_back(current);
                delete right;
                return true;
                
            }
            
        }
        else
        {
            Address child_new_address;
            std::string child_new_value;
            bool splited=node_insert(root_address,value,record_address,&child_new_address,&child_new_value);
            if (splited==false)
            {
                return false;
            }
            else
            {
                if (now->number<max_branch_number)
                {
                    for (int i=max_branch_number-1;i>loc;i--)
                    {
                        now->key[i]->assign(now->key[i-1]->str());
                        now->link[i]=now->link[i-1];
                    }
                    now->key[loc]->assign(child_new_value);
                    now->link[loc]=child_new_address;
                }
                else
                {
                    Bptree_node *right=new_node();
                    for (int i=max_branch_number-1;i>loc;i--)
                    {
                        now->key[i]->assign(now->key[i-1]->str());
                        now->link[i]=now->link[i-1];
                    }
                    now->key[loc]->assign(child_new_value);
                    now->link[loc]=child_new_address;
                    now->number++;
                    int j=0;
                    for (int i=now->number/2;i<max_branch_number;i++)
                    {
                        right->key[j]->assign(now->key[i]->str());
                        right->link[j]=now->link[i];
                        now->link[i]=null_value;
                        j++;
                    }
                    int all=now->number;
                    *new_value=now->key[all/2]->str();
                    now->number=all/2;
                    right->number=all-all/2;
                    right->link[max_branch_number]=now->link[max_branch_number];
                    Address right_address=new_block();
                    *new_address=right_address;
                    now->link[max_branch_number]=null_value;
                    right->write_back(right_address);
                    now->write_back(current);
                    delete right;
                    return true;

                    
                }
            }
        }
    }
    delete target;
    return false;
}

void Bptree::test(Table_info table,Attribute attribute)
{
//    Bptree_node *node=new_node();
//    node->leaf=1;
//    node->key[1]->assign("44.3");
//    node->key[0]->assign("31.2");
//    Address address(table.database,filename,BLOCK_SIZE*2);
//    node->link[0]=address;
//    node->write_back(address);
//    delete node;
//    node=new_node();
//    node->read_from(address);
    
    
}
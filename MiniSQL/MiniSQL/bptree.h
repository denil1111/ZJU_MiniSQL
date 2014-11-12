//
//  bptree.h
//  MiniSQL
//
//  Created by zyhc on 11/9/14.
//  Copyright (c) 2014 zyhc. All rights reserved.
//

#ifndef __MiniSQL__bptree__
#define __MiniSQL__bptree__

#include <stdio.h>
#include "record.h"
#include "buffer.h"
#include "storage.h"
class Key_type
{
public:
    static Buffer* buffer;
    union
    {
        char* key_str;
        int size;
        float key_float;
        int key_int;
    }key;
    Key_type(){};
    virtual void assign(std::string data);
    virtual bool compare(Key_type*);
    virtual void get_byte(char* byte);
};
class String_key: public Key_type
{
public:
    String_key(int size)
    {
        key.key_str=new char[size];
    }
    void assign(std::string data);
    bool compare(Key_type* another)
    {
        return key.key_str>another->key.key_str;
    }
    ~String_key()
    {
        delete [] key.key_str;
    }
    void get_byte(char* byte);
};
class Int_key: public Key_type
{
public:
    Int_key(){}
    void assign(std::string data);
    bool compare(Key_type* another)
    {
        return key.key_int>another->key.key_int;
    }
    void get_byte(char* byte);

};
class Float_key: public Key_type
{
public:
    Float_key(){}
    void assign(std::string data);
    bool compare(Key_type* another)
    {
        return key.key_float>another->key.key_float;
    }
    virtual void get_byte(char* byte);    
};
class Bptree_node
{
public:
    int number;
    std::vector<Key_type*> key;
    bool leaf;
    Address *link;
    Bptree_node(int count, type_enum type, int size);
    void write_back(Address);
    void read_from(Address);
    ~Bptree_node()
    {
        for (int i=0;i<key.size();i++)
        {
            delete key[i];
        }
    }
};
class Bptree
{
private:
    Bptree_node *root;
    int max_branch_number;
//    Buffer * buffer;
    Storage disk;
    
public:
    static Buffer* buffer;
    Bptree(Storage disk)
    {
        this->disk=disk;
    }
    void get_root(Table_info,Attribute attribute)
    {
        
    }
    void create(Table_info table,Attribute attribute);

    
};
#endif /* defined(__MiniSQL__bptree__) */

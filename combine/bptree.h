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
    union
    {
        char* key_str;
        float key_float;
        int key_int;
    }key;
    int size;
    Key_type(){}
    virtual ~Key_type(){}
    virtual void assign(std::string data)=0;
    virtual bool not_bigger_than(Key_type*)=0;
    virtual bool equal(Key_type*)=0;
    virtual std::string str()=0;
    virtual void get_byte(unsigned char* byte)=0;
    virtual void read_byte(unsigned char* byte)=0;
};
class String_key: public Key_type
{
public:
    String_key(int size)
    {
        key.key_str=new char[size];
        this->size=size;
    }
    void assign(std::string data);
    std::string str();
    bool not_bigger_than(Key_type* another)
    {

        return strcmp(key.key_str,another->key.key_str)<=0;
    }
    bool equal(Key_type* another)
    {
        return strcmp(key.key_str,another->key.key_str)==0;
    }
    ~String_key()
    {
        delete [] key.key_str;
    }
    void get_byte(unsigned char* byte);
    void read_byte(unsigned char* byte);
};
class Int_key: public Key_type
{
public:
    Int_key()
    {
        size=4;
    }
    void assign(std::string data);
    std::string str();
    bool not_bigger_than(Key_type* another)
    {
        return key.key_int<=another->key.key_int;
    }
    bool equal(Key_type* another)
    {
        return key.key_int==another->key.key_int;
    }
    void get_byte(unsigned char* byte);
    void read_byte(unsigned char* byte);

};
class Float_key: public Key_type
{
public:
    Float_key()
    {
        size=4;
    }
    void assign(std::string data);
    std::string str();
    bool not_bigger_than(Key_type* another)
    {
        return key.key_float<=another->key.key_float;
    }
    bool equal(Key_type* another)
    {
        return key.key_float==another->key.key_float;
    }
    void get_byte(unsigned char* byte);
    void read_byte(unsigned char* byte);
};
class Bptree_node
{
public:
    static Buffer* buffer;
    int max_count;
    int number;
    std::vector<Key_type*> key;
    std::vector<bool> deleted;
    bool leaf;
    Address *link;
    int size;
    Bptree_node(int count, type_enum type, int size);
    void write_back(Address);
    void read_from(Address);
    ~Bptree_node()
    {
        for (int i=0;i<key.size();i++)
        {
            delete key[i];
        }
        delete[] link;
    }
};
class Bptree
{
private:
    std::string filename;
    Address root_address;
    Bptree_node *root;
    int max_branch_number;
//    Buffer * buffer;
    Attribute attribute;
    Storage disk;
    Bptree_node *new_node();
    bool node_insert(Address,std::string,Address,Address*,std::string*);
    static int not_smaller_than_start_int;
    static Address not_smaller_than_start_address;
    static int bigger_than_start_int;
    static Address bigger_than_start_address;
    static int smaller_than_end_int;
    static Address smaller_than_end_address;
    static int not_bigger_than_end_int;
    static Address not_bigger_than_end_address;

public:
    static Buffer* buffer;
    Bptree()
    {
    }
    void get_root(Table_info,Attribute);
    void create(Table_info table,Attribute attribute);
    Address search(Table_info,Attribute,std::string);
    void insert(Table_info,Attribute,std::string,Address);
    Address new_block();
    void deletion(Table_info,Attribute,std::string);
    void test(Table_info,Attribute);
    void drop(Table_info,Attribute);
    void print(Table_info,Attribute);
    void print_node(Address);
    void search_section(Table_info table,Attribute attribute,bool left_open,std::string left,bool right_open,std::string right,Address* begin,Address* end);
    ~Bptree()
    {
        delete root;
    }
    
};


#endif /* defined(__MiniSQL__bptree__) */

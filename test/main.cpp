//
//  main.cpp
//  MiniSQL
//
//  Created by zyhc on 10/27/14.
//  Copyright (c) 2014 zyhc. All rights reserved.
//

#include <iostream>
#include "tinyxml.h"
#include "storage.h"
#include "error.h"
#include "buffer.h"
#include "record.h"
#include "bptree.h"
#include "sqltree.hpp"
#include "catalog.h"

// void storage_test()
// {
//     Block* data=new Block();
//     Address address;
//     address.database_name="zyh";
//     address.file_name="friend";
//     address.file_offset=8;
//     Storage storage;
//     try{
//         storage.read_data(address,data);
//         for (int i=0;i<8;i++)
//         {
//             std::cout << (*data)[i];
//         }
//     }
//     catch( Error error)
//     {
//         error.print_error();
//     }
//     unsigned char newdata[BLOCK_SIZE];
//     for (int i=0;i<BLOCK_SIZE;i++)
//     {
//         newdata[i]='s';
//     }
//     Block newblock(newdata);
//     try{
//         storage.write_data(address,&newblock);
//     }
//     catch( Error error)
//     {
//         error.print_error();
//     }

// }
// void buffer_test()
// {
//     Block* data=new Block();
//     Address address;
//     address.database_name="zyh";
//     address.file_name="friend";
//     address.file_offset=8;
//     Buffer buffer;
//     unsigned char newdata[BLOCK_SIZE];
//     for (int i=0;i<BLOCK_SIZE;i++)
//     {
//         newdata[i]='e';
//     }
//     Block newblock1(newdata);
//     buffer.write_data(address,&newblock1);
//     address.database_name="zyh";
//     address.file_name="friend";
//     address.file_offset=9;
//     for (int i=0;i<BLOCK_SIZE;i++)
//     {
//         newdata[i]='9';
//     }
//     Block newblock2(newdata);
//     buffer.write_data(address,&newblock2);
//     address.database_name="zyh";
//     address.file_name="friend";
//     address.file_offset=10;
//     for (int i=0;i<BLOCK_SIZE;i++)
//     {
//         newdata[i]='X';
//     }
//     Block newblock3(newdata);
//     buffer.write_data(address,&newblock3);
//     address.database_name="zyh";
//     address.file_name="friend";
//     address.file_offset=8;
//     for (int i=0;i<BLOCK_SIZE;i++)
//     {
//         newdata[i]='8';
//     }
//     Block newblock4(newdata);
//     buffer.write_data(address,&newblock4);
//     Block readblock;
//     buffer.read_data(address,&readblock);
//     std::cout<<readblock[0]<<std::endl;
//     address.database_name="zyh";
//     address.file_name="friend";
//     address.file_offset=11;
//     for (int i=0;i<BLOCK_SIZE;i++)
//     {
//         newdata[i]='L';
//     }
//     Block newblock5(newdata);
//     buffer.write_data(address,&newblock1);
//     address.file_offset=9;
//     buffer.read_data(address,&readblock);
//     std::cout<<readblock[0]<<std::endl;
//     address.database_name="zyh";
//     address.file_name="friend";
//     address.file_offset=8;
//     for (int i=0;i<BLOCK_SIZE;i++)
//     {
//         newdata[i]='p';
//     }
//     Block newblocknew(newdata);
//     buffer.write_data(address,&newblocknew);
// }

int main()
{
    Buffer buffer;
    // Storage disk;
 	// Catalog init_catalog;
 	// Record record;
    Record::buffer=&buffer;
    Catalog catalog;
    Parse_Node::catalog=&catalog;
    // Bptree_node::buffer=&buffer;
    // Bptree::buffer=&buffer;

    // Database_info database_info;
    // Table_info table_info;
    
    TiXmlDocument doc;
    const char * xmlFile = "catalog.xml";
    
    // Database_info db;
    // db.database_name="ZJU";
    // catalog.database_list.push_back(db);
    // catalog.write_file();

    // init_catalog.read_file();

    if (doc.LoadFile(xmlFile))
    {
        //cout << 1 << endl;
        doc.Print();
    }
    else
    {
        std::cout << "can not parse xml cataolog.xml" << std::endl;
    }
    std::cout << "===inside main===" << std::endl;

    
    //<Databse name="ZJU" />

    try
    {
    	Parse_Node::catalog->read_file();
    	Interpreter intp;
	    intp.run_parser();
	    intp.run_sql();
    
		catalog.write_file();
		if (doc.LoadFile(xmlFile))
		{
		    //cout << 1 << endl;
		    doc.Print();
		}
		else
		{
		    std::cout << "can not parse xml cataolog.xml" << std::endl;
		}

		std::cout << "===after change===" << std::endl;

		return 0;

	}
	catch(Error error)
    {
    	error.print_error();
    }

    return 0;
}

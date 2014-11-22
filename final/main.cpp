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

int main(int ac, char **av)
{
    Buffer buffer;
    Record::buffer=&buffer;
    Catalog catalog;
    Parse_Node::catalog=&catalog;
    Parse_Node::buffer=&buffer;
    Bptree_node::buffer=&buffer;
    Bptree::buffer=&buffer;
    bool flag=false;

    Parse_Node::catalog->read_file();
    while (true)
    {
        try
        {
            char * fn;
            if (ac==1)
            {
                fn="std";
            }
            else
            {
                fn=av[1];
            }
            Interpreter intp;
            intp.run_parser(fn);
            intp.run_sql();
            // if (ac!=1) break;
            
        }
        catch(Error error)
        {
            error.print_error();
        }
        catch(Exit)
        {
            break;
        }
        catch(...)
        {
            Error error(19);
            error.print_error();
        }
    }
    return 0;
}
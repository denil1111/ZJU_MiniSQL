//
//  error.cpp
//  MiniSQL
//
//  Created by zyhc on 10/27/14.
//  Copyright (c) 2014 zyhc. All rights reserved.
//

#include "error.h"
#include <iostream>
const std::string Error::error_list[]={
    "database storage failed",  //0
    "database does not exist",  //1
    "table does not exist",  //2
    "table already exists"  //3
};
Error::Error(int number)
{
    error_number=number;
    error_content="";
}
Error::Error(int number,std::string content)
{
    error_number=number;
    error_content=content;
}
void Error::print_error()
{
    std::cout<<error_list[error_number]<<":"<<error_content<<std::endl;
}
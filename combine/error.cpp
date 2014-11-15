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
    "table already exists",  //3
    "database already exists", //4
    "More than 32 attributes", //5
    "Out of char range(1~255)", //6
    "More than 2 primary keys", //7
    "Already have index or attribute is not unique", //8
    "Has no index", //9
    "Has no attribute", //10
    "Unknown kind Fault", //11
    "Cann't +-*/ string", //12
    "Invalid where clause", //13
    "Invalid operation", //14
    "Attribute not exists", //15
    "Duplicated index value", //16
    "Unexist value", //17
    "SQL syntax error",//18
    "Unknown error",//19
    "Exit" //20
};
Error::Error(int number)
{
    error_number=number;
    std::cout<<"in error"<<std::endl;
    error_content="";
    std::cout<<"in error"<<std::endl;
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
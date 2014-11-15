//
//  error.h
//  MiniSQL
//
//  Created by zyhc on 10/27/14.
//  Copyright (c) 2014 zyhc. All rights reserved.
//

#ifndef __MiniSQL__error__
#define __MiniSQL__error__

#include <string>
class Exit{

};
class Error
{
private:
    static const std::string error_list[];
    std::string error_content;
    
public:
	int error_number;
    Error(int);
    Error(int,std::string);
    void print_error();
    
};
#endif /* defined(__MiniSQL__error__) */
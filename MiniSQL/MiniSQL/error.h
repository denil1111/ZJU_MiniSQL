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
class Error
{
private:
    static const std::string error_list[];
    int error_number;
    
public:
    Error(int);
    void print_error();
    
};
const std::string Error::error_list[]={
    "database storage failed",
    "..."
};
#endif /* defined(__MiniSQL__error__) */

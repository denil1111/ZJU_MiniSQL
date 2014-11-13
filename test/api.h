//
//  api.h
//  MiniSQL
//
//  Created by zyhc on 11/9/14.
//  Copyright (c) 2014 zyhc. All rights reserved.
//

#ifndef __MiniSQL__api__
#define __MiniSQL__api__

#include <stdio.h>
#include <vector>
#include "record.h"
#include <string>
struct Table_data
{
    Table_info info;
    std::vector<Tuple_info> tuple_list;
};
class Api
{
public:
    Table_data select_attribute(std::vector<std::string> select_attribute,Table_data table);
//    Table_data select(plan_tree* root);
    
};

#endif /* defined(__MiniSQL__api__) */

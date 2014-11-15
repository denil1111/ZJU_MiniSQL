//
//  buffer.h
//  MiniSQL
//
//  Created by zyhc on 10/28/14.
//  Copyright (c) 2014 zyhc. All rights reserved.
//

#ifndef __MiniSQL__buffer__
#define __MiniSQL__buffer__
#define MAX_BUFFER_SIZE (1024*16)
// #define MAX_BUFFER_SIZE 3 //for test
#include <stdio.h>
#include <vector>
#include "storage.h"
struct Buffer_info
{
    Address address;
    Block data;
};
class Buffer
{
private:
    std::vector<Buffer_info> buffer_list;
    Storage disk;
    void remove_block_when_full();
    void remove_block(int);
public:
    Buffer()
    {
    }
    void read_data(Address,Block*);
    void write_data(Address,const Block*);
    void remove_file(Address);
    ~Buffer();
    
};
#endif /* defined(__MiniSQL__buffer__) */

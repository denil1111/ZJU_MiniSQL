#Buffer test
set buffer size= 3 blocks
##text1:write_data

insert five blocks continously with 4 different address.
the input list is [8,9,10.8,11].

	address.database_name="zyh";
    address.file_name="friend";
    address.file_offset=8;
    Buffer buffer;
    unsigned char newdata[BLOCK_SIZE];
    for (int i=0;i<BLOCK_SIZE;i++)
    {
        newdata[i]='s';
    }
    Block newblock1(newdata);
    buffer.write_data(address,&newblock1);
    address.database_name="zyh";
    address.file_name="friend";
    address.file_offset=9;
    for (int i=0;i<BLOCK_SIZE;i++)
    {
        newdata[i]='s';
    }
    Block newblock2(newdata);
    buffer.write_data(address,&newblock2);
    address.database_name="zyh";
    address.file_name="friend";
    address.file_offset=10;
    for (int i=0;i<BLOCK_SIZE;i++)
    {
        newdata[i]='s';
    }
    Block newblock3(newdata);
    buffer.write_data(address,&newblock3);
    address.database_name="zyh";
    address.file_name="friend";
    address.file_offset=8;
    for (int i=0;i<BLOCK_SIZE;i++)
    {
        newdata[i]='s';
    }
    Block newblock4(newdata);
    buffer.write_data(address,&newblock4);
    address.database_name="zyh";
    address.file_name="friend";
    address.file_offset=11;
    for (int i=0;i<BLOCK_SIZE;i++)
    {
        newdata[i]='s';
    }
    Block newblock5(newdata);
    buffer.write_data(address,&newblock1);
    address.database_name="zyh";
    address.file_name="friend";
    address.file_offset=11;
    for (int i=0;i<BLOCK_SIZE;i++)
    {
        newdata[i]='s';
    }
    buffer.write_data(address,&newblock3);
###test result
####the change of buffer list
	8
	8,9
	8,9
	8,9,10
	9,10,8
	10,8,11
##test2:read and write
test read and write together and check whether the data is write back to the disk.

	Block* data=new Block();
    Address address;
    address.database_name="zyh";
    address.file_name="friend";
    address.file_offset=8;
    Buffer buffer;
    unsigned char newdata[BLOCK_SIZE];
    for (int i=0;i<BLOCK_SIZE;i++)
    {
        newdata[i]='e';
    }
    Block newblock1(newdata);
    buffer.write_data(address,&newblock1);
    address.database_name="zyh";
    address.file_name="friend";
    address.file_offset=9;
    for (int i=0;i<BLOCK_SIZE;i++)
    {
        newdata[i]='9';
    }
    Block newblock2(newdata);
    buffer.write_data(address,&newblock2);
    address.database_name="zyh";
    address.file_name="friend";
    address.file_offset=10;
    for (int i=0;i<BLOCK_SIZE;i++)
    {
        newdata[i]='X';
    }
    Block newblock3(newdata);
    buffer.write_data(address,&newblock3);
    address.database_name="zyh";
    address.file_name="friend";
    address.file_offset=8;
    for (int i=0;i<BLOCK_SIZE;i++)
    {
        newdata[i]='8';
    }
    Block newblock4(newdata);
    buffer.write_data(address,&newblock4);
    Block readblock;
    buffer.read_data(address,&readblock);
    std::cout<<readblock[0]<<std::endl;
    address.database_name="zyh";
    address.file_name="friend";
    address.file_offset=11;
    for (int i=0;i<BLOCK_SIZE;i++)
    {
        newdata[i]='L';
    }
    Block newblock5(newdata);
    buffer.write_data(address,&newblock1);
    address.file_offset=9;
    buffer.read_data(address,&readblock);
    std::cout<<readblock[0]<<std::endl;

###test result
#### the change of the buffer list
	8
	8,9
	8,9,10
	9,10,8
	9,10,8
	10,8,11
	8,11,9
	
#### output
	8
	9
	
##test3:write back
test if the data in the buffer will be written back to the disk when the close the database.add one write near the end of the program.
	    
	address.database_name="zyh";
    address.file_name="friend";
    address.file_offset=8;
    for (int i=0;i<BLOCK_SIZE;i++)
    {
        newdata[i]='p';
    }
    Block newblocknew(newdata);
    buffer.write_data(address,&newblocknew);
 
###test result
the 8th block of the file is all of 'p'.
 

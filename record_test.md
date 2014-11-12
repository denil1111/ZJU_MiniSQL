#record test
##test1: pack and unpack
pack 5 data and unpack them.one of them is "ac" with the size is only 2, which will throw an error.


    Record record;
    Table_info table;
    table.table_name="friend";
    table.database="zyh";
    Attribute attribute;
    Tuple_data tuple_data(90);
    Tuple_info tuple;
    attribute.type=1;
    attribute.size=4;
    table.attribute_list.push_back(attribute);
    attribute.type=3;
    attribute.size=6;
    table.attribute_list.push_back(attribute);
    attribute.type=3;
    attribute.size=4;
    table.attribute_list.push_back(attribute);
    attribute.type=3;
    attribute.size=2;
    table.attribute_list.push_back(attribute);
    attribute.type=3;
    attribute.size=4;
    table.attribute_list.push_back(attribute);
    tuple.info.push_back("44");
    tuple.info.push_back("abcde");
    tuple.info.push_back("ac");
    tuple.info.push_back("ac");
    tuple.info.push_back("ac");
    Tuple_info tuple_unpack;
    for (int i=0;i<5;i++)
        tuple_unpack.info.push_back("");
    try
    {
        record.pack(table,tuple,&tuple_data);
    }
    catch (Error error)
    {
        error.print_error();
    }
    printf("before unpack\n");
      printf("\n");
    record.unpack(table,&tuple_unpack,&tuple_data);
    for (int i=0;i<5;i++)
        std::cout<<tuple_unpack.info[i]<<std::endl;
    for (int i=0;i<30;i++)
        printf("%X  ",tuple_data.data[i]);
###test result
####error:
	data overflow:string is too long
	the input is 44(int) abcde(6) ac(4) ac(3) 44.4(float) 
	
now change the size to 3
###test result
####output
	44
	abcde
	ac
	ac
	44.4
####byte data
	2C  0  0  0  61  62  63  64  65  0  61  63  0  0  61  63  0  FFFFFF9A  FFFFFF99  31  42  0  0  0  0  0  0  0  0  0  
	
##test2: create table
create a new table, write the original header information.(using the tuple before

	table.table_name="friendg";
    table.database="zyh";
    record.create_table(table);
###test result
####binary file
	0000 0000 0c00 0000 0000 0000 0000 0000
	0000 0000 0000 0000 0000 0000 0000 0000
	0000 0000 0000 0000 0000 0000 0000 0000
0c->12(the new address is 12)
##test3: insert tuple
create three tuple one by one
	
	record.insert_tuple(table, tuple_unpack);
    record.insert_tuple(table, tuple_unpack);
    record.insert_tuple(table, tuple_unpack);
    
###test result
####binary file 1
	0000 0000 2900 0000 0c00 0000 2c00 0000
	6162 6364 6500 6163 0000 6163 009a 9931
	4200 0000 0000 0000 0000 0000 0000 0000
####binary file 2
	0000 0000 4600 0000 2900 0000 2c00 0000
	6162 6364 6500 6163 0000 6163 009a 9931
	4200 0000 0029 0000 002c 0000 0061 6263
	6465 0061 6300 0061 6300 9a99 3142 0c00
	0000 0000 0000 0000 0000 0000 0000 0000
####binary file 3
	0000 0000 6300 0000 4600 0000 2c00 0000
	6162 6364 6500 6163 0000 6163 009a 9931
	4200 0000 0029 0000 002c 0000 0061 6263
	6465 0061 6300 0061 6300 9a99 3142 0c00
	0000 4600 0000 2c00 0000 6162 6364 6500
	6163 0000 6163 009a 9931 4229 0000 0000
	0000 0000 0000 0000 0000 0000 0000 0000	
	
##test4 insert and delete
test mixed delete and insert after previous test

	Address del_address;
    del_address=record.int_to_address(table, 12);
    record.delete_tuple(table, del_address);
    del_address=record.int_to_address(table, 41);
    record.delete_tuple(table, del_address);
    record.insert_tuple(table, tuple_unpack);
###test result 
####binary file 1
	
	0c00 0000 6300 0000 4600 0000 0000 0000
	6162 6364 6500 6163 0029 0000 009a 9931
	4200 0000 0029 0000 002c 0000 0061 6263
	6465 0061 6300 0061 6300 9a99 3142 0000
	0000 4600 0000 2c00 0000 6162 6364 6500
	6163 0000 6163 009a 9931 4229 0000 0000
	0000 0000 0000 0000 0000 0000 0000 0000
####binary	file 2
	2900 0000 6300 0000 4600 0000 0000 0000
	6162 6364 6500 6163 0046 0000 009a 9931
	4200 0000 0029 0000 000c 0000 0061 6263
	6465 0061 6300 0061 6300 9a99 3142 0000
	0000 4600 0000 2c00 0000 6162 6364 6500
	6163 0000 6163 009a 9931 4200 0000 0000
	0000 0000 0000 0000 0000 0000 0000 0000
####binary file 3
	0c00 0000 6300 0000 2900 0000 0000 0000
	6162 6364 6500 6163 0046 0000 009a 9931
	4200 0000 0029 0000 002c 0000 0061 6263
	6465 0061 6300 0061 6300 9a99 3142 4600
	0000 0000 0000 2c00 0000 6162 6364 6500
	6163 0000 6163 009a 9931 4200 0000 0029
	0000 0000 0000 0000 0000 0000 0000 0000
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
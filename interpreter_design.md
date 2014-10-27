#Interpreter Design 1.0
###Summary

1. 语法检查以及合法性检查并翻译成语法树
2. 从语法树底层单步生成命令内部数据表示
3. 调用api，执行命令

###Function

1. 支持数据类型：int, char(n) 1<=n<=255, float
2. create database \<database name>
3. create table \<table name>

	(attribute type,	
	……
	
	primary key (attribute)
	)
	
	* 最多32属性
	* unique属性
	* 单属性主键
	
4. create index \<index name> on \<table name>

   drop index \<index name>

	* 对于主键自动建立B树索引

5. select

	from
	
	where
	
	* and,*,范围,等值
	
6. insert into \<table name> values (……)
7. delete from \<table name>
8. drop table \<table name>
9. drop database \<database name>

###Implement
1. 对于语句进行处理，进行语法语义分析，具体调用catalog给的信息api：

	* 存在检查
	* 是否满足属性，包括类型，unique
	* 各个语句格式是否满足
	

2. 处理语句构造语法树，单步执行:

	执行模块：
	* create_database(Database db_name) 
	* drop_database(Database db_name) 	* create_table(Table tb_name, attribute list)具体用什么数据结构实现还没想好	* drop_table(Table tb_name)	* create_index(Index index_name,Table tb_name, Attribute attr_name)		* delete_index(Index index_name)	* select(Table tb_name,condition list)具体用什么数据结构实现还没想好	* insert(Table tb_name,record list)	* delete(Table tb_name,condition list)

3. 将更新信息反馈到catalog，调用catalog api来进行创建修改操作：

	创建删除database，创建删除table，创建删除index
4. 交互接口

	* 调用catalog所给信息进行检查
	* 将更新信息反馈给catalog
	* UI交互		


show database; 
use database ZJU;
show tables;
create table t(a int,b int unique,c int,index(c),primary key(a));









select * from ttt where a>3 and a<300;
create table fuck( 
id int,
name varchar(10),
age int,
ability float
);
insert into fuck values(1001,zyh,20,99.99);
insert into fuck values(1002,lyt,20,0.01);
insert into fuck values(1003,zyt,5,69.99);
insert into fuck values(1004,lyh,5,10.01);
insert into fuck values(1005,zyh_no2,1,79.99);
insert into fuck values(1006,lyt_no2,2,5.01);
insert into fuck values(1007,zyh_no3,3,59.99);
insert into fuck values(1008,lyt_no3,4,6.01);
insert into fuck values(1009,zyh_no4,5,49.99);
insert into fuck values(1010,lyt_no4,6,21.01);

delete from fuck where name="lyt";

create table computer(
id int 
,   
name varchar(30)
, 
age int
,           
rank int unique,
primary key(id)
)
;
select * from ttt where a>3 and a<=6;
insert into ttt values(1,2);
insert into ttt values(3,2);
insert into ttt values(4,2);	
insert into ttt values(5,2);
insert into ttt values(6,2);
insert into ttt values(7,2);

create table t(a varchar(10),b int,key(a));

create table t(a int,b int,c int,d int, e int, f int, g int, h int,i int,j int,k int,l int,m int,n int,o int,p int, q int,r int,s int,t int,u int,v int,w int,x int, y int,z int,aa int,bb int,cc int,dd int,ee int,ff int,gg int,hh int,ll int); 

create/drop db implement
delete
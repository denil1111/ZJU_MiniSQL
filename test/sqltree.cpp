#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
#include "sqltree.hpp"
#include "sql.hpp"
// using namespace std;
node::~node()
{
    for (int i=0;i<attr_list.size();i++){
            delete attr_list[i];
        }
        for (int i=0;i<sp_list.size();i++){
            delete sp_list[i];
        }
        delete select_where_clause;
        delete l;
        delete r;
}
void Interpreter::run_parser()
{
    // if(!yyparse())
    //     printf("SQL parse worked\n");
    // else
    //     printf("SQL parse failed\n");
    node *yyy_parse();
    plan_tree=yyy_parse();
}
int main(){
    Interpreter intp;
    intp.run_parser();

}
// int main(){
//     string a="a";
//     string b="b";
//     string t1="t1";
//     string t2="t2";
    
//     NAME_NODE * p=new_name(a);
    
//     vector <NAME_NODE> test;
    
//     cout<<test.size()<<endl;
    
//     test.push_back(*p);
    
//     cout<<test.front().name<<endl;
    
// }
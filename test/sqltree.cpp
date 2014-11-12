#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
#include "sqltree.hpp"
#include "sql.hpp"
// using namespace std;
Parse_Node::~Parse_Node()
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
    Parse_Node *yyy_parse();
    plan_tree=yyy_parse();
    std::cout<<"in run_parser"<<std::endl;
    std::cout<<plan_tree->kind<<std::endl;
    std::cout<<plan_tree->attr_list[0]->attr_name<<std::endl;
}

int main(){
    Interpreter intp;
    intp.run_parser();
}

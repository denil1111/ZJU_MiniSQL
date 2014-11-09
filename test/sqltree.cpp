#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h>
#include "sqltree.hpp"
// using namespace std;


FORMULA_NODE *
new_formula(int cmp, node *l, node *r)
{
    FORMULA_NODE *n = new FORMULA_NODE;
    n->cmp=cmp;
    n->l = l;
    n->r = r;
    return n;
}

INT_NODE*
new_int(int a)
{
    INT_NODE * n = new INT_NODE;
    n->int_num=a;
    return n;
}

NAME_NODE *
new_name(std::string s)
{
    NAME_NODE * n = new NAME_NODE;
    n->name=s;
    return n;
}

STRING_NODE *
new_string(std::string s)
{
    STRING_NODE * n = new STRING_NODE;
    n->s=s;
    return n;
}

FLOAT_NODE *
new_float(float a)
{
    FLOAT_NODE * n = new FLOAT_NODE;
    n->float_num=a;
    return n;
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
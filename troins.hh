#ifndef TROINS_H
#define TROINS_H
#include<vector>
#include<string>
#include<map>
using namespace std;
class troins{
public:
    string keyword;
    string specs;
    vector<string> args;
};
class TroinBuffer{
public:
    vector<troins> buffer;
    map<string,int> labels;
    void gen(troins ins);//append to buffer.
    int nextinstr();//return buffer.length();
    void backpatch(vector<int> ilist,string label);
    string newlabel();
};
class keywords{
public:
    string gt="goto";
    string ret="return";
    string prm="param";
    string ass="=";
};
class specs{
public:
    string na="";
    string ifs="if";
    string iff="ifFalse";
    string call="call";
    string bop="bop";
    string uop="uop";
    string arrr="arrr";
    string arrl="arrl";
    string adr="adr";
    string ptrr="ptrr";
    string ptrl="ptrl";
};
/*
keyword = "goto"
    goto L //specs = "", args = {L}
    if x goto L//specs = "if", args = {x,L}
    ifFalse x goto L//specs = "ifFalse", args = {x, L}
    if x relop y goto L//specs = "if", args = {x, relop, y, L}
keyword:return
    return y\\args = {y}
keword: param
    param x\\args = {x}
keyword: =
    y = call p,n\\specs="call"; args = {y,p,n}
    x = y op z\\specs="bop";args = {x,y,op,z}
    x = op y\\specs = "uop";args = {x,op,y}
    x = y\\specs = ""; args = {x,y}
    x = y[i]\\specs = "arrr" \\args = {x,y,i}
    x[i] = y\\specs = "arrl" \\args = {x,i,y}
    x = &y\\specs = "adr"\\args = {x,y}
    x = *y\\specs = "ptrr"\\args = {x,y}
    *x = y\\specs = "ptrl"\\args = {*x,y}
*/
#endif
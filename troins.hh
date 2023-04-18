#ifndef TROINS_H
#define TROINS_H
#include<vector>
#include<string>
#include<map>
#include<iostream>
using namespace std;
class troins{
public:
    enum kws{
        gt,
        ret,
        prm,
        ass
    };
    enum specs{
        na,
        ifs,
        iff,
        call,
        bop,
        uop,
        arrr,
        arrl,
        adr,
        ptrr,
        ptrl
    };
    kws keyword;
    specs spec;
    vector<string> args;
    troins(kws kw, specs spec, vector<string> args);
    string toString();
};
class TroinBuffer{
public:
    bool condcode = false;
    vector<troins> buffer;
    map<int,string> labels;
    void gen(troins ins);//append to buffer.
    int nextinstr();//return buffer.length();
    void backpatch(vector<int> ilist,string label);
    vector<int> merge(vector<int> l1,vector<int> l2);
    string newLabel();
    void printCode();
    void setLabel(string name);
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
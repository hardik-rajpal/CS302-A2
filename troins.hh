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
        func,
        ass,
        nop
    };
    enum specs{
        na, // not applicable
        ifs, // if statement
        iff, // if false
        call, 
        param,
        bop, // binary operation
        uop, // unary operator
        arrr, // DON'T ASM 
        arrl, // DON'T ASM 
        adr, // address of 
        ptrr, // pointer on right x = *y
        ptrl // pointer on left  *x = y
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
    string condtype="";
    vector<troins> buffer;
    map<int,string> labels;
    map<int,string> asmlabels;

    void gen(troins ins);//append to buffer.
    int nextinstr();//return buffer.length();
    void backpatch(vector<int> ilist,string label);
    vector<int> merge(vector<int> l1,vector<int> l2);
    string newLabel();
    void printCode();
    void setLabel(string name);
    void printASM();
    vector<string> getASM();
};
/*
keyword = "goto"
    goto L //specs = "", args = {L}
    if x goto L//specs = "ifs", args = {x,L}
    ifFalse x goto L//specs = "ifFalse", args = {x, L}
    if x relop y goto L//specs = "if", args = {x, relop, y, L}
keyword:return
    return y\\args = {y}
keyword: func
    param x\\specs="param"args = {x}
    call f,n\\specs="call",args={f,n}
keyword: =
    y = call p,n\\specs="call"; args = {y,p,n}
    x = y op z\\specs="bop";args = {x,y,op,z}
    x = op y\\specs = "uop";args = {x,op,y}
    x = y\\specs = ""; args = {x,y}
    x = y[i]\\specs = "arrr" \\args = {x,y,i}
    x[i] = y\\specs = "arrl" \\args = {x,i,y}
    x = &y\\specs = "adr"\\args = {x,y}
    x = *y\\specs = "ptrr"\\args = {x,y}
    *x = y\\specs = "ptrl"\\args = {x,y}
*/
#endif
#include<iostream>
#include"symtab.h"
using namespace std;
int main(){
    SymTab t;
    t.rows["x"] = SymEntry(SymTab::INT,SymTab::FUN,SymTab::GLOBAL,4,18);
    SymEntry u = t.rows["x"];
    cout<<u.type<<" "<<u.offset<<" "<<u.size<<endl;

}
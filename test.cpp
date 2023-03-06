#include<iostream>
#include"symtab.h"
using namespace std;
int main(){
    Symbols::gst = new SymTab();
    Symbols::gst->rows["x"] = SymEntry(SymTab::INT,SymTab::VAR,SymTab::GLOBAL,4,18);
    Symbols::gst->rows["main"] = SymEntry(SymTab::INT,SymTab::FUN,SymTab::GLOBAL,0,0);
    Symbols::flsts["main"] = new SymTab();
    Symbols::flsts["main"]->rows["x"] = SymEntry(SymTab::INT,SymTab::VAR,SymTab::LOCAL,4,18);
    Symbols::gst->printJson();

}
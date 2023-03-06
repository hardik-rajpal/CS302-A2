#ifndef SYMTAB_H
#define SYMTAB_H
#include <string>
#include <map>
#include <vector>
#include <iostream>
using namespace std;
class SymEntry;
class SymTab
{
public:
    enum ST_type
    {
        INT,
        FLOAT
    };
    enum ST_HL_type
    {
        VAR,
        FUN,
        STRUCT
    };
    enum ST_LPG
    {
        LOCAL,
        PARAM,
        GLOBAL
    };
    map<string, SymEntry> rows;
    void printJson();
    SymTab(){};
};
class SymEntry
{
public:
    size_t offset = 0;
    size_t size = 0;
    SymTab::ST_type type;
    SymTab::ST_HL_type hltype;
    SymTab::ST_LPG lpgtype;
    SymTab *lst;
    void *astnodeptr;
    SymEntry(SymTab::ST_type type, SymTab::ST_HL_type hltype, SymTab::ST_LPG lpgtype, size_t size, size_t offset) : type(type), hltype(hltype), lpgtype(lpgtype), size(size), offset(offset) {}
    SymEntry(){};
    void printJson(string varname);
};
class Symbols{
public:
    static SymTab * gst;
    static map<string, SymTab *> flsts;
    static map<string, SymTab *> slsts;
};
#endif
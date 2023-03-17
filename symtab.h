#ifndef SYMTAB_H
#define SYMTAB_H
#include <string>
#include <map>
#include <vector>
#include <iostream>
#include "ast.hh"
using namespace std;
class SymEntry;
class SymTab
{
    int getNewOffsetInStruct();
public:
    string type = "global";
    abstract_astnode * ptr;
    enum ST_type
    {
        INT,
        FLOAT,
        STRUCT_TYPE,
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
    int getNewOffset(size_t posSize);
    int getParamOffset(size_t posSize);
    SymTab(){};
};
class SymEntry
{
public:
    long long offset = 0;
    size_t size = 0;
    typespec_astnode type;
    SymTab::ST_HL_type hltype;
    SymTab::ST_LPG lpgtype;
    SymTab *lst;
    void *astnodeptr;
    SymEntry(typespec_astnode type, SymTab::ST_HL_type hltype, SymTab::ST_LPG lpgtype, size_t size, size_t offset) : type(type), hltype(hltype), lpgtype(lpgtype), size(size), offset(offset) {}
    SymEntry(){};
    void printJson(string varname);
};
class Symbols{
public:
    static bool symTabConstructed;
    static SymTab * gst;
    static map<string, SymTab *> flsts;
    static map<string, SymTab *> slsts;
    static int getStructBaseTypeWidth(string structname);
    static SymEntry* getSymEntry(SymTab * tst, string symbol,bool isMember=false);
};
#endif
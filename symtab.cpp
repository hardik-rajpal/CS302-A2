#include "symtab.h"
#include "util.hh"
SymTab *Symbols::gst;
map<string, SymTab *> Symbols::flsts;
map<string, SymTab *> Symbols::slsts;
int Symbols::symTabStage = 0;
using namespace std;
void SymEntry::printJson(string varname)
{
    cout << "[\n\"" << varname << "\",";
    switch (hltype)
    {
    case SymTab::FUN:
        cout << "\"fun\",\n";
        break;
    case SymTab::STRUCT:
        cout << "\"struct\",\n";
        break;
    case SymTab::VAR:
        cout << "\"var\",\n";
        break;
    }
    switch (lpgtype)
    {
    case SymTab::LOCAL:
        cout << "\"local\",\n";
        break;
    case SymTab::PARAM:
        cout << "\"param\",\n";
        break;
    case SymTab::GLOBAL:
        cout << "\"global\",\n";
        break;
    }
    cout << size << ",\n";
    if (hltype == SymTab::STRUCT)
    {
        cout << "\"-\",\n";
    }
    else
    {
        cout << offset << ",\n";
    }
    if (hltype == SymTab::STRUCT)
    {
        cout << "\"-\"\n";
    }
    else
    {
        cout << "\"" << type.typeName << "\"";
    }
    cout << "\n]";
}
void SymTab::printJson()
{
    cout << "{\n\"globalST\": [\n";
    auto iter = rows.begin();
    for (; iter != rows.end();)
    {
        (*iter).second.printJson((*iter).first);
        if ((++iter) != (rows.end()))
        {
            cout << ",";
        }
        cout << "\n";
    }
    cout << "],\n\"structs\":[\n";
    auto iterlst = Symbols::slsts.begin();
    for (; iterlst != Symbols::slsts.end();)
    {
        cout << "{\n\"name\":\"" << (*iterlst).first << "\",\n\"localST\":[\n"
             << endl;
        auto rows = (*iterlst).second->rows;
        auto iterent = rows.begin();
        for (; iterent != rows.end();)
        {
            iterent->second.printJson(iterent->first);
            if ((++iterent) != (rows.end()))
            {
                cout << ",";
            }
            cout << "\n";
        }
        cout << "]\n";
        cout << "}" << endl;
        if ((++iterlst) != (Symbols::slsts).end())
        {
            cout << ",";
        }
        cout << "\n";
    }
    cout << "],\n\"functions\":[" << endl;
    iterlst = Symbols::flsts.begin();
    for (; iterlst != Symbols::flsts.end();)
    {
        cout << "{\n\"name\":\"" << (*iterlst).first << "\",\n\"localST\":[\n";
        auto iterent = (*iterlst).second->rows.begin();
        for (; iterent != (*iterlst).second->rows.end();)
        {
            (*iterent).second.printJson((*iterent).first);
            if ((++iterent) != (((*iterlst).second->rows.end())))
            {
                cout << ",";
            }
            cout << "\n";
        }
        cout << "],\n";
        cout << "\"ast\":";
        iterlst->second->ptr->print();
        cout << "}" << endl;
        if ((++iterlst) != (Symbols::flsts).end())
        {
            cout << ",";
        }
        cout << "\n";
    }
    cout << "]\n";
    cout << "}" << endl;
}
int SymTab::getNewOffsetInStruct()
{
    int size = 0;
    for (auto entry : rows)
    {
        size += entry.second.size;
    }
    return size;
}
int SymTab::getNewOffset(size_t posSize)
{
    if (type == "struct")
    {
        return getNewOffsetInStruct();
    }
    auto iter = rows.begin();
    auto miniter = rows.begin();
    int newOffset = -posSize;
    bool offsetSet = true;
    for (; iter != rows.end(); iter++)
    {
        if (iter->second.lpgtype == LOCAL)
        {
            offsetSet = false;
            if ((*iter).second.offset < (*miniter).second.offset)
            {
                miniter = iter;
            }
        }
    }
    if (!offsetSet)
    {
        SymEntry &minOffsetEntry = (*miniter).second;
        newOffset = minOffsetEntry.offset - posSize;
    }
    return newOffset;
}
int Symbols::getStructBaseTypeWidth(string structname)
{
    int size = 0;
    if (slsts[structname])
    {
        for (auto entry : slsts[structname]->rows)
        {
            size += entry.second.size;
        };
        return size;
    }
    cout << "Error! Unknown struct encountered in code!";
    throw;
    return 0;
}
// within a struct the offsets start from 0, then increased by the size of the first field then the next field.
SymEntry *Symbols::getSymEntry(SymTab *tst, string symbol, bool isMember)
{
    if (tst->rows.count(symbol))
    {
        return &(tst->rows[symbol]);
    }
    if ((!isMember) && Symbols::gst->rows.count(symbol))
    {
        return &(Symbols::gst->rows[symbol]);
    }
    return NULL;
}

int SymTab::getParamOffset(size_t posSize)
{
    auto iter = rows.begin();
    auto miniter = rows.begin();
    int newOffset = -4;
    bool offsetSet = true;
    for (; iter != rows.end(); iter++)
    {
        if (iter->second.lpgtype == SymTab::ST_LPG::PARAM)
        {
            offsetSet = false;
            if ((*iter).second.offset < (*miniter).second.offset)
            {
                miniter = iter;
            }
        }
    }
    if (!offsetSet)
    {
        SymEntry &minOffsetEntry = (*miniter).second;
        newOffset = minOffsetEntry.offset - posSize;
    }
    return newOffset;
}
void Symbols::initGST(){
    op_binary_astnode::boolops={
        "OR_OP","AND_OP",
    };
    op_binary_astnode::boolgens={
        "LE_OP?","GE_OP?","GT_OP?","LT_OP?"
    };
    op_binary_astnode::boolgenseq={
        "NE_OP?","EQ_OP?"
    };
    typespec_astnode::voidc.baseTypeName = "void";
    typespec_astnode::voidc.baseTypeWidth = 0;
    typespec_astnode::voidc.typeName = typespec_astnode::voidc.baseTypeName;
    typespec_astnode::voidc.typeWidth = typespec_astnode::voidc.baseTypeWidth;
    typespec_astnode::structc.baseTypeWidth = 0;
    typespec_astnode::structc.baseTypeName = "struct";
    typespec_astnode::structc.typeName = typespec_astnode::structc.baseTypeName;
    typespec_astnode::structc.typeWidth = typespec_astnode::structc.baseTypeWidth;
    typespec_astnode::intc.baseTypeWidth = 4;
    typespec_astnode::intc.baseTypeName = "int";
    typespec_astnode::intc.typeName = typespec_astnode::intc.baseTypeName;
    typespec_astnode::intc.typeWidth = typespec_astnode::intc.baseTypeWidth;
    typespec_astnode::floatc.baseTypeWidth = 4;
    typespec_astnode::floatc.baseTypeName = "float";
    typespec_astnode::floatc.typeName = typespec_astnode::floatc.baseTypeName;
    typespec_astnode::floatc.typeWidth = typespec_astnode::floatc.baseTypeWidth;
    typespec_astnode::stringc.baseTypeWidth = 0;
    typespec_astnode::stringc.baseTypeName = "string";
    typespec_astnode::stringc.typeName = typespec_astnode::stringc.baseTypeName;
    typespec_astnode::stringc.typeWidth = typespec_astnode::stringc.baseTypeWidth;
}

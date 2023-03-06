#include "symtab.h"
SymTab * Symbols::gst;
map<string, SymTab *> Symbols::flsts;
map<string, SymTab *> Symbols::slsts;
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
    cout << size << ",\n"
         << offset << ",\n";
    switch (type)
    {
    case SymTab::INT:
        cout << "\"int\"";
        break;
    case SymTab::FLOAT:
        cout << "\"float\"";
        break;
    }
    cout << "\n]";
}
void SymTab::printJson()
{
    cout << "{\n\"globalST\": [\n";
    for (auto entry : rows)
    {
        entry.second.printJson(entry.first);
        if (&entry != &(*rows.rbegin()))
        {
            cout << ",";
        }
        cout << "\n";
    }
    cout << "],\n\"structs\":[\n";
    for (auto lst : Symbols::slsts)
    {
        cout << "{\n\"name\":" << lst.first << ",\n\"localST\":[\n";
        for (auto entry : lst.second->rows)
        {
            entry.second.printJson(entry.first);
            if (&entry != &(*(lst.second->rows.rbegin())))
            {
                cout << ",";
            }
            cout << "\n";
        }
        cout << "],\n";
        // TODO:printAST here.
        cout << "}\n";
        if (lst != *(Symbols::slsts).rbegin())
        {
            cout << ",";
        }
        cout << "\n";
    }
    cout << "],\n\"functions\":[\n";
    for (auto lst : (Symbols::flsts))
    {
        cout << "{\n\"name\":" << lst.first << ",\n\"localST\":[\n";
        for (auto entry : lst.second->rows)
        {
            entry.second.printJson(entry.first);
            if (&entry != &(*(lst.second->rows.rbegin())))
            {
                cout << ",";
            }
            cout << "\n";
            // if(entry.second.hltype==SymTab::STRUCT){
            //     // slsts[entry.first] =
            // }
        }
        cout << "],\n";
        // TODO:printAST here.
        cout << "}\n";
        if (lst != *(Symbols::flsts).rbegin())
        {
            cout << ",";
        }
        cout << "\n";
    }
    cout<<"]\n";
}
#include "symtab.h"
SymTab * Symbols::gst;
map<string, SymTab *> Symbols::flsts;
map<string, SymTab *> Symbols::slsts;
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
    cout << size << ",\n"
         << offset << ",\n";
    cout<<"\""<<type<<"\"";
    cout << "\n]";
}
void SymTab::printJson()
{
    cout << "{\n\"globalST\": [\n";
    auto iter = rows.begin();
    for (;iter!=rows.end();)
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
    for (;iterlst!=Symbols::slsts.end();)
    {
        cout << "{\n\"name\":\"" << (*iterlst).first << "\",\n\"localST\":[\n"<<endl;
        auto rows = (*iterlst).second->rows;
        auto iterent = rows.begin();
        for (;iterent!=rows.end();)
        {
            iterent->second.printJson(iterent->first);
            if ((++iterent) != (rows.end()))
            {
                cout << ",";
            }
            cout << "\n";
        }
        cout << "]\n";
        // TODO:add comma above, printAST here.
        cout << "}"<<endl;
        if ((++iterlst) != (Symbols::slsts).end())
        {
            cout << ",";
        }
        cout << "\n";
    }
    cout << "],\n\"functions\":["<<endl;
    iterlst = Symbols::flsts.begin();
    for (;iterlst!=Symbols::flsts.end();)
    {
        cout << "{\n\"name\":\"" << (*iterlst).first << "\",\n\"localST\":[\n";
        auto iterent = (*iterlst).second->rows.begin();
        for (;iterent != (*iterlst).second->rows.end();)
        {
            (*iterent).second.printJson((*iterent).first);
            if ((++iterent) != (((*iterlst).second->rows.end())))
            {
                cout << ",";
            }
            cout << "\n";
        }
        cout << "]\n";
        // TODO:printAST here.
        cout << "}"<<endl;
        if ((++iterlst) != (Symbols::flsts).end())
        {
            cout << ",";
        }
        cout << "\n";
    }
    cout<<"]\n";
    cout<<"}"<<endl;
}
int SymTab::getNewOffset(){
    auto iter = rows.begin();
    auto maxiter = rows.begin();
    int newOffset = 0;
    if(rows.size()>0){
        for(;iter!=rows.end();iter++){
            if((*iter).second.offset>(*maxiter).second.offset){
                maxiter = iter;
            }
        }
        SymEntry &maxOffsetEntry = (*maxiter).second;
        newOffset = maxOffsetEntry.offset + maxOffsetEntry.size;
    }
    return newOffset;
}
int Symbols::getStructBaseTypeWidth(string structname){
    int size = 0;
    if(slsts[structname]){
        return slsts[structname]->getNewOffset();
    }
    cout<<"Error! Unknown struct encountered in code!";
    throw ;
    return 0;
}
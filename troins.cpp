#include<algorithm>
#include <sstream>
#include<set>
#include"troins.hh"
#include"symtab.h"
void TroinBuffer::gen(troins ins){
    buffer.push_back(ins);
}
int TroinBuffer::nextinstr(){
    return buffer.size();
}
void TroinBuffer::backpatch(vector<int> list, string label){
    //all elements of list must point to goto isntructions.
    for(int index:list){
        vector<string> &args = buffer[index].args;
        args[args.size()-1]=label;//all goto instructions satisfy L being last arg.
    }
}
vector<int> TroinBuffer::merge(vector<int> l1,vector<int> l2){
    vector<int> res;
    for(int x:l1){
        res.push_back(x);
    }
    for(int x:l2){
        res.push_back(x);
    }
    return res;
}

string TroinBuffer::newLabel(){
    return "L"+to_string(labels.size());
}
troins::troins(kws kw, specs spc, vector<string> _args){
    keyword  = kw;spec = spc;args = _args;
}
string troins::toString(){
    //TODO: may not account for procedure call.
    string ans = "";
    switch (keyword)
    {
    case (kws::ass):
        switch (spec)
        {
        case (specs::bop):
            ans = args[0] + " = " + args[1]  + " " +args[2] + " " + args[3];
            break;        
        case (specs::na):
            ans = args[0] + " = " + args[1];
            break;
        case (specs::uop):
            ans = args[0] + " = " + args[1] + args[2];
            break;
        case (specs::call):
            ans = args[0] + " = " + " call "+args[1]+", "+args[2];
            break;
        }
        break;
    case (kws::gt):
        switch(spec)
        {
        case (specs::na):
            ans = "goto "+args[0];
            break;
        case (specs::ifs):
            if(args.size()>2){
                ans = "if "+ args[0] + args[1] + args[2]+" goto "+args[3];
            }
            else{
                ans = "if "+args[0] + " goto "+args[1];
            }
        }
        break;
    case (kws::func):
        switch (spec)
        {
        case specs::call:
            ans = "call "+args[0]+", "+args[1];
            break;
        case specs::param:
            ans = "param "+args[0];
            break;
        default:
            break;
        }
        break;
    case (kws::ret):
        ans = "return "+args[0];
        break;    
    case (kws::nop):
        ans = "nop";
        break;
    }
    
    return ans;
}
void TroinBuffer::printCode(){
    for(auto strlit: Symbols::strlits){
        cout<<strlit.second<<":\n\t"<<".string "<<strlit.first<<endl;
    }
    for(int i=0;i<buffer.size();i++){
        troins t = buffer[i];
        if(labels.count(i)){
            std::cout<<labels[i]<<":"<<std::endl;
        }
        std::cout<<"\t"<<t.toString()<<std::endl;
    }
}

bool isTemp(std::string s) {
    return true;
}

vector<string> TroinBuffer::getASM(){
    //NOTE: SymTabs are accessible using Symbols:: gst, flsts, slsts and funcalls.
    //For ebp offsets, etc.
    /*
    write code to generate assembly instructions from buf of troins, labels.
    labels:
    {
        index in buf==> label of line if any
    }
    */
    std::vector<std::string> ans;
    std::string function_name = "";
    int offset;
    std::stringstream ss;
    std::vector<troins> params;

    for (int i = 0; i < buffer.size(); ++i) {
        troins t = buffer[i];
        if (labels.count(i)) {
            if (labels[i][0] != '.') {
                // have reached a new function
                function_name = labels[i];
            }
            asmlabels.insert(std::make_pair(ans.size(), labels[i]));
        }
        switch(t.keyword) {
            case (troins::kws::ass):
            switch(t.spec) {
                case troins::specs::bop:
                // x = y op z 
                // args = {x,y,op,z}
                // move y to eax
                offset = Symbols::flsts[function_name]->rows[t.args[1]].offset;
                // movl offset(%ebp), %eax, 
                if (offset != 0) 
                    ss << "movl " << offset << "(%ebp), %eax\n";
                else
                    ss << t.args[1] << ", movl %eax\n";
                offset = Symbols::flsts[function_name]->rows[t.args[3]].offset;
                if (offset) {
                    if (t.args[2] == "+") 
                        ss << "addl " << offset << "(%ebp), %eax\n";
                    else if (t.args[2] == "-")
                        ss << "subl " << offset << "(%ebp), %eax\n";
                    else if (t.args[2] == "AND_OP")
                        ss << "andl " << offset << "(%ebp), %eax\n";
                }
                else {
                    if (t.args[2] == "+") 
                        ss << "addl $" << t.args[3] << ", %eax\n";
                    else if (t.args[2] == "-")
                        ss << "subl $" << t.args[3] << ", %eax\n";
                    else if (t.args[2] == "AND_OP")
                        ss << "andl $" << t.args[3] << ", %eax\n";
                }

                // store result into x
                offset = Symbols::flsts[function_name]->rows[t.args[0]].offset;
                ss << "movl " << "%eax, " << offset << "%(ebp)\n";
                ans.push_back(ss.str());
                ss.str("");
                break;
            }
            break;

            case (troins::kws::func):
            switch(t.spec) {
                case (troins::specs::param):
                params.push_back(t);
                break;

                case (troins::specs::call):
                for (auto param: params) {
                    offset = Symbols::flsts[function_name]->rows[t.args[0]].offset;
                    if (offset) {
                        ss << "pushl " << offset << "(%ebp)\n";
                    }
                    else {
                        ss << "pushl $" << t.args[0] << "\n";
                    }
                }
                ss << "call " << t.args[0] << "\n";
                params.clear();
                ans.push_back(ss.str());
                ss.str("");
                break;
            }
            break;

            case (troins::kws::gt):
            switch(t.spec) {
                
            }
            break;

            case (troins::kws::nop):
            break;

            case (troins::kws::ret):
            if(t.args.size()) {
                offset = Symbols::flsts[function_name]->rows[t.args[0]].offset;
                if (offset)
                    ss << "movl " << offset << "(%ebp), %eax\n";
                else 
                    ss << "movl $" << t.args[0] << ", %eax\n";
                // calculate offset of return value 
                int num_params = 1;
                for(auto row: Symbols::flsts[function_name]->rows) {
                    if (row.second.lpgtype == SymTab::ST_LPG::PARAM)
                        num_params++;
                }
                int offset_ret_val = 4 * num_params;
                ss << "movl %eax, " << offset << "(%ebp)\n";
            }
            ss << "ret\n";
            ans.push_back(ss.str());
            ss.str("");
            break;

            default:
            break;
        }
    }
    return ans;
}
void TroinBuffer::printASM(){
    std::vector<std::string> ans = getASM();
    for(auto strlit:Symbols::strlits){
        cout<<strlit.second<<":\n\t"<<".string "<<strlit.first<<endl;
    }
    for(int i=0;i<ans.size();i++){
        string instr = ans[i];
        if(asmlabels.count(i)){
            std::cout<<asmlabels[i]<<":"<<std::endl;
        }
        std::cout<<"\t"<<instr<<std::endl;
    }
    return ;
}
void TroinBuffer::setLabel(string name){
    // if(labels.count(buffer.size())){
    //     string oldname = labels[buffer.size()];
    //     for(int i=buffer.size()-1;i>-1;i--){
    //         troins &t = buffer[i];
    //         if(t.keyword==troins::gt){
    //             std::cerr<<"found gt stmt: "<<t.args[t.args.size()-1]<<endl;
    //             if(t.args[t.args.size()-1]==oldname){
    //                 t.args[t.args.size()-1] = name;
    //             }
    //         }
    //     }
    // }
    labels[buffer.size()] = name;
    // std::cerr<<"{"<<endl;
    // for(auto entry:labels){
    //     std::cerr<<"\t"<<entry.first<<":"<<entry.second<<endl;
    // }
    // std::cerr<<"}"<<endl;
}
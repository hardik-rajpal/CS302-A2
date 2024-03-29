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
        case (specs::ptrl):
            ans = "*"+args[0]+" = "+args[1];
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
        if(args.size()){
            ans = "return " + args[0];
        }
        else{
            ans = "return";
        }
        break;    
    case (kws::nop):
        ans = "nop";
        break;
    }
    
    return ans;
}
void TroinBuffer::printCode(){
    for(auto strlit: Symbols::strlits){
        cout<<"# "<<strlit.second<<":\n#\t"<<".string "<<strlit.first<<endl;
    }
    for(int i=0;i<buffer.size();i++){
        troins t = buffer[i];
        if(labels.count(i)){
            std::cout<<"# "<<labels[i]<<":"<<std::endl;
        }
        if(t.keyword==troins::gt){
            if(t.args[t.args.size()-1]==""){
                continue;
            }
        }
        std::cout<<"#\t"<<t.toString()<<std::endl;
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
        index in buf==>label of line if any
    }
    */
    std::vector<std::string> ans;
    std::string function_name = "";
    int shift_esp = 0;
    int offset;
    std::stringstream ss;
    std::vector<troins> params;

    for (int i = 0; i < buffer.size(); ++i) {
        troins t = buffer[i];
        ans.push_back("# " + t.toString() + "\n");
        if (labels.count(i)) {
            if (labels[i][0] != '.') {
                // have reached a new function
                function_name = labels[i];
                ss << "pushl %ebp\nmovl %esp, %ebp\n";
                // find amount to shift esp by 
                shift_esp = 0;
                for (auto row: Symbols::flsts[function_name]->rows) {
                    if (row.second.lpgtype == SymTab::ST_LPG::LOCAL)
                        shift_esp += row.second.size;
                }

                ss << "subl $" << shift_esp << ", %esp\n";
            }
            asmlabels.insert(std::make_pair(ans.size(), labels[i]));
        }
        if(t.keyword==troins::gt){
            if(t.args[t.args.size()-1]==""){
                continue;
            }
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
                if (offset) 
                    ss << "movl " << offset << "(%ebp), %eax\n";
                else
                    ss << "movl $" << t.args[1] << ", %eax\n";
                offset = Symbols::flsts[function_name]->rows[t.args[3]].offset;
                if (offset) {
                    if (t.args[2] == "+") 
                        ss << "addl " << offset << "(%ebp), %eax\n";
                    else if (t.args[2] == "-")
                        ss << "subl " << offset << "(%ebp), %eax\n";
                    else if (t.args[2] == "*")
                        ss << "imull " << offset << "(%ebp), %eax\n";
                    else if (t.args[2] == "/") {
                        ss << "movl " << offset << "(%ebp), %ecx\n";
                        ss << "cltd\n";
                        ss << "idivl %ecx\n";
                    }
                    else if (t.args[2] == "&") 
                        ss << "andl " << offset << "(%ebp), %eax\n";
                    else if (t.args[2] == "|") 
                        ss << "orl " << offset << "(%ebp), %eax\n";
                    else if (t.args[2] == "AND_OP") {
                        ss << "movl " << offset << "(%ebp), %ebx\n";
                        ss << "cmpl $0, %eax\nsetne %al\nmovzbl %al, %eax\n";
                        ss << "cmpl $0, %ebx\nsetne %bl\nmovzbl %bl, %ebx\n";
                        ss << "andl %ebx, %eax\n";
                    }
                    else if (t.args[2] == "OR_OP") {
                        ss << "movl " << offset << "(%ebp), %ebx\n";
                        ss << "cmpl $0, %eax\nsetne %al\nmovzbl %al, %eax\n";
                        ss << "cmpl $0, %ebx\nsetne %bl\nmovzbl %bl, %ebx\n";
                        ss << "orl %ebx, %eax\n";
                    }
                    else if (t.args[2] == "GT_OP") {
                        ss << "cmpl " << offset << "(%ebp), %eax\n";
                        ss << "setg %al\nmovzbl %al, %eax\n";
                    }
                    else if (t.args[2] == "LT_OP") {
                        ss << "cmpl " << offset << "(%ebp), %eax\n";
                        ss << "setl %al\nmovzbl %al, %eax\n";
                    }
                    else if (t.args[2] == "GE_OP") {
                        ss << "cmpl " << offset << "(%ebp), %eax\n";
                        ss << "setge %al\nmovzbl %al, %eax\n";
                    }
                    else if (t.args[2] == "LE_OP") {
                        ss << "cmpl " << offset << "(%ebp), %eax\n";
                        ss << "setle %al\nmovzbl %al, %eax\n";
                    }
                    else if (t.args[2] == "EQ_OP") {
                        ss << "cmpl " << offset << "(%ebp), %eax\n";
                        ss << "sete %al\nmovzbl %al, %eax\n";
                    }
                    else if (t.args[2] == "NE_OP") {
                        ss << "cmpl " << offset << "(%ebp), %eax\n";
                        ss << "setne %al\nmovzbl %al, %eax\n";
                    }
                }
                else {
                    if (t.args[2] == "+") 
                        ss << "addl $" << t.args[3] << ", %eax\n";
                    else if (t.args[2] == "-")
                        ss << "subl $" << t.args[3] << ", %eax\n";
                    else if (t.args[2] == "*")
                        ss << "imull $" << t.args[3] << ", %eax\n";
                    else if (t.args[2] == "/") {
                        ss << "movl $" << t.args[3] << ", %ecx\n";
                        ss << "cltd\n";
                        ss << "idivl %ecx\n";
                    }
                    else if (t.args[2] == "&") 
                        ss << "andl $" << t.args[3] << ", %eax\n";
                    else if (t.args[2] == "|") 
                        ss << "orl $" << t.args[3] << ", %eax\n";
                    else if (t.args[2] == "AND_OP") {
                        ss << "movl $" << t.args[3] << ", %ebx\n";
                        ss << "cmpl $0, %eax\nsetne %al\nmovzbl %al, %eax\n";
                        ss << "cmpl $0, %ebx\nsetne %bl\nmovzbl %bl, %ebx\n";
                        ss << "andl %ebx, %eax\n";
                    }
                    else if (t.args[2] == "OR_OP") {
                        ss << "movl $" << t.args[3] << ", %ebx\n";
                        ss << "cmpl $0, %eax\nsetne %al\nmovzbl %al, %eax\n";
                        ss << "cmpl $0, %ebx\nsetne %bl\nmovzbl %bl, %ebx\n";
                        ss << "orl %ebx, %eax\n";
                    }
                    else if (t.args[2] == "GT_OP") {
                        ss << "cmpl $" << t.args[3] << ", %eax\n";
                        ss << "setg %al\nmovzbl %al, %eax\n";
                    }
                    else if (t.args[2] == "LT_OP") {
                        ss << "cmpl $" << t.args[3] << ", %eax\n";
                        ss << "setl %al\nmovzbl %al, %eax\n";
                    }
                    else if (t.args[2] == "GE_OP") {
                        ss << "cmpl $" << t.args[3] << ", %eax\n";
                        ss << "setge %al\nmovzbl %al, %eax\n";
                    }
                    else if (t.args[2] == "LE_OP") {
                        ss << "cmpl $" << t.args[3] << ", %eax\n";
                        ss << "setle %al\nmovzbl %al, %eax\n";
                    }
                    else if (t.args[2] == "EQ_OP") {
                        ss << "cmpl $" << t.args[3] << ", %eax\n";
                        ss << "sete %al\nmovzbl %al, %eax\n";
                    }
                    else if (t.args[2] == "NE_OP") {
                        ss << "cmpl $" << t.args[3] << ", %eax\n";
                        ss << "setne %al\nmovzbl %al, %eax\n";
                    }
                }

                // store result into x
                offset = Symbols::flsts[function_name]->rows[t.args[0]].offset;
                ss << "movl " << "%eax, " << offset << "(%ebp)\n";

                ans.push_back(ss.str());
                ss.str("");
                break;

                case (troins::specs::na): {
                int source_offset = Symbols::flsts[function_name]->rows[t.args[1]].offset;
                int dest_offset = Symbols::flsts[function_name]->rows[t.args[0]].offset;
                int type_size = Symbols::flsts[function_name]->rows[t.args[0]].size;
                for (int _i = 0; _i < type_size; _i += 4) {
                    if (source_offset){
                        ss << "movl " << source_offset + _i << "(%ebp), %eax\n";
                    }
                    else{
                        ss << "movl $" << t.args[1] << ", %eax\n";
                    }
                    
                    ss << "movl %eax, " << dest_offset + _i << "(%ebp)\n";
                }

                ans.push_back(ss.str());
                ss.str("");
                break;
                }

                case troins::specs::adr:
                break;

                case troins::specs::ptrr:
                break;

                case troins::specs::ptrl:{
                // *x = y
                // args = {x,y}
                int source_offset = Symbols::flsts[function_name]->rows[t.args[1]].offset;
                int dest_offset = Symbols::flsts[function_name]->rows[t.args[0]].offset;
                if (source_offset) {
                    typespec_astnode type = Symbols::flsts[function_name]->rows[t.args[1]].type;
                    int struct_size = Symbols::gst->rows[type.typeName].size;
                    struct_size = (struct_size? struct_size: 4);
                    ss << "movl " << dest_offset << "(%ebp), %ebx\n";
                    for (int _i = 0; _i < struct_size; _i += 4) {
                        ss << "movl " << source_offset + _i << "(%ebp), %eax\n";
                        // ss << "movl %(ebx), %ebx";
                        ss << "movl %eax, " << _i << "(%ebx)\n";
                    }
                }
                else {
                    ss << "movl $" << t.args[1] << ", %eax\n";
                    offset = Symbols::flsts[function_name]->rows[t.args[0]].offset;
                    ss << "movl " << offset  << "(%ebp), %ebx\n";
                    ss << "movl %eax, (%ebx)\n";
                }
                ans.push_back(ss.str());
                ss.str("");
                break;
                }

                case troins::specs::uop:
                if (t.args[1] == "&") {
                    offset = Symbols::flsts[function_name]->rows[t.args[2]].offset;
                    ss << "movl %ebp, %eax\n";
                    ss << "add $" << offset << ", %eax\n";
                    offset = Symbols::flsts[function_name]->rows[t.args[0]].offset;
                    ss << "movl %eax, " << offset << "(%ebp)\n";
                }
                else if (t.args[1] == "*") {
                    // ans.push_back("here, motherfucker");
                    // t.args = {x, *, y}
                    typespec_astnode type = Symbols::flsts[function_name]->rows[t.args[0]].type;
                    int struct_size = Symbols::gst->rows[type.typeName].size;
                    struct_size = (struct_size? struct_size: 4);
                    int source_offset = Symbols::flsts[function_name]->rows[t.args[2]].offset;
                    int dest_offset = Symbols::flsts[function_name]->rows[t.args[0]].offset;
                    for (int _i = 0; _i < struct_size; _i += 4) {
                        ss << "movl " << source_offset << "(%ebp), %eax\n";
                        ss << "addl $" << _i << ", %eax\n";
                        ss << "movl (%eax), %eax\n";
                        ss << "movl %eax, " << dest_offset + _i << "(%ebp)\n";
                    }
                }
                else if (t.args[1] == "!") {
                    int source_offset = Symbols::flsts[function_name]->rows[t.args[2]].offset;
                    int dest_offset = Symbols::flsts[function_name]->rows[t.args[0]].offset;
                    if (source_offset)
                        ss << "movl " << source_offset << "(%ebp), %eax\n";
                    else
                        ss << "movl $" << t.args[2] << ", %eax\n";
                    ss << "cmpl $" << 0 << ", %eax\n";
                    ss << "sete %al\nmovzbl %al, %eax\n";
                    ss << "movl %eax, " << dest_offset << "(%ebp)\n";
                }
                else if (t.args[1] == "-") {
                    // args = {x, -, y}
                    offset = Symbols::flsts[function_name]->rows[t.args[2]].offset;
                    if (offset) {
                        ss << "movl " << offset << "(%ebp), %eax\n";
                        ss << "imull $-1, %eax\n";
                        offset = Symbols::flsts[function_name]->rows[t.args[0]].offset;
                        ss << "movl %eax, " << offset << "(%ebp)\n";
                    }
                    else {
                        ss << "movl $" << t.args[2] << ", %eax\n";
                        ss << "imull $-1, %eax\n";
                        offset = Symbols::flsts[function_name]->rows[t.args[0]].offset;
                        ss << "movl %eax, " << offset << "(%ebp)\n";
                    }
                }

                ans.push_back(ss.str());
                ss.str("");
                ans.push_back(ss.str());
                ss.str("");
                break;

                case (troins::specs::call): {
                // make space for return value
                typespec_astnode type = Symbols::gst->rows[t.args[1]].type;
                int ret_space = 0;
                if (type.typeName != "void") {
                    ret_space = type.typeWidth;
                    ss << "subl $" << ret_space << ", %esp\n";
                }
                // push the parameters
                int params_space = 0;
                //FYI, Swayam Chube, I reversed the parameters order here.
                reverse(params.begin(),params.end());
                for (auto param: params) {
                    int offset = Symbols::flsts[function_name]->rows[param.args[0]].offset;
                    if (offset) {
                        typespec_astnode type = Symbols::flsts[function_name]->rows[param.args[0]].type;
                        int struct_size = Symbols::gst->rows[type.typeName].size;
                        if (struct_size) {
                            ss << "subl $" << struct_size << ", %esp\n";
                            params_space += struct_size;
                            for (int _i = 0; _i < struct_size; _i += 4) {
                                ss << "movl " << offset + _i << "(%ebp), %eax\n";
                                ss << "movl %eax, " << _i << "(%esp)\n";
                            }
                        }
                        else {
                            ss << "pushl " << offset << "(%ebp)\n";
                            params_space += 4;
                        }
                    } 
                    else {
                        ss << "pushl $" << param.args[0] << "\n";
                        params_space += 4;
                    }
                }
                // ss << "subl $4, %esp\n"; // for the static link
                ss << "call " << t.args[1] << "\n";
                ss << "addl $" << params_space << ", %esp\n";
                // need to add retspace
                offset = Symbols::flsts[function_name]->rows[t.args[0]].offset;
                for (int _i = 0; _i < ret_space; _i += 4) {
                    ss << "movl " << _i << "(%esp), %eax\n";
                    ss << "movl %eax, " << offset + _i << "(%ebp)\n";
                }
                ss << "addl $" << ret_space << ", %esp\n";
                params.clear();
                ans.push_back(ss.str());
                ss.str("");
                break;
                }
            }
            break;


            case (troins::kws::func):
            switch(t.spec) {
                case (troins::specs::param):
                params.push_back(t);
                break;

                case (troins::specs::call):
                // make space for return value
                typespec_astnode type = Symbols::gst->rows[t.args[0]].type;
                int ret_space = 0;
                if (type.typeName != "void") {
                    ret_space = type.typeWidth;
                    ss << "subl $" << ret_space << ", %esp\n";
                }
                // push the parameters
                int params_space = 0;
                if (t.args[0] != "printf")
                    std::reverse(params.begin(), params.end());
                for (auto param: params) {
                    int offset = Symbols::flsts[function_name]->rows[param.args[0]].offset;
                    if (offset) {
                        typespec_astnode type = Symbols::flsts[function_name]->rows[param.args[0]].type;
                        int struct_size = Symbols::gst->rows[type.typeName].size;
                        if (struct_size) {
                            ss << "subl $" << struct_size << ", %esp\n";
                            params_space += struct_size;
                            for (int _i = 0; _i < struct_size; _i += 4) {
                                ss << "movl " << offset + _i << "(%ebp), %eax\n";
                                ss << "movl %eax, " << _i << "(%esp)\n";
                            }
                        }
                        else {
                            ss << "pushl " << offset << "(%ebp)\n";
                            params_space += 4;
                        }
                    } 
                    else {
                        ss << "pushl $" << param.args[0] << "\n";
                        params_space += 4;
                    }
                }
                ss << "call " << t.args[0] << "\n";
                ss << "addl $" << ret_space + params_space << ", %esp\n";
                params.clear();
                ans.push_back(ss.str());
                ss.str("");
                break;
            }
            break;

            case (troins::kws::gt):
            switch(t.spec) {
                case troins::specs::na:
                ss << "jmp " << t.args[0] << "\n";
                ans.push_back(ss.str());
                ss.str("");
                break;

                case troins::specs::ifs:
                offset = Symbols::flsts[function_name]->rows[t.args[0]].offset;
                if (offset) 
                    ss << "movl " << offset << "(%ebp), %eax\n";
                else 
                    ss << "movl $" << t.args[0] << ", %eax\n";

                ss << "cmpl $0, %eax\n";
                ss << "jne " << t.args[1] << "\n";
                ans.push_back(ss.str());
                ss.str("");
                break;
            }
            break;

            case (troins::kws::nop):
            ans.push_back("nop\n");
            break;

            case (troins::kws::ret):
            ss << "addl $" << shift_esp << ", %esp\n";
            if(t.args.size()) {
                offset = Symbols::flsts[function_name]->rows[t.args[0]].offset;
                // TODO: Take care of returning structs 4 bytes eaach
                // calculate offset of return value 
                int offset_ret_val = 8;  // for eip and dynamic link
                for(auto row: Symbols::flsts[function_name]->rows) {
                    if (row.second.lpgtype == SymTab::ST_LPG::PARAM) {
                        typespec_astnode type = row.second.type;
                        offset_ret_val += type.typeWidth;
                    }
                }
                int ret_size = Symbols::gst->rows[function_name].type.typeWidth;
                for (int _i = 0; _i < ret_size; _i += 4) {
                    if (offset) 
                        ss << "movl " << offset + _i << "(%ebp), %eax\n";
                    else 
                        ss << "movl $" << t.args[0] << ", %eax\n";

                    ss << "movl %eax, " << offset_ret_val + _i << "(%ebp)\n";
                }
            }
            ss << "leave\nmovl $0, %eax\nret";
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
    std::cout << ".section .rodata\n";
    for(auto strlit:Symbols::strlits){
        std::cout << strlit.second << ":\n\t" << ".string " << strlit.first << std::endl;
    }

    std::cout << ".text\n";
    for(int i=0;i<ans.size();i++){
        string instr = ans[i];
        if(asmlabels.count(i)){
            if (asmlabels[i][0] != '.') {
                std::cout << ".globl " << asmlabels[i] << "\n";
            }
            std::cout<< asmlabels[i] << ":" << std::endl;
        }
        std::cout<<instr<<std::endl;
    }
    return ;
}
void TroinBuffer::setLabel(string name){
    labels[buffer.size()] = name;
}
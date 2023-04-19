#include<algorithm>
#include<set>
#include"troins.hh"
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
    case (kws::prm):
        break;
    case (kws::ret):
        break;    
    case (kws::nop):
        ans = "nop";
        break;
    }
    
    return ans;
}
void TroinBuffer::printCode(){
    for(int i=0;i<buffer.size();i++){
        troins t = buffer[i];
        if(labels.count(i)){
            std::cout<<labels[i]<<":"<<std::endl;
        }
        std::cout<<"\t"<<t.toString()<<std::endl;
    }
}
void TroinBuffer::setLabel(string name){
    if(labels.count(buffer.size())){
        string oldname = labels[buffer.size()];
        for(int i=buffer.size()-1;i>-1;i--){
            troins &t = buffer[i];
            if(t.keyword==troins::gt){
                std::cerr<<"found gt stmt: "<<t.args[t.args.size()-1]<<endl;
                if(t.args[t.args.size()-1]==oldname){
                    t.args[t.args.size()-1] = name;
                }
            }
        }
    }
    labels[buffer.size()] = name;
    std::cerr<<"{"<<endl;
    for(auto entry:labels){
        std::cerr<<"\t"<<entry.first<<":"<<entry.second<<endl;
    }
    std::cerr<<"}"<<endl;
}
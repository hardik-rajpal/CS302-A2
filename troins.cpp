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
string TroinBuffer::newlabel(){
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
        break;
    case (kws::prm):
        break;
    case (kws::ret):
        break;    
    }
    return ans;
}
void TroinBuffer::printCode(){
    for(troins t:buffer){
        std::cout<<t.toString()<<std::endl;
    }
}
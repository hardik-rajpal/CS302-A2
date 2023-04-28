#include <iostream>
#include <string>
#include <set>
#include "ast.hh"
#include "util.hh"
typespec_astnode typespec_astnode::voidc,typespec_astnode::intc,typespec_astnode::floatc,typespec_astnode::stringc,typespec_astnode::structc;
std::set<std::string> op_binary_astnode::boolops,op_binary_astnode::boolgens,op_binary_astnode::boolgenseq;
identifier_astnode::identifier_astnode(std::string id) : id(id) { }

void identifier_astnode::print() {
    // std::cout << "\"identifier\": \"" << this->id << "\"";
    printAst(
        NULL, "s",
        "identifier", this->id.c_str()
    );
}

stringconst_astnode::stringconst_astnode(std::string value) : value(value) {
    // addr = value;
}

void stringconst_astnode::print() {
    printAst(
        NULL, "s",
        "stringconst", this->value.substr(1,this->value.length()-2).c_str()
    );
}
intconst_astnode::intconst_astnode(std::string value) : value(std::stoi(value)) { }

void intconst_astnode::print() {
    printAst(
        NULL, "i",
        "intconst", this->value
    );
}

floatconst_astnode::floatconst_astnode(std::string value) : value(std::stof(value)) { }

void floatconst_astnode::print() {
    printAst(
        NULL, "f",
        "floatconst", this->value
    );
}

seq_astnode::seq_astnode(std::vector<statement_astnode*> children) : children(children) { }

void seq_astnode::print() {
    printAst(
        NULL, "l",
        "seq", this->children
    );
}

assignS_astnode::assignS_astnode(exp_astnode* exp1, exp_astnode* exp2): exp1(exp1), exp2(exp2) {}

void assignS_astnode::print() {
    printAst(
        "assignS", "aa",
        "left", this->exp1,
        "right", this->exp2
    );
}

if_astnode::if_astnode(exp_astnode* exp, statement_astnode* statement1, statement_astnode* statement2): exp(exp), statement1(statement1), statement2(statement2) {}

void if_astnode::print() {
    printAst(
        "if", "aaa",
        "cond", this->exp,
        "then", this->statement1,
        "else", this->statement2
    );
}

while_astnode::while_astnode(exp_astnode* exp, statement_astnode* statement): exp(exp), statement(statement) {}

void while_astnode::print() {
    printAst(
        "while", "aa",
        "cond", this->exp,
        "stmt", this->statement
    );
}

for_astnode::for_astnode(exp_astnode* exp1, exp_astnode* exp2, exp_astnode* exp3, statement_astnode* statement): exp1(exp1), exp2(exp2), exp3(exp3), statement(statement) {}

void for_astnode::print() {
    printAst(
        "for", "aaaa",
        "init", this->exp1,
        "guard", this->exp2,
        "step", this->exp3,
        "body", this->statement
    );
}

op_binary_astnode::op_binary_astnode(std::string op, exp_astnode* exp1, exp_astnode* exp2): op(op), exp1(exp1), exp2(exp2) {
    bool isfloat = exp1->typeNode.typeName=="float"||exp2->typeNode.typeName=="float";
    bool arrptrs = (exp1->typeNode.numptrstars+exp1->typeNode.arrsizes.size()==exp2->typeNode.numptrstars+exp2->typeNode.arrsizes.size())&&(exp1->typeNode.numptrstars+exp1->typeNode.arrsizes.size()>0);
    bool ptrsdelta = (exp1->typeNode.numptrstars+exp1->typeNode.arrsizes.size()>0&&exp2->typeNode.typeName=="int")||(exp2->typeNode.numptrstars+exp2->typeNode.arrsizes.size()>0&&exp1->typeNode.typeName=="int");
    if(boolops.count(op)||boolgens.count(op)){
        typeNode = typespec_astnode::intc;
    }
    else{
        if(op=="MINUS?"&&arrptrs){
                typeNode = typespec_astnode::intc;
        }
        else if(ptrsdelta){
            //set type to ptr;
            if(exp1->typeNode.typeName=="int"){
                typeNode = exp2->typeNode;
            }
            else{
                //exp2->typeNode.typeName =="int"
                typeNode = exp1->typeNode;
            }
        }
        else{
            if(isfloat){
                typeNode = typespec_astnode::floatc;
            }
            else{
                typeNode = typespec_astnode::intc;
            }
        }
    }
    //op dismabiguation and exp casting.
    if(op[op.length()-1]=='?'){
        this->op = op.substr(0,op.size()-1);
        if(isfloat){
            this->op += "_FLOAT";
            if(exp1->typeNode.typeName=="int"){
                std::cerr<<"gonna update exp1"<<endl;
                this->exp1 = new op_unary_astnode("TO_FLOAT",exp1);
                std::cerr<<exp1->typeNode.typeName<<std::endl;
            }
            if(exp2->typeNode.typeName=="int"){
                this->exp2 = new op_unary_astnode("TO_FLOAT",exp2);
            }
        }
        else{
            this->op += "_INT";
        }
    }
}

void op_binary_astnode::print() {
    printAst(
        "op_binary", "saa",
        "op", this->op.c_str(),
        "left", this->exp1,
        "right", this->exp2
    );
}
bool typespec_astnode::comparableTypes(typespec_astnode t2){
    if(isNumeric()&&(t2.isNumeric())){
        return true;
    }
    int nrs = numptrstars+arrsizes.size();
    int t2nrs = t2.numptrstars+t2.arrsizes.size();
    if((baseTypeName==t2.baseTypeName)&&(t2nrs==nrs)){
        return true;
    }
    return false;
}
bool typespec_astnode::equatableTypes(typespec_astnode t2){
    if(comparableTypes(t2)){
        return true;
    }
    if(typeName=="void*"||t2.typeName=="void*"){
        return true;
    }
    if(isnullval&&(t2.numptrstars+t2.arrsizes.size()>0)){
        return true;
    }
    if(t2.isnullval&&(numptrstars+arrsizes.size()>0)){
        return true;
    }
    return false;
}
bool op_binary_astnode::operandsCompatible(std::string op,exp_astnode* exp1, exp_astnode* exp2){
    if(op_binary_astnode::boolgenseq.count(op)){
        return exp1->typeNode.equatableTypes(exp2->typeNode);
    }
    else if(op_binary_astnode::boolgens.count(op)){
        return exp1->typeNode.comparableTypes(exp2->typeNode);
    }
    else if(op_binary_astnode::boolops.count(op)){
        if(exp1->typeNode.isNumeric()||(exp1->typeNode.numptrstars+exp1->typeNode.arrsizes.size()>0)){
            if(exp2->typeNode.isNumeric()||(exp2->typeNode.numptrstars+exp2->typeNode.arrsizes.size()>0)){
                return true;
            }
        }
        return false;
    }
    else{
        //numeric ops TODO
        if(exp1->typeNode.isNumeric()&&exp2->typeNode.isNumeric()){
            return true;
        }
        if(op=="PLUS?"||op=="MINUS?"){
            //ptr arithmetic
            int nrs1 = exp1->typeNode.numptrstars+exp1->typeNode.arrsizes.size();
            int nrs2 = exp2->typeNode.numptrstars+exp2->typeNode.arrsizes.size();
            if(exp1->typeNode.isNumeric()&&(nrs2>0)){
                return true;
            }
            if(exp2->typeNode.isNumeric()&&(nrs1>0)){
                return true;
            }
            if(op=="MINUS?"){
                if(nrs1==nrs2){
                    return true;
                }
            }
            return false;
        }
        return false;
    }
    
    return true;
}
bool op_unary_astnode::compatibleOperand(std::string op, exp_astnode* exp){
    //TODO write some basic checks.
    int nrs = exp->typeNode.numptrstars+exp->typeNode.arrsizes.size();
    if(nrs==0&&exp->typeNode.baseTypeName.substr(0,6)=="struct"){
        if(op=="ADDRESS"){
            return true;
        }
        return false;
    }
    if(op=="UMINUS"&&(!exp->typeNode.isNumeric())){
        return false;
    }
    if(op=="NOT"&&(!exp->typeNode.isNumeric())&&(nrs==0)){
        return false;
    }
    return true;
}
op_unary_astnode::op_unary_astnode(std::string op, exp_astnode* exp): op(op), exp(exp) {
    if(op=="TO_FLOAT"){
        //parser generated==>error free.
        typeNode = typespec_astnode::floatc;
    }
    else if(op=="TO_INT"){
        //parser generated==>error free.
        typeNode = typespec_astnode::intc;
    }
    else if(op=="NOT"){
        typeNode = typespec_astnode::intc;
    }
    else{
        typeNode = exp->typeNode;
    }
    if(op=="DEREF"){
        typeNode.deref();
        //error checking done by parser.
    }
    else if(op=="ADDRESS"){
        //must be an lvalue.
        typeNode.addressOf();
    }
}

void op_unary_astnode::print() {
    printAst(
        "op_unary", "sa", 
        "op", this->op.c_str(),
        "child", this->exp
    );
}

assignE_astnode::assignE_astnode(exp_astnode* exp1, exp_astnode* exp2): exp1(exp1), exp2(exp2) {}

void assignE_astnode::print() {
    printAst(
        "assignE", "aa",
        "left", this->exp1,
        "right", this->exp2
    );
}

pointer_astnode::pointer_astnode(exp_astnode* exp): exp(exp) {}

void pointer_astnode::print() {
}

funcall_astnode::funcall_astnode(identifier_astnode* id, std::vector<exp_astnode*> exp_list, bool is_proc): id(id), exp_list(exp_list), is_proc(is_proc) {}

void funcall_astnode::print() {
    if (is_proc)
    printAst(
        "proccall", "al",
        "fname", id,
        "params", exp_list
    );
    else 
    printAst(
        "funcall", "al",
        "fname", id,
        "params", exp_list
    );
}

arrayref_astnode::arrayref_astnode(exp_astnode* exp1, exp_astnode* exp2): exp1(exp1), exp2(exp2) {
    typeNode = exp1->typeNode;
    typeNode.deref();
}

void arrayref_astnode::print() {
    printAst(
        "arrayref", "aa",
        "array", this->exp1,
        "index", this->exp2
    );
}

deref_astnode::deref_astnode(exp_astnode* exp): exp(exp) {}

void deref_astnode::print() {
    std::cout << "\"deref";
}

member_astnode::member_astnode(exp_astnode* exp, identifier_astnode* identifier): exp(exp), identifier(identifier) {
    
}

void member_astnode::print() {
    printAst(
        "member", "aa",
        "struct", this->exp,
        "field", this->identifier
    );
}

arrow_astnode::arrow_astnode(exp_astnode* exp, identifier_astnode* identifier): exp(exp), identifier(identifier) {}

void arrow_astnode::print() {
    printAst(
        "arrow", "aa",
        "pointer", this->exp,
        "field", this->identifier
    );
}

void fundeclarator_astnode::print(){
}
fundeclarator_astnode::fundeclarator_astnode(std::string name,std::vector<typespec_astnode> ptypes):name(name),paramtypes(ptypes){

}
typespec_astnode::typespec_astnode(){
}
int typespec_astnode::genTypeWidth(){
    int btw = baseTypeWidth;
    if(numptrstars>0){
        btw = 4;
    }
    for(auto size:arrsizes){
        btw*=size;
    }
    return btw;
}
void typespec_astnode::deref(){
    if(arrsizes.size()>0){
        arrsizes.pop_back();
    }
    else if(numptrstars>0){
        numptrstars--;
    }
    else{
        //nothing done=> typeName unchanged=> error check in parser.yy
        return;
    }
    islval = true;
    typeName = genTypeName();
    typeWidth = genTypeWidth();
}
void typespec_astnode::addressOf(){
    numptrstars+=1;
    islval = false;
    typeName = genTypeName();
    typeWidth = genTypeWidth();
}
bool typespec_astnode::isNumeric(){
    return numtypes.count(typeName);
}
int typespec_astnode::getnrs(){
    return numptrstars+arrsizes.size();
}

std::string typespec_astnode::genTypeName(){
    std::string tn = baseTypeName;
    int k = numptrstars;
    while(k--){
        tn += "*";
    }
    for(auto iter = arrsizes.rbegin();iter!=arrsizes.rend();iter++){
        tn += ("["+std::to_string(*iter)+"]");
    }
    return tn;
}
bool typespec_astnode::compatibleWith(typespec_astnode t2,bool isparam){
    if((numptrstars+arrsizes.size())==0){
        //int, float or struct smt var.
        if((t2.numptrstars+t2.arrsizes.size())!=0){
            return false;
        }
        //Note: struct names need to match, as in gcc.
        if(numtypes.count(baseTypeName)&&numtypes.count(t2.baseTypeName)){
            return true;
        }
        return (baseTypeName==t2.baseTypeName);
    }
    else{
        //handling null ptr case separately.
        if(t2.isnullval){
            if(arrsizes.size()!=0){
                return false;
            }
            return true;
        }
        if(typeName=="void*"||t2.typeName=="void*"){
            return true;
        }
        if(numptrstars+arrsizes.size()!=t2.numptrstars+t2.arrsizes.size()){
            return false;
        }
        if((!isparam)&&arrsizes.size()!=0){
            return false;
        }
        if(isparam&&(arrsizes.size()==1)&&(numptrstars==0)&&(t2.numptrstars==1)&&(t2.arrsizes.size()==0)){
            return true;
        }
        //arrsizes = 0;=>numptrstars!=0;
        if(t2.arrsizes.size()==0){
            return (baseTypeName==t2.baseTypeName)||(t2.baseTypeName=="void"||baseTypeName=="void");
        }
        if(t2.arrsizes.size()==1){
            if(baseTypeName=="void"){
                return true;
            }
            else{
                return baseTypeName==t2.baseTypeName;
            }
        }

        return false;
        //number of ptrs+ arr[] == number of ptrs + arr[]
    }
}

return_astnode::return_astnode(exp_astnode* exp): exp(exp) { };
void return_astnode::print() {
    printAst(
        NULL, "a",
        "return", exp
    );
}

void empty_astnode::print() {
    std::cout << "\"empty\"";
}
std::string unopName(std::string inp,bool toSymbol){
    if(toSymbol){
        if(inp=="UMINUS"){
            return "-";
        }
        else if(inp=="NOT"){
            return "!";
        }
        else if(inp=="ADDRESS"){
            return "&";
        }
        else if(inp=="DEREF"){
            return "*";
        }
    }
    else{
        switch (inp[0])
        {
        case '-':
            return "UMINUS";
            break;
        case '!':
            return "NOT";
        case '&':
            return "ADDRESS";
        case '*':
            return "DEREF";
        }
    }
    return "unopNameScrewup";
}
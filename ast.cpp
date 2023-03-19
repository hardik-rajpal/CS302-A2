#include <iostream>
#include <string>
#include <set>
#include "ast.hh"
#include "util.hh"
typespec_astnode typespec_astnode::voidc,typespec_astnode::intc,typespec_astnode::floatc,typespec_astnode::stringc,typespec_astnode::structc;
identifier_astnode::identifier_astnode(std::string id) : id(id) { }

void identifier_astnode::print() {
    // std::cout << "\"identifier\": \"" << this->id << "\"";
    printAst(
        NULL, "s",
        "identifier", this->id.c_str()
    );
}

stringconst_astnode::stringconst_astnode(std::string value) : value(value) { }

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
    std::set<std::string> boolops={
        "OR_OP",
        "AND_OP",
    };
    if(boolops.count(op)){
        typeNode = typespec_astnode::intc;
    }
    else if(exp1->typeNode.typeName=="float"||exp2->typeNode.typeName=="float"){
        typeNode = typespec_astnode::floatc;
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
        typeNode = exp1->typeNode;
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

op_unary_astnode::op_unary_astnode(std::string op, exp_astnode* exp): op(op), exp(exp) {
    //TODO validity checks
    if(op=="TO_FLOAT"){
        //parser generated==>error free.
        typeNode = typespec_astnode::floatc;
    }
    else if(op=="TO_INT"){
        //parser generated==>error free.
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
    std::cout << "\"arrayref\": {\n";
    this->exp1->print();
    std::cout << ",\n";
    this->exp2->print();
    std::cout << "\n}";
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
int typespec_astnode::genTypeWidth(){
    int btw = baseTypeWidth;
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
    typeName = genTypeName();
}
void typespec_astnode::addressOf(){
    numptrstars+=1;
    typeName = genTypeName();
}
bool typespec_astnode::isNumeric(){
    return numtypes.count(typeName);
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
bool typespec_astnode::compatibleWith(typespec_astnode t2){
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
        if(numptrstars+arrsizes.size()!=t2.numptrstars+t2.arrsizes.size()){
            return false;
        }
        if(arrsizes.size()!=0){
            return false;
        }
        //arrsizes = 0;=>numptrstars!=0;
        if(t2.arrsizes.size()==1){
            if(typeName.substr(0,4)=="void"){
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
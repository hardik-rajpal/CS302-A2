#include <iostream>
#include <string>
#include <set>
#include "ast.hh"
#include "util.hh"
typespec_astnode typespec_astnode::intc,typespec_astnode::floatc,typespec_astnode::stringc,typespec_astnode::structc;
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
        "stringconst", this->value.c_str()
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
        "EQ_OP_INT","NE_OP_INT","LT_OP_INT","GT_OP_INT","LE_OP_INT","GE_OP_INT",
        "EQ_OP_FLOAT","NE_OP_FLOAT","LT_OP_FLOAT","GT_OP_FLOAT","LE_OP_FLOAT","GE_OP_FLOAT",
    };
    if(boolops.count(op)){
        typeNode = typespec_astnode::intc;
    }
    else if(exp1->typeNode.baseTypeName=="float"||exp2->typeNode.baseTypeName=="float"){
        if(exp1->typeNode.baseTypeName=="float"){
            typeNode = exp1->typeNode;
        }
        else{
            typeNode = exp2->typeNode;
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
    typeNode = exp->typeNode;
    if(op=="DEREF"){
        typeNode.deref();
    }
    else if(op=="ADDRESS"){
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

funcall_astnode::funcall_astnode(exp_astnode* exp1, exp_astnode* exp2): exp1(exp1), exp2(exp2) {}

void funcall_astnode::print() {
    std::cout << "\"funcall\": {\n";
    this->exp1->print();
    std::cout << ",\n";
    this->exp2->print();
    std::cout << "\n}";
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
    typespec_astnode::structc.baseTypeWidth = 0;
    typespec_astnode::structc.baseTypeName = "struct";
    typespec_astnode::structc.typeName = "struct";
    typespec_astnode::structc.typeWidth = 0;
    typespec_astnode::intc.baseTypeWidth = 4;
    typespec_astnode::intc.baseTypeName = "int";
    typespec_astnode::intc.typeName = "int";
    typespec_astnode::intc.typeWidth = 4;
    typespec_astnode::floatc.baseTypeWidth = 8;
    typespec_astnode::floatc.baseTypeName = "float";
    typespec_astnode::floatc.typeName = "float";
    typespec_astnode::floatc.typeWidth = 8;
    typespec_astnode::stringc.baseTypeWidth = 0;
    typespec_astnode::stringc.baseTypeName = "string";
    typespec_astnode::stringc.typeName = "string";
    typespec_astnode::stringc.typeWidth = 0;
}
void typespec_astnode::deref(){
    if(arrsizes.size()>0){
        arrsizes.pop_back();
    }
    else if(numptrstars>0){
        numptrstars--;
    }
    else{
        std::cout<<"Error in deref funcall."<<std::endl;
        return;
    }
    typeName = genTypeName();
}
void typespec_astnode::addressOf(){
    numptrstars+=1;
    typeName = genTypeName();
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
#include <iostream>
#include <string>
#include "ast.hh"

identifier_astnode::identifier_astnode(std::string id) : id(id) { }

void identifier_astnode::print() {
    std::cout << "\"identifier\": \"" << this->id << "\"";
}

stringconst_astnode::stringconst_astnode(std::string value) : value(value) { }

void stringconst_astnode::print() {
    std::cout << "\"stringconst\": " << this->value << "\n";
}
intconst_astnode::intconst_astnode(std::string value) : value(std::stoi(value)) { }

void intconst_astnode::print() {
    std::cout << "\"intconst\": " << this->value << "\n";
}

floatconst_astnode::floatconst_astnode(std::string value) : value(std::stof(value)) { }

void floatconst_astnode::print() {
    std::cout << "\"floatconst\": " << this->value << "\n";
}

seq_astnode::seq_astnode(std::vector<statement_astnode*> children) : children(children) { }

void seq_astnode::print() {
    std::cout << "\"seq\": [\n";
    for (statement_astnode* child: children) {
        if(child){
            std::cout << "{\n";
            child->print();
            std::cout << "\n},\n";
        }
    }
    std::cout << "]\n";
}

assignS_astnode::assignS_astnode(exp_astnode* exp1, exp_astnode* exp2): exp1(exp1), exp2(exp2) {}

void assignS_astnode::print() {
    std::cout << "\"assignS\": {\n";
    (this->exp1)->print();
    std::cout << ",\n";
    (this->exp2)->print();
    std::cout << "\n}";
}

if_astnode::if_astnode(exp_astnode* exp, statement_astnode* statement1, statement_astnode* statement2): exp(exp), statement1(statement1), statement2(statement2) {}

void if_astnode::print() {
    std::cout << "\"if\": {\n";
    this->exp->print();
    std::cout << ",\n";
    this->statement1->print();
    std::cout << ",\n";
    if(this->statement2){
        this->statement2->print();
    }
    std::cout << "\n}";
}

while_astnode::while_astnode(exp_astnode* exp, statement_astnode* statement): exp(exp), statement(statement) {}

void while_astnode::print() {
    std::cout << "\"while\": {\n";
    this->exp->print();
    std::cout << ",\n";
    this->statement->print();
    std::cout << "\n}";
}

for_astnode::for_astnode(exp_astnode* exp1, exp_astnode* exp2, exp_astnode* exp3, statement_astnode* statement): exp1(exp1), exp2(exp2), exp3(exp3), statement(statement) {}

void for_astnode::print() {
    std::cout << "\"for\": {\n";
    this->exp1->print();
    std::cout << ",\n";
    this->exp2->print();
    std::cout << ",\n";
    this->exp3->print();
    std::cout << "\n}";
}

op_binary_astnode::op_binary_astnode(std::string op, exp_astnode* exp1, exp_astnode* exp2): op(op), exp1(exp1), exp2(exp2) {}

void op_binary_astnode::print() {
    std::cout << "\"op_binary\": {\n";
    std::cout << "\"\": \"" << this->op << "\",\n";
    this->exp1->print();
    std::cout << ",\n";
    this->exp2->print();
    std::cout << "\n}";
}

op_unary_astnode::op_unary_astnode(std::string op, exp_astnode* exp): op(op), exp(exp) {}

void op_unary_astnode::print() {
    std::cout << "\"op_unary\": {\n";
    std::cout << "\"\": \"" << this->op << "\",\n";
    this->exp->print();
    std::cout << "\n}";
}

assignE_astnode::assignE_astnode(exp_astnode* exp1, exp_astnode* exp2): exp1(exp1), exp2(exp2) {}

void assignE_astnode::print() {
    std::cout << "\"assignE\": {\n";
    this->exp1->print();
    std::cout << ",\n";
    this->exp2->print();
    std::cout << "\n}";
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

arrayref_astnode::arrayref_astnode(exp_astnode* exp1, exp_astnode* exp2): exp1(exp1), exp2(exp2) {}

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

member_astnode::member_astnode(exp_astnode* exp, identifier_astnode* identifier): exp(exp), identifier(identifier) {}

void member_astnode::print() {
    std::cout << "\"member\": {\n";
    this->exp->print();
    std::cout << ",\n";
    this->identifier->print();
    std::cout << "\n}";
}

arrow_astnode::arrow_astnode(exp_astnode* exp, identifier_astnode* identifier): exp(exp), identifier(identifier) {}

void arrow_astnode::print() {
    std::cout << "\"arrow\": {\n";
    this->exp->print();
    std::cout << ",\n";
    this->identifier->print();
    std::cout << "\n}";
}

void fundeclarator_astnode::print(){

}
fundeclarator_astnode::fundeclarator_astnode(std::string name,std::vector<typespec_astnode> ptypes):name(name),paramtypes(ptypes){

}
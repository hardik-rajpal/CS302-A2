#include "ast.hh"
#include <string>

identifier_astnode::identifier_astnode(std::string id) : id(id) { }

void identifier_astnode::print() {
    std::cout << "\"identifier\": \"" << this->id << "\",";
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
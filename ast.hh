#include <iostream>
#include <string>

enum base_type {
    INT,
    FLOAT,
    INT_PTR,
    FLOAT_PTR,
};

class abstract_astnode {
public:
    virtual void print() = 0;
public:
    union {
        base_type type;
        char c;
    } astnode_type;
};

class exp_astnode: public abstract_astnode {
};

class intconst_astnode: public exp_astnode {
public:
    intconst_astnode(std::string value);
    void print();
private:
    int value;
};

class floatconst_astnode: public exp_astnode {
public:
    floatconst_astnode(std::string value);
    void print();
private:
    float value;
};

class stringconst_astnode: public exp_astnode {
public:
    stringconst_astnode(std::string value);
    void print();
private:
    std::string value;
};

class identifier_astnode: public exp_astnode {
public:
    identifier_astnode(std::string id);
    void print();
private:
    std::string id;
};
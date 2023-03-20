#ifndef AST_HH
#define AST_HH
#include <string>
#include <vector>
#include <set>
enum base_type {
    INT,
    FLOAT,
    INT_PTR,
    FLOAT_PTR
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

/* Abstract Classes */
class statement_astnode: public abstract_astnode {
};
class typespec_astnode{
    std::set<std::string> numtypes= {"int","float"};
public:
    bool isnullval = false;
    static typespec_astnode structc, intc, floatc,stringc, voidc;
    int baseTypeWidth;
    std::string baseTypeName;
    std::string typeName;
    int typeWidth;
    int numptrstars = 0;
    bool islval = true;
    std::vector<int> arrsizes;
public:
    typespec_astnode();
    std::string genTypeName();
    void deref();
    void addressOf();
    bool compatibleWith(typespec_astnode t2, bool isparam=false);
    bool comparableTypes(typespec_astnode t2);
    bool isNumeric();
    int genTypeWidth();
    
};
struct offsetcomp{
    bool operator()(std::pair<long long, typespec_astnode> p1, std::pair<long long, typespec_astnode> p2)const{
        return p1.first<p2.first;
    }
};
class exp_astnode: public abstract_astnode {
public:
    typespec_astnode typeNode;
};

class ref_astnode: public exp_astnode {
};

/* Derived Classes */
class empty_astnode: public statement_astnode {
public:
    void print();
};

class seq_astnode: public statement_astnode {
public:
    seq_astnode(std::vector<statement_astnode*>);
    void print();
private:
    std::vector<statement_astnode*> children;
};

class assignS_astnode:public statement_astnode {
public:
    assignS_astnode(exp_astnode*, exp_astnode*);
    void print();
private:
    exp_astnode* exp1, *exp2;
};

class return_astnode:public statement_astnode {
public: 
    return_astnode(exp_astnode*);
    void print();
private:
    exp_astnode* exp;
};

class if_astnode:public statement_astnode {
public:
    if_astnode(exp_astnode*, statement_astnode*, statement_astnode*);
    void print();
private:
    exp_astnode* exp;
    statement_astnode* statement1, *statement2;
};

class while_astnode:public statement_astnode {
public:
    while_astnode(exp_astnode*, statement_astnode*);
    void print();
private:
    exp_astnode* exp;
    statement_astnode* statement;
};

class for_astnode:public statement_astnode {
public: 
    for_astnode(exp_astnode*, exp_astnode*, exp_astnode*, statement_astnode*);
    void print();
private:
    exp_astnode* exp1, *exp2, *exp3;
    statement_astnode* statement;
};

class op_binary_astnode: public exp_astnode {
private:
    exp_astnode* exp1, *exp2;

public:
    static std::set<std::string> boolops;
    static std::set<std::string> boolgens;
public:
    op_binary_astnode(std::string, exp_astnode*, exp_astnode*);
    void print();
    static bool operandsCompatible(std::string,exp_astnode*, exp_astnode*);
    std::string op;
};

class op_unary_astnode: public exp_astnode {
public:
    op_unary_astnode(std::string, exp_astnode*);
    void print();
    static bool compatibleOperand(std::string , exp_astnode*);
private:
    std::string op;
    exp_astnode* exp;
};

class assignE_astnode: public exp_astnode {
public:
    assignE_astnode(exp_astnode* exp1, exp_astnode* exp2);
    void print();
    exp_astnode* exp1, *exp2;
    exp_astnode* expres;
};
class fundeclarator_astnode: public abstract_astnode{
    public:
    std::string name;
    std::vector<typespec_astnode> paramtypes;
    fundeclarator_astnode(std::string name,std::vector<typespec_astnode> ptypes);
    void print();
};

class explist_astnode: public exp_astnode {

};

class pointer_astnode: public exp_astnode {
public:
    pointer_astnode(exp_astnode*);
    void print();
private:
    exp_astnode* exp;
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

class arrayref_astnode: public ref_astnode {
public: 
    arrayref_astnode(exp_astnode*, exp_astnode*);
    void print();
private:
    exp_astnode* exp1, *exp2;
};

class deref_astnode: public ref_astnode {
public:
    deref_astnode(exp_astnode*);
    void print();
private:
    exp_astnode* exp;
};

class member_astnode: public ref_astnode {
public:
    member_astnode(exp_astnode*, identifier_astnode*);
    void print();
private:
    exp_astnode* exp;
    identifier_astnode* identifier;
};

class arrow_astnode: public ref_astnode {
public: 
    arrow_astnode(exp_astnode*, identifier_astnode*);
    void print();
private:
    exp_astnode* exp;
    identifier_astnode* identifier;
};
    
class funcall_astnode: public exp_astnode, public statement_astnode {
public:
    funcall_astnode(identifier_astnode*, std::vector<exp_astnode*>, bool);
    void print();
private:
    identifier_astnode* id;
    std::vector<exp_astnode*> exp_list;
    bool is_proc;
};

#endif
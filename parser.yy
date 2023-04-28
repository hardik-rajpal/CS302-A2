%skeleton "lalr1.cc"
%require  "3.0.1"

%defines 
%define api.namespace {IPL}
%define api.parser.class {Parser}
%define api.value.type variant
/* %define api.location.type {IPL::location} */
%define parse.assert
%define parse.trace

%code requires{
    #include "ast.hh"
    #include "location.hh"
    #include <set>
    #include <algorithm>
   namespace IPL {
      class Scanner;
   }
}
%printer { std::cerr << $$; } VOID
%printer { std::cerr << $$; } INT
%printer { std::cerr << $$; } FLOAT
%printer { std::cerr << $$; } STRUCT
%printer { std::cerr << $$; } IDENTIFIER
%printer { std::cerr << $$; } INT_CONSTANT
%printer { std::cerr << $$; } FLOAT_CONSTANT
%printer { std::cerr << $$; } STRING_LITERAL
%printer { std::cerr << $$; } OR_OP
%printer { std::cerr << $$; } AND_OP
%printer { std::cerr << $$; } EQ_OP
%printer { std::cerr << $$; } NE_OP
%printer { std::cerr << $$; } LE_OP
%printer { std::cerr << $$; } GE_OP
%printer { std::cerr << $$; } INC_OP
%printer { std::cerr << $$; } PTR_OP
%printer { std::cerr << $$; } IF
%printer { std::cerr << $$; } ELSE
%printer { std::cerr << $$; } WHILE
%printer { std::cerr << $$; } MAIN
%printer { std::cerr << $$; } PRINTF
%printer { std::cerr << $$; } FOR
%printer { std::cerr << $$; } RETURN
%printer { std::cerr << $$; } OTHERS


%parse-param { Scanner  &scanner  }
%locations
%code{
   #include <iostream>
   #include <cstdlib>
   #include <fstream>
   #include <string>
   #include <stack>
   #include "scanner.hh"
   #include "symtab.h"
   #include "troins.hh"
#undef yylex
#define yylex IPL::Parser::scanner.yylex
stack<SymTab*> ststack;
int retType;
typespec_astnode structc,intc,voidc,floatc,stringc;
typespec_astnode toptype;
string topvarname;
TroinBuffer code;
#define gen(...) code.gen(troins(__VA_ARGS__))
#define newtemp(A) Symbols::newTemp(ststack.top(),A)
}



%start begin_nterm

%token <std::string> VOID
%token <std::string> INT
%token <std::string> FLOAT
%token <std::string> STRUCT 
%token <std::string> IDENTIFIER
%token <std::string> INT_CONSTANT
%token <std::string> FLOAT_CONSTANT
%token <std::string> STRING_LITERAL
%token <std::string> OR_OP
%token <std::string> AND_OP
%token <std::string> EQ_OP
%token <std::string> NE_OP
%token <std::string> LE_OP
%token <std::string> GE_OP
%token <std::string> INC_OP
%token <std::string> PTR_OP
%token <std::string> IF
%token <std::string> MAIN
%token <std::string> PRINTF
%token <std::string> ELSE
%token <std::string> WHILE
%token <std::string> FOR
%token <std::string> RETURN
%token <std::string> OTHERS
%left '+' '-'
%left '*' '/'
%token '=' '(' ')' ',' '{' '}' '[' ']' '!' '&' '<' '>' ';' '\n'
%nterm <std::vector<abstract_astnode*>> translation_unit begin_nterm program
%nterm <abstract_astnode*> struct_specifier declaration_list 

%nterm <exp_astnode*> expression unary_expression postfix_expression primary_expression //assignment_expression

%nterm <op_binary_astnode*> logical_and_expression equality_expression relational_expression additive_expression multiplicative_expression ifgotocoder

%nterm <funcall_astnode*> procedure_call printf_call

%nterm <mnt*> mnterm

%nterm <assignE_astnode*> assignment_expression

%nterm <statement_astnode*> function_definition statement selection_statement iteration_statement assignment_statement main_definition

%nterm <std::vector<statement_astnode*>> compound_statement statement_list
%nterm <std::vector<exp_astnode*>> expression_list
%nterm <std::string> unary_operator
%nterm <typespec_astnode> type_specifier declaration declarator_list declarator declarator_arr parameter_declaration
%nterm <std::vector<typespec_astnode>> parameter_list 
%nterm <fundeclarator_astnode*> fun_declarator
%%
begin_nterm: {
    if(Symbols::symTabStage==0){
        Symbols::gst = new SymTab();
        Symbols::initGST();//initializes typespec vals, boolgen vals
    }
    ststack.push(Symbols::gst);
    structc = typespec_astnode::structc;
    intc = typespec_astnode::intc;
    floatc = typespec_astnode::floatc;
    stringc = typespec_astnode::stringc;
    voidc = typespec_astnode::voidc;

} program {
    if(Symbols::symTabStage==1){
        // ststack.top()->printJson();
    }
    else if(Symbols::symTabStage==2){
        code.printCode();
        std::cout<<"\n****************ASM Starts here********** "<<std::endl;
        //TODO: will comment out last two instructions before submission, 
        //to print only asm.
        code.printASM();
    }
    Symbols::symTabStage+=1;
}
program:main_definition{

}
|translation_unit main_definition{

}

main_definition:INT MAIN '(' ')' {
    std::string name = $2;
    if(Symbols::symTabStage==0){
        ststack.top()->rows[name] = SymEntry(toptype,SymTab::ST_HL_type::FUN,SymTab::ST_LPG::GLOBAL,0,0);
        Symbols::flsts[name] = new SymTab();
        Symbols::flsts[name]->rettype = new typespec_astnode;
        Symbols::flsts[name]->type = "function";
        *(Symbols::flsts[name]->rettype) = typespec_astnode::intc;
    }
    else{
        if(Symbols::symTabStage==2){
            code.setLabel(name);
        }
    }
    ststack.push(Symbols::flsts[name]);
} compound_statement{
    if(Symbols::symTabStage>0){
        ststack.top()->ptr = new seq_astnode($6);
    }
    $$ = nullptr;
    ststack.pop();
}

translation_unit: struct_specifier{
}
| function_definition{
    $$ = std::vector<abstract_astnode*>();
    $$.push_back($1);
}
| translation_unit struct_specifier{
}
| translation_unit function_definition{
    $$ = $1;
    $$.push_back($2);
}
;

struct_specifier: STRUCT IDENTIFIER {
    string structName = "struct " + $2;
    if(Symbols::symTabStage==0){
        ststack.top()->rows[structName] = SymEntry(structc,SymTab::ST_HL_type::STRUCT,SymTab::ST_LPG::GLOBAL,0,0);
        Symbols::slsts[structName] = new SymTab();
        Symbols::slsts[structName]->type = "struct";
    }
    ststack.push(Symbols::slsts[structName]);
}'{' declaration_list '}' ';'{
    // if(Symbols::symTabStage==0){
    ststack.pop();
    if(Symbols::symTabStage==0){
        for(auto entry: ststack.top()->rows){
            if(entry.second.size==0&&entry.second.hltype==SymTab::ST_HL_type::STRUCT){
                ststack.top()->rows[entry.first].size = Symbols::getStructBaseTypeWidth(entry.first);
            }
        }
    }
    // }
};

function_definition: type_specifier fun_declarator compound_statement{
    if(Symbols::symTabStage>0){
        ststack.top()->ptr = new seq_astnode($3);
    }
    $$ = nullptr;
    ststack.pop();
};

type_specifier: VOID{
    typespec_astnode ts;
    ts.baseTypeWidth = 0;
    ts.baseTypeName = "void";
    ts.typeWidth = ts.baseTypeWidth;
    ts.typeName = "void";
    $$ = ts;
    if(Symbols::symTabStage==0){
        toptype = ts;
    }

}
| INT{
    // retType = SymTab::ST_type::INT;
    typespec_astnode ts = intc;
    $$ = ts;
    if(Symbols::symTabStage==0){
        toptype = ts;
    }

}
| STRUCT IDENTIFIER{
    // retType = SymTab::ST_type::STRUCT_TYPE;
    typespec_astnode ts;
    ts.typeName = "struct "+($2);
    ts.baseTypeWidth = Symbols::getStructBaseTypeWidth(ts.typeName);
    ts.typeWidth = ts.baseTypeWidth;
    ts.baseTypeName = ts.typeName;
    $$ = ts;
    if(Symbols::symTabStage==0){
        toptype = ts;
    }
}
;

fun_declarator: IDENTIFIER '('{
    std::string name = $1;
    if(Symbols::symTabStage==0){
        ststack.top()->rows[name] = SymEntry(toptype,SymTab::ST_HL_type::FUN,SymTab::ST_LPG::GLOBAL,0,0);
        Symbols::flsts[name] = new SymTab();
        Symbols::flsts[name]->type = "function";
        Symbols::flsts[name]->rettype = new typespec_astnode();
        *(Symbols::flsts[name]->rettype) = toptype;
    }
    ststack.push(Symbols::flsts[name]);
    if(Symbols::symTabStage==2){
        code.setLabel(name);
    }
} parameter_list ')'{
    $$ = NULL;
    if(Symbols::symTabStage==0){
        auto &rows = (ststack.top())->rows;
        long long minParamOffset = 0;
        for(auto entry:rows){
            minParamOffset = min(minParamOffset,ststack.top()->rows[entry.first].offset);
        }
        int localsParamsGap = 12;
        int summer = localsParamsGap - minParamOffset;
        auto iter = rows.begin();
        for(;iter!=rows.end();){
            rows[iter->first].offset += summer;    
            iter++;
        }
    }
    else{
        std::string name = $1;
        std::vector<typespec_astnode> vect = std::vector<typespec_astnode>();
        $$ = new fundeclarator_astnode(name, vect);
    }
}
| IDENTIFIER '(' ')'{
    std::string name = $1;
    if(Symbols::symTabStage==0){
        ststack.top()->rows[name] = SymEntry(toptype,SymTab::ST_HL_type::FUN,SymTab::ST_LPG::GLOBAL,0,0);
        Symbols::flsts[name] = new SymTab();
        Symbols::flsts[name]->rettype = new typespec_astnode;
        Symbols::flsts[name]->type = "function";
        *(Symbols::flsts[name]->rettype) = toptype;
    }
    else{
        $$ = new fundeclarator_astnode(name,std::vector<typespec_astnode>());
        if(Symbols::symTabStage==2){
            code.setLabel(name);
        }
    }
    ststack.push(Symbols::flsts[name]);
}
;

parameter_list: parameter_declaration{
    if(Symbols::symTabStage==1){
        $$ = std::vector<typespec_astnode>();
        $$.push_back($1);
    }
}
| parameter_list ',' parameter_declaration {
    if(Symbols::symTabStage==1){
        $$ = $1;
        $$.push_back($3);
    }
}
;

parameter_declaration: type_specifier declarator{
    $$ = $1;
    if(Symbols::symTabStage==0){
        if($2.typeName=="void"){
            error(@$,"Cannot declare variable of type \"void\"");
        }
        ststack.top()->rows[topvarname] = SymEntry($2,SymTab::ST_HL_type::VAR,SymTab::ST_LPG::PARAM,$2.typeWidth,0);
        ststack.top()->rows[topvarname].offset = ststack.top()->getParamOffset(ststack.top()->rows[topvarname].size);
    }
}
;

declarator_arr: IDENTIFIER{
    $$ = toptype;
    $$.typeWidth = $$.baseTypeWidth;
    if(Symbols::symTabStage==0){
        topvarname = $1;
        // if(Symbols::getSymEntry(Symbols::gst, $$)){
            //error(@$, "Identifier is taken.")
        //}
    }
}
| declarator_arr '[' INT_CONSTANT ']'{
    $$ = $1;
    if(Symbols::symTabStage==0){
        typespec_astnode tstmp = $1;
        $$.arrsizes.insert($$.arrsizes.begin(),std::stoi($3));
        $$.typeWidth = $$.genTypeWidth();
        $$.typeName = $$.genTypeName();
    }
};

declarator: declarator_arr{
    $$ = $1;
}
| '*' declarator {
    $$ = $2;
    $$.baseTypeWidth = 4;
    $$.numptrstars+=1;
    $$.typeWidth = $$.genTypeWidth();
    $$.typeName = $$.genTypeName();
}
;

compound_statement: '{' '}'{
    $$ = std::vector<statement_astnode*>();
}
| '{' statement_list '}'{
    $$ = $2;
}
| '{' declaration_list '}' {
    $$ = std::vector<statement_astnode*>();

}
| '{' declaration_list statement_list '}'{
    $$ = $3;
}
;

statement_list: statement {
    std::vector<statement_astnode*> temp;
    statement_astnode* stmt = $1;
    if(stmt!=NULL){
        temp.push_back($1);
    }
    $$ = temp;
}
| statement_list statement{
    $1.push_back($2);
    $$ = $1;
}
;

statement: ';'{
    if(Symbols::symTabStage>0){   
        $$ = new empty_astnode();
    }
}
| '{' statement_list '}'{
    if(Symbols::symTabStage>0){   
        $$ = new seq_astnode($2);
    }
}
| selection_statement{
    $$ = $1;
}
| iteration_statement{
    $$ = $1;
}
| assignment_statement{
    $$ = $1;
}
| procedure_call{
    $$ = $1;
}
| printf_call{
    $$ = $1;
}
| RETURN expression ';'{
    if(Symbols::symTabStage>0){
        typespec_astnode rt = *(ststack.top()->rettype);
        if (!rt.compatibleWith($2->typeNode)) {
            error(@$, "Function must return "+ rt.typeName+" but returns "+$2->typeNode.typeName );
        }
        else{
            $$ = new return_astnode($2);
            if(rt.isNumeric()){
                if (rt.typeName != $2->typeNode.typeName) {
                    std::string ltypename = rt.typeName;
                    std::transform(ltypename.begin(), ltypename.end(), ltypename.begin(), [](auto c) { return std::toupper(c); });
                    // std::cerr << ltypename << std::endl;
                    std::string utypename = "TO_" + ltypename;
                    $$ = new return_astnode(new op_unary_astnode(utypename, $2));
                }
            }
        }
    }
    if(Symbols::symTabStage==2){
        gen(troins::ret,troins::na,{$2->addr});
    }
}
;

printf_call: PRINTF '(' STRING_LITERAL ')' ';' {
    exp_astnode* arg1 = new stringconst_astnode($3);
    arg1->addr = Symbols::newStrLit($3);
    $$ = new funcall_astnode(new identifier_astnode($1), std::vector<exp_astnode*>(1,arg1), true);
    if(Symbols::symTabStage==2){
        gen(troins::func,troins::param,{arg1->addr});
        gen(troins::func,troins::call,{$1,"1"});
    }
}// P1
| PRINTF '(' STRING_LITERAL ',' expression_list ')' ';'{
    std::vector<exp_astnode*> args = $5;
    exp_astnode* strnode = new stringconst_astnode($3);
    strnode->addr = Symbols::newStrLit($3);
    args.insert(args.begin(),strnode);
    std::reverse(args.begin(),args.end());

    $$ = new funcall_astnode(new identifier_astnode($1), args, true);
    if(Symbols::symTabStage==2){
        for(exp_astnode* prm:args){
            gen(troins::func,troins::param,{prm->addr});
        }
        gen(troins::func,troins::call,{$1,to_string(args.size())});
    }
} // P1
assignment_expression: unary_expression '=' expression{
    if(Symbols::symTabStage>0){
        // std::cerr<<__LINE__<<std::endl;
        std::cerr<<$1->typeNode.typeName<<" = "<<$3->typeNode.typeName<<std::endl;
        if(($1->typeNode.compatibleWith($3->typeNode))){
            // std::cerr<<__LINE__<<std::endl;
            if(!($1->typeNode.islval)){
                error(@$,"Error: Tried to assign value to rvalue.");
            }
            
            
            if($1->typeNode.typeName!=$3->typeNode.typeName){
                // std::cerr<<__LINE__<<std::endl;
                if ($1->typeNode.isNumeric()){
                    // std::cerr<<__LINE__<<std::endl;
                    std::string ltypename = $1->typeNode.typeName;
                    std::transform(ltypename.begin(), ltypename.end(), ltypename.begin(), [](auto c) { return std::toupper(c); });
                    // std::cerr << ltypename << std::endl;
                    std::string utypename = "TO_" + ltypename;
                    $$ = new assignE_astnode($1, new op_unary_astnode(utypename, $3));
                }
                else{
                    $$ = new assignE_astnode($1, $3);
                }
            }
            else {$$ = new assignE_astnode($1, $3);}
        }
        else{
            error(@$,"Incompatible types: tried to assign "+$3->typeNode.typeName+" to "+$1->typeNode.typeName);
        }
    }
    if(Symbols::symTabStage==2){
        std::string t1;
        if($3->isproxyaddr||$3->iselem){
            typespec_astnode tn = $3->typeNode;
            tn.deref();
            t1 = newtemp(tn);
            gen(troins::ass,troins::uop,{t1,"*",$3->addr});
        }
        else{
            t1 = $3->addr;
        }
        if($1->isproxyaddr||$1->iselem){
            gen(troins::ass,troins::ptrl,{$1->addr,t1});
        }
        else{
            gen(troins::ass,troins::na,{$1->addr,t1});
        }
    }
}
;

assignment_statement: assignment_expression ';'{
    if(Symbols::symTabStage>0){
        $$ = new assignS_astnode($1->exp1, $1->exp2);
    }
}
;

procedure_call: IDENTIFIER '(' ')' ';'{
    if (Symbols::symTabStage>0) {
        std::string function_name = $1;
        if(!($1=="printf"||$1=="scanf")){
            SymTab* fstab = Symbols::flsts[function_name];
            if (fstab == nullptr) {
                error(@$, "Procedure \"" + $1 + "\" not declared");
            }
        //Arg checks.
            std::set<std::pair<long long, std::string>> expected;
            for (auto row: fstab->rows) {
                if (row.second.lpgtype == SymTab::PARAM) {
                    expected.insert(std::make_pair(row.second.offset, row.second.type.typeName));
                }
            }
            if (!expected.empty()) {
                error(@$, "Procedure \"" + $1 + "\" called with too few arguments");
            }
            $$ = new funcall_astnode(new identifier_astnode($1), std::vector<exp_astnode*>(), true);
            $$->typeNode = Symbols::getSymEntry(Symbols::gst, $1)->type;
        }
        else {
            $$ = new funcall_astnode(new identifier_astnode($1), std::vector<exp_astnode*>(), true);
            $$->typeNode = voidc;
        }
    }
    if(Symbols::symTabStage==2){
        gen(troins::func,troins::call,{$1,"0"});
    }
}
| IDENTIFIER '(' expression_list ')' ';'{
    std::reverse($3.begin(),$3.end());
    if (Symbols::symTabStage>0) {
        std::string function_name = $1;
        if(!($1=="printf"||$1=="scanf")){
            SymTab* fstab = Symbols::flsts[function_name];
            std::set<std::pair<long long, typespec_astnode>,struct offsetcomp> expected;
            for (auto row: fstab->rows) {
                if (row.second.lpgtype == SymTab::PARAM) {
                    expected.insert(std::make_pair(row.second.offset, row.second.type));
                }
            }
            if ($3.size() < expected.size()) {
                error(@$, "Procedure \"" + $1 + "\" called with too few arguments");
            }
            else if ($3.size() > expected.size()) {
                error(@$, "Procedure \"" + $1 + "\" called with too many arguments");
            }
            std::vector<exp_astnode*> exp_list = $3;
            std::reverse(exp_list.begin(), exp_list.end());
            int i = 0;
            for (auto item: expected) {
                if (!item.second.compatibleWith(exp_list[i]->typeNode,true)) {
                    error(@$, "Expected \"" + item.second.typeName + "\" but argument is of type \"" + exp_list[i]->typeNode.typeName + "\"");
                }
                else if(item.second.typeName != exp_list[i]->typeNode.typeName && item.second.isNumeric() && exp_list[i]->typeNode.isNumeric()) {
                    std::string ltypename = item.second.typeName;
                    std::transform(ltypename.begin(), ltypename.end(), ltypename.begin(), [](auto c) { return std::toupper(c); });
                    // std::cerr << ltypename << std::endl;
                    std::string utypename = "TO_" + ltypename;
                    exp_list[i] = new op_unary_astnode(utypename, exp_list[i]);
                }
                i++;
            }
            std::reverse(exp_list.begin(),exp_list.end());
            $$ = new funcall_astnode(new identifier_astnode($1), exp_list, true);
            $$->typeNode = Symbols::getSymEntry(Symbols::gst, $1)->type;
        }
        else {
            $$ = new funcall_astnode(new identifier_astnode($1), $3, true);
            $$->typeNode = voidc;
        }
    }
    if(Symbols::symTabStage==2){
        for(exp_astnode* prm:$3){
            gen(troins::func,troins::param,{prm->addr});
        }
        gen(troins::func,troins::call,{$1,to_string($3.size())});
    }
}
;

expression: logical_and_expression{
    $$ = $1;
    // std::cerr<<__LINE__<<$$->typeNode.typeName<<endl;
}
| expression OR_OP mnterm logical_and_expression{
    if(Symbols::symTabStage>0){
        $$ = new op_binary_astnode("OR_OP",$1,$4);
    }
    if(Symbols::symTabStage==2){
        if(code.condcode){
            code.backpatch($1->fl,$3->nil);
            $$->tl = code.merge($1->tl,$4->tl);
            $$->fl = $4->fl;
        }
        else{
            gen(troins::ass,troins::bop,{$$->addr,$1->addr,"OR_OP",$4->addr});
        }
    }
}
;
mnterm:{
    $$ = new mnt();
    if(code.condcode){
        $$->nil = code.condtype+"_"+code.newLabel();
        code.setLabel($$->nil);
    }
}
ifgotocoder: equality_expression{
    $$ = $1;
    if(Symbols::symTabStage==2){
        if(code.condcode){
            $$->tl = {code.nextinstr()};
            gen(troins::gt,troins::ifs,{$1->addr,""});
            $$->fl = {code.nextinstr()};
            gen(troins::gt,troins::na,{""});
        }
    }
}
logical_and_expression: ifgotocoder{
    $$ = $1;
}
| logical_and_expression AND_OP mnterm ifgotocoder{
    if(Symbols::symTabStage>0){
        $$ = new op_binary_astnode("AND_OP", $1, $4);
    }
    if(Symbols::symTabStage==2){
        $$->addr = newtemp(typespec_astnode::intc);
        if(code.condcode){
            $$->tl = $4->tl;
            code.backpatch($1->tl,$3->nil);
            $$->fl = code.merge($1->fl,$4->fl);
        }
        else{
            gen(troins::ass,troins::bop,{$$->addr,$1->addr,"AND_OP",$4->addr});
        }
    }
}
;

equality_expression: relational_expression{
    $$ = $1;
    // std::cerr<<__LINE__<<$$->typeNode.typeName<<endl;
}
| equality_expression EQ_OP relational_expression {
    std::string op = "EQ_OP?";
    if(Symbols::symTabStage>0){
        if(!op_binary_astnode::operandsCompatible(op,$1,$3)){
            error(@$,"Incompatible operands for "+op+": \""+$1->typeNode.typeName+"\", \""+$3->typeNode.typeName+"\"");
        }
        $$ = new op_binary_astnode(op, $1, $3);
    }
    if(Symbols::symTabStage==2){
        op = op.substr(0,op.size()-1);
        std::string t1 = newtemp(typespec_astnode::intc);
        gen(troins::ass,troins::bop,{t1,$1->addr,op,$3->addr});
        $$->addr = t1;

    }
}
| equality_expression NE_OP relational_expression{
    std::string op = "NE_OP?";
    if(Symbols::symTabStage>0){ 
        if(!op_binary_astnode::operandsCompatible(op,$1,$3)){
            error(@$,"Incompatible operands for "+op+": \""+$1->typeNode.typeName+"\", \""+$3->typeNode.typeName+"\"");
        }
        $$ = new op_binary_astnode(op, $1, $3);
    }
    if(Symbols::symTabStage==2){
        op = op.substr(0,op.size()-1);
        std::string t1 = newtemp(typespec_astnode::intc);
        gen(troins::ass,troins::bop,{t1,$1->addr,op,$3->addr});
        $$->addr = t1;

    }
}
;

relational_expression: additive_expression{
    $$ = $1;
    // std::cerr<<__LINE__<<$$->typeNode.typeName<<endl;
}
| relational_expression '<' additive_expression{
    std::string op = "LT_OP?";
    if(Symbols::symTabStage>0){
        if(!op_binary_astnode::operandsCompatible(op,$1,$3)){
            error(@$,"Incompatible operands for "+op+": \""+$1->typeNode.typeName+"\", \""+$3->typeNode.typeName+"\"");
        }
        $$ = new op_binary_astnode(op, $1, $3);
    }
    if(Symbols::symTabStage==2){
        op = op.substr(0,op.size()-1);
        std::string t1 = newtemp(typespec_astnode::intc);
        gen(troins::ass,troins::bop,{t1,$1->addr,op,$3->addr});
        $$->addr = t1;
    }

}
| relational_expression '>' additive_expression{
    std::string op = "GT_OP?";
    if(Symbols::symTabStage>0){
        if(!op_binary_astnode::operandsCompatible(op,$1,$3)){
            error(@$,"Incompatible operands for "+op+": \""+$1->typeNode.typeName+"\", \""+$3->typeNode.typeName+"\"");
        }
        $$ = new op_binary_astnode(op, $1, $3);
    }
    if(Symbols::symTabStage==2){
        op = op.substr(0,op.size()-1);
        std::string t1 = newtemp(typespec_astnode::intc);
        gen(troins::ass,troins::bop,{t1,$1->addr,op,$3->addr});
        $$->addr = t1;

    }
}
| relational_expression LE_OP additive_expression{
    std::string op = "LE_OP?";
    if(Symbols::symTabStage>0){
        if(!op_binary_astnode::operandsCompatible(op,$1,$3)){
            error(@$,"Incompatible operands for "+op+": \""+$1->typeNode.typeName+"\", \""+$3->typeNode.typeName+"\"");
        }
        $$ = new op_binary_astnode(op, $1, $3);
    }
    if(Symbols::symTabStage==2){
        op = op.substr(0,op.size()-1);
        std::string t1 = newtemp(typespec_astnode::intc);
        gen(troins::ass,troins::bop,{t1,$1->addr,op,$3->addr});
        $$->addr = t1;

    }
}
| relational_expression GE_OP additive_expression{
    std::string op = "GE_OP?";
    if(Symbols::symTabStage>0){
        if(!op_binary_astnode::operandsCompatible(op,$1,$3)){
            error(@$,"Incompatible operands for "+op+": \""+$1->typeNode.typeName+"\", \""+$3->typeNode.typeName+"\"");
        }
        $$ = new op_binary_astnode(op, $1, $3);
    }
    if(Symbols::symTabStage==2){
        op = op.substr(0,op.size()-1);
        std::string t1 = newtemp(typespec_astnode::intc);
        gen(troins::ass,troins::bop,{t1,$1->addr,op,$3->addr});
        $$->addr = t1;

    }
}
;

additive_expression: multiplicative_expression{
    $$ = $1;
    // std::cerr<<__LINE__<<$$->typeNode.typeName<<endl;
}
| additive_expression '+' multiplicative_expression{
    if(Symbols::symTabStage!=0){
        std::string op = "PLUS?";
        if(!op_binary_astnode::operandsCompatible(op,$1,$3)){
            error(@$,"Incompatible operands for "+op+": \""+$1->typeNode.typeName+"\", \""+$3->typeNode.typeName+"\"");
        }
        $$ = new op_binary_astnode(op, $1, $3);
    }
    if(Symbols::symTabStage==2){
        $$->addr = newtemp(typespec_astnode::intc);
        gen(troins::ass,troins::bop,{$$->addr,$1->addr,"+",$3->addr});
    }
}
| additive_expression '-' multiplicative_expression{
    if(Symbols::symTabStage>0){
        std::string op = "MINUS?";
        if(!op_binary_astnode::operandsCompatible(op,$1,$3)){
            error(@$,"Incompatible operands for "+op+": \""+$1->typeNode.typeName+"\", \""+$3->typeNode.typeName+"\"");
        }
        $$ = new op_binary_astnode(op, $1, $3);
    }
    if(Symbols::symTabStage==2){
        $$->addr = newtemp(typespec_astnode::intc);
        gen(troins::ass,troins::bop,{$$->addr,$1->addr,"-",$3->addr});
    }
}
;

unary_expression: postfix_expression{
    $$ = $1;
    // std::cerr<<__LINE__<<$$->typeNode.typeName<<endl;
}
| unary_operator unary_expression{
    if(Symbols::symTabStage!=0){
        //validity checks.
        std::string op = $1;
        if(!op_unary_astnode::compatibleOperand($1,$2)){
            error(@$,"Incompatible operand for "+op+": \""+$2->typeNode.typeName+"\"");
        }
        $$ = new op_unary_astnode($1, $2);
        if($1=="ADDRESS"||$1=="DEREF"){
            if($1=="ADDRESS"&&(!$2->typeNode.islval)){
                error(@$,"Tried to get address of rval: "+$2->typeNode.typeName);
            }
            if($$->typeNode.typeName==$2->typeNode.typeName){
                error(@$,"Invalid operand type \"" + $2->typeNode.typeName +"\" of unary *");
            }
            int nrs = $2->typeNode.numptrstars + $2->typeNode.arrsizes.size();
            if($1=="DEREF"&&$2->typeNode.typeName.substr(0,4)=="void"&&(nrs==1)){
                error(@$,"Dereferenced incomplete type void*");
            }
        }
    }
    if(Symbols::symTabStage==2){
        std::string t0;
        if($2->isproxyaddr||$2->iselem){
            typespec_astnode tn = $2->typeNode;
            tn.deref();
            t0 = newtemp(tn);
            gen(troins::ass,troins::uop,{t0,"*",$2->addr});
        }
        else{
            t0 = $2->addr;
        }
        string op = unopName($1,true);
        if(op=="*"){
            $$->isproxyaddr = true;
            $$->addr = t0;
        }
        else{
            typespec_astnode tn = Symbols::getSymEntry(ststack.top(),t0,false)->type;
            if(op=="&"){
                tn.addressOf();
            }
            $$->addr = newtemp(tn);
            gen(troins::ass,troins::uop,{$$->addr,op,t0});
        }
    }
}
;

multiplicative_expression: unary_expression{
    if(Symbols::symTabStage!=0){   
        $$ = (op_binary_astnode*) $1;
    }
    if(Symbols::symTabStage==2){
        $$->addr = Symbols::resolveProxies($1,code,ststack.top());
    }
}
| multiplicative_expression '*' unary_expression{
    //operator and expression match check here.
    if(Symbols::symTabStage!=0){
        std::string op = "MULT?";
        if(!op_binary_astnode::operandsCompatible(op,$1,$3)){
            error(@$,"Incompatible operands for "+op+": \""+$1->typeNode.typeName+"\", \""+$3->typeNode.typeName+"\"");
        }
        $$ = new op_binary_astnode(op, $1, $3);
    }
    if(Symbols::symTabStage==2){
        $3->addr = Symbols::resolveProxies($3,code,ststack.top());
        $$->addr = newtemp(typespec_astnode::intc);
        gen(troins::ass,troins::bop,{$$->addr,$1->addr,"*",$3->addr});
    }
}
| multiplicative_expression '/' unary_expression{
    if(Symbols::symTabStage!=0){
        std::string op = "DIV?";
        if(!op_binary_astnode::operandsCompatible(op,$1,$3)){
            error(@$,"Incompatible operands for "+op+": \""+$1->typeNode.typeName+"\", \""+$3->typeNode.typeName+"\"");
        }
        $$ = new op_binary_astnode(op, $1, $3);
    }
    if(Symbols::symTabStage==2){
        $3->addr = Symbols::resolveProxies($3,code,ststack.top());
        $$->addr = newtemp(typespec_astnode::intc);
        gen(troins::ass,troins::bop,{$$->addr,$1->addr,"/",$3->addr});
    }
}
;

postfix_expression: primary_expression{
    $$ = $1;
}
| postfix_expression '[' expression ']'{
    if(Symbols::symTabStage!=0){
        if($1->typeNode.typeName.substr(0,4)=="void"){
            error(@$,"Tried to dereference an incomplete type.");
        }
        if($1->typeNode.numptrstars + $1->typeNode.arrsizes.size()==0){
            error(@$, "Tried to dereference a non-pointer");
        }
        if($3->typeNode.typeName!="int"){
            error(@$, "Argument passed to operator[] must be of type int.");
        }
        $$ = new arrayref_astnode($1, $3);
    }
    if(Symbols::symTabStage==2){
        /*
        t1 = $1->addr
        type = $1->typeNode
        type.deref()
        t2 = newTemp(); gen(t2 = expression.addr '*' type.typeWidth)
        gen: t3 = t1 + t2
        */
        typespec_astnode tmp = $1->typeNode;tmp.deref();
        std::string t0;
        if($1->isproxyaddr||$1->iselem){
            t0 = $1->addr;
        }
        else{
            typespec_astnode tn = $1->typeNode;
            tn.addressOf();
            t0 = newtemp(tn);
            gen(troins::ass,troins::uop,{t0,"&",$1->addr});
        }
        string t1 = newtemp(typespec_astnode::intc);
        gen(troins::ass,troins::bop,{t1, to_string(tmp.typeWidth),"*",$3->addr});
        typespec_astnode tn = Symbols::getSymEntry(ststack.top(),t0,false)->type;
        string t2 = newtemp(tn);
        gen(troins::ass,troins::bop,{t2, t0, "+", t1});
        $$->addr = t2;
        $$->iselem = true;
    }

}
| IDENTIFIER '(' ')'{
    if (Symbols::symTabStage>0) {
        std::string function_name = $1;
        if(!($1=="printf"||$1=="scanf")){
            SymTab* fstab = Symbols::flsts[function_name];
            if (fstab == nullptr) {
                error(@$, "Procedure \"" + $1 + "\" not declared");
            }
            std::set<std::pair<long long, std::string>> expected;
            for (auto row: fstab->rows) {
                if (row.second.lpgtype == SymTab::PARAM) {
                    expected.insert(std::make_pair(row.second.offset, row.second.type.typeName));
                }
            }
            if (!expected.empty()) {
                error(@$, "Procedure \"" + $1 + "\" called with too few arguments");
            }
            $$ = new funcall_astnode(new identifier_astnode($1), std::vector<exp_astnode*>(), false);
            $$->typeNode = Symbols::getSymEntry(Symbols::gst, $1)->type;
        }
        else {
            $$ = new funcall_astnode(new identifier_astnode($1), std::vector<exp_astnode*>(), false);
            $$->typeNode = voidc;
        }
    }
    if(Symbols::symTabStage==2){
        typespec_astnode tn = Symbols::getSymEntry(ststack.top(),$1,false)->type;
        $$->addr = newtemp(tn);
        gen(troins::ass,troins::call,{$$->addr,$1,"0"});
    }
}
| IDENTIFIER '(' expression_list ')'{
    std::reverse($3.begin(),$3.end());
    if (Symbols::symTabStage>0) {
        std::string function_name = $1;
        if(!($1=="printf"||$1=="scanf")){
            SymTab* fstab = Symbols::flsts[function_name];
            std::set<std::pair<long long, typespec_astnode>,struct offsetcomp> expected;
            for (auto row: fstab->rows) {
                if (row.second.lpgtype == SymTab::PARAM) {
                    expected.insert(std::make_pair(row.second.offset, row.second.type));
                }
            }
            if ($3.size() < expected.size()) {
                error(@$, "Procedure \"" + $1 + "\" called with too few arguments");
            }
            else if ($3.size() > expected.size()) {
                error(@$, "Procedure \"" + $1 + "\" called with too many arguments");
            }
            std::vector<exp_astnode*> exp_list = $3;
            std::reverse(exp_list.begin(), exp_list.end());
            int i = 0;
            for (auto item: expected) {
                if (!item.second.compatibleWith(exp_list[i]->typeNode,true)) {
                    error(@$, "Expected \"" + item.second.typeName + "\" but argument is of type \"" + exp_list[i]->typeNode.typeName + "\"");
                }
                else if(item.second.typeName != exp_list[i]->typeNode.typeName && item.second.isNumeric() && exp_list[i]->typeNode.isNumeric()) {
                    std::string ltypename = item.second.typeName;
                    std::transform(ltypename.begin(), ltypename.end(), ltypename.begin(), [](auto c) { return std::toupper(c); });
                    // std::cerr << ltypename << std::endl;
                    std::string utypename = "TO_" + ltypename;
                    exp_list[i] = new op_unary_astnode(utypename, exp_list[i]);
                }
                i++;
            }
            std::reverse(exp_list.begin(),exp_list.end());
            $$ = new funcall_astnode(new identifier_astnode($1), exp_list, false);
            $$->typeNode = Symbols::getSymEntry(Symbols::gst, $1)->type;
        }
        else {
            $$ = new funcall_astnode(new identifier_astnode($1), $3, false);
            $$->typeNode = voidc;
        }
    }
    if(Symbols::symTabStage==2){
        typespec_astnode tn = Symbols::getSymEntry(ststack.top(),$1,false)->type;
        $$->addr = newtemp(tn);
        for(exp_astnode* prm:$3){
            gen(troins::func,troins::param,{prm->addr});
        }
        gen(troins::ass,troins::call,{$$->addr,$1,to_string($3.size())});
    }
}
| postfix_expression '.' IDENTIFIER{
    //fix offset 
    std::string structName;
    if(Symbols::symTabStage!=0){
        if($1->typeNode.typeName.substr(0,6)!="struct"){
            error(@$,"LHS of . must be of type struct.");
        }
        $$ = new member_astnode($1, new identifier_astnode($3));
        structName = $1->typeNode.typeName;
        // std::cerr<<"symtab constr, structname: "<<structName<<std::endl;
        SymEntry* memberEntry = Symbols::getSymEntry(Symbols::slsts[structName],$3,true);
        if(memberEntry){
            $$->typeNode = memberEntry->type;
        }
        else{
            string errormsg = "Member "+$3+" not found in "+structName;
            error(@$,errormsg);
        }
    }
    if(Symbols::symTabStage==2){
        /*
        a.b
        t1 = &a
        t2 = t1 + offset
        t3 = *t2
        */
        string t1;
        string offset = to_string(Symbols::getOffsetInStruct(structName,$3));
        typespec_astnode tn = $1->typeNode;
        if(!($1->isproxyaddr||$1->iselem)){
            tn.addressOf();
            t1 = newtemp(tn);    
            gen(troins::ass,troins::uop,{t1,"&",$1->addr});
        }
        else{
            t1 = $1->addr;
        }
        SymEntry* memberEntry = Symbols::getSymEntry(Symbols::slsts[structName],$3,true);
        tn = memberEntry->type;
        tn.addressOf();
        string t2 = newtemp(tn);
        gen(troins::ass,troins::bop,{t2,t1,"+",offset});
        $$->addr = t2;
        $$->isproxyaddr=true;
    }
}
| postfix_expression PTR_OP IDENTIFIER{
    //fix offset
    std::string structName;
    if(Symbols::symTabStage!=0){
        if($1->typeNode.typeName.substr(0,6)!="struct"){
            error(@$,"LHS of -> must be of type struct.");
        }
        $$ = new arrow_astnode($1, new identifier_astnode($3));
        typespec_astnode dereftype = $1->typeNode;
        dereftype.deref();
        structName  = dereftype.typeName;
        $1->typeNode.compatibleWith(dereftype);
        SymEntry* memberEntry = Symbols::getSymEntry(Symbols::slsts[structName],$3,true);
        if(memberEntry){
            $$->typeNode = memberEntry->type;
        }
        else{
            string errormsg = "Member "+$3+" not found in "+structName;
            error(@$,errormsg);
        }
    }
    if(Symbols::symTabStage==2){
        /*
        a.b
        t1 = a + offset
        */
        string t1;
        typespec_astnode tn = $1->typeNode;
        if($1->isproxyaddr){
            tn.deref();
            t1 = newtemp(tn);
            gen(troins::ass,troins::uop,{t1,"*",$1->addr});
        }
        else{
            t1 = $1->addr;
        }
        string offset = to_string(Symbols::getOffsetInStruct(structName,$3));
        SymEntry*memberEntry = Symbols::getSymEntry(Symbols::slsts[structName],$3,true);
        tn = memberEntry->type;
        tn.addressOf();
        string t2 = newtemp(tn);
        gen(troins::ass,troins::bop,{t2,t1,"+",offset});
        $$->isproxyaddr = true;
        $$->addr = t2;
    }
}
| postfix_expression INC_OP{
    //fix offset.
    if(Symbols::symTabStage>0){
        if(!($1->typeNode.islval)){
            error(@$,"Postfix operator "+$2+" can only be applied to lvalues.");
        }
        if(!($1->typeNode.isNumeric()||($1->typeNode.numptrstars>0&&$1->typeNode.arrsizes.size()==0))){
            error(@$,"Invalid data type for postfix operator "+$2);
        }
        $$ = new op_unary_astnode("PP",$1);
        $$->typeNode = $1->typeNode;
        $$->typeNode.islval = false;
    }
    if(Symbols::symTabStage==2){
        string t0;
        if($1->isproxyaddr||$1->iselem){
            typespec_astnode tn = $1->typeNode;
            tn.deref();
            t0 = newtemp(tn);
            gen(troins::ass,troins::uop,{t0,"*",$1->addr});
        }
        else{
            t0 = $1->addr;
        }
        string t = newtemp($1->typeNode);
        $$->addr = t;
        gen(troins::ass,troins::na,{$$->addr,t0});
        if($1->isproxyaddr||$1->iselem){
            string t1 = newtemp($1->typeNode);
            gen(troins::ass,troins::bop,{t1,t0,"+","1"});
            gen(troins::ass,troins::ptrl,{$1->addr,t1});            
        }
        else{
            gen(troins::ass,troins::bop,{$1->addr,t0,"+","1"});
        }
        /*
        if \$\1 is proxy addr,
        t1=  t0+1
        *$\1->addr = t1
        else
        $\1->addr = t0+1
        */
    }
}
;

primary_expression: IDENTIFIER{
    if(Symbols::symTabStage!=0){
        //0 is pre symtab construction.
        $$ = new identifier_astnode($1);
        SymEntry * entry = Symbols::getSymEntry(ststack.top(),$1);
        if(!entry){
            std::string errormsg = "Variable \""+$1+"\" not declared";
            error(@$,errormsg);
        }
        else{
            $$->typeNode = entry->type;
            // std::cerr << __LINE__ << $$->typeNode.typeName<<std::endl;
        }
 
    }
    if(Symbols::symTabStage==2){
        $$->addr = $1;
    }
    // std::cerr<<"bloom"<<std::endl;
}
| INT_CONSTANT{
    if(Symbols::symTabStage!=0){   
        $$ = new intconst_astnode($1);
        $$->typeNode = intc;
        $$->typeNode.islval = false;
        if($1=="0"){
            $$->typeNode.isnullval = true;
        }
    }
    if(Symbols::symTabStage==2){
        $$->addr = $1;
    }

}
| STRING_LITERAL{
    if(Symbols::symTabStage!=0){   
        $$ = new stringconst_astnode($1);
        $$->typeNode = stringc;
        $$->typeNode.islval = false;
        // $$->print();
    }
    if(Symbols::symTabStage==2){
        $$->addr = Symbols::newStrLit($1);
    }
}
| '(' expression ')'{
    $$ = $2;
}
;

expression_list: expression{
    $$ = std::vector<exp_astnode*>();
    $$.push_back($1);
}
| expression_list ',' expression{
    $1.push_back($3);
    $$ = $1;
}
;
unary_operator: '-'{
    $$ = unopName("-");
}
|'!'{
    $$ = unopName("!");

}
|'&'{
    $$ = unopName("&");

}
|'*'{
    $$ = unopName("*");
}
;

selection_statement: IF {
    if(Symbols::symTabStage==2){
        code.condcode = true;
        code.condtype = ".if_cond";
    }
} '(' expression ')' {
    if(Symbols::symTabStage==2){
        code.condcode = false;
        code.condtype = "";
        std::string label = ".if_stmt_"+code.newLabel();
        code.setLabel(label);
        code.backpatch($4->tl,label);
    }
} statement {
    if(Symbols::symTabStage==2){
        
        $7->next = {code.nextinstr()};
        gen(troins::gt,troins::na,{""});
    }
} ELSE {
    if(Symbols::symTabStage==2){
        std::string label = ".else_stmt"+code.newLabel();
        code.setLabel(label);
        code.backpatch($4->fl,label);
    }
} statement{
    if(Symbols::symTabStage>0){  
        if(!($4->typeNode.isNumeric()||$4->typeNode.getnrs()>0)){
            error(@$,"Invalid type for condition expression in for loop");
        }    
        $$ = new if_astnode($4, $7, $11);
    }
    if(Symbols::symTabStage==2){
        std::string label=".if_exit_"+code.newLabel();
        code.setLabel(label);
        gen(troins::nop,troins::na,{});
        code.backpatch($7->next,label);
    }
}
;

iteration_statement: WHILE {
    if(Symbols::symTabStage==2){
        code.condtype=".while_cond";
        code.condcode = true;
    }
} mnterm '(' expression ')' {
    if(Symbols::symTabStage==2){
        code.condtype=".while_stmt";
    }
} mnterm {
    if(Symbols::symTabStage==2){
        code.condcode=false;
        code.condtype="";
        gen(troins::nop,troins::na,{});
    }
} statement{
    if(Symbols::symTabStage>0){   
        if(!($5->typeNode.isNumeric()||$5->typeNode.getnrs()>0)){
            error(@$,"Invalid type for condition expression in while loop");
        }   
        $$ = new while_astnode($5, $10);
    }
    if(Symbols::symTabStage==2){
        code.backpatch($5->tl,$8->nil);
        gen(troins::gt,troins::na,{$3->nil});
        std::string label = ".while_exit_"+code.newLabel();
        code.setLabel(label);
        code.backpatch($5->fl,label);
    }
}
| FOR '('  assignment_expression ';' {
    if(Symbols::symTabStage==2){
        code.condcode=true;
        code.condtype=".for_cond";
    }
} mnterm/*6*/ expression/*7*/ {
    if(Symbols::symTabStage==2){
        code.condtype=".for_incrementor";
    }
} mnterm/*9*/{
    if(Symbols::symTabStage==2){
        code.condcode=false;
        code.condtype="";
    }
} ';' assignment_expression ')'{
    if(Symbols::symTabStage==2){
        gen(troins::gt,troins::na,{$6->nil});
        code.condcode = true;
        code.condtype = ".for_stmt";
    }
} mnterm {
    if(Symbols::symTabStage==2){
        code.condcode = false;
        code.condtype = "";
        gen(troins::nop,troins::na,{});
    }
} statement{
    if(Symbols::symTabStage>0){
        if(!($7->typeNode.isNumeric()||$7->typeNode.getnrs()>0)){
            error(@$,"Invalid type for condition expression in for loop");
        }   
        $$ = new for_astnode($3, $7, $12, $17);
    }
    if(Symbols::symTabStage==2){
        code.backpatch($7->tl,$15->nil);
        gen(troins::gt,troins::na,{$9->nil});
        std::string label = ".for_exit_"+code.newLabel();
        code.setLabel(label);
        code.backpatch($7->fl,label);
    }
}
;

declaration_list: declaration{
}
| declaration_list declaration{
}
;

declaration:type_specifier declarator_list  ';'{
}
;

declarator_list: declarator{
    $$ = $1;
    // std::cerr<<$1.typeName<<" has "<<$1.numptrstars<<" stars"<<std::endl;
    string type = $1.typeName;
    int size = $1.typeWidth;
    if(Symbols::symTabStage==0){
        // std::cerr<<topvarname<<": "<<size<<" "<<std::endl;
        int offset = ststack.top()->getNewOffset(size);
        SymTab* st = ststack.top();
        if($1.typeName=="void"){
            error(@$,"Cannot declare variable of type \"void\"");
        }
        st->rows[topvarname] = SymEntry($1,SymTab::ST_HL_type::VAR,SymTab::ST_LPG::LOCAL,size,offset);
    }
}
| declarator_list ',' declarator{
    $$ = $3;
    string type = $3.typeName;
    int size = $3.typeWidth;
    if(Symbols::symTabStage==0){
        if($3.typeName=="void"){
            error(@$,"Cannot declare variable of type \"void\"");
        }
        int offset = ststack.top()->getNewOffset(size);
        ststack.top()->rows[topvarname] = SymEntry($3,SymTab::ST_HL_type::VAR,SymTab::ST_LPG::LOCAL,size,offset);
    }
}
;

%%
//grammar definition.
void 
IPL::Parser::error( const location_type &l, const std::string &err_message )
{
   std::cout << "Error at line " << l.begin.line << ": " << err_message << "\n";
   exit(1);
}

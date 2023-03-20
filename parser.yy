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
#undef yylex
#define yylex IPL::Parser::scanner.yylex
stack<SymTab*> ststack;
int retType;
typespec_astnode structc,intc,voidc,floatc,stringc;
typespec_astnode toptype;
string topvarname;
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
%token <std::string> ELSE
%token <std::string> WHILE
%token <std::string> FOR
%token <std::string> RETURN
%token <std::string> OTHERS
%left '+' '-'
%left '*' '/'
%token '=' '(' ')' ',' '{' '}' '[' ']' '!' '&' '<' '>' ';' '\n'
%nterm <std::vector<abstract_astnode*>> translation_unit begin_nterm
%nterm <abstract_astnode*> struct_specifier declaration_list

%nterm <exp_astnode*> expression unary_expression postfix_expression primary_expression //assignment_expression

%nterm <op_binary_astnode*> logical_and_expression equality_expression relational_expression additive_expression multiplicative_expression

%nterm <funcall_astnode*> procedure_call

%nterm <assignE_astnode*> assignment_expression

%nterm <statement_astnode*> function_definition statement selection_statement iteration_statement assignment_statement

%nterm <std::vector<statement_astnode*>> compound_statement statement_list
%nterm <std::vector<exp_astnode*>> expression_list

%nterm <std::string> unary_operator
%nterm <typespec_astnode> type_specifier declaration declarator_list declarator declarator_arr parameter_declaration
%nterm <std::vector<typespec_astnode>> parameter_list 
%nterm <fundeclarator_astnode*> fun_declarator
%%
begin_nterm: {
    structc = typespec_astnode::structc;
    intc = typespec_astnode::intc;
    floatc = typespec_astnode::floatc;
    stringc = typespec_astnode::stringc;
    voidc = typespec_astnode::voidc;
    if(!Symbols::symTabConstructed){
        Symbols::gst = new SymTab();
        Symbols::initGST();
    }
    else{
        // std::cout<<"Here again";
    }
    ststack.push(Symbols::gst);

} translation_unit {
    if(!Symbols::symTabConstructed){
        Symbols::symTabConstructed = true;
        // ststack.top()->printJson();
        // std::cerr<<"Parsing round 1 done"<<std::endl;
    }
    else{
        ststack.top()->printJson();
        // std::cout<<"here again"<<std::endl;
    }
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
    if(!Symbols::symTabConstructed){
        ststack.top()->rows[structName] = SymEntry(structc,SymTab::ST_HL_type::STRUCT,SymTab::ST_LPG::GLOBAL,0,0);
        Symbols::slsts[structName] = new SymTab();
        Symbols::slsts[structName]->type = "struct";
    }
    ststack.push(Symbols::slsts[structName]);
}'{' declaration_list '}' ';'{
    // if(!Symbols::symTabConstructed){
    ststack.pop();
    if(!Symbols::symTabConstructed){
        for(auto entry: ststack.top()->rows){
            if(entry.second.size==0&&entry.second.hltype==SymTab::ST_HL_type::STRUCT){
                ststack.top()->rows[entry.first].size = Symbols::getStructBaseTypeWidth(entry.first);
            }
        }
    }
    // }
};

function_definition: type_specifier fun_declarator compound_statement{
    if(Symbols::symTabConstructed){
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
    if(!Symbols::symTabConstructed){
        toptype = ts;
    }

}
| INT{
    // retType = SymTab::ST_type::INT;
    typespec_astnode ts = intc;
    $$ = ts;
    if(!Symbols::symTabConstructed){
        toptype = ts;
    }

}
| FLOAT{
    // retType = SymTab::ST_type::FLOAT;
    typespec_astnode ts = floatc;
    $$ = ts;
    if(!Symbols::symTabConstructed){
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
    if(!Symbols::symTabConstructed){
        toptype = ts;
    }
}
;

fun_declarator: IDENTIFIER '('{
    std::string name = $1;
    if(!Symbols::symTabConstructed){
        ststack.top()->rows[name] = SymEntry(toptype,SymTab::ST_HL_type::FUN,SymTab::ST_LPG::GLOBAL,0,0);
        Symbols::flsts[name] = new SymTab();
        Symbols::flsts[name]->type = "function";
        Symbols::flsts[name]->rettype = new typespec_astnode();
        *(Symbols::flsts[name]->rettype) = toptype;
    }
    ststack.push(Symbols::flsts[name]);
} parameter_list ')'{
    $$ = NULL;
    if(!Symbols::symTabConstructed){
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
        //TODO: fix this.
        std::string name = $1;
        std::vector<typespec_astnode> vect = std::vector<typespec_astnode>();
        $$ = new fundeclarator_astnode(name, vect);
    }
}
| IDENTIFIER '(' ')'{
    std::string name = $1;
    if(!Symbols::symTabConstructed){
        ststack.top()->rows[name] = SymEntry(toptype,SymTab::ST_HL_type::FUN,SymTab::ST_LPG::GLOBAL,0,0);
        Symbols::flsts[name] = new SymTab();
        Symbols::flsts[name]->rettype = new typespec_astnode;
        Symbols::flsts[name]->type = "function";
        *(Symbols::flsts[name]->rettype) = toptype;
    }
    else{
        $$ = new fundeclarator_astnode(name,std::vector<typespec_astnode>());
    }
    ststack.push(Symbols::flsts[name]);
}
;

parameter_list: parameter_declaration{
    if(Symbols::symTabConstructed){
        $$ = std::vector<typespec_astnode>();
        $$.push_back($1);
    }
}
| parameter_declaration ',' parameter_list {
    if(Symbols::symTabConstructed){
        $$ = $3;
        $$.push_back($1);
    }
}
;

parameter_declaration: type_specifier declarator{
    $$ = $1;
    if(!Symbols::symTabConstructed){
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
    if(!Symbols::symTabConstructed){
        topvarname = $1;
    }
}
| declarator_arr '[' INT_CONSTANT ']'{
    $$ = $1;
    if(!Symbols::symTabConstructed){
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
    //TODO
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
    if(Symbols::symTabConstructed){   
        $$ = new empty_astnode();
    }
}
| '{' statement_list '}'{
    if(Symbols::symTabConstructed){   
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
| RETURN expression ';'{
    if(Symbols::symTabConstructed){
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
}
;

assignment_expression: unary_expression '=' expression{
    if(Symbols::symTabConstructed){
        // std::cerr<<__LINE__<<std::endl;
        std::cerr<<$1->typeNode.typeName<<" = "<<$3->typeNode.typeName<<std::endl;
        if(($1->typeNode.compatibleWith($3->typeNode))){
            // std::cerr<<__LINE__<<std::endl;
            if(!($1->typeNode.islval)){
                error(@$,"Error: "+$1->typeNode.typeName +" is not an lval.");
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
}
;

assignment_statement: assignment_expression ';'{
    if(Symbols::symTabConstructed){
        $$ = new assignS_astnode($1->exp1, $1->exp2);
    }
}
;

procedure_call: IDENTIFIER '(' ')' ';'{
    if (Symbols::symTabConstructed) {
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
}
| IDENTIFIER '(' expression_list ')' ';'{
    if (Symbols::symTabConstructed) {
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
}
;

expression: logical_and_expression{
    $$ = $1;
    // std::cerr<<__LINE__<<$$->typeNode.typeName<<endl;
}
| expression OR_OP logical_and_expression{
    if(Symbols::symTabConstructed){
        $$ = new op_binary_astnode("OR_OP",$1,$3);
    }
}
;

logical_and_expression: equality_expression{
    $$ = $1;
    // std::cerr<<__LINE__<<$$->typeNode.typeName<<endl;
}
| logical_and_expression AND_OP equality_expression{
    if(Symbols::symTabConstructed){   
        $$ = new op_binary_astnode("AND_OP", $1, $3);
    }
}
;

equality_expression: relational_expression{
    $$ = $1;
    // std::cerr<<__LINE__<<$$->typeNode.typeName<<endl;
}
| equality_expression EQ_OP relational_expression {
    if(Symbols::symTabConstructed){
        std::string op = "EQ_OP?";
        if(!op_binary_astnode::operandsCompatible(op,$1,$3)){
            error(@$,"Incompatible operands for "+op+": \""+$1->typeNode.typeName+"\", \""+$3->typeNode.typeName+"\"");
        }
        $$ = new op_binary_astnode(op, $1, $3);
    }
}
| equality_expression NE_OP relational_expression{
    if(Symbols::symTabConstructed){ 
        std::string op = "NE_OP?";
        if(!op_binary_astnode::operandsComptible(op,$1,$3)){
            error(@$,"Incompatible operands for "+op+": \""+$1->typeNode.typeName+"\", \""+$3->typeNode.typeName+"\"");
        }
        $$ = new op_binary_astnode("NE_OP?", $1, $3);
    }
}
;

relational_expression: additive_expression{
    $$ = $1;
    // std::cerr<<__LINE__<<$$->typeNode.typeName<<endl;
}
| relational_expression '<' additive_expression{
    if(Symbols::symTabConstructed){
        $$ = new op_binary_astnode("LT_OP?", $1, $3);
    }
}
| relational_expression '>' additive_expression{
    if(Symbols::symTabConstructed){
        $$ = new op_binary_astnode("GT_OP?", $1, $3);
    }
}
| relational_expression LE_OP additive_expression{
    if(Symbols::symTabConstructed){
        $$ = new op_binary_astnode("LE_OP?", $1, $3);
    }
}
| relational_expression GE_OP additive_expression{
    if(Symbols::symTabConstructed){
        $$ = new op_binary_astnode("GE_OP?", $1, $3);
    }
}
;

additive_expression: multiplicative_expression{
    $$ = $1;
    // std::cerr<<__LINE__<<$$->typeNode.typeName<<endl;
}
| additive_expression '+' multiplicative_expression{
    if(Symbols::symTabConstructed){
        $$ = new op_binary_astnode("PLUS?", $1, $3);
    }
}
| additive_expression '-' multiplicative_expression{
    if(Symbols::symTabConstructed){
        $$ = new op_binary_astnode("MINUS?", $1, $3);
    }
}
;

unary_expression: postfix_expression{
    $$ = $1;
    // std::cerr<<__LINE__<<$$->typeNode.typeName<<endl;
}
| unary_operator unary_expression{
    if(Symbols::symTabConstructed){
        //validity checks.
        $$ = new op_unary_astnode($1, $2);
        if($1=="ADDRESS"||$1=="DEREF"){
            if($1=="ADDRESS"&&(!$2->typeNode.islval)){
                error(@$,"Tried to get address of rval: "+$2->typeNode.typeName);
            }
            if($$->typeNode.typeName==$2->typeNode.typeName){
                error(@$,"Invalid operand type \"" + $2->typeNode.typeName +"\" of unary *");
            }
        }
    }
}
;

multiplicative_expression: unary_expression{
    if(Symbols::symTabConstructed){   
        $$ = (op_binary_astnode*) $1;
    }

}
| multiplicative_expression '*' unary_expression{
    //operator and expression match check here.
    if(Symbols::symTabConstructed){
        $$ = new op_binary_astnode("MULT?", $1, $3);
    }
}
| multiplicative_expression '/' unary_expression{
    if(Symbols::symTabConstructed){
        $$ = new op_binary_astnode("DIV?", $1, $3);
    }
}
;

postfix_expression: primary_expression{
    $$ = $1;
}
| postfix_expression '[' expression ']'{
    if(Symbols::symTabConstructed){   
        $$ = new arrayref_astnode($1, $3);
    }
}
| IDENTIFIER '(' ')'{
    if (Symbols::symTabConstructed) {
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
}
| IDENTIFIER '(' expression_list ')'{
    if (Symbols::symTabConstructed) {
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
}
| postfix_expression '.' IDENTIFIER{
    if(Symbols::symTabConstructed){
        $$ = new member_astnode($1, new identifier_astnode($3));
        std::cerr<<"using this rule"<<std::endl;
        std::string structName = $1->typeNode.typeName;
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
}
| postfix_expression PTR_OP IDENTIFIER{
    if(Symbols::symTabConstructed){
        $$ = new arrow_astnode($1, new identifier_astnode($3));
        typespec_astnode dereftype = $1->typeNode;
        dereftype.deref();
        std::string structName  = dereftype.typeName;
        //TODO restrict global table search here.
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
}
| postfix_expression INC_OP{
    if(Symbols::symTabConstructed){
        //type checks for $1
        
        $$ = new op_unary_astnode("PP",$1);
        $$->typeNode = $1->typeNode;
    }
}
;

primary_expression: IDENTIFIER{
    if(Symbols::symTabConstructed){
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
    std::cerr<<"bloom"<<std::endl;
}
| INT_CONSTANT{
    if(Symbols::symTabConstructed){   
        $$ = new intconst_astnode($1);
        $$->typeNode = intc;
        $$->typeNode.islval = false;
        if($1=="0"){
            $$->typeNode.isnullval = true;
        }
    }
}
| FLOAT_CONSTANT{
    if(Symbols::symTabConstructed){   
        $$ = new floatconst_astnode($1);
        $$->typeNode = floatc;
        $$->typeNode.islval = false;
    }
}
| STRING_LITERAL{
    if(Symbols::symTabConstructed){   
        $$ = new stringconst_astnode($1);
        $$->typeNode = stringc;
        $$->typeNode.islval = false;
        // $$->print();
    }
}
| '(' expression ')'{
    $$ = $2;
}
;

expression_list: expression{
    $$ = std::vector<exp_astnode*>();
    $$.push_back($1);
    // std::cerr << __LINE__ << (*($$.rbegin()))->typeNode.typeName<<std::endl;
}
| expression_list ',' expression{
    $1.push_back($3);
    $$ = $1;
}
;
unary_operator: '-'{
    $$ = std::string("UMINUS");
}
| '!'{
    $$ = std::string("NOT");
}
| '&'{
    $$ = std::string("ADDRESS");
}
| '*'{
    $$ = std::string("DEREF");
}
;

selection_statement: IF '(' expression ')' statement ELSE statement{
    if(Symbols::symTabConstructed){   
        $$ = new if_astnode($3, $5, $7);
    }
}
;

iteration_statement: WHILE '(' expression ')' statement{
    if(Symbols::symTabConstructed){   
        $$ = new while_astnode($3, $5);
    }
}
| FOR '(' assignment_expression ';' expression ';' assignment_expression ')' statement{
    if(Symbols::symTabConstructed){   
        $$ = new for_astnode($3, $5, $7, $9);
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
    if(!Symbols::symTabConstructed){
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
    if(!Symbols::symTabConstructed){
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

%skeleton "lalr1.cc"
%require  "3.0.1"

%defines 
%define api.namespace {IPL}
%define api.parser.class {Parser}

%define parse.trace

%code requires{
    #include "location.hh"
    #include "ast.hh"

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
typespec_astnode toptype;
typespec_astnode structc, intc, floatc,stringc;
string topvarname;
}

%define api.value.type variant
%define api.location.type {IPL::location}
%define parse.assert

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
%nterm <abstract_astnode*> struct_specifier procedure_call declaration_list

%nterm <exp_astnode*> expression logical_and_expression equality_expression relational_expression additive_expression unary_expression multiplicative_expression postfix_expression primary_expression expression_list //assignment_expression

%nterm <assignE_astnode*> assignment_expression

%nterm <statement_astnode*> function_definition statement selection_statement iteration_statement assignment_statement

%nterm <std::vector<statement_astnode*>> compound_statement statement_list

%nterm <std::string> unary_operator
%nterm <typespec_astnode> type_specifier declaration declarator_list declarator declarator_arr parameter_declaration
%nterm <std::vector<typespec_astnode>> parameter_list 
%nterm <fundeclarator_astnode*> fun_declarator
%%
begin_nterm: {
    structc.baseTypeWidth = 0;
    structc.baseTypeName = "struct";
    structc.typeName = "struct";
    structc.typeWidth = 0;
    intc.baseTypeWidth = 4;
    intc.baseTypeName = "int";
    intc.typeName = "int";
    intc.typeWidth = 4;
    floatc.baseTypeWidth = 8;
    floatc.baseTypeName = "float";
    floatc.typeName = "float";
    floatc.typeWidth = 8;
    stringc.baseTypeWidth = 0;
    stringc.baseTypeName = "string";
    stringc.typeName = "string";
    stringc.typeWidth = 0;
    if(!Symbols::symTabConstructed){
        Symbols::gst = new SymTab();
        ststack.push(Symbols::gst);
    }
    else{
        // std::cout<<"Here again";
    }

} translation_unit {
    if(!Symbols::symTabConstructed){
        ststack.top()->printJson();
        Symbols::symTabConstructed = true;
    }
}

translation_unit: struct_specifier{
    if(!Symbols::symTabConstructed){
        for(auto entry: ststack.top()->rows){
            if(entry.second.size==0&&entry.second.hltype==SymTab::ST_HL_type::STRUCT){
                ststack.top()->rows[entry.first].size = Symbols::getStructBaseTypeWidth(entry.first);
            }
        }
    }
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
    if(!Symbols::symTabConstructed){
        string structName = "struct " + $2;
        ststack.top()->rows[structName] = SymEntry(structc,SymTab::ST_HL_type::STRUCT,SymTab::ST_LPG::GLOBAL,0,0);
        Symbols::slsts[structName] = new SymTab();
        Symbols::slsts[structName]->type = "struct";
        // Symbols::slsts[$2] = new SymTab();
        ststack.push(Symbols::slsts[structName]);
    }
}'{' declaration_list '}' ';'{
    if(!Symbols::symTabConstructed){
        ststack.pop();
    }
};

function_definition: type_specifier fun_declarator compound_statement{
    $$ = new seq_astnode($3);
    if(!Symbols::symTabConstructed){
        ststack.pop();
    }
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
    typespec_astnode ts;
    ts.baseTypeWidth = 4;
    ts.typeWidth = ts.baseTypeWidth;
    ts.typeName = "int";
    ts.baseTypeName = "int";
    $$ = ts;
    if(!Symbols::symTabConstructed){
        toptype = ts;
    }

}
| FLOAT{
    // retType = SymTab::ST_type::FLOAT;
    typespec_astnode ts;
    ts.baseTypeWidth = 8;
    ts.typeWidth = ts.baseTypeWidth;
    ts.typeName = "float";
    ts.baseTypeName = "float";
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
    if(!Symbols::symTabConstructed){
        std::string name = $1;
        ststack.top()->rows[name] = SymEntry(toptype,SymTab::ST_HL_type::FUN,SymTab::ST_LPG::GLOBAL,0,0);
        Symbols::flsts[name] = new SymTab();
        Symbols::flsts[name]->type = "function";
        ststack.push(Symbols::flsts[name]);
    }
} parameter_list ')'{
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
    //TODO: fix this.
    
    std::string name = $1;
    std::vector<typespec_astnode> vect = std::vector<typespec_astnode>();
    $$ = new fundeclarator_astnode(name, vect);
}
| IDENTIFIER '(' ')'{
    std::string name = $1;
    $$ = new fundeclarator_astnode(name,std::vector<typespec_astnode>());
    if(!Symbols::symTabConstructed){
        ststack.top()->rows[name] = SymEntry(toptype,SymTab::ST_HL_type::FUN,SymTab::ST_LPG::GLOBAL,0,0);
        Symbols::flsts[name] = new SymTab();
        ststack.push(Symbols::flsts[name]);
    }
}
;

parameter_list: parameter_declaration{
    $$ = std::vector<typespec_astnode>();
    $$.push_back($1);
}
| parameter_declaration ',' parameter_list {
    $$ = $3;
    $$.push_back($1);
}
;

parameter_declaration: type_specifier declarator{
    $$ = $1;
    if(!Symbols::symTabConstructed){
        ststack.top()->rows[topvarname] = SymEntry(toptype,SymTab::ST_HL_type::VAR,SymTab::ST_LPG::PARAM,toptype.typeWidth,0);
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
    $$ = toptype;
    typespec_astnode tstmp = $1;
    $$.typeWidth = ((tstmp).typeWidth) * (std::stoi($3));
    $$.typeName = (tstmp).typeName+"["+($3)+"]";
    $$.arrsizes.push_back(std::stoi($3));
};

declarator: declarator_arr{
    $$ = $1;
}
| '*' declarator {
    $$.typeWidth = 4;
    $$.baseTypeWidth = $2.typeWidth;
    $$.typeName = $2.typeName+"*";
    $$.numptrstars+=1;
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
    $$ = NULL;
}
| '{' statement_list '}'{
    $$ = new seq_astnode($2);
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
    $$ = NULL;
}
| RETURN expression ';'{
    $$ = NULL;
}
;

assignment_expression: unary_expression '=' expression{
    $$ = new assignE_astnode($1, $3);
}
;

assignment_statement: assignment_expression ';'{
    $$ = new assignS_astnode($1->exp1, $1->exp2);
}
;

procedure_call: IDENTIFIER '(' ')' ';'{
}
| IDENTIFIER '(' expression_list ')' ';'{
}
;

expression: logical_and_expression{
    $$ = $1;
}
| expression OR_OP logical_and_expression{
}
;

logical_and_expression: equality_expression{
    $$ = $1;
}
| logical_and_expression AND_OP equality_expression{
    $$ = new op_binary_astnode("AND?", $1, $3);
}
;

equality_expression: relational_expression{
    $$ = $1;
}
| equality_expression EQ_OP relational_expression {
    $$ = new op_binary_astnode("EQ?", $1, $3);
}
| equality_expression NE_OP relational_expression{
    $$ = new op_binary_astnode("NE?", $1, $3);
}
;

relational_expression: additive_expression{
    $$ = $1;
}
| relational_expression '<' additive_expression{
    $$ = new op_binary_astnode("LT?", $1, $3);
}
| relational_expression '>' additive_expression{
    $$ = new op_binary_astnode("GT?", $1, $3);
}
| relational_expression LE_OP additive_expression{
    $$ = new op_binary_astnode("LE?", $1, $3);
}
| relational_expression GE_OP additive_expression{
    $$ = new op_binary_astnode("GE?", $1, $3);
}
;

additive_expression: multiplicative_expression{
    $$ = $1;
}
| additive_expression '+' multiplicative_expression{
    $$ = new op_binary_astnode("PLUS?", $1, $3);
}
| additive_expression '-' multiplicative_expression{
    $$ = new op_binary_astnode("MINUS?", $1, $3);
}
;

unary_expression: postfix_expression{
    $$ = $1;
}
| unary_operator unary_expression{
    $$ = new op_unary_astnode($1, $2);
}
;

multiplicative_expression: unary_expression{
    $$ = $1;
}
| multiplicative_expression '*' unary_expression{
    $$ = new op_binary_astnode("MULT?", $1, $3);
    //overloading resolution.
}
| multiplicative_expression '/' unary_expression{
    $$ = new op_binary_astnode("DIV?", $1, $3);
    //overloading resolution.
}
;

postfix_expression: primary_expression{
    $$ = $1;
}
| postfix_expression '[' expression ']'{
    $$ = new arrayref_astnode($1, $3);
}
| IDENTIFIER '(' ')'{
    //TODO Funcall
}
| IDENTIFIER '(' expression_list ')'{
    //TODO funcall
}
| postfix_expression '.' IDENTIFIER{
    $$ = new member_astnode($1, new identifier_astnode($3));
    //TODO
    std::string structName = $1->typeNode.typeName;
    SymEntry* memberEntry = Symbols::getSymEntry(Symbols::slsts[structName],$3);
    if(memberEntry){
        $$->typeNode = memberEntry->type;
    }
    else{
        //throw member dne
    }
}
| postfix_expression PTR_OP IDENTIFIER{
    $$ = new member_astnode(new arrow_astnode($1, new identifier_astnode($3)), new identifier_astnode($3));
    typespec_astnode dereftype = $1->typeNode;
    dereftype.deref();
    std::string structName  = dereftype.typeName;
    //TODO restrict global table search here.
    SymEntry* memberEntry = Symbols::getSymEntry(Symbols::slsts[structName],$3);
    if(memberEntry){
        $$->typeNode = memberEntry->type;
    }
    else{
        //throw member dne
    }
}
| postfix_expression INC_OP{
    
}
;

primary_expression: IDENTIFIER{
    $$ = new identifier_astnode($1);
    if(Symbols::symTabConstructed){
        SymEntry * entry = Symbols::getSymEntry(ststack.top(),$1);
        if(!entry){
            std::cout<<"Write error handling code."<<endl;
        }
        else{
            $$->typeNode = entry->type;
        }
    }
}
| INT_CONSTANT{
    $$ = new intconst_astnode($1);
    $$->typeNode = intc;
}
| FLOAT_CONSTANT{
    $$ = new floatconst_astnode($1);
    $$->typeNode = floatc;
}
| STRING_LITERAL{
    $$ = new stringconst_astnode($1);
    $$->typeNode = stringc;
    $$->print();
}
| '(' expression ')'{
    //TODO
    $$ = $2;
}
;

expression_list: expression{
}
| expression_list ',' expression{
}
;

unary_operator: '-'{
    $$ = std::string("UMINUS?");
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
    $$ = new if_astnode($3, $5, $7);
}
;

iteration_statement: WHILE '(' expression ')' statement{
    $$ = new while_astnode($3, $5);
}
| FOR '(' assignment_expression ';' expression ';' assignment_expression ')' statement{
    $$ = new for_astnode($3, $5, $7, $9);
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
    string type = $1.typeName;
    int size = $1.typeWidth;
    if(!Symbols::symTabConstructed){
        int offset = ststack.top()->getNewOffset(size);
        SymTab* st = ststack.top();
        st->rows[topvarname] = SymEntry($1,SymTab::ST_HL_type::VAR,SymTab::ST_LPG::LOCAL,size,offset);
    }
}
| declarator_list ',' declarator{
    $$ = $3;
    string type = $3.typeName;
    int size = $3.typeWidth;
    if(!Symbols::symTabConstructed){
        int offset = ststack.top()->getNewOffset(size);
        ststack.top()->rows[topvarname] = SymEntry($3,SymTab::ST_HL_type::VAR,SymTab::ST_LPG::LOCAL,size,offset);
    }
}
;

%%
//grammar definition.
void IPL::Parser::error( const location_type &l, const std::string &err_message )
{
   std::cerr << "Error: " << err_message << " at " << l << "\n";
}

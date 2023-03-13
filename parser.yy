%skeleton "lalr1.cc"
%require  "3.0.1"

%defines 
%define api.namespace {IPL}
%define api.parser.class {Parser}

%define parse.trace

%code requires{
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
string topvarname;
}

%define api.value.type variant
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
    Symbols::gst = new SymTab();
    ststack.push(Symbols::gst);
    // std::cout<<"pushed onto stack"<<Symbols::gst<<"\n";
} translation_unit {
    // std::cout << "about to begin printing\n";
    // for (auto item: $2) {
    //     item->print();
    // }
    // ststack.top()->printJson();
    // std::cout <<"printed\n";
    
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
    ststack.top()->rows[structName] = SymEntry("struct",SymTab::ST_HL_type::STRUCT,SymTab::ST_LPG::GLOBAL,0,0);
    Symbols::slsts[structName] = new SymTab();
    ststack.push(Symbols::slsts[structName]);
}'{' declaration_list '}' ';'{
    ststack.pop();
};

function_definition: type_specifier fun_declarator compound_statement{
    $$ = new seq_astnode($3);
    ststack.pop();
};

type_specifier: VOID{
    typespec_astnode ts;
    ts.baseTypeWidth = 0;
    ts.typeName = "void";
    $$ = ts;
    toptype = ts;

}
| INT{
    // retType = SymTab::ST_type::INT;
    typespec_astnode ts;
    ts.baseTypeWidth = 4;
    ts.typeName = "int";
    $$ = ts;
    toptype = ts;

}
| FLOAT{
    // retType = SymTab::ST_type::FLOAT;
    typespec_astnode ts;
    ts.baseTypeWidth = 8;
    ts.typeName = "float";
    $$ = ts;
    toptype = ts;
}
| STRUCT IDENTIFIER{
    // retType = SymTab::ST_type::STRUCT_TYPE;
    typespec_astnode ts;
    string structname = $2;
    ts.baseTypeWidth = Symbols::getStructBaseTypeWidth(structname);
    ts.typeName = "struct "+($2);
    $$ = ts;
    toptype = ts;
}
;

fun_declarator: IDENTIFIER '(' parameter_list ')'{
    std::string name = $1;
    $$ = new fundeclarator_astnode(name, $3);
    ststack.top()->rows[name] = SymEntry(toptype.typeName,SymTab::ST_HL_type::FUN,SymTab::ST_LPG::GLOBAL,0,0);
    Symbols::flsts[name] = new SymTab();
    ststack.push(Symbols::flsts[name]);
}
| IDENTIFIER '(' ')'{
    std::string name = $1;
    $$ = new fundeclarator_astnode(name,std::vector<typespec_astnode>());
    ststack.top()->rows[name] = SymEntry(toptype.typeName,SymTab::ST_HL_type::FUN,SymTab::ST_LPG::GLOBAL,0,0);
    Symbols::flsts[name] = new SymTab();
    ststack.push(Symbols::flsts[name]);
}
;

parameter_list: parameter_declaration{
    $$ = std::vector<typespec_astnode>();
    $$.push_back($1);
}
| parameter_list ',' parameter_declaration{
    $$ = $1;
    $$.push_back($3);
}
;

parameter_declaration: type_specifier declarator{
    $$ = $1;
}
;

declarator_arr: IDENTIFIER{
    $$ = toptype;
    $$.typeWidth = $$.baseTypeWidth;
    topvarname = $1;
}
| declarator_arr '[' INT_CONSTANT ']'{
    $$ = toptype;
    typespec_astnode tstmp = $1;
    $$.typeWidth = ((tstmp).typeWidth) * (std::stoi($3));
    $$.typeName = "array("+(tstmp).typeName+","+($3)+")";

}
;

declarator: declarator_arr{
    $$ = $1;
}
| '*' declarator {
    $$.typeWidth = 4;
    $$.baseTypeWidth = $2.typeWidth;
    $$.typeName = "pointer("+$2.typeName+")";
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
}
| multiplicative_expression '/' unary_expression{
    $$ = new op_binary_astnode("DIV?", $1, $3);
}
;

postfix_expression: primary_expression{
    $$ = $1;
}
| postfix_expression '[' expression ']'{
    $$ = new arrayref_astnode($1, $3);
}
| IDENTIFIER '(' ')'{
}
| IDENTIFIER '(' expression_list ')'{
}
| postfix_expression '.' IDENTIFIER{
    $$ = new member_astnode($1, new identifier_astnode($3));
}
| postfix_expression PTR_OP IDENTIFIER{
    $$ = new arrow_astnode($1, new identifier_astnode($3));
}
| postfix_expression INC_OP{
    
}
;

primary_expression: IDENTIFIER{
    $$ = new identifier_astnode($1);
}
| INT_CONSTANT{
    $$ = new intconst_astnode($1);
}
| FLOAT_CONSTANT{
    $$ = new floatconst_astnode($1);
}
| STRING_LITERAL{
    $$ = new stringconst_astnode($1);
    $$->print();
}
| '(' expression ')'{
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
    int offset = ststack.top()->getNewOffset();
    SymTab* st = ststack.top();

    st->rows[topvarname] = SymEntry(type,SymTab::ST_HL_type::VAR,SymTab::ST_LPG::LOCAL,size,offset);
}
| declarator_list ',' declarator{
    $$ = $3;
    string type = $3.typeName;
    int size = $3.typeWidth;
    int offset = ststack.top()->getNewOffset();
    ststack.top()->rows[topvarname] = SymEntry(type,SymTab::ST_HL_type::VAR,SymTab::ST_LPG::LOCAL,size,offset);
}
;

%%
//grammar definition.
void IPL::Parser::error( const location_type &l, const std::string &err_message )
{
   std::cerr << "Error: " << err_message << " at " << l << "\n";
}

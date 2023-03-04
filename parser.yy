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
   #include "scanner.hh"

#undef yylex
#define yylex IPL::Parser::scanner.yylex
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

%nterm <abstract_astnode*> begin_nterm, translation_unit struct_specifier function_definition fun_declarator parameter_list parameter_declaration declarator_arr declarator compound_statement statement_list statement assignment_expression assignment_statement procedure_call expression logical_and_expression equality_expression relational_expression additive_expression unary_expression multiplicative_expression postfix_expression primary_expression expression_list selection_statement iteration_statement declaration_list declaration declarator_list 

%nterm <exp_astnode*> 

%nterm <statement_astnode*> function_definition 

%nterm <std::vector<statement_astnode*>> compound_statement statement_list

%nterm <std::string> type_specifier, unary_operator
%%
begin_nterm: translation_unit {
    $1->print();
}

translation_unit: struct_specifier{
}
| function_definition{
}
| translation_unit struct_specifier{
}
| translation_unit function_definition{
}
;

struct_specifier: STRUCT IDENTIFIER '{' declaration_list '}' ';'{
};

function_definition: type_specifier fun_declarator compound_statement{
};

type_specifier: VOID{
}
| INT{
}
| FLOAT{
}
| STRUCT IDENTIFIER{
}
;

fun_declarator: IDENTIFIER '(' parameter_list ')'{
}
| IDENTIFIER '(' ')'{
}
;

parameter_list: parameter_declaration{
}
| parameter_list ',' parameter_declaration{
}
;

parameter_declaration: type_specifier declarator{
}
;

declarator_arr: IDENTIFIER{
}
| declarator_arr '[' INT_CONSTANT ']'{
}
;

declarator: declarator_arr{
}
| '*' declarator{
}
;

compound_statement: '{' '}'{
}
| '{' statement_list '}'{
    $$ = $2;
}
| '{' declaration_list '}' {
}
| '{' declaration_list statement_list '}'{
    $$ = $3;
}
;

statement_list: statement{
    std::vector<statement_astnode*> temp;
    temp.push_back($1);
    $$ = temp;
}
| statement_list statement{
    $$ = $1.push_back($2);
}
;

statement: ';'{
}
| '{' statement_list '}'{
}
| selection_statement{
}
| iteration_statement{
}
| assignment_statement{
}
| procedure_call{
}
| RETURN expression ';'{
}
;

assignment_expression: unary_expression '=' expression{
}
;

assignment_statement: assignment_expression ';'{
}
;

procedure_call: IDENTIFIER '(' ')' ';'{
}
| IDENTIFIER '(' expression_list ')' ';'{
}
;

expression: logical_and_expression{
}
| expression OR_OP logical_and_expression{
}
;

logical_and_expression: equality_expression{
}
| logical_and_expression AND_OP equality_expression{
}
;

equality_expression: relational_expression{
}
| equality_expression EQ_OP relational_expression {
    $$ = new op_binary_astnode("EQ?", $1, $3);
}
| equality_expression NE_OP relational_expression{
    $$ = new op_binary_astnode("NE?", $1, $3);
}
;

relational_expression: additive_expression{
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
}
| additive_expression '+' multiplicative_expression{
    $$ = new op_binary_astnode("PLUS?", $1, $3);
}
| additive_expression '-' multiplicative_expression{
    $$ = new op_binary_astnode("MINUS?", $1, $3);
}
;

unary_expression: postfix_expression{
}
| unary_operator unary_expression{
    $$ = new op_unary_astnode($1, $2);
}
;

multiplicative_expression: unary_expression{
}
| multiplicative_expression '*' unary_expression{
    $$ = new op_binary_astnode("MULT?", $1, $3);
}
| multiplicative_expression '/' unary_expression{
    $$ = new op_binary_astnode("DIV?", $1, $3);
}
;

postfix_expression: primary_expression{
}
| postfix_expression '[' expression ']'{
}
| IDENTIFIER '(' ')'{
}
| IDENTIFIER '(' expression_list ')'{
}
| postfix_expression '.' IDENTIFIER{
}
| postfix_expression PTR_OP IDENTIFIER{
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
}
;

iteration_statement: WHILE '(' expression ')' statement{
}
| FOR '(' assignment_expression ';' expression ';' assignment_expression ')' statement{
}
;

declaration_list: declaration{
}
| declaration_list declaration{
}
;

declaration: type_specifier declarator_list ';'{
}
;

declarator_list: declarator{
}
| declarator_list ',' declarator{
}
;

%%
//grammar definition.
void IPL::Parser::error( const location_type &l, const std::string &err_message )
{
   std::cerr << "Error: " << err_message << " at " << l << "\n";
}

%skeleton "lalr1.cc"
%require  "3.0.1"

%defines 
%define api.namespace {IPL}
%define api.parser.class {Parser}

%define parse.trace

%code requires{
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
   int nodeCount = 0;

#undef yylex
#define yylex IPL::Parser::scanner.yylex

std::string stringify(std::string s)
{
    char c;
    unsigned int i = 0;
    while (i < s.length()) {
        c = s[i];
        if (c == '\\') {
            s = s.substr(0, i) + '\\' + s.substr(i,s.length() - i);
            i += 2;
        }
        else if (c == '\"') {
            s = s.substr(0, i) + '\\' + s.substr(i,s.length() - i);
            i += 2;
        }
        else {
            i++;
        }
    }
    return s;
}
#define SHLBL(NN,NT) std::cout<< NN <<"[label=\""<<#NT<<"\"]\n"
#define SHLX(NN,T) std::cout<< NN <<"[label=\" "<<T<<" \"]\n"
#define SHCN(N1,N2) std::cout << N1 << " -> " << N2 << "\n"
}




%define api.value.type variant
%define parse.assert

%start translation_unit



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

%nterm <int> translation_unit struct_specifier function_definition type_specifier fun_declarator parameter_list parameter_declaration declarator_arr declarator compound_statement statement_list statement assignment_expression assignment_statement procedure_call expression logical_and_expression equality_expression relational_expression additive_expression unary_expression multiplicative_expression postfix_expression primary_expression expression_list unary_operator selection_statement iteration_statement declaration_list declaration declarator_list 
%%
translation_unit: 
struct_specifier{
   $$ = ++nodeCount;
   SHLBL($$,translation_unit);
   SHCN($$,$1);
}
| function_definition{
   $$ = ++nodeCount;
   SHLBL($$,translation_unit);
   SHCN($$,$1);
}
| translation_unit struct_specifier{
   $$ = ++nodeCount;
   SHLBL($$,translation_unit);
   SHCN($$,$1);
   SHCN($$,$2);
}
| translation_unit function_definition{
   $$ = ++nodeCount;
   SHLBL($$,translation_unit);
   SHCN($$,$1);
   SHCN($$,$2);
}
;
struct_specifier: STRUCT IDENTIFIER '{' declaration_list '}' ';'{
   $$ = ++nodeCount;
   SHLBL($$,struct_specifier);
   SHLX(++nodeCount,$1);
   SHCN($$,nodeCount);
   SHLX(++nodeCount,$2);
   SHCN($$,nodeCount);
   SHLX(++nodeCount,"{");
   SHCN($$,nodeCount);
   SHCN($$,$4);
   SHLX(++nodeCount,"}");
   SHCN($$,nodeCount);
   SHLX(++nodeCount,";");
   SHCN($$,nodeCount);
};

function_definition: type_specifier fun_declarator compound_statement{
   $$ = ++nodeCount;
   SHLBL($$,function_definition);
   SHCN($$,$1);
   SHCN($$,$2);
   SHCN($$,$3);

};
type_specifier: VOID{
   $$ = ++nodeCount;
   SHLBL($$,type_specifier);
   SHLX(++nodeCount,$1);
   SHCN($$,nodeCount);
}
              | INT{
                  $$ = ++nodeCount;
                  SHLBL($$,type_specifier);
                  SHLX(++nodeCount,$1);
                  SHCN($$,nodeCount);
              }
              | FLOAT{
                  $$ = ++nodeCount;
                  SHLBL($$,type_specifier);
                  SHLX(++nodeCount,$1);
                  SHCN($$,nodeCount);
              }
              | STRUCT IDENTIFIER{
                  $$ = ++nodeCount;
                  SHLBL($$,type_specifier);
                  SHLX(++nodeCount,$1);
                  SHCN($$,nodeCount);
                  SHLX(++nodeCount,$2);
                  SHCN($$,nodeCount);
              }
;
fun_declarator: IDENTIFIER '(' parameter_list ')'{
      $$ = ++nodeCount;
      SHLBL($$,fun_declarator);
      SHLX(++nodeCount,$1);
      SHCN($$,nodeCount);
      SHLX(++nodeCount,"(");
      SHCN($$,nodeCount);
      SHCN($$,$3);
      SHLX(++nodeCount,")");
      SHCN($$,nodeCount);
}
              | IDENTIFIER '(' ')'{
               $$ = ++nodeCount;
               SHLBL($$,fun_declarator);
               SHLX(++nodeCount,$1);
               SHCN($$,nodeCount);
               SHLX(++nodeCount,"(");
               SHCN($$,nodeCount);
               SHLX(++nodeCount,")");
               SHCN($$,nodeCount);
              }
;
parameter_list: parameter_declaration{
      $$ = ++nodeCount;
      SHLBL($$,parameter_list);
      SHCN($$,$1);
}
| parameter_list ',' parameter_declaration{
$$ = ++nodeCount;
SHLBL($$,parameter_list);
SHCN($$,$1);
SHLX(++nodeCount,",");
SHCN($$,nodeCount);
SHCN($$,$3);
}
;
parameter_declaration: type_specifier declarator{
   $$ = ++nodeCount;
   SHLBL($$,parameter_declaration);
   SHCN($$,$1);
   SHCN($$,$2);
}
;
declarator_arr: IDENTIFIER{
      $$ = ++nodeCount;
      SHLBL($$,declarator_arr);
      SHLX(++nodeCount,$1);
      SHCN($$,nodeCount);
}
| declarator_arr '[' INT_CONSTANT ']'{
      $$ = ++nodeCount;
      SHLBL($$,declarator_arr);
      SHCN($$,$1);
      SHLX(++nodeCount,"[");
      SHCN($$,nodeCount);
      SHLX(++nodeCount,$3);
      SHCN($$,nodeCount);
      SHLX(++nodeCount,"]");
      SHCN($$,nodeCount);
}
;
declarator: declarator_arr{
      $$ = ++nodeCount;
      SHLBL($$,declarator);
      SHCN($$,$1);
}
          | '*' declarator{
      $$ = ++nodeCount;
      SHLBL($$,declarator);
      SHLX(++nodeCount,"*");
      SHCN($$,nodeCount);
      SHCN($$,$2);      
}
;
compound_statement: '{' '}'{
      $$ = ++nodeCount;
      SHLBL($$,compound_statement);
      SHLX(++nodeCount,"{");
      SHCN($$,nodeCount);
      SHLX(++nodeCount,"}");
      SHCN($$,nodeCount);
}
| '{' statement_list '}'{
   $$ = ++nodeCount;
   SHLBL($$,compound_statement);
   SHLX(++nodeCount,"{");
   SHCN($$,nodeCount);
   SHCN($$,$2);
   SHLX(++nodeCount,"}");   
   SHCN($$,nodeCount);
}
| '{' declaration_list statement_list '}'{
      $$ = ++nodeCount;
      SHLBL($$,compound_statement);
      SHLX(++nodeCount,"{");
      SHCN($$,nodeCount);
      SHCN($$,$2);
      SHCN($$,$3);
      SHLX(++nodeCount,"}");
      SHCN($$,nodeCount);
}
;
statement_list: statement{
      $$ = ++nodeCount;
      SHLBL($$,statement_list);
      SHCN($$,$1);
}
| statement_list statement{
      $$ = ++nodeCount;
      SHLBL($$,statement_list);
      SHCN($$,$1);
      SHCN($$,$2);
}
;
statement: ';'{
   $$ = ++nodeCount;
   SHLBL($$,statement);
   SHLX(++nodeCount,";");
   SHCN($$,nodeCount);
}
          | '{' statement_list '}'{
            $$ = ++nodeCount;
            SHLBL($$,statement);
            SHLX(++nodeCount,"{");
            SHCN($$,nodeCount);
            SHCN($$,$2);
            SHLX(++nodeCount,"}");
            SHCN($$,nodeCount);
          }
          | selection_statement{
               $$ = ++nodeCount;
               SHLBL($$,statement);
               SHCN($$,$1);
          }
          | iteration_statement{
               $$ = ++nodeCount;
               SHLBL($$,statement);
               SHCN($$,$1);
          }
          | assignment_statement{
               $$ = ++nodeCount;
               SHLBL($$,statement);
               SHCN($$,$1);
          }
          | procedure_call{
               $$ = ++nodeCount;
               SHLBL($$,statement);
               SHCN($$,$1);
          }
          | RETURN expression ';'{
               $$ = ++nodeCount;
               SHLBL($$,statement);
               SHLX(++nodeCount,$1);
               SHCN($$,nodeCount);
               SHCN($$,$2);
               SHLX(++nodeCount,";");
               SHCN($$,nodeCount);
          }
;
assignment_expression: unary_expression '=' expression{
      $$ = ++nodeCount;
      SHLBL($$,assignment_expression);
   SHCN($$,$1);
   SHLX(++nodeCount,"=");
   SHCN($$,nodeCount);
   SHCN($$,$3);
}
;
assignment_statement: assignment_expression ';'{
      $$ = ++nodeCount;
      SHLBL($$,assignment_statement);
      SHCN($$,$1);
      SHLX(++nodeCount,";");
      SHCN($$,nodeCount);
}
;
procedure_call: IDENTIFIER '(' ')' ';'{
   $$ = ++nodeCount;
   SHLBL($$,procedure_call);
   SHLX(++nodeCount,$1);
   SHCN($$,nodeCount);
   SHLX(++nodeCount,"(");
   SHCN($$,nodeCount);
   SHLX(++nodeCount,")");
   SHCN($$,nodeCount);
   SHLX(++nodeCount,";");
   SHCN($$,nodeCount);
}
              | IDENTIFIER '(' expression_list ')' ';'{
                  $$ = ++nodeCount;
                  SHLBL($$,procedure_call);
                  SHLX(++nodeCount,$1);
                  SHCN($$,nodeCount);
                  SHLX(++nodeCount,"(");
                  SHCN($$,nodeCount);
                  SHCN($$,$3);
                  SHLX(++nodeCount,")");
                  SHCN($$,nodeCount);
                  SHLX(++nodeCount,";");
                  SHCN($$,nodeCount);
              }
;
expression: logical_and_expression{
      $$ = ++nodeCount;
      SHLBL($$,expression);
      SHCN($$,$1);
}
          | expression OR_OP logical_and_expression{
               $$ = ++nodeCount;
               SHLBL($$,expression);
               SHCN($$,$1);
               SHLX(++nodeCount,$2);
               SHCN($$,nodeCount);
               SHCN($$,$3);
          }
;
logical_and_expression: equality_expression{
      $$ = ++nodeCount;
      SHLBL($$,logical_and_expression);
      SHCN($$,$1);
}
                      | logical_and_expression AND_OP equality_expression{
                           $$ = ++nodeCount;
                           SHLBL($$,logical_and_expression);
                           SHCN($$,$1);
                           SHLX(++nodeCount,$2);
                           SHCN($$,nodeCount);
                           SHCN($$,$3);
                      }
;
equality_expression: relational_expression{
      $$ = ++nodeCount;
      SHLBL($$,equality_expression);
      SHCN($$,$1);
}
| equality_expression EQ_OP relational_expression{
      $$ = ++nodeCount;
      SHLBL($$,equality_expression);
      SHCN($$,$1);
      SHLX(++nodeCount,$2);
      SHCN($$,nodeCount);
      SHCN($$,$3);
}
| equality_expression NE_OP relational_expression{
         $$ = ++nodeCount;
      SHLBL($$,equality_expression);
      SHCN($$,$1);
      SHLX(++nodeCount,$2);
      SHCN($$,nodeCount);
      SHCN($$,$3);
}
;
relational_expression: additive_expression{
      $$ = ++nodeCount;
      SHLBL($$,relational_expression);
      SHCN($$,$1);
}
                      | relational_expression '<' additive_expression{
                           $$ = ++nodeCount;
                           SHLBL($$,relational_expression);
                           SHCN($$,$1);
                           SHLX(++nodeCount,"<");
                           SHCN($$,nodeCount);
                           SHCN($$,$3);
                      }
                      | relational_expression '>' additive_expression{
                           $$ = ++nodeCount;
                           SHLBL($$,relational_expression);
                           SHCN($$,$1);
                           SHLX(++nodeCount,">");
                           SHCN($$,nodeCount);
                           SHCN($$,$3);
                      }
                      | relational_expression LE_OP additive_expression{
                           $$ = ++nodeCount;
                           SHLBL($$,relational_expression);
                           SHCN($$,$1);
                           SHLX(++nodeCount,$2);
                           SHCN($$,nodeCount);
                           SHCN($$,$3);
                      }
                      | relational_expression GE_OP additive_expression{
                           $$ = ++nodeCount;
                           SHLBL($$,relational_expression);
                           SHCN($$,$1);
                           SHLX(++nodeCount,$2);
                           SHCN($$,nodeCount);
                           SHCN($$,$3);
                      }
;
additive_expression: multiplicative_expression{
      $$ = ++nodeCount;
      SHLBL($$,additive_expression);
      SHCN($$,$1);
}
                    | additive_expression '+' multiplicative_expression{
                        $$ = ++nodeCount;
                        SHLBL($$,additive_expression);
                        SHCN($$,$1);
                        SHLX(++nodeCount,"+");
                        SHCN($$,nodeCount);
                        SHCN($$,$3);
                    }
                    | additive_expression '-' multiplicative_expression{
                        $$ = ++nodeCount;
                        SHLBL($$,additive_expression);
                        SHCN($$,$1);
                        SHLX(++nodeCount,"-");
                        SHCN($$,nodeCount);
                        SHCN($$,$3);
                    }
;
unary_expression: postfix_expression{
      $$ = ++nodeCount;
      SHLBL($$,unary_expression);
      SHCN($$,$1);
}
| unary_operator unary_expression{
      $$ = ++nodeCount;
      SHLBL($$,unary_expression);
      SHCN($$,$1);
      SHCN($$,$2);
}
;
multiplicative_expression: unary_expression{
      $$ = ++nodeCount;
      SHLBL($$,multiplicative_expression);
      SHCN($$,$1);
}
| multiplicative_expression '*' unary_expression{
      $$ = ++nodeCount;
      SHLBL($$,multiplicative_expression);
      SHCN($$,$1);
      SHLX(++nodeCount,"*");
      SHCN($$,nodeCount);
      SHCN($$,$3);
}
| multiplicative_expression '/' unary_expression{
      $$ = ++nodeCount;
      SHLBL($$,multiplicative_expression);
      SHCN($$,$1);
      SHLX(++nodeCount,"/");
      SHCN($$,nodeCount);
      SHCN($$,$3);
}
;
postfix_expression: primary_expression{
      $$ = ++nodeCount;
      SHLBL($$,postfix_expression);
      SHCN($$,$1);
}
                  | postfix_expression '[' expression ']'{
                        $$ = ++nodeCount;
                        SHLBL($$,postfix_expression);
                        SHCN($$,$1);
                        SHLX(++nodeCount,"[");
                        SHCN($$,nodeCount);
                        SHCN($$,$3);
                        SHLX(++nodeCount,"]");
                        SHCN($$,nodeCount);
                  }
                  | IDENTIFIER '(' ')'{
                        $$ = ++nodeCount;
                        SHLBL($$,postfix_expression);
                        SHLX(++nodeCount,$1);
                        SHCN($$,nodeCount);
                        SHLX(++nodeCount,"(");
                        SHCN($$,nodeCount);
                        SHLX(++nodeCount,")");
                        SHCN($$,nodeCount);
                  }
                  | IDENTIFIER '(' expression_list ')'{
                        $$ = ++nodeCount;
                        SHLBL($$,postfix_expression);
                        SHLX(++nodeCount,$1);
                        SHCN($$,nodeCount);
                        SHLX(++nodeCount,"(");
                        SHCN($$,nodeCount);
                        SHCN($$,$3);
                        SHLX(++nodeCount,")");
                        SHCN($$,nodeCount);
                  }
                  | postfix_expression '.' IDENTIFIER{
                        $$ = ++nodeCount;
                        SHLBL($$,postfix_expression);
                        SHCN($$,$1);
                        SHLX(++nodeCount,".");
                        SHCN($$,nodeCount);
                        SHLX(++nodeCount,$3);
                        SHCN($$,nodeCount);
                  }
                  | postfix_expression PTR_OP IDENTIFIER{
                        $$ = ++nodeCount;
                        SHLBL($$,postfix_expression);
                        SHCN($$,$1);
                        SHLX(++nodeCount,$2);
                        SHCN($$,nodeCount);
                        SHLX(++nodeCount,$3);
                        SHCN($$,nodeCount);
                  }
                  | postfix_expression INC_OP{
                        $$ = ++nodeCount;
                        SHLBL($$,postfix_expression);
                        SHCN($$,$1);
                        SHLX(++nodeCount,$2);
                        SHCN($$,nodeCount);
                  }
;
primary_expression: IDENTIFIER{
      $$ = ++nodeCount;
      SHLBL($$,primary_expression);
      SHLX(++nodeCount,$1);
      SHCN($$,nodeCount);
}
                  | INT_CONSTANT{
                        $$ = ++nodeCount;
                        SHLBL($$,primary_expression);
                        SHLX(++nodeCount,$1);
                        SHCN($$,nodeCount);
                  }
                  | FLOAT_CONSTANT{
                        $$ = ++nodeCount;
                        SHLBL($$,primary_expression);
                        SHLX(++nodeCount,$1);
                        SHCN($$,nodeCount);
                  }
                  | STRING_LITERAL{
                        $$ = ++nodeCount;
                        SHLBL($$,primary_expression);
                        std::cout << ++nodeCount << "[label=\"\\\"\"+" << $1 << "+\"\\\"\"]\n";
                        SHCN($$,nodeCount);
                  }
                  | '(' expression ')'{
                        $$ = ++nodeCount;
                        SHLBL($$,primary_expression);
                        SHLX(++nodeCount,"(");
                        SHCN($$,nodeCount);
                        SHCN($$,$2);
                        SHLX(++nodeCount,")");
                        SHCN($$,nodeCount);

                  }
;
expression_list: expression{
      $$ = ++nodeCount;
      SHLBL($$,expression_list);
      SHCN($$,$1);
}
                | expression_list ',' expression{
                     $$ = ++nodeCount;
                     SHLBL($$,expression_list);
                     SHCN($$,$1);
                     SHLX(++nodeCount,",");
                     SHCN($$,nodeCount);
                     SHCN($$,$3);
                }
;
unary_operator: '-'{
      $$ = ++nodeCount;
      SHLBL($$,unary_operator);
      SHLX(++nodeCount,"-");
      SHCN($$,nodeCount);
}
              | '!'{
                  $$ = ++nodeCount;
                  SHLBL($$,unary_operator);
                  SHLX(++nodeCount,"!");
                  SHCN($$,nodeCount);
              }
              | '&'{
                  $$ = ++nodeCount;
                  SHLBL($$,unary_operator);
                  SHLX(++nodeCount,"&");
                  SHCN($$,nodeCount);
              }
              | '*'{
                  $$ = ++nodeCount;
                  SHLBL($$,unary_operator);
                  SHLX(++nodeCount,"*");
                  SHCN($$,nodeCount);
              }
;
selection_statement: IF '(' expression ')' statement ELSE statement{
      $$ = ++nodeCount;
      SHLBL($$,selection_statement);
      SHLX(++nodeCount,$1);
      SHCN($$,nodeCount);
      SHLX(++nodeCount,"(");
      SHCN($$,nodeCount);
      SHCN($$,$3);
      SHLX(++nodeCount,")");
      SHCN($$,nodeCount);
      SHCN($$,$5);
      SHLX(++nodeCount,$6);
      SHCN($$,nodeCount);
      SHCN($$,$7);
}
;
iteration_statement: WHILE '(' expression ')' statement{
      $$ = ++nodeCount;
      SHLBL($$,iteration_statement);
      SHLX(++nodeCount,$1);
      SHCN($$,nodeCount);
      SHLX(++nodeCount,"(");
      SHCN($$,nodeCount);
      SHCN($$,$3);
      SHLX(++nodeCount,")");
      SHCN($$,nodeCount);
      SHCN($$,$5);
}
| FOR '(' assignment_expression ';' expression ';' assignment_expression ')' statement{
      $$ = ++nodeCount;
      SHLBL($$,iteration_statement);
      SHLX(++nodeCount,$1);
      SHCN($$,nodeCount);
      SHLX(++nodeCount,"(");
      SHCN($$,nodeCount);
      SHCN($$,$3);
      SHLX(++nodeCount,";");
      SHCN($$,nodeCount);
      SHCN($$,$5);
      SHLX(++nodeCount,";");
      SHCN($$,nodeCount);
      SHCN($$,$7);
      SHLX(++nodeCount,")");
      SHCN($$,nodeCount);
      SHCN($$,$9);
}
;
declaration_list: declaration{
      $$ = ++nodeCount;
      SHLBL($$,declaration_list);
      SHCN($$,$1);
}
                | declaration_list declaration{
                     $$ = ++nodeCount;
                     SHLBL($$,declaration_list);
                     SHCN($$,$1);
                     SHCN($$,$2);
                }
;
declaration: type_specifier declarator_list ';'{
      $$ = ++nodeCount;
      SHLBL($$,declaration);
      SHCN($$,$1);
      SHCN($$,$2);
      SHLX(++nodeCount,";");
      SHCN($$,nodeCount);
}
;
declarator_list: declarator{
      $$ = ++nodeCount;
      SHLBL($$,declarator_list);
      SHCN($$,$1);
}
                | declarator_list ',' declarator{
                     $$ = ++nodeCount;
                     SHLBL($$,declarator_list);
                     SHCN($$,$1);
                     SHLX(++nodeCount,",");
                     SHCN($$,nodeCount);
                     SHCN($$,$3);
                }
;

%%
//grammar definition.
void IPL::Parser::error( const location_type &l, const std::string &err_message )
{
   std::cerr << "Error: " << err_message << " at " << l << "\n";
}

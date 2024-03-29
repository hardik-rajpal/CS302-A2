%{

#include "scanner.hh"
#include "parser.tab.hh"
// #include <fstream>
// #include <string>
#undef  YY_DECL
#define YY_DECL int IPL::Scanner::yylex( IPL::Parser::semantic_type * const lval, IPL::Parser::location_type *location )

//We want these to be the first action after a token is recognized. 

#define YY_USER_ACTION loc->step(); loc->columns();

// token_type is a short hand for IPL::Parser::token

using token_type = IPL::Parser::token;

%}

/* %option debug */
%option nodefault
%option yyclass="Scanner"
%option noyywrap
%option c++

%% 

%{  /** Code executed at the beginning of yylex **/
    yylval = lval;
    loc = location;
%}

[ \t\r]                                                   {}
[\n]                                                  loc->lines();
[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/]                       {}
void {
  yylval->emplace< std::string >( YYText() );
  return token_type::VOID;
}
int {
  yylval->emplace< std::string >( YYText() );
  return token_type::INT;
}
float {
  yylval->emplace< std::string >( YYText() );
  return token_type::FLOAT;
}
struct {
  yylval->emplace< std::string >( YYText() );
  return token_type::STRUCT;
}
if {
  yylval->emplace< std::string >( YYText() );
  return token_type::IF;
}
else {
  yylval->emplace< std::string >( YYText() );
  return token_type::ELSE;
}
while {
  yylval->emplace< std::string >( YYText() );
  return token_type::WHILE;
}
main {
  yylval->emplace< std::string >( YYText() );
  return token_type::MAIN;
}
printf {
  yylval->emplace< std::string >( YYText() );
  return token_type::PRINTF;
}
for {
  yylval->emplace< std::string >( YYText() );
  return token_type::FOR;
}
return {
  yylval->emplace< std::string >( YYText() );
  return token_type::RETURN;
}
"||" {
  yylval->emplace< std::string >( YYText() );
  return token_type::OR_OP;
}
"&&" {
  yylval->emplace< std::string >( YYText() );
  return token_type::AND_OP;
}
"==" {
  yylval->emplace< std::string >( YYText() );
  return token_type::EQ_OP;
}
"!=" {
  yylval->emplace< std::string >( YYText() );
  return token_type::NE_OP;
}
"<=" {
  yylval->emplace< std::string >( YYText() );
  return token_type::LE_OP;
}
">=" {
  yylval->emplace< std::string >( YYText() );
  return token_type::GE_OP;
}
("++") {
  yylval->emplace< std::string >( YYText() );
  return token_type::INC_OP;
}
"->" {
  yylval->emplace< std::string >( YYText() );
  return token_type::PTR_OP;
}
"="                                                     return '=';
"+"                                                     return '+';
"-"                                                     return '-';
"*"                                                     return '*';
"/"                                                     return '/';
"("                                                     return '(';
")"                                                     return ')';
","                                                     return ',';
"{"                                                     return '{';
"}"                                                     return '}';
"["                                                     return '[';
"]"                                                     return ']';
"!"                                                     return '!';
"&"                                                     return '&';
"<"                                                     return '<';
">"                                                     return '>';
";"                                                     return ';';
"."                                                     return '.';
\"((\\\"|\\\\|\\n|\\t)|[^\\\"])*\" {
  yylval->emplace< std::string >( YYText() );
  return token_type::STRING_LITERAL;
}
(0|[1-9][0-9]*|0[bB][01]+|0[0-7]+|0[xX][0-9a-fA-F]*) {
  yylval->emplace< std::string >( YYText() );
  return token_type::INT_CONSTANT;
}
([0-9]*\.[0-9]+|[0-9]+\.[0-9]*)([eE][+-]?[0-9]+)? {
  yylval->emplace< std::string >( YYText() );
  return token_type::FLOAT_CONSTANT;
}
[a-zA-Z_][a-zA-Z0-9_]* {
  yylval->emplace< std::string >( YYText() );
  return token_type::IDENTIFIER;
}
.                                                       return token_type::OTHERS;
<<EOF>>                                                 yyterminate();
%%

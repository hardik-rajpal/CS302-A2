// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.tab.hh"


// Unqualified %code blocks.
#line 49 "parser.yy"

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

#line 67 "parser.tab.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 5 "parser.yy"
namespace IPL {
#line 160 "parser.tab.cc"

  /// Build a parser object.
  Parser::Parser (Scanner  &scanner_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->kind ())
    {
      case symbol_kind::S_struct_specifier: // struct_specifier
      case symbol_kind::S_declaration_list: // declaration_list
        value.copy< abstract_astnode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_assignment_expression: // assignment_expression
        value.copy< assignE_astnode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression: // expression
      case symbol_kind::S_unary_expression: // unary_expression
      case symbol_kind::S_postfix_expression: // postfix_expression
      case symbol_kind::S_primary_expression: // primary_expression
        value.copy< exp_astnode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_printf_call: // printf_call
      case symbol_kind::S_procedure_call: // procedure_call
        value.copy< funcall_astnode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_fun_declarator: // fun_declarator
        value.copy< fundeclarator_astnode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_mnterm: // mnterm
        value.copy< mnt* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ifgotocoder: // ifgotocoder
      case symbol_kind::S_logical_and_expression: // logical_and_expression
      case symbol_kind::S_equality_expression: // equality_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
        value.copy< op_binary_astnode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_main_definition: // main_definition
      case symbol_kind::S_function_definition: // function_definition
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_assignment_statement: // assignment_statement
      case symbol_kind::S_selection_statement: // selection_statement
      case symbol_kind::S_iteration_statement: // iteration_statement
        value.copy< statement_astnode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_STRUCT: // STRUCT
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_INT_CONSTANT: // INT_CONSTANT
      case symbol_kind::S_FLOAT_CONSTANT: // FLOAT_CONSTANT
      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
      case symbol_kind::S_OR_OP: // OR_OP
      case symbol_kind::S_AND_OP: // AND_OP
      case symbol_kind::S_EQ_OP: // EQ_OP
      case symbol_kind::S_NE_OP: // NE_OP
      case symbol_kind::S_LE_OP: // LE_OP
      case symbol_kind::S_GE_OP: // GE_OP
      case symbol_kind::S_INC_OP: // INC_OP
      case symbol_kind::S_PTR_OP: // PTR_OP
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_PRINTF: // PRINTF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_OTHERS: // OTHERS
      case symbol_kind::S_unary_operator: // unary_operator
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_begin_nterm: // begin_nterm
      case symbol_kind::S_program: // program
      case symbol_kind::S_translation_unit: // translation_unit
        value.copy< std::vector<abstract_astnode*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression_list: // expression_list
        value.copy< std::vector<exp_astnode*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_compound_statement: // compound_statement
      case symbol_kind::S_statement_list: // statement_list
        value.copy< std::vector<statement_astnode*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter_list: // parameter_list
        value.copy< std::vector<typespec_astnode> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type_specifier: // type_specifier
      case symbol_kind::S_parameter_declaration: // parameter_declaration
      case symbol_kind::S_declarator_arr: // declarator_arr
      case symbol_kind::S_declarator: // declarator
      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_declarator_list: // declarator_list
        value.copy< typespec_astnode > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  Parser::symbol_kind_type
  Parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_struct_specifier: // struct_specifier
      case symbol_kind::S_declaration_list: // declaration_list
        value.move< abstract_astnode* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_assignment_expression: // assignment_expression
        value.move< assignE_astnode* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_expression: // expression
      case symbol_kind::S_unary_expression: // unary_expression
      case symbol_kind::S_postfix_expression: // postfix_expression
      case symbol_kind::S_primary_expression: // primary_expression
        value.move< exp_astnode* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_printf_call: // printf_call
      case symbol_kind::S_procedure_call: // procedure_call
        value.move< funcall_astnode* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_fun_declarator: // fun_declarator
        value.move< fundeclarator_astnode* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_mnterm: // mnterm
        value.move< mnt* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_ifgotocoder: // ifgotocoder
      case symbol_kind::S_logical_and_expression: // logical_and_expression
      case symbol_kind::S_equality_expression: // equality_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
        value.move< op_binary_astnode* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_main_definition: // main_definition
      case symbol_kind::S_function_definition: // function_definition
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_assignment_statement: // assignment_statement
      case symbol_kind::S_selection_statement: // selection_statement
      case symbol_kind::S_iteration_statement: // iteration_statement
        value.move< statement_astnode* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_STRUCT: // STRUCT
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_INT_CONSTANT: // INT_CONSTANT
      case symbol_kind::S_FLOAT_CONSTANT: // FLOAT_CONSTANT
      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
      case symbol_kind::S_OR_OP: // OR_OP
      case symbol_kind::S_AND_OP: // AND_OP
      case symbol_kind::S_EQ_OP: // EQ_OP
      case symbol_kind::S_NE_OP: // NE_OP
      case symbol_kind::S_LE_OP: // LE_OP
      case symbol_kind::S_GE_OP: // GE_OP
      case symbol_kind::S_INC_OP: // INC_OP
      case symbol_kind::S_PTR_OP: // PTR_OP
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_PRINTF: // PRINTF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_OTHERS: // OTHERS
      case symbol_kind::S_unary_operator: // unary_operator
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_begin_nterm: // begin_nterm
      case symbol_kind::S_program: // program
      case symbol_kind::S_translation_unit: // translation_unit
        value.move< std::vector<abstract_astnode*> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_expression_list: // expression_list
        value.move< std::vector<exp_astnode*> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_compound_statement: // compound_statement
      case symbol_kind::S_statement_list: // statement_list
        value.move< std::vector<statement_astnode*> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_parameter_list: // parameter_list
        value.move< std::vector<typespec_astnode> > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_type_specifier: // type_specifier
      case symbol_kind::S_parameter_declaration: // parameter_declaration
      case symbol_kind::S_declarator_arr: // declarator_arr
      case symbol_kind::S_declarator: // declarator
      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_declarator_list: // declarator_list
        value.move< typespec_astnode > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_kind.
  Parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  Parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  Parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  Parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  Parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  Parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  Parser::symbol_kind_type
  Parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  Parser::symbol_kind_type
  Parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_kind_type
  Parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_struct_specifier: // struct_specifier
      case symbol_kind::S_declaration_list: // declaration_list
        value.YY_MOVE_OR_COPY< abstract_astnode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_assignment_expression: // assignment_expression
        value.YY_MOVE_OR_COPY< assignE_astnode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression: // expression
      case symbol_kind::S_unary_expression: // unary_expression
      case symbol_kind::S_postfix_expression: // postfix_expression
      case symbol_kind::S_primary_expression: // primary_expression
        value.YY_MOVE_OR_COPY< exp_astnode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_printf_call: // printf_call
      case symbol_kind::S_procedure_call: // procedure_call
        value.YY_MOVE_OR_COPY< funcall_astnode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_fun_declarator: // fun_declarator
        value.YY_MOVE_OR_COPY< fundeclarator_astnode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_mnterm: // mnterm
        value.YY_MOVE_OR_COPY< mnt* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ifgotocoder: // ifgotocoder
      case symbol_kind::S_logical_and_expression: // logical_and_expression
      case symbol_kind::S_equality_expression: // equality_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
        value.YY_MOVE_OR_COPY< op_binary_astnode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_main_definition: // main_definition
      case symbol_kind::S_function_definition: // function_definition
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_assignment_statement: // assignment_statement
      case symbol_kind::S_selection_statement: // selection_statement
      case symbol_kind::S_iteration_statement: // iteration_statement
        value.YY_MOVE_OR_COPY< statement_astnode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_STRUCT: // STRUCT
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_INT_CONSTANT: // INT_CONSTANT
      case symbol_kind::S_FLOAT_CONSTANT: // FLOAT_CONSTANT
      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
      case symbol_kind::S_OR_OP: // OR_OP
      case symbol_kind::S_AND_OP: // AND_OP
      case symbol_kind::S_EQ_OP: // EQ_OP
      case symbol_kind::S_NE_OP: // NE_OP
      case symbol_kind::S_LE_OP: // LE_OP
      case symbol_kind::S_GE_OP: // GE_OP
      case symbol_kind::S_INC_OP: // INC_OP
      case symbol_kind::S_PTR_OP: // PTR_OP
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_PRINTF: // PRINTF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_OTHERS: // OTHERS
      case symbol_kind::S_unary_operator: // unary_operator
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_begin_nterm: // begin_nterm
      case symbol_kind::S_program: // program
      case symbol_kind::S_translation_unit: // translation_unit
        value.YY_MOVE_OR_COPY< std::vector<abstract_astnode*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression_list: // expression_list
        value.YY_MOVE_OR_COPY< std::vector<exp_astnode*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_compound_statement: // compound_statement
      case symbol_kind::S_statement_list: // statement_list
        value.YY_MOVE_OR_COPY< std::vector<statement_astnode*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter_list: // parameter_list
        value.YY_MOVE_OR_COPY< std::vector<typespec_astnode> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type_specifier: // type_specifier
      case symbol_kind::S_parameter_declaration: // parameter_declaration
      case symbol_kind::S_declarator_arr: // declarator_arr
      case symbol_kind::S_declarator: // declarator
      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_declarator_list: // declarator_list
        value.YY_MOVE_OR_COPY< typespec_astnode > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_struct_specifier: // struct_specifier
      case symbol_kind::S_declaration_list: // declaration_list
        value.move< abstract_astnode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_assignment_expression: // assignment_expression
        value.move< assignE_astnode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression: // expression
      case symbol_kind::S_unary_expression: // unary_expression
      case symbol_kind::S_postfix_expression: // postfix_expression
      case symbol_kind::S_primary_expression: // primary_expression
        value.move< exp_astnode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_printf_call: // printf_call
      case symbol_kind::S_procedure_call: // procedure_call
        value.move< funcall_astnode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_fun_declarator: // fun_declarator
        value.move< fundeclarator_astnode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_mnterm: // mnterm
        value.move< mnt* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_ifgotocoder: // ifgotocoder
      case symbol_kind::S_logical_and_expression: // logical_and_expression
      case symbol_kind::S_equality_expression: // equality_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
        value.move< op_binary_astnode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_main_definition: // main_definition
      case symbol_kind::S_function_definition: // function_definition
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_assignment_statement: // assignment_statement
      case symbol_kind::S_selection_statement: // selection_statement
      case symbol_kind::S_iteration_statement: // iteration_statement
        value.move< statement_astnode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_STRUCT: // STRUCT
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_INT_CONSTANT: // INT_CONSTANT
      case symbol_kind::S_FLOAT_CONSTANT: // FLOAT_CONSTANT
      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
      case symbol_kind::S_OR_OP: // OR_OP
      case symbol_kind::S_AND_OP: // AND_OP
      case symbol_kind::S_EQ_OP: // EQ_OP
      case symbol_kind::S_NE_OP: // NE_OP
      case symbol_kind::S_LE_OP: // LE_OP
      case symbol_kind::S_GE_OP: // GE_OP
      case symbol_kind::S_INC_OP: // INC_OP
      case symbol_kind::S_PTR_OP: // PTR_OP
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_PRINTF: // PRINTF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_OTHERS: // OTHERS
      case symbol_kind::S_unary_operator: // unary_operator
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_begin_nterm: // begin_nterm
      case symbol_kind::S_program: // program
      case symbol_kind::S_translation_unit: // translation_unit
        value.move< std::vector<abstract_astnode*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression_list: // expression_list
        value.move< std::vector<exp_astnode*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_compound_statement: // compound_statement
      case symbol_kind::S_statement_list: // statement_list
        value.move< std::vector<statement_astnode*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_parameter_list: // parameter_list
        value.move< std::vector<typespec_astnode> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_type_specifier: // type_specifier
      case symbol_kind::S_parameter_declaration: // parameter_declaration
      case symbol_kind::S_declarator_arr: // declarator_arr
      case symbol_kind::S_declarator: // declarator
      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_declarator_list: // declarator_list
        value.move< typespec_astnode > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_struct_specifier: // struct_specifier
      case symbol_kind::S_declaration_list: // declaration_list
        value.copy< abstract_astnode* > (that.value);
        break;

      case symbol_kind::S_assignment_expression: // assignment_expression
        value.copy< assignE_astnode* > (that.value);
        break;

      case symbol_kind::S_expression: // expression
      case symbol_kind::S_unary_expression: // unary_expression
      case symbol_kind::S_postfix_expression: // postfix_expression
      case symbol_kind::S_primary_expression: // primary_expression
        value.copy< exp_astnode* > (that.value);
        break;

      case symbol_kind::S_printf_call: // printf_call
      case symbol_kind::S_procedure_call: // procedure_call
        value.copy< funcall_astnode* > (that.value);
        break;

      case symbol_kind::S_fun_declarator: // fun_declarator
        value.copy< fundeclarator_astnode* > (that.value);
        break;

      case symbol_kind::S_mnterm: // mnterm
        value.copy< mnt* > (that.value);
        break;

      case symbol_kind::S_ifgotocoder: // ifgotocoder
      case symbol_kind::S_logical_and_expression: // logical_and_expression
      case symbol_kind::S_equality_expression: // equality_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
        value.copy< op_binary_astnode* > (that.value);
        break;

      case symbol_kind::S_main_definition: // main_definition
      case symbol_kind::S_function_definition: // function_definition
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_assignment_statement: // assignment_statement
      case symbol_kind::S_selection_statement: // selection_statement
      case symbol_kind::S_iteration_statement: // iteration_statement
        value.copy< statement_astnode* > (that.value);
        break;

      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_STRUCT: // STRUCT
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_INT_CONSTANT: // INT_CONSTANT
      case symbol_kind::S_FLOAT_CONSTANT: // FLOAT_CONSTANT
      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
      case symbol_kind::S_OR_OP: // OR_OP
      case symbol_kind::S_AND_OP: // AND_OP
      case symbol_kind::S_EQ_OP: // EQ_OP
      case symbol_kind::S_NE_OP: // NE_OP
      case symbol_kind::S_LE_OP: // LE_OP
      case symbol_kind::S_GE_OP: // GE_OP
      case symbol_kind::S_INC_OP: // INC_OP
      case symbol_kind::S_PTR_OP: // PTR_OP
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_PRINTF: // PRINTF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_OTHERS: // OTHERS
      case symbol_kind::S_unary_operator: // unary_operator
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_begin_nterm: // begin_nterm
      case symbol_kind::S_program: // program
      case symbol_kind::S_translation_unit: // translation_unit
        value.copy< std::vector<abstract_astnode*> > (that.value);
        break;

      case symbol_kind::S_expression_list: // expression_list
        value.copy< std::vector<exp_astnode*> > (that.value);
        break;

      case symbol_kind::S_compound_statement: // compound_statement
      case symbol_kind::S_statement_list: // statement_list
        value.copy< std::vector<statement_astnode*> > (that.value);
        break;

      case symbol_kind::S_parameter_list: // parameter_list
        value.copy< std::vector<typespec_astnode> > (that.value);
        break;

      case symbol_kind::S_type_specifier: // type_specifier
      case symbol_kind::S_parameter_declaration: // parameter_declaration
      case symbol_kind::S_declarator_arr: // declarator_arr
      case symbol_kind::S_declarator: // declarator
      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_declarator_list: // declarator_list
        value.copy< typespec_astnode > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_struct_specifier: // struct_specifier
      case symbol_kind::S_declaration_list: // declaration_list
        value.move< abstract_astnode* > (that.value);
        break;

      case symbol_kind::S_assignment_expression: // assignment_expression
        value.move< assignE_astnode* > (that.value);
        break;

      case symbol_kind::S_expression: // expression
      case symbol_kind::S_unary_expression: // unary_expression
      case symbol_kind::S_postfix_expression: // postfix_expression
      case symbol_kind::S_primary_expression: // primary_expression
        value.move< exp_astnode* > (that.value);
        break;

      case symbol_kind::S_printf_call: // printf_call
      case symbol_kind::S_procedure_call: // procedure_call
        value.move< funcall_astnode* > (that.value);
        break;

      case symbol_kind::S_fun_declarator: // fun_declarator
        value.move< fundeclarator_astnode* > (that.value);
        break;

      case symbol_kind::S_mnterm: // mnterm
        value.move< mnt* > (that.value);
        break;

      case symbol_kind::S_ifgotocoder: // ifgotocoder
      case symbol_kind::S_logical_and_expression: // logical_and_expression
      case symbol_kind::S_equality_expression: // equality_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
        value.move< op_binary_astnode* > (that.value);
        break;

      case symbol_kind::S_main_definition: // main_definition
      case symbol_kind::S_function_definition: // function_definition
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_assignment_statement: // assignment_statement
      case symbol_kind::S_selection_statement: // selection_statement
      case symbol_kind::S_iteration_statement: // iteration_statement
        value.move< statement_astnode* > (that.value);
        break;

      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_STRUCT: // STRUCT
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_INT_CONSTANT: // INT_CONSTANT
      case symbol_kind::S_FLOAT_CONSTANT: // FLOAT_CONSTANT
      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
      case symbol_kind::S_OR_OP: // OR_OP
      case symbol_kind::S_AND_OP: // AND_OP
      case symbol_kind::S_EQ_OP: // EQ_OP
      case symbol_kind::S_NE_OP: // NE_OP
      case symbol_kind::S_LE_OP: // LE_OP
      case symbol_kind::S_GE_OP: // GE_OP
      case symbol_kind::S_INC_OP: // INC_OP
      case symbol_kind::S_PTR_OP: // PTR_OP
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_PRINTF: // PRINTF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_OTHERS: // OTHERS
      case symbol_kind::S_unary_operator: // unary_operator
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_begin_nterm: // begin_nterm
      case symbol_kind::S_program: // program
      case symbol_kind::S_translation_unit: // translation_unit
        value.move< std::vector<abstract_astnode*> > (that.value);
        break;

      case symbol_kind::S_expression_list: // expression_list
        value.move< std::vector<exp_astnode*> > (that.value);
        break;

      case symbol_kind::S_compound_statement: // compound_statement
      case symbol_kind::S_statement_list: // statement_list
        value.move< std::vector<statement_astnode*> > (that.value);
        break;

      case symbol_kind::S_parameter_list: // parameter_list
        value.move< std::vector<typespec_astnode> > (that.value);
        break;

      case symbol_kind::S_type_specifier: // type_specifier
      case symbol_kind::S_parameter_declaration: // parameter_declaration
      case symbol_kind::S_declarator_arr: // declarator_arr
      case symbol_kind::S_declarator: // declarator
      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_declarator_list: // declarator_list
        value.move< typespec_astnode > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        switch (yykind)
    {
      case symbol_kind::S_VOID: // VOID
#line 21 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1025 "parser.tab.cc"
        break;

      case symbol_kind::S_INT: // INT
#line 22 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1031 "parser.tab.cc"
        break;

      case symbol_kind::S_FLOAT: // FLOAT
#line 23 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1037 "parser.tab.cc"
        break;

      case symbol_kind::S_STRUCT: // STRUCT
#line 24 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1043 "parser.tab.cc"
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
#line 25 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1049 "parser.tab.cc"
        break;

      case symbol_kind::S_INT_CONSTANT: // INT_CONSTANT
#line 26 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1055 "parser.tab.cc"
        break;

      case symbol_kind::S_FLOAT_CONSTANT: // FLOAT_CONSTANT
#line 27 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1061 "parser.tab.cc"
        break;

      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
#line 28 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1067 "parser.tab.cc"
        break;

      case symbol_kind::S_OR_OP: // OR_OP
#line 29 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1073 "parser.tab.cc"
        break;

      case symbol_kind::S_AND_OP: // AND_OP
#line 30 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1079 "parser.tab.cc"
        break;

      case symbol_kind::S_EQ_OP: // EQ_OP
#line 31 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1085 "parser.tab.cc"
        break;

      case symbol_kind::S_NE_OP: // NE_OP
#line 32 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1091 "parser.tab.cc"
        break;

      case symbol_kind::S_LE_OP: // LE_OP
#line 33 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1097 "parser.tab.cc"
        break;

      case symbol_kind::S_GE_OP: // GE_OP
#line 34 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1103 "parser.tab.cc"
        break;

      case symbol_kind::S_INC_OP: // INC_OP
#line 35 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1109 "parser.tab.cc"
        break;

      case symbol_kind::S_PTR_OP: // PTR_OP
#line 36 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1115 "parser.tab.cc"
        break;

      case symbol_kind::S_IF: // IF
#line 37 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1121 "parser.tab.cc"
        break;

      case symbol_kind::S_MAIN: // MAIN
#line 40 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1127 "parser.tab.cc"
        break;

      case symbol_kind::S_PRINTF: // PRINTF
#line 41 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1133 "parser.tab.cc"
        break;

      case symbol_kind::S_ELSE: // ELSE
#line 38 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1139 "parser.tab.cc"
        break;

      case symbol_kind::S_WHILE: // WHILE
#line 39 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1145 "parser.tab.cc"
        break;

      case symbol_kind::S_FOR: // FOR
#line 42 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1151 "parser.tab.cc"
        break;

      case symbol_kind::S_RETURN: // RETURN
#line 43 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1157 "parser.tab.cc"
        break;

      case symbol_kind::S_OTHERS: // OTHERS
#line 44 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1163 "parser.tab.cc"
        break;

      default:
        break;
    }
        yyo << ')';
      }
  }
#endif

  void
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.kind_ = yytranslate_ (yylex (&yyla.value, &yyla.location));
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_struct_specifier: // struct_specifier
      case symbol_kind::S_declaration_list: // declaration_list
        yylhs.value.emplace< abstract_astnode* > ();
        break;

      case symbol_kind::S_assignment_expression: // assignment_expression
        yylhs.value.emplace< assignE_astnode* > ();
        break;

      case symbol_kind::S_expression: // expression
      case symbol_kind::S_unary_expression: // unary_expression
      case symbol_kind::S_postfix_expression: // postfix_expression
      case symbol_kind::S_primary_expression: // primary_expression
        yylhs.value.emplace< exp_astnode* > ();
        break;

      case symbol_kind::S_printf_call: // printf_call
      case symbol_kind::S_procedure_call: // procedure_call
        yylhs.value.emplace< funcall_astnode* > ();
        break;

      case symbol_kind::S_fun_declarator: // fun_declarator
        yylhs.value.emplace< fundeclarator_astnode* > ();
        break;

      case symbol_kind::S_mnterm: // mnterm
        yylhs.value.emplace< mnt* > ();
        break;

      case symbol_kind::S_ifgotocoder: // ifgotocoder
      case symbol_kind::S_logical_and_expression: // logical_and_expression
      case symbol_kind::S_equality_expression: // equality_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
        yylhs.value.emplace< op_binary_astnode* > ();
        break;

      case symbol_kind::S_main_definition: // main_definition
      case symbol_kind::S_function_definition: // function_definition
      case symbol_kind::S_statement: // statement
      case symbol_kind::S_assignment_statement: // assignment_statement
      case symbol_kind::S_selection_statement: // selection_statement
      case symbol_kind::S_iteration_statement: // iteration_statement
        yylhs.value.emplace< statement_astnode* > ();
        break;

      case symbol_kind::S_VOID: // VOID
      case symbol_kind::S_INT: // INT
      case symbol_kind::S_FLOAT: // FLOAT
      case symbol_kind::S_STRUCT: // STRUCT
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_INT_CONSTANT: // INT_CONSTANT
      case symbol_kind::S_FLOAT_CONSTANT: // FLOAT_CONSTANT
      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
      case symbol_kind::S_OR_OP: // OR_OP
      case symbol_kind::S_AND_OP: // AND_OP
      case symbol_kind::S_EQ_OP: // EQ_OP
      case symbol_kind::S_NE_OP: // NE_OP
      case symbol_kind::S_LE_OP: // LE_OP
      case symbol_kind::S_GE_OP: // GE_OP
      case symbol_kind::S_INC_OP: // INC_OP
      case symbol_kind::S_PTR_OP: // PTR_OP
      case symbol_kind::S_IF: // IF
      case symbol_kind::S_MAIN: // MAIN
      case symbol_kind::S_PRINTF: // PRINTF
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_OTHERS: // OTHERS
      case symbol_kind::S_unary_operator: // unary_operator
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_begin_nterm: // begin_nterm
      case symbol_kind::S_program: // program
      case symbol_kind::S_translation_unit: // translation_unit
        yylhs.value.emplace< std::vector<abstract_astnode*> > ();
        break;

      case symbol_kind::S_expression_list: // expression_list
        yylhs.value.emplace< std::vector<exp_astnode*> > ();
        break;

      case symbol_kind::S_compound_statement: // compound_statement
      case symbol_kind::S_statement_list: // statement_list
        yylhs.value.emplace< std::vector<statement_astnode*> > ();
        break;

      case symbol_kind::S_parameter_list: // parameter_list
        yylhs.value.emplace< std::vector<typespec_astnode> > ();
        break;

      case symbol_kind::S_type_specifier: // type_specifier
      case symbol_kind::S_parameter_declaration: // parameter_declaration
      case symbol_kind::S_declarator_arr: // declarator_arr
      case symbol_kind::S_declarator: // declarator
      case symbol_kind::S_declaration: // declaration
      case symbol_kind::S_declarator_list: // declarator_list
        yylhs.value.emplace< typespec_astnode > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // $@1: %empty
#line 123 "parser.yy"
             {
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

}
#line 1530 "parser.tab.cc"
    break;

  case 3: // begin_nterm: $@1 program
#line 135 "parser.yy"
          {
    if(Symbols::symTabStage==1){
        // ststack.top()->printJson();
    }
    else if(Symbols::symTabStage==2){
        Symbols::gst->printJson();
        std::cout<<"\n# *****************3A starts here**************"<<std::endl;
        code.printCode();
        std::cout<<"\n# ****************ASM Starts here********** "<<std::endl;
        //TODO: will comment out last two instructions before submission, 
        //to print only asm.
        code.printASM();
    }
    Symbols::symTabStage+=1;
}
#line 1550 "parser.tab.cc"
    break;

  case 4: // program: main_definition
#line 150 "parser.yy"
                       {

}
#line 1558 "parser.tab.cc"
    break;

  case 5: // program: translation_unit main_definition
#line 153 "parser.yy"
                                 {

}
#line 1566 "parser.tab.cc"
    break;

  case 6: // $@2: %empty
#line 157 "parser.yy"
                                 {
    std::string name = yystack_[2].value.as < std::string > ();
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
}
#line 1587 "parser.tab.cc"
    break;

  case 7: // main_definition: INT MAIN '(' ')' $@2 compound_statement
#line 172 "parser.yy"
                    {
    if(Symbols::symTabStage>0){
        ststack.top()->ptr = new seq_astnode(yystack_[0].value.as < std::vector<statement_astnode*> > ());
    }
    yylhs.value.as < statement_astnode* > () = nullptr;
    ststack.pop();
}
#line 1599 "parser.tab.cc"
    break;

  case 8: // translation_unit: struct_specifier
#line 180 "parser.yy"
                                  {
}
#line 1606 "parser.tab.cc"
    break;

  case 9: // translation_unit: function_definition
#line 182 "parser.yy"
                     {
    yylhs.value.as < std::vector<abstract_astnode*> > () = std::vector<abstract_astnode*>();
    yylhs.value.as < std::vector<abstract_astnode*> > ().push_back(yystack_[0].value.as < statement_astnode* > ());
}
#line 1615 "parser.tab.cc"
    break;

  case 10: // translation_unit: translation_unit struct_specifier
#line 186 "parser.yy"
                                   {
}
#line 1622 "parser.tab.cc"
    break;

  case 11: // translation_unit: translation_unit function_definition
#line 188 "parser.yy"
                                      {
    yylhs.value.as < std::vector<abstract_astnode*> > () = yystack_[1].value.as < std::vector<abstract_astnode*> > ();
    yylhs.value.as < std::vector<abstract_astnode*> > ().push_back(yystack_[0].value.as < statement_astnode* > ());
}
#line 1631 "parser.tab.cc"
    break;

  case 12: // $@3: %empty
#line 194 "parser.yy"
                                    {
    string structName = "struct " + yystack_[0].value.as < std::string > ();
    if(Symbols::symTabStage==0){
        ststack.top()->rows[structName] = SymEntry(structc,SymTab::ST_HL_type::STRUCT,SymTab::ST_LPG::GLOBAL,0,0);
        Symbols::slsts[structName] = new SymTab();
        Symbols::slsts[structName]->type = "struct";
    }
    ststack.push(Symbols::slsts[structName]);
}
#line 1645 "parser.tab.cc"
    break;

  case 13: // struct_specifier: STRUCT IDENTIFIER $@3 '{' declaration_list '}' ';'
#line 202 "parser.yy"
                             {
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
}
#line 1662 "parser.tab.cc"
    break;

  case 14: // function_definition: type_specifier fun_declarator compound_statement
#line 215 "parser.yy"
                                                                     {
    if(Symbols::symTabStage>0){
        ststack.top()->ptr = new seq_astnode(yystack_[0].value.as < std::vector<statement_astnode*> > ());
    }
    if(Symbols::symTabStage==2){
        if(yystack_[2].value.as < typespec_astnode > ().typeName=="void"){
            gen(troins::ret,troins::na,{});
        }
    }
    yylhs.value.as < statement_astnode* > () = nullptr;
    ststack.pop();
}
#line 1679 "parser.tab.cc"
    break;

  case 15: // type_specifier: VOID
#line 228 "parser.yy"
                    {
    typespec_astnode ts;
    ts.baseTypeWidth = 0;
    ts.baseTypeName = "void";
    ts.typeWidth = ts.baseTypeWidth;
    ts.typeName = "void";
    yylhs.value.as < typespec_astnode > () = ts;
    if(Symbols::symTabStage==0){
        toptype = ts;
    }

}
#line 1696 "parser.tab.cc"
    break;

  case 16: // type_specifier: INT
#line 240 "parser.yy"
     {
    // retType = SymTab::ST_type::INT;
    typespec_astnode ts = intc;
    yylhs.value.as < typespec_astnode > () = ts;
    if(Symbols::symTabStage==0){
        toptype = ts;
    }

}
#line 1710 "parser.tab.cc"
    break;

  case 17: // type_specifier: STRUCT IDENTIFIER
#line 249 "parser.yy"
                   {
    // retType = SymTab::ST_type::STRUCT_TYPE;
    typespec_astnode ts;
    ts.typeName = "struct "+(yystack_[0].value.as < std::string > ());
    ts.baseTypeWidth = Symbols::getStructBaseTypeWidth(ts.typeName);
    ts.typeWidth = ts.baseTypeWidth;
    ts.baseTypeName = ts.typeName;
    yylhs.value.as < typespec_astnode > () = ts;
    if(Symbols::symTabStage==0){
        toptype = ts;
    }
}
#line 1727 "parser.tab.cc"
    break;

  case 18: // $@4: %empty
#line 263 "parser.yy"
                              {
    std::string name = yystack_[1].value.as < std::string > ();
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
}
#line 1746 "parser.tab.cc"
    break;

  case 19: // fun_declarator: IDENTIFIER '(' $@4 parameter_list ')'
#line 276 "parser.yy"
                    {
    yylhs.value.as < fundeclarator_astnode* > () = NULL;
    if(Symbols::symTabStage==0){
        auto &rows = (ststack.top())->rows;
        long long minParamOffset = 0;
        for(auto entry:rows){
            minParamOffset = min(minParamOffset,ststack.top()->rows[entry.first].offset);
        }
        int localsParamsGap = 8;
        int summer = localsParamsGap - minParamOffset;
        auto iter = rows.begin();
        for(;iter!=rows.end();){
            rows[iter->first].offset += summer;    
            iter++;
        }
    }
    else{
        std::string name = yystack_[4].value.as < std::string > ();
        std::vector<typespec_astnode> vect = std::vector<typespec_astnode>();
        yylhs.value.as < fundeclarator_astnode* > () = new fundeclarator_astnode(name, vect);
    }
}
#line 1773 "parser.tab.cc"
    break;

  case 20: // fun_declarator: IDENTIFIER '(' ')'
#line 298 "parser.yy"
                    {
    std::string name = yystack_[2].value.as < std::string > ();
    if(Symbols::symTabStage==0){
        ststack.top()->rows[name] = SymEntry(toptype,SymTab::ST_HL_type::FUN,SymTab::ST_LPG::GLOBAL,0,0);
        Symbols::flsts[name] = new SymTab();
        Symbols::flsts[name]->rettype = new typespec_astnode;
        Symbols::flsts[name]->type = "function";
        *(Symbols::flsts[name]->rettype) = toptype;
    }
    else{
        yylhs.value.as < fundeclarator_astnode* > () = new fundeclarator_astnode(name,std::vector<typespec_astnode>());
        if(Symbols::symTabStage==2){
            code.setLabel(name);
        }
    }
    ststack.push(Symbols::flsts[name]);
}
#line 1795 "parser.tab.cc"
    break;

  case 21: // parameter_list: parameter_declaration
#line 317 "parser.yy"
                                     {
    if(Symbols::symTabStage==1){
        yylhs.value.as < std::vector<typespec_astnode> > () = std::vector<typespec_astnode>();
        yylhs.value.as < std::vector<typespec_astnode> > ().push_back(yystack_[0].value.as < typespec_astnode > ());
    }
}
#line 1806 "parser.tab.cc"
    break;

  case 22: // parameter_list: parameter_list ',' parameter_declaration
#line 323 "parser.yy"
                                           {
    if(Symbols::symTabStage==1){
        yylhs.value.as < std::vector<typespec_astnode> > () = yystack_[2].value.as < std::vector<typespec_astnode> > ();
        yylhs.value.as < std::vector<typespec_astnode> > ().push_back(yystack_[0].value.as < typespec_astnode > ());
    }
}
#line 1817 "parser.tab.cc"
    break;

  case 23: // parameter_declaration: type_specifier declarator
#line 331 "parser.yy"
                                                {
    yylhs.value.as < typespec_astnode > () = yystack_[1].value.as < typespec_astnode > ();
    if(Symbols::symTabStage==0){
        if(yystack_[0].value.as < typespec_astnode > ().typeName=="void"){
            error(yylhs.location,"Cannot declare variable of type \"void\"");
        }
        ststack.top()->rows[topvarname] = SymEntry(yystack_[0].value.as < typespec_astnode > (),SymTab::ST_HL_type::VAR,SymTab::ST_LPG::PARAM,yystack_[0].value.as < typespec_astnode > ().typeWidth,0);
        ststack.top()->rows[topvarname].offset = ststack.top()->getParamOffset(ststack.top()->rows[topvarname].size);
    }
}
#line 1832 "parser.tab.cc"
    break;

  case 24: // declarator_arr: IDENTIFIER
#line 343 "parser.yy"
                          {
    yylhs.value.as < typespec_astnode > () = toptype;
    yylhs.value.as < typespec_astnode > ().typeWidth = yylhs.value.as < typespec_astnode > ().baseTypeWidth;
    if(Symbols::symTabStage==0){
        topvarname = yystack_[0].value.as < std::string > ();
        // if(Symbols::getSymEntry(Symbols::gst, $$)){
            //error(@$, "Identifier is taken.")
        //}
    }
}
#line 1847 "parser.tab.cc"
    break;

  case 25: // declarator_arr: declarator_arr '[' INT_CONSTANT ']'
#line 353 "parser.yy"
                                     {
    yylhs.value.as < typespec_astnode > () = yystack_[3].value.as < typespec_astnode > ();
    if(Symbols::symTabStage==0){
        typespec_astnode tstmp = yystack_[3].value.as < typespec_astnode > ();
        yylhs.value.as < typespec_astnode > ().arrsizes.insert(yylhs.value.as < typespec_astnode > ().arrsizes.begin(),std::stoi(yystack_[1].value.as < std::string > ()));
        yylhs.value.as < typespec_astnode > ().typeWidth = yylhs.value.as < typespec_astnode > ().genTypeWidth();
        yylhs.value.as < typespec_astnode > ().typeName = yylhs.value.as < typespec_astnode > ().genTypeName();
    }
}
#line 1861 "parser.tab.cc"
    break;

  case 26: // declarator: declarator_arr
#line 363 "parser.yy"
                          {
    yylhs.value.as < typespec_astnode > () = yystack_[0].value.as < typespec_astnode > ();
}
#line 1869 "parser.tab.cc"
    break;

  case 27: // declarator: '*' declarator
#line 366 "parser.yy"
                 {
    yylhs.value.as < typespec_astnode > () = yystack_[0].value.as < typespec_astnode > ();
    yylhs.value.as < typespec_astnode > ().baseTypeWidth = 4;
    yylhs.value.as < typespec_astnode > ().numptrstars+=1;
    yylhs.value.as < typespec_astnode > ().typeWidth = yylhs.value.as < typespec_astnode > ().genTypeWidth();
    yylhs.value.as < typespec_astnode > ().typeName = yylhs.value.as < typespec_astnode > ().genTypeName();
}
#line 1881 "parser.tab.cc"
    break;

  case 28: // compound_statement: '{' '}'
#line 375 "parser.yy"
                           {
    yylhs.value.as < std::vector<statement_astnode*> > () = std::vector<statement_astnode*>();
}
#line 1889 "parser.tab.cc"
    break;

  case 29: // compound_statement: '{' statement_list '}'
#line 378 "parser.yy"
                        {
    yylhs.value.as < std::vector<statement_astnode*> > () = yystack_[1].value.as < std::vector<statement_astnode*> > ();
}
#line 1897 "parser.tab.cc"
    break;

  case 30: // compound_statement: '{' declaration_list '}'
#line 381 "parser.yy"
                           {
    yylhs.value.as < std::vector<statement_astnode*> > () = std::vector<statement_astnode*>();

}
#line 1906 "parser.tab.cc"
    break;

  case 31: // compound_statement: '{' declaration_list statement_list '}'
#line 385 "parser.yy"
                                         {
    yylhs.value.as < std::vector<statement_astnode*> > () = yystack_[1].value.as < std::vector<statement_astnode*> > ();
}
#line 1914 "parser.tab.cc"
    break;

  case 32: // statement_list: statement
#line 390 "parser.yy"
                          {
    std::vector<statement_astnode*> temp;
    statement_astnode* stmt = yystack_[0].value.as < statement_astnode* > ();
    if(stmt!=NULL){
        temp.push_back(yystack_[0].value.as < statement_astnode* > ());
    }
    yylhs.value.as < std::vector<statement_astnode*> > () = temp;
}
#line 1927 "parser.tab.cc"
    break;

  case 33: // statement_list: statement_list statement
#line 398 "parser.yy"
                          {
    yystack_[1].value.as < std::vector<statement_astnode*> > ().push_back(yystack_[0].value.as < statement_astnode* > ());
    yylhs.value.as < std::vector<statement_astnode*> > () = yystack_[1].value.as < std::vector<statement_astnode*> > ();
}
#line 1936 "parser.tab.cc"
    break;

  case 34: // statement: ';'
#line 404 "parser.yy"
              {
    if(Symbols::symTabStage>0){   
        yylhs.value.as < statement_astnode* > () = new empty_astnode();
    }
}
#line 1946 "parser.tab.cc"
    break;

  case 35: // statement: '{' statement_list '}'
#line 409 "parser.yy"
                        {
    if(Symbols::symTabStage>0){   
        yylhs.value.as < statement_astnode* > () = new seq_astnode(yystack_[1].value.as < std::vector<statement_astnode*> > ());
    }
}
#line 1956 "parser.tab.cc"
    break;

  case 36: // statement: selection_statement
#line 414 "parser.yy"
                     {
    yylhs.value.as < statement_astnode* > () = yystack_[0].value.as < statement_astnode* > ();
}
#line 1964 "parser.tab.cc"
    break;

  case 37: // statement: iteration_statement
#line 417 "parser.yy"
                     {
    yylhs.value.as < statement_astnode* > () = yystack_[0].value.as < statement_astnode* > ();
}
#line 1972 "parser.tab.cc"
    break;

  case 38: // statement: assignment_statement
#line 420 "parser.yy"
                      {
    yylhs.value.as < statement_astnode* > () = yystack_[0].value.as < statement_astnode* > ();
}
#line 1980 "parser.tab.cc"
    break;

  case 39: // statement: procedure_call
#line 423 "parser.yy"
                {
    yylhs.value.as < statement_astnode* > () = yystack_[0].value.as < funcall_astnode* > ();
}
#line 1988 "parser.tab.cc"
    break;

  case 40: // statement: printf_call
#line 426 "parser.yy"
             {
    yylhs.value.as < statement_astnode* > () = yystack_[0].value.as < funcall_astnode* > ();
}
#line 1996 "parser.tab.cc"
    break;

  case 41: // statement: RETURN expression ';'
#line 429 "parser.yy"
                       {
    if(Symbols::symTabStage>0){
        typespec_astnode rt = *(ststack.top()->rettype);
        if (!rt.compatibleWith(yystack_[1].value.as < exp_astnode* > ()->typeNode)) {
            error(yylhs.location, "Function must return "+ rt.typeName+" but returns "+yystack_[1].value.as < exp_astnode* > ()->typeNode.typeName );
        }
        else{
            yylhs.value.as < statement_astnode* > () = new return_astnode(yystack_[1].value.as < exp_astnode* > ());
            if(rt.isNumeric()){
                if (rt.typeName != yystack_[1].value.as < exp_astnode* > ()->typeNode.typeName) {
                    std::string ltypename = rt.typeName;
                    std::transform(ltypename.begin(), ltypename.end(), ltypename.begin(), [](auto c) { return std::toupper(c); });
                    // std::cerr << ltypename << std::endl;
                    std::string utypename = "TO_" + ltypename;
                    yylhs.value.as < statement_astnode* > () = new return_astnode(new op_unary_astnode(utypename, yystack_[1].value.as < exp_astnode* > ()));
                }
            }
        }
    }
    if(Symbols::symTabStage==2){
        gen(troins::ret,troins::na,{yystack_[1].value.as < exp_astnode* > ()->addr});
    }
}
#line 2024 "parser.tab.cc"
    break;

  case 42: // printf_call: PRINTF '(' STRING_LITERAL ')' ';'
#line 454 "parser.yy"
                                               {
    exp_astnode* arg1 = new stringconst_astnode(yystack_[2].value.as < std::string > ());
    arg1->addr = Symbols::newStrLit(yystack_[2].value.as < std::string > ());
    yylhs.value.as < funcall_astnode* > () = new funcall_astnode(new identifier_astnode(yystack_[4].value.as < std::string > ()), std::vector<exp_astnode*>(1,arg1), true);
    if(Symbols::symTabStage==2){
        gen(troins::func,troins::param,{arg1->addr});
        gen(troins::func,troins::call,{yystack_[4].value.as < std::string > (),"1"});
    }
}
#line 2038 "parser.tab.cc"
    break;

  case 43: // printf_call: PRINTF '(' STRING_LITERAL ',' expression_list ')' ';'
#line 463 "parser.yy"
                                                       {
    std::vector<exp_astnode*> args = yystack_[2].value.as < std::vector<exp_astnode*> > ();
    exp_astnode* strnode = new stringconst_astnode(yystack_[4].value.as < std::string > ());
    strnode->addr = Symbols::newStrLit(yystack_[4].value.as < std::string > ());
    args.insert(args.begin(),strnode);
    std::reverse(args.begin(),args.end());

    yylhs.value.as < funcall_astnode* > () = new funcall_astnode(new identifier_astnode(yystack_[6].value.as < std::string > ()), args, true);
    if(Symbols::symTabStage==2){
        for(exp_astnode* prm:args){
            gen(troins::func,troins::param,{prm->addr});
        }
        gen(troins::func,troins::call,{yystack_[6].value.as < std::string > (),to_string(args.size())});
    }
}
#line 2058 "parser.tab.cc"
    break;

  case 44: // assignment_expression: unary_expression '=' expression
#line 478 "parser.yy"
                                                      {
    if(Symbols::symTabStage>0){
        // std::cerr<<__LINE__<<std::endl;
        std::cerr<<yystack_[2].value.as < exp_astnode* > ()->typeNode.typeName<<" = "<<yystack_[0].value.as < exp_astnode* > ()->typeNode.typeName<<std::endl;
        if((yystack_[2].value.as < exp_astnode* > ()->typeNode.compatibleWith(yystack_[0].value.as < exp_astnode* > ()->typeNode))){
            // std::cerr<<__LINE__<<std::endl;
            if(!(yystack_[2].value.as < exp_astnode* > ()->typeNode.islval)){
                error(yylhs.location,"Error: Tried to assign value to rvalue.");
            }
            
            
            if(yystack_[2].value.as < exp_astnode* > ()->typeNode.typeName!=yystack_[0].value.as < exp_astnode* > ()->typeNode.typeName){
                // std::cerr<<__LINE__<<std::endl;
                if (yystack_[2].value.as < exp_astnode* > ()->typeNode.isNumeric()){
                    // std::cerr<<__LINE__<<std::endl;
                    std::string ltypename = yystack_[2].value.as < exp_astnode* > ()->typeNode.typeName;
                    std::transform(ltypename.begin(), ltypename.end(), ltypename.begin(), [](auto c) { return std::toupper(c); });
                    // std::cerr << ltypename << std::endl;
                    std::string utypename = "TO_" + ltypename;
                    yylhs.value.as < assignE_astnode* > () = new assignE_astnode(yystack_[2].value.as < exp_astnode* > (), new op_unary_astnode(utypename, yystack_[0].value.as < exp_astnode* > ()));
                }
                else{
                    yylhs.value.as < assignE_astnode* > () = new assignE_astnode(yystack_[2].value.as < exp_astnode* > (), yystack_[0].value.as < exp_astnode* > ());
                }
            }
            else {yylhs.value.as < assignE_astnode* > () = new assignE_astnode(yystack_[2].value.as < exp_astnode* > (), yystack_[0].value.as < exp_astnode* > ());}
        }
        else{
            error(yylhs.location,"Incompatible types: tried to assign "+yystack_[0].value.as < exp_astnode* > ()->typeNode.typeName+" to "+yystack_[2].value.as < exp_astnode* > ()->typeNode.typeName);
        }
    }
    if(Symbols::symTabStage==2){
        std::string t1;
        if(yystack_[0].value.as < exp_astnode* > ()->isproxyaddr||yystack_[0].value.as < exp_astnode* > ()->iselem){
            typespec_astnode tn = yystack_[0].value.as < exp_astnode* > ()->typeNode;
            tn.deref();
            t1 = newtemp(tn);
            gen(troins::ass,troins::uop,{t1,"*",yystack_[0].value.as < exp_astnode* > ()->addr});
        }
        else{
            t1 = yystack_[0].value.as < exp_astnode* > ()->addr;
        }
        if(yystack_[2].value.as < exp_astnode* > ()->isproxyaddr||yystack_[2].value.as < exp_astnode* > ()->iselem){
            gen(troins::ass,troins::ptrl,{yystack_[2].value.as < exp_astnode* > ()->addr,t1});
        }
        else{
            gen(troins::ass,troins::na,{yystack_[2].value.as < exp_astnode* > ()->addr,t1});
        }
    }
}
#line 2113 "parser.tab.cc"
    break;

  case 45: // assignment_statement: assignment_expression ';'
#line 530 "parser.yy"
                                               {
    if(Symbols::symTabStage>0){
        yylhs.value.as < statement_astnode* > () = new assignS_astnode(yystack_[1].value.as < assignE_astnode* > ()->exp1, yystack_[1].value.as < assignE_astnode* > ()->exp2);
    }
}
#line 2123 "parser.tab.cc"
    break;

  case 46: // procedure_call: IDENTIFIER '(' ')' ';'
#line 537 "parser.yy"
                                      {
    if (Symbols::symTabStage>0) {
        std::string function_name = yystack_[3].value.as < std::string > ();
        if(!(yystack_[3].value.as < std::string > ()=="printf"||yystack_[3].value.as < std::string > ()=="scanf")){
            SymTab* fstab = Symbols::flsts[function_name];
            if (fstab == nullptr) {
                error(yylhs.location, "Procedure \"" + yystack_[3].value.as < std::string > () + "\" not declared");
            }
        //Arg checks.
            std::set<std::pair<long long, std::string>> expected;
            for (auto row: fstab->rows) {
                if (row.second.lpgtype == SymTab::PARAM) {
                    expected.insert(std::make_pair(row.second.offset, row.second.type.typeName));
                }
            }
            if (!expected.empty()) {
                error(yylhs.location, "Procedure \"" + yystack_[3].value.as < std::string > () + "\" called with too few arguments");
            }
            yylhs.value.as < funcall_astnode* > () = new funcall_astnode(new identifier_astnode(yystack_[3].value.as < std::string > ()), std::vector<exp_astnode*>(), true);
            yylhs.value.as < funcall_astnode* > ()->typeNode = Symbols::getSymEntry(Symbols::gst, yystack_[3].value.as < std::string > ())->type;
        }
        else {
            yylhs.value.as < funcall_astnode* > () = new funcall_astnode(new identifier_astnode(yystack_[3].value.as < std::string > ()), std::vector<exp_astnode*>(), true);
            yylhs.value.as < funcall_astnode* > ()->typeNode = voidc;
        }
    }
    if(Symbols::symTabStage==2){
        gen(troins::func,troins::call,{yystack_[3].value.as < std::string > (),"0"});
    }
}
#line 2158 "parser.tab.cc"
    break;

  case 47: // procedure_call: IDENTIFIER '(' expression_list ')' ';'
#line 567 "parser.yy"
                                        {
    std::reverse(yystack_[2].value.as < std::vector<exp_astnode*> > ().begin(),yystack_[2].value.as < std::vector<exp_astnode*> > ().end());
    if (Symbols::symTabStage>0) {
        std::string function_name = yystack_[4].value.as < std::string > ();
        if(!(yystack_[4].value.as < std::string > ()=="printf"||yystack_[4].value.as < std::string > ()=="scanf")){
            SymTab* fstab = Symbols::flsts[function_name];
            std::set<std::pair<long long, typespec_astnode>,struct offsetcomp> expected;
            for (auto row: fstab->rows) {
                if (row.second.lpgtype == SymTab::PARAM) {
                    expected.insert(std::make_pair(row.second.offset, row.second.type));
                }
            }
            if (yystack_[2].value.as < std::vector<exp_astnode*> > ().size() < expected.size()) {
                error(yylhs.location, "Procedure \"" + yystack_[4].value.as < std::string > () + "\" called with too few arguments");
            }
            else if (yystack_[2].value.as < std::vector<exp_astnode*> > ().size() > expected.size()) {
                error(yylhs.location, "Procedure \"" + yystack_[4].value.as < std::string > () + "\" called with too many arguments");
            }
            std::vector<exp_astnode*> exp_list = yystack_[2].value.as < std::vector<exp_astnode*> > ();
            std::reverse(exp_list.begin(), exp_list.end());
            int i = 0;
            for (auto item: expected) {
                if (!item.second.compatibleWith(exp_list[i]->typeNode,true)) {
                    error(yylhs.location, "Expected \"" + item.second.typeName + "\" but argument is of type \"" + exp_list[i]->typeNode.typeName + "\"");
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
            yylhs.value.as < funcall_astnode* > () = new funcall_astnode(new identifier_astnode(yystack_[4].value.as < std::string > ()), exp_list, true);
            yylhs.value.as < funcall_astnode* > ()->typeNode = Symbols::getSymEntry(Symbols::gst, yystack_[4].value.as < std::string > ())->type;
        }
        else {
            yylhs.value.as < funcall_astnode* > () = new funcall_astnode(new identifier_astnode(yystack_[4].value.as < std::string > ()), yystack_[2].value.as < std::vector<exp_astnode*> > (), true);
            yylhs.value.as < funcall_astnode* > ()->typeNode = voidc;
        }
    }
    if(Symbols::symTabStage==2){
        for(exp_astnode* prm:yystack_[2].value.as < std::vector<exp_astnode*> > ()){
            gen(troins::func,troins::param,{prm->addr});
        }
        gen(troins::func,troins::call,{yystack_[4].value.as < std::string > (),to_string(yystack_[2].value.as < std::vector<exp_astnode*> > ().size())});
    }
}
#line 2213 "parser.tab.cc"
    break;

  case 48: // expression: logical_and_expression
#line 619 "parser.yy"
                                  {
    yylhs.value.as < exp_astnode* > () = yystack_[0].value.as < op_binary_astnode* > ();
    // std::cerr<<__LINE__<<$$->typeNode.typeName<<endl;
}
#line 2222 "parser.tab.cc"
    break;

  case 49: // expression: expression OR_OP mnterm logical_and_expression
#line 623 "parser.yy"
                                                {
    if(Symbols::symTabStage>0){
        yylhs.value.as < exp_astnode* > () = new op_binary_astnode("OR_OP",yystack_[3].value.as < exp_astnode* > (),yystack_[0].value.as < op_binary_astnode* > ());
    }
    if(Symbols::symTabStage==2){
        yylhs.value.as < exp_astnode* > ()->addr = newtemp(typespec_astnode::intc);
        if(code.condcode){
            code.backpatch(yystack_[3].value.as < exp_astnode* > ()->fl,yystack_[1].value.as < mnt* > ()->nil);
            yylhs.value.as < exp_astnode* > ()->tl = code.merge(yystack_[3].value.as < exp_astnode* > ()->tl,yystack_[0].value.as < op_binary_astnode* > ()->tl);
            yylhs.value.as < exp_astnode* > ()->fl = yystack_[0].value.as < op_binary_astnode* > ()->fl;
        }
        else{
            gen(troins::ass,troins::bop,{yylhs.value.as < exp_astnode* > ()->addr,yystack_[3].value.as < exp_astnode* > ()->addr,"OR_OP",yystack_[0].value.as < op_binary_astnode* > ()->addr});
        }
    }
}
#line 2243 "parser.tab.cc"
    break;

  case 50: // mnterm: %empty
#line 640 "parser.yy"
       {
    yylhs.value.as < mnt* > () = new mnt();
    if(code.condcode){
        yylhs.value.as < mnt* > ()->nil = code.condtype+"_"+code.newLabel();
        code.setLabel(yylhs.value.as < mnt* > ()->nil);
    }
}
#line 2255 "parser.tab.cc"
    break;

  case 51: // ifgotocoder: equality_expression
#line 647 "parser.yy"
                                {
    yylhs.value.as < op_binary_astnode* > () = yystack_[0].value.as < op_binary_astnode* > ();
    if(Symbols::symTabStage==2){
        if(code.condcode&&(!(yylhs.value.as < op_binary_astnode* > ()->ifgened))){
            yylhs.value.as < op_binary_astnode* > ()->tl = {code.nextinstr()};
            gen(troins::gt,troins::ifs,{yystack_[0].value.as < op_binary_astnode* > ()->addr,""});
            yylhs.value.as < op_binary_astnode* > ()->fl = {code.nextinstr()};
            gen(troins::gt,troins::na,{""});
            yylhs.value.as < op_binary_astnode* > ()->ifgened = true;
        }
    }
}
#line 2272 "parser.tab.cc"
    break;

  case 52: // logical_and_expression: ifgotocoder
#line 659 "parser.yy"
                                   {
    yylhs.value.as < op_binary_astnode* > () = yystack_[0].value.as < op_binary_astnode* > ();
}
#line 2280 "parser.tab.cc"
    break;

  case 53: // logical_and_expression: logical_and_expression AND_OP mnterm ifgotocoder
#line 662 "parser.yy"
                                                  {
    if(Symbols::symTabStage>0){
        yylhs.value.as < op_binary_astnode* > () = new op_binary_astnode("AND_OP", yystack_[3].value.as < op_binary_astnode* > (), yystack_[0].value.as < op_binary_astnode* > ());
    }
    if(Symbols::symTabStage==2){
        yylhs.value.as < op_binary_astnode* > ()->addr = newtemp(typespec_astnode::intc);
        if(code.condcode){
            yylhs.value.as < op_binary_astnode* > ()->tl = yystack_[0].value.as < op_binary_astnode* > ()->tl;
            code.backpatch(yystack_[3].value.as < op_binary_astnode* > ()->tl,yystack_[1].value.as < mnt* > ()->nil);
            yylhs.value.as < op_binary_astnode* > ()->fl = code.merge(yystack_[3].value.as < op_binary_astnode* > ()->fl,yystack_[0].value.as < op_binary_astnode* > ()->fl);
        }
        else{
            gen(troins::ass,troins::bop,{yylhs.value.as < op_binary_astnode* > ()->addr,yystack_[3].value.as < op_binary_astnode* > ()->addr,"AND_OP",yystack_[0].value.as < op_binary_astnode* > ()->addr});
        }
    }
}
#line 2301 "parser.tab.cc"
    break;

  case 54: // equality_expression: relational_expression
#line 680 "parser.yy"
                                          {
    yylhs.value.as < op_binary_astnode* > () = yystack_[0].value.as < op_binary_astnode* > ();
    // std::cerr<<__LINE__<<$$->typeNode.typeName<<endl;
}
#line 2310 "parser.tab.cc"
    break;

  case 55: // equality_expression: equality_expression EQ_OP relational_expression
#line 684 "parser.yy"
                                                  {
    std::string op = "EQ_OP?";
    if(Symbols::symTabStage>0){
        if(!op_binary_astnode::operandsCompatible(op,yystack_[2].value.as < op_binary_astnode* > (),yystack_[0].value.as < op_binary_astnode* > ())){
            error(yylhs.location,"Incompatible operands for "+op+": \""+yystack_[2].value.as < op_binary_astnode* > ()->typeNode.typeName+"\", \""+yystack_[0].value.as < op_binary_astnode* > ()->typeNode.typeName+"\"");
        }
        yylhs.value.as < op_binary_astnode* > () = new op_binary_astnode(op, yystack_[2].value.as < op_binary_astnode* > (), yystack_[0].value.as < op_binary_astnode* > ());
    }
    if(Symbols::symTabStage==2){
        op = op.substr(0,op.size()-1);
        std::string t1 = newtemp(typespec_astnode::intc);
        gen(troins::ass,troins::bop,{t1,yystack_[2].value.as < op_binary_astnode* > ()->addr,op,yystack_[0].value.as < op_binary_astnode* > ()->addr});
        yylhs.value.as < op_binary_astnode* > ()->addr = t1;

    }
}
#line 2331 "parser.tab.cc"
    break;

  case 56: // equality_expression: equality_expression NE_OP relational_expression
#line 700 "parser.yy"
                                                 {
    std::string op = "NE_OP?";
    if(Symbols::symTabStage>0){ 
        if(!op_binary_astnode::operandsCompatible(op,yystack_[2].value.as < op_binary_astnode* > (),yystack_[0].value.as < op_binary_astnode* > ())){
            error(yylhs.location,"Incompatible operands for "+op+": \""+yystack_[2].value.as < op_binary_astnode* > ()->typeNode.typeName+"\", \""+yystack_[0].value.as < op_binary_astnode* > ()->typeNode.typeName+"\"");
        }
        yylhs.value.as < op_binary_astnode* > () = new op_binary_astnode(op, yystack_[2].value.as < op_binary_astnode* > (), yystack_[0].value.as < op_binary_astnode* > ());
    }
    if(Symbols::symTabStage==2){
        op = op.substr(0,op.size()-1);
        std::string t1 = newtemp(typespec_astnode::intc);
        gen(troins::ass,troins::bop,{t1,yystack_[2].value.as < op_binary_astnode* > ()->addr,op,yystack_[0].value.as < op_binary_astnode* > ()->addr});
        yylhs.value.as < op_binary_astnode* > ()->addr = t1;

    }
}
#line 2352 "parser.tab.cc"
    break;

  case 57: // relational_expression: additive_expression
#line 718 "parser.yy"
                                          {
    yylhs.value.as < op_binary_astnode* > () = yystack_[0].value.as < op_binary_astnode* > ();
    // std::cerr<<__LINE__<<$$->typeNode.typeName<<endl;
}
#line 2361 "parser.tab.cc"
    break;

  case 58: // relational_expression: relational_expression '<' additive_expression
#line 722 "parser.yy"
                                               {
    std::string op = "LT_OP?";
    if(Symbols::symTabStage>0){
        if(!op_binary_astnode::operandsCompatible(op,yystack_[2].value.as < op_binary_astnode* > (),yystack_[0].value.as < op_binary_astnode* > ())){
            error(yylhs.location,"Incompatible operands for "+op+": \""+yystack_[2].value.as < op_binary_astnode* > ()->typeNode.typeName+"\", \""+yystack_[0].value.as < op_binary_astnode* > ()->typeNode.typeName+"\"");
        }
        yylhs.value.as < op_binary_astnode* > () = new op_binary_astnode(op, yystack_[2].value.as < op_binary_astnode* > (), yystack_[0].value.as < op_binary_astnode* > ());
    }
    if(Symbols::symTabStage==2){
        op = op.substr(0,op.size()-1);
        std::string t1 = newtemp(typespec_astnode::intc);
        gen(troins::ass,troins::bop,{t1,yystack_[2].value.as < op_binary_astnode* > ()->addr,op,yystack_[0].value.as < op_binary_astnode* > ()->addr});
        yylhs.value.as < op_binary_astnode* > ()->addr = t1;
    }

}
#line 2382 "parser.tab.cc"
    break;

  case 59: // relational_expression: relational_expression '>' additive_expression
#line 738 "parser.yy"
                                               {
    std::string op = "GT_OP?";
    if(Symbols::symTabStage>0){
        if(!op_binary_astnode::operandsCompatible(op,yystack_[2].value.as < op_binary_astnode* > (),yystack_[0].value.as < op_binary_astnode* > ())){
            error(yylhs.location,"Incompatible operands for "+op+": \""+yystack_[2].value.as < op_binary_astnode* > ()->typeNode.typeName+"\", \""+yystack_[0].value.as < op_binary_astnode* > ()->typeNode.typeName+"\"");
        }
        yylhs.value.as < op_binary_astnode* > () = new op_binary_astnode(op, yystack_[2].value.as < op_binary_astnode* > (), yystack_[0].value.as < op_binary_astnode* > ());
    }
    if(Symbols::symTabStage==2){
        op = op.substr(0,op.size()-1);
        std::string t1 = newtemp(typespec_astnode::intc);
        gen(troins::ass,troins::bop,{t1,yystack_[2].value.as < op_binary_astnode* > ()->addr,op,yystack_[0].value.as < op_binary_astnode* > ()->addr});
        yylhs.value.as < op_binary_astnode* > ()->addr = t1;

    }
}
#line 2403 "parser.tab.cc"
    break;

  case 60: // relational_expression: relational_expression LE_OP additive_expression
#line 754 "parser.yy"
                                                 {
    std::string op = "LE_OP?";
    if(Symbols::symTabStage>0){
        if(!op_binary_astnode::operandsCompatible(op,yystack_[2].value.as < op_binary_astnode* > (),yystack_[0].value.as < op_binary_astnode* > ())){
            error(yylhs.location,"Incompatible operands for "+op+": \""+yystack_[2].value.as < op_binary_astnode* > ()->typeNode.typeName+"\", \""+yystack_[0].value.as < op_binary_astnode* > ()->typeNode.typeName+"\"");
        }
        yylhs.value.as < op_binary_astnode* > () = new op_binary_astnode(op, yystack_[2].value.as < op_binary_astnode* > (), yystack_[0].value.as < op_binary_astnode* > ());
    }
    if(Symbols::symTabStage==2){
        op = op.substr(0,op.size()-1);
        std::string t1 = newtemp(typespec_astnode::intc);
        gen(troins::ass,troins::bop,{t1,yystack_[2].value.as < op_binary_astnode* > ()->addr,op,yystack_[0].value.as < op_binary_astnode* > ()->addr});
        yylhs.value.as < op_binary_astnode* > ()->addr = t1;

    }
}
#line 2424 "parser.tab.cc"
    break;

  case 61: // relational_expression: relational_expression GE_OP additive_expression
#line 770 "parser.yy"
                                                 {
    std::string op = "GE_OP?";
    if(Symbols::symTabStage>0){
        if(!op_binary_astnode::operandsCompatible(op,yystack_[2].value.as < op_binary_astnode* > (),yystack_[0].value.as < op_binary_astnode* > ())){
            error(yylhs.location,"Incompatible operands for "+op+": \""+yystack_[2].value.as < op_binary_astnode* > ()->typeNode.typeName+"\", \""+yystack_[0].value.as < op_binary_astnode* > ()->typeNode.typeName+"\"");
        }
        yylhs.value.as < op_binary_astnode* > () = new op_binary_astnode(op, yystack_[2].value.as < op_binary_astnode* > (), yystack_[0].value.as < op_binary_astnode* > ());
    }
    if(Symbols::symTabStage==2){
        op = op.substr(0,op.size()-1);
        std::string t1 = newtemp(typespec_astnode::intc);
        gen(troins::ass,troins::bop,{t1,yystack_[2].value.as < op_binary_astnode* > ()->addr,op,yystack_[0].value.as < op_binary_astnode* > ()->addr});
        yylhs.value.as < op_binary_astnode* > ()->addr = t1;

    }
}
#line 2445 "parser.tab.cc"
    break;

  case 62: // additive_expression: multiplicative_expression
#line 788 "parser.yy"
                                              {
    yylhs.value.as < op_binary_astnode* > () = yystack_[0].value.as < op_binary_astnode* > ();
    // std::cerr<<__LINE__<<$$->typeNode.typeName<<endl;
}
#line 2454 "parser.tab.cc"
    break;

  case 63: // additive_expression: additive_expression '+' multiplicative_expression
#line 792 "parser.yy"
                                                   {
    if(Symbols::symTabStage!=0){
        std::string op = "PLUS?";
        if(!op_binary_astnode::operandsCompatible(op,yystack_[2].value.as < op_binary_astnode* > (),yystack_[0].value.as < op_binary_astnode* > ())){
            error(yylhs.location,"Incompatible operands for "+op+": \""+yystack_[2].value.as < op_binary_astnode* > ()->typeNode.typeName+"\", \""+yystack_[0].value.as < op_binary_astnode* > ()->typeNode.typeName+"\"");
        }
        yylhs.value.as < op_binary_astnode* > () = new op_binary_astnode(op, yystack_[2].value.as < op_binary_astnode* > (), yystack_[0].value.as < op_binary_astnode* > ());
    }
    if(Symbols::symTabStage==2){
        yylhs.value.as < op_binary_astnode* > ()->addr = newtemp(typespec_astnode::intc);
        gen(troins::ass,troins::bop,{yylhs.value.as < op_binary_astnode* > ()->addr,yystack_[2].value.as < op_binary_astnode* > ()->addr,"+",yystack_[0].value.as < op_binary_astnode* > ()->addr});
    }
}
#line 2472 "parser.tab.cc"
    break;

  case 64: // additive_expression: additive_expression '-' multiplicative_expression
#line 805 "parser.yy"
                                                   {
    if(Symbols::symTabStage>0){
        std::string op = "MINUS?";
        if(!op_binary_astnode::operandsCompatible(op,yystack_[2].value.as < op_binary_astnode* > (),yystack_[0].value.as < op_binary_astnode* > ())){
            error(yylhs.location,"Incompatible operands for "+op+": \""+yystack_[2].value.as < op_binary_astnode* > ()->typeNode.typeName+"\", \""+yystack_[0].value.as < op_binary_astnode* > ()->typeNode.typeName+"\"");
        }
        yylhs.value.as < op_binary_astnode* > () = new op_binary_astnode(op, yystack_[2].value.as < op_binary_astnode* > (), yystack_[0].value.as < op_binary_astnode* > ());
    }
    if(Symbols::symTabStage==2){
        yylhs.value.as < op_binary_astnode* > ()->addr = newtemp(typespec_astnode::intc);
        gen(troins::ass,troins::bop,{yylhs.value.as < op_binary_astnode* > ()->addr,yystack_[2].value.as < op_binary_astnode* > ()->addr,"-",yystack_[0].value.as < op_binary_astnode* > ()->addr});
    }
}
#line 2490 "parser.tab.cc"
    break;

  case 65: // unary_expression: postfix_expression
#line 820 "parser.yy"
                                    {
    yylhs.value.as < exp_astnode* > () = yystack_[0].value.as < exp_astnode* > ();
    // std::cerr<<__LINE__<<$$->typeNode.typeName<<endl;
}
#line 2499 "parser.tab.cc"
    break;

  case 66: // unary_expression: unary_operator unary_expression
#line 824 "parser.yy"
                                 {
    if(Symbols::symTabStage!=0){
        //validity checks.
        std::string op = yystack_[1].value.as < std::string > ();
        if(!op_unary_astnode::compatibleOperand(yystack_[1].value.as < std::string > (),yystack_[0].value.as < exp_astnode* > ())){
            error(yylhs.location,"Incompatible operand for "+op+": \""+yystack_[0].value.as < exp_astnode* > ()->typeNode.typeName+"\"");
        }
        yylhs.value.as < exp_astnode* > () = new op_unary_astnode(yystack_[1].value.as < std::string > (), yystack_[0].value.as < exp_astnode* > ());
        if(yystack_[1].value.as < std::string > ()=="ADDRESS"||yystack_[1].value.as < std::string > ()=="DEREF"){
            if(yystack_[1].value.as < std::string > ()=="ADDRESS"&&(!yystack_[0].value.as < exp_astnode* > ()->typeNode.islval)){
                error(yylhs.location,"Tried to get address of rval: "+yystack_[0].value.as < exp_astnode* > ()->typeNode.typeName);
            }
            if(yylhs.value.as < exp_astnode* > ()->typeNode.typeName==yystack_[0].value.as < exp_astnode* > ()->typeNode.typeName){
                error(yylhs.location,"Invalid operand type \"" + yystack_[0].value.as < exp_astnode* > ()->typeNode.typeName +"\" of unary *");
            }
            int nrs = yystack_[0].value.as < exp_astnode* > ()->typeNode.numptrstars + yystack_[0].value.as < exp_astnode* > ()->typeNode.arrsizes.size();
            if(yystack_[1].value.as < std::string > ()=="DEREF"&&yystack_[0].value.as < exp_astnode* > ()->typeNode.typeName.substr(0,4)=="void"&&(nrs==1)){
                error(yylhs.location,"Dereferenced incomplete type void*");
            }
        }
    }
    if(Symbols::symTabStage==2){
        std::string t0;
        string op = unopName(yystack_[1].value.as < std::string > (),true);
        if(yystack_[0].value.as < exp_astnode* > ()->isproxyaddr||yystack_[0].value.as < exp_astnode* > ()->iselem){
            typespec_astnode tn = yystack_[0].value.as < exp_astnode* > ()->typeNode;
            if(op=="&"){
                yylhs.value.as < exp_astnode* > ()->addr = yystack_[0].value.as < exp_astnode* > ()->addr;//$$ isproxy addr is false.
            }
            else if(op=="*"){
                tn.deref();
                t0 = newtemp(tn);
                gen(troins::ass,troins::uop,{t0,"*",yystack_[0].value.as < exp_astnode* > ()->addr});
                yylhs.value.as < exp_astnode* > ()->isproxyaddr = true;
                yylhs.value.as < exp_astnode* > ()->addr = t0;
            }
            else{
                tn.deref();
                t0 = newtemp(tn);
                gen(troins::ass,troins::uop,{t0,"*",yystack_[0].value.as < exp_astnode* > ()->addr});
                typespec_astnode tn = Symbols::getSymEntry(ststack.top(),t0,false)->type;
                yylhs.value.as < exp_astnode* > ()->addr = newtemp(tn);
                gen(troins::ass,troins::uop,{yylhs.value.as < exp_astnode* > ()->addr,op,t0});
                if(op=="!"){
                    yylhs.value.as < exp_astnode* > ()->fl = yystack_[0].value.as < exp_astnode* > ()->tl;
                    yylhs.value.as < exp_astnode* > ()->tl = yystack_[0].value.as < exp_astnode* > ()->fl;
                    yylhs.value.as < exp_astnode* > ()->ifgened = true;
                }
            }
        }
        else{
            typespec_astnode tn = yystack_[0].value.as < exp_astnode* > ()->typeNode;
            if(op=="&"){
                tn.addressOf();
                t0 = newtemp(tn);
                gen(troins::ass,troins::uop,{t0,"&",yystack_[0].value.as < exp_astnode* > ()->addr});
                yylhs.value.as < exp_astnode* > ()->addr = t0;//$$ isproxy addr is false.
            }
            else if(op=="*"){
                yylhs.value.as < exp_astnode* > ()->isproxyaddr = true;
                yylhs.value.as < exp_astnode* > ()->addr = yystack_[0].value.as < exp_astnode* > ()->addr;
            }
            else{
                t0 = yystack_[0].value.as < exp_astnode* > ()->addr;
                SymEntry * tmpse = Symbols::getSymEntry(ststack.top(),t0,false);
                typespec_astnode tn;
                if(tmpse){
                     tn = tmpse->type;
                }
                else{
                    tn = typespec_astnode::intc;
                }
                yylhs.value.as < exp_astnode* > ()->addr = newtemp(tn);
                gen(troins::ass,troins::uop,{yylhs.value.as < exp_astnode* > ()->addr,op,t0});
                if(op=="!"){
                    yylhs.value.as < exp_astnode* > ()->fl = yystack_[0].value.as < exp_astnode* > ()->tl;
                    yylhs.value.as < exp_astnode* > ()->tl = yystack_[0].value.as < exp_astnode* > ()->fl;
                    yylhs.value.as < exp_astnode* > ()->ifgened = true;
                }
            }
        }
    }
}
#line 2587 "parser.tab.cc"
    break;

  case 67: // multiplicative_expression: unary_expression
#line 909 "parser.yy"
                                           {
    if(Symbols::symTabStage!=0){   
        yylhs.value.as < op_binary_astnode* > () = (op_binary_astnode*) yystack_[0].value.as < exp_astnode* > ();
    }
    if(Symbols::symTabStage==2){
        yylhs.value.as < op_binary_astnode* > ()->addr = Symbols::resolveProxies(yystack_[0].value.as < exp_astnode* > (),code,ststack.top());
        yylhs.value.as < op_binary_astnode* > ()->isproxyaddr = false;
        yylhs.value.as < op_binary_astnode* > ()->iselem = false;
    }
}
#line 2602 "parser.tab.cc"
    break;

  case 68: // multiplicative_expression: multiplicative_expression '*' unary_expression
#line 919 "parser.yy"
                                                {
    //operator and expression match check here.
    if(Symbols::symTabStage!=0){
        std::string op = "MULT?";
        if(!op_binary_astnode::operandsCompatible(op,yystack_[2].value.as < op_binary_astnode* > (),yystack_[0].value.as < exp_astnode* > ())){
            error(yylhs.location,"Incompatible operands for "+op+": \""+yystack_[2].value.as < op_binary_astnode* > ()->typeNode.typeName+"\", \""+yystack_[0].value.as < exp_astnode* > ()->typeNode.typeName+"\"");
        }
        yylhs.value.as < op_binary_astnode* > () = new op_binary_astnode(op, yystack_[2].value.as < op_binary_astnode* > (), yystack_[0].value.as < exp_astnode* > ());
    }
    if(Symbols::symTabStage==2){
        yystack_[0].value.as < exp_astnode* > ()->addr = Symbols::resolveProxies(yystack_[0].value.as < exp_astnode* > (),code,ststack.top());
        yylhs.value.as < op_binary_astnode* > ()->addr = newtemp(typespec_astnode::intc);
        gen(troins::ass,troins::bop,{yylhs.value.as < op_binary_astnode* > ()->addr,yystack_[2].value.as < op_binary_astnode* > ()->addr,"*",yystack_[0].value.as < exp_astnode* > ()->addr});
    }
}
#line 2622 "parser.tab.cc"
    break;

  case 69: // multiplicative_expression: multiplicative_expression '/' unary_expression
#line 934 "parser.yy"
                                                {
    if(Symbols::symTabStage!=0){
        std::string op = "DIV?";
        if(!op_binary_astnode::operandsCompatible(op,yystack_[2].value.as < op_binary_astnode* > (),yystack_[0].value.as < exp_astnode* > ())){
            error(yylhs.location,"Incompatible operands for "+op+": \""+yystack_[2].value.as < op_binary_astnode* > ()->typeNode.typeName+"\", \""+yystack_[0].value.as < exp_astnode* > ()->typeNode.typeName+"\"");
        }
        yylhs.value.as < op_binary_astnode* > () = new op_binary_astnode(op, yystack_[2].value.as < op_binary_astnode* > (), yystack_[0].value.as < exp_astnode* > ());
    }
    if(Symbols::symTabStage==2){
        yystack_[0].value.as < exp_astnode* > ()->addr = Symbols::resolveProxies(yystack_[0].value.as < exp_astnode* > (),code,ststack.top());
        yylhs.value.as < op_binary_astnode* > ()->addr = newtemp(typespec_astnode::intc);
        gen(troins::ass,troins::bop,{yylhs.value.as < op_binary_astnode* > ()->addr,yystack_[2].value.as < op_binary_astnode* > ()->addr,"/",yystack_[0].value.as < exp_astnode* > ()->addr});
    }
}
#line 2641 "parser.tab.cc"
    break;

  case 70: // postfix_expression: primary_expression
#line 950 "parser.yy"
                                      {
    yylhs.value.as < exp_astnode* > () = yystack_[0].value.as < exp_astnode* > ();
}
#line 2649 "parser.tab.cc"
    break;

  case 71: // postfix_expression: postfix_expression '[' expression ']'
#line 953 "parser.yy"
                                       {
    if(Symbols::symTabStage!=0){
        if(yystack_[3].value.as < exp_astnode* > ()->typeNode.typeName.substr(0,4)=="void"){
            error(yylhs.location,"Tried to dereference an incomplete type.");
        }
        if(yystack_[3].value.as < exp_astnode* > ()->typeNode.numptrstars + yystack_[3].value.as < exp_astnode* > ()->typeNode.arrsizes.size()==0){
            error(yylhs.location, "Tried to dereference a non-pointer");
        }
        if(yystack_[1].value.as < exp_astnode* > ()->typeNode.typeName!="int"){
            error(yylhs.location, "Argument passed to operator[] must be of type int.");
        }
        yylhs.value.as < exp_astnode* > () = new arrayref_astnode(yystack_[3].value.as < exp_astnode* > (), yystack_[1].value.as < exp_astnode* > ());
    }
    if(Symbols::symTabStage==2){
        /*
        t1 = $1->addr
        type = $1->typeNode
        type.deref()
        t2 = newTemp(); gen(t2 = expression.addr '*' type.typeWidth)
        gen: t3 = t1 + t2
        */
        typespec_astnode tmp = yystack_[3].value.as < exp_astnode* > ()->typeNode;tmp.deref();
        std::string t0;
        if(yystack_[3].value.as < exp_astnode* > ()->isproxyaddr||yystack_[3].value.as < exp_astnode* > ()->iselem){
            t0 = yystack_[3].value.as < exp_astnode* > ()->addr;
        }
        else{
            typespec_astnode tn = yystack_[3].value.as < exp_astnode* > ()->typeNode;
            tn.addressOf();
            t0 = newtemp(tn);
            gen(troins::ass,troins::uop,{t0,"&",yystack_[3].value.as < exp_astnode* > ()->addr});
        }
        string t1 = newtemp(typespec_astnode::intc);
        gen(troins::ass,troins::bop,{t1, to_string(tmp.typeWidth),"*",yystack_[1].value.as < exp_astnode* > ()->addr});
        typespec_astnode tn = Symbols::getSymEntry(ststack.top(),t0,false)->type;
        string t2 = newtemp(tn);
        gen(troins::ass,troins::bop,{t2, t0, "+", t1});
        yylhs.value.as < exp_astnode* > ()->addr = t2;
        yylhs.value.as < exp_astnode* > ()->iselem = true;
    }

}
#line 2696 "parser.tab.cc"
    break;

  case 72: // postfix_expression: IDENTIFIER '(' ')'
#line 995 "parser.yy"
                    {
    if (Symbols::symTabStage>0) {
        std::string function_name = yystack_[2].value.as < std::string > ();
        if(!(yystack_[2].value.as < std::string > ()=="printf"||yystack_[2].value.as < std::string > ()=="scanf")){
            SymTab* fstab = Symbols::flsts[function_name];
            if (fstab == nullptr) {
                error(yylhs.location, "Procedure \"" + yystack_[2].value.as < std::string > () + "\" not declared");
            }
            std::set<std::pair<long long, std::string>> expected;
            for (auto row: fstab->rows) {
                if (row.second.lpgtype == SymTab::PARAM) {
                    expected.insert(std::make_pair(row.second.offset, row.second.type.typeName));
                }
            }
            if (!expected.empty()) {
                error(yylhs.location, "Procedure \"" + yystack_[2].value.as < std::string > () + "\" called with too few arguments");
            }
            yylhs.value.as < exp_astnode* > () = new funcall_astnode(new identifier_astnode(yystack_[2].value.as < std::string > ()), std::vector<exp_astnode*>(), false);
            yylhs.value.as < exp_astnode* > ()->typeNode = Symbols::getSymEntry(Symbols::gst, yystack_[2].value.as < std::string > ())->type;
        }
        else {
            yylhs.value.as < exp_astnode* > () = new funcall_astnode(new identifier_astnode(yystack_[2].value.as < std::string > ()), std::vector<exp_astnode*>(), false);
            yylhs.value.as < exp_astnode* > ()->typeNode = voidc;
        }
    }
    if(Symbols::symTabStage==2){
        typespec_astnode tn = Symbols::getSymEntry(ststack.top(),yystack_[2].value.as < std::string > (),false)->type;
        yylhs.value.as < exp_astnode* > ()->addr = newtemp(tn);
        gen(troins::ass,troins::call,{yylhs.value.as < exp_astnode* > ()->addr,yystack_[2].value.as < std::string > (),"0"});
    }
}
#line 2732 "parser.tab.cc"
    break;

  case 73: // postfix_expression: IDENTIFIER '(' expression_list ')'
#line 1026 "parser.yy"
                                    {
    std::reverse(yystack_[1].value.as < std::vector<exp_astnode*> > ().begin(),yystack_[1].value.as < std::vector<exp_astnode*> > ().end());
    if (Symbols::symTabStage>0) {
        std::string function_name = yystack_[3].value.as < std::string > ();
        if(!(yystack_[3].value.as < std::string > ()=="printf"||yystack_[3].value.as < std::string > ()=="scanf")){
            SymTab* fstab = Symbols::flsts[function_name];
            std::set<std::pair<long long, typespec_astnode>,struct offsetcomp> expected;
            for (auto row: fstab->rows) {
                if (row.second.lpgtype == SymTab::PARAM) {
                    expected.insert(std::make_pair(row.second.offset, row.second.type));
                }
            }
            if (yystack_[1].value.as < std::vector<exp_astnode*> > ().size() < expected.size()) {
                error(yylhs.location, "Procedure \"" + yystack_[3].value.as < std::string > () + "\" called with too few arguments");
            }
            else if (yystack_[1].value.as < std::vector<exp_astnode*> > ().size() > expected.size()) {
                error(yylhs.location, "Procedure \"" + yystack_[3].value.as < std::string > () + "\" called with too many arguments");
            }
            std::vector<exp_astnode*> exp_list = yystack_[1].value.as < std::vector<exp_astnode*> > ();
            // std::reverse(exp_list.begin(), exp_list.end());
            int i = 0;
            for (auto item: expected) {
                if (!item.second.compatibleWith(exp_list[i]->typeNode,true)) {
                    error(yylhs.location, "Expected \"" + item.second.typeName + "\" but argument is of type \"" + exp_list[i]->typeNode.typeName + "\"");
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
            // std::reverse(exp_list.begin(),exp_list.end());
            yylhs.value.as < exp_astnode* > () = new funcall_astnode(new identifier_astnode(yystack_[3].value.as < std::string > ()), exp_list, false);
            yylhs.value.as < exp_astnode* > ()->typeNode = Symbols::getSymEntry(Symbols::gst, yystack_[3].value.as < std::string > ())->type;
        }
        else {
            yylhs.value.as < exp_astnode* > () = new funcall_astnode(new identifier_astnode(yystack_[3].value.as < std::string > ()), yystack_[1].value.as < std::vector<exp_astnode*> > (), false);
            yylhs.value.as < exp_astnode* > ()->typeNode = voidc;
        }
    }
    if(Symbols::symTabStage==2){
        typespec_astnode tn = Symbols::getSymEntry(ststack.top(),yystack_[3].value.as < std::string > (),false)->type;
        yylhs.value.as < exp_astnode* > ()->addr = newtemp(tn);
        for(exp_astnode* prm:yystack_[1].value.as < std::vector<exp_astnode*> > ()){
            gen(troins::func,troins::param,{prm->addr});
        }
        gen(troins::ass,troins::call,{yylhs.value.as < exp_astnode* > ()->addr,yystack_[3].value.as < std::string > (),to_string(yystack_[1].value.as < std::vector<exp_astnode*> > ().size())});
    }
}
#line 2789 "parser.tab.cc"
    break;

  case 74: // postfix_expression: postfix_expression '.' IDENTIFIER
#line 1078 "parser.yy"
                                   {
    //fix offset 
    std::string structName;
    if(Symbols::symTabStage!=0){
        if(yystack_[2].value.as < exp_astnode* > ()->typeNode.typeName.substr(0,6)!="struct"){
            error(yylhs.location,"LHS of . must be of type struct.");
        }
        yylhs.value.as < exp_astnode* > () = new member_astnode(yystack_[2].value.as < exp_astnode* > (), new identifier_astnode(yystack_[0].value.as < std::string > ()));
        structName = yystack_[2].value.as < exp_astnode* > ()->typeNode.typeName;
        // std::cerr<<"symtab constr, structname: "<<structName<<std::endl;
        SymEntry* memberEntry = Symbols::getSymEntry(Symbols::slsts[structName],yystack_[0].value.as < std::string > (),true);
        if(memberEntry){
            yylhs.value.as < exp_astnode* > ()->typeNode = memberEntry->type;
        }
        else{
            string errormsg = "Member "+yystack_[0].value.as < std::string > ()+" not found in "+structName;
            error(yylhs.location,errormsg);
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
        string offset = to_string(Symbols::getOffsetInStruct(structName,yystack_[0].value.as < std::string > ()));
        typespec_astnode tn = yystack_[2].value.as < exp_astnode* > ()->typeNode;
        if(!(yystack_[2].value.as < exp_astnode* > ()->isproxyaddr||yystack_[2].value.as < exp_astnode* > ()->iselem)){
            tn.addressOf();
            t1 = newtemp(tn);    
            gen(troins::ass,troins::uop,{t1,"&",yystack_[2].value.as < exp_astnode* > ()->addr});
        }
        else{
            t1 = yystack_[2].value.as < exp_astnode* > ()->addr;
        }
        SymEntry* memberEntry = Symbols::getSymEntry(Symbols::slsts[structName],yystack_[0].value.as < std::string > (),true);
        tn = memberEntry->type;
        tn.addressOf();
        string t2 = newtemp(tn);
        gen(troins::ass,troins::bop,{t2,t1,"+",offset});
        yylhs.value.as < exp_astnode* > ()->addr = t2;
        yylhs.value.as < exp_astnode* > ()->isproxyaddr=true;
    }
}
#line 2840 "parser.tab.cc"
    break;

  case 75: // postfix_expression: postfix_expression PTR_OP IDENTIFIER
#line 1124 "parser.yy"
                                      {
    //fix offset
    std::string structName;
    if(Symbols::symTabStage!=0){
        if(yystack_[2].value.as < exp_astnode* > ()->typeNode.typeName.substr(0,6)!="struct"){
            error(yylhs.location,"LHS of -> must be of type struct.");
        }
        yylhs.value.as < exp_astnode* > () = new arrow_astnode(yystack_[2].value.as < exp_astnode* > (), new identifier_astnode(yystack_[0].value.as < std::string > ()));
        typespec_astnode dereftype = yystack_[2].value.as < exp_astnode* > ()->typeNode;
        dereftype.deref();
        structName  = dereftype.typeName;
        yystack_[2].value.as < exp_astnode* > ()->typeNode.compatibleWith(dereftype);
        SymEntry* memberEntry = Symbols::getSymEntry(Symbols::slsts[structName],yystack_[0].value.as < std::string > (),true);
        if(memberEntry){
            yylhs.value.as < exp_astnode* > ()->typeNode = memberEntry->type;
        }
        else{
            string errormsg = "Member "+yystack_[0].value.as < std::string > ()+" not found in "+structName;
            error(yylhs.location,errormsg);
        }
    }
    if(Symbols::symTabStage==2){
        /*
        a.b
        t1 = a + offset
        */
        string t1;
        typespec_astnode tn = yystack_[2].value.as < exp_astnode* > ()->typeNode;
        if(yystack_[2].value.as < exp_astnode* > ()->isproxyaddr){
            tn.deref();
            t1 = newtemp(tn);
            gen(troins::ass,troins::uop,{t1,"*",yystack_[2].value.as < exp_astnode* > ()->addr});
        }
        else{
            t1 = yystack_[2].value.as < exp_astnode* > ()->addr;
        }
        string offset = to_string(Symbols::getOffsetInStruct(structName,yystack_[0].value.as < std::string > ()));
        SymEntry*memberEntry = Symbols::getSymEntry(Symbols::slsts[structName],yystack_[0].value.as < std::string > (),true);
        tn = memberEntry->type;
        tn.addressOf();
        string t2 = newtemp(tn);
        gen(troins::ass,troins::bop,{t2,t1,"+",offset});
        yylhs.value.as < exp_astnode* > ()->isproxyaddr = true;
        yylhs.value.as < exp_astnode* > ()->addr = t2;
    }
}
#line 2891 "parser.tab.cc"
    break;

  case 76: // postfix_expression: postfix_expression INC_OP
#line 1170 "parser.yy"
                           {
    //fix offset.
    if(Symbols::symTabStage>0){
        if(!(yystack_[1].value.as < exp_astnode* > ()->typeNode.islval)){
            error(yylhs.location,"Postfix operator "+yystack_[0].value.as < std::string > ()+" can only be applied to lvalues.");
        }
        if(!(yystack_[1].value.as < exp_astnode* > ()->typeNode.isNumeric()||(yystack_[1].value.as < exp_astnode* > ()->typeNode.numptrstars>0&&yystack_[1].value.as < exp_astnode* > ()->typeNode.arrsizes.size()==0))){
            error(yylhs.location,"Invalid data type for postfix operator "+yystack_[0].value.as < std::string > ());
        }
        yylhs.value.as < exp_astnode* > () = new op_unary_astnode("PP",yystack_[1].value.as < exp_astnode* > ());
        yylhs.value.as < exp_astnode* > ()->typeNode = yystack_[1].value.as < exp_astnode* > ()->typeNode;
        yylhs.value.as < exp_astnode* > ()->typeNode.islval = false;
    }
    if(Symbols::symTabStage==2){
        string t0;
        if(yystack_[1].value.as < exp_astnode* > ()->isproxyaddr||yystack_[1].value.as < exp_astnode* > ()->iselem){
            typespec_astnode tn = yystack_[1].value.as < exp_astnode* > ()->typeNode;
            tn.deref();
            t0 = newtemp(tn);
            gen(troins::ass,troins::uop,{t0,"*",yystack_[1].value.as < exp_astnode* > ()->addr});
        }
        else{
            t0 = yystack_[1].value.as < exp_astnode* > ()->addr;
        }
        string t = newtemp(yystack_[1].value.as < exp_astnode* > ()->typeNode);
        yylhs.value.as < exp_astnode* > ()->addr = t;
        gen(troins::ass,troins::na,{yylhs.value.as < exp_astnode* > ()->addr,t0});
        if(yystack_[1].value.as < exp_astnode* > ()->isproxyaddr||yystack_[1].value.as < exp_astnode* > ()->iselem){
            string t1 = newtemp(yystack_[1].value.as < exp_astnode* > ()->typeNode);
            gen(troins::ass,troins::bop,{t1,t0,"+","1"});
            gen(troins::ass,troins::ptrl,{yystack_[1].value.as < exp_astnode* > ()->addr,t1});            
        }
        else{
            gen(troins::ass,troins::bop,{yystack_[1].value.as < exp_astnode* > ()->addr,t0,"+","1"});
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
#line 2940 "parser.tab.cc"
    break;

  case 77: // primary_expression: IDENTIFIER
#line 1216 "parser.yy"
                              {
    if(Symbols::symTabStage!=0){
        //0 is pre symtab construction.
        yylhs.value.as < exp_astnode* > () = new identifier_astnode(yystack_[0].value.as < std::string > ());
        SymEntry * entry = Symbols::getSymEntry(ststack.top(),yystack_[0].value.as < std::string > ());
        if(!entry){
            std::string errormsg = "Variable \""+yystack_[0].value.as < std::string > ()+"\" not declared";
            error(yylhs.location,errormsg);
        }
        else{
            yylhs.value.as < exp_astnode* > ()->typeNode = entry->type;
            // std::cerr << __LINE__ << $$->typeNode.typeName<<std::endl;
        }
 
    }
    if(Symbols::symTabStage==2){
        yylhs.value.as < exp_astnode* > ()->addr = yystack_[0].value.as < std::string > ();
    }
    // std::cerr<<"bloom"<<std::endl;
}
#line 2965 "parser.tab.cc"
    break;

  case 78: // primary_expression: INT_CONSTANT
#line 1236 "parser.yy"
              {
    if(Symbols::symTabStage!=0){   
        yylhs.value.as < exp_astnode* > () = new intconst_astnode(yystack_[0].value.as < std::string > ());
        yylhs.value.as < exp_astnode* > ()->typeNode = intc;
        yylhs.value.as < exp_astnode* > ()->typeNode.islval = false;
        if(yystack_[0].value.as < std::string > ()=="0"){
            yylhs.value.as < exp_astnode* > ()->typeNode.isnullval = true;
        }
    }
    if(Symbols::symTabStage==2){
        yylhs.value.as < exp_astnode* > ()->addr = yystack_[0].value.as < std::string > ();
    }

}
#line 2984 "parser.tab.cc"
    break;

  case 79: // primary_expression: STRING_LITERAL
#line 1250 "parser.yy"
                {
    if(Symbols::symTabStage!=0){   
        yylhs.value.as < exp_astnode* > () = new stringconst_astnode(yystack_[0].value.as < std::string > ());
        yylhs.value.as < exp_astnode* > ()->typeNode = stringc;
        yylhs.value.as < exp_astnode* > ()->typeNode.islval = false;
        // $$->print();
    }
    if(Symbols::symTabStage==2){
        yylhs.value.as < exp_astnode* > ()->addr = Symbols::newStrLit(yystack_[0].value.as < std::string > ());
    }
}
#line 3000 "parser.tab.cc"
    break;

  case 80: // primary_expression: '(' expression ')'
#line 1261 "parser.yy"
                    {
    yylhs.value.as < exp_astnode* > () = yystack_[1].value.as < exp_astnode* > ();
}
#line 3008 "parser.tab.cc"
    break;

  case 81: // expression_list: expression
#line 1266 "parser.yy"
                           {
    yylhs.value.as < std::vector<exp_astnode*> > () = std::vector<exp_astnode*>();
    yylhs.value.as < std::vector<exp_astnode*> > ().push_back(yystack_[0].value.as < exp_astnode* > ());
}
#line 3017 "parser.tab.cc"
    break;

  case 82: // expression_list: expression_list ',' expression
#line 1270 "parser.yy"
                                {
    yystack_[2].value.as < std::vector<exp_astnode*> > ().push_back(yystack_[0].value.as < exp_astnode* > ());
    yylhs.value.as < std::vector<exp_astnode*> > () = yystack_[2].value.as < std::vector<exp_astnode*> > ();
}
#line 3026 "parser.tab.cc"
    break;

  case 83: // unary_operator: '-'
#line 1275 "parser.yy"
                   {
    yylhs.value.as < std::string > () = unopName("-");
}
#line 3034 "parser.tab.cc"
    break;

  case 84: // unary_operator: '!'
#line 1278 "parser.yy"
    {
    yylhs.value.as < std::string > () = unopName("!");

}
#line 3043 "parser.tab.cc"
    break;

  case 85: // unary_operator: '&'
#line 1282 "parser.yy"
    {
    yylhs.value.as < std::string > () = unopName("&");

}
#line 3052 "parser.tab.cc"
    break;

  case 86: // unary_operator: '*'
#line 1286 "parser.yy"
    {
    yylhs.value.as < std::string > () = unopName("*");
}
#line 3060 "parser.tab.cc"
    break;

  case 87: // $@5: %empty
#line 1291 "parser.yy"
                        {
    if(Symbols::symTabStage==2){
        code.condcode = true;
        code.condtype = ".if_cond";
    }
}
#line 3071 "parser.tab.cc"
    break;

  case 88: // $@6: %empty
#line 1296 "parser.yy"
                     {
    if(Symbols::symTabStage==2){
        code.condcode = false;
        code.condtype = "";
        std::string label = ".if_stmt_"+code.newLabel();
        code.setLabel(label);
        code.backpatch(yystack_[1].value.as < exp_astnode* > ()->tl,label);
    }
}
#line 3085 "parser.tab.cc"
    break;

  case 89: // $@7: %empty
#line 1304 "parser.yy"
            {
    if(Symbols::symTabStage==2){
        
        yystack_[0].value.as < statement_astnode* > ()->next = {code.nextinstr()};
        gen(troins::gt,troins::na,{""});
    }
}
#line 3097 "parser.tab.cc"
    break;

  case 90: // $@8: %empty
#line 1310 "parser.yy"
       {
    if(Symbols::symTabStage==2){
        std::string label = ".else_stmt"+code.newLabel();
        code.setLabel(label);
        code.backpatch(yystack_[5].value.as < exp_astnode* > ()->fl,label);
        gen(troins::nop,troins::na,{});
    }
}
#line 3110 "parser.tab.cc"
    break;

  case 91: // selection_statement: IF $@5 '(' expression ')' $@6 statement $@7 ELSE $@8 statement
#line 1317 "parser.yy"
           {
    if(Symbols::symTabStage>0){  
        if(!(yystack_[7].value.as < exp_astnode* > ()->typeNode.isNumeric()||yystack_[7].value.as < exp_astnode* > ()->typeNode.getnrs()>0)){
            error(yylhs.location,"Invalid type for condition expression in for loop");
        }    
        yylhs.value.as < statement_astnode* > () = new if_astnode(yystack_[7].value.as < exp_astnode* > (), yystack_[4].value.as < statement_astnode* > (), yystack_[0].value.as < statement_astnode* > ());
    }
    if(Symbols::symTabStage==2){
        std::string label=".if_exit_"+code.newLabel();
        code.setLabel(label);
        gen(troins::nop,troins::na,{});
        code.backpatch(yystack_[4].value.as < statement_astnode* > ()->next,label);
    }
}
#line 3129 "parser.tab.cc"
    break;

  case 92: // $@9: %empty
#line 1333 "parser.yy"
                           {
    if(Symbols::symTabStage==2){
        code.condtype=".while_cond";
        code.condcode = true;
    }
}
#line 3140 "parser.tab.cc"
    break;

  case 93: // $@10: %empty
#line 1338 "parser.yy"
                            {
    if(Symbols::symTabStage==2){
        code.condtype=".while_stmt";
    }
}
#line 3150 "parser.tab.cc"
    break;

  case 94: // $@11: %empty
#line 1342 "parser.yy"
         {
    if(Symbols::symTabStage==2){
        code.condcode=false;
        code.condtype="";
        gen(troins::nop,troins::na,{});
    }
}
#line 3162 "parser.tab.cc"
    break;

  case 95: // iteration_statement: WHILE $@9 mnterm '(' expression ')' $@10 mnterm $@11 statement
#line 1348 "parser.yy"
           {
    if(Symbols::symTabStage>0){   
        if(!(yystack_[5].value.as < exp_astnode* > ()->typeNode.isNumeric()||yystack_[5].value.as < exp_astnode* > ()->typeNode.getnrs()>0)){
            error(yylhs.location,"Invalid type for condition expression in while loop");
        }   
        yylhs.value.as < statement_astnode* > () = new while_astnode(yystack_[5].value.as < exp_astnode* > (), yystack_[0].value.as < statement_astnode* > ());
    }
    if(Symbols::symTabStage==2){
        code.backpatch(yystack_[5].value.as < exp_astnode* > ()->tl,yystack_[2].value.as < mnt* > ()->nil);
        gen(troins::gt,troins::na,{yystack_[7].value.as < mnt* > ()->nil});
        std::string label = ".while_exit_"+code.newLabel();
        code.setLabel(label);
        code.backpatch(yystack_[5].value.as < exp_astnode* > ()->fl,label);
    }
}
#line 3182 "parser.tab.cc"
    break;

  case 96: // $@12: %empty
#line 1363 "parser.yy"
                                     {
    if(Symbols::symTabStage==2){
        code.condcode=true;
        code.condtype=".for_cond";
    }
}
#line 3193 "parser.tab.cc"
    break;

  case 97: // $@13: %empty
#line 1368 "parser.yy"
                              {
    if(Symbols::symTabStage==2){
        code.condtype=".for_incrementor";
    }
}
#line 3203 "parser.tab.cc"
    break;

  case 98: // $@14: %empty
#line 1372 "parser.yy"
             {
    if(Symbols::symTabStage==2){
        code.condcode=false;
        code.condtype="";
    }
}
#line 3214 "parser.tab.cc"
    break;

  case 99: // $@15: %empty
#line 1377 "parser.yy"
                               {
    if(Symbols::symTabStage==2){
        gen(troins::gt,troins::na,{yystack_[7].value.as < mnt* > ()->nil});
        code.condcode = true;
        code.condtype = ".for_stmt";
    }
}
#line 3226 "parser.tab.cc"
    break;

  case 100: // $@16: %empty
#line 1383 "parser.yy"
         {
    if(Symbols::symTabStage==2){
        code.condcode = false;
        code.condtype = "";
        gen(troins::nop,troins::na,{});
    }
}
#line 3238 "parser.tab.cc"
    break;

  case 101: // iteration_statement: FOR '(' assignment_expression ';' $@12 mnterm expression $@13 mnterm $@14 ';' assignment_expression ')' $@15 mnterm $@16 statement
#line 1389 "parser.yy"
           {
    if(Symbols::symTabStage>0){
        if(!(yystack_[10].value.as < exp_astnode* > ()->typeNode.isNumeric()||yystack_[10].value.as < exp_astnode* > ()->typeNode.getnrs()>0)){
            error(yylhs.location,"Invalid type for condition expression in for loop");
        }   
        yylhs.value.as < statement_astnode* > () = new for_astnode(yystack_[14].value.as < assignE_astnode* > (), yystack_[10].value.as < exp_astnode* > (), yystack_[5].value.as < assignE_astnode* > (), yystack_[0].value.as < statement_astnode* > ());
    }
    if(Symbols::symTabStage==2){
        code.backpatch(yystack_[10].value.as < exp_astnode* > ()->tl,yystack_[2].value.as < mnt* > ()->nil);
        gen(troins::gt,troins::na,{yystack_[8].value.as < mnt* > ()->nil});
        std::string label = ".for_exit_"+code.newLabel();
        code.setLabel(label);
        code.backpatch(yystack_[10].value.as < exp_astnode* > ()->fl,label);
    }
}
#line 3258 "parser.tab.cc"
    break;

  case 102: // declaration_list: declaration
#line 1406 "parser.yy"
                             {
}
#line 3265 "parser.tab.cc"
    break;

  case 103: // declaration_list: declaration_list declaration
#line 1408 "parser.yy"
                              {
}
#line 3272 "parser.tab.cc"
    break;

  case 104: // declaration: type_specifier declarator_list ';'
#line 1412 "parser.yy"
                                               {
}
#line 3279 "parser.tab.cc"
    break;

  case 105: // declarator_list: declarator
#line 1416 "parser.yy"
                           {
    yylhs.value.as < typespec_astnode > () = yystack_[0].value.as < typespec_astnode > ();
    // std::cerr<<$1.typeName<<" has "<<$1.numptrstars<<" stars"<<std::endl;
    string type = yystack_[0].value.as < typespec_astnode > ().typeName;
    int size = yystack_[0].value.as < typespec_astnode > ().typeWidth;
    if(Symbols::symTabStage==0){
        // std::cerr<<topvarname<<": "<<size<<" "<<std::endl;
        int offset = ststack.top()->getNewOffset(size);
        SymTab* st = ststack.top();
        if(yystack_[0].value.as < typespec_astnode > ().typeName=="void"){
            error(yylhs.location,"Cannot declare variable of type \"void\"");
        }
        st->rows[topvarname] = SymEntry(yystack_[0].value.as < typespec_astnode > (),SymTab::ST_HL_type::VAR,SymTab::ST_LPG::LOCAL,size,offset);
    }
}
#line 3299 "parser.tab.cc"
    break;

  case 106: // declarator_list: declarator_list ',' declarator
#line 1431 "parser.yy"
                                {
    yylhs.value.as < typespec_astnode > () = yystack_[0].value.as < typespec_astnode > ();
    string type = yystack_[0].value.as < typespec_astnode > ().typeName;
    int size = yystack_[0].value.as < typespec_astnode > ().typeWidth;
    if(Symbols::symTabStage==0){
        if(yystack_[0].value.as < typespec_astnode > ().typeName=="void"){
            error(yylhs.location,"Cannot declare variable of type \"void\"");
        }
        int offset = ststack.top()->getNewOffset(size);
        ststack.top()->rows[topvarname] = SymEntry(yystack_[0].value.as < typespec_astnode > (),SymTab::ST_HL_type::VAR,SymTab::ST_LPG::LOCAL,size,offset);
    }
}
#line 3316 "parser.tab.cc"
    break;


#line 3320 "parser.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        std::string msg = YY_("syntax error");
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
  Parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0









  const signed char Parser::yypact_ninf_ = -109;

  const signed char Parser::yytable_ninf_ = -18;

  const short
  Parser::yypact_[] =
  {
    -109,    28,   101,  -109,  -109,    35,    25,  -109,  -109,   101,
    -109,  -109,    64,     3,    73,  -109,  -109,  -109,    32,    34,
      55,    50,    83,   154,  -109,  -109,   119,  -109,   119,  -109,
     106,    79,  -109,  -109,  -109,    95,  -109,   108,   275,  -109,
    -109,   275,   107,  -109,  -109,  -109,  -109,     9,    58,  -109,
    -109,   113,  -109,  -109,   120,    22,  -109,   275,  -109,  -109,
     192,  -109,    34,     8,     9,    62,  -109,  -109,    14,   112,
     149,  -109,   275,   131,    -2,  -109,   156,    78,    15,    72,
    -109,    80,    37,   215,  -109,     9,   129,  -109,   -16,  -109,
    -109,  -109,   275,  -109,   165,   275,   167,  -109,  -109,   238,
    -109,  -109,   141,  -109,  -109,   119,   142,   176,   100,   275,
     104,   159,   145,   261,  -109,  -109,  -109,   275,   275,   275,
     275,   275,   275,   275,   275,   275,   275,  -109,  -109,  -109,
     184,     9,  -109,   176,  -109,    12,  -109,  -109,  -109,  -109,
    -109,   158,   275,    40,   160,   275,   275,  -109,  -109,   115,
     275,   275,    15,    15,    72,    72,    72,    72,    80,    80,
    -109,  -109,   166,  -109,  -109,  -109,   176,  -109,  -109,   121,
      51,  -109,  -109,   156,  -109,  -109,   107,   162,  -109,   275,
    -109,  -109,  -109,   176,   185,  -109,  -109,  -109,   107,  -109,
     107,  -109,   163,  -109,   275,   175,  -109,  -109,  -109,   107,
    -109
  };

  const signed char
  Parser::yydefact_[] =
  {
       2,     0,     0,     1,    15,    16,     0,     3,     4,     0,
       8,     9,     0,     0,    12,     5,    10,    11,     0,     0,
       0,     0,    18,     0,    14,     6,     0,    20,     0,    16,
       0,    77,    78,    79,    87,     0,    92,     0,     0,    83,
      86,     0,     0,    28,    84,    85,    34,     0,     0,    32,
      40,     0,    38,    39,     0,    65,    70,     0,    36,    37,
       0,   102,     0,     0,     0,     0,    21,    17,     0,     0,
       0,    50,     0,    77,     0,    52,    48,    51,    54,    57,
      67,    62,     0,     0,    24,     0,    26,   105,     0,    29,
      33,    45,     0,    76,     0,     0,     0,    66,    30,     0,
     103,     7,     0,    23,    19,     0,    72,    81,     0,     0,
       0,     0,     0,     0,    50,    41,    50,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    80,    35,    27,
       0,     0,   104,    44,    75,     0,    74,    31,    13,    22,
      46,    73,     0,     0,     0,     0,     0,    96,    72,     0,
       0,     0,    55,    56,    60,    61,    58,    59,    63,    64,
      68,    69,     0,   106,    71,    47,    82,    88,    42,     0,
       0,    50,    73,    49,    53,    25,     0,     0,    93,     0,
      89,    43,    50,    97,     0,    94,    50,    90,     0,    98,
       0,    95,     0,    91,     0,     0,    99,    50,   100,     0,
     101
  };

  const short
  Parser::yypgoto_[] =
  {
    -109,  -109,  -109,  -109,   200,  -109,  -109,   201,  -109,   203,
       1,  -109,  -109,  -109,   109,  -109,   -59,   157,   -27,   -47,
    -109,   -70,  -109,  -109,   -34,  -108,    67,    76,  -109,    52,
      -1,   -23,    57,  -109,  -109,  -100,  -109,  -109,  -109,  -109,
    -109,  -109,  -109,  -109,  -109,  -109,  -109,  -109,  -109,  -109,
    -109,   204,   -43,  -109
  };

  const unsigned char
  Parser::yydefgoto_[] =
  {
       0,     1,     2,     7,     8,    62,     9,    10,    21,    11,
      47,    19,    28,    65,    66,    86,    87,    24,    48,    49,
      50,    51,    52,    53,   107,   111,    75,    76,    77,    78,
      79,    80,    81,    55,    56,   108,    57,    58,    69,   176,
     184,   190,    59,    71,   182,   188,   171,   186,   192,   197,
     199,    60,    61,    88
  };

  const short
  Parser::yytable_[] =
  {
      54,    90,   112,    12,    74,   103,   150,    82,   151,   114,
      12,     4,    29,   149,    30,    83,    84,   100,   131,    54,
     100,    73,    32,   114,    33,    54,   129,   132,     3,    64,
     119,   120,    14,    99,    97,    20,    90,    54,    85,    93,
      94,   115,    39,    40,   102,   169,    41,   106,   114,    54,
     164,   114,    90,    44,    45,    13,   121,   122,   133,    95,
      54,   135,   114,   179,    22,    31,    32,    96,    33,    23,
     127,    18,   163,   167,   185,   143,    54,    34,   189,    35,
     -17,    36,    37,    38,   178,    26,    39,    40,    25,   198,
      41,   117,   118,    42,    89,   104,   105,    44,    45,   123,
     124,    46,   160,   161,     4,     5,    64,     6,   166,   125,
     126,    68,   170,    67,    31,    32,    27,    33,   154,   155,
     156,   157,     4,    29,   195,    30,    34,    70,    35,   180,
      36,    37,    38,   141,   142,    39,    40,   144,   145,    41,
      72,   191,    42,   193,   109,   183,    44,    45,   172,   142,
      46,    92,   200,    54,   177,   142,    91,     4,    29,   110,
      30,    31,    32,   113,    33,    54,   130,    54,   116,   152,
     153,    54,   134,    34,   136,    35,    54,    36,    37,    38,
     158,   159,    39,    40,   138,   140,    41,   114,   147,    42,
      43,   146,   162,    44,    45,     4,    29,    46,    30,    31,
      32,   165,    33,   168,   175,   181,   194,   187,   196,    15,
      16,    34,    17,    35,   139,    36,    37,    38,   174,   101,
      39,    40,    31,    32,    41,    33,   173,    42,    98,     0,
      63,    44,    45,     0,    34,    46,    35,     0,    36,    37,
      38,     0,     0,    39,    40,    31,    32,    41,    33,     0,
      42,   128,     0,     0,    44,    45,     0,    34,    46,    35,
       0,    36,    37,    38,     0,     0,    39,    40,    73,    32,
      41,    33,     0,    42,   137,     0,     0,    44,    45,     0,
       0,    46,    73,    32,     0,    33,     0,     0,     0,    39,
      40,     0,     0,    41,   148,     0,     0,     0,     0,     0,
      44,    45,     0,    39,    40,     0,     0,    41,     0,     0,
       0,     0,     0,     0,    44,    45
  };

  const short
  Parser::yycheck_[] =
  {
      23,    48,    72,     2,    38,    64,   114,    41,   116,    11,
       9,     3,     4,   113,     6,    42,     7,    60,    34,    42,
      63,     7,     8,    11,    10,    48,    85,    43,     0,    28,
      15,    16,     7,    60,    57,    32,    83,    60,    29,    17,
      18,    43,    28,    29,    36,   145,    32,    33,    11,    72,
      38,    11,    99,    39,    40,    20,    41,    42,    92,    37,
      83,    95,    11,   171,    32,     7,     8,    45,    10,    35,
      33,     7,   131,    33,   182,   109,    99,    19,   186,    21,
       7,    23,    24,    25,    33,    35,    28,    29,    33,   197,
      32,    13,    14,    35,    36,    33,    34,    39,    40,    27,
      28,    43,   125,   126,     3,     4,   105,     6,   142,    29,
      30,    32,   146,     7,     7,     8,    33,    10,   119,   120,
     121,   122,     3,     4,   194,     6,    19,    32,    21,   176,
      23,    24,    25,    33,    34,    28,    29,    33,    34,    32,
      32,   188,    35,   190,    32,   179,    39,    40,    33,    34,
      43,    31,   199,   176,    33,    34,    43,     3,     4,    10,
       6,     7,     8,    32,    10,   188,    37,   190,    12,   117,
     118,   194,     7,    19,     7,    21,   199,    23,    24,    25,
     123,   124,    28,    29,    43,    43,    32,    11,    43,    35,
      36,    32,     8,    39,    40,     3,     4,    43,     6,     7,
       8,    43,    10,    43,    38,    43,    43,    22,    33,     9,
       9,    19,     9,    21,   105,    23,    24,    25,   151,    62,
      28,    29,     7,     8,    32,    10,   150,    35,    36,    -1,
      26,    39,    40,    -1,    19,    43,    21,    -1,    23,    24,
      25,    -1,    -1,    28,    29,     7,     8,    32,    10,    -1,
      35,    36,    -1,    -1,    39,    40,    -1,    19,    43,    21,
      -1,    23,    24,    25,    -1,    -1,    28,    29,     7,     8,
      32,    10,    -1,    35,    36,    -1,    -1,    39,    40,    -1,
      -1,    43,     7,     8,    -1,    10,    -1,    -1,    -1,    28,
      29,    -1,    -1,    32,    33,    -1,    -1,    -1,    -1,    -1,
      39,    40,    -1,    28,    29,    -1,    -1,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    40
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    47,    48,     0,     3,     4,     6,    49,    50,    52,
      53,    55,    56,    20,     7,    50,    53,    55,     7,    57,
      32,    54,    32,    35,    63,    33,    35,    33,    58,     4,
       6,     7,     8,    10,    19,    21,    23,    24,    25,    28,
      29,    32,    35,    36,    39,    40,    43,    56,    64,    65,
      66,    67,    68,    69,    77,    79,    80,    82,    83,    88,
      97,    98,    51,    97,    56,    59,    60,     7,    32,    84,
      32,    89,    32,     7,    70,    72,    73,    74,    75,    76,
      77,    78,    70,    64,     7,    29,    61,    62,    99,    36,
      65,    43,    31,    17,    18,    37,    45,    77,    36,    64,
      98,    63,    36,    62,    33,    34,    33,    70,    81,    32,
      10,    71,    67,    32,    11,    43,    12,    13,    14,    15,
      16,    41,    42,    27,    28,    29,    30,    33,    36,    62,
      37,    34,    43,    70,     7,    70,     7,    36,    43,    60,
      43,    33,    34,    70,    33,    34,    32,    43,    33,    81,
      71,    71,    75,    75,    76,    76,    76,    76,    78,    78,
      77,    77,     8,    62,    38,    43,    70,    33,    43,    81,
      70,    92,    33,    73,    72,    38,    85,    33,    33,    71,
      65,    43,    90,    70,    86,    71,    93,    22,    91,    71,
      87,    65,    94,    65,    43,    67,    33,    95,    71,    96,
      65
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    46,    48,    47,    49,    49,    51,    50,    52,    52,
      52,    52,    54,    53,    55,    56,    56,    56,    58,    57,
      57,    59,    59,    60,    61,    61,    62,    62,    63,    63,
      63,    63,    64,    64,    65,    65,    65,    65,    65,    65,
      65,    65,    66,    66,    67,    68,    69,    69,    70,    70,
      71,    72,    73,    73,    74,    74,    74,    75,    75,    75,
      75,    75,    76,    76,    76,    77,    77,    78,    78,    78,
      79,    79,    79,    79,    79,    79,    79,    80,    80,    80,
      80,    81,    81,    82,    82,    82,    82,    84,    85,    86,
      87,    83,    89,    90,    91,    88,    92,    93,    94,    95,
      96,    88,    97,    97,    98,    99,    99
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     0,     2,     1,     2,     0,     6,     1,     1,
       2,     2,     0,     7,     3,     1,     1,     2,     0,     5,
       3,     1,     3,     2,     1,     4,     1,     2,     2,     3,
       3,     4,     1,     2,     1,     3,     1,     1,     1,     1,
       1,     3,     5,     7,     3,     2,     4,     5,     1,     4,
       0,     1,     1,     4,     1,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     2,     1,     3,     3,
       1,     4,     3,     4,     3,     3,     2,     1,     1,     1,
       3,     1,     3,     1,     1,     1,     1,     0,     0,     0,
       0,    11,     0,     0,     0,    10,     0,     0,     0,     0,
       0,    17,     1,     2,     3,     1,     3
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "VOID", "INT", "FLOAT",
  "STRUCT", "IDENTIFIER", "INT_CONSTANT", "FLOAT_CONSTANT",
  "STRING_LITERAL", "OR_OP", "AND_OP", "EQ_OP", "NE_OP", "LE_OP", "GE_OP",
  "INC_OP", "PTR_OP", "IF", "MAIN", "PRINTF", "ELSE", "WHILE", "FOR",
  "RETURN", "OTHERS", "'+'", "'-'", "'*'", "'/'", "'='", "'('", "')'",
  "','", "'{'", "'}'", "'['", "']'", "'!'", "'&'", "'<'", "'>'", "';'",
  "'\\n'", "'.'", "$accept", "begin_nterm", "$@1", "program",
  "main_definition", "$@2", "translation_unit", "struct_specifier", "$@3",
  "function_definition", "type_specifier", "fun_declarator", "$@4",
  "parameter_list", "parameter_declaration", "declarator_arr",
  "declarator", "compound_statement", "statement_list", "statement",
  "printf_call", "assignment_expression", "assignment_statement",
  "procedure_call", "expression", "mnterm", "ifgotocoder",
  "logical_and_expression", "equality_expression", "relational_expression",
  "additive_expression", "unary_expression", "multiplicative_expression",
  "postfix_expression", "primary_expression", "expression_list",
  "unary_operator", "selection_statement", "$@5", "$@6", "$@7", "$@8",
  "iteration_statement", "$@9", "$@10", "$@11", "$@12", "$@13", "$@14",
  "$@15", "$@16", "declaration_list", "declaration", "declarator_list", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,   123,   123,   123,   150,   153,   157,   157,   180,   182,
     186,   188,   194,   194,   215,   228,   240,   249,   263,   263,
     298,   317,   323,   331,   343,   353,   363,   366,   375,   378,
     381,   385,   390,   398,   404,   409,   414,   417,   420,   423,
     426,   429,   454,   463,   478,   530,   537,   567,   619,   623,
     640,   647,   659,   662,   680,   684,   700,   718,   722,   738,
     754,   770,   788,   792,   805,   820,   824,   909,   919,   934,
     950,   953,   995,  1026,  1078,  1124,  1170,  1216,  1236,  1250,
    1261,  1266,  1270,  1275,  1278,  1282,  1286,  1291,  1296,  1304,
    1310,  1291,  1333,  1338,  1342,  1333,  1363,  1368,  1372,  1377,
    1383,  1363,  1406,  1408,  1412,  1416,  1431
  };

  void
  Parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  Parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  Parser::symbol_kind_type
  Parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      44,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,     2,     2,     2,     2,    40,     2,
      32,    33,    29,    27,    34,    28,    45,    30,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    43,
      41,    31,    42,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    37,     2,    38,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    35,     2,    36,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26
    };
    // Last valid token kind.
    const int code_max = 281;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 5 "parser.yy"
} // IPL
#line 3849 "parser.tab.cc"

#line 1445 "parser.yy"

//grammar definition.
void 
IPL::Parser::error( const location_type &l, const std::string &err_message )
{
   std::cout << "Error at line " << l.begin.line << ": " << err_message << "\n";
   exit(1);
}

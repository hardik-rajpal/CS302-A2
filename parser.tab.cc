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
#line 47 "parser.yy"

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

#line 63 "parser.tab.cc"


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
#line 156 "parser.tab.cc"

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

      case symbol_kind::S_procedure_call: // procedure_call
        value.copy< funcall_astnode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_fun_declarator: // fun_declarator
        value.copy< fundeclarator_astnode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_logical_and_expression: // logical_and_expression
      case symbol_kind::S_equality_expression: // equality_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
        value.copy< op_binary_astnode* > (YY_MOVE (that.value));
        break;

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
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_OTHERS: // OTHERS
      case symbol_kind::S_unary_operator: // unary_operator
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_begin_nterm: // begin_nterm
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

      case symbol_kind::S_procedure_call: // procedure_call
        value.move< funcall_astnode* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_fun_declarator: // fun_declarator
        value.move< fundeclarator_astnode* > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_logical_and_expression: // logical_and_expression
      case symbol_kind::S_equality_expression: // equality_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
        value.move< op_binary_astnode* > (YY_MOVE (s.value));
        break;

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
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_OTHERS: // OTHERS
      case symbol_kind::S_unary_operator: // unary_operator
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_begin_nterm: // begin_nterm
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

      case symbol_kind::S_procedure_call: // procedure_call
        value.YY_MOVE_OR_COPY< funcall_astnode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_fun_declarator: // fun_declarator
        value.YY_MOVE_OR_COPY< fundeclarator_astnode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_logical_and_expression: // logical_and_expression
      case symbol_kind::S_equality_expression: // equality_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
        value.YY_MOVE_OR_COPY< op_binary_astnode* > (YY_MOVE (that.value));
        break;

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
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_OTHERS: // OTHERS
      case symbol_kind::S_unary_operator: // unary_operator
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_begin_nterm: // begin_nterm
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

      case symbol_kind::S_procedure_call: // procedure_call
        value.move< funcall_astnode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_fun_declarator: // fun_declarator
        value.move< fundeclarator_astnode* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_logical_and_expression: // logical_and_expression
      case symbol_kind::S_equality_expression: // equality_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
        value.move< op_binary_astnode* > (YY_MOVE (that.value));
        break;

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
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_OTHERS: // OTHERS
      case symbol_kind::S_unary_operator: // unary_operator
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_begin_nterm: // begin_nterm
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

      case symbol_kind::S_procedure_call: // procedure_call
        value.copy< funcall_astnode* > (that.value);
        break;

      case symbol_kind::S_fun_declarator: // fun_declarator
        value.copy< fundeclarator_astnode* > (that.value);
        break;

      case symbol_kind::S_logical_and_expression: // logical_and_expression
      case symbol_kind::S_equality_expression: // equality_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
        value.copy< op_binary_astnode* > (that.value);
        break;

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
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_OTHERS: // OTHERS
      case symbol_kind::S_unary_operator: // unary_operator
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_begin_nterm: // begin_nterm
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

      case symbol_kind::S_procedure_call: // procedure_call
        value.move< funcall_astnode* > (that.value);
        break;

      case symbol_kind::S_fun_declarator: // fun_declarator
        value.move< fundeclarator_astnode* > (that.value);
        break;

      case symbol_kind::S_logical_and_expression: // logical_and_expression
      case symbol_kind::S_equality_expression: // equality_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
        value.move< op_binary_astnode* > (that.value);
        break;

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
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_OTHERS: // OTHERS
      case symbol_kind::S_unary_operator: // unary_operator
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_begin_nterm: // begin_nterm
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
#line 961 "parser.tab.cc"
        break;

      case symbol_kind::S_INT: // INT
#line 22 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 967 "parser.tab.cc"
        break;

      case symbol_kind::S_FLOAT: // FLOAT
#line 23 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 973 "parser.tab.cc"
        break;

      case symbol_kind::S_STRUCT: // STRUCT
#line 24 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 979 "parser.tab.cc"
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
#line 25 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 985 "parser.tab.cc"
        break;

      case symbol_kind::S_INT_CONSTANT: // INT_CONSTANT
#line 26 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 991 "parser.tab.cc"
        break;

      case symbol_kind::S_FLOAT_CONSTANT: // FLOAT_CONSTANT
#line 27 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 997 "parser.tab.cc"
        break;

      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
#line 28 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1003 "parser.tab.cc"
        break;

      case symbol_kind::S_OR_OP: // OR_OP
#line 29 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1009 "parser.tab.cc"
        break;

      case symbol_kind::S_AND_OP: // AND_OP
#line 30 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1015 "parser.tab.cc"
        break;

      case symbol_kind::S_EQ_OP: // EQ_OP
#line 31 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1021 "parser.tab.cc"
        break;

      case symbol_kind::S_NE_OP: // NE_OP
#line 32 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1027 "parser.tab.cc"
        break;

      case symbol_kind::S_LE_OP: // LE_OP
#line 33 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1033 "parser.tab.cc"
        break;

      case symbol_kind::S_GE_OP: // GE_OP
#line 34 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1039 "parser.tab.cc"
        break;

      case symbol_kind::S_INC_OP: // INC_OP
#line 35 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1045 "parser.tab.cc"
        break;

      case symbol_kind::S_PTR_OP: // PTR_OP
#line 36 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1051 "parser.tab.cc"
        break;

      case symbol_kind::S_IF: // IF
#line 37 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1057 "parser.tab.cc"
        break;

      case symbol_kind::S_ELSE: // ELSE
#line 38 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1063 "parser.tab.cc"
        break;

      case symbol_kind::S_WHILE: // WHILE
#line 39 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1069 "parser.tab.cc"
        break;

      case symbol_kind::S_FOR: // FOR
#line 40 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1075 "parser.tab.cc"
        break;

      case symbol_kind::S_RETURN: // RETURN
#line 41 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1081 "parser.tab.cc"
        break;

      case symbol_kind::S_OTHERS: // OTHERS
#line 42 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1087 "parser.tab.cc"
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

      case symbol_kind::S_procedure_call: // procedure_call
        yylhs.value.emplace< funcall_astnode* > ();
        break;

      case symbol_kind::S_fun_declarator: // fun_declarator
        yylhs.value.emplace< fundeclarator_astnode* > ();
        break;

      case symbol_kind::S_logical_and_expression: // logical_and_expression
      case symbol_kind::S_equality_expression: // equality_expression
      case symbol_kind::S_relational_expression: // relational_expression
      case symbol_kind::S_additive_expression: // additive_expression
      case symbol_kind::S_multiplicative_expression: // multiplicative_expression
        yylhs.value.emplace< op_binary_astnode* > ();
        break;

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
      case symbol_kind::S_ELSE: // ELSE
      case symbol_kind::S_WHILE: // WHILE
      case symbol_kind::S_FOR: // FOR
      case symbol_kind::S_RETURN: // RETURN
      case symbol_kind::S_OTHERS: // OTHERS
      case symbol_kind::S_unary_operator: // unary_operator
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_begin_nterm: // begin_nterm
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
#line 114 "parser.yy"
             {
    if(!Symbols::symTabConstructed){
        Symbols::gst = new SymTab();
        Symbols::initGST();//initializes typespec vals, boolgen vals
    }
    else{
        // std::cout<<"Here again";
    }
    ststack.push(Symbols::gst);
    structc = typespec_astnode::structc;
    intc = typespec_astnode::intc;
    floatc = typespec_astnode::floatc;
    stringc = typespec_astnode::stringc;
    voidc = typespec_astnode::voidc;

}
#line 1447 "parser.tab.cc"
    break;

  case 3: // begin_nterm: $@1 translation_unit
#line 129 "parser.yy"
                   {
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
#line 1463 "parser.tab.cc"
    break;

  case 4: // translation_unit: struct_specifier
#line 141 "parser.yy"
                                  {
}
#line 1470 "parser.tab.cc"
    break;

  case 5: // translation_unit: function_definition
#line 143 "parser.yy"
                     {
    yylhs.value.as < std::vector<abstract_astnode*> > () = std::vector<abstract_astnode*>();
    yylhs.value.as < std::vector<abstract_astnode*> > ().push_back(yystack_[0].value.as < statement_astnode* > ());
}
#line 1479 "parser.tab.cc"
    break;

  case 6: // translation_unit: translation_unit struct_specifier
#line 147 "parser.yy"
                                   {
}
#line 1486 "parser.tab.cc"
    break;

  case 7: // translation_unit: translation_unit function_definition
#line 149 "parser.yy"
                                      {
    yylhs.value.as < std::vector<abstract_astnode*> > () = yystack_[1].value.as < std::vector<abstract_astnode*> > ();
    yylhs.value.as < std::vector<abstract_astnode*> > ().push_back(yystack_[0].value.as < statement_astnode* > ());
}
#line 1495 "parser.tab.cc"
    break;

  case 8: // $@2: %empty
#line 155 "parser.yy"
                                    {
    string structName = "struct " + yystack_[0].value.as < std::string > ();
    if(!Symbols::symTabConstructed){
        ststack.top()->rows[structName] = SymEntry(structc,SymTab::ST_HL_type::STRUCT,SymTab::ST_LPG::GLOBAL,0,0);
        Symbols::slsts[structName] = new SymTab();
        Symbols::slsts[structName]->type = "struct";
    }
    ststack.push(Symbols::slsts[structName]);
}
#line 1509 "parser.tab.cc"
    break;

  case 9: // struct_specifier: STRUCT IDENTIFIER $@2 '{' declaration_list '}' ';'
#line 163 "parser.yy"
                             {
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
}
#line 1526 "parser.tab.cc"
    break;

  case 10: // function_definition: type_specifier fun_declarator compound_statement
#line 176 "parser.yy"
                                                                     {
    if(Symbols::symTabConstructed){
        ststack.top()->ptr = new seq_astnode(yystack_[0].value.as < std::vector<statement_astnode*> > ());
    }
    yylhs.value.as < statement_astnode* > () = nullptr;
    ststack.pop();
}
#line 1538 "parser.tab.cc"
    break;

  case 11: // type_specifier: VOID
#line 184 "parser.yy"
                    {
    typespec_astnode ts;
    ts.baseTypeWidth = 0;
    ts.baseTypeName = "void";
    ts.typeWidth = ts.baseTypeWidth;
    ts.typeName = "void";
    yylhs.value.as < typespec_astnode > () = ts;
    if(!Symbols::symTabConstructed){
        toptype = ts;
    }

}
#line 1555 "parser.tab.cc"
    break;

  case 12: // type_specifier: INT
#line 196 "parser.yy"
     {
    // retType = SymTab::ST_type::INT;
    typespec_astnode ts = intc;
    yylhs.value.as < typespec_astnode > () = ts;
    if(!Symbols::symTabConstructed){
        toptype = ts;
    }

}
#line 1569 "parser.tab.cc"
    break;

  case 13: // type_specifier: FLOAT
#line 205 "parser.yy"
       {
    // retType = SymTab::ST_type::FLOAT;
    typespec_astnode ts = floatc;
    yylhs.value.as < typespec_astnode > () = ts;
    if(!Symbols::symTabConstructed){
        toptype = ts;
    }
}
#line 1582 "parser.tab.cc"
    break;

  case 14: // type_specifier: STRUCT IDENTIFIER
#line 213 "parser.yy"
                   {
    // retType = SymTab::ST_type::STRUCT_TYPE;
    typespec_astnode ts;
    ts.typeName = "struct "+(yystack_[0].value.as < std::string > ());
    ts.baseTypeWidth = Symbols::getStructBaseTypeWidth(ts.typeName);
    ts.typeWidth = ts.baseTypeWidth;
    ts.baseTypeName = ts.typeName;
    yylhs.value.as < typespec_astnode > () = ts;
    if(!Symbols::symTabConstructed){
        toptype = ts;
    }
}
#line 1599 "parser.tab.cc"
    break;

  case 15: // $@3: %empty
#line 227 "parser.yy"
                              {
    std::string name = yystack_[1].value.as < std::string > ();
    if(!Symbols::symTabConstructed){
        ststack.top()->rows[name] = SymEntry(toptype,SymTab::ST_HL_type::FUN,SymTab::ST_LPG::GLOBAL,0,0);
        Symbols::flsts[name] = new SymTab();
        Symbols::flsts[name]->type = "function";
        Symbols::flsts[name]->rettype = new typespec_astnode();
        *(Symbols::flsts[name]->rettype) = toptype;
    }
    ststack.push(Symbols::flsts[name]);
}
#line 1615 "parser.tab.cc"
    break;

  case 16: // fun_declarator: IDENTIFIER '(' $@3 parameter_list ')'
#line 237 "parser.yy"
                    {
    yylhs.value.as < fundeclarator_astnode* > () = NULL;
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
        std::string name = yystack_[4].value.as < std::string > ();
        std::vector<typespec_astnode> vect = std::vector<typespec_astnode>();
        yylhs.value.as < fundeclarator_astnode* > () = new fundeclarator_astnode(name, vect);
    }
}
#line 1642 "parser.tab.cc"
    break;

  case 17: // fun_declarator: IDENTIFIER '(' ')'
#line 259 "parser.yy"
                    {
    std::string name = yystack_[2].value.as < std::string > ();
    if(!Symbols::symTabConstructed){
        ststack.top()->rows[name] = SymEntry(toptype,SymTab::ST_HL_type::FUN,SymTab::ST_LPG::GLOBAL,0,0);
        Symbols::flsts[name] = new SymTab();
        Symbols::flsts[name]->rettype = new typespec_astnode;
        Symbols::flsts[name]->type = "function";
        *(Symbols::flsts[name]->rettype) = toptype;
    }
    else{
        yylhs.value.as < fundeclarator_astnode* > () = new fundeclarator_astnode(name,std::vector<typespec_astnode>());
    }
    ststack.push(Symbols::flsts[name]);
}
#line 1661 "parser.tab.cc"
    break;

  case 18: // parameter_list: parameter_declaration
#line 275 "parser.yy"
                                     {
    if(Symbols::symTabConstructed){
        yylhs.value.as < std::vector<typespec_astnode> > () = std::vector<typespec_astnode>();
        yylhs.value.as < std::vector<typespec_astnode> > ().push_back(yystack_[0].value.as < typespec_astnode > ());
    }
}
#line 1672 "parser.tab.cc"
    break;

  case 19: // parameter_list: parameter_declaration ',' parameter_list
#line 281 "parser.yy"
                                           {
    if(Symbols::symTabConstructed){
        yylhs.value.as < std::vector<typespec_astnode> > () = yystack_[0].value.as < std::vector<typespec_astnode> > ();
        yylhs.value.as < std::vector<typespec_astnode> > ().push_back(yystack_[2].value.as < typespec_astnode > ());
    }
}
#line 1683 "parser.tab.cc"
    break;

  case 20: // parameter_declaration: type_specifier declarator
#line 289 "parser.yy"
                                                {
    yylhs.value.as < typespec_astnode > () = yystack_[1].value.as < typespec_astnode > ();
    if(!Symbols::symTabConstructed){
        if(yystack_[0].value.as < typespec_astnode > ().typeName=="void"){
            error(yylhs.location,"Cannot declare variable of type \"void\"");
        }
        ststack.top()->rows[topvarname] = SymEntry(yystack_[0].value.as < typespec_astnode > (),SymTab::ST_HL_type::VAR,SymTab::ST_LPG::PARAM,yystack_[0].value.as < typespec_astnode > ().typeWidth,0);
        ststack.top()->rows[topvarname].offset = ststack.top()->getParamOffset(ststack.top()->rows[topvarname].size);
    }
}
#line 1698 "parser.tab.cc"
    break;

  case 21: // declarator_arr: IDENTIFIER
#line 301 "parser.yy"
                          {
    yylhs.value.as < typespec_astnode > () = toptype;
    yylhs.value.as < typespec_astnode > ().typeWidth = yylhs.value.as < typespec_astnode > ().baseTypeWidth;
    if(!Symbols::symTabConstructed){
        topvarname = yystack_[0].value.as < std::string > ();
    }
}
#line 1710 "parser.tab.cc"
    break;

  case 22: // declarator_arr: declarator_arr '[' INT_CONSTANT ']'
#line 308 "parser.yy"
                                     {
    yylhs.value.as < typespec_astnode > () = yystack_[3].value.as < typespec_astnode > ();
    if(!Symbols::symTabConstructed){
        typespec_astnode tstmp = yystack_[3].value.as < typespec_astnode > ();
        yylhs.value.as < typespec_astnode > ().arrsizes.insert(yylhs.value.as < typespec_astnode > ().arrsizes.begin(),std::stoi(yystack_[1].value.as < std::string > ()));
        yylhs.value.as < typespec_astnode > ().typeWidth = yylhs.value.as < typespec_astnode > ().genTypeWidth();
        yylhs.value.as < typespec_astnode > ().typeName = yylhs.value.as < typespec_astnode > ().genTypeName();
    }
}
#line 1724 "parser.tab.cc"
    break;

  case 23: // declarator: declarator_arr
#line 318 "parser.yy"
                          {
    yylhs.value.as < typespec_astnode > () = yystack_[0].value.as < typespec_astnode > ();
}
#line 1732 "parser.tab.cc"
    break;

  case 24: // declarator: '*' declarator
#line 321 "parser.yy"
                 {
    yylhs.value.as < typespec_astnode > () = yystack_[0].value.as < typespec_astnode > ();
    yylhs.value.as < typespec_astnode > ().baseTypeWidth = 4;
    yylhs.value.as < typespec_astnode > ().numptrstars+=1;
    yylhs.value.as < typespec_astnode > ().typeWidth = yylhs.value.as < typespec_astnode > ().genTypeWidth();
    yylhs.value.as < typespec_astnode > ().typeName = yylhs.value.as < typespec_astnode > ().genTypeName();
}
#line 1744 "parser.tab.cc"
    break;

  case 25: // compound_statement: '{' '}'
#line 330 "parser.yy"
                           {
    yylhs.value.as < std::vector<statement_astnode*> > () = std::vector<statement_astnode*>();
}
#line 1752 "parser.tab.cc"
    break;

  case 26: // compound_statement: '{' statement_list '}'
#line 333 "parser.yy"
                        {
    yylhs.value.as < std::vector<statement_astnode*> > () = yystack_[1].value.as < std::vector<statement_astnode*> > ();
}
#line 1760 "parser.tab.cc"
    break;

  case 27: // compound_statement: '{' declaration_list '}'
#line 336 "parser.yy"
                           {
    //TODO important
    yylhs.value.as < std::vector<statement_astnode*> > () = std::vector<statement_astnode*>();

}
#line 1770 "parser.tab.cc"
    break;

  case 28: // compound_statement: '{' declaration_list statement_list '}'
#line 341 "parser.yy"
                                         {
    yylhs.value.as < std::vector<statement_astnode*> > () = yystack_[1].value.as < std::vector<statement_astnode*> > ();
}
#line 1778 "parser.tab.cc"
    break;

  case 29: // statement_list: statement
#line 346 "parser.yy"
                          {
    std::vector<statement_astnode*> temp;
    statement_astnode* stmt = yystack_[0].value.as < statement_astnode* > ();
    if(stmt!=NULL){
        temp.push_back(yystack_[0].value.as < statement_astnode* > ());
    }
    yylhs.value.as < std::vector<statement_astnode*> > () = temp;
}
#line 1791 "parser.tab.cc"
    break;

  case 30: // statement_list: statement_list statement
#line 354 "parser.yy"
                          {
    yystack_[1].value.as < std::vector<statement_astnode*> > ().push_back(yystack_[0].value.as < statement_astnode* > ());
    yylhs.value.as < std::vector<statement_astnode*> > () = yystack_[1].value.as < std::vector<statement_astnode*> > ();
}
#line 1800 "parser.tab.cc"
    break;

  case 31: // statement: ';'
#line 360 "parser.yy"
              {
    if(Symbols::symTabConstructed){   
        yylhs.value.as < statement_astnode* > () = new empty_astnode();
    }
}
#line 1810 "parser.tab.cc"
    break;

  case 32: // statement: '{' statement_list '}'
#line 365 "parser.yy"
                        {
    if(Symbols::symTabConstructed){   
        yylhs.value.as < statement_astnode* > () = new seq_astnode(yystack_[1].value.as < std::vector<statement_astnode*> > ());
    }
}
#line 1820 "parser.tab.cc"
    break;

  case 33: // statement: selection_statement
#line 370 "parser.yy"
                     {
    yylhs.value.as < statement_astnode* > () = yystack_[0].value.as < statement_astnode* > ();
}
#line 1828 "parser.tab.cc"
    break;

  case 34: // statement: iteration_statement
#line 373 "parser.yy"
                     {
    yylhs.value.as < statement_astnode* > () = yystack_[0].value.as < statement_astnode* > ();
}
#line 1836 "parser.tab.cc"
    break;

  case 35: // statement: assignment_statement
#line 376 "parser.yy"
                      {
    yylhs.value.as < statement_astnode* > () = yystack_[0].value.as < statement_astnode* > ();
}
#line 1844 "parser.tab.cc"
    break;

  case 36: // statement: procedure_call
#line 379 "parser.yy"
                {
    yylhs.value.as < statement_astnode* > () = yystack_[0].value.as < funcall_astnode* > ();
}
#line 1852 "parser.tab.cc"
    break;

  case 37: // statement: RETURN expression ';'
#line 382 "parser.yy"
                       {
    if(Symbols::symTabConstructed){
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
}
#line 1877 "parser.tab.cc"
    break;

  case 38: // assignment_expression: unary_expression '=' expression
#line 404 "parser.yy"
                                                      {
    if(Symbols::symTabConstructed){
        // std::cerr<<__LINE__<<std::endl;
        std::cerr<<yystack_[2].value.as < exp_astnode* > ()->typeNode.typeName<<" = "<<yystack_[0].value.as < exp_astnode* > ()->typeNode.typeName<<std::endl;
        if((yystack_[2].value.as < exp_astnode* > ()->typeNode.compatibleWith(yystack_[0].value.as < exp_astnode* > ()->typeNode))){
            // std::cerr<<__LINE__<<std::endl;
            if(!(yystack_[2].value.as < exp_astnode* > ()->typeNode.islval)){
                error(yylhs.location,"Error: "+yystack_[2].value.as < exp_astnode* > ()->typeNode.typeName +" is not an lval.");
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
}
#line 1914 "parser.tab.cc"
    break;

  case 39: // assignment_statement: assignment_expression ';'
#line 438 "parser.yy"
                                               {
    if(Symbols::symTabConstructed){
        yylhs.value.as < statement_astnode* > () = new assignS_astnode(yystack_[1].value.as < assignE_astnode* > ()->exp1, yystack_[1].value.as < assignE_astnode* > ()->exp2);
    }
}
#line 1924 "parser.tab.cc"
    break;

  case 40: // procedure_call: IDENTIFIER '(' ')' ';'
#line 445 "parser.yy"
                                      {
    if (Symbols::symTabConstructed) {
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
}
#line 1956 "parser.tab.cc"
    break;

  case 41: // procedure_call: IDENTIFIER '(' expression_list ')' ';'
#line 472 "parser.yy"
                                        {
    if (Symbols::symTabConstructed) {
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
}
#line 2004 "parser.tab.cc"
    break;

  case 42: // expression: logical_and_expression
#line 517 "parser.yy"
                                  {
    yylhs.value.as < exp_astnode* > () = yystack_[0].value.as < op_binary_astnode* > ();
    // std::cerr<<__LINE__<<$$->typeNode.typeName<<endl;
}
#line 2013 "parser.tab.cc"
    break;

  case 43: // expression: expression OR_OP logical_and_expression
#line 521 "parser.yy"
                                         {
    if(Symbols::symTabConstructed){
        yylhs.value.as < exp_astnode* > () = new op_binary_astnode("OR_OP",yystack_[2].value.as < exp_astnode* > (),yystack_[0].value.as < op_binary_astnode* > ());
    }
}
#line 2023 "parser.tab.cc"
    break;

  case 44: // logical_and_expression: equality_expression
#line 528 "parser.yy"
                                           {
    yylhs.value.as < op_binary_astnode* > () = yystack_[0].value.as < op_binary_astnode* > ();
    // std::cerr<<__LINE__<<$$->typeNode.typeName<<endl;
}
#line 2032 "parser.tab.cc"
    break;

  case 45: // logical_and_expression: logical_and_expression AND_OP equality_expression
#line 532 "parser.yy"
                                                   {
    if(Symbols::symTabConstructed){   
        yylhs.value.as < op_binary_astnode* > () = new op_binary_astnode("AND_OP", yystack_[2].value.as < op_binary_astnode* > (), yystack_[0].value.as < op_binary_astnode* > ());
    }
}
#line 2042 "parser.tab.cc"
    break;

  case 46: // equality_expression: relational_expression
#line 539 "parser.yy"
                                          {
    yylhs.value.as < op_binary_astnode* > () = yystack_[0].value.as < op_binary_astnode* > ();
    // std::cerr<<__LINE__<<$$->typeNode.typeName<<endl;
}
#line 2051 "parser.tab.cc"
    break;

  case 47: // equality_expression: equality_expression EQ_OP relational_expression
#line 543 "parser.yy"
                                                  {
    if(Symbols::symTabConstructed){
        std::string op = "EQ_OP?";
        if(!op_binary_astnode::operandsCompatible(op,yystack_[2].value.as < op_binary_astnode* > (),yystack_[0].value.as < op_binary_astnode* > ())){
            error(yylhs.location,"Incompatible operands for "+op+": \""+yystack_[2].value.as < op_binary_astnode* > ()->typeNode.typeName+"\", \""+yystack_[0].value.as < op_binary_astnode* > ()->typeNode.typeName+"\"");
        }
        yylhs.value.as < op_binary_astnode* > () = new op_binary_astnode(op, yystack_[2].value.as < op_binary_astnode* > (), yystack_[0].value.as < op_binary_astnode* > ());
    }
}
#line 2065 "parser.tab.cc"
    break;

  case 48: // equality_expression: equality_expression NE_OP relational_expression
#line 552 "parser.yy"
                                                 {
    if(Symbols::symTabConstructed){ 
        std::string op = "NE_OP?";
        if(!op_binary_astnode::operandsCompatible(op,yystack_[2].value.as < op_binary_astnode* > (),yystack_[0].value.as < op_binary_astnode* > ())){
            error(yylhs.location,"Incompatible operands for "+op+": \""+yystack_[2].value.as < op_binary_astnode* > ()->typeNode.typeName+"\", \""+yystack_[0].value.as < op_binary_astnode* > ()->typeNode.typeName+"\"");
        }
        yylhs.value.as < op_binary_astnode* > () = new op_binary_astnode(op, yystack_[2].value.as < op_binary_astnode* > (), yystack_[0].value.as < op_binary_astnode* > ());
    }
}
#line 2079 "parser.tab.cc"
    break;

  case 49: // relational_expression: additive_expression
#line 563 "parser.yy"
                                          {
    yylhs.value.as < op_binary_astnode* > () = yystack_[0].value.as < op_binary_astnode* > ();
    // std::cerr<<__LINE__<<$$->typeNode.typeName<<endl;
}
#line 2088 "parser.tab.cc"
    break;

  case 50: // relational_expression: relational_expression '<' additive_expression
#line 567 "parser.yy"
                                               {
    if(Symbols::symTabConstructed){
        std::string op = "LT_OP?";
        if(!op_binary_astnode::operandsCompatible(op,yystack_[2].value.as < op_binary_astnode* > (),yystack_[0].value.as < op_binary_astnode* > ())){
            error(yylhs.location,"Incompatible operands for "+op+": \""+yystack_[2].value.as < op_binary_astnode* > ()->typeNode.typeName+"\", \""+yystack_[0].value.as < op_binary_astnode* > ()->typeNode.typeName+"\"");
        }
        yylhs.value.as < op_binary_astnode* > () = new op_binary_astnode(op, yystack_[2].value.as < op_binary_astnode* > (), yystack_[0].value.as < op_binary_astnode* > ());
    }
}
#line 2102 "parser.tab.cc"
    break;

  case 51: // relational_expression: relational_expression '>' additive_expression
#line 576 "parser.yy"
                                               {
    if(Symbols::symTabConstructed){
        std::string op = "GT_OP?";
        if(!op_binary_astnode::operandsCompatible(op,yystack_[2].value.as < op_binary_astnode* > (),yystack_[0].value.as < op_binary_astnode* > ())){
            error(yylhs.location,"Incompatible operands for "+op+": \""+yystack_[2].value.as < op_binary_astnode* > ()->typeNode.typeName+"\", \""+yystack_[0].value.as < op_binary_astnode* > ()->typeNode.typeName+"\"");
        }
        yylhs.value.as < op_binary_astnode* > () = new op_binary_astnode(op, yystack_[2].value.as < op_binary_astnode* > (), yystack_[0].value.as < op_binary_astnode* > ());
    }
}
#line 2116 "parser.tab.cc"
    break;

  case 52: // relational_expression: relational_expression LE_OP additive_expression
#line 585 "parser.yy"
                                                 {
    if(Symbols::symTabConstructed){
        std::string op = "LE_OP?";
        if(!op_binary_astnode::operandsCompatible(op,yystack_[2].value.as < op_binary_astnode* > (),yystack_[0].value.as < op_binary_astnode* > ())){
            error(yylhs.location,"Incompatible operands for "+op+": \""+yystack_[2].value.as < op_binary_astnode* > ()->typeNode.typeName+"\", \""+yystack_[0].value.as < op_binary_astnode* > ()->typeNode.typeName+"\"");
        }
        yylhs.value.as < op_binary_astnode* > () = new op_binary_astnode(op, yystack_[2].value.as < op_binary_astnode* > (), yystack_[0].value.as < op_binary_astnode* > ());
    }
}
#line 2130 "parser.tab.cc"
    break;

  case 53: // relational_expression: relational_expression GE_OP additive_expression
#line 594 "parser.yy"
                                                 {
    if(Symbols::symTabConstructed){
        std::string op = "GE_OP?";
        if(!op_binary_astnode::operandsCompatible(op,yystack_[2].value.as < op_binary_astnode* > (),yystack_[0].value.as < op_binary_astnode* > ())){
            error(yylhs.location,"Incompatible operands for "+op+": \""+yystack_[2].value.as < op_binary_astnode* > ()->typeNode.typeName+"\", \""+yystack_[0].value.as < op_binary_astnode* > ()->typeNode.typeName+"\"");
        }
        yylhs.value.as < op_binary_astnode* > () = new op_binary_astnode(op, yystack_[2].value.as < op_binary_astnode* > (), yystack_[0].value.as < op_binary_astnode* > ());
    }
}
#line 2144 "parser.tab.cc"
    break;

  case 54: // additive_expression: multiplicative_expression
#line 605 "parser.yy"
                                              {
    yylhs.value.as < op_binary_astnode* > () = yystack_[0].value.as < op_binary_astnode* > ();
    // std::cerr<<__LINE__<<$$->typeNode.typeName<<endl;
}
#line 2153 "parser.tab.cc"
    break;

  case 55: // additive_expression: additive_expression '+' multiplicative_expression
#line 609 "parser.yy"
                                                   {
    if(Symbols::symTabConstructed){
        std::string op = "PLUS?";
        if(!op_binary_astnode::operandsCompatible(op,yystack_[2].value.as < op_binary_astnode* > (),yystack_[0].value.as < op_binary_astnode* > ())){
            error(yylhs.location,"Incompatible operands for "+op+": \""+yystack_[2].value.as < op_binary_astnode* > ()->typeNode.typeName+"\", \""+yystack_[0].value.as < op_binary_astnode* > ()->typeNode.typeName+"\"");
        }
        yylhs.value.as < op_binary_astnode* > () = new op_binary_astnode(op, yystack_[2].value.as < op_binary_astnode* > (), yystack_[0].value.as < op_binary_astnode* > ());
    }
}
#line 2167 "parser.tab.cc"
    break;

  case 56: // additive_expression: additive_expression '-' multiplicative_expression
#line 618 "parser.yy"
                                                   {
    if(Symbols::symTabConstructed){
        std::string op = "MINUS?";
        if(!op_binary_astnode::operandsCompatible(op,yystack_[2].value.as < op_binary_astnode* > (),yystack_[0].value.as < op_binary_astnode* > ())){
            error(yylhs.location,"Incompatible operands for "+op+": \""+yystack_[2].value.as < op_binary_astnode* > ()->typeNode.typeName+"\", \""+yystack_[0].value.as < op_binary_astnode* > ()->typeNode.typeName+"\"");
        }
        yylhs.value.as < op_binary_astnode* > () = new op_binary_astnode(op, yystack_[2].value.as < op_binary_astnode* > (), yystack_[0].value.as < op_binary_astnode* > ());
    }
}
#line 2181 "parser.tab.cc"
    break;

  case 57: // unary_expression: postfix_expression
#line 629 "parser.yy"
                                    {
    yylhs.value.as < exp_astnode* > () = yystack_[0].value.as < exp_astnode* > ();
    // std::cerr<<__LINE__<<$$->typeNode.typeName<<endl;
}
#line 2190 "parser.tab.cc"
    break;

  case 58: // unary_expression: unary_operator unary_expression
#line 633 "parser.yy"
                                 {
    if(Symbols::symTabConstructed){
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
        }
    }
}
#line 2213 "parser.tab.cc"
    break;

  case 59: // multiplicative_expression: unary_expression
#line 653 "parser.yy"
                                           {
    if(Symbols::symTabConstructed){   
        yylhs.value.as < op_binary_astnode* > () = (op_binary_astnode*) yystack_[0].value.as < exp_astnode* > ();
    }

}
#line 2224 "parser.tab.cc"
    break;

  case 60: // multiplicative_expression: multiplicative_expression '*' unary_expression
#line 659 "parser.yy"
                                                {
    //operator and expression match check here.
    if(Symbols::symTabConstructed){
        std::string op = "MULT?";
        if(!op_binary_astnode::operandsCompatible(op,yystack_[2].value.as < op_binary_astnode* > (),yystack_[0].value.as < exp_astnode* > ())){
            error(yylhs.location,"Incompatible operands for "+op+": \""+yystack_[2].value.as < op_binary_astnode* > ()->typeNode.typeName+"\", \""+yystack_[0].value.as < exp_astnode* > ()->typeNode.typeName+"\"");
        }
        yylhs.value.as < op_binary_astnode* > () = new op_binary_astnode(op, yystack_[2].value.as < op_binary_astnode* > (), yystack_[0].value.as < exp_astnode* > ());
    }
}
#line 2239 "parser.tab.cc"
    break;

  case 61: // multiplicative_expression: multiplicative_expression '/' unary_expression
#line 669 "parser.yy"
                                                {
    if(Symbols::symTabConstructed){
        std::string op = "DIV?";
        if(!op_binary_astnode::operandsCompatible(op,yystack_[2].value.as < op_binary_astnode* > (),yystack_[0].value.as < exp_astnode* > ())){
            error(yylhs.location,"Incompatible operands for "+op+": \""+yystack_[2].value.as < op_binary_astnode* > ()->typeNode.typeName+"\", \""+yystack_[0].value.as < exp_astnode* > ()->typeNode.typeName+"\"");
        }
        yylhs.value.as < op_binary_astnode* > () = new op_binary_astnode(op, yystack_[2].value.as < op_binary_astnode* > (), yystack_[0].value.as < exp_astnode* > ());
    }
}
#line 2253 "parser.tab.cc"
    break;

  case 62: // postfix_expression: primary_expression
#line 680 "parser.yy"
                                      {
    yylhs.value.as < exp_astnode* > () = yystack_[0].value.as < exp_astnode* > ();
}
#line 2261 "parser.tab.cc"
    break;

  case 63: // postfix_expression: postfix_expression '[' expression ']'
#line 683 "parser.yy"
                                       {
    if(Symbols::symTabConstructed){   
        yylhs.value.as < exp_astnode* > () = new arrayref_astnode(yystack_[3].value.as < exp_astnode* > (), yystack_[1].value.as < exp_astnode* > ());
    }
}
#line 2271 "parser.tab.cc"
    break;

  case 64: // postfix_expression: IDENTIFIER '(' ')'
#line 688 "parser.yy"
                    {
    if (Symbols::symTabConstructed) {
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
}
#line 2302 "parser.tab.cc"
    break;

  case 65: // postfix_expression: IDENTIFIER '(' expression_list ')'
#line 714 "parser.yy"
                                    {
    if (Symbols::symTabConstructed) {
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
            yylhs.value.as < exp_astnode* > () = new funcall_astnode(new identifier_astnode(yystack_[3].value.as < std::string > ()), exp_list, false);
            yylhs.value.as < exp_astnode* > ()->typeNode = Symbols::getSymEntry(Symbols::gst, yystack_[3].value.as < std::string > ())->type;
        }
        else {
            yylhs.value.as < exp_astnode* > () = new funcall_astnode(new identifier_astnode(yystack_[3].value.as < std::string > ()), yystack_[1].value.as < std::vector<exp_astnode*> > (), false);
            yylhs.value.as < exp_astnode* > ()->typeNode = voidc;
        }
    }
}
#line 2350 "parser.tab.cc"
    break;

  case 66: // postfix_expression: postfix_expression '.' IDENTIFIER
#line 757 "parser.yy"
                                   {
    if(Symbols::symTabConstructed){
        yylhs.value.as < exp_astnode* > () = new member_astnode(yystack_[2].value.as < exp_astnode* > (), new identifier_astnode(yystack_[0].value.as < std::string > ()));
        std::cerr<<"using this rule"<<std::endl;
        std::string structName = yystack_[2].value.as < exp_astnode* > ()->typeNode.typeName;
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
}
#line 2371 "parser.tab.cc"
    break;

  case 67: // postfix_expression: postfix_expression PTR_OP IDENTIFIER
#line 773 "parser.yy"
                                      {
    if(Symbols::symTabConstructed){
        yylhs.value.as < exp_astnode* > () = new arrow_astnode(yystack_[2].value.as < exp_astnode* > (), new identifier_astnode(yystack_[0].value.as < std::string > ()));
        typespec_astnode dereftype = yystack_[2].value.as < exp_astnode* > ()->typeNode;
        dereftype.deref();
        std::string structName  = dereftype.typeName;
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
}
#line 2393 "parser.tab.cc"
    break;

  case 68: // postfix_expression: postfix_expression INC_OP
#line 790 "parser.yy"
                           {
    if(Symbols::symTabConstructed){
        //type checks for $1
        
        yylhs.value.as < exp_astnode* > () = new op_unary_astnode("PP",yystack_[1].value.as < exp_astnode* > ());
        yylhs.value.as < exp_astnode* > ()->typeNode = yystack_[1].value.as < exp_astnode* > ()->typeNode;
    }
}
#line 2406 "parser.tab.cc"
    break;

  case 69: // primary_expression: IDENTIFIER
#line 800 "parser.yy"
                              {
    if(Symbols::symTabConstructed){
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
    std::cerr<<"bloom"<<std::endl;
}
#line 2427 "parser.tab.cc"
    break;

  case 70: // primary_expression: INT_CONSTANT
#line 816 "parser.yy"
              {
    if(Symbols::symTabConstructed){   
        yylhs.value.as < exp_astnode* > () = new intconst_astnode(yystack_[0].value.as < std::string > ());
        yylhs.value.as < exp_astnode* > ()->typeNode = intc;
        yylhs.value.as < exp_astnode* > ()->typeNode.islval = false;
        if(yystack_[0].value.as < std::string > ()=="0"){
            yylhs.value.as < exp_astnode* > ()->typeNode.isnullval = true;
        }
    }
}
#line 2442 "parser.tab.cc"
    break;

  case 71: // primary_expression: FLOAT_CONSTANT
#line 826 "parser.yy"
                {
    if(Symbols::symTabConstructed){   
        yylhs.value.as < exp_astnode* > () = new floatconst_astnode(yystack_[0].value.as < std::string > ());
        yylhs.value.as < exp_astnode* > ()->typeNode = floatc;
        yylhs.value.as < exp_astnode* > ()->typeNode.islval = false;
    }
}
#line 2454 "parser.tab.cc"
    break;

  case 72: // primary_expression: STRING_LITERAL
#line 833 "parser.yy"
                {
    if(Symbols::symTabConstructed){   
        yylhs.value.as < exp_astnode* > () = new stringconst_astnode(yystack_[0].value.as < std::string > ());
        yylhs.value.as < exp_astnode* > ()->typeNode = stringc;
        yylhs.value.as < exp_astnode* > ()->typeNode.islval = false;
        // $$->print();
    }
}
#line 2467 "parser.tab.cc"
    break;

  case 73: // primary_expression: '(' expression ')'
#line 841 "parser.yy"
                    {
    yylhs.value.as < exp_astnode* > () = yystack_[1].value.as < exp_astnode* > ();
}
#line 2475 "parser.tab.cc"
    break;

  case 74: // expression_list: expression
#line 846 "parser.yy"
                           {
    yylhs.value.as < std::vector<exp_astnode*> > () = std::vector<exp_astnode*>();
    yylhs.value.as < std::vector<exp_astnode*> > ().push_back(yystack_[0].value.as < exp_astnode* > ());
    // std::cerr << __LINE__ << (*($$.rbegin()))->typeNode.typeName<<std::endl;
}
#line 2485 "parser.tab.cc"
    break;

  case 75: // expression_list: expression_list ',' expression
#line 851 "parser.yy"
                                {
    yystack_[2].value.as < std::vector<exp_astnode*> > ().push_back(yystack_[0].value.as < exp_astnode* > ());
    yylhs.value.as < std::vector<exp_astnode*> > () = yystack_[2].value.as < std::vector<exp_astnode*> > ();
}
#line 2494 "parser.tab.cc"
    break;

  case 76: // unary_operator: '-'
#line 856 "parser.yy"
                   {
    yylhs.value.as < std::string > () = std::string("UMINUS");
}
#line 2502 "parser.tab.cc"
    break;

  case 77: // unary_operator: '!'
#line 859 "parser.yy"
     {
    yylhs.value.as < std::string > () = std::string("NOT");
}
#line 2510 "parser.tab.cc"
    break;

  case 78: // unary_operator: '&'
#line 862 "parser.yy"
     {
    yylhs.value.as < std::string > () = std::string("ADDRESS");
}
#line 2518 "parser.tab.cc"
    break;

  case 79: // unary_operator: '*'
#line 865 "parser.yy"
     {
    yylhs.value.as < std::string > () = std::string("DEREF");
}
#line 2526 "parser.tab.cc"
    break;

  case 80: // selection_statement: IF '(' expression ')' statement ELSE statement
#line 870 "parser.yy"
                                                                   {
    if(Symbols::symTabConstructed){   
        yylhs.value.as < statement_astnode* > () = new if_astnode(yystack_[4].value.as < exp_astnode* > (), yystack_[2].value.as < statement_astnode* > (), yystack_[0].value.as < statement_astnode* > ());
    }
}
#line 2536 "parser.tab.cc"
    break;

  case 81: // iteration_statement: WHILE '(' expression ')' statement
#line 877 "parser.yy"
                                                       {
    if(Symbols::symTabConstructed){   
        yylhs.value.as < statement_astnode* > () = new while_astnode(yystack_[2].value.as < exp_astnode* > (), yystack_[0].value.as < statement_astnode* > ());
    }
}
#line 2546 "parser.tab.cc"
    break;

  case 82: // iteration_statement: FOR '(' assignment_expression ';' expression ';' assignment_expression ')' statement
#line 882 "parser.yy"
                                                                                      {
    if(Symbols::symTabConstructed){   
        yylhs.value.as < statement_astnode* > () = new for_astnode(yystack_[6].value.as < assignE_astnode* > (), yystack_[4].value.as < exp_astnode* > (), yystack_[2].value.as < assignE_astnode* > (), yystack_[0].value.as < statement_astnode* > ());
    }
}
#line 2556 "parser.tab.cc"
    break;

  case 83: // declaration_list: declaration
#line 889 "parser.yy"
                             {
}
#line 2563 "parser.tab.cc"
    break;

  case 84: // declaration_list: declaration_list declaration
#line 891 "parser.yy"
                              {
}
#line 2570 "parser.tab.cc"
    break;

  case 85: // declaration: type_specifier declarator_list ';'
#line 895 "parser.yy"
                                               {
}
#line 2577 "parser.tab.cc"
    break;

  case 86: // declarator_list: declarator
#line 899 "parser.yy"
                           {
    yylhs.value.as < typespec_astnode > () = yystack_[0].value.as < typespec_astnode > ();
    // std::cerr<<$1.typeName<<" has "<<$1.numptrstars<<" stars"<<std::endl;
    string type = yystack_[0].value.as < typespec_astnode > ().typeName;
    int size = yystack_[0].value.as < typespec_astnode > ().typeWidth;
    if(!Symbols::symTabConstructed){
        // std::cerr<<topvarname<<": "<<size<<" "<<std::endl;
        int offset = ststack.top()->getNewOffset(size);
        SymTab* st = ststack.top();
        if(yystack_[0].value.as < typespec_astnode > ().typeName=="void"){
            error(yylhs.location,"Cannot declare variable of type \"void\"");
        }
        st->rows[topvarname] = SymEntry(yystack_[0].value.as < typespec_astnode > (),SymTab::ST_HL_type::VAR,SymTab::ST_LPG::LOCAL,size,offset);
    }
}
#line 2597 "parser.tab.cc"
    break;

  case 87: // declarator_list: declarator_list ',' declarator
#line 914 "parser.yy"
                                {
    yylhs.value.as < typespec_astnode > () = yystack_[0].value.as < typespec_astnode > ();
    string type = yystack_[0].value.as < typespec_astnode > ().typeName;
    int size = yystack_[0].value.as < typespec_astnode > ().typeWidth;
    if(!Symbols::symTabConstructed){
        if(yystack_[0].value.as < typespec_astnode > ().typeName=="void"){
            error(yylhs.location,"Cannot declare variable of type \"void\"");
        }
        int offset = ststack.top()->getNewOffset(size);
        ststack.top()->rows[topvarname] = SymEntry(yystack_[0].value.as < typespec_astnode > (),SymTab::ST_HL_type::VAR,SymTab::ST_LPG::LOCAL,size,offset);
    }
}
#line 2614 "parser.tab.cc"
    break;


#line 2618 "parser.tab.cc"

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









  const signed char Parser::yypact_ninf_ = -62;

  const signed char Parser::yytable_ninf_ = -15;

  const short
  Parser::yypact_[] =
  {
     -62,    18,    81,   -62,   -62,   -62,   -62,    14,    81,   -62,
     -62,    17,    22,   -62,   -62,    13,    24,    34,    40,   123,
     -62,   105,   -62,   105,    48,    67,   -62,   -62,   -62,    73,
      86,    88,   310,   -62,   -62,   310,   267,   -62,   -62,   -62,
     -62,    12,    42,   -62,    78,   -62,   -62,    91,    -2,   -62,
     310,   -62,   -62,   162,   -62,     8,    12,    92,    90,   -62,
     272,   310,   310,   310,    94,    -4,   113,    60,    62,    56,
     -62,    61,     9,   197,   -62,    12,   103,   -62,    21,   -62,
     -62,   -62,   310,   -62,   134,   310,   140,   -62,   -62,   232,
     -62,   107,   -62,   -62,   105,   110,   141,    68,    15,    16,
     114,   304,   310,   -62,   310,   310,   310,   310,   310,   310,
     310,   310,   310,   310,   310,   -62,   -62,   -62,   146,    12,
     -62,   141,   -62,    -6,   -62,   -62,   -62,   -62,   -62,   117,
     310,   267,   267,   310,   -62,    74,   113,    60,    62,    62,
      56,    56,    56,    56,    61,    61,   -62,   -62,   126,   -62,
     -62,   -62,   141,   139,   -62,    -3,   -62,   -62,   267,   310,
     -62,   132,   267,   -62
  };

  const signed char
  Parser::yydefact_[] =
  {
       2,     0,     0,     1,    11,    12,    13,     0,     3,     4,
       5,     0,     8,     6,     7,     0,     0,     0,    15,     0,
      10,     0,    17,     0,     0,    69,    70,    71,    72,     0,
       0,     0,     0,    76,    79,     0,     0,    25,    77,    78,
      31,     0,     0,    29,     0,    35,    36,     0,    57,    62,
       0,    33,    34,     0,    83,     0,     0,     0,    18,    14,
       0,     0,     0,     0,    69,     0,    42,    44,    46,    49,
      59,    54,     0,     0,    21,     0,    23,    86,     0,    26,
      30,    39,     0,    68,     0,     0,     0,    58,    27,     0,
      84,     0,    20,    16,     0,    64,    74,     0,     0,     0,
       0,     0,     0,    37,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    73,    32,    24,     0,     0,
      85,    38,    67,     0,    66,    28,     9,    19,    40,    65,
       0,     0,     0,     0,    64,     0,    43,    45,    47,    48,
      52,    53,    50,    51,    55,    56,    60,    61,     0,    87,
      63,    41,    75,     0,    81,     0,    65,    22,     0,     0,
      80,     0,     0,    82
  };

  const short
  Parser::yypgoto_[] =
  {
     -62,   -62,   -62,   -62,   165,   -62,   166,     2,   -62,   -62,
      82,   -62,   -62,   -53,   -62,    -8,   -41,   -61,   -62,   -62,
     -26,    75,    71,   -13,    27,   -19,     3,   -62,   -62,    77,
     -62,   -62,   -62,   158,     5,   -62
  };

  const signed char
  Parser::yydefgoto_[] =
  {
       0,     1,     2,     8,     9,    17,    10,    41,    16,    23,
      57,    58,    76,    77,    20,    42,    43,    44,    45,    46,
      96,    66,    67,    68,    69,    70,    71,    48,    49,    97,
      50,    51,    52,    53,    54,    78
  };

  const short
  Parser::yytable_[] =
  {
      47,    80,   100,    92,    11,   102,    65,   102,   102,    72,
      11,     4,     5,     6,    24,    83,    84,    47,     3,    74,
     102,    12,   117,    47,    15,    56,   102,   102,    73,   -14,
     150,    87,    80,    85,    47,    98,    99,   103,   159,    75,
     115,    86,    91,    18,    47,    89,   131,   132,    80,    25,
      26,    27,    28,   119,    47,    59,   121,    19,    90,   123,
      90,    29,   120,    30,    31,    32,   149,    21,    33,    34,
      47,    22,    35,   105,   106,    36,    79,   107,   108,    38,
      39,   111,   112,    40,     4,     5,     6,     7,   113,   114,
     153,   154,   138,   139,   146,   147,    56,    60,   161,   129,
     130,   109,   110,    61,   152,   156,   130,   155,     4,     5,
       6,    24,    47,    47,   144,   145,    62,   160,    63,    81,
      82,   163,    94,    93,   101,   104,     4,     5,     6,    24,
      25,    26,    27,    28,   140,   141,   142,   143,   118,    47,
      47,   122,    29,    47,    30,    31,    32,   124,   126,    33,
      34,   128,   102,    35,   148,   133,    36,    37,   151,   158,
      38,    39,   157,   162,    40,     4,     5,     6,    24,    25,
      26,    27,    28,    13,    14,   137,   127,   136,   135,    55,
       0,    29,     0,    30,    31,    32,     0,     0,    33,    34,
       0,     0,    35,     0,     0,    36,    88,     0,     0,    38,
      39,     0,     0,    40,    25,    26,    27,    28,     0,     0,
       0,     0,     0,     0,     0,     0,    29,     0,    30,    31,
      32,     0,     0,    33,    34,     0,     0,    35,     0,     0,
      36,   116,     0,     0,    38,    39,     0,     0,    40,    25,
      26,    27,    28,     0,     0,     0,     0,     0,     0,     0,
       0,    29,     0,    30,    31,    32,     0,     0,    33,    34,
       0,     0,    35,     0,     0,    36,   125,     0,     0,    38,
      39,     0,     0,    40,    25,    26,    27,    28,     0,    64,
      26,    27,    28,     0,     0,     0,    29,     0,    30,    31,
      32,     0,     0,    33,    34,     0,     0,    35,    33,    34,
      36,     0,    35,    95,    38,    39,     0,     0,    40,    38,
      39,    64,    26,    27,    28,     0,     0,    64,    26,    27,
      28,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      33,    34,     0,     0,    35,   134,    33,    34,     0,     0,
      35,    38,    39,     0,     0,     0,     0,    38,    39
  };

  const short
  Parser::yycheck_[] =
  {
      19,    42,    63,    56,     2,    11,    32,    11,    11,    35,
       8,     3,     4,     5,     6,    17,    18,    36,     0,     7,
      11,     7,    75,    42,     7,    23,    11,    11,    36,     7,
      36,    50,    73,    35,    53,    61,    62,    41,    41,    27,
      31,    43,    34,    30,    63,    53,    31,    31,    89,     7,
       8,     9,    10,    32,    73,     7,    82,    33,    53,    85,
      55,    19,    41,    21,    22,    23,   119,    33,    26,    27,
      89,    31,    30,    13,    14,    33,    34,    15,    16,    37,
      38,    25,    26,    41,     3,     4,     5,     6,    27,    28,
     131,   132,   105,   106,   113,   114,    94,    30,   159,    31,
      32,    39,    40,    30,   130,    31,    32,   133,     3,     4,
       5,     6,   131,   132,   111,   112,    30,   158,    30,    41,
      29,   162,    32,    31,    30,    12,     3,     4,     5,     6,
       7,     8,     9,    10,   107,   108,   109,   110,    35,   158,
     159,     7,    19,   162,    21,    22,    23,     7,    41,    26,
      27,    41,    11,    30,     8,    41,    33,    34,    41,    20,
      37,    38,    36,    31,    41,     3,     4,     5,     6,     7,
       8,     9,    10,     8,     8,   104,    94,   102,   101,    21,
      -1,    19,    -1,    21,    22,    23,    -1,    -1,    26,    27,
      -1,    -1,    30,    -1,    -1,    33,    34,    -1,    -1,    37,
      38,    -1,    -1,    41,     7,     8,     9,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,    21,    22,
      23,    -1,    -1,    26,    27,    -1,    -1,    30,    -1,    -1,
      33,    34,    -1,    -1,    37,    38,    -1,    -1,    41,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    -1,    21,    22,    23,    -1,    -1,    26,    27,
      -1,    -1,    30,    -1,    -1,    33,    34,    -1,    -1,    37,
      38,    -1,    -1,    41,     7,     8,     9,    10,    -1,     7,
       8,     9,    10,    -1,    -1,    -1,    19,    -1,    21,    22,
      23,    -1,    -1,    26,    27,    -1,    -1,    30,    26,    27,
      33,    -1,    30,    31,    37,    38,    -1,    -1,    41,    37,
      38,     7,     8,     9,    10,    -1,    -1,     7,     8,     9,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      26,    27,    -1,    -1,    30,    31,    26,    27,    -1,    -1,
      30,    37,    38,    -1,    -1,    -1,    -1,    37,    38
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    45,    46,     0,     3,     4,     5,     6,    47,    48,
      50,    51,     7,    48,    50,     7,    52,    49,    30,    33,
      58,    33,    31,    53,     6,     7,     8,     9,    10,    19,
      21,    22,    23,    26,    27,    30,    33,    34,    37,    38,
      41,    51,    59,    60,    61,    62,    63,    69,    71,    72,
      74,    75,    76,    77,    78,    77,    51,    54,    55,     7,
      30,    30,    30,    30,     7,    64,    65,    66,    67,    68,
      69,    70,    64,    59,     7,    27,    56,    57,    79,    34,
      60,    41,    29,    17,    18,    35,    43,    69,    34,    59,
      78,    34,    57,    31,    32,    31,    64,    73,    64,    64,
      61,    30,    11,    41,    12,    13,    14,    15,    16,    39,
      40,    25,    26,    27,    28,    31,    34,    57,    35,    32,
      41,    64,     7,    64,     7,    34,    41,    54,    41,    31,
      32,    31,    31,    41,    31,    73,    65,    66,    67,    67,
      68,    68,    68,    68,    70,    70,    69,    69,     8,    57,
      36,    41,    64,    60,    60,    64,    31,    36,    20,    41,
      60,    61,    31,    60
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    44,    46,    45,    47,    47,    47,    47,    49,    48,
      50,    51,    51,    51,    51,    53,    52,    52,    54,    54,
      55,    56,    56,    57,    57,    58,    58,    58,    58,    59,
      59,    60,    60,    60,    60,    60,    60,    60,    61,    62,
      63,    63,    64,    64,    65,    65,    66,    66,    66,    67,
      67,    67,    67,    67,    68,    68,    68,    69,    69,    70,
      70,    70,    71,    71,    71,    71,    71,    71,    71,    72,
      72,    72,    72,    72,    73,    73,    74,    74,    74,    74,
      75,    76,    76,    77,    77,    78,    79,    79
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     0,     2,     1,     1,     2,     2,     0,     7,
       3,     1,     1,     1,     2,     0,     5,     3,     1,     3,
       2,     1,     4,     1,     2,     2,     3,     3,     4,     1,
       2,     1,     3,     1,     1,     1,     1,     3,     3,     2,
       4,     5,     1,     3,     1,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     2,     1,
       3,     3,     1,     4,     3,     4,     3,     3,     2,     1,
       1,     1,     1,     3,     1,     3,     1,     1,     1,     1,
       7,     5,     9,     1,     2,     3,     1,     3
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
  "INC_OP", "PTR_OP", "IF", "ELSE", "WHILE", "FOR", "RETURN", "OTHERS",
  "'+'", "'-'", "'*'", "'/'", "'='", "'('", "')'", "','", "'{'", "'}'",
  "'['", "']'", "'!'", "'&'", "'<'", "'>'", "';'", "'\\n'", "'.'",
  "$accept", "begin_nterm", "$@1", "translation_unit", "struct_specifier",
  "$@2", "function_definition", "type_specifier", "fun_declarator", "$@3",
  "parameter_list", "parameter_declaration", "declarator_arr",
  "declarator", "compound_statement", "statement_list", "statement",
  "assignment_expression", "assignment_statement", "procedure_call",
  "expression", "logical_and_expression", "equality_expression",
  "relational_expression", "additive_expression", "unary_expression",
  "multiplicative_expression", "postfix_expression", "primary_expression",
  "expression_list", "unary_operator", "selection_statement",
  "iteration_statement", "declaration_list", "declaration",
  "declarator_list", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const short
  Parser::yyrline_[] =
  {
       0,   114,   114,   114,   141,   143,   147,   149,   155,   155,
     176,   184,   196,   205,   213,   227,   227,   259,   275,   281,
     289,   301,   308,   318,   321,   330,   333,   336,   341,   346,
     354,   360,   365,   370,   373,   376,   379,   382,   404,   438,
     445,   472,   517,   521,   528,   532,   539,   543,   552,   563,
     567,   576,   585,   594,   605,   609,   618,   629,   633,   653,
     659,   669,   680,   683,   688,   714,   757,   773,   790,   800,
     816,   826,   833,   841,   846,   851,   856,   859,   862,   865,
     870,   877,   882,   889,   891,   895,   899,   914
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
      42,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,     2,     2,     2,     2,    38,     2,
      30,    31,    27,    25,    32,    26,    43,    28,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    41,
      39,    29,    40,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    35,     2,    36,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    33,     2,    34,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24
    };
    // Last valid token kind.
    const int code_max = 279;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 5 "parser.yy"
} // IPL
#line 3128 "parser.tab.cc"

#line 928 "parser.yy"

//grammar definition.
void 
IPL::Parser::error( const location_type &l, const std::string &err_message )
{
   std::cout << "Error at line " << l.begin.line << ": " << err_message << "\n";
   exit(1);
}

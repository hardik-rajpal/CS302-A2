// A Bison parser, made by GNU Bison 3.5.1.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2020 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

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

// Undocumented macros, especially those whose name start with YY_,
// are private implementation details.  Do not rely on them.





#include "parser.tab.hh"


// Unqualified %code blocks.
#line 42 "parser.yy"

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

#line 61 "parser.tab.cc"


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
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE (Symbol)
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
#line 153 "parser.tab.cc"


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

  /*---------------.
  | Symbol types.  |
  `---------------*/

  // basic_symbol.
#if 201103L <= YY_CPLUSPLUS
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (basic_symbol&& that)
    : Base (std::move (that))
    , value ()
    , location (std::move (that.location))
  {
    switch (this->type_get ())
    {
      case 47: // struct_specifier
      case 48: // procedure_call
      case 49: // declaration_list
        value.move< abstract_astnode* > (std::move (that.value));
        break;

      case 60: // assignment_expression
        value.move< assignE_astnode* > (std::move (that.value));
        break;

      case 50: // expression
      case 51: // logical_and_expression
      case 52: // equality_expression
      case 53: // relational_expression
      case 54: // additive_expression
      case 55: // unary_expression
      case 56: // multiplicative_expression
      case 57: // postfix_expression
      case 58: // primary_expression
      case 59: // expression_list
        value.move< exp_astnode* > (std::move (that.value));
        break;

      case 76: // fun_declarator
        value.move< fundeclarator_astnode* > (std::move (that.value));
        break;

      case 61: // function_definition
      case 62: // statement
      case 63: // selection_statement
      case 64: // iteration_statement
      case 65: // assignment_statement
        value.move< statement_astnode* > (std::move (that.value));
        break;

      case 3: // VOID
      case 4: // INT
      case 5: // FLOAT
      case 6: // STRUCT
      case 7: // IDENTIFIER
      case 8: // INT_CONSTANT
      case 9: // FLOAT_CONSTANT
      case 10: // STRING_LITERAL
      case 11: // OR_OP
      case 12: // AND_OP
      case 13: // EQ_OP
      case 14: // NE_OP
      case 15: // LE_OP
      case 16: // GE_OP
      case 17: // INC_OP
      case 18: // PTR_OP
      case 19: // IF
      case 20: // ELSE
      case 21: // WHILE
      case 22: // FOR
      case 23: // RETURN
      case 24: // OTHERS
      case 68: // unary_operator
        value.move< std::string > (std::move (that.value));
        break;

      case 45: // translation_unit
      case 46: // begin_nterm
        value.move< std::vector<abstract_astnode*> > (std::move (that.value));
        break;

      case 66: // compound_statement
      case 67: // statement_list
        value.move< std::vector<statement_astnode*> > (std::move (that.value));
        break;

      case 75: // parameter_list
        value.move< std::vector<typespec_astnode> > (std::move (that.value));
        break;

      case 69: // type_specifier
      case 70: // declaration
      case 71: // declarator_list
      case 72: // declarator
      case 73: // declarator_arr
      case 74: // parameter_declaration
        value.move< typespec_astnode > (std::move (that.value));
        break;

      default:
        break;
    }

  }
#endif

  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
    , location (that.location)
  {
    switch (this->type_get ())
    {
      case 47: // struct_specifier
      case 48: // procedure_call
      case 49: // declaration_list
        value.copy< abstract_astnode* > (YY_MOVE (that.value));
        break;

      case 60: // assignment_expression
        value.copy< assignE_astnode* > (YY_MOVE (that.value));
        break;

      case 50: // expression
      case 51: // logical_and_expression
      case 52: // equality_expression
      case 53: // relational_expression
      case 54: // additive_expression
      case 55: // unary_expression
      case 56: // multiplicative_expression
      case 57: // postfix_expression
      case 58: // primary_expression
      case 59: // expression_list
        value.copy< exp_astnode* > (YY_MOVE (that.value));
        break;

      case 76: // fun_declarator
        value.copy< fundeclarator_astnode* > (YY_MOVE (that.value));
        break;

      case 61: // function_definition
      case 62: // statement
      case 63: // selection_statement
      case 64: // iteration_statement
      case 65: // assignment_statement
        value.copy< statement_astnode* > (YY_MOVE (that.value));
        break;

      case 3: // VOID
      case 4: // INT
      case 5: // FLOAT
      case 6: // STRUCT
      case 7: // IDENTIFIER
      case 8: // INT_CONSTANT
      case 9: // FLOAT_CONSTANT
      case 10: // STRING_LITERAL
      case 11: // OR_OP
      case 12: // AND_OP
      case 13: // EQ_OP
      case 14: // NE_OP
      case 15: // LE_OP
      case 16: // GE_OP
      case 17: // INC_OP
      case 18: // PTR_OP
      case 19: // IF
      case 20: // ELSE
      case 21: // WHILE
      case 22: // FOR
      case 23: // RETURN
      case 24: // OTHERS
      case 68: // unary_operator
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case 45: // translation_unit
      case 46: // begin_nterm
        value.copy< std::vector<abstract_astnode*> > (YY_MOVE (that.value));
        break;

      case 66: // compound_statement
      case 67: // statement_list
        value.copy< std::vector<statement_astnode*> > (YY_MOVE (that.value));
        break;

      case 75: // parameter_list
        value.copy< std::vector<typespec_astnode> > (YY_MOVE (that.value));
        break;

      case 69: // type_specifier
      case 70: // declaration
      case 71: // declarator_list
      case 72: // declarator
      case 73: // declarator_arr
      case 74: // parameter_declaration
        value.copy< typespec_astnode > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }



  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->type_get ())
    {
      case 47: // struct_specifier
      case 48: // procedure_call
      case 49: // declaration_list
        value.move< abstract_astnode* > (YY_MOVE (s.value));
        break;

      case 60: // assignment_expression
        value.move< assignE_astnode* > (YY_MOVE (s.value));
        break;

      case 50: // expression
      case 51: // logical_and_expression
      case 52: // equality_expression
      case 53: // relational_expression
      case 54: // additive_expression
      case 55: // unary_expression
      case 56: // multiplicative_expression
      case 57: // postfix_expression
      case 58: // primary_expression
      case 59: // expression_list
        value.move< exp_astnode* > (YY_MOVE (s.value));
        break;

      case 76: // fun_declarator
        value.move< fundeclarator_astnode* > (YY_MOVE (s.value));
        break;

      case 61: // function_definition
      case 62: // statement
      case 63: // selection_statement
      case 64: // iteration_statement
      case 65: // assignment_statement
        value.move< statement_astnode* > (YY_MOVE (s.value));
        break;

      case 3: // VOID
      case 4: // INT
      case 5: // FLOAT
      case 6: // STRUCT
      case 7: // IDENTIFIER
      case 8: // INT_CONSTANT
      case 9: // FLOAT_CONSTANT
      case 10: // STRING_LITERAL
      case 11: // OR_OP
      case 12: // AND_OP
      case 13: // EQ_OP
      case 14: // NE_OP
      case 15: // LE_OP
      case 16: // GE_OP
      case 17: // INC_OP
      case 18: // PTR_OP
      case 19: // IF
      case 20: // ELSE
      case 21: // WHILE
      case 22: // FOR
      case 23: // RETURN
      case 24: // OTHERS
      case 68: // unary_operator
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case 45: // translation_unit
      case 46: // begin_nterm
        value.move< std::vector<abstract_astnode*> > (YY_MOVE (s.value));
        break;

      case 66: // compound_statement
      case 67: // statement_list
        value.move< std::vector<statement_astnode*> > (YY_MOVE (s.value));
        break;

      case 75: // parameter_list
        value.move< std::vector<typespec_astnode> > (YY_MOVE (s.value));
        break;

      case 69: // type_specifier
      case 70: // declaration
      case 71: // declarator_list
      case 72: // declarator
      case 73: // declarator_arr
      case 74: // parameter_declaration
        value.move< typespec_astnode > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

    location = YY_MOVE (s.location);
  }

  // by_type.
  Parser::by_type::by_type ()
    : type (empty_symbol)
  {}

#if 201103L <= YY_CPLUSPLUS
  Parser::by_type::by_type (by_type&& that)
    : type (that.type)
  {
    that.clear ();
  }
#endif

  Parser::by_type::by_type (const by_type& that)
    : type (that.type)
  {}

  Parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  void
  Parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  void
  Parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  int
  Parser::by_type::type_get () const YY_NOEXCEPT
  {
    return type;
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

  Parser::symbol_number_type
  Parser::by_state::type_get () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[+state];
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.type_get ())
    {
      case 47: // struct_specifier
      case 48: // procedure_call
      case 49: // declaration_list
        value.YY_MOVE_OR_COPY< abstract_astnode* > (YY_MOVE (that.value));
        break;

      case 60: // assignment_expression
        value.YY_MOVE_OR_COPY< assignE_astnode* > (YY_MOVE (that.value));
        break;

      case 50: // expression
      case 51: // logical_and_expression
      case 52: // equality_expression
      case 53: // relational_expression
      case 54: // additive_expression
      case 55: // unary_expression
      case 56: // multiplicative_expression
      case 57: // postfix_expression
      case 58: // primary_expression
      case 59: // expression_list
        value.YY_MOVE_OR_COPY< exp_astnode* > (YY_MOVE (that.value));
        break;

      case 76: // fun_declarator
        value.YY_MOVE_OR_COPY< fundeclarator_astnode* > (YY_MOVE (that.value));
        break;

      case 61: // function_definition
      case 62: // statement
      case 63: // selection_statement
      case 64: // iteration_statement
      case 65: // assignment_statement
        value.YY_MOVE_OR_COPY< statement_astnode* > (YY_MOVE (that.value));
        break;

      case 3: // VOID
      case 4: // INT
      case 5: // FLOAT
      case 6: // STRUCT
      case 7: // IDENTIFIER
      case 8: // INT_CONSTANT
      case 9: // FLOAT_CONSTANT
      case 10: // STRING_LITERAL
      case 11: // OR_OP
      case 12: // AND_OP
      case 13: // EQ_OP
      case 14: // NE_OP
      case 15: // LE_OP
      case 16: // GE_OP
      case 17: // INC_OP
      case 18: // PTR_OP
      case 19: // IF
      case 20: // ELSE
      case 21: // WHILE
      case 22: // FOR
      case 23: // RETURN
      case 24: // OTHERS
      case 68: // unary_operator
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case 45: // translation_unit
      case 46: // begin_nterm
        value.YY_MOVE_OR_COPY< std::vector<abstract_astnode*> > (YY_MOVE (that.value));
        break;

      case 66: // compound_statement
      case 67: // statement_list
        value.YY_MOVE_OR_COPY< std::vector<statement_astnode*> > (YY_MOVE (that.value));
        break;

      case 75: // parameter_list
        value.YY_MOVE_OR_COPY< std::vector<typespec_astnode> > (YY_MOVE (that.value));
        break;

      case 69: // type_specifier
      case 70: // declaration
      case 71: // declarator_list
      case 72: // declarator
      case 73: // declarator_arr
      case 74: // parameter_declaration
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
    switch (that.type_get ())
    {
      case 47: // struct_specifier
      case 48: // procedure_call
      case 49: // declaration_list
        value.move< abstract_astnode* > (YY_MOVE (that.value));
        break;

      case 60: // assignment_expression
        value.move< assignE_astnode* > (YY_MOVE (that.value));
        break;

      case 50: // expression
      case 51: // logical_and_expression
      case 52: // equality_expression
      case 53: // relational_expression
      case 54: // additive_expression
      case 55: // unary_expression
      case 56: // multiplicative_expression
      case 57: // postfix_expression
      case 58: // primary_expression
      case 59: // expression_list
        value.move< exp_astnode* > (YY_MOVE (that.value));
        break;

      case 76: // fun_declarator
        value.move< fundeclarator_astnode* > (YY_MOVE (that.value));
        break;

      case 61: // function_definition
      case 62: // statement
      case 63: // selection_statement
      case 64: // iteration_statement
      case 65: // assignment_statement
        value.move< statement_astnode* > (YY_MOVE (that.value));
        break;

      case 3: // VOID
      case 4: // INT
      case 5: // FLOAT
      case 6: // STRUCT
      case 7: // IDENTIFIER
      case 8: // INT_CONSTANT
      case 9: // FLOAT_CONSTANT
      case 10: // STRING_LITERAL
      case 11: // OR_OP
      case 12: // AND_OP
      case 13: // EQ_OP
      case 14: // NE_OP
      case 15: // LE_OP
      case 16: // GE_OP
      case 17: // INC_OP
      case 18: // PTR_OP
      case 19: // IF
      case 20: // ELSE
      case 21: // WHILE
      case 22: // FOR
      case 23: // RETURN
      case 24: // OTHERS
      case 68: // unary_operator
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case 45: // translation_unit
      case 46: // begin_nterm
        value.move< std::vector<abstract_astnode*> > (YY_MOVE (that.value));
        break;

      case 66: // compound_statement
      case 67: // statement_list
        value.move< std::vector<statement_astnode*> > (YY_MOVE (that.value));
        break;

      case 75: // parameter_list
        value.move< std::vector<typespec_astnode> > (YY_MOVE (that.value));
        break;

      case 69: // type_specifier
      case 70: // declaration
      case 71: // declarator_list
      case 72: // declarator
      case 73: // declarator_arr
      case 74: // parameter_declaration
        value.move< typespec_astnode > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.type_get ())
    {
      case 47: // struct_specifier
      case 48: // procedure_call
      case 49: // declaration_list
        value.copy< abstract_astnode* > (that.value);
        break;

      case 60: // assignment_expression
        value.copy< assignE_astnode* > (that.value);
        break;

      case 50: // expression
      case 51: // logical_and_expression
      case 52: // equality_expression
      case 53: // relational_expression
      case 54: // additive_expression
      case 55: // unary_expression
      case 56: // multiplicative_expression
      case 57: // postfix_expression
      case 58: // primary_expression
      case 59: // expression_list
        value.copy< exp_astnode* > (that.value);
        break;

      case 76: // fun_declarator
        value.copy< fundeclarator_astnode* > (that.value);
        break;

      case 61: // function_definition
      case 62: // statement
      case 63: // selection_statement
      case 64: // iteration_statement
      case 65: // assignment_statement
        value.copy< statement_astnode* > (that.value);
        break;

      case 3: // VOID
      case 4: // INT
      case 5: // FLOAT
      case 6: // STRUCT
      case 7: // IDENTIFIER
      case 8: // INT_CONSTANT
      case 9: // FLOAT_CONSTANT
      case 10: // STRING_LITERAL
      case 11: // OR_OP
      case 12: // AND_OP
      case 13: // EQ_OP
      case 14: // NE_OP
      case 15: // LE_OP
      case 16: // GE_OP
      case 17: // INC_OP
      case 18: // PTR_OP
      case 19: // IF
      case 20: // ELSE
      case 21: // WHILE
      case 22: // FOR
      case 23: // RETURN
      case 24: // OTHERS
      case 68: // unary_operator
        value.copy< std::string > (that.value);
        break;

      case 45: // translation_unit
      case 46: // begin_nterm
        value.copy< std::vector<abstract_astnode*> > (that.value);
        break;

      case 66: // compound_statement
      case 67: // statement_list
        value.copy< std::vector<statement_astnode*> > (that.value);
        break;

      case 75: // parameter_list
        value.copy< std::vector<typespec_astnode> > (that.value);
        break;

      case 69: // type_specifier
      case 70: // declaration
      case 71: // declarator_list
      case 72: // declarator
      case 73: // declarator_arr
      case 74: // parameter_declaration
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
    switch (that.type_get ())
    {
      case 47: // struct_specifier
      case 48: // procedure_call
      case 49: // declaration_list
        value.move< abstract_astnode* > (that.value);
        break;

      case 60: // assignment_expression
        value.move< assignE_astnode* > (that.value);
        break;

      case 50: // expression
      case 51: // logical_and_expression
      case 52: // equality_expression
      case 53: // relational_expression
      case 54: // additive_expression
      case 55: // unary_expression
      case 56: // multiplicative_expression
      case 57: // postfix_expression
      case 58: // primary_expression
      case 59: // expression_list
        value.move< exp_astnode* > (that.value);
        break;

      case 76: // fun_declarator
        value.move< fundeclarator_astnode* > (that.value);
        break;

      case 61: // function_definition
      case 62: // statement
      case 63: // selection_statement
      case 64: // iteration_statement
      case 65: // assignment_statement
        value.move< statement_astnode* > (that.value);
        break;

      case 3: // VOID
      case 4: // INT
      case 5: // FLOAT
      case 6: // STRUCT
      case 7: // IDENTIFIER
      case 8: // INT_CONSTANT
      case 9: // FLOAT_CONSTANT
      case 10: // STRING_LITERAL
      case 11: // OR_OP
      case 12: // AND_OP
      case 13: // EQ_OP
      case 14: // NE_OP
      case 15: // LE_OP
      case 16: // GE_OP
      case 17: // INC_OP
      case 18: // PTR_OP
      case 19: // IF
      case 20: // ELSE
      case 21: // WHILE
      case 22: // FOR
      case 23: // RETURN
      case 24: // OTHERS
      case 68: // unary_operator
        value.move< std::string > (that.value);
        break;

      case 45: // translation_unit
      case 46: // begin_nterm
        value.move< std::vector<abstract_astnode*> > (that.value);
        break;

      case 66: // compound_statement
      case 67: // statement_list
        value.move< std::vector<statement_astnode*> > (that.value);
        break;

      case 75: // parameter_list
        value.move< std::vector<typespec_astnode> > (that.value);
        break;

      case 69: // type_specifier
      case 70: // declaration
      case 71: // declarator_list
      case 72: // declarator
      case 73: // declarator_arr
      case 74: // parameter_declaration
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
  Parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
#if defined __GNUC__ && ! defined __clang__ && ! defined __ICC && __GNUC__ * 100 + __GNUC_MINOR__ <= 408
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
#endif
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    switch (yytype)
    {
      case 3: // VOID
#line 16 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 989 "parser.tab.cc"
        break;

      case 4: // INT
#line 17 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 995 "parser.tab.cc"
        break;

      case 5: // FLOAT
#line 18 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1001 "parser.tab.cc"
        break;

      case 6: // STRUCT
#line 19 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1007 "parser.tab.cc"
        break;

      case 7: // IDENTIFIER
#line 20 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1013 "parser.tab.cc"
        break;

      case 8: // INT_CONSTANT
#line 21 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1019 "parser.tab.cc"
        break;

      case 9: // FLOAT_CONSTANT
#line 22 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1025 "parser.tab.cc"
        break;

      case 10: // STRING_LITERAL
#line 23 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1031 "parser.tab.cc"
        break;

      case 11: // OR_OP
#line 24 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1037 "parser.tab.cc"
        break;

      case 12: // AND_OP
#line 25 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1043 "parser.tab.cc"
        break;

      case 13: // EQ_OP
#line 26 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1049 "parser.tab.cc"
        break;

      case 14: // NE_OP
#line 27 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1055 "parser.tab.cc"
        break;

      case 15: // LE_OP
#line 28 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1061 "parser.tab.cc"
        break;

      case 16: // GE_OP
#line 29 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1067 "parser.tab.cc"
        break;

      case 17: // INC_OP
#line 30 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1073 "parser.tab.cc"
        break;

      case 18: // PTR_OP
#line 31 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1079 "parser.tab.cc"
        break;

      case 19: // IF
#line 32 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1085 "parser.tab.cc"
        break;

      case 20: // ELSE
#line 33 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1091 "parser.tab.cc"
        break;

      case 21: // WHILE
#line 34 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1097 "parser.tab.cc"
        break;

      case 22: // FOR
#line 35 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1103 "parser.tab.cc"
        break;

      case 23: // RETURN
#line 36 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1109 "parser.tab.cc"
        break;

      case 24: // OTHERS
#line 37 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1115 "parser.tab.cc"
        break;

      default:
        break;
    }
    yyo << ')';
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
  Parser::yypop_ (int n)
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
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue)
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
        YYCDEBUG << "Reading a token: ";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location));
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

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
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
      case 47: // struct_specifier
      case 48: // procedure_call
      case 49: // declaration_list
        yylhs.value.emplace< abstract_astnode* > ();
        break;

      case 60: // assignment_expression
        yylhs.value.emplace< assignE_astnode* > ();
        break;

      case 50: // expression
      case 51: // logical_and_expression
      case 52: // equality_expression
      case 53: // relational_expression
      case 54: // additive_expression
      case 55: // unary_expression
      case 56: // multiplicative_expression
      case 57: // postfix_expression
      case 58: // primary_expression
      case 59: // expression_list
        yylhs.value.emplace< exp_astnode* > ();
        break;

      case 76: // fun_declarator
        yylhs.value.emplace< fundeclarator_astnode* > ();
        break;

      case 61: // function_definition
      case 62: // statement
      case 63: // selection_statement
      case 64: // iteration_statement
      case 65: // assignment_statement
        yylhs.value.emplace< statement_astnode* > ();
        break;

      case 3: // VOID
      case 4: // INT
      case 5: // FLOAT
      case 6: // STRUCT
      case 7: // IDENTIFIER
      case 8: // INT_CONSTANT
      case 9: // FLOAT_CONSTANT
      case 10: // STRING_LITERAL
      case 11: // OR_OP
      case 12: // AND_OP
      case 13: // EQ_OP
      case 14: // NE_OP
      case 15: // LE_OP
      case 16: // GE_OP
      case 17: // INC_OP
      case 18: // PTR_OP
      case 19: // IF
      case 20: // ELSE
      case 21: // WHILE
      case 22: // FOR
      case 23: // RETURN
      case 24: // OTHERS
      case 68: // unary_operator
        yylhs.value.emplace< std::string > ();
        break;

      case 45: // translation_unit
      case 46: // begin_nterm
        yylhs.value.emplace< std::vector<abstract_astnode*> > ();
        break;

      case 66: // compound_statement
      case 67: // statement_list
        yylhs.value.emplace< std::vector<statement_astnode*> > ();
        break;

      case 75: // parameter_list
        yylhs.value.emplace< std::vector<typespec_astnode> > ();
        break;

      case 69: // type_specifier
      case 70: // declaration
      case 71: // declarator_list
      case 72: // declarator
      case 73: // declarator_arr
      case 74: // parameter_declaration
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
  case 2:
#line 104 "parser.yy"
             {
    Symbols::gst = new SymTab();
    ststack.push(Symbols::gst);
    // std::cout<<"pushed onto stack"<<Symbols::gst<<"\n";
}
#line 1443 "parser.tab.cc"
    break;

  case 3:
#line 108 "parser.yy"
                   {
    ststack.top()->printJson();
    // std::cout <<"printed\n";
}
#line 1452 "parser.tab.cc"
    break;

  case 4:
#line 113 "parser.yy"
                                  {
    for(auto entry: ststack.top()->rows){
        if(entry.second.size==0&&entry.second.hltype==SymTab::ST_HL_type::STRUCT){
            ststack.top()->rows[entry.first].size = Symbols::getStructBaseTypeWidth(entry.first);
        }
    }
}
#line 1464 "parser.tab.cc"
    break;

  case 5:
#line 120 "parser.yy"
                     {
    yylhs.value.as < std::vector<abstract_astnode*> > () = std::vector<abstract_astnode*>();
    yylhs.value.as < std::vector<abstract_astnode*> > ().push_back(yystack_[0].value.as < statement_astnode* > ());
}
#line 1473 "parser.tab.cc"
    break;

  case 6:
#line 124 "parser.yy"
                                   {
}
#line 1480 "parser.tab.cc"
    break;

  case 7:
#line 126 "parser.yy"
                                      {
    yylhs.value.as < std::vector<abstract_astnode*> > () = yystack_[1].value.as < std::vector<abstract_astnode*> > ();
    yylhs.value.as < std::vector<abstract_astnode*> > ().push_back(yystack_[0].value.as < statement_astnode* > ());
}
#line 1489 "parser.tab.cc"
    break;

  case 8:
#line 132 "parser.yy"
                                    {
    string structName = "struct " + yystack_[0].value.as < std::string > ();
    ststack.top()->rows[structName] = SymEntry("struct",SymTab::ST_HL_type::STRUCT,SymTab::ST_LPG::GLOBAL,0,0);
    Symbols::slsts[structName] = new SymTab();
    // Symbols::slsts[$2] = new SymTab();
    ststack.push(Symbols::slsts[structName]);
    // SymTab *table = ststack.top();

}
#line 1503 "parser.tab.cc"
    break;

  case 9:
#line 140 "parser.yy"
                             {
    ststack.pop();
}
#line 1511 "parser.tab.cc"
    break;

  case 10:
#line 144 "parser.yy"
                                                                     {
    ststack.top()->ptr = new seq_astnode(yystack_[0].value.as < std::vector<statement_astnode*> > ());
    yylhs.value.as < statement_astnode* > () = nullptr;
    ststack.pop();
}
#line 1521 "parser.tab.cc"
    break;

  case 11:
#line 150 "parser.yy"
                    {
    typespec_astnode ts;
    ts.baseTypeWidth = 0;
    ts.typeWidth = ts.baseTypeWidth;
    ts.typeName = "void";
    yylhs.value.as < typespec_astnode > () = ts;
    toptype = ts;

}
#line 1535 "parser.tab.cc"
    break;

  case 12:
#line 159 "parser.yy"
     {
    // retType = SymTab::ST_type::INT;
    typespec_astnode ts;
    ts.baseTypeWidth = 4;
    ts.typeWidth = ts.baseTypeWidth;
    ts.typeName = "int";
    yylhs.value.as < typespec_astnode > () = ts;
    toptype = ts;

}
#line 1550 "parser.tab.cc"
    break;

  case 13:
#line 169 "parser.yy"
       {
    // retType = SymTab::ST_type::FLOAT;
    typespec_astnode ts;
    ts.baseTypeWidth = 8;
    ts.typeWidth = ts.baseTypeWidth;
    ts.typeName = "float";
    yylhs.value.as < typespec_astnode > () = ts;
    toptype = ts;
}
#line 1564 "parser.tab.cc"
    break;

  case 14:
#line 178 "parser.yy"
                   {
    // retType = SymTab::ST_type::STRUCT_TYPE;
    typespec_astnode ts;
    ts.typeName = "struct "+(yystack_[0].value.as < std::string > ());
    ts.baseTypeWidth = Symbols::getStructBaseTypeWidth(ts.typeName);
    ts.typeWidth = ts.baseTypeWidth;
    yylhs.value.as < typespec_astnode > () = ts;
    toptype = ts;
}
#line 1578 "parser.tab.cc"
    break;

  case 15:
#line 189 "parser.yy"
                              {
    std::string name = yystack_[1].value.as < std::string > ();
    ststack.top()->rows[name] = SymEntry(toptype.typeName,SymTab::ST_HL_type::FUN,SymTab::ST_LPG::GLOBAL,0,0);
    Symbols::flsts[name] = new SymTab();
    ststack.push(Symbols::flsts[name]);
}
#line 1589 "parser.tab.cc"
    break;

  case 16:
#line 194 "parser.yy"
                    {
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
    
    //TODO: fix this.
    std::string name = yystack_[4].value.as < std::string > ();
    std::vector<typespec_astnode> vect = std::vector<typespec_astnode>();
    yylhs.value.as < fundeclarator_astnode* > () = new fundeclarator_astnode(name, vect);
}
#line 1613 "parser.tab.cc"
    break;

  case 17:
#line 213 "parser.yy"
                    {
    std::string name = yystack_[2].value.as < std::string > ();
    yylhs.value.as < fundeclarator_astnode* > () = new fundeclarator_astnode(name,std::vector<typespec_astnode>());
    ststack.top()->rows[name] = SymEntry(toptype.typeName,SymTab::ST_HL_type::FUN,SymTab::ST_LPG::GLOBAL,0,0);
    Symbols::flsts[name] = new SymTab();
    ststack.push(Symbols::flsts[name]);
}
#line 1625 "parser.tab.cc"
    break;

  case 18:
#line 222 "parser.yy"
                                     {
    yylhs.value.as < std::vector<typespec_astnode> > () = std::vector<typespec_astnode>();
    yylhs.value.as < std::vector<typespec_astnode> > ().push_back(yystack_[0].value.as < typespec_astnode > ());
}
#line 1634 "parser.tab.cc"
    break;

  case 19:
#line 226 "parser.yy"
                                           {
    yylhs.value.as < std::vector<typespec_astnode> > () = yystack_[0].value.as < std::vector<typespec_astnode> > ();
    yylhs.value.as < std::vector<typespec_astnode> > ().push_back(yystack_[2].value.as < typespec_astnode > ());
}
#line 1643 "parser.tab.cc"
    break;

  case 20:
#line 232 "parser.yy"
                                                {
    yylhs.value.as < typespec_astnode > () = yystack_[1].value.as < typespec_astnode > ();
    ststack.top()->rows[topvarname] = SymEntry(toptype.typeName,SymTab::ST_HL_type::VAR,SymTab::ST_LPG::PARAM,toptype.typeWidth,0);
    ststack.top()->rows[topvarname].offset = ststack.top()->getParamOffset(ststack.top()->rows[topvarname].size);
}
#line 1653 "parser.tab.cc"
    break;

  case 21:
#line 239 "parser.yy"
                          {
    yylhs.value.as < typespec_astnode > () = toptype;
    yylhs.value.as < typespec_astnode > ().typeWidth = yylhs.value.as < typespec_astnode > ().baseTypeWidth;
    topvarname = yystack_[0].value.as < std::string > ();
}
#line 1663 "parser.tab.cc"
    break;

  case 22:
#line 244 "parser.yy"
                                     {
    yylhs.value.as < typespec_astnode > () = toptype;
    typespec_astnode tstmp = yystack_[3].value.as < typespec_astnode > ();
    yylhs.value.as < typespec_astnode > ().typeWidth = ((tstmp).typeWidth) * (std::stoi(yystack_[1].value.as < std::string > ()));
    yylhs.value.as < typespec_astnode > ().typeName = "array("+(tstmp).typeName+","+(yystack_[1].value.as < std::string > ())+")";

}
#line 1675 "parser.tab.cc"
    break;

  case 23:
#line 253 "parser.yy"
                          {
    yylhs.value.as < typespec_astnode > () = yystack_[0].value.as < typespec_astnode > ();
}
#line 1683 "parser.tab.cc"
    break;

  case 24:
#line 256 "parser.yy"
                 {
    yylhs.value.as < typespec_astnode > ().typeWidth = 4;
    yylhs.value.as < typespec_astnode > ().baseTypeWidth = yystack_[0].value.as < typespec_astnode > ().typeWidth;
    yylhs.value.as < typespec_astnode > ().typeName = "pointer("+yystack_[0].value.as < typespec_astnode > ().typeName+")";
}
#line 1693 "parser.tab.cc"
    break;

  case 25:
#line 263 "parser.yy"
                           {
    yylhs.value.as < std::vector<statement_astnode*> > () = std::vector<statement_astnode*>();
}
#line 1701 "parser.tab.cc"
    break;

  case 26:
#line 266 "parser.yy"
                        {
    yylhs.value.as < std::vector<statement_astnode*> > () = yystack_[1].value.as < std::vector<statement_astnode*> > ();
}
#line 1709 "parser.tab.cc"
    break;

  case 27:
#line 269 "parser.yy"
                           {
    //TODO
    yylhs.value.as < std::vector<statement_astnode*> > () = std::vector<statement_astnode*>();

}
#line 1719 "parser.tab.cc"
    break;

  case 28:
#line 274 "parser.yy"
                                         {
    yylhs.value.as < std::vector<statement_astnode*> > () = yystack_[1].value.as < std::vector<statement_astnode*> > ();
}
#line 1727 "parser.tab.cc"
    break;

  case 29:
#line 279 "parser.yy"
                          {
    std::vector<statement_astnode*> temp;
    statement_astnode* stmt = yystack_[0].value.as < statement_astnode* > ();
    if(stmt!=NULL){
        temp.push_back(yystack_[0].value.as < statement_astnode* > ());
    }
    yylhs.value.as < std::vector<statement_astnode*> > () = temp;
}
#line 1740 "parser.tab.cc"
    break;

  case 30:
#line 287 "parser.yy"
                          {
    yystack_[1].value.as < std::vector<statement_astnode*> > ().push_back(yystack_[0].value.as < statement_astnode* > ());
    yylhs.value.as < std::vector<statement_astnode*> > () = yystack_[1].value.as < std::vector<statement_astnode*> > ();
}
#line 1749 "parser.tab.cc"
    break;

  case 31:
#line 293 "parser.yy"
              {
    yylhs.value.as < statement_astnode* > () = new empty_astnode();
}
#line 1757 "parser.tab.cc"
    break;

  case 32:
#line 296 "parser.yy"
                        {
    yylhs.value.as < statement_astnode* > () = new seq_astnode(yystack_[1].value.as < std::vector<statement_astnode*> > ());
}
#line 1765 "parser.tab.cc"
    break;

  case 33:
#line 299 "parser.yy"
                     {
    yylhs.value.as < statement_astnode* > () = yystack_[0].value.as < statement_astnode* > ();
}
#line 1773 "parser.tab.cc"
    break;

  case 34:
#line 302 "parser.yy"
                     {
    yylhs.value.as < statement_astnode* > () = yystack_[0].value.as < statement_astnode* > ();
}
#line 1781 "parser.tab.cc"
    break;

  case 35:
#line 305 "parser.yy"
                      {
    yylhs.value.as < statement_astnode* > () = yystack_[0].value.as < statement_astnode* > ();
}
#line 1789 "parser.tab.cc"
    break;

  case 36:
#line 308 "parser.yy"
                {
    yylhs.value.as < statement_astnode* > () = NULL;
}
#line 1797 "parser.tab.cc"
    break;

  case 37:
#line 311 "parser.yy"
                       {
    yylhs.value.as < statement_astnode* > () = new return_astnode(yystack_[1].value.as < exp_astnode* > ());
}
#line 1805 "parser.tab.cc"
    break;

  case 38:
#line 316 "parser.yy"
                                                      {
    yylhs.value.as < assignE_astnode* > () = new assignE_astnode(yystack_[2].value.as < exp_astnode* > (), yystack_[0].value.as < exp_astnode* > ());
}
#line 1813 "parser.tab.cc"
    break;

  case 39:
#line 321 "parser.yy"
                                               {
    yylhs.value.as < statement_astnode* > () = new assignS_astnode(yystack_[1].value.as < assignE_astnode* > ()->exp1, yystack_[1].value.as < assignE_astnode* > ()->exp2);
}
#line 1821 "parser.tab.cc"
    break;

  case 40:
#line 326 "parser.yy"
                                      {
}
#line 1828 "parser.tab.cc"
    break;

  case 41:
#line 328 "parser.yy"
                                        {
}
#line 1835 "parser.tab.cc"
    break;

  case 42:
#line 332 "parser.yy"
                                  {
    yylhs.value.as < exp_astnode* > () = yystack_[0].value.as < exp_astnode* > ();
}
#line 1843 "parser.tab.cc"
    break;

  case 43:
#line 335 "parser.yy"
                                         {
}
#line 1850 "parser.tab.cc"
    break;

  case 44:
#line 339 "parser.yy"
                                           {
    yylhs.value.as < exp_astnode* > () = yystack_[0].value.as < exp_astnode* > ();
}
#line 1858 "parser.tab.cc"
    break;

  case 45:
#line 342 "parser.yy"
                                                   {
    yylhs.value.as < exp_astnode* > () = new op_binary_astnode("AND?", yystack_[2].value.as < exp_astnode* > (), yystack_[0].value.as < exp_astnode* > ());
}
#line 1866 "parser.tab.cc"
    break;

  case 46:
#line 347 "parser.yy"
                                          {
    yylhs.value.as < exp_astnode* > () = yystack_[0].value.as < exp_astnode* > ();
}
#line 1874 "parser.tab.cc"
    break;

  case 47:
#line 350 "parser.yy"
                                                  {
    yylhs.value.as < exp_astnode* > () = new op_binary_astnode("EQ?", yystack_[2].value.as < exp_astnode* > (), yystack_[0].value.as < exp_astnode* > ());
}
#line 1882 "parser.tab.cc"
    break;

  case 48:
#line 353 "parser.yy"
                                                 {
    yylhs.value.as < exp_astnode* > () = new op_binary_astnode("NE?", yystack_[2].value.as < exp_astnode* > (), yystack_[0].value.as < exp_astnode* > ());
}
#line 1890 "parser.tab.cc"
    break;

  case 49:
#line 358 "parser.yy"
                                          {
    yylhs.value.as < exp_astnode* > () = yystack_[0].value.as < exp_astnode* > ();
}
#line 1898 "parser.tab.cc"
    break;

  case 50:
#line 361 "parser.yy"
                                               {
    yylhs.value.as < exp_astnode* > () = new op_binary_astnode("LT?", yystack_[2].value.as < exp_astnode* > (), yystack_[0].value.as < exp_astnode* > ());
}
#line 1906 "parser.tab.cc"
    break;

  case 51:
#line 364 "parser.yy"
                                               {
    yylhs.value.as < exp_astnode* > () = new op_binary_astnode("GT?", yystack_[2].value.as < exp_astnode* > (), yystack_[0].value.as < exp_astnode* > ());
}
#line 1914 "parser.tab.cc"
    break;

  case 52:
#line 367 "parser.yy"
                                                 {
    yylhs.value.as < exp_astnode* > () = new op_binary_astnode("LE?", yystack_[2].value.as < exp_astnode* > (), yystack_[0].value.as < exp_astnode* > ());
}
#line 1922 "parser.tab.cc"
    break;

  case 53:
#line 370 "parser.yy"
                                                 {
    yylhs.value.as < exp_astnode* > () = new op_binary_astnode("GE?", yystack_[2].value.as < exp_astnode* > (), yystack_[0].value.as < exp_astnode* > ());
}
#line 1930 "parser.tab.cc"
    break;

  case 54:
#line 375 "parser.yy"
                                              {
    yylhs.value.as < exp_astnode* > () = yystack_[0].value.as < exp_astnode* > ();
}
#line 1938 "parser.tab.cc"
    break;

  case 55:
#line 378 "parser.yy"
                                                   {
    yylhs.value.as < exp_astnode* > () = new op_binary_astnode("PLUS?", yystack_[2].value.as < exp_astnode* > (), yystack_[0].value.as < exp_astnode* > ());
}
#line 1946 "parser.tab.cc"
    break;

  case 56:
#line 381 "parser.yy"
                                                   {
    yylhs.value.as < exp_astnode* > () = new op_binary_astnode("MINUS?", yystack_[2].value.as < exp_astnode* > (), yystack_[0].value.as < exp_astnode* > ());
}
#line 1954 "parser.tab.cc"
    break;

  case 57:
#line 386 "parser.yy"
                                    {
    yylhs.value.as < exp_astnode* > () = yystack_[0].value.as < exp_astnode* > ();
}
#line 1962 "parser.tab.cc"
    break;

  case 58:
#line 389 "parser.yy"
                                 {
    yylhs.value.as < exp_astnode* > () = new op_unary_astnode(yystack_[1].value.as < std::string > (), yystack_[0].value.as < exp_astnode* > ());
}
#line 1970 "parser.tab.cc"
    break;

  case 59:
#line 394 "parser.yy"
                                           {
    yylhs.value.as < exp_astnode* > () = yystack_[0].value.as < exp_astnode* > ();
}
#line 1978 "parser.tab.cc"
    break;

  case 60:
#line 397 "parser.yy"
                                                {
    yylhs.value.as < exp_astnode* > () = new op_binary_astnode("MULT?", yystack_[2].value.as < exp_astnode* > (), yystack_[0].value.as < exp_astnode* > ());
}
#line 1986 "parser.tab.cc"
    break;

  case 61:
#line 400 "parser.yy"
                                                {
    yylhs.value.as < exp_astnode* > () = new op_binary_astnode("DIV?", yystack_[2].value.as < exp_astnode* > (), yystack_[0].value.as < exp_astnode* > ());
}
#line 1994 "parser.tab.cc"
    break;

  case 62:
#line 405 "parser.yy"
                                      {
    yylhs.value.as < exp_astnode* > () = yystack_[0].value.as < exp_astnode* > ();
}
#line 2002 "parser.tab.cc"
    break;

  case 63:
#line 408 "parser.yy"
                                       {
    yylhs.value.as < exp_astnode* > () = new arrayref_astnode(yystack_[3].value.as < exp_astnode* > (), yystack_[1].value.as < exp_astnode* > ());
}
#line 2010 "parser.tab.cc"
    break;

  case 64:
#line 411 "parser.yy"
                    {
}
#line 2017 "parser.tab.cc"
    break;

  case 65:
#line 413 "parser.yy"
                                    {
}
#line 2024 "parser.tab.cc"
    break;

  case 66:
#line 415 "parser.yy"
                                   {
    yylhs.value.as < exp_astnode* > () = new member_astnode(yystack_[2].value.as < exp_astnode* > (), new identifier_astnode(yystack_[0].value.as < std::string > ()));
}
#line 2032 "parser.tab.cc"
    break;

  case 67:
#line 418 "parser.yy"
                                      {
    yylhs.value.as < exp_astnode* > () = new arrow_astnode(yystack_[2].value.as < exp_astnode* > (), new identifier_astnode(yystack_[0].value.as < std::string > ()));
}
#line 2040 "parser.tab.cc"
    break;

  case 68:
#line 421 "parser.yy"
                           {
    
}
#line 2048 "parser.tab.cc"
    break;

  case 69:
#line 426 "parser.yy"
                              {
    yylhs.value.as < exp_astnode* > () = new identifier_astnode(yystack_[0].value.as < std::string > ());
}
#line 2056 "parser.tab.cc"
    break;

  case 70:
#line 429 "parser.yy"
              {
    yylhs.value.as < exp_astnode* > () = new intconst_astnode(yystack_[0].value.as < std::string > ());
}
#line 2064 "parser.tab.cc"
    break;

  case 71:
#line 432 "parser.yy"
                {
    yylhs.value.as < exp_astnode* > () = new floatconst_astnode(yystack_[0].value.as < std::string > ());
}
#line 2072 "parser.tab.cc"
    break;

  case 72:
#line 435 "parser.yy"
                {
    yylhs.value.as < exp_astnode* > () = new stringconst_astnode(yystack_[0].value.as < std::string > ());
    yylhs.value.as < exp_astnode* > ()->print();
}
#line 2081 "parser.tab.cc"
    break;

  case 73:
#line 439 "parser.yy"
                    {
}
#line 2088 "parser.tab.cc"
    break;

  case 74:
#line 443 "parser.yy"
                           {
}
#line 2095 "parser.tab.cc"
    break;

  case 75:
#line 445 "parser.yy"
                                {
}
#line 2102 "parser.tab.cc"
    break;

  case 76:
#line 449 "parser.yy"
                   {
    yylhs.value.as < std::string > () = std::string("UMINUS?");
}
#line 2110 "parser.tab.cc"
    break;

  case 77:
#line 452 "parser.yy"
     {
    yylhs.value.as < std::string > () = std::string("NOT");
}
#line 2118 "parser.tab.cc"
    break;

  case 78:
#line 455 "parser.yy"
     {
    yylhs.value.as < std::string > () = std::string("ADDRESS");
}
#line 2126 "parser.tab.cc"
    break;

  case 79:
#line 458 "parser.yy"
     {
    yylhs.value.as < std::string > () = std::string("DEREF");
}
#line 2134 "parser.tab.cc"
    break;

  case 80:
#line 463 "parser.yy"
                                                                   {
    yylhs.value.as < statement_astnode* > () = new if_astnode(yystack_[4].value.as < exp_astnode* > (), yystack_[2].value.as < statement_astnode* > (), yystack_[0].value.as < statement_astnode* > ());
}
#line 2142 "parser.tab.cc"
    break;

  case 81:
#line 468 "parser.yy"
                                                       {
    yylhs.value.as < statement_astnode* > () = new while_astnode(yystack_[2].value.as < exp_astnode* > (), yystack_[0].value.as < statement_astnode* > ());
}
#line 2150 "parser.tab.cc"
    break;

  case 82:
#line 471 "parser.yy"
                                                                                      {
    yylhs.value.as < statement_astnode* > () = new for_astnode(yystack_[6].value.as < assignE_astnode* > (), yystack_[4].value.as < exp_astnode* > (), yystack_[2].value.as < assignE_astnode* > (), yystack_[0].value.as < statement_astnode* > ());
}
#line 2158 "parser.tab.cc"
    break;

  case 83:
#line 476 "parser.yy"
                             {
}
#line 2165 "parser.tab.cc"
    break;

  case 84:
#line 478 "parser.yy"
                              {
}
#line 2172 "parser.tab.cc"
    break;

  case 85:
#line 482 "parser.yy"
                                               {
}
#line 2179 "parser.tab.cc"
    break;

  case 86:
#line 486 "parser.yy"
                           {
    yylhs.value.as < typespec_astnode > () = yystack_[0].value.as < typespec_astnode > ();
    string type = yystack_[0].value.as < typespec_astnode > ().typeName;
    int size = yystack_[0].value.as < typespec_astnode > ().typeWidth;
    int offset = ststack.top()->getNewOffset(size);
    SymTab* st = ststack.top();

    st->rows[topvarname] = SymEntry(type,SymTab::ST_HL_type::VAR,SymTab::ST_LPG::LOCAL,size,offset);
}
#line 2193 "parser.tab.cc"
    break;

  case 87:
#line 495 "parser.yy"
                                {
    yylhs.value.as < typespec_astnode > () = yystack_[0].value.as < typespec_astnode > ();
    string type = yystack_[0].value.as < typespec_astnode > ().typeName;
    int size = yystack_[0].value.as < typespec_astnode > ().typeWidth;
    int offset = ststack.top()->getNewOffset(size);
    ststack.top()->rows[topvarname] = SymEntry(type,SymTab::ST_HL_type::VAR,SymTab::ST_LPG::LOCAL,size,offset);
}
#line 2205 "parser.tab.cc"
    break;


#line 2209 "parser.tab.cc"

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
      YY_STACK_PRINT ();

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
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
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
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[+yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yy_error_token_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yy_error_token_)
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

  // Generate an error message.
  std::string
  Parser::yysyntax_error_ (state_type, const symbol_type&) const
  {
    return YY_("syntax error");
  }


  const signed char Parser::yypact_ninf_ = -62;

  const signed char Parser::yytable_ninf_ = -15;

  const short
  Parser::yypact_[] =
  {
     -62,    24,    75,   -62,   -62,   -62,   -62,    46,    75,   -62,
     -62,    48,    52,   -62,   -62,    12,    34,    43,    14,   115,
     -62,   123,   -62,   123,    65,    63,   -62,   -62,   -62,    67,
      73,    81,   299,   -62,   -62,   299,   294,   -62,   -62,   -62,
     -62,   -62,   154,    53,    17,   -62,    76,   -62,   -62,   -62,
     -62,   189,   299,     1,   -62,     9,     1,   103,   113,   -62,
      31,   299,   299,   299,   124,     7,   143,    61,    50,    38,
     -62,    64,    -2,   224,   -62,   259,   -62,   299,   -62,   158,
     299,   159,   -62,   -62,   -62,   -62,   -62,     1,   -22,   -62,
     132,   127,   -62,   123,   -62,   128,   160,    69,     5,    39,
     129,    78,   299,   -62,   299,   299,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   -62,   -62,   -62,   160,   -62,
      11,   -62,   -62,     1,   -62,   164,   -62,   -62,   -62,   133,
     299,   294,   294,   299,   -62,   119,   143,    61,    50,    50,
      38,    38,    38,    38,    64,    64,   -62,   -62,   -62,   -62,
     142,   -62,   160,   162,   -62,    10,   -62,   -62,   294,   299,
     -62,   148,   294,   -62
  };

  const signed char
  Parser::yydefact_[] =
  {
       2,     0,     0,     1,    11,    12,    13,     0,     3,     4,
       5,     0,     8,     6,     7,     0,     0,     0,    15,     0,
      10,     0,    17,     0,     0,    69,    70,    71,    72,     0,
       0,     0,     0,    76,    79,     0,     0,    25,    77,    78,
      31,    36,     0,     0,    57,    62,     0,    29,    33,    34,
      35,     0,     0,     0,    83,     0,     0,    18,     0,    14,
       0,     0,     0,     0,    69,     0,    42,    44,    46,    49,
      59,    54,     0,     0,    27,     0,    84,     0,    68,     0,
       0,     0,    39,    26,    30,    58,    21,     0,     0,    86,
      23,     0,    20,     0,    16,    64,    74,     0,     0,     0,
       0,     0,     0,    37,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    73,    32,    28,    38,    67,
       0,    66,    24,     0,    85,     0,     9,    19,    40,    65,
       0,     0,     0,     0,    64,     0,    43,    45,    47,    48,
      52,    53,    50,    51,    55,    56,    60,    61,    63,    87,
       0,    41,    75,     0,    81,     0,    65,    22,     0,     0,
      80,     0,     0,    82
  };

  const short
  Parser::yypgoto_[] =
  {
     -62,   -62,   -62,   175,   -62,   165,   -31,    83,    85,    41,
      23,   -19,    -5,   -62,   -62,    89,   -61,   185,   -48,   -62,
     -62,   -62,   -62,    35,   -62,     3,   -35,   -62,   -50,   -62,
     -62,   101,   -62,   -62,   -62,   -62
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,     8,     1,     9,    41,    42,    96,    66,    67,    68,
      69,    70,    71,    44,    45,    97,    46,    10,    47,    48,
      49,    50,    20,    51,    52,    53,    54,    88,    89,    90,
      57,    58,    16,     2,    17,    23
  };

  const short
  Parser::yytable_[] =
  {
      43,    65,   100,    84,    72,    11,    92,    76,    86,   102,
     123,    11,     4,     5,     6,    24,   102,    43,   102,   124,
      76,   102,   102,    43,     3,    84,    56,    84,    87,   115,
      98,    99,    43,    85,    78,    79,   131,   122,    64,    26,
      27,    28,    18,    91,    43,    22,   118,   148,   103,   120,
     102,   159,    80,    12,    43,    15,    43,    33,    34,   -14,
      81,    35,    95,   111,   112,   107,   108,    19,    38,    39,
     132,    73,    59,   149,   105,   106,    21,    75,     4,     5,
       6,     7,    77,   153,   154,    64,    26,    27,    28,   109,
     110,   113,   114,    60,   146,   147,    56,    61,   161,   152,
     129,   130,   155,    62,    33,    34,   144,   145,    35,   134,
     160,    63,    43,    43,   163,    38,    39,    82,     4,     5,
       6,    24,    25,    26,    27,    28,     4,     5,     6,    24,
     140,   141,   142,   143,    29,    93,    30,    31,    32,    43,
      43,    33,    34,    43,    94,    35,   138,   139,    36,    37,
     156,   130,    38,    39,   101,   104,    40,     4,     5,     6,
      24,    25,    26,    27,    28,   119,   121,   125,   126,   128,
     133,   102,   150,    29,   151,    30,    31,    32,   157,   162,
      33,    34,   158,    13,    35,   136,    55,    36,    74,   137,
     135,    38,    39,    14,   127,    40,    25,    26,    27,    28,
       0,     0,     0,     0,     0,     0,     0,     0,    29,     0,
      30,    31,    32,     0,     0,    33,    34,     0,     0,    35,
       0,     0,    36,    83,     0,     0,    38,    39,     0,     0,
      40,    25,    26,    27,    28,     0,     0,     0,     0,     0,
       0,     0,     0,    29,     0,    30,    31,    32,     0,     0,
      33,    34,     0,     0,    35,     0,     0,    36,   116,     0,
       0,    38,    39,     0,     0,    40,    25,    26,    27,    28,
       0,     0,     0,     0,     0,     0,     0,     0,    29,     0,
      30,    31,    32,     0,     0,    33,    34,     0,     0,    35,
       0,     0,    36,   117,     0,     0,    38,    39,     0,     0,
      40,    25,    26,    27,    28,     0,    64,    26,    27,    28,
       0,     0,     0,    29,     0,    30,    31,    32,     0,     0,
      33,    34,     0,     0,    35,    33,    34,    36,     0,    35,
       0,    38,    39,     0,     0,    40,    38,    39
  };

  const short
  Parser::yycheck_[] =
  {
      19,    32,    63,    51,    35,     2,    56,    42,     7,    11,
      32,     8,     3,     4,     5,     6,    11,    36,    11,    41,
      55,    11,    11,    42,     0,    73,    23,    75,    27,    31,
      61,    62,    51,    52,    17,    18,    31,    87,     7,     8,
       9,    10,    30,    34,    63,    31,    77,    36,    41,    80,
      11,    41,    35,     7,    73,     7,    75,    26,    27,     7,
      43,    30,    31,    25,    26,    15,    16,    33,    37,    38,
      31,    36,     7,   123,    13,    14,    33,    42,     3,     4,
       5,     6,    29,   131,   132,     7,     8,     9,    10,    39,
      40,    27,    28,    30,   113,   114,    93,    30,   159,   130,
      31,    32,   133,    30,    26,    27,   111,   112,    30,    31,
     158,    30,   131,   132,   162,    37,    38,    41,     3,     4,
       5,     6,     7,     8,     9,    10,     3,     4,     5,     6,
     107,   108,   109,   110,    19,    32,    21,    22,    23,   158,
     159,    26,    27,   162,    31,    30,   105,   106,    33,    34,
      31,    32,    37,    38,    30,    12,    41,     3,     4,     5,
       6,     7,     8,     9,    10,     7,     7,    35,    41,    41,
      41,    11,     8,    19,    41,    21,    22,    23,    36,    31,
      26,    27,    20,     8,    30,   102,    21,    33,    34,   104,
     101,    37,    38,     8,    93,    41,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,
      21,    22,    23,    -1,    -1,    26,    27,    -1,    -1,    30,
      -1,    -1,    33,    34,    -1,    -1,    37,    38,    -1,    -1,
      41,     7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    19,    -1,    21,    22,    23,    -1,    -1,
      26,    27,    -1,    -1,    30,    -1,    -1,    33,    34,    -1,
      -1,    37,    38,    -1,    -1,    41,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,
      21,    22,    23,    -1,    -1,    26,    27,    -1,    -1,    30,
      -1,    -1,    33,    34,    -1,    -1,    37,    38,    -1,    -1,
      41,     7,     8,     9,    10,    -1,     7,     8,     9,    10,
      -1,    -1,    -1,    19,    -1,    21,    22,    23,    -1,    -1,
      26,    27,    -1,    -1,    30,    26,    27,    33,    -1,    30,
      -1,    37,    38,    -1,    -1,    41,    37,    38
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    46,    77,     0,     3,     4,     5,     6,    45,    47,
      61,    69,     7,    47,    61,     7,    76,    78,    30,    33,
      66,    33,    31,    79,     6,     7,     8,     9,    10,    19,
      21,    22,    23,    26,    27,    30,    33,    34,    37,    38,
      41,    48,    49,    55,    57,    58,    60,    62,    63,    64,
      65,    67,    68,    69,    70,    49,    69,    74,    75,     7,
      30,    30,    30,    30,     7,    50,    51,    52,    53,    54,
      55,    56,    50,    67,    34,    67,    70,    29,    17,    18,
      35,    43,    41,    34,    62,    55,     7,    27,    71,    72,
      73,    34,    72,    32,    31,    31,    50,    59,    50,    50,
      60,    30,    11,    41,    12,    13,    14,    15,    16,    39,
      40,    25,    26,    27,    28,    31,    34,    34,    50,     7,
      50,     7,    72,    32,    41,    35,    41,    75,    41,    31,
      32,    31,    31,    41,    31,    59,    51,    52,    53,    53,
      54,    54,    54,    54,    56,    56,    55,    55,    36,    72,
       8,    41,    50,    62,    62,    50,    31,    36,    20,    41,
      62,    60,    31,    62
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    44,    77,    46,    45,    45,    45,    45,    78,    47,
      61,    69,    69,    69,    69,    79,    76,    76,    75,    75,
      74,    73,    73,    72,    72,    66,    66,    66,    66,    67,
      67,    62,    62,    62,    62,    62,    62,    62,    60,    65,
      48,    48,    50,    50,    51,    51,    52,    52,    52,    53,
      53,    53,    53,    53,    54,    54,    54,    55,    55,    56,
      56,    56,    57,    57,    57,    57,    57,    57,    57,    58,
      58,    58,    58,    58,    59,    59,    68,    68,    68,    68,
      63,    64,    64,    49,    49,    70,    71,    71
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
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "$end", "error", "$undefined", "VOID", "INT", "FLOAT", "STRUCT",
  "IDENTIFIER", "INT_CONSTANT", "FLOAT_CONSTANT", "STRING_LITERAL",
  "OR_OP", "AND_OP", "EQ_OP", "NE_OP", "LE_OP", "GE_OP", "INC_OP",
  "PTR_OP", "IF", "ELSE", "WHILE", "FOR", "RETURN", "OTHERS", "'+'", "'-'",
  "'*'", "'/'", "'='", "'('", "')'", "','", "'{'", "'}'", "'['", "']'",
  "'!'", "'&'", "'<'", "'>'", "';'", "'\\n'", "'.'", "$accept",
  "translation_unit", "begin_nterm", "struct_specifier", "procedure_call",
  "declaration_list", "expression", "logical_and_expression",
  "equality_expression", "relational_expression", "additive_expression",
  "unary_expression", "multiplicative_expression", "postfix_expression",
  "primary_expression", "expression_list", "assignment_expression",
  "function_definition", "statement", "selection_statement",
  "iteration_statement", "assignment_statement", "compound_statement",
  "statement_list", "unary_operator", "type_specifier", "declaration",
  "declarator_list", "declarator", "declarator_arr",
  "parameter_declaration", "parameter_list", "fun_declarator", "$@1",
  "$@2", "$@3", YY_NULLPTR
  };


  const short
  Parser::yyrline_[] =
  {
       0,   104,   104,   104,   113,   120,   124,   126,   132,   132,
     144,   150,   159,   169,   178,   189,   189,   213,   222,   226,
     232,   239,   244,   253,   256,   263,   266,   269,   274,   279,
     287,   293,   296,   299,   302,   305,   308,   311,   316,   321,
     326,   328,   332,   335,   339,   342,   347,   350,   353,   358,
     361,   364,   367,   370,   375,   378,   381,   386,   389,   394,
     397,   400,   405,   408,   411,   413,   415,   418,   421,   426,
     429,   432,   435,   439,   443,   445,   449,   452,   455,   458,
     463,   468,   471,   476,   478,   482,   486,   495
  };

  // Print the state stack on the debug stream.
  void
  Parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  Parser::yy_reduce_print_ (int yyrule)
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

  Parser::token_number_type
  Parser::yytranslate_ (int t)
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const token_number_type
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
    const int user_token_number_max_ = 279;

    if (t <= 0)
      return yyeof_;
    else if (t <= user_token_number_max_)
      return translate_table[t];
    else
      return yy_undef_token_;
  }

#line 5 "parser.yy"
} // IPL
#line 2704 "parser.tab.cc"

#line 504 "parser.yy"

//grammar definition.
void IPL::Parser::error( const location_type &l, const std::string &err_message )
{
   std::cerr << "Error: " << err_message << " at " << l << "\n";
}

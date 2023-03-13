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
    // std::cout << "about to begin printing\n";
    // for (auto item: $2) {
    //     item->print();
    // }
    ststack.top()->printJson();
    // std::cout <<"printed\n";
    
}
#line 1457 "parser.tab.cc"
    break;

  case 4:
#line 118 "parser.yy"
                                  {
    
}
#line 1465 "parser.tab.cc"
    break;

  case 5:
#line 121 "parser.yy"
                     {
    yylhs.value.as < std::vector<abstract_astnode*> > () = std::vector<abstract_astnode*>();
    yylhs.value.as < std::vector<abstract_astnode*> > ().push_back(yystack_[0].value.as < statement_astnode* > ());
}
#line 1474 "parser.tab.cc"
    break;

  case 6:
#line 125 "parser.yy"
                                   {
}
#line 1481 "parser.tab.cc"
    break;

  case 7:
#line 127 "parser.yy"
                                      {
    yylhs.value.as < std::vector<abstract_astnode*> > () = yystack_[1].value.as < std::vector<abstract_astnode*> > ();
    yylhs.value.as < std::vector<abstract_astnode*> > ().push_back(yystack_[0].value.as < statement_astnode* > ());
}
#line 1490 "parser.tab.cc"
    break;

  case 8:
#line 133 "parser.yy"
                                    {
    string structName = "struct " + yystack_[0].value.as < std::string > ();
    ststack.top()->rows[structName] = SymEntry("struct",SymTab::ST_HL_type::STRUCT,SymTab::ST_LPG::GLOBAL,0,0);
    Symbols::slsts[structName] = new SymTab();
    ststack.push(Symbols::slsts[structName]);
}
#line 1501 "parser.tab.cc"
    break;

  case 9:
#line 138 "parser.yy"
                             {
    ststack.pop();
}
#line 1509 "parser.tab.cc"
    break;

  case 10:
#line 142 "parser.yy"
                                                                     {
    yylhs.value.as < statement_astnode* > () = new seq_astnode(yystack_[0].value.as < std::vector<statement_astnode*> > ());
    ststack.pop();
}
#line 1518 "parser.tab.cc"
    break;

  case 11:
#line 147 "parser.yy"
                    {
    typespec_astnode ts;
    ts.baseTypeWidth = 0;
    ts.typeName = "void";
    yylhs.value.as < typespec_astnode > () = ts;
    toptype = ts;

}
#line 1531 "parser.tab.cc"
    break;

  case 12:
#line 155 "parser.yy"
     {
    // retType = SymTab::ST_type::INT;
    typespec_astnode ts;
    ts.baseTypeWidth = 4;
    ts.typeName = "int";
    yylhs.value.as < typespec_astnode > () = ts;
    toptype = ts;

}
#line 1545 "parser.tab.cc"
    break;

  case 13:
#line 164 "parser.yy"
       {
    // retType = SymTab::ST_type::FLOAT;
    typespec_astnode ts;
    ts.baseTypeWidth = 8;
    ts.typeName = "float";
    yylhs.value.as < typespec_astnode > () = ts;
    toptype = ts;
}
#line 1558 "parser.tab.cc"
    break;

  case 14:
#line 172 "parser.yy"
                   {
    // retType = SymTab::ST_type::STRUCT_TYPE;
    typespec_astnode ts;
    string structname = yystack_[0].value.as < std::string > ();
    ts.baseTypeWidth = Symbols::getStructBaseTypeWidth(structname);
    ts.typeName = "struct "+(yystack_[0].value.as < std::string > ());
    yylhs.value.as < typespec_astnode > () = ts;
    toptype = ts;
}
#line 1572 "parser.tab.cc"
    break;

  case 15:
#line 183 "parser.yy"
                                                 {
    std::string name = yystack_[3].value.as < std::string > ();
    yylhs.value.as < fundeclarator_astnode* > () = new fundeclarator_astnode(name, yystack_[1].value.as < std::vector<typespec_astnode> > ());
    ststack.top()->rows[name] = SymEntry(toptype.typeName,SymTab::ST_HL_type::FUN,SymTab::ST_LPG::GLOBAL,0,0);
    Symbols::flsts[name] = new SymTab();
    ststack.push(Symbols::flsts[name]);
}
#line 1584 "parser.tab.cc"
    break;

  case 16:
#line 190 "parser.yy"
                    {
    std::string name = yystack_[2].value.as < std::string > ();
    yylhs.value.as < fundeclarator_astnode* > () = new fundeclarator_astnode(name,std::vector<typespec_astnode>());
    ststack.top()->rows[name] = SymEntry(toptype.typeName,SymTab::ST_HL_type::FUN,SymTab::ST_LPG::GLOBAL,0,0);
    Symbols::flsts[name] = new SymTab();
    ststack.push(Symbols::flsts[name]);
}
#line 1596 "parser.tab.cc"
    break;

  case 17:
#line 199 "parser.yy"
                                     {
    yylhs.value.as < std::vector<typespec_astnode> > () = std::vector<typespec_astnode>();
    yylhs.value.as < std::vector<typespec_astnode> > ().push_back(yystack_[0].value.as < typespec_astnode > ());
}
#line 1605 "parser.tab.cc"
    break;

  case 18:
#line 203 "parser.yy"
                                          {
    yylhs.value.as < std::vector<typespec_astnode> > () = yystack_[2].value.as < std::vector<typespec_astnode> > ();
    yylhs.value.as < std::vector<typespec_astnode> > ().push_back(yystack_[0].value.as < typespec_astnode > ());
}
#line 1614 "parser.tab.cc"
    break;

  case 19:
#line 209 "parser.yy"
                                                {
    yylhs.value.as < typespec_astnode > () = yystack_[1].value.as < typespec_astnode > ();
}
#line 1622 "parser.tab.cc"
    break;

  case 20:
#line 214 "parser.yy"
                          {
    yylhs.value.as < typespec_astnode > () = toptype;
    yylhs.value.as < typespec_astnode > ().typeWidth = yylhs.value.as < typespec_astnode > ().baseTypeWidth;
    topvarname = yystack_[0].value.as < std::string > ();
}
#line 1632 "parser.tab.cc"
    break;

  case 21:
#line 219 "parser.yy"
                                     {
    yylhs.value.as < typespec_astnode > () = toptype;
    typespec_astnode tstmp = yystack_[3].value.as < typespec_astnode > ();
    yylhs.value.as < typespec_astnode > ().typeWidth = ((tstmp).typeWidth) * (std::stoi(yystack_[1].value.as < std::string > ()));
    yylhs.value.as < typespec_astnode > ().typeName = "array("+(tstmp).typeName+","+(yystack_[1].value.as < std::string > ())+")";

}
#line 1644 "parser.tab.cc"
    break;

  case 22:
#line 228 "parser.yy"
                          {
    yylhs.value.as < typespec_astnode > () = yystack_[0].value.as < typespec_astnode > ();
}
#line 1652 "parser.tab.cc"
    break;

  case 23:
#line 231 "parser.yy"
                 {
    yylhs.value.as < typespec_astnode > ().typeWidth = 4;
    yylhs.value.as < typespec_astnode > ().baseTypeWidth = yystack_[0].value.as < typespec_astnode > ().typeWidth;
    yylhs.value.as < typespec_astnode > ().typeName = "pointer("+yystack_[0].value.as < typespec_astnode > ().typeName+")";
}
#line 1662 "parser.tab.cc"
    break;

  case 24:
#line 238 "parser.yy"
                           {
    yylhs.value.as < std::vector<statement_astnode*> > () = std::vector<statement_astnode*>();
}
#line 1670 "parser.tab.cc"
    break;

  case 25:
#line 241 "parser.yy"
                        {
    yylhs.value.as < std::vector<statement_astnode*> > () = yystack_[1].value.as < std::vector<statement_astnode*> > ();
}
#line 1678 "parser.tab.cc"
    break;

  case 26:
#line 244 "parser.yy"
                           {
    //TODO
    yylhs.value.as < std::vector<statement_astnode*> > () = std::vector<statement_astnode*>();

}
#line 1688 "parser.tab.cc"
    break;

  case 27:
#line 249 "parser.yy"
                                         {
    yylhs.value.as < std::vector<statement_astnode*> > () = yystack_[1].value.as < std::vector<statement_astnode*> > ();
}
#line 1696 "parser.tab.cc"
    break;

  case 28:
#line 254 "parser.yy"
                          {
    std::vector<statement_astnode*> temp;
    statement_astnode* stmt = yystack_[0].value.as < statement_astnode* > ();
    if(stmt!=NULL){
        temp.push_back(yystack_[0].value.as < statement_astnode* > ());
    }
    yylhs.value.as < std::vector<statement_astnode*> > () = temp;
}
#line 1709 "parser.tab.cc"
    break;

  case 29:
#line 262 "parser.yy"
                          {
    yystack_[1].value.as < std::vector<statement_astnode*> > ().push_back(yystack_[0].value.as < statement_astnode* > ());
    yylhs.value.as < std::vector<statement_astnode*> > () = yystack_[1].value.as < std::vector<statement_astnode*> > ();
}
#line 1718 "parser.tab.cc"
    break;

  case 30:
#line 268 "parser.yy"
              {
    yylhs.value.as < statement_astnode* > () = NULL;
}
#line 1726 "parser.tab.cc"
    break;

  case 31:
#line 271 "parser.yy"
                        {
    yylhs.value.as < statement_astnode* > () = new seq_astnode(yystack_[1].value.as < std::vector<statement_astnode*> > ());
}
#line 1734 "parser.tab.cc"
    break;

  case 32:
#line 274 "parser.yy"
                     {
    yylhs.value.as < statement_astnode* > () = yystack_[0].value.as < statement_astnode* > ();
}
#line 1742 "parser.tab.cc"
    break;

  case 33:
#line 277 "parser.yy"
                     {
    yylhs.value.as < statement_astnode* > () = yystack_[0].value.as < statement_astnode* > ();
}
#line 1750 "parser.tab.cc"
    break;

  case 34:
#line 280 "parser.yy"
                      {
    yylhs.value.as < statement_astnode* > () = yystack_[0].value.as < statement_astnode* > ();
}
#line 1758 "parser.tab.cc"
    break;

  case 35:
#line 283 "parser.yy"
                {
    yylhs.value.as < statement_astnode* > () = NULL;
}
#line 1766 "parser.tab.cc"
    break;

  case 36:
#line 286 "parser.yy"
                       {
    yylhs.value.as < statement_astnode* > () = NULL;
}
#line 1774 "parser.tab.cc"
    break;

  case 37:
#line 291 "parser.yy"
                                                      {
    yylhs.value.as < assignE_astnode* > () = new assignE_astnode(yystack_[2].value.as < exp_astnode* > (), yystack_[0].value.as < exp_astnode* > ());
}
#line 1782 "parser.tab.cc"
    break;

  case 38:
#line 296 "parser.yy"
                                               {
    yylhs.value.as < statement_astnode* > () = new assignS_astnode(yystack_[1].value.as < assignE_astnode* > ()->exp1, yystack_[1].value.as < assignE_astnode* > ()->exp2);
}
#line 1790 "parser.tab.cc"
    break;

  case 39:
#line 301 "parser.yy"
                                      {
}
#line 1797 "parser.tab.cc"
    break;

  case 40:
#line 303 "parser.yy"
                                        {
}
#line 1804 "parser.tab.cc"
    break;

  case 41:
#line 307 "parser.yy"
                                  {
    yylhs.value.as < exp_astnode* > () = yystack_[0].value.as < exp_astnode* > ();
}
#line 1812 "parser.tab.cc"
    break;

  case 42:
#line 310 "parser.yy"
                                         {
}
#line 1819 "parser.tab.cc"
    break;

  case 43:
#line 314 "parser.yy"
                                           {
    yylhs.value.as < exp_astnode* > () = yystack_[0].value.as < exp_astnode* > ();
}
#line 1827 "parser.tab.cc"
    break;

  case 44:
#line 317 "parser.yy"
                                                   {
    yylhs.value.as < exp_astnode* > () = new op_binary_astnode("AND?", yystack_[2].value.as < exp_astnode* > (), yystack_[0].value.as < exp_astnode* > ());
}
#line 1835 "parser.tab.cc"
    break;

  case 45:
#line 322 "parser.yy"
                                          {
    yylhs.value.as < exp_astnode* > () = yystack_[0].value.as < exp_astnode* > ();
}
#line 1843 "parser.tab.cc"
    break;

  case 46:
#line 325 "parser.yy"
                                                  {
    yylhs.value.as < exp_astnode* > () = new op_binary_astnode("EQ?", yystack_[2].value.as < exp_astnode* > (), yystack_[0].value.as < exp_astnode* > ());
}
#line 1851 "parser.tab.cc"
    break;

  case 47:
#line 328 "parser.yy"
                                                 {
    yylhs.value.as < exp_astnode* > () = new op_binary_astnode("NE?", yystack_[2].value.as < exp_astnode* > (), yystack_[0].value.as < exp_astnode* > ());
}
#line 1859 "parser.tab.cc"
    break;

  case 48:
#line 333 "parser.yy"
                                          {
    yylhs.value.as < exp_astnode* > () = yystack_[0].value.as < exp_astnode* > ();
}
#line 1867 "parser.tab.cc"
    break;

  case 49:
#line 336 "parser.yy"
                                               {
    yylhs.value.as < exp_astnode* > () = new op_binary_astnode("LT?", yystack_[2].value.as < exp_astnode* > (), yystack_[0].value.as < exp_astnode* > ());
}
#line 1875 "parser.tab.cc"
    break;

  case 50:
#line 339 "parser.yy"
                                               {
    yylhs.value.as < exp_astnode* > () = new op_binary_astnode("GT?", yystack_[2].value.as < exp_astnode* > (), yystack_[0].value.as < exp_astnode* > ());
}
#line 1883 "parser.tab.cc"
    break;

  case 51:
#line 342 "parser.yy"
                                                 {
    yylhs.value.as < exp_astnode* > () = new op_binary_astnode("LE?", yystack_[2].value.as < exp_astnode* > (), yystack_[0].value.as < exp_astnode* > ());
}
#line 1891 "parser.tab.cc"
    break;

  case 52:
#line 345 "parser.yy"
                                                 {
    yylhs.value.as < exp_astnode* > () = new op_binary_astnode("GE?", yystack_[2].value.as < exp_astnode* > (), yystack_[0].value.as < exp_astnode* > ());
}
#line 1899 "parser.tab.cc"
    break;

  case 53:
#line 350 "parser.yy"
                                              {
    yylhs.value.as < exp_astnode* > () = yystack_[0].value.as < exp_astnode* > ();
}
#line 1907 "parser.tab.cc"
    break;

  case 54:
#line 353 "parser.yy"
                                                   {
    yylhs.value.as < exp_astnode* > () = new op_binary_astnode("PLUS?", yystack_[2].value.as < exp_astnode* > (), yystack_[0].value.as < exp_astnode* > ());
}
#line 1915 "parser.tab.cc"
    break;

  case 55:
#line 356 "parser.yy"
                                                   {
    yylhs.value.as < exp_astnode* > () = new op_binary_astnode("MINUS?", yystack_[2].value.as < exp_astnode* > (), yystack_[0].value.as < exp_astnode* > ());
}
#line 1923 "parser.tab.cc"
    break;

  case 56:
#line 361 "parser.yy"
                                    {
    yylhs.value.as < exp_astnode* > () = yystack_[0].value.as < exp_astnode* > ();
}
#line 1931 "parser.tab.cc"
    break;

  case 57:
#line 364 "parser.yy"
                                 {
    yylhs.value.as < exp_astnode* > () = new op_unary_astnode(yystack_[1].value.as < std::string > (), yystack_[0].value.as < exp_astnode* > ());
}
#line 1939 "parser.tab.cc"
    break;

  case 58:
#line 369 "parser.yy"
                                           {
    yylhs.value.as < exp_astnode* > () = yystack_[0].value.as < exp_astnode* > ();
}
#line 1947 "parser.tab.cc"
    break;

  case 59:
#line 372 "parser.yy"
                                                {
    yylhs.value.as < exp_astnode* > () = new op_binary_astnode("MULT?", yystack_[2].value.as < exp_astnode* > (), yystack_[0].value.as < exp_astnode* > ());
}
#line 1955 "parser.tab.cc"
    break;

  case 60:
#line 375 "parser.yy"
                                                {
    yylhs.value.as < exp_astnode* > () = new op_binary_astnode("DIV?", yystack_[2].value.as < exp_astnode* > (), yystack_[0].value.as < exp_astnode* > ());
}
#line 1963 "parser.tab.cc"
    break;

  case 61:
#line 380 "parser.yy"
                                      {
    yylhs.value.as < exp_astnode* > () = yystack_[0].value.as < exp_astnode* > ();
}
#line 1971 "parser.tab.cc"
    break;

  case 62:
#line 383 "parser.yy"
                                       {
    yylhs.value.as < exp_astnode* > () = new arrayref_astnode(yystack_[3].value.as < exp_astnode* > (), yystack_[1].value.as < exp_astnode* > ());
}
#line 1979 "parser.tab.cc"
    break;

  case 63:
#line 386 "parser.yy"
                    {
}
#line 1986 "parser.tab.cc"
    break;

  case 64:
#line 388 "parser.yy"
                                    {
}
#line 1993 "parser.tab.cc"
    break;

  case 65:
#line 390 "parser.yy"
                                   {
    yylhs.value.as < exp_astnode* > () = new member_astnode(yystack_[2].value.as < exp_astnode* > (), new identifier_astnode(yystack_[0].value.as < std::string > ()));
}
#line 2001 "parser.tab.cc"
    break;

  case 66:
#line 393 "parser.yy"
                                      {
    yylhs.value.as < exp_astnode* > () = new arrow_astnode(yystack_[2].value.as < exp_astnode* > (), new identifier_astnode(yystack_[0].value.as < std::string > ()));
}
#line 2009 "parser.tab.cc"
    break;

  case 67:
#line 396 "parser.yy"
                           {
    
}
#line 2017 "parser.tab.cc"
    break;

  case 68:
#line 401 "parser.yy"
                              {
    yylhs.value.as < exp_astnode* > () = new identifier_astnode(yystack_[0].value.as < std::string > ());
}
#line 2025 "parser.tab.cc"
    break;

  case 69:
#line 404 "parser.yy"
              {
    yylhs.value.as < exp_astnode* > () = new intconst_astnode(yystack_[0].value.as < std::string > ());
}
#line 2033 "parser.tab.cc"
    break;

  case 70:
#line 407 "parser.yy"
                {
    yylhs.value.as < exp_astnode* > () = new floatconst_astnode(yystack_[0].value.as < std::string > ());
}
#line 2041 "parser.tab.cc"
    break;

  case 71:
#line 410 "parser.yy"
                {
    yylhs.value.as < exp_astnode* > () = new stringconst_astnode(yystack_[0].value.as < std::string > ());
    yylhs.value.as < exp_astnode* > ()->print();
}
#line 2050 "parser.tab.cc"
    break;

  case 72:
#line 414 "parser.yy"
                    {
}
#line 2057 "parser.tab.cc"
    break;

  case 73:
#line 418 "parser.yy"
                           {
}
#line 2064 "parser.tab.cc"
    break;

  case 74:
#line 420 "parser.yy"
                                {
}
#line 2071 "parser.tab.cc"
    break;

  case 75:
#line 424 "parser.yy"
                   {
    yylhs.value.as < std::string > () = std::string("UMINUS?");
}
#line 2079 "parser.tab.cc"
    break;

  case 76:
#line 427 "parser.yy"
     {
    yylhs.value.as < std::string > () = std::string("NOT");
}
#line 2087 "parser.tab.cc"
    break;

  case 77:
#line 430 "parser.yy"
     {
    yylhs.value.as < std::string > () = std::string("ADDRESS");
}
#line 2095 "parser.tab.cc"
    break;

  case 78:
#line 433 "parser.yy"
     {
    yylhs.value.as < std::string > () = std::string("DEREF");
}
#line 2103 "parser.tab.cc"
    break;

  case 79:
#line 438 "parser.yy"
                                                                   {
    yylhs.value.as < statement_astnode* > () = new if_astnode(yystack_[4].value.as < exp_astnode* > (), yystack_[2].value.as < statement_astnode* > (), yystack_[0].value.as < statement_astnode* > ());
}
#line 2111 "parser.tab.cc"
    break;

  case 80:
#line 443 "parser.yy"
                                                       {
    yylhs.value.as < statement_astnode* > () = new while_astnode(yystack_[2].value.as < exp_astnode* > (), yystack_[0].value.as < statement_astnode* > ());
}
#line 2119 "parser.tab.cc"
    break;

  case 81:
#line 446 "parser.yy"
                                                                                      {
    yylhs.value.as < statement_astnode* > () = new for_astnode(yystack_[6].value.as < assignE_astnode* > (), yystack_[4].value.as < exp_astnode* > (), yystack_[2].value.as < assignE_astnode* > (), yystack_[0].value.as < statement_astnode* > ());
}
#line 2127 "parser.tab.cc"
    break;

  case 82:
#line 451 "parser.yy"
                             {
}
#line 2134 "parser.tab.cc"
    break;

  case 83:
#line 453 "parser.yy"
                              {
}
#line 2141 "parser.tab.cc"
    break;

  case 84:
#line 457 "parser.yy"
                                               {
}
#line 2148 "parser.tab.cc"
    break;

  case 85:
#line 461 "parser.yy"
                           {
    yylhs.value.as < typespec_astnode > () = yystack_[0].value.as < typespec_astnode > ();
    string type = yystack_[0].value.as < typespec_astnode > ().typeName;
    int size = yystack_[0].value.as < typespec_astnode > ().typeWidth;
    int offset = ststack.top()->getNewOffset();
    SymTab* st = ststack.top();

    st->rows[topvarname] = SymEntry(type,SymTab::ST_HL_type::VAR,SymTab::ST_LPG::LOCAL,size,offset);
}
#line 2162 "parser.tab.cc"
    break;

  case 86:
#line 470 "parser.yy"
                                {
    yylhs.value.as < typespec_astnode > () = yystack_[0].value.as < typespec_astnode > ();
    string type = yystack_[0].value.as < typespec_astnode > ().typeName;
    int size = yystack_[0].value.as < typespec_astnode > ().typeWidth;
    int offset = ststack.top()->getNewOffset();
    ststack.top()->rows[topvarname] = SymEntry(type,SymTab::ST_HL_type::VAR,SymTab::ST_LPG::LOCAL,size,offset);
}
#line 2174 "parser.tab.cc"
    break;


#line 2178 "parser.tab.cc"

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


  const signed char Parser::yypact_ninf_ = -67;

  const signed char Parser::yytable_ninf_ = -15;

  const short
  Parser::yypact_[] =
  {
     -67,    46,    72,   -67,   -67,   -67,   -67,    44,    72,   -67,
     -67,    49,    51,   -67,   -67,   -21,    38,    48,    26,   114,
     -67,   122,    62,   -67,    16,   -67,    22,    61,   -67,   -67,
     -67,    65,    69,    78,   330,   -67,   -67,   330,   293,   -67,
     -67,   -67,   -67,   -67,   153,    33,    55,   -67,    73,   -67,
     -67,   -67,   -67,   188,   330,    16,   -67,    10,   -67,   -67,
      16,   -67,    99,   -67,   122,    56,   330,   330,   330,   113,
      -8,    92,    71,     2,    63,   -67,    74,    29,   223,   -67,
     258,   -67,   330,   -67,   142,   330,   143,   -67,   -67,   -67,
     -67,     7,   -67,   112,   -67,   146,   -67,   123,   154,    75,
      36,    39,   125,   298,   330,   -67,   330,   330,   330,   330,
     330,   330,   330,   330,   330,   330,   330,   -67,   -67,   -67,
     154,   -67,     9,   -67,    16,   -67,   -67,   131,   -67,   127,
     330,   293,   293,   330,   -67,    79,    92,    71,     2,     2,
      63,    63,    63,    63,    74,    74,   -67,   -67,   -67,   -67,
     -67,   -67,   154,   149,   -67,    -3,   -67,   293,   330,   -67,
     139,   293,   -67
  };

  const signed char
  Parser::yydefact_[] =
  {
       2,     0,     0,     1,    11,    12,    13,     0,     3,     4,
       5,     0,     8,     6,     7,     0,     0,     0,     0,     0,
      10,     0,     0,    16,     0,    17,     0,    68,    69,    70,
      71,     0,     0,     0,     0,    75,    78,     0,     0,    24,
      76,    77,    30,    35,     0,     0,    56,    61,     0,    28,
      32,    33,    34,     0,     0,     0,    82,     0,    14,    20,
       0,    19,    22,    15,     0,     0,     0,     0,     0,    68,
       0,    41,    43,    45,    48,    58,    53,     0,     0,    26,
       0,    83,     0,    67,     0,     0,     0,    38,    25,    29,
      57,     0,    85,     0,    23,     0,    18,    63,    73,     0,
       0,     0,     0,     0,     0,    36,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    72,    31,    27,
      37,    66,     0,    65,     0,    84,     9,     0,    39,    64,
       0,     0,     0,     0,    63,     0,    42,    44,    46,    47,
      51,    52,    49,    50,    54,    55,    59,    60,    62,    86,
      21,    40,    74,     0,    80,     0,    64,     0,     0,    79,
       0,     0,    81
  };

  const short
  Parser::yypgoto_[] =
  {
     -67,   -67,   -67,   163,   -67,   152,   -30,    77,    76,     8,
      20,   -19,    32,   -67,   -67,    81,   -66,   169,   -52,   -67,
     -67,   -67,   -67,   -17,   -67,     4,   -33,   -67,   -50,   -67,
     121,   -67,   -67,   -67,   -67
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,     8,     1,     9,    43,    44,    98,    71,    72,    73,
      74,    75,    76,    46,    47,    99,    48,    10,    49,    50,
      51,    52,    20,    53,    54,    55,    56,    91,    61,    62,
      25,    26,    16,     2,    17
  };

  const short
  Parser::yytable_[] =
  {
      45,    89,   102,   104,    70,    92,    11,    77,   104,    18,
      94,    81,    11,     4,     5,     6,    22,   109,   110,    45,
     104,    78,    24,    59,    81,    45,    89,    80,    89,     4,
       5,     6,    22,   105,    45,    90,   100,   101,   158,   124,
     104,   111,   112,    60,    93,   148,     3,   104,   125,    45,
     104,    12,   120,    63,    64,   122,    15,    23,   -14,    45,
     117,    45,    82,    69,    28,    29,    30,   131,    24,    58,
     132,    19,    83,    84,   149,     4,     5,     6,     7,   153,
     154,    21,    35,    36,   107,   108,    37,    97,   113,   114,
      85,    65,   160,    40,    41,    66,   146,   147,    86,    67,
     152,   115,   116,   155,   106,   159,   129,   130,    68,   162,
     156,   130,    45,    45,    87,   138,   139,     4,     5,     6,
      22,    27,    28,    29,    30,     4,     5,     6,    22,   140,
     141,   142,   143,    31,    95,    32,    33,    34,    45,    45,
      35,    36,    45,   103,    37,   144,   145,    38,    39,   121,
     123,    40,    41,   126,   127,    42,     4,     5,     6,    22,
      27,    28,    29,    30,   128,   104,   133,   150,   151,   157,
     161,    13,    31,    57,    32,    33,    34,    14,     0,    35,
      36,   136,   137,    37,   135,    96,    38,    79,     0,     0,
      40,    41,     0,     0,    42,    27,    28,    29,    30,     0,
       0,     0,     0,     0,     0,     0,     0,    31,     0,    32,
      33,    34,     0,     0,    35,    36,     0,     0,    37,     0,
       0,    38,    88,     0,     0,    40,    41,     0,     0,    42,
      27,    28,    29,    30,     0,     0,     0,     0,     0,     0,
       0,     0,    31,     0,    32,    33,    34,     0,     0,    35,
      36,     0,     0,    37,     0,     0,    38,   118,     0,     0,
      40,    41,     0,     0,    42,    27,    28,    29,    30,     0,
       0,     0,     0,     0,     0,     0,     0,    31,     0,    32,
      33,    34,     0,     0,    35,    36,     0,     0,    37,     0,
       0,    38,   119,     0,     0,    40,    41,     0,     0,    42,
      27,    28,    29,    30,     0,    69,    28,    29,    30,     0,
       0,     0,    31,     0,    32,    33,    34,     0,     0,    35,
      36,     0,     0,    37,    35,    36,    38,     0,    37,   134,
      40,    41,     0,     0,    42,    40,    41,    69,    28,    29,
      30,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    35,    36,     0,     0,
      37,     0,     0,     0,     0,     0,     0,    40,    41
  };

  const short
  Parser::yycheck_[] =
  {
      19,    53,    68,    11,    34,    55,     2,    37,    11,    30,
      60,    44,     8,     3,     4,     5,     6,    15,    16,    38,
      11,    38,    18,     7,    57,    44,    78,    44,    80,     3,
       4,     5,     6,    41,    53,    54,    66,    67,    41,    32,
      11,    39,    40,    27,    34,    36,     0,    11,    41,    68,
      11,     7,    82,    31,    32,    85,     7,    31,     7,    78,
      31,    80,    29,     7,     8,     9,    10,    31,    64,     7,
      31,    33,    17,    18,   124,     3,     4,     5,     6,   131,
     132,    33,    26,    27,    13,    14,    30,    31,    25,    26,
      35,    30,   158,    37,    38,    30,   115,   116,    43,    30,
     130,    27,    28,   133,    12,   157,    31,    32,    30,   161,
      31,    32,   131,   132,    41,   107,   108,     3,     4,     5,
       6,     7,     8,     9,    10,     3,     4,     5,     6,   109,
     110,   111,   112,    19,    35,    21,    22,    23,   157,   158,
      26,    27,   161,    30,    30,   113,   114,    33,    34,     7,
       7,    37,    38,    41,     8,    41,     3,     4,     5,     6,
       7,     8,     9,    10,    41,    11,    41,    36,    41,    20,
      31,     8,    19,    21,    21,    22,    23,     8,    -1,    26,
      27,   104,   106,    30,   103,    64,    33,    34,    -1,    -1,
      37,    38,    -1,    -1,    41,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,    21,
      22,    23,    -1,    -1,    26,    27,    -1,    -1,    30,    -1,
      -1,    33,    34,    -1,    -1,    37,    38,    -1,    -1,    41,
       7,     8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    19,    -1,    21,    22,    23,    -1,    -1,    26,
      27,    -1,    -1,    30,    -1,    -1,    33,    34,    -1,    -1,
      37,    38,    -1,    -1,    41,     7,     8,     9,    10,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,    21,
      22,    23,    -1,    -1,    26,    27,    -1,    -1,    30,    -1,
      -1,    33,    34,    -1,    -1,    37,    38,    -1,    -1,    41,
       7,     8,     9,    10,    -1,     7,     8,     9,    10,    -1,
      -1,    -1,    19,    -1,    21,    22,    23,    -1,    -1,    26,
      27,    -1,    -1,    30,    26,    27,    33,    -1,    30,    31,
      37,    38,    -1,    -1,    41,    37,    38,     7,     8,     9,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    -1,    -1,
      30,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    46,    77,     0,     3,     4,     5,     6,    45,    47,
      61,    69,     7,    47,    61,     7,    76,    78,    30,    33,
      66,    33,     6,    31,    69,    74,    75,     7,     8,     9,
      10,    19,    21,    22,    23,    26,    27,    30,    33,    34,
      37,    38,    41,    48,    49,    55,    57,    58,    60,    62,
      63,    64,    65,    67,    68,    69,    70,    49,     7,     7,
      27,    72,    73,    31,    32,    30,    30,    30,    30,     7,
      50,    51,    52,    53,    54,    55,    56,    50,    67,    34,
      67,    70,    29,    17,    18,    35,    43,    41,    34,    62,
      55,    71,    72,    34,    72,    35,    74,    31,    50,    59,
      50,    50,    60,    30,    11,    41,    12,    13,    14,    15,
      16,    39,    40,    25,    26,    27,    28,    31,    34,    34,
      50,     7,    50,     7,    32,    41,    41,     8,    41,    31,
      32,    31,    31,    41,    31,    59,    51,    52,    53,    53,
      54,    54,    54,    54,    56,    56,    55,    55,    36,    72,
      36,    41,    50,    62,    62,    50,    31,    20,    41,    62,
      60,    31,    62
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    44,    77,    46,    45,    45,    45,    45,    78,    47,
      61,    69,    69,    69,    69,    76,    76,    75,    75,    74,
      73,    73,    72,    72,    66,    66,    66,    66,    67,    67,
      62,    62,    62,    62,    62,    62,    62,    60,    65,    48,
      48,    50,    50,    51,    51,    52,    52,    52,    53,    53,
      53,    53,    53,    54,    54,    54,    55,    55,    56,    56,
      56,    57,    57,    57,    57,    57,    57,    57,    58,    58,
      58,    58,    58,    59,    59,    68,    68,    68,    68,    63,
      64,    64,    49,    49,    70,    71,    71
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     0,     2,     1,     1,     2,     2,     0,     7,
       3,     1,     1,     1,     2,     4,     3,     1,     3,     2,
       1,     4,     1,     2,     2,     3,     3,     4,     1,     2,
       1,     3,     1,     1,     1,     1,     3,     3,     2,     4,
       5,     1,     3,     1,     3,     1,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     2,     1,     3,
       3,     1,     4,     3,     4,     3,     3,     2,     1,     1,
       1,     1,     3,     1,     3,     1,     1,     1,     1,     7,
       5,     9,     1,     2,     3,     1,     3
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
  "$@2", YY_NULLPTR
  };


  const short
  Parser::yyrline_[] =
  {
       0,   104,   104,   104,   118,   121,   125,   127,   133,   133,
     142,   147,   155,   164,   172,   183,   190,   199,   203,   209,
     214,   219,   228,   231,   238,   241,   244,   249,   254,   262,
     268,   271,   274,   277,   280,   283,   286,   291,   296,   301,
     303,   307,   310,   314,   317,   322,   325,   328,   333,   336,
     339,   342,   345,   350,   353,   356,   361,   364,   369,   372,
     375,   380,   383,   386,   388,   390,   393,   396,   401,   404,
     407,   410,   414,   418,   420,   424,   427,   430,   433,   438,
     443,   446,   451,   453,   457,   461,   470
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
#line 2679 "parser.tab.cc"

#line 479 "parser.yy"

//grammar definition.
void IPL::Parser::error( const location_type &l, const std::string &err_message )
{
   std::cerr << "Error: " << err_message << " at " << l << "\n";
}

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
<<<<<<< HEAD
#line 46 "parser.yy"
=======
#line 47 "parser.yy"
>>>>>>> semchecks

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
typespec_astnode structc,intc,floatc,stringc;
typespec_astnode toptype;
string topvarname;

#line 62 "parser.tab.cc"


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
#line 154 "parser.tab.cc"


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
      case 48: // declaration_list
        value.move< abstract_astnode* > (std::move (that.value));
        break;

      case 59: // assignment_expression
        value.move< assignE_astnode* > (std::move (that.value));
        break;

      case 49: // expression
      case 50: // unary_expression
      case 51: // postfix_expression
      case 52: // primary_expression
        value.move< exp_astnode* > (std::move (that.value));
        break;

      case 58: // procedure_call
        value.move< funcall_astnode* > (std::move (that.value));
        break;

      case 76: // fun_declarator
        value.move< fundeclarator_astnode* > (std::move (that.value));
        break;

      case 53: // logical_and_expression
      case 54: // equality_expression
      case 55: // relational_expression
      case 56: // additive_expression
      case 57: // multiplicative_expression
        value.move< op_binary_astnode* > (std::move (that.value));
        break;

      case 60: // function_definition
      case 61: // statement
      case 62: // selection_statement
      case 63: // iteration_statement
      case 64: // assignment_statement
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

      case 67: // expression_list
        value.move< std::vector<exp_astnode*> > (std::move (that.value));
        break;

      case 65: // compound_statement
      case 66: // statement_list
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
      case 48: // declaration_list
        value.copy< abstract_astnode* > (YY_MOVE (that.value));
        break;

      case 59: // assignment_expression
        value.copy< assignE_astnode* > (YY_MOVE (that.value));
        break;

      case 49: // expression
      case 50: // unary_expression
      case 51: // postfix_expression
      case 52: // primary_expression
        value.copy< exp_astnode* > (YY_MOVE (that.value));
        break;

      case 58: // procedure_call
        value.copy< funcall_astnode* > (YY_MOVE (that.value));
        break;

      case 76: // fun_declarator
        value.copy< fundeclarator_astnode* > (YY_MOVE (that.value));
        break;

      case 53: // logical_and_expression
      case 54: // equality_expression
      case 55: // relational_expression
      case 56: // additive_expression
      case 57: // multiplicative_expression
        value.copy< op_binary_astnode* > (YY_MOVE (that.value));
        break;

      case 60: // function_definition
      case 61: // statement
      case 62: // selection_statement
      case 63: // iteration_statement
      case 64: // assignment_statement
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

      case 67: // expression_list
        value.copy< std::vector<exp_astnode*> > (YY_MOVE (that.value));
        break;

      case 65: // compound_statement
      case 66: // statement_list
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
      case 48: // declaration_list
        value.move< abstract_astnode* > (YY_MOVE (s.value));
        break;

      case 59: // assignment_expression
        value.move< assignE_astnode* > (YY_MOVE (s.value));
        break;

      case 49: // expression
      case 50: // unary_expression
      case 51: // postfix_expression
      case 52: // primary_expression
        value.move< exp_astnode* > (YY_MOVE (s.value));
        break;

      case 58: // procedure_call
        value.move< funcall_astnode* > (YY_MOVE (s.value));
        break;

      case 76: // fun_declarator
        value.move< fundeclarator_astnode* > (YY_MOVE (s.value));
        break;

      case 53: // logical_and_expression
      case 54: // equality_expression
      case 55: // relational_expression
      case 56: // additive_expression
      case 57: // multiplicative_expression
        value.move< op_binary_astnode* > (YY_MOVE (s.value));
        break;

      case 60: // function_definition
      case 61: // statement
      case 62: // selection_statement
      case 63: // iteration_statement
      case 64: // assignment_statement
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

      case 67: // expression_list
        value.move< std::vector<exp_astnode*> > (YY_MOVE (s.value));
        break;

      case 65: // compound_statement
      case 66: // statement_list
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
      case 48: // declaration_list
        value.YY_MOVE_OR_COPY< abstract_astnode* > (YY_MOVE (that.value));
        break;

      case 59: // assignment_expression
        value.YY_MOVE_OR_COPY< assignE_astnode* > (YY_MOVE (that.value));
        break;

      case 49: // expression
      case 50: // unary_expression
      case 51: // postfix_expression
      case 52: // primary_expression
        value.YY_MOVE_OR_COPY< exp_astnode* > (YY_MOVE (that.value));
        break;

      case 58: // procedure_call
        value.YY_MOVE_OR_COPY< funcall_astnode* > (YY_MOVE (that.value));
        break;

      case 76: // fun_declarator
        value.YY_MOVE_OR_COPY< fundeclarator_astnode* > (YY_MOVE (that.value));
        break;

      case 53: // logical_and_expression
      case 54: // equality_expression
      case 55: // relational_expression
      case 56: // additive_expression
      case 57: // multiplicative_expression
        value.YY_MOVE_OR_COPY< op_binary_astnode* > (YY_MOVE (that.value));
        break;

      case 60: // function_definition
      case 61: // statement
      case 62: // selection_statement
      case 63: // iteration_statement
      case 64: // assignment_statement
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

      case 67: // expression_list
        value.YY_MOVE_OR_COPY< std::vector<exp_astnode*> > (YY_MOVE (that.value));
        break;

      case 65: // compound_statement
      case 66: // statement_list
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
      case 48: // declaration_list
        value.move< abstract_astnode* > (YY_MOVE (that.value));
        break;

      case 59: // assignment_expression
        value.move< assignE_astnode* > (YY_MOVE (that.value));
        break;

      case 49: // expression
      case 50: // unary_expression
      case 51: // postfix_expression
      case 52: // primary_expression
        value.move< exp_astnode* > (YY_MOVE (that.value));
        break;

      case 58: // procedure_call
        value.move< funcall_astnode* > (YY_MOVE (that.value));
        break;

      case 76: // fun_declarator
        value.move< fundeclarator_astnode* > (YY_MOVE (that.value));
        break;

      case 53: // logical_and_expression
      case 54: // equality_expression
      case 55: // relational_expression
      case 56: // additive_expression
      case 57: // multiplicative_expression
        value.move< op_binary_astnode* > (YY_MOVE (that.value));
        break;

      case 60: // function_definition
      case 61: // statement
      case 62: // selection_statement
      case 63: // iteration_statement
      case 64: // assignment_statement
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

      case 67: // expression_list
        value.move< std::vector<exp_astnode*> > (YY_MOVE (that.value));
        break;

      case 65: // compound_statement
      case 66: // statement_list
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
      case 48: // declaration_list
        value.copy< abstract_astnode* > (that.value);
        break;

      case 59: // assignment_expression
        value.copy< assignE_astnode* > (that.value);
        break;

      case 49: // expression
      case 50: // unary_expression
      case 51: // postfix_expression
      case 52: // primary_expression
        value.copy< exp_astnode* > (that.value);
        break;

      case 58: // procedure_call
        value.copy< funcall_astnode* > (that.value);
        break;

      case 76: // fun_declarator
        value.copy< fundeclarator_astnode* > (that.value);
        break;

      case 53: // logical_and_expression
      case 54: // equality_expression
      case 55: // relational_expression
      case 56: // additive_expression
      case 57: // multiplicative_expression
        value.copy< op_binary_astnode* > (that.value);
        break;

      case 60: // function_definition
      case 61: // statement
      case 62: // selection_statement
      case 63: // iteration_statement
      case 64: // assignment_statement
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

      case 67: // expression_list
        value.copy< std::vector<exp_astnode*> > (that.value);
        break;

      case 65: // compound_statement
      case 66: // statement_list
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
      case 48: // declaration_list
        value.move< abstract_astnode* > (that.value);
        break;

      case 59: // assignment_expression
        value.move< assignE_astnode* > (that.value);
        break;

      case 49: // expression
      case 50: // unary_expression
      case 51: // postfix_expression
      case 52: // primary_expression
        value.move< exp_astnode* > (that.value);
        break;

      case 58: // procedure_call
        value.move< funcall_astnode* > (that.value);
        break;

      case 76: // fun_declarator
        value.move< fundeclarator_astnode* > (that.value);
        break;

      case 53: // logical_and_expression
      case 54: // equality_expression
      case 55: // relational_expression
      case 56: // additive_expression
      case 57: // multiplicative_expression
        value.move< op_binary_astnode* > (that.value);
        break;

      case 60: // function_definition
      case 61: // statement
      case 62: // selection_statement
      case 63: // iteration_statement
      case 64: // assignment_statement
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

      case 67: // expression_list
        value.move< std::vector<exp_astnode*> > (that.value);
        break;

      case 65: // compound_statement
      case 66: // statement_list
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
<<<<<<< HEAD
      case symbol_kind::S_VOID: // VOID
#line 20 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 925 "parser.tab.cc"
        break;

      case symbol_kind::S_INT: // INT
#line 21 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 931 "parser.tab.cc"
        break;

      case symbol_kind::S_FLOAT: // FLOAT
#line 22 "parser.yy"
=======
      case 3: // VOID
#line 21 "parser.yy"
>>>>>>> semchecks
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1053 "parser.tab.cc"
        break;

<<<<<<< HEAD
      case symbol_kind::S_STRUCT: // STRUCT
#line 23 "parser.yy"
=======
      case 4: // INT
#line 22 "parser.yy"
>>>>>>> semchecks
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1059 "parser.tab.cc"
        break;

<<<<<<< HEAD
      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
#line 24 "parser.yy"
=======
      case 5: // FLOAT
#line 23 "parser.yy"
>>>>>>> semchecks
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1065 "parser.tab.cc"
        break;

<<<<<<< HEAD
      case symbol_kind::S_INT_CONSTANT: // INT_CONSTANT
#line 25 "parser.yy"
=======
      case 6: // STRUCT
#line 24 "parser.yy"
>>>>>>> semchecks
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1071 "parser.tab.cc"
        break;

<<<<<<< HEAD
      case symbol_kind::S_FLOAT_CONSTANT: // FLOAT_CONSTANT
#line 26 "parser.yy"
=======
      case 7: // IDENTIFIER
#line 25 "parser.yy"
>>>>>>> semchecks
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1077 "parser.tab.cc"
        break;

<<<<<<< HEAD
      case symbol_kind::S_STRING_LITERAL: // STRING_LITERAL
#line 27 "parser.yy"
=======
      case 8: // INT_CONSTANT
#line 26 "parser.yy"
>>>>>>> semchecks
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1083 "parser.tab.cc"
        break;

<<<<<<< HEAD
      case symbol_kind::S_OR_OP: // OR_OP
#line 28 "parser.yy"
=======
      case 9: // FLOAT_CONSTANT
#line 27 "parser.yy"
>>>>>>> semchecks
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1089 "parser.tab.cc"
        break;

<<<<<<< HEAD
      case symbol_kind::S_AND_OP: // AND_OP
#line 29 "parser.yy"
=======
      case 10: // STRING_LITERAL
#line 28 "parser.yy"
>>>>>>> semchecks
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1095 "parser.tab.cc"
        break;

<<<<<<< HEAD
      case symbol_kind::S_EQ_OP: // EQ_OP
#line 30 "parser.yy"
=======
      case 11: // OR_OP
#line 29 "parser.yy"
>>>>>>> semchecks
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1101 "parser.tab.cc"
        break;

<<<<<<< HEAD
      case symbol_kind::S_NE_OP: // NE_OP
#line 31 "parser.yy"
=======
      case 12: // AND_OP
#line 30 "parser.yy"
>>>>>>> semchecks
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1107 "parser.tab.cc"
        break;

<<<<<<< HEAD
      case symbol_kind::S_LE_OP: // LE_OP
#line 32 "parser.yy"
=======
      case 13: // EQ_OP
#line 31 "parser.yy"
>>>>>>> semchecks
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1113 "parser.tab.cc"
        break;

<<<<<<< HEAD
      case symbol_kind::S_GE_OP: // GE_OP
#line 33 "parser.yy"
=======
      case 14: // NE_OP
#line 32 "parser.yy"
>>>>>>> semchecks
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1119 "parser.tab.cc"
        break;

<<<<<<< HEAD
      case symbol_kind::S_INC_OP: // INC_OP
#line 34 "parser.yy"
=======
      case 15: // LE_OP
#line 33 "parser.yy"
>>>>>>> semchecks
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1125 "parser.tab.cc"
        break;

<<<<<<< HEAD
      case symbol_kind::S_PTR_OP: // PTR_OP
#line 35 "parser.yy"
=======
      case 16: // GE_OP
#line 34 "parser.yy"
>>>>>>> semchecks
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1131 "parser.tab.cc"
        break;

<<<<<<< HEAD
      case symbol_kind::S_IF: // IF
#line 36 "parser.yy"
=======
      case 17: // INC_OP
#line 35 "parser.yy"
>>>>>>> semchecks
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1137 "parser.tab.cc"
        break;

<<<<<<< HEAD
      case symbol_kind::S_ELSE: // ELSE
#line 37 "parser.yy"
=======
      case 18: // PTR_OP
#line 36 "parser.yy"
>>>>>>> semchecks
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1143 "parser.tab.cc"
        break;

<<<<<<< HEAD
      case symbol_kind::S_WHILE: // WHILE
#line 38 "parser.yy"
=======
      case 19: // IF
#line 37 "parser.yy"
>>>>>>> semchecks
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1149 "parser.tab.cc"
        break;

<<<<<<< HEAD
      case symbol_kind::S_FOR: // FOR
#line 39 "parser.yy"
=======
      case 20: // ELSE
#line 38 "parser.yy"
>>>>>>> semchecks
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1155 "parser.tab.cc"
        break;

<<<<<<< HEAD
      case symbol_kind::S_RETURN: // RETURN
#line 40 "parser.yy"
=======
      case 21: // WHILE
#line 39 "parser.yy"
>>>>>>> semchecks
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1161 "parser.tab.cc"
        break;

<<<<<<< HEAD
      case symbol_kind::S_OTHERS: // OTHERS
#line 41 "parser.yy"
=======
      case 22: // FOR
#line 40 "parser.yy"
>>>>>>> semchecks
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1167 "parser.tab.cc"
        break;

      case 23: // RETURN
#line 41 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1173 "parser.tab.cc"
        break;

      case 24: // OTHERS
#line 42 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1179 "parser.tab.cc"
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
      case 48: // declaration_list
        yylhs.value.emplace< abstract_astnode* > ();
        break;

      case 59: // assignment_expression
        yylhs.value.emplace< assignE_astnode* > ();
        break;

      case 49: // expression
      case 50: // unary_expression
      case 51: // postfix_expression
      case 52: // primary_expression
        yylhs.value.emplace< exp_astnode* > ();
        break;

      case 58: // procedure_call
        yylhs.value.emplace< funcall_astnode* > ();
        break;

      case 76: // fun_declarator
        yylhs.value.emplace< fundeclarator_astnode* > ();
        break;

      case 53: // logical_and_expression
      case 54: // equality_expression
      case 55: // relational_expression
      case 56: // additive_expression
      case 57: // multiplicative_expression
        yylhs.value.emplace< op_binary_astnode* > ();
        break;

      case 60: // function_definition
      case 61: // statement
      case 62: // selection_statement
      case 63: // iteration_statement
      case 64: // assignment_statement
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

      case 67: // expression_list
        yylhs.value.emplace< std::vector<exp_astnode*> > ();
        break;

      case 65: // compound_statement
      case 66: // statement_list
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
<<<<<<< HEAD
  case 2: // $@1: %empty
#line 110 "parser.yy"
=======
  case 2:
#line 114 "parser.yy"
>>>>>>> semchecks
             {
    structc = typespec_astnode::structc;
    intc = typespec_astnode::intc;
    floatc = typespec_astnode::floatc;
    stringc = typespec_astnode::stringc;
    if(!Symbols::symTabConstructed){
        Symbols::gst = new SymTab();
    }
    else{
        // std::cout<<"Here again";
    }
    ststack.push(Symbols::gst);

}
#line 1525 "parser.tab.cc"
    break;

<<<<<<< HEAD
  case 3: // begin_nterm: $@1 translation_unit
#line 123 "parser.yy"
=======
  case 3:
#line 127 "parser.yy"
>>>>>>> semchecks
                   {
    if(!Symbols::symTabConstructed){
        Symbols::symTabConstructed = true;
        // std::cerr<<"Parsing round 1 done"<<std::endl;
    }
    else{
        ststack.top()->printJson();
        // std::cout<<"here again"<<std::endl;
    }
}
#line 1540 "parser.tab.cc"
    break;

<<<<<<< HEAD
  case 4: // translation_unit: struct_specifier
#line 133 "parser.yy"
=======
  case 4:
#line 138 "parser.yy"
>>>>>>> semchecks
                                  {
    if(!Symbols::symTabConstructed){
        for(auto entry: ststack.top()->rows){
            if(entry.second.size==0&&entry.second.hltype==SymTab::ST_HL_type::STRUCT){
                ststack.top()->rows[entry.first].size = Symbols::getStructBaseTypeWidth(entry.first);
            }
        }
    }
}
#line 1554 "parser.tab.cc"
    break;

<<<<<<< HEAD
  case 5: // translation_unit: function_definition
#line 142 "parser.yy"
=======
  case 5:
#line 147 "parser.yy"
>>>>>>> semchecks
                     {
    yylhs.value.as < std::vector<abstract_astnode*> > () = std::vector<abstract_astnode*>();
    yylhs.value.as < std::vector<abstract_astnode*> > ().push_back(yystack_[0].value.as < statement_astnode* > ());
}
#line 1563 "parser.tab.cc"
    break;

<<<<<<< HEAD
  case 6: // translation_unit: translation_unit struct_specifier
#line 146 "parser.yy"
=======
  case 6:
#line 151 "parser.yy"
>>>>>>> semchecks
                                   {
}
#line 1570 "parser.tab.cc"
    break;

<<<<<<< HEAD
  case 7: // translation_unit: translation_unit function_definition
#line 148 "parser.yy"
=======
  case 7:
#line 153 "parser.yy"
>>>>>>> semchecks
                                      {
    yylhs.value.as < std::vector<abstract_astnode*> > () = yystack_[1].value.as < std::vector<abstract_astnode*> > ();
    yylhs.value.as < std::vector<abstract_astnode*> > ().push_back(yystack_[0].value.as < statement_astnode* > ());
}
#line 1579 "parser.tab.cc"
    break;

<<<<<<< HEAD
  case 8: // $@2: %empty
#line 154 "parser.yy"
=======
  case 8:
#line 159 "parser.yy"
>>>>>>> semchecks
                                    {
    string structName = "struct " + yystack_[0].value.as < std::string > ();
    if(!Symbols::symTabConstructed){
        ststack.top()->rows[structName] = SymEntry(structc,SymTab::ST_HL_type::STRUCT,SymTab::ST_LPG::GLOBAL,0,0);
        Symbols::slsts[structName] = new SymTab();
        Symbols::slsts[structName]->type = "struct";
    }
    ststack.push(Symbols::slsts[structName]);
}
<<<<<<< HEAD
#line 1470 "parser.tab.cc"
=======
#line 1594 "parser.tab.cc"
>>>>>>> semchecks
    break;

  case 9:
#line 168 "parser.yy"
                             {
    // if(!Symbols::symTabConstructed){
        ststack.pop();
    // }
}
<<<<<<< HEAD
#line 1480 "parser.tab.cc"
=======
#line 1604 "parser.tab.cc"
>>>>>>> semchecks
    break;

  case 10:
#line 174 "parser.yy"
                                                                     {
    if(Symbols::symTabConstructed){
        ststack.top()->ptr = new seq_astnode(yystack_[0].value.as < std::vector<statement_astnode*> > ());
    }
    yylhs.value.as < statement_astnode* > () = nullptr;
    ststack.pop();
}
<<<<<<< HEAD
#line 1492 "parser.tab.cc"
    break;

  case 11: // type_specifier: VOID
#line 176 "parser.yy"
=======
#line 1614 "parser.tab.cc"
    break;

  case 11:
#line 180 "parser.yy"
>>>>>>> semchecks
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
<<<<<<< HEAD
#line 1509 "parser.tab.cc"
    break;

  case 12: // type_specifier: INT
#line 188 "parser.yy"
=======
#line 1631 "parser.tab.cc"
    break;

  case 12:
#line 192 "parser.yy"
>>>>>>> semchecks
     {
    // retType = SymTab::ST_type::INT;
    typespec_astnode ts = intc;
    yylhs.value.as < typespec_astnode > () = ts;
    if(!Symbols::symTabConstructed){
        toptype = ts;
    }

}
<<<<<<< HEAD
#line 1523 "parser.tab.cc"
    break;

  case 13: // type_specifier: FLOAT
#line 197 "parser.yy"
=======
#line 1649 "parser.tab.cc"
    break;

  case 13:
#line 205 "parser.yy"
>>>>>>> semchecks
       {
    // retType = SymTab::ST_type::FLOAT;
    typespec_astnode ts = floatc;
    yylhs.value.as < typespec_astnode > () = ts;
    if(!Symbols::symTabConstructed){
        toptype = ts;
    }
}
<<<<<<< HEAD
#line 1536 "parser.tab.cc"
    break;

  case 14: // type_specifier: STRUCT IDENTIFIER
#line 205 "parser.yy"
=======
#line 1666 "parser.tab.cc"
    break;

  case 14:
#line 217 "parser.yy"
>>>>>>> semchecks
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
<<<<<<< HEAD
#line 1553 "parser.tab.cc"
    break;

  case 15: // $@3: %empty
#line 219 "parser.yy"
=======
#line 1683 "parser.tab.cc"
    break;

  case 15:
#line 231 "parser.yy"
>>>>>>> semchecks
                              {
    std::string name = yystack_[1].value.as < std::string > ();
    if(!Symbols::symTabConstructed){
        ststack.top()->rows[name] = SymEntry(toptype,SymTab::ST_HL_type::FUN,SymTab::ST_LPG::GLOBAL,0,0);
        Symbols::flsts[name] = new SymTab();
        Symbols::flsts[name]->type = "function";
    }
    ststack.push(Symbols::flsts[name]);
}
<<<<<<< HEAD
#line 1567 "parser.tab.cc"
    break;

  case 16: // fun_declarator: IDENTIFIER '(' $@3 parameter_list ')'
#line 227 "parser.yy"
=======
#line 1697 "parser.tab.cc"
    break;

  case 16:
#line 239 "parser.yy"
>>>>>>> semchecks
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
        //TODO: fix this.
        std::string name = yystack_[4].value.as < std::string > ();
        std::vector<typespec_astnode> vect = std::vector<typespec_astnode>();
        yylhs.value.as < fundeclarator_astnode* > () = new fundeclarator_astnode(name, vect);
    }
}
<<<<<<< HEAD
#line 1595 "parser.tab.cc"
    break;

  case 17: // fun_declarator: IDENTIFIER '(' ')'
#line 250 "parser.yy"
=======
#line 1724 "parser.tab.cc"
    break;

  case 17:
#line 261 "parser.yy"
>>>>>>> semchecks
                    {
    std::string name = yystack_[2].value.as < std::string > ();
    if(!Symbols::symTabConstructed){
        ststack.top()->rows[name] = SymEntry(toptype,SymTab::ST_HL_type::FUN,SymTab::ST_LPG::GLOBAL,0,0);
        Symbols::flsts[name] = new SymTab();
    }
    else{
        yylhs.value.as < fundeclarator_astnode* > () = new fundeclarator_astnode(name,std::vector<typespec_astnode>());
    }
    ststack.push(Symbols::flsts[name]);
}
<<<<<<< HEAD
#line 1611 "parser.tab.cc"
    break;

  case 18: // parameter_list: parameter_declaration
#line 263 "parser.yy"
=======
#line 1738 "parser.tab.cc"
    break;

  case 18:
#line 272 "parser.yy"
>>>>>>> semchecks
                                     {
    if(Symbols::symTabConstructed){
        yylhs.value.as < std::vector<typespec_astnode> > () = std::vector<typespec_astnode>();
        yylhs.value.as < std::vector<typespec_astnode> > ().push_back(yystack_[0].value.as < typespec_astnode > ());
    }
}
<<<<<<< HEAD
#line 1622 "parser.tab.cc"
    break;

  case 19: // parameter_list: parameter_declaration ',' parameter_list
#line 269 "parser.yy"
=======
#line 1747 "parser.tab.cc"
    break;

  case 19:
#line 276 "parser.yy"
>>>>>>> semchecks
                                           {
    if(Symbols::symTabConstructed){
        yylhs.value.as < std::vector<typespec_astnode> > () = yystack_[0].value.as < std::vector<typespec_astnode> > ();
        yylhs.value.as < std::vector<typespec_astnode> > ().push_back(yystack_[2].value.as < typespec_astnode > ());
    }
}
#line 1756 "parser.tab.cc"
    break;

<<<<<<< HEAD
  case 20: // parameter_declaration: type_specifier declarator
#line 277 "parser.yy"
=======
  case 20:
#line 282 "parser.yy"
>>>>>>> semchecks
                                                {
    yylhs.value.as < typespec_astnode > () = yystack_[1].value.as < typespec_astnode > ();
    if(!Symbols::symTabConstructed){
        ststack.top()->rows[topvarname] = SymEntry(toptype,SymTab::ST_HL_type::VAR,SymTab::ST_LPG::PARAM,toptype.typeWidth,0);
        ststack.top()->rows[topvarname].offset = ststack.top()->getParamOffset(ststack.top()->rows[topvarname].size);
    }
}
#line 1768 "parser.tab.cc"
    break;

<<<<<<< HEAD
  case 21: // declarator_arr: IDENTIFIER
#line 286 "parser.yy"
=======
  case 21:
#line 291 "parser.yy"
>>>>>>> semchecks
                          {
    yylhs.value.as < typespec_astnode > () = toptype;
    yylhs.value.as < typespec_astnode > ().typeWidth = yylhs.value.as < typespec_astnode > ().baseTypeWidth;
    if(!Symbols::symTabConstructed){
        topvarname = yystack_[0].value.as < std::string > ();
    }
}
#line 1780 "parser.tab.cc"
    break;

<<<<<<< HEAD
  case 22: // declarator_arr: declarator_arr '[' INT_CONSTANT ']'
#line 293 "parser.yy"
=======
  case 22:
#line 298 "parser.yy"
>>>>>>> semchecks
                                     {
    yylhs.value.as < typespec_astnode > () = yystack_[3].value.as < typespec_astnode > ();
    if(!Symbols::symTabConstructed){
        typespec_astnode tstmp = yystack_[3].value.as < typespec_astnode > ();
        yylhs.value.as < typespec_astnode > ().typeWidth = ((tstmp).typeWidth) * (std::stoi(yystack_[1].value.as < std::string > ()));
        yylhs.value.as < typespec_astnode > ().typeName = (tstmp).typeName+"["+(yystack_[1].value.as < std::string > ())+"]";
        yylhs.value.as < typespec_astnode > ().arrsizes.push_back(std::stoi(yystack_[1].value.as < std::string > ()));
    }
}
#line 1794 "parser.tab.cc"
    break;

<<<<<<< HEAD
  case 23: // declarator: declarator_arr
#line 303 "parser.yy"
=======
  case 23:
#line 308 "parser.yy"
>>>>>>> semchecks
                          {
    yylhs.value.as < typespec_astnode > () = yystack_[0].value.as < typespec_astnode > ();
}
#line 1802 "parser.tab.cc"
    break;

<<<<<<< HEAD
  case 24: // declarator: '*' declarator
#line 306 "parser.yy"
=======
  case 24:
#line 311 "parser.yy"
>>>>>>> semchecks
                 {
    yylhs.value.as < typespec_astnode > () = yystack_[0].value.as < typespec_astnode > ();
    yylhs.value.as < typespec_astnode > ().typeWidth = 4;
    yylhs.value.as < typespec_astnode > ().baseTypeWidth = yystack_[0].value.as < typespec_astnode > ().typeWidth;
    yylhs.value.as < typespec_astnode > ().numptrstars+=1;
    yylhs.value.as < typespec_astnode > ().typeName = yylhs.value.as < typespec_astnode > ().genTypeName();
}
<<<<<<< HEAD
#line 1691 "parser.tab.cc"
    break;

  case 25: // compound_statement: '{' '}'
#line 315 "parser.yy"
                           {
    yylhs.value.as < std::vector<statement_astnode*> > () = std::vector<statement_astnode*>();
}
#line 1699 "parser.tab.cc"
    break;

  case 26: // compound_statement: '{' statement_list '}'
#line 318 "parser.yy"
                        {
    yylhs.value.as < std::vector<statement_astnode*> > () = yystack_[1].value.as < std::vector<statement_astnode*> > ();
}
#line 1707 "parser.tab.cc"
    break;

  case 27: // compound_statement: '{' declaration_list '}'
#line 321 "parser.yy"
=======
#line 1813 "parser.tab.cc"
    break;

  case 25:
#line 319 "parser.yy"
                           {
    yylhs.value.as < std::vector<statement_astnode*> > () = std::vector<statement_astnode*>();
}
#line 1821 "parser.tab.cc"
    break;

  case 26:
#line 322 "parser.yy"
                        {
    yylhs.value.as < std::vector<statement_astnode*> > () = yystack_[1].value.as < std::vector<statement_astnode*> > ();
}
#line 1829 "parser.tab.cc"
    break;

  case 27:
#line 325 "parser.yy"
>>>>>>> semchecks
                           {
    //TODO
    yylhs.value.as < std::vector<statement_astnode*> > () = std::vector<statement_astnode*>();

}
<<<<<<< HEAD
#line 1717 "parser.tab.cc"
    break;

  case 28: // compound_statement: '{' declaration_list statement_list '}'
#line 326 "parser.yy"
                                         {
    yylhs.value.as < std::vector<statement_astnode*> > () = yystack_[1].value.as < std::vector<statement_astnode*> > ();
}
#line 1725 "parser.tab.cc"
    break;

  case 29: // statement_list: statement
#line 331 "parser.yy"
=======
#line 1839 "parser.tab.cc"
    break;

  case 28:
#line 330 "parser.yy"
                                         {
    yylhs.value.as < std::vector<statement_astnode*> > () = yystack_[1].value.as < std::vector<statement_astnode*> > ();
}
#line 1847 "parser.tab.cc"
    break;

  case 29:
#line 335 "parser.yy"
>>>>>>> semchecks
                          {
    std::vector<statement_astnode*> temp;
    statement_astnode* stmt = yystack_[0].value.as < statement_astnode* > ();
    if(stmt!=NULL){
        temp.push_back(yystack_[0].value.as < statement_astnode* > ());
    }
    yylhs.value.as < std::vector<statement_astnode*> > () = temp;
}
<<<<<<< HEAD
#line 1738 "parser.tab.cc"
    break;

  case 30: // statement_list: statement_list statement
#line 339 "parser.yy"
=======
#line 1860 "parser.tab.cc"
    break;

  case 30:
#line 343 "parser.yy"
>>>>>>> semchecks
                          {
    yystack_[1].value.as < std::vector<statement_astnode*> > ().push_back(yystack_[0].value.as < statement_astnode* > ());
    yylhs.value.as < std::vector<statement_astnode*> > () = yystack_[1].value.as < std::vector<statement_astnode*> > ();
}
<<<<<<< HEAD
#line 1747 "parser.tab.cc"
    break;

  case 31: // statement: ';'
#line 345 "parser.yy"
=======
#line 1869 "parser.tab.cc"
    break;

  case 31:
#line 349 "parser.yy"
>>>>>>> semchecks
              {
    if(Symbols::symTabConstructed){   
        yylhs.value.as < statement_astnode* > () = new empty_astnode();
    }
}
<<<<<<< HEAD
#line 1757 "parser.tab.cc"
    break;

  case 32: // statement: '{' statement_list '}'
#line 350 "parser.yy"
=======
#line 1877 "parser.tab.cc"
    break;

  case 32:
#line 352 "parser.yy"
>>>>>>> semchecks
                        {
    if(Symbols::symTabConstructed){   
        yylhs.value.as < statement_astnode* > () = new seq_astnode(yystack_[1].value.as < std::vector<statement_astnode*> > ());
    }
}
<<<<<<< HEAD
#line 1767 "parser.tab.cc"
    break;

  case 33: // statement: selection_statement
=======
#line 1885 "parser.tab.cc"
    break;

  case 33:
>>>>>>> semchecks
#line 355 "parser.yy"
                     {
    yylhs.value.as < statement_astnode* > () = yystack_[0].value.as < statement_astnode* > ();
}
<<<<<<< HEAD
#line 1775 "parser.tab.cc"
    break;

  case 34: // statement: iteration_statement
=======
#line 1893 "parser.tab.cc"
    break;

  case 34:
>>>>>>> semchecks
#line 358 "parser.yy"
                     {
    yylhs.value.as < statement_astnode* > () = yystack_[0].value.as < statement_astnode* > ();
}
<<<<<<< HEAD
#line 1783 "parser.tab.cc"
    break;

  case 35: // statement: assignment_statement
=======
#line 1901 "parser.tab.cc"
    break;

  case 35:
>>>>>>> semchecks
#line 361 "parser.yy"
                      {
    yylhs.value.as < statement_astnode* > () = yystack_[0].value.as < statement_astnode* > ();
}
<<<<<<< HEAD
#line 1791 "parser.tab.cc"
    break;

  case 36: // statement: procedure_call
=======
#line 1909 "parser.tab.cc"
    break;

  case 36:
>>>>>>> semchecks
#line 364 "parser.yy"
                {
    yylhs.value.as < statement_astnode* > () = yystack_[0].value.as < funcall_astnode* > ();
}
<<<<<<< HEAD
#line 1799 "parser.tab.cc"
    break;

  case 37: // statement: RETURN expression ';'
=======
#line 1917 "parser.tab.cc"
    break;

  case 37:
>>>>>>> semchecks
#line 367 "parser.yy"
                       {
    if(Symbols::symTabConstructed){
        yylhs.value.as < statement_astnode* > () = new return_astnode(yystack_[1].value.as < exp_astnode* > ());
    }
}
<<<<<<< HEAD
#line 1809 "parser.tab.cc"
    break;

  case 38: // assignment_expression: unary_expression '=' expression
#line 374 "parser.yy"
=======
#line 1925 "parser.tab.cc"
    break;

  case 38:
#line 372 "parser.yy"
>>>>>>> semchecks
                                                      {
    if(Symbols::symTabConstructed){
        // std::cerr<<__LINE__<<std::endl;
        std::cerr<<yystack_[2].value.as < exp_astnode* > ()->typeNode.typeName<<" = "<<yystack_[0].value.as < exp_astnode* > ()->typeNode.typeName<<std::endl;
        if(yystack_[2].value.as < exp_astnode* > ()->typeNode.compatibleWith(yystack_[0].value.as < exp_astnode* > ()->typeNode)){
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
            }
            else {yylhs.value.as < assignE_astnode* > () = new assignE_astnode(yystack_[2].value.as < exp_astnode* > (), yystack_[0].value.as < exp_astnode* > ());}
        }
        else{
            error(yylhs.location,"Incompatible types: tried to assign "+yystack_[0].value.as < exp_astnode* > ()->typeNode.typeName+" to "+yystack_[2].value.as < exp_astnode* > ()->typeNode.typeName);
        }
    }
}
<<<<<<< HEAD
#line 1843 "parser.tab.cc"
    break;

  case 39: // assignment_statement: assignment_expression ';'
#line 405 "parser.yy"
=======
#line 1933 "parser.tab.cc"
    break;

  case 39:
#line 377 "parser.yy"
>>>>>>> semchecks
                                               {
    if(Symbols::symTabConstructed){
        yylhs.value.as < statement_astnode* > () = new assignS_astnode(yystack_[1].value.as < assignE_astnode* > ()->exp1, yystack_[1].value.as < assignE_astnode* > ()->exp2);
    }
}
<<<<<<< HEAD
#line 1853 "parser.tab.cc"
    break;

  case 40: // procedure_call: IDENTIFIER '(' ')' ';'
#line 412 "parser.yy"
                                      {
}
#line 1860 "parser.tab.cc"
    break;

  case 41: // procedure_call: IDENTIFIER '(' expression_list ')' ';'
#line 414 "parser.yy"
                                        {
}
#line 1867 "parser.tab.cc"
    break;

  case 42: // expression: logical_and_expression
#line 418 "parser.yy"
=======
#line 1941 "parser.tab.cc"
    break;

  case 40:
#line 382 "parser.yy"
                                      {
    if (Symbols::symTabConstructed) {
        std::string function_name = yystack_[3].value.as < std::string > ();
        SymTab* fstab = Symbols::flsts[function_name];
        if (fstab == nullptr) {
            error(yylhs.location, "Procedure \"" + yystack_[3].value.as < std::string > () + "\" not declared");
        }
        std::set<std::pair<long long, std::string>> expected;
        for (auto row: fstab->rows) {
            if (row.second.lpgtype == SymTab::PARAM) {
                expected.insert(std::make_pair(row.second.offset, row.second.type.typeName));
            }
        }
        if (!expected.empty()) {
            error(yylhs.location, "Procedure \"" + yystack_[3].value.as < std::string > () + "\" called with too few arguments");
        }
        yylhs.value.as < funcall_astnode* > () = new funcall_astnode(new identifier_astnode(yystack_[3].value.as < std::string > ()), std::vector<exp_astnode*>());
    }
}
#line 1965 "parser.tab.cc"
    break;

  case 41:
#line 401 "parser.yy"
                                        {
    if (Symbols::symTabConstructed) {
        std::string function_name = yystack_[4].value.as < std::string > ();
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
            if (item.second.compatibleWith(exp_list[i]->typeNode)) {
                error(yylhs.location, "Expected \"" + item.second.typeName + "\" but argument is of type \"" + exp_list[i]->typeNode.typeName + "\"");
            }
            i++;
        }

        yylhs.value.as < funcall_astnode* > () = new funcall_astnode(new identifier_astnode(yystack_[4].value.as < std::string > ()), yystack_[2].value.as < std::vector<exp_astnode*> > ());
    }
}
#line 1999 "parser.tab.cc"
    break;

  case 42:
#line 432 "parser.yy"
>>>>>>> semchecks
                                  {
    yylhs.value.as < exp_astnode* > () = yystack_[0].value.as < op_binary_astnode* > ();
    std::cerr<<__LINE__<<yylhs.value.as < exp_astnode* > ()->typeNode.typeName<<endl;
}
<<<<<<< HEAD
#line 1875 "parser.tab.cc"
    break;

  case 43: // expression: expression OR_OP logical_and_expression
#line 421 "parser.yy"
=======
#line 2008 "parser.tab.cc"
    break;

  case 43:
#line 436 "parser.yy"
>>>>>>> semchecks
                                         {
    if(Symbols::symTabConstructed){
        yylhs.value.as < exp_astnode* > () = new op_binary_astnode("OR_OP",yystack_[2].value.as < exp_astnode* > (),yystack_[0].value.as < op_binary_astnode* > ());
    }
}
<<<<<<< HEAD
#line 1885 "parser.tab.cc"
    break;

  case 44: // logical_and_expression: equality_expression
#line 428 "parser.yy"
=======
#line 2015 "parser.tab.cc"
    break;

  case 44:
#line 440 "parser.yy"
>>>>>>> semchecks
                                           {
    yylhs.value.as < op_binary_astnode* > () = yystack_[0].value.as < op_binary_astnode* > ();
    std::cerr<<__LINE__<<yylhs.value.as < op_binary_astnode* > ()->typeNode.typeName<<endl;
}
<<<<<<< HEAD
#line 1893 "parser.tab.cc"
    break;

  case 45: // logical_and_expression: logical_and_expression AND_OP equality_expression
#line 431 "parser.yy"
                                                   {
    if(Symbols::symTabConstructed){   
        yylhs.value.as < op_binary_astnode* > () = new op_binary_astnode("AND_OP", yystack_[2].value.as < op_binary_astnode* > (), yystack_[0].value.as < op_binary_astnode* > ());
    }
=======
#line 2024 "parser.tab.cc"
    break;

  case 45:
#line 444 "parser.yy"
                                                   {
    yylhs.value.as < op_binary_astnode* > () = new op_binary_astnode("AND?", yystack_[2].value.as < op_binary_astnode* > (), yystack_[0].value.as < op_binary_astnode* > ());
}
#line 2032 "parser.tab.cc"
    break;

  case 46:
#line 449 "parser.yy"
                                          {
    yylhs.value.as < op_binary_astnode* > () = yystack_[0].value.as < op_binary_astnode* > ();
    std::cerr<<__LINE__<<yylhs.value.as < op_binary_astnode* > ()->typeNode.typeName<<endl;
}
#line 2041 "parser.tab.cc"
    break;

  case 47:
#line 453 "parser.yy"
                                                  {
    yylhs.value.as < op_binary_astnode* > () = new op_binary_astnode("EQ?", yystack_[2].value.as < op_binary_astnode* > (), yystack_[0].value.as < op_binary_astnode* > ());
}
#line 2049 "parser.tab.cc"
    break;

  case 48:
#line 456 "parser.yy"
                                                 {
    yylhs.value.as < op_binary_astnode* > () = new op_binary_astnode("NE?", yystack_[2].value.as < op_binary_astnode* > (), yystack_[0].value.as < op_binary_astnode* > ());
}
#line 2057 "parser.tab.cc"
    break;

  case 49:
#line 461 "parser.yy"
                                          {
    yylhs.value.as < op_binary_astnode* > () = yystack_[0].value.as < op_binary_astnode* > ();
    std::cerr<<__LINE__<<yylhs.value.as < op_binary_astnode* > ()->typeNode.typeName<<endl;
}
#line 2066 "parser.tab.cc"
    break;

  case 50:
#line 465 "parser.yy"
                                               {
    yylhs.value.as < op_binary_astnode* > () = new op_binary_astnode("LT?", yystack_[2].value.as < op_binary_astnode* > (), yystack_[0].value.as < op_binary_astnode* > ());
>>>>>>> semchecks
}
#line 2074 "parser.tab.cc"
    break;

<<<<<<< HEAD
  case 46: // equality_expression: relational_expression
#line 438 "parser.yy"
                                          {
    yylhs.value.as < op_binary_astnode* > () = yystack_[0].value.as < op_binary_astnode* > ();
=======
  case 51:
#line 468 "parser.yy"
                                               {
    yylhs.value.as < op_binary_astnode* > () = new op_binary_astnode("GT?", yystack_[2].value.as < op_binary_astnode* > (), yystack_[0].value.as < op_binary_astnode* > ());
>>>>>>> semchecks
}
#line 2082 "parser.tab.cc"
    break;

<<<<<<< HEAD
  case 47: // equality_expression: equality_expression EQ_OP relational_expression
#line 441 "parser.yy"
                                                  {
    if(Symbols::symTabConstructed){   
        yylhs.value.as < op_binary_astnode* > () = new op_binary_astnode("EQ?", yystack_[2].value.as < op_binary_astnode* > (), yystack_[0].value.as < op_binary_astnode* > ());
    }
}
#line 1921 "parser.tab.cc"
    break;

  case 48: // equality_expression: equality_expression NE_OP relational_expression
#line 446 "parser.yy"
                                                 {
    if(Symbols::symTabConstructed){   
        yylhs.value.as < op_binary_astnode* > () = new op_binary_astnode("NE?", yystack_[2].value.as < op_binary_astnode* > (), yystack_[0].value.as < op_binary_astnode* > ());
    }
}
#line 1931 "parser.tab.cc"
    break;

  case 49: // relational_expression: additive_expression
#line 453 "parser.yy"
                                          {
    yylhs.value.as < op_binary_astnode* > () = yystack_[0].value.as < op_binary_astnode* > ();
}
#line 1939 "parser.tab.cc"
    break;

  case 50: // relational_expression: relational_expression '<' additive_expression
#line 456 "parser.yy"
                                               {
    if(Symbols::symTabConstructed){
        yylhs.value.as < op_binary_astnode* > () = new op_binary_astnode("LT_OP?", yystack_[2].value.as < op_binary_astnode* > (), yystack_[0].value.as < op_binary_astnode* > ());
        yylhs.value.as < op_binary_astnode* > ()->op = yylhs.value.as < op_binary_astnode* > ()->op.substr(0,yylhs.value.as < op_binary_astnode* > ()->op.size()-1);
        if(yylhs.value.as < op_binary_astnode* > ()->typeNode.baseTypeName=="float"){
            yylhs.value.as < op_binary_astnode* > ()->op += "_FLOAT";
        }
        else{
            yylhs.value.as < op_binary_astnode* > ()->op += "_INT";
        }
    }
}
#line 1956 "parser.tab.cc"
    break;

  case 51: // relational_expression: relational_expression '>' additive_expression
#line 468 "parser.yy"
                                               {
    if(Symbols::symTabConstructed){
        yylhs.value.as < op_binary_astnode* > () = new op_binary_astnode("GT_OP?", yystack_[2].value.as < op_binary_astnode* > (), yystack_[0].value.as < op_binary_astnode* > ());
        yylhs.value.as < op_binary_astnode* > ()->op = yylhs.value.as < op_binary_astnode* > ()->op.substr(0,yylhs.value.as < op_binary_astnode* > ()->op.size()-1);
        if(yylhs.value.as < op_binary_astnode* > ()->typeNode.baseTypeName=="float"){
            yylhs.value.as < op_binary_astnode* > ()->op += "_FLOAT";
        }
        else{
            yylhs.value.as < op_binary_astnode* > ()->op += "_INT";
        }
    }
}
#line 1973 "parser.tab.cc"
    break;

  case 52: // relational_expression: relational_expression LE_OP additive_expression
#line 480 "parser.yy"
                                                 {
    if(Symbols::symTabConstructed){
        yylhs.value.as < op_binary_astnode* > () = new op_binary_astnode("LE_OP?", yystack_[2].value.as < op_binary_astnode* > (), yystack_[0].value.as < op_binary_astnode* > ());
        yylhs.value.as < op_binary_astnode* > ()->op = yylhs.value.as < op_binary_astnode* > ()->op.substr(0,yylhs.value.as < op_binary_astnode* > ()->op.size()-1);
        if(yylhs.value.as < op_binary_astnode* > ()->typeNode.baseTypeName=="float"){
            yylhs.value.as < op_binary_astnode* > ()->op += "_FLOAT";
        }
        else{
            yylhs.value.as < op_binary_astnode* > ()->op += "_INT";
        }
    }
}
#line 1990 "parser.tab.cc"
    break;

  case 53: // relational_expression: relational_expression GE_OP additive_expression
#line 492 "parser.yy"
=======
  case 52:
#line 471 "parser.yy"
                                                 {
    yylhs.value.as < op_binary_astnode* > () = new op_binary_astnode("LE?", yystack_[2].value.as < op_binary_astnode* > (), yystack_[0].value.as < op_binary_astnode* > ());
}
#line 2090 "parser.tab.cc"
    break;

  case 53:
#line 474 "parser.yy"
>>>>>>> semchecks
                                                 {
    if(Symbols::symTabConstructed){
        yylhs.value.as < op_binary_astnode* > () = new op_binary_astnode("GE_OP?", yystack_[2].value.as < op_binary_astnode* > (), yystack_[0].value.as < op_binary_astnode* > ());
        yylhs.value.as < op_binary_astnode* > ()->op = yylhs.value.as < op_binary_astnode* > ()->op.substr(0,yylhs.value.as < op_binary_astnode* > ()->op.size()-1);
        if(yylhs.value.as < op_binary_astnode* > ()->typeNode.baseTypeName=="float"){
            yylhs.value.as < op_binary_astnode* > ()->op += "_FLOAT";
        }
        else{
            yylhs.value.as < op_binary_astnode* > ()->op += "_INT";
        }
    }
}
<<<<<<< HEAD
#line 2007 "parser.tab.cc"
    break;

  case 54: // additive_expression: multiplicative_expression
#line 506 "parser.yy"
=======
#line 2098 "parser.tab.cc"
    break;

  case 54:
#line 479 "parser.yy"
>>>>>>> semchecks
                                              {
    yylhs.value.as < op_binary_astnode* > () = yystack_[0].value.as < op_binary_astnode* > ();
    std::cerr<<__LINE__<<yylhs.value.as < op_binary_astnode* > ()->typeNode.typeName<<endl;
}
<<<<<<< HEAD
#line 2015 "parser.tab.cc"
    break;

  case 55: // additive_expression: additive_expression '+' multiplicative_expression
#line 509 "parser.yy"
=======
#line 2107 "parser.tab.cc"
    break;

  case 55:
#line 483 "parser.yy"
>>>>>>> semchecks
                                                   {
    if(Symbols::symTabConstructed){
        yylhs.value.as < op_binary_astnode* > () = new op_binary_astnode("PLUS?", yystack_[2].value.as < op_binary_astnode* > (), yystack_[0].value.as < op_binary_astnode* > ());
        yylhs.value.as < op_binary_astnode* > ()->op = yylhs.value.as < op_binary_astnode* > ()->op.substr(0,yylhs.value.as < op_binary_astnode* > ()->op.size()-1);
        if(yylhs.value.as < op_binary_astnode* > ()->typeNode.baseTypeName=="float"){
            yylhs.value.as < op_binary_astnode* > ()->op += "_FLOAT";
        }
        else{
            yylhs.value.as < op_binary_astnode* > ()->op += "_INT";
        }
    }
}
<<<<<<< HEAD
#line 2032 "parser.tab.cc"
    break;

  case 56: // additive_expression: additive_expression '-' multiplicative_expression
#line 521 "parser.yy"
=======
#line 2124 "parser.tab.cc"
    break;

  case 56:
#line 495 "parser.yy"
>>>>>>> semchecks
                                                   {
    if(Symbols::symTabConstructed){
        yylhs.value.as < op_binary_astnode* > () = new op_binary_astnode("MINUS?", yystack_[2].value.as < op_binary_astnode* > (), yystack_[0].value.as < op_binary_astnode* > ());
        yylhs.value.as < op_binary_astnode* > ()->op = yylhs.value.as < op_binary_astnode* > ()->op.substr(0,yylhs.value.as < op_binary_astnode* > ()->op.size()-1);
        if(yylhs.value.as < op_binary_astnode* > ()->typeNode.baseTypeName=="float"){
            yylhs.value.as < op_binary_astnode* > ()->op += "_FLOAT";
        }
        else{
            yylhs.value.as < op_binary_astnode* > ()->op += "_INT";
        }
    }
}
<<<<<<< HEAD
#line 2049 "parser.tab.cc"
    break;

  case 57: // unary_expression: postfix_expression
#line 535 "parser.yy"
=======
#line 2141 "parser.tab.cc"
    break;

  case 57:
#line 509 "parser.yy"
>>>>>>> semchecks
                                    {
    yylhs.value.as < exp_astnode* > () = yystack_[0].value.as < exp_astnode* > ();
    std::cerr<<__LINE__<<yylhs.value.as < exp_astnode* > ()->typeNode.typeName<<endl;
}
<<<<<<< HEAD
#line 2057 "parser.tab.cc"
    break;

  case 58: // unary_expression: unary_operator unary_expression
#line 538 "parser.yy"
=======
#line 2150 "parser.tab.cc"
    break;

  case 58:
#line 513 "parser.yy"
>>>>>>> semchecks
                                 {
    if(Symbols::symTabConstructed){
        //validity checks.
        if(yystack_[1].value.as < std::string > ()=="ADDRESS"&&(!yystack_[0].value.as < exp_astnode* > ()->typeNode.islval)){
            error(yylhs.location,"Tried to get address of rval: "+yystack_[0].value.as < exp_astnode* > ()->typeNode.typeName);
        }
        yylhs.value.as < exp_astnode* > () = new op_unary_astnode(yystack_[1].value.as < std::string > (), yystack_[0].value.as < exp_astnode* > ());
        if(yylhs.value.as < exp_astnode* > ()->typeNode.typeName==yystack_[0].value.as < exp_astnode* > ()->typeNode.typeName){
            error(yylhs.location,"Tried to dereference " + yystack_[0].value.as < exp_astnode* > ()->typeNode.typeName);
        }
    }
}
<<<<<<< HEAD
#line 2074 "parser.tab.cc"
    break;

  case 59: // multiplicative_expression: unary_expression
#line 552 "parser.yy"
                                           {
    if(Symbols::symTabConstructed){   
        yylhs.value.as < op_binary_astnode* > () = (op_binary_astnode*) yystack_[0].value.as < exp_astnode* > ();
    }

}
#line 2085 "parser.tab.cc"
    break;

  case 60: // multiplicative_expression: multiplicative_expression '*' unary_expression
#line 558 "parser.yy"
=======
#line 2158 "parser.tab.cc"
    break;

  case 59:
#line 518 "parser.yy"
                                           {
    yylhs.value.as < op_binary_astnode* > () = (op_binary_astnode*) yystack_[0].value.as < exp_astnode* > ();
    std::cerr<<__LINE__<<yylhs.value.as < op_binary_astnode* > ()->typeNode.typeName<<endl;

}
#line 2168 "parser.tab.cc"
    break;

  case 60:
#line 523 "parser.yy"
>>>>>>> semchecks
                                                {
    //operator and expression match check here.
    if(Symbols::symTabConstructed){
        yylhs.value.as < op_binary_astnode* > () = new op_binary_astnode("MULT?", yystack_[2].value.as < op_binary_astnode* > (), yystack_[0].value.as < exp_astnode* > ());
        yylhs.value.as < op_binary_astnode* > ()->op = yylhs.value.as < op_binary_astnode* > ()->op.substr(0,yylhs.value.as < op_binary_astnode* > ()->op.size()-1);
        if(yylhs.value.as < op_binary_astnode* > ()->typeNode.baseTypeName=="float"){
            yylhs.value.as < op_binary_astnode* > ()->op += "_FLOAT";
        }
        else{
            yylhs.value.as < op_binary_astnode* > ()->op += "_INT";
        }
    }
}
<<<<<<< HEAD
#line 2103 "parser.tab.cc"
    break;

  case 61: // multiplicative_expression: multiplicative_expression '/' unary_expression
#line 571 "parser.yy"
=======
#line 2186 "parser.tab.cc"
    break;

  case 61:
#line 536 "parser.yy"
>>>>>>> semchecks
                                                {
    if(Symbols::symTabConstructed){
        yylhs.value.as < op_binary_astnode* > () = new op_binary_astnode("DIV?", yystack_[2].value.as < op_binary_astnode* > (), yystack_[0].value.as < exp_astnode* > ());
        yylhs.value.as < op_binary_astnode* > ()->op = yylhs.value.as < op_binary_astnode* > ()->op.substr(0,yylhs.value.as < op_binary_astnode* > ()->op.size()-1);
        if(yylhs.value.as < op_binary_astnode* > ()->typeNode.baseTypeName=="float"){
            yylhs.value.as < op_binary_astnode* > ()->op += "_FLOAT";
        }
        else{
            yylhs.value.as < op_binary_astnode* > ()->op += "_INT";
        }
    }
}
<<<<<<< HEAD
#line 2120 "parser.tab.cc"
    break;

  case 62: // postfix_expression: primary_expression
#line 585 "parser.yy"
=======
#line 2203 "parser.tab.cc"
    break;

  case 62:
#line 550 "parser.yy"
>>>>>>> semchecks
                                      {
    yylhs.value.as < exp_astnode* > () = yystack_[0].value.as < exp_astnode* > ();
    std::cerr<<__LINE__<<yylhs.value.as < exp_astnode* > ()->typeNode.typeName<<endl;
}
<<<<<<< HEAD
#line 2128 "parser.tab.cc"
    break;

  case 63: // postfix_expression: postfix_expression '[' expression ']'
#line 588 "parser.yy"
=======
#line 2212 "parser.tab.cc"
    break;

  case 63:
#line 554 "parser.yy"
>>>>>>> semchecks
                                       {
    if(Symbols::symTabConstructed){   
        yylhs.value.as < exp_astnode* > () = new arrayref_astnode(yystack_[3].value.as < exp_astnode* > (), yystack_[1].value.as < exp_astnode* > ());
    }
}
<<<<<<< HEAD
#line 2138 "parser.tab.cc"
    break;

  case 64: // postfix_expression: IDENTIFIER '(' ')'
#line 593 "parser.yy"
                    {
    // TODO
}
#line 2146 "parser.tab.cc"
    break;

  case 65: // postfix_expression: IDENTIFIER '(' expression_list ')'
#line 596 "parser.yy"
=======
#line 2220 "parser.tab.cc"
    break;

  case 64:
#line 557 "parser.yy"
                    {
    // TODO
}
#line 2228 "parser.tab.cc"
    break;

  case 65:
#line 560 "parser.yy"
>>>>>>> semchecks
                                    {
    //TODO funcall
    yylhs.value.as < exp_astnode* > () = new funcall_astnode(new identifier_astnode(yystack_[3].value.as < std::string > ()), yystack_[1].value.as < std::vector<exp_astnode*> > ());
}
<<<<<<< HEAD
#line 2154 "parser.tab.cc"
    break;

  case 66: // postfix_expression: postfix_expression '.' IDENTIFIER
#line 599 "parser.yy"
=======
#line 2237 "parser.tab.cc"
    break;

  case 66:
#line 564 "parser.yy"
>>>>>>> semchecks
                                   {
    if(Symbols::symTabConstructed){
        yylhs.value.as < exp_astnode* > () = new member_astnode(yystack_[2].value.as < exp_astnode* > (), new identifier_astnode(yystack_[0].value.as < std::string > ()));
        std::cerr<<"using this rule"<<std::endl;
        std::string structName = yystack_[2].value.as < exp_astnode* > ()->typeNode.typeName;
        // std::cerr<<"symtab constr, structname: "<<structName<<std::endl;
        SymEntry* memberEntry = Symbols::getSymEntry(Symbols::slsts[structName],yystack_[0].value.as < std::string > (),true);
        if(memberEntry){
            yylhs.value.as < exp_astnode* > ()->typeNode = memberEntry->type;
            // std::cerr<<"Member "<<$3<<" found in "<<structName<<std::endl;
        }
        else{
            // std::cerr<<"Member "<<$3<<" not found in "<<structName<<std::endl;
            string errormsg = "Member "+yystack_[0].value.as < std::string > ()+" not found in "+structName;
            error(yylhs.location,errormsg);
        }
    }
}
<<<<<<< HEAD
#line 2177 "parser.tab.cc"
    break;

  case 67: // postfix_expression: postfix_expression PTR_OP IDENTIFIER
#line 617 "parser.yy"
=======
#line 2259 "parser.tab.cc"
    break;

  case 67:
#line 581 "parser.yy"
>>>>>>> semchecks
                                      {
    if(Symbols::symTabConstructed){
        yylhs.value.as < exp_astnode* > () = new member_astnode(new arrow_astnode(yystack_[2].value.as < exp_astnode* > (), new identifier_astnode(yystack_[0].value.as < std::string > ())), new identifier_astnode(yystack_[0].value.as < std::string > ()));
        typespec_astnode dereftype = yystack_[2].value.as < exp_astnode* > ()->typeNode;
        dereftype.deref();
        std::string structName  = dereftype.typeName;
        //TODO restrict global table search here.
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
<<<<<<< HEAD
#line 2199 "parser.tab.cc"
    break;

  case 68: // postfix_expression: postfix_expression INC_OP
#line 634 "parser.yy"
                           {
    
}
#line 2207 "parser.tab.cc"
    break;

  case 69: // primary_expression: IDENTIFIER
#line 639 "parser.yy"
=======
#line 2280 "parser.tab.cc"
    break;

  case 68:
#line 597 "parser.yy"
                           {
    
}
#line 2288 "parser.tab.cc"
    break;

  case 69:
#line 602 "parser.yy"
>>>>>>> semchecks
                              {
    if(Symbols::symTabConstructed){
        yylhs.value.as < exp_astnode* > () = new identifier_astnode(yystack_[0].value.as < std::string > ());
        SymEntry * entry = Symbols::getSymEntry(ststack.top(),yystack_[0].value.as < std::string > ());
        if(!entry){
            std::string errormsg = "Symbol "+yystack_[0].value.as < std::string > ()+" not found.";
            error(yylhs.location,errormsg);
        }
        else{
            yylhs.value.as < exp_astnode* > ()->typeNode = entry->type;
            std::cerr << __LINE__ << yylhs.value.as < exp_astnode* > ()->typeNode.typeName<<std::endl;
        }
 
    }
    std::cerr<<"bloom"<<std::endl;
}
<<<<<<< HEAD
#line 2225 "parser.tab.cc"
    break;

  case 70: // primary_expression: INT_CONSTANT
#line 652 "parser.yy"
=======
#line 2308 "parser.tab.cc"
    break;

  case 70:
#line 617 "parser.yy"
>>>>>>> semchecks
              {
    if(Symbols::symTabConstructed){   
        yylhs.value.as < exp_astnode* > () = new intconst_astnode(yystack_[0].value.as < std::string > ());
        yylhs.value.as < exp_astnode* > ()->typeNode = intc;
        yylhs.value.as < exp_astnode* > ()->typeNode.islval = false;
    }
}
<<<<<<< HEAD
#line 2237 "parser.tab.cc"
    break;

  case 71: // primary_expression: FLOAT_CONSTANT
#line 659 "parser.yy"
=======
#line 2317 "parser.tab.cc"
    break;

  case 71:
#line 621 "parser.yy"
>>>>>>> semchecks
                {
    if(Symbols::symTabConstructed){   
        yylhs.value.as < exp_astnode* > () = new floatconst_astnode(yystack_[0].value.as < std::string > ());
        yylhs.value.as < exp_astnode* > ()->typeNode = floatc;
        yylhs.value.as < exp_astnode* > ()->typeNode.islval = false;
    }
}
<<<<<<< HEAD
#line 2249 "parser.tab.cc"
    break;

  case 72: // primary_expression: STRING_LITERAL
#line 666 "parser.yy"
=======
#line 2326 "parser.tab.cc"
    break;

  case 72:
#line 625 "parser.yy"
>>>>>>> semchecks
                {
    if(Symbols::symTabConstructed){   
        yylhs.value.as < exp_astnode* > () = new stringconst_astnode(yystack_[0].value.as < std::string > ());
        yylhs.value.as < exp_astnode* > ()->typeNode = stringc;
        yylhs.value.as < exp_astnode* > ()->typeNode.islval = false;
        yylhs.value.as < exp_astnode* > ()->print();
    }
}
<<<<<<< HEAD
#line 2262 "parser.tab.cc"
    break;

  case 73: // primary_expression: '(' expression ')'
#line 674 "parser.yy"
=======
#line 2336 "parser.tab.cc"
    break;

  case 73:
#line 630 "parser.yy"
>>>>>>> semchecks
                    {
    yylhs.value.as < exp_astnode* > () = yystack_[1].value.as < exp_astnode* > ();
}
<<<<<<< HEAD
#line 2270 "parser.tab.cc"
    break;

  case 74: // expression_list: expression
#line 679 "parser.yy"
=======
#line 2345 "parser.tab.cc"
    break;

  case 74:
#line 636 "parser.yy"
>>>>>>> semchecks
                           {
    yylhs.value.as < std::vector<exp_astnode*> > () = std::vector<exp_astnode*>();
    yylhs.value.as < std::vector<exp_astnode*> > ().push_back(yystack_[0].value.as < exp_astnode* > ());
    std::cerr << __LINE__ << (*(yylhs.value.as < std::vector<exp_astnode*> > ().rbegin()))->typeNode.typeName<<std::endl;
}
<<<<<<< HEAD
#line 2277 "parser.tab.cc"
    break;

  case 75: // expression_list: expression_list ',' expression
#line 681 "parser.yy"
=======
#line 2355 "parser.tab.cc"
    break;

  case 75:
#line 641 "parser.yy"
>>>>>>> semchecks
                                {
    yystack_[2].value.as < std::vector<exp_astnode*> > ().push_back(yystack_[0].value.as < exp_astnode* > ());
    yylhs.value.as < std::vector<exp_astnode*> > () = yystack_[2].value.as < std::vector<exp_astnode*> > ();
}
<<<<<<< HEAD
#line 2284 "parser.tab.cc"
    break;

  case 76: // unary_operator: '-'
#line 685 "parser.yy"
                   {
    yylhs.value.as < std::string > () = std::string("UMINUS?");
}
#line 2292 "parser.tab.cc"
    break;

  case 77: // unary_operator: '!'
#line 688 "parser.yy"
     {
    yylhs.value.as < std::string > () = std::string("NOT");
}
#line 2300 "parser.tab.cc"
    break;

  case 78: // unary_operator: '&'
#line 691 "parser.yy"
     {
    yylhs.value.as < std::string > () = std::string("ADDRESS");
}
#line 2308 "parser.tab.cc"
    break;

  case 79: // unary_operator: '*'
#line 694 "parser.yy"
     {
    yylhs.value.as < std::string > () = std::string("DEREF");
}
#line 2316 "parser.tab.cc"
    break;

  case 80: // selection_statement: IF '(' expression ')' statement ELSE statement
#line 699 "parser.yy"
=======
#line 2364 "parser.tab.cc"
    break;

  case 76:
#line 647 "parser.yy"
                   {
    yylhs.value.as < std::string > () = std::string("UMINUS?");
}
#line 2372 "parser.tab.cc"
    break;

  case 77:
#line 650 "parser.yy"
     {
    yylhs.value.as < std::string > () = std::string("NOT");
}
#line 2380 "parser.tab.cc"
    break;

  case 78:
#line 653 "parser.yy"
     {
    yylhs.value.as < std::string > () = std::string("ADDRESS");
}
#line 2388 "parser.tab.cc"
    break;

  case 79:
#line 656 "parser.yy"
     {
    yylhs.value.as < std::string > () = std::string("DEREF");
}
#line 2396 "parser.tab.cc"
    break;

  case 80:
#line 661 "parser.yy"
>>>>>>> semchecks
                                                                   {
    if(Symbols::symTabConstructed){   
        yylhs.value.as < statement_astnode* > () = new if_astnode(yystack_[4].value.as < exp_astnode* > (), yystack_[2].value.as < statement_astnode* > (), yystack_[0].value.as < statement_astnode* > ());
    }
}
<<<<<<< HEAD
#line 2326 "parser.tab.cc"
    break;

  case 81: // iteration_statement: WHILE '(' expression ')' statement
#line 706 "parser.yy"
=======
#line 2404 "parser.tab.cc"
    break;

  case 81:
#line 666 "parser.yy"
>>>>>>> semchecks
                                                       {
    if(Symbols::symTabConstructed){   
        yylhs.value.as < statement_astnode* > () = new while_astnode(yystack_[2].value.as < exp_astnode* > (), yystack_[0].value.as < statement_astnode* > ());
    }
}
<<<<<<< HEAD
#line 2336 "parser.tab.cc"
    break;

  case 82: // iteration_statement: FOR '(' assignment_expression ';' expression ';' assignment_expression ')' statement
#line 711 "parser.yy"
=======
#line 2412 "parser.tab.cc"
    break;

  case 82:
#line 669 "parser.yy"
>>>>>>> semchecks
                                                                                      {
    if(Symbols::symTabConstructed){   
        yylhs.value.as < statement_astnode* > () = new for_astnode(yystack_[6].value.as < assignE_astnode* > (), yystack_[4].value.as < exp_astnode* > (), yystack_[2].value.as < assignE_astnode* > (), yystack_[0].value.as < statement_astnode* > ());
    }
}
<<<<<<< HEAD
#line 2346 "parser.tab.cc"
    break;

  case 83: // declaration_list: declaration
#line 718 "parser.yy"
                             {
}
#line 2353 "parser.tab.cc"
    break;

  case 84: // declaration_list: declaration_list declaration
#line 720 "parser.yy"
                              {
}
#line 2360 "parser.tab.cc"
    break;

  case 85: // declaration: type_specifier declarator_list ';'
#line 724 "parser.yy"
                                               {
}
#line 2367 "parser.tab.cc"
    break;

  case 86: // declarator_list: declarator
#line 728 "parser.yy"
=======
#line 2420 "parser.tab.cc"
    break;

  case 83:
#line 674 "parser.yy"
                             {
}
#line 2427 "parser.tab.cc"
    break;

  case 84:
#line 676 "parser.yy"
                              {
}
#line 2434 "parser.tab.cc"
    break;

  case 85:
#line 680 "parser.yy"
                                               {
}
#line 2441 "parser.tab.cc"
    break;

  case 86:
#line 684 "parser.yy"
>>>>>>> semchecks
                           {
    yylhs.value.as < typespec_astnode > () = yystack_[0].value.as < typespec_astnode > ();
    // std::cerr<<$1.typeName<<" has "<<$1.numptrstars<<" stars"<<std::endl;
    string type = yystack_[0].value.as < typespec_astnode > ().typeName;
    int size = yystack_[0].value.as < typespec_astnode > ().typeWidth;
    if(!Symbols::symTabConstructed){
        // std::cerr<<topvarname<<": "<<size<<" "<<std::endl;
        int offset = ststack.top()->getNewOffset(size);
        SymTab* st = ststack.top();
        st->rows[topvarname] = SymEntry(yystack_[0].value.as < typespec_astnode > (),SymTab::ST_HL_type::VAR,SymTab::ST_LPG::LOCAL,size,offset);
    }
}
<<<<<<< HEAD
#line 2384 "parser.tab.cc"
    break;

  case 87: // declarator_list: declarator_list ',' declarator
#line 740 "parser.yy"
=======
#line 2457 "parser.tab.cc"
    break;

  case 87:
#line 695 "parser.yy"
>>>>>>> semchecks
                                {
    yylhs.value.as < typespec_astnode > () = yystack_[0].value.as < typespec_astnode > ();
    string type = yystack_[0].value.as < typespec_astnode > ().typeName;
    int size = yystack_[0].value.as < typespec_astnode > ().typeWidth;
    if(!Symbols::symTabConstructed){
        int offset = ststack.top()->getNewOffset(size);
        ststack.top()->rows[topvarname] = SymEntry(yystack_[0].value.as < typespec_astnode > (),SymTab::ST_HL_type::VAR,SymTab::ST_LPG::LOCAL,size,offset);
    }
}
<<<<<<< HEAD
#line 2398 "parser.tab.cc"
    break;


#line 2402 "parser.tab.cc"
=======
#line 2471 "parser.tab.cc"
    break;


#line 2475 "parser.tab.cc"
>>>>>>> semchecks

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
     -62,    20,    75,   -62,   -62,   -62,   -62,     0,    75,   -62,
     -62,    35,    46,   -62,   -62,    29,    43,    64,    33,   115,
     -62,   123,   -62,   123,    86,    52,   -62,   -62,   -62,    73,
      81,    87,   299,   -62,   -62,   299,   294,   -62,   -62,   -62,
     -62,   154,   106,    17,   -62,   -62,   103,   -62,   -62,   -62,
     -62,   189,   299,     1,   -62,     9,     1,   118,   120,   -62,
      31,   299,   299,   299,   124,     7,   -62,   143,    58,    50,
      49,    -4,    -2,   224,   -62,   259,   -62,   299,   -62,   158,
     299,   159,   -62,   -62,   -62,   -62,   -62,     1,   -22,   -62,
     132,   127,   -62,   123,   -62,   128,   160,    60,     5,    36,
     129,    78,   299,   -62,   299,   299,   299,   299,   299,   299,
     299,   299,   299,   299,   299,   -62,   -62,   -62,   160,   -62,
      34,   -62,   -62,     1,   -62,   164,   -62,   -62,   -62,   133,
     299,   294,   294,   299,   -62,    69,   143,    58,    50,    50,
      49,    49,    49,    49,    -4,    -4,   -62,   -62,   -62,   -62,
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
      31,     0,     0,    57,    62,    36,     0,    29,    33,    34,
      35,     0,     0,     0,    83,     0,     0,    18,     0,    14,
       0,     0,     0,     0,    69,     0,    59,    42,    44,    46,
      49,    54,     0,     0,    27,     0,    84,     0,    68,     0,
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
     -62,   -62,   -62,   175,   165,   -31,   -19,   -62,   -62,    83,
      85,    41,    23,    -5,   -62,   -61,   182,   -48,   -62,   -62,
     -62,   -62,    14,    92,   -62,     3,    22,   -62,   -50,   -62,
     -62,   101,   -62,   -62,   -62,   -62
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,     8,     1,     9,    41,    96,    66,    43,    44,    67,
      68,    69,    70,    71,    45,    46,    10,    47,    48,    49,
      50,    20,    51,    97,    52,    53,    54,    88,    89,    90,
      57,    58,    16,     2,    17,    23
  };

  const short
  Parser::yytable_[] =
  {
      42,    65,   100,    84,    72,    11,    92,    12,    86,   102,
     123,    11,     4,     5,     6,    24,   102,    42,   102,   124,
       3,   102,    42,   113,   114,    84,    56,    84,    87,   115,
      98,    99,    42,    85,    78,    79,   131,   122,    64,    26,
      27,    28,    15,    91,    42,   102,   118,   102,   103,   120,
      73,   159,    80,   -14,    42,    75,    42,    33,    34,    18,
      81,    35,    95,    76,    22,   107,   108,   132,    38,    39,
     148,   105,   106,   149,   111,   112,    19,    76,     4,     5,
       6,     7,    60,   153,   154,    64,    26,    27,    28,   109,
     110,   129,   130,    59,   146,   147,    56,    21,   161,   152,
     156,   130,   155,    61,    33,    34,   144,   145,    35,   134,
     160,    62,    42,    42,   163,    38,    39,    63,     4,     5,
       6,    24,    25,    26,    27,    28,     4,     5,     6,    24,
     140,   141,   142,   143,    29,    77,    30,    31,    32,    42,
      42,    33,    34,    42,    82,    35,   138,   139,    36,    37,
      93,    94,    38,    39,   101,   104,    40,     4,     5,     6,
      24,    25,    26,    27,    28,   119,   121,   125,   126,   128,
     133,   102,   150,    29,   151,    30,    31,    32,   157,   162,
      33,    34,   158,    13,    35,   136,    55,    36,    74,   137,
      14,    38,    39,   135,   127,    40,    25,    26,    27,    28,
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
      19,    32,    63,    51,    35,     2,    56,     7,     7,    11,
      32,     8,     3,     4,     5,     6,    11,    36,    11,    41,
       0,    11,    41,    27,    28,    73,    23,    75,    27,    31,
      61,    62,    51,    52,    17,    18,    31,    87,     7,     8,
       9,    10,     7,    34,    63,    11,    77,    11,    41,    80,
      36,    41,    35,     7,    73,    41,    75,    26,    27,    30,
      43,    30,    31,    41,    31,    15,    16,    31,    37,    38,
      36,    13,    14,   123,    25,    26,    33,    55,     3,     4,
       5,     6,    30,   131,   132,     7,     8,     9,    10,    39,
      40,    31,    32,     7,   113,   114,    93,    33,   159,   130,
      31,    32,   133,    30,    26,    27,   111,   112,    30,    31,
     158,    30,   131,   132,   162,    37,    38,    30,     3,     4,
       5,     6,     7,     8,     9,    10,     3,     4,     5,     6,
     107,   108,   109,   110,    19,    29,    21,    22,    23,   158,
     159,    26,    27,   162,    41,    30,   105,   106,    33,    34,
      32,    31,    37,    38,    30,    12,    41,     3,     4,     5,
       6,     7,     8,     9,    10,     7,     7,    35,    41,    41,
      41,    11,     8,    19,    41,    21,    22,    23,    36,    31,
      26,    27,    20,     8,    30,   102,    21,    33,    34,   104,
       8,    37,    38,   101,    93,    41,     7,     8,     9,    10,
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
      60,    69,     7,    47,    60,     7,    76,    78,    30,    33,
      65,    33,    31,    79,     6,     7,     8,     9,    10,    19,
      21,    22,    23,    26,    27,    30,    33,    34,    37,    38,
      41,    48,    50,    51,    52,    58,    59,    61,    62,    63,
      64,    66,    68,    69,    70,    48,    69,    74,    75,     7,
      30,    30,    30,    30,     7,    49,    50,    53,    54,    55,
      56,    57,    49,    66,    34,    66,    70,    29,    17,    18,
      35,    43,    41,    34,    61,    50,     7,    27,    71,    72,
      73,    34,    72,    32,    31,    31,    49,    67,    49,    49,
      59,    30,    11,    41,    12,    13,    14,    15,    16,    39,
      40,    25,    26,    27,    28,    31,    34,    34,    49,     7,
      49,     7,    72,    32,    41,    35,    41,    75,    41,    31,
      32,    31,    31,    41,    31,    67,    53,    54,    55,    55,
      56,    56,    56,    56,    57,    57,    50,    50,    36,    72,
       8,    41,    49,    61,    61,    49,    31,    36,    20,    41,
      61,    59,    31,    61
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    44,    77,    46,    45,    45,    45,    45,    78,    47,
      60,    69,    69,    69,    69,    79,    76,    76,    75,    75,
      74,    73,    73,    72,    72,    65,    65,    65,    65,    66,
      66,    61,    61,    61,    61,    61,    61,    61,    59,    64,
      58,    58,    49,    49,    53,    53,    54,    54,    54,    55,
      55,    55,    55,    55,    56,    56,    56,    50,    50,    57,
      57,    57,    51,    51,    51,    51,    51,    51,    51,    52,
      52,    52,    52,    52,    67,    67,    68,    68,    68,    68,
      62,    63,    63,    48,    48,    70,    71,    71
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
  "translation_unit", "begin_nterm", "struct_specifier",
  "declaration_list", "expression", "unary_expression",
  "postfix_expression", "primary_expression", "logical_and_expression",
  "equality_expression", "relational_expression", "additive_expression",
  "multiplicative_expression", "procedure_call", "assignment_expression",
  "function_definition", "statement", "selection_statement",
  "iteration_statement", "assignment_statement", "compound_statement",
  "statement_list", "expression_list", "unary_operator", "type_specifier",
  "declaration", "declarator_list", "declarator", "declarator_arr",
  "parameter_declaration", "parameter_list", "fun_declarator", "$@1",
  "$@2", "$@3", YY_NULLPTR
  };


  const short
  Parser::yyrline_[] =
  {
<<<<<<< HEAD
       0,   110,   110,   110,   133,   142,   146,   148,   154,   154,
     168,   176,   188,   197,   205,   219,   219,   250,   263,   269,
     277,   286,   293,   303,   306,   315,   318,   321,   326,   331,
     339,   345,   350,   355,   358,   361,   364,   367,   374,   405,
     412,   414,   418,   421,   428,   431,   438,   441,   446,   453,
     456,   468,   480,   492,   506,   509,   521,   535,   538,   552,
     558,   571,   585,   588,   593,   596,   599,   617,   634,   639,
     652,   659,   666,   674,   679,   681,   685,   688,   691,   694,
     699,   706,   711,   718,   720,   724,   728,   740
=======
       0,   114,   114,   114,   138,   147,   151,   153,   159,   159,
     174,   180,   192,   205,   217,   231,   231,   261,   272,   276,
     282,   291,   298,   308,   311,   319,   322,   325,   330,   335,
     343,   349,   352,   355,   358,   361,   364,   367,   372,   377,
     382,   401,   432,   436,   440,   444,   449,   453,   456,   461,
     465,   468,   471,   474,   479,   483,   495,   509,   513,   518,
     523,   536,   550,   554,   557,   560,   564,   581,   597,   602,
     617,   621,   625,   630,   636,   641,   647,   650,   653,   656,
     661,   666,   669,   674,   676,   680,   684,   695
>>>>>>> semchecks
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
<<<<<<< HEAD
#line 2912 "parser.tab.cc"

#line 751 "parser.yy"
=======
#line 2970 "parser.tab.cc"

#line 706 "parser.yy"
>>>>>>> semchecks

//grammar definition.
void 
IPL::Parser::error( const location_type &l, const std::string &err_message )
{
<<<<<<< HEAD
    std::cout << "Error at line " << l.begin.line << ": " << err_message <<"\n";
    exit(1);
=======
   std::cout << "Error at line " << l.begin.line << ": " << err_message << "\n";
   exit(1);

>>>>>>> semchecks
}

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
   #include "scanner.hh"

#undef yylex
#define yylex IPL::Parser::scanner.yylex

#line 56 "parser.tab.cc"


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
#line 148 "parser.tab.cc"


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
      case 45: // begin_nterm
      case 46: // translation_unit
      case 47: // struct_specifier
      case 48: // fun_declarator
      case 49: // parameter_list
      case 50: // parameter_declaration
      case 51: // declarator_arr
      case 52: // declarator
      case 53: // procedure_call
      case 54: // declaration_list
      case 55: // declaration
      case 56: // declarator_list
        value.move< abstract_astnode* > (std::move (that.value));
        break;

      case 67: // assignment_expression
        value.move< assignE_astnode* > (std::move (that.value));
        break;

      case 57: // expression
      case 58: // logical_and_expression
      case 59: // equality_expression
      case 60: // relational_expression
      case 61: // additive_expression
      case 62: // unary_expression
      case 63: // multiplicative_expression
      case 64: // postfix_expression
      case 65: // primary_expression
      case 66: // expression_list
        value.move< exp_astnode* > (std::move (that.value));
        break;

      case 68: // function_definition
      case 69: // statement
      case 70: // selection_statement
      case 71: // iteration_statement
      case 72: // assignment_statement
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
      case 75: // type_specifier
      case 76: // unary_operator
        value.move< std::string > (std::move (that.value));
        break;

      case 73: // compound_statement
      case 74: // statement_list
        value.move< std::vector<statement_astnode*> > (std::move (that.value));
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
      case 45: // begin_nterm
      case 46: // translation_unit
      case 47: // struct_specifier
      case 48: // fun_declarator
      case 49: // parameter_list
      case 50: // parameter_declaration
      case 51: // declarator_arr
      case 52: // declarator
      case 53: // procedure_call
      case 54: // declaration_list
      case 55: // declaration
      case 56: // declarator_list
        value.copy< abstract_astnode* > (YY_MOVE (that.value));
        break;

      case 67: // assignment_expression
        value.copy< assignE_astnode* > (YY_MOVE (that.value));
        break;

      case 57: // expression
      case 58: // logical_and_expression
      case 59: // equality_expression
      case 60: // relational_expression
      case 61: // additive_expression
      case 62: // unary_expression
      case 63: // multiplicative_expression
      case 64: // postfix_expression
      case 65: // primary_expression
      case 66: // expression_list
        value.copy< exp_astnode* > (YY_MOVE (that.value));
        break;

      case 68: // function_definition
      case 69: // statement
      case 70: // selection_statement
      case 71: // iteration_statement
      case 72: // assignment_statement
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
      case 75: // type_specifier
      case 76: // unary_operator
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case 73: // compound_statement
      case 74: // statement_list
        value.copy< std::vector<statement_astnode*> > (YY_MOVE (that.value));
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
      case 45: // begin_nterm
      case 46: // translation_unit
      case 47: // struct_specifier
      case 48: // fun_declarator
      case 49: // parameter_list
      case 50: // parameter_declaration
      case 51: // declarator_arr
      case 52: // declarator
      case 53: // procedure_call
      case 54: // declaration_list
      case 55: // declaration
      case 56: // declarator_list
        value.move< abstract_astnode* > (YY_MOVE (s.value));
        break;

      case 67: // assignment_expression
        value.move< assignE_astnode* > (YY_MOVE (s.value));
        break;

      case 57: // expression
      case 58: // logical_and_expression
      case 59: // equality_expression
      case 60: // relational_expression
      case 61: // additive_expression
      case 62: // unary_expression
      case 63: // multiplicative_expression
      case 64: // postfix_expression
      case 65: // primary_expression
      case 66: // expression_list
        value.move< exp_astnode* > (YY_MOVE (s.value));
        break;

      case 68: // function_definition
      case 69: // statement
      case 70: // selection_statement
      case 71: // iteration_statement
      case 72: // assignment_statement
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
      case 75: // type_specifier
      case 76: // unary_operator
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case 73: // compound_statement
      case 74: // statement_list
        value.move< std::vector<statement_astnode*> > (YY_MOVE (s.value));
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
      case 45: // begin_nterm
      case 46: // translation_unit
      case 47: // struct_specifier
      case 48: // fun_declarator
      case 49: // parameter_list
      case 50: // parameter_declaration
      case 51: // declarator_arr
      case 52: // declarator
      case 53: // procedure_call
      case 54: // declaration_list
      case 55: // declaration
      case 56: // declarator_list
        value.YY_MOVE_OR_COPY< abstract_astnode* > (YY_MOVE (that.value));
        break;

      case 67: // assignment_expression
        value.YY_MOVE_OR_COPY< assignE_astnode* > (YY_MOVE (that.value));
        break;

      case 57: // expression
      case 58: // logical_and_expression
      case 59: // equality_expression
      case 60: // relational_expression
      case 61: // additive_expression
      case 62: // unary_expression
      case 63: // multiplicative_expression
      case 64: // postfix_expression
      case 65: // primary_expression
      case 66: // expression_list
        value.YY_MOVE_OR_COPY< exp_astnode* > (YY_MOVE (that.value));
        break;

      case 68: // function_definition
      case 69: // statement
      case 70: // selection_statement
      case 71: // iteration_statement
      case 72: // assignment_statement
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
      case 75: // type_specifier
      case 76: // unary_operator
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case 73: // compound_statement
      case 74: // statement_list
        value.YY_MOVE_OR_COPY< std::vector<statement_astnode*> > (YY_MOVE (that.value));
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
      case 45: // begin_nterm
      case 46: // translation_unit
      case 47: // struct_specifier
      case 48: // fun_declarator
      case 49: // parameter_list
      case 50: // parameter_declaration
      case 51: // declarator_arr
      case 52: // declarator
      case 53: // procedure_call
      case 54: // declaration_list
      case 55: // declaration
      case 56: // declarator_list
        value.move< abstract_astnode* > (YY_MOVE (that.value));
        break;

      case 67: // assignment_expression
        value.move< assignE_astnode* > (YY_MOVE (that.value));
        break;

      case 57: // expression
      case 58: // logical_and_expression
      case 59: // equality_expression
      case 60: // relational_expression
      case 61: // additive_expression
      case 62: // unary_expression
      case 63: // multiplicative_expression
      case 64: // postfix_expression
      case 65: // primary_expression
      case 66: // expression_list
        value.move< exp_astnode* > (YY_MOVE (that.value));
        break;

      case 68: // function_definition
      case 69: // statement
      case 70: // selection_statement
      case 71: // iteration_statement
      case 72: // assignment_statement
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
      case 75: // type_specifier
      case 76: // unary_operator
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case 73: // compound_statement
      case 74: // statement_list
        value.move< std::vector<statement_astnode*> > (YY_MOVE (that.value));
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
      case 45: // begin_nterm
      case 46: // translation_unit
      case 47: // struct_specifier
      case 48: // fun_declarator
      case 49: // parameter_list
      case 50: // parameter_declaration
      case 51: // declarator_arr
      case 52: // declarator
      case 53: // procedure_call
      case 54: // declaration_list
      case 55: // declaration
      case 56: // declarator_list
        value.copy< abstract_astnode* > (that.value);
        break;

      case 67: // assignment_expression
        value.copy< assignE_astnode* > (that.value);
        break;

      case 57: // expression
      case 58: // logical_and_expression
      case 59: // equality_expression
      case 60: // relational_expression
      case 61: // additive_expression
      case 62: // unary_expression
      case 63: // multiplicative_expression
      case 64: // postfix_expression
      case 65: // primary_expression
      case 66: // expression_list
        value.copy< exp_astnode* > (that.value);
        break;

      case 68: // function_definition
      case 69: // statement
      case 70: // selection_statement
      case 71: // iteration_statement
      case 72: // assignment_statement
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
      case 75: // type_specifier
      case 76: // unary_operator
        value.copy< std::string > (that.value);
        break;

      case 73: // compound_statement
      case 74: // statement_list
        value.copy< std::vector<statement_astnode*> > (that.value);
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
      case 45: // begin_nterm
      case 46: // translation_unit
      case 47: // struct_specifier
      case 48: // fun_declarator
      case 49: // parameter_list
      case 50: // parameter_declaration
      case 51: // declarator_arr
      case 52: // declarator
      case 53: // procedure_call
      case 54: // declaration_list
      case 55: // declaration
      case 56: // declarator_list
        value.move< abstract_astnode* > (that.value);
        break;

      case 67: // assignment_expression
        value.move< assignE_astnode* > (that.value);
        break;

      case 57: // expression
      case 58: // logical_and_expression
      case 59: // equality_expression
      case 60: // relational_expression
      case 61: // additive_expression
      case 62: // unary_expression
      case 63: // multiplicative_expression
      case 64: // postfix_expression
      case 65: // primary_expression
      case 66: // expression_list
        value.move< exp_astnode* > (that.value);
        break;

      case 68: // function_definition
      case 69: // statement
      case 70: // selection_statement
      case 71: // iteration_statement
      case 72: // assignment_statement
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
      case 75: // type_specifier
      case 76: // unary_operator
        value.move< std::string > (that.value);
        break;

      case 73: // compound_statement
      case 74: // statement_list
        value.move< std::vector<statement_astnode*> > (that.value);
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
#line 900 "parser.tab.cc"
        break;

      case 4: // INT
#line 17 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 906 "parser.tab.cc"
        break;

      case 5: // FLOAT
#line 18 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 912 "parser.tab.cc"
        break;

      case 6: // STRUCT
#line 19 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 918 "parser.tab.cc"
        break;

      case 7: // IDENTIFIER
#line 20 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 924 "parser.tab.cc"
        break;

      case 8: // INT_CONSTANT
#line 21 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 930 "parser.tab.cc"
        break;

      case 9: // FLOAT_CONSTANT
#line 22 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 936 "parser.tab.cc"
        break;

      case 10: // STRING_LITERAL
#line 23 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 942 "parser.tab.cc"
        break;

      case 11: // OR_OP
#line 24 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 948 "parser.tab.cc"
        break;

      case 12: // AND_OP
#line 25 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 954 "parser.tab.cc"
        break;

      case 13: // EQ_OP
#line 26 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 960 "parser.tab.cc"
        break;

      case 14: // NE_OP
#line 27 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 966 "parser.tab.cc"
        break;

      case 15: // LE_OP
#line 28 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 972 "parser.tab.cc"
        break;

      case 16: // GE_OP
#line 29 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 978 "parser.tab.cc"
        break;

      case 17: // INC_OP
#line 30 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 984 "parser.tab.cc"
        break;

      case 18: // PTR_OP
#line 31 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 990 "parser.tab.cc"
        break;

      case 19: // IF
#line 32 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 996 "parser.tab.cc"
        break;

      case 20: // ELSE
#line 33 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1002 "parser.tab.cc"
        break;

      case 21: // WHILE
#line 34 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1008 "parser.tab.cc"
        break;

      case 22: // FOR
#line 35 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1014 "parser.tab.cc"
        break;

      case 23: // RETURN
#line 36 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1020 "parser.tab.cc"
        break;

      case 24: // OTHERS
#line 37 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 1026 "parser.tab.cc"
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
      case 45: // begin_nterm
      case 46: // translation_unit
      case 47: // struct_specifier
      case 48: // fun_declarator
      case 49: // parameter_list
      case 50: // parameter_declaration
      case 51: // declarator_arr
      case 52: // declarator
      case 53: // procedure_call
      case 54: // declaration_list
      case 55: // declaration
      case 56: // declarator_list
        yylhs.value.emplace< abstract_astnode* > ();
        break;

      case 67: // assignment_expression
        yylhs.value.emplace< assignE_astnode* > ();
        break;

      case 57: // expression
      case 58: // logical_and_expression
      case 59: // equality_expression
      case 60: // relational_expression
      case 61: // additive_expression
      case 62: // unary_expression
      case 63: // multiplicative_expression
      case 64: // postfix_expression
      case 65: // primary_expression
      case 66: // expression_list
        yylhs.value.emplace< exp_astnode* > ();
        break;

      case 68: // function_definition
      case 69: // statement
      case 70: // selection_statement
      case 71: // iteration_statement
      case 72: // assignment_statement
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
      case 75: // type_specifier
      case 76: // unary_operator
        yylhs.value.emplace< std::string > ();
        break;

      case 73: // compound_statement
      case 74: // statement_list
        yylhs.value.emplace< std::vector<statement_astnode*> > ();
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
#line 96 "parser.yy"
                              {
    std::cout << "about to begin printing\n";
    yystack_[0].value.as < abstract_astnode* > ()->print();
}
#line 1341 "parser.tab.cc"
    break;

  case 3:
#line 101 "parser.yy"
                                  {
}
#line 1348 "parser.tab.cc"
    break;

  case 4:
#line 103 "parser.yy"
                     {
    yylhs.value.as < abstract_astnode* > () = yystack_[0].value.as < statement_astnode* > ();
}
#line 1356 "parser.tab.cc"
    break;

  case 5:
#line 106 "parser.yy"
                                   {
}
#line 1363 "parser.tab.cc"
    break;

  case 6:
#line 108 "parser.yy"
                                      {
}
#line 1370 "parser.tab.cc"
    break;

  case 7:
#line 112 "parser.yy"
                                                                {
}
#line 1377 "parser.tab.cc"
    break;

  case 8:
#line 115 "parser.yy"
                                                                     {
    yylhs.value.as < statement_astnode* > () = new seq_astnode(yystack_[0].value.as < std::vector<statement_astnode*> > ());
}
#line 1385 "parser.tab.cc"
    break;

  case 9:
#line 119 "parser.yy"
                    {
}
#line 1392 "parser.tab.cc"
    break;

  case 10:
#line 121 "parser.yy"
     {
}
#line 1399 "parser.tab.cc"
    break;

  case 11:
#line 123 "parser.yy"
       {
}
#line 1406 "parser.tab.cc"
    break;

  case 12:
#line 125 "parser.yy"
                   {
}
#line 1413 "parser.tab.cc"
    break;

  case 13:
#line 129 "parser.yy"
                                                 {
}
#line 1420 "parser.tab.cc"
    break;

  case 14:
#line 131 "parser.yy"
                    {
}
#line 1427 "parser.tab.cc"
    break;

  case 15:
#line 135 "parser.yy"
                                     {
}
#line 1434 "parser.tab.cc"
    break;

  case 16:
#line 137 "parser.yy"
                                          {
}
#line 1441 "parser.tab.cc"
    break;

  case 17:
#line 141 "parser.yy"
                                                {
}
#line 1448 "parser.tab.cc"
    break;

  case 18:
#line 145 "parser.yy"
                          {
}
#line 1455 "parser.tab.cc"
    break;

  case 19:
#line 147 "parser.yy"
                                     {
}
#line 1462 "parser.tab.cc"
    break;

  case 20:
#line 151 "parser.yy"
                          {
}
#line 1469 "parser.tab.cc"
    break;

  case 21:
#line 153 "parser.yy"
                {
}
#line 1476 "parser.tab.cc"
    break;

  case 22:
#line 157 "parser.yy"
                           {
}
#line 1483 "parser.tab.cc"
    break;

  case 23:
#line 159 "parser.yy"
                        {
    yylhs.value.as < std::vector<statement_astnode*> > () = yystack_[1].value.as < std::vector<statement_astnode*> > ();
}
#line 1491 "parser.tab.cc"
    break;

  case 24:
#line 162 "parser.yy"
                           {
}
#line 1498 "parser.tab.cc"
    break;

  case 25:
#line 164 "parser.yy"
                                         {
    yylhs.value.as < std::vector<statement_astnode*> > () = yystack_[1].value.as < std::vector<statement_astnode*> > ();
}
#line 1506 "parser.tab.cc"
    break;

  case 26:
#line 169 "parser.yy"
                          {
    std::vector<statement_astnode*> temp;
    temp.push_back(yystack_[0].value.as < statement_astnode* > ());
    yylhs.value.as < std::vector<statement_astnode*> > () = temp;
}
#line 1516 "parser.tab.cc"
    break;

  case 27:
#line 174 "parser.yy"
                          {
    yystack_[1].value.as < std::vector<statement_astnode*> > ().push_back(yystack_[0].value.as < statement_astnode* > ());
    yylhs.value.as < std::vector<statement_astnode*> > () = yystack_[1].value.as < std::vector<statement_astnode*> > ();
}
#line 1525 "parser.tab.cc"
    break;

  case 28:
#line 180 "parser.yy"
              {
}
#line 1532 "parser.tab.cc"
    break;

  case 29:
#line 182 "parser.yy"
                        {
    yylhs.value.as < statement_astnode* > () = new seq_astnode(yystack_[1].value.as < std::vector<statement_astnode*> > ());
}
#line 1540 "parser.tab.cc"
    break;

  case 30:
#line 185 "parser.yy"
                     {
    yylhs.value.as < statement_astnode* > () = yystack_[0].value.as < statement_astnode* > ();
}
#line 1548 "parser.tab.cc"
    break;

  case 31:
#line 188 "parser.yy"
                     {
    yylhs.value.as < statement_astnode* > () = yystack_[0].value.as < statement_astnode* > ();
}
#line 1556 "parser.tab.cc"
    break;

  case 32:
#line 191 "parser.yy"
                      {
    yylhs.value.as < statement_astnode* > () = yystack_[0].value.as < statement_astnode* > ();
}
#line 1564 "parser.tab.cc"
    break;

  case 33:
#line 194 "parser.yy"
                {
}
#line 1571 "parser.tab.cc"
    break;

  case 34:
#line 196 "parser.yy"
                       {
}
#line 1578 "parser.tab.cc"
    break;

  case 35:
#line 200 "parser.yy"
                                                      {
    yylhs.value.as < assignE_astnode* > () = new assignE_astnode(yystack_[2].value.as < exp_astnode* > (), yystack_[0].value.as < exp_astnode* > ());
}
#line 1586 "parser.tab.cc"
    break;

  case 36:
#line 205 "parser.yy"
                                               {
    yylhs.value.as < statement_astnode* > () = new assignS_astnode(yystack_[1].value.as < assignE_astnode* > ()->exp1, yystack_[1].value.as < assignE_astnode* > ()->exp2);
}
#line 1594 "parser.tab.cc"
    break;

  case 37:
#line 210 "parser.yy"
                                      {
}
#line 1601 "parser.tab.cc"
    break;

  case 38:
#line 212 "parser.yy"
                                        {
}
#line 1608 "parser.tab.cc"
    break;

  case 39:
#line 216 "parser.yy"
                                  {
    yylhs.value.as < exp_astnode* > () = yystack_[0].value.as < exp_astnode* > ();
}
#line 1616 "parser.tab.cc"
    break;

  case 40:
#line 219 "parser.yy"
                                         {
}
#line 1623 "parser.tab.cc"
    break;

  case 41:
#line 223 "parser.yy"
                                           {
    yylhs.value.as < exp_astnode* > () = yystack_[0].value.as < exp_astnode* > ();
}
#line 1631 "parser.tab.cc"
    break;

  case 42:
#line 226 "parser.yy"
                                                   {
    yylhs.value.as < exp_astnode* > () = new op_binary_astnode("AND?", yystack_[2].value.as < exp_astnode* > (), yystack_[0].value.as < exp_astnode* > ());
}
#line 1639 "parser.tab.cc"
    break;

  case 43:
#line 231 "parser.yy"
                                          {
    yylhs.value.as < exp_astnode* > () = yystack_[0].value.as < exp_astnode* > ();
}
#line 1647 "parser.tab.cc"
    break;

  case 44:
#line 234 "parser.yy"
                                                  {
    yylhs.value.as < exp_astnode* > () = new op_binary_astnode("EQ?", yystack_[2].value.as < exp_astnode* > (), yystack_[0].value.as < exp_astnode* > ());
}
#line 1655 "parser.tab.cc"
    break;

  case 45:
#line 237 "parser.yy"
                                                 {
    yylhs.value.as < exp_astnode* > () = new op_binary_astnode("NE?", yystack_[2].value.as < exp_astnode* > (), yystack_[0].value.as < exp_astnode* > ());
}
#line 1663 "parser.tab.cc"
    break;

  case 46:
#line 242 "parser.yy"
                                          {
    yylhs.value.as < exp_astnode* > () = yystack_[0].value.as < exp_astnode* > ();
}
#line 1671 "parser.tab.cc"
    break;

  case 47:
#line 245 "parser.yy"
                                               {
    yylhs.value.as < exp_astnode* > () = new op_binary_astnode("LT?", yystack_[2].value.as < exp_astnode* > (), yystack_[0].value.as < exp_astnode* > ());
}
#line 1679 "parser.tab.cc"
    break;

  case 48:
#line 248 "parser.yy"
                                               {
    yylhs.value.as < exp_astnode* > () = new op_binary_astnode("GT?", yystack_[2].value.as < exp_astnode* > (), yystack_[0].value.as < exp_astnode* > ());
}
#line 1687 "parser.tab.cc"
    break;

  case 49:
#line 251 "parser.yy"
                                                 {
    yylhs.value.as < exp_astnode* > () = new op_binary_astnode("LE?", yystack_[2].value.as < exp_astnode* > (), yystack_[0].value.as < exp_astnode* > ());
}
#line 1695 "parser.tab.cc"
    break;

  case 50:
#line 254 "parser.yy"
                                                 {
    yylhs.value.as < exp_astnode* > () = new op_binary_astnode("GE?", yystack_[2].value.as < exp_astnode* > (), yystack_[0].value.as < exp_astnode* > ());
}
#line 1703 "parser.tab.cc"
    break;

  case 51:
#line 259 "parser.yy"
                                              {
    yylhs.value.as < exp_astnode* > () = yystack_[0].value.as < exp_astnode* > ();
}
#line 1711 "parser.tab.cc"
    break;

  case 52:
#line 262 "parser.yy"
                                                   {
    yylhs.value.as < exp_astnode* > () = new op_binary_astnode("PLUS?", yystack_[2].value.as < exp_astnode* > (), yystack_[0].value.as < exp_astnode* > ());
}
#line 1719 "parser.tab.cc"
    break;

  case 53:
#line 265 "parser.yy"
                                                   {
    yylhs.value.as < exp_astnode* > () = new op_binary_astnode("MINUS?", yystack_[2].value.as < exp_astnode* > (), yystack_[0].value.as < exp_astnode* > ());
}
#line 1727 "parser.tab.cc"
    break;

  case 54:
#line 270 "parser.yy"
                                    {
    yylhs.value.as < exp_astnode* > () = yystack_[0].value.as < exp_astnode* > ();
}
#line 1735 "parser.tab.cc"
    break;

  case 55:
#line 273 "parser.yy"
                                 {
    yylhs.value.as < exp_astnode* > () = new op_unary_astnode(yystack_[1].value.as < std::string > (), yystack_[0].value.as < exp_astnode* > ());
}
#line 1743 "parser.tab.cc"
    break;

  case 56:
#line 278 "parser.yy"
                                           {
    yylhs.value.as < exp_astnode* > () = yystack_[0].value.as < exp_astnode* > ();
}
#line 1751 "parser.tab.cc"
    break;

  case 57:
#line 281 "parser.yy"
                                                {
    yylhs.value.as < exp_astnode* > () = new op_binary_astnode("MULT?", yystack_[2].value.as < exp_astnode* > (), yystack_[0].value.as < exp_astnode* > ());
}
#line 1759 "parser.tab.cc"
    break;

  case 58:
#line 284 "parser.yy"
                                                {
    yylhs.value.as < exp_astnode* > () = new op_binary_astnode("DIV?", yystack_[2].value.as < exp_astnode* > (), yystack_[0].value.as < exp_astnode* > ());
}
#line 1767 "parser.tab.cc"
    break;

  case 59:
#line 289 "parser.yy"
                                      {
    yylhs.value.as < exp_astnode* > () = yystack_[0].value.as < exp_astnode* > ();
}
#line 1775 "parser.tab.cc"
    break;

  case 60:
#line 292 "parser.yy"
                                       {
    yylhs.value.as < exp_astnode* > () = new arrayref_astnode(yystack_[3].value.as < exp_astnode* > (), yystack_[1].value.as < exp_astnode* > ());
}
#line 1783 "parser.tab.cc"
    break;

  case 61:
#line 295 "parser.yy"
                    {
}
#line 1790 "parser.tab.cc"
    break;

  case 62:
#line 297 "parser.yy"
                                    {
}
#line 1797 "parser.tab.cc"
    break;

  case 63:
#line 299 "parser.yy"
                                   {
    yylhs.value.as < exp_astnode* > () = new member_astnode(yystack_[2].value.as < exp_astnode* > (), new identifier_astnode(yystack_[0].value.as < std::string > ()));
}
#line 1805 "parser.tab.cc"
    break;

  case 64:
#line 302 "parser.yy"
                                      {
    yylhs.value.as < exp_astnode* > () = new arrow_astnode(yystack_[2].value.as < exp_astnode* > (), new identifier_astnode(yystack_[0].value.as < std::string > ()));
}
#line 1813 "parser.tab.cc"
    break;

  case 65:
#line 305 "parser.yy"
                           {
}
#line 1820 "parser.tab.cc"
    break;

  case 66:
#line 309 "parser.yy"
                              {
    yylhs.value.as < exp_astnode* > () = new identifier_astnode(yystack_[0].value.as < std::string > ());
}
#line 1828 "parser.tab.cc"
    break;

  case 67:
#line 312 "parser.yy"
              {
    yylhs.value.as < exp_astnode* > () = new intconst_astnode(yystack_[0].value.as < std::string > ());
}
#line 1836 "parser.tab.cc"
    break;

  case 68:
#line 315 "parser.yy"
                {
    yylhs.value.as < exp_astnode* > () = new floatconst_astnode(yystack_[0].value.as < std::string > ());
}
#line 1844 "parser.tab.cc"
    break;

  case 69:
#line 318 "parser.yy"
                {
    yylhs.value.as < exp_astnode* > () = new stringconst_astnode(yystack_[0].value.as < std::string > ());
    yylhs.value.as < exp_astnode* > ()->print();
}
#line 1853 "parser.tab.cc"
    break;

  case 70:
#line 322 "parser.yy"
                    {
}
#line 1860 "parser.tab.cc"
    break;

  case 71:
#line 326 "parser.yy"
                           {
}
#line 1867 "parser.tab.cc"
    break;

  case 72:
#line 328 "parser.yy"
                                {
}
#line 1874 "parser.tab.cc"
    break;

  case 73:
#line 332 "parser.yy"
                   {
    yylhs.value.as < std::string > () = std::string("UMINUS?");
}
#line 1882 "parser.tab.cc"
    break;

  case 74:
#line 335 "parser.yy"
     {
    yylhs.value.as < std::string > () = std::string("NOT");
}
#line 1890 "parser.tab.cc"
    break;

  case 75:
#line 338 "parser.yy"
     {
    yylhs.value.as < std::string > () = std::string("ADDRESS");
}
#line 1898 "parser.tab.cc"
    break;

  case 76:
#line 341 "parser.yy"
     {
    yylhs.value.as < std::string > () = std::string("DEREF");
}
#line 1906 "parser.tab.cc"
    break;

  case 77:
#line 346 "parser.yy"
                                                                   {
    yylhs.value.as < statement_astnode* > () = new if_astnode(yystack_[4].value.as < exp_astnode* > (), yystack_[2].value.as < statement_astnode* > (), yystack_[0].value.as < statement_astnode* > ());
}
#line 1914 "parser.tab.cc"
    break;

  case 78:
#line 351 "parser.yy"
                                                       {
    yylhs.value.as < statement_astnode* > () = new while_astnode(yystack_[2].value.as < exp_astnode* > (), yystack_[0].value.as < statement_astnode* > ());
}
#line 1922 "parser.tab.cc"
    break;

  case 79:
#line 354 "parser.yy"
                                                                                      {
    yylhs.value.as < statement_astnode* > () = new for_astnode(yystack_[6].value.as < assignE_astnode* > (), yystack_[4].value.as < exp_astnode* > (), yystack_[2].value.as < assignE_astnode* > (), yystack_[0].value.as < statement_astnode* > ());
}
#line 1930 "parser.tab.cc"
    break;

  case 80:
#line 359 "parser.yy"
                             {
}
#line 1937 "parser.tab.cc"
    break;

  case 81:
#line 361 "parser.yy"
                              {
}
#line 1944 "parser.tab.cc"
    break;

  case 82:
#line 365 "parser.yy"
                                               {
}
#line 1951 "parser.tab.cc"
    break;

  case 83:
#line 369 "parser.yy"
                           {
}
#line 1958 "parser.tab.cc"
    break;

  case 84:
#line 371 "parser.yy"
                                {
}
#line 1965 "parser.tab.cc"
    break;


#line 1969 "parser.tab.cc"

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


  const signed char Parser::yypact_ninf_ = -70;

  const signed char Parser::yytable_ninf_ = -1;

  const short
  Parser::yypact_[] =
  {
      80,   -70,   -70,   -70,    15,    17,    80,   -70,   -70,    22,
      26,   -70,   -70,   -70,    31,    44,    89,    66,   113,   -70,
      56,    10,   -70,    12,   -70,    57,   -70,    12,    51,   -70,
     -70,   -70,    60,    70,    72,   329,   -70,   -70,   329,   292,
     -70,   -70,   -70,   -70,   -70,   152,    67,    14,   -70,    90,
     -70,   -70,   -70,   -70,   187,   329,   -70,    92,   -70,   -70,
      12,   107,   -70,    50,   -70,    89,   -70,    16,   329,   329,
     329,   100,    -7,   136,    53,    35,    99,   -70,    78,    34,
     222,   -70,   257,   329,   -70,   142,   329,   145,   -70,   -70,
     -70,   -70,   -70,   -70,   155,    12,   -70,   -70,   112,   153,
      83,    45,    49,   124,   297,   329,   -70,   329,   329,   329,
     329,   329,   329,   329,   329,   329,   329,   329,   -70,   -70,
     -70,   153,   -70,    -3,   -70,   130,   -70,   -70,   126,   329,
     292,   292,   329,   -70,    95,   136,    53,    35,    35,    99,
      99,    99,    99,    78,    78,   -70,   -70,   -70,   -70,   -70,
     153,   148,   -70,     7,   -70,   292,   329,   -70,   138,   292,
     -70
  };

  const signed char
  Parser::yydefact_[] =
  {
       0,     9,    10,    11,     0,     0,     2,     3,     4,     0,
      12,     1,     5,     6,     0,     0,     0,     0,     0,     8,
       0,     0,    80,     0,    14,     0,    15,     0,    66,    67,
      68,    69,     0,     0,     0,     0,    73,    76,     0,     0,
      22,    74,    75,    28,    33,     0,     0,    54,    59,     0,
      26,    30,    31,    32,     0,     0,    12,     0,    81,    18,
       0,    20,    83,     0,    13,     0,    17,     0,     0,     0,
       0,    66,     0,    39,    41,    43,    46,    56,    51,     0,
       0,    24,     0,     0,    65,     0,     0,     0,    36,    23,
      27,    55,     7,    21,     0,     0,    82,    16,    61,    71,
       0,     0,     0,     0,     0,     0,    34,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    70,    29,
      25,    35,    64,     0,    63,     0,    84,    37,    62,     0,
       0,     0,     0,    61,     0,    40,    42,    44,    45,    49,
      50,    47,    48,    52,    53,    57,    58,    60,    19,    38,
      72,     0,    78,     0,    62,     0,     0,    77,     0,     0,
      79
  };

  const short
  Parser::yypgoto_[] =
  {
     -70,   -70,   -70,   164,   -70,   -70,   111,   -70,   -22,   -70,
     154,   -10,   -70,   -28,    75,    74,    20,    -2,   -18,    30,
     -70,   -70,    73,   -69,   177,   -52,   -70,   -70,   -70,   -70,
     -33,     3,   -70
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,     5,     6,     7,    15,    25,    26,    61,    62,    44,
      21,    22,    63,    99,    73,    74,    75,    76,    77,    78,
      47,    48,   100,    49,     8,    50,    51,    52,    53,    19,
      54,    23,    55
  };

  const unsigned char
  Parser::yytable_[] =
  {
      46,   103,    90,     9,   105,    66,    80,    72,   105,     9,
      79,    58,    82,     1,     2,     3,    20,    11,   105,    59,
      27,    46,    10,    71,    29,    30,    31,    46,    90,    14,
      90,    84,    85,   147,   106,    58,    46,    91,    93,    60,
     101,   102,    36,    37,    57,   105,    38,    98,   156,    86,
     110,   111,    46,    41,    42,   121,   105,    87,   123,    16,
     105,    17,    46,    56,    46,   118,   108,   109,    27,     1,
       2,     3,    20,   126,   112,   113,   130,    18,   151,   152,
     131,    67,    95,     1,     2,     3,     4,   158,    64,    65,
      68,    96,     1,     2,     3,    20,    83,    24,   145,   146,
      69,   150,    70,   157,   153,   116,   117,   160,   139,   140,
     141,   142,    46,    46,   128,   129,     1,     2,     3,    20,
      28,    29,    30,    31,   114,   115,   154,   129,   137,   138,
     104,    88,    32,    92,    33,    34,    35,    46,    46,    36,
      37,    46,    94,    38,   143,   144,    39,    40,   107,   122,
      41,    42,   124,   127,    43,     1,     2,     3,    20,    28,
      29,    30,    31,   125,   105,   132,   148,   149,   155,   159,
      12,    32,    45,    33,    34,    35,    97,   134,    36,    37,
     135,   136,    38,    13,     0,    39,    81,     0,     0,    41,
      42,     0,     0,    43,    28,    29,    30,    31,     0,     0,
       0,     0,     0,     0,     0,     0,    32,     0,    33,    34,
      35,     0,     0,    36,    37,     0,     0,    38,     0,     0,
      39,    89,     0,     0,    41,    42,     0,     0,    43,    28,
      29,    30,    31,     0,     0,     0,     0,     0,     0,     0,
       0,    32,     0,    33,    34,    35,     0,     0,    36,    37,
       0,     0,    38,     0,     0,    39,   119,     0,     0,    41,
      42,     0,     0,    43,    28,    29,    30,    31,     0,     0,
       0,     0,     0,     0,     0,     0,    32,     0,    33,    34,
      35,     0,     0,    36,    37,     0,     0,    38,     0,     0,
      39,   120,     0,     0,    41,    42,     0,     0,    43,    28,
      29,    30,    31,     0,    71,    29,    30,    31,     0,     0,
       0,    32,     0,    33,    34,    35,     0,     0,    36,    37,
       0,     0,    38,    36,    37,    39,     0,    38,   133,    41,
      42,     0,     0,    43,    41,    42,    71,    29,    30,    31,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    36,    37,     0,     0,    38,
       0,     0,     0,     0,     0,     0,    41,    42
  };

  const short
  Parser::yycheck_[] =
  {
      18,    70,    54,     0,    11,    27,    39,    35,    11,     6,
      38,    21,    45,     3,     4,     5,     6,     0,    11,     7,
      17,    39,     7,     7,     8,     9,    10,    45,    80,     7,
      82,    17,    18,    36,    41,    45,    54,    55,    60,    27,
      68,    69,    26,    27,    34,    11,    30,    31,    41,    35,
      15,    16,    70,    37,    38,    83,    11,    43,    86,    33,
      11,    30,    80,     7,    82,    31,    13,    14,    65,     3,
       4,     5,     6,    95,    39,    40,    31,    33,   130,   131,
      31,    30,    32,     3,     4,     5,     6,   156,    31,    32,
      30,    41,     3,     4,     5,     6,    29,    31,   116,   117,
      30,   129,    30,   155,   132,    27,    28,   159,   110,   111,
     112,   113,   130,   131,    31,    32,     3,     4,     5,     6,
       7,     8,     9,    10,    25,    26,    31,    32,   108,   109,
      30,    41,    19,    41,    21,    22,    23,   155,   156,    26,
      27,   159,    35,    30,   114,   115,    33,    34,    12,     7,
      37,    38,     7,    41,    41,     3,     4,     5,     6,     7,
       8,     9,    10,     8,    11,    41,    36,    41,    20,    31,
       6,    19,    18,    21,    22,    23,    65,   104,    26,    27,
     105,   107,    30,     6,    -1,    33,    34,    -1,    -1,    37,
      38,    -1,    -1,    41,     7,     8,     9,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,    21,    22,
      23,    -1,    -1,    26,    27,    -1,    -1,    30,    -1,    -1,
      33,    34,    -1,    -1,    37,    38,    -1,    -1,    41,     7,
       8,     9,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    -1,    21,    22,    23,    -1,    -1,    26,    27,
      -1,    -1,    30,    -1,    -1,    33,    34,    -1,    -1,    37,
      38,    -1,    -1,    41,     7,     8,     9,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    -1,    21,    22,
      23,    -1,    -1,    26,    27,    -1,    -1,    30,    -1,    -1,
      33,    34,    -1,    -1,    37,    38,    -1,    -1,    41,     7,
       8,     9,    10,    -1,     7,     8,     9,    10,    -1,    -1,
      -1,    19,    -1,    21,    22,    23,    -1,    -1,    26,    27,
      -1,    -1,    30,    26,    27,    33,    -1,    30,    31,    37,
      38,    -1,    -1,    41,    37,    38,     7,     8,     9,    10,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    27,    -1,    -1,    30,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    38
  };

  const signed char
  Parser::yystos_[] =
  {
       0,     3,     4,     5,     6,    45,    46,    47,    68,    75,
       7,     0,    47,    68,     7,    48,    33,    30,    33,    73,
       6,    54,    55,    75,    31,    49,    50,    75,     7,     8,
       9,    10,    19,    21,    22,    23,    26,    27,    30,    33,
      34,    37,    38,    41,    53,    54,    62,    64,    65,    67,
      69,    70,    71,    72,    74,    76,     7,    34,    55,     7,
      27,    51,    52,    56,    31,    32,    52,    30,    30,    30,
      30,     7,    57,    58,    59,    60,    61,    62,    63,    57,
      74,    34,    74,    29,    17,    18,    35,    43,    41,    34,
      69,    62,    41,    52,    35,    32,    41,    50,    31,    57,
      66,    57,    57,    67,    30,    11,    41,    12,    13,    14,
      15,    16,    39,    40,    25,    26,    27,    28,    31,    34,
      34,    57,     7,    57,     7,     8,    52,    41,    31,    32,
      31,    31,    41,    31,    66,    58,    59,    60,    60,    61,
      61,    61,    61,    63,    63,    62,    62,    36,    36,    41,
      57,    69,    69,    57,    31,    20,    41,    69,    67,    31,
      69
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    44,    45,    46,    46,    46,    46,    47,    68,    75,
      75,    75,    75,    48,    48,    49,    49,    50,    51,    51,
      52,    52,    73,    73,    73,    73,    74,    74,    69,    69,
      69,    69,    69,    69,    69,    67,    72,    53,    53,    57,
      57,    58,    58,    59,    59,    59,    60,    60,    60,    60,
      60,    61,    61,    61,    62,    62,    63,    63,    63,    64,
      64,    64,    64,    64,    64,    64,    65,    65,    65,    65,
      65,    66,    66,    76,    76,    76,    76,    70,    71,    71,
      54,    54,    55,    56,    56
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     1,     1,     2,     2,     6,     3,     1,
       1,     1,     2,     4,     3,     1,     3,     2,     1,     4,
       1,     2,     2,     3,     3,     4,     1,     2,     1,     3,
       1,     1,     1,     1,     3,     3,     2,     4,     5,     1,
       3,     1,     3,     1,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     2,     1,     3,     3,     1,
       4,     3,     4,     3,     3,     2,     1,     1,     1,     1,
       3,     1,     3,     1,     1,     1,     1,     7,     5,     9,
       1,     2,     3,     1,     3
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
  "begin_nterm", "translation_unit", "struct_specifier", "fun_declarator",
  "parameter_list", "parameter_declaration", "declarator_arr",
  "declarator", "procedure_call", "declaration_list", "declaration",
  "declarator_list", "expression", "logical_and_expression",
  "equality_expression", "relational_expression", "additive_expression",
  "unary_expression", "multiplicative_expression", "postfix_expression",
  "primary_expression", "expression_list", "assignment_expression",
  "function_definition", "statement", "selection_statement",
  "iteration_statement", "assignment_statement", "compound_statement",
  "statement_list", "type_specifier", "unary_operator", YY_NULLPTR
  };


  const short
  Parser::yyrline_[] =
  {
       0,    96,    96,   101,   103,   106,   108,   112,   115,   119,
     121,   123,   125,   129,   131,   135,   137,   141,   145,   147,
     151,   153,   157,   159,   162,   164,   169,   174,   180,   182,
     185,   188,   191,   194,   196,   200,   205,   210,   212,   216,
     219,   223,   226,   231,   234,   237,   242,   245,   248,   251,
     254,   259,   262,   265,   270,   273,   278,   281,   284,   289,
     292,   295,   297,   299,   302,   305,   309,   312,   315,   318,
     322,   326,   328,   332,   335,   338,   341,   346,   351,   354,
     359,   361,   365,   369,   371
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
#line 2469 "parser.tab.cc"

#line 375 "parser.yy"

//grammar definition.
void IPL::Parser::error( const location_type &l, const std::string &err_message )
{
   std::cerr << "Error: " << err_message << " at " << l << "\n";
}

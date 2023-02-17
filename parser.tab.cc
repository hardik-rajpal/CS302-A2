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
      case 45: // translation_unit
      case 46: // struct_specifier
      case 47: // function_definition
      case 48: // fun_declarator
      case 49: // parameter_list
      case 50: // parameter_declaration
      case 51: // declarator_arr
      case 52: // declarator
      case 53: // compound_statement
      case 54: // statement_list
      case 55: // statement
      case 56: // assignment_expression
      case 57: // assignment_statement
      case 58: // procedure_call
      case 59: // expression
      case 60: // logical_and_expression
      case 61: // equality_expression
      case 62: // relational_expression
      case 63: // additive_expression
      case 64: // unary_expression
      case 65: // multiplicative_expression
      case 66: // postfix_expression
      case 67: // primary_expression
      case 68: // expression_list
      case 69: // unary_operator
      case 70: // selection_statement
      case 71: // iteration_statement
      case 72: // declaration_list
      case 73: // declaration
      case 74: // declarator_list
        value.move< abstract_astnode* > (std::move (that.value));
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
        value.move< std::string > (std::move (that.value));
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
      case 45: // translation_unit
      case 46: // struct_specifier
      case 47: // function_definition
      case 48: // fun_declarator
      case 49: // parameter_list
      case 50: // parameter_declaration
      case 51: // declarator_arr
      case 52: // declarator
      case 53: // compound_statement
      case 54: // statement_list
      case 55: // statement
      case 56: // assignment_expression
      case 57: // assignment_statement
      case 58: // procedure_call
      case 59: // expression
      case 60: // logical_and_expression
      case 61: // equality_expression
      case 62: // relational_expression
      case 63: // additive_expression
      case 64: // unary_expression
      case 65: // multiplicative_expression
      case 66: // postfix_expression
      case 67: // primary_expression
      case 68: // expression_list
      case 69: // unary_operator
      case 70: // selection_statement
      case 71: // iteration_statement
      case 72: // declaration_list
      case 73: // declaration
      case 74: // declarator_list
        value.copy< abstract_astnode* > (YY_MOVE (that.value));
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
        value.copy< std::string > (YY_MOVE (that.value));
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
      case 45: // translation_unit
      case 46: // struct_specifier
      case 47: // function_definition
      case 48: // fun_declarator
      case 49: // parameter_list
      case 50: // parameter_declaration
      case 51: // declarator_arr
      case 52: // declarator
      case 53: // compound_statement
      case 54: // statement_list
      case 55: // statement
      case 56: // assignment_expression
      case 57: // assignment_statement
      case 58: // procedure_call
      case 59: // expression
      case 60: // logical_and_expression
      case 61: // equality_expression
      case 62: // relational_expression
      case 63: // additive_expression
      case 64: // unary_expression
      case 65: // multiplicative_expression
      case 66: // postfix_expression
      case 67: // primary_expression
      case 68: // expression_list
      case 69: // unary_operator
      case 70: // selection_statement
      case 71: // iteration_statement
      case 72: // declaration_list
      case 73: // declaration
      case 74: // declarator_list
        value.move< abstract_astnode* > (YY_MOVE (s.value));
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
        value.move< std::string > (YY_MOVE (s.value));
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
      case 45: // translation_unit
      case 46: // struct_specifier
      case 47: // function_definition
      case 48: // fun_declarator
      case 49: // parameter_list
      case 50: // parameter_declaration
      case 51: // declarator_arr
      case 52: // declarator
      case 53: // compound_statement
      case 54: // statement_list
      case 55: // statement
      case 56: // assignment_expression
      case 57: // assignment_statement
      case 58: // procedure_call
      case 59: // expression
      case 60: // logical_and_expression
      case 61: // equality_expression
      case 62: // relational_expression
      case 63: // additive_expression
      case 64: // unary_expression
      case 65: // multiplicative_expression
      case 66: // postfix_expression
      case 67: // primary_expression
      case 68: // expression_list
      case 69: // unary_operator
      case 70: // selection_statement
      case 71: // iteration_statement
      case 72: // declaration_list
      case 73: // declaration
      case 74: // declarator_list
        value.YY_MOVE_OR_COPY< abstract_astnode* > (YY_MOVE (that.value));
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
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
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
      case 45: // translation_unit
      case 46: // struct_specifier
      case 47: // function_definition
      case 48: // fun_declarator
      case 49: // parameter_list
      case 50: // parameter_declaration
      case 51: // declarator_arr
      case 52: // declarator
      case 53: // compound_statement
      case 54: // statement_list
      case 55: // statement
      case 56: // assignment_expression
      case 57: // assignment_statement
      case 58: // procedure_call
      case 59: // expression
      case 60: // logical_and_expression
      case 61: // equality_expression
      case 62: // relational_expression
      case 63: // additive_expression
      case 64: // unary_expression
      case 65: // multiplicative_expression
      case 66: // postfix_expression
      case 67: // primary_expression
      case 68: // expression_list
      case 69: // unary_operator
      case 70: // selection_statement
      case 71: // iteration_statement
      case 72: // declaration_list
      case 73: // declaration
      case 74: // declarator_list
        value.move< abstract_astnode* > (YY_MOVE (that.value));
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
        value.move< std::string > (YY_MOVE (that.value));
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
      case 45: // translation_unit
      case 46: // struct_specifier
      case 47: // function_definition
      case 48: // fun_declarator
      case 49: // parameter_list
      case 50: // parameter_declaration
      case 51: // declarator_arr
      case 52: // declarator
      case 53: // compound_statement
      case 54: // statement_list
      case 55: // statement
      case 56: // assignment_expression
      case 57: // assignment_statement
      case 58: // procedure_call
      case 59: // expression
      case 60: // logical_and_expression
      case 61: // equality_expression
      case 62: // relational_expression
      case 63: // additive_expression
      case 64: // unary_expression
      case 65: // multiplicative_expression
      case 66: // postfix_expression
      case 67: // primary_expression
      case 68: // expression_list
      case 69: // unary_operator
      case 70: // selection_statement
      case 71: // iteration_statement
      case 72: // declaration_list
      case 73: // declaration
      case 74: // declarator_list
        value.copy< abstract_astnode* > (that.value);
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
        value.copy< std::string > (that.value);
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
      case 45: // translation_unit
      case 46: // struct_specifier
      case 47: // function_definition
      case 48: // fun_declarator
      case 49: // parameter_list
      case 50: // parameter_declaration
      case 51: // declarator_arr
      case 52: // declarator
      case 53: // compound_statement
      case 54: // statement_list
      case 55: // statement
      case 56: // assignment_expression
      case 57: // assignment_statement
      case 58: // procedure_call
      case 59: // expression
      case 60: // logical_and_expression
      case 61: // equality_expression
      case 62: // relational_expression
      case 63: // additive_expression
      case 64: // unary_expression
      case 65: // multiplicative_expression
      case 66: // postfix_expression
      case 67: // primary_expression
      case 68: // expression_list
      case 69: // unary_operator
      case 70: // selection_statement
      case 71: // iteration_statement
      case 72: // declaration_list
      case 73: // declaration
      case 74: // declarator_list
        value.move< abstract_astnode* > (that.value);
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
        value.move< std::string > (that.value);
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
#line 809 "parser.tab.cc"
        break;

      case 4: // INT
#line 17 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 815 "parser.tab.cc"
        break;

      case 5: // FLOAT
#line 18 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 821 "parser.tab.cc"
        break;

      case 6: // STRUCT
#line 19 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 827 "parser.tab.cc"
        break;

      case 7: // IDENTIFIER
#line 20 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 833 "parser.tab.cc"
        break;

      case 8: // INT_CONSTANT
#line 21 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 839 "parser.tab.cc"
        break;

      case 9: // FLOAT_CONSTANT
#line 22 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 845 "parser.tab.cc"
        break;

      case 10: // STRING_LITERAL
#line 23 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 851 "parser.tab.cc"
        break;

      case 11: // OR_OP
#line 24 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 857 "parser.tab.cc"
        break;

      case 12: // AND_OP
#line 25 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 863 "parser.tab.cc"
        break;

      case 13: // EQ_OP
#line 26 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 869 "parser.tab.cc"
        break;

      case 14: // NE_OP
#line 27 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 875 "parser.tab.cc"
        break;

      case 15: // LE_OP
#line 28 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 881 "parser.tab.cc"
        break;

      case 16: // GE_OP
#line 29 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 887 "parser.tab.cc"
        break;

      case 17: // INC_OP
#line 30 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 893 "parser.tab.cc"
        break;

      case 18: // PTR_OP
#line 31 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 899 "parser.tab.cc"
        break;

      case 19: // IF
#line 32 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 905 "parser.tab.cc"
        break;

      case 20: // ELSE
#line 33 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 911 "parser.tab.cc"
        break;

      case 21: // WHILE
#line 34 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 917 "parser.tab.cc"
        break;

      case 22: // FOR
#line 35 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 923 "parser.tab.cc"
        break;

      case 23: // RETURN
#line 36 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 929 "parser.tab.cc"
        break;

      case 24: // OTHERS
#line 37 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 935 "parser.tab.cc"
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
      case 45: // translation_unit
      case 46: // struct_specifier
      case 47: // function_definition
      case 48: // fun_declarator
      case 49: // parameter_list
      case 50: // parameter_declaration
      case 51: // declarator_arr
      case 52: // declarator
      case 53: // compound_statement
      case 54: // statement_list
      case 55: // statement
      case 56: // assignment_expression
      case 57: // assignment_statement
      case 58: // procedure_call
      case 59: // expression
      case 60: // logical_and_expression
      case 61: // equality_expression
      case 62: // relational_expression
      case 63: // additive_expression
      case 64: // unary_expression
      case 65: // multiplicative_expression
      case 66: // postfix_expression
      case 67: // primary_expression
      case 68: // expression_list
      case 69: // unary_operator
      case 70: // selection_statement
      case 71: // iteration_statement
      case 72: // declaration_list
      case 73: // declaration
      case 74: // declarator_list
        yylhs.value.emplace< abstract_astnode* > ();
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
        yylhs.value.emplace< std::string > ();
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
#line 88 "parser.yy"
                                  {
    yystack_[0].value.as < abstract_astnode* > ()->print();
}
#line 1236 "parser.tab.cc"
    break;

  case 3:
#line 91 "parser.yy"
                     {
    yystack_[0].value.as < abstract_astnode* > ()->print();
}
#line 1244 "parser.tab.cc"
    break;

  case 4:
#line 94 "parser.yy"
                                   {
    yystack_[1].value.as < abstract_astnode* > ()->print();
}
#line 1252 "parser.tab.cc"
    break;

  case 5:
#line 97 "parser.yy"
                                      {
    yystack_[1].value.as < abstract_astnode* > ()->print();
}
#line 1260 "parser.tab.cc"
    break;

  case 6:
#line 102 "parser.yy"
                                                                {
}
#line 1267 "parser.tab.cc"
    break;

  case 7:
#line 105 "parser.yy"
                                                                     {
}
#line 1274 "parser.tab.cc"
    break;

  case 8:
#line 108 "parser.yy"
                    {
}
#line 1281 "parser.tab.cc"
    break;

  case 9:
#line 110 "parser.yy"
     {
}
#line 1288 "parser.tab.cc"
    break;

  case 10:
#line 112 "parser.yy"
       {
}
#line 1295 "parser.tab.cc"
    break;

  case 11:
#line 114 "parser.yy"
                   {
}
#line 1302 "parser.tab.cc"
    break;

  case 12:
#line 118 "parser.yy"
                                                 {
}
#line 1309 "parser.tab.cc"
    break;

  case 13:
#line 120 "parser.yy"
                    {
}
#line 1316 "parser.tab.cc"
    break;

  case 14:
#line 124 "parser.yy"
                                     {
}
#line 1323 "parser.tab.cc"
    break;

  case 15:
#line 126 "parser.yy"
                                          {
}
#line 1330 "parser.tab.cc"
    break;

  case 16:
#line 130 "parser.yy"
                                                {
}
#line 1337 "parser.tab.cc"
    break;

  case 17:
#line 134 "parser.yy"
                          {
}
#line 1344 "parser.tab.cc"
    break;

  case 18:
#line 136 "parser.yy"
                                     {
}
#line 1351 "parser.tab.cc"
    break;

  case 19:
#line 140 "parser.yy"
                          {
}
#line 1358 "parser.tab.cc"
    break;

  case 20:
#line 142 "parser.yy"
                {
}
#line 1365 "parser.tab.cc"
    break;

  case 21:
#line 146 "parser.yy"
                           {
}
#line 1372 "parser.tab.cc"
    break;

  case 22:
#line 148 "parser.yy"
                        {
}
#line 1379 "parser.tab.cc"
    break;

  case 23:
#line 150 "parser.yy"
                           {
}
#line 1386 "parser.tab.cc"
    break;

  case 24:
#line 152 "parser.yy"
                                         {
}
#line 1393 "parser.tab.cc"
    break;

  case 25:
#line 156 "parser.yy"
                         {
}
#line 1400 "parser.tab.cc"
    break;

  case 26:
#line 158 "parser.yy"
                          {
}
#line 1407 "parser.tab.cc"
    break;

  case 27:
#line 162 "parser.yy"
              {
}
#line 1414 "parser.tab.cc"
    break;

  case 28:
#line 164 "parser.yy"
                        {
}
#line 1421 "parser.tab.cc"
    break;

  case 29:
#line 166 "parser.yy"
                     {
}
#line 1428 "parser.tab.cc"
    break;

  case 30:
#line 168 "parser.yy"
                     {
}
#line 1435 "parser.tab.cc"
    break;

  case 31:
#line 170 "parser.yy"
                      {
}
#line 1442 "parser.tab.cc"
    break;

  case 32:
#line 172 "parser.yy"
                {
}
#line 1449 "parser.tab.cc"
    break;

  case 33:
#line 174 "parser.yy"
                       {
}
#line 1456 "parser.tab.cc"
    break;

  case 34:
#line 178 "parser.yy"
                                                      {
}
#line 1463 "parser.tab.cc"
    break;

  case 35:
#line 182 "parser.yy"
                                               {
}
#line 1470 "parser.tab.cc"
    break;

  case 36:
#line 186 "parser.yy"
                                      {
}
#line 1477 "parser.tab.cc"
    break;

  case 37:
#line 188 "parser.yy"
                                        {
}
#line 1484 "parser.tab.cc"
    break;

  case 38:
#line 192 "parser.yy"
                                  {
}
#line 1491 "parser.tab.cc"
    break;

  case 39:
#line 194 "parser.yy"
                                         {
}
#line 1498 "parser.tab.cc"
    break;

  case 40:
#line 198 "parser.yy"
                                           {
}
#line 1505 "parser.tab.cc"
    break;

  case 41:
#line 200 "parser.yy"
                                                   {
}
#line 1512 "parser.tab.cc"
    break;

  case 42:
#line 204 "parser.yy"
                                          {
}
#line 1519 "parser.tab.cc"
    break;

  case 43:
#line 206 "parser.yy"
                                                 {
}
#line 1526 "parser.tab.cc"
    break;

  case 44:
#line 208 "parser.yy"
                                                 {
}
#line 1533 "parser.tab.cc"
    break;

  case 45:
#line 212 "parser.yy"
                                          {
}
#line 1540 "parser.tab.cc"
    break;

  case 46:
#line 214 "parser.yy"
                                               {
}
#line 1547 "parser.tab.cc"
    break;

  case 47:
#line 216 "parser.yy"
                                               {
}
#line 1554 "parser.tab.cc"
    break;

  case 48:
#line 218 "parser.yy"
                                                 {
}
#line 1561 "parser.tab.cc"
    break;

  case 49:
#line 220 "parser.yy"
                                                 {
}
#line 1568 "parser.tab.cc"
    break;

  case 50:
#line 224 "parser.yy"
                                              {
}
#line 1575 "parser.tab.cc"
    break;

  case 51:
#line 226 "parser.yy"
                                                   {
}
#line 1582 "parser.tab.cc"
    break;

  case 52:
#line 228 "parser.yy"
                                                   {
}
#line 1589 "parser.tab.cc"
    break;

  case 53:
#line 232 "parser.yy"
                                    {
}
#line 1596 "parser.tab.cc"
    break;

  case 54:
#line 234 "parser.yy"
                                 {
}
#line 1603 "parser.tab.cc"
    break;

  case 55:
#line 238 "parser.yy"
                                           {
}
#line 1610 "parser.tab.cc"
    break;

  case 56:
#line 240 "parser.yy"
                                                {
}
#line 1617 "parser.tab.cc"
    break;

  case 57:
#line 242 "parser.yy"
                                                {
}
#line 1624 "parser.tab.cc"
    break;

  case 58:
#line 246 "parser.yy"
                                      {
}
#line 1631 "parser.tab.cc"
    break;

  case 59:
#line 248 "parser.yy"
                                       {
}
#line 1638 "parser.tab.cc"
    break;

  case 60:
#line 250 "parser.yy"
                    {
}
#line 1645 "parser.tab.cc"
    break;

  case 61:
#line 252 "parser.yy"
                                    {
}
#line 1652 "parser.tab.cc"
    break;

  case 62:
#line 254 "parser.yy"
                                   {
}
#line 1659 "parser.tab.cc"
    break;

  case 63:
#line 256 "parser.yy"
                                      {
}
#line 1666 "parser.tab.cc"
    break;

  case 64:
#line 258 "parser.yy"
                           {
}
#line 1673 "parser.tab.cc"
    break;

  case 65:
#line 262 "parser.yy"
                              {
    yylhs.value.as < abstract_astnode* > () = new identifier_astnode(yystack_[0].value.as < std::string > ());
}
#line 1681 "parser.tab.cc"
    break;

  case 66:
#line 265 "parser.yy"
              {
    yylhs.value.as < abstract_astnode* > () = new intconst_astnode(yystack_[0].value.as < std::string > ());
}
#line 1689 "parser.tab.cc"
    break;

  case 67:
#line 268 "parser.yy"
                {
    yylhs.value.as < abstract_astnode* > () = new floatconst_astnode(yystack_[0].value.as < std::string > ());
}
#line 1697 "parser.tab.cc"
    break;

  case 68:
#line 271 "parser.yy"
                {
    yylhs.value.as < abstract_astnode* > () = new stringconst_astnode(yystack_[0].value.as < std::string > ());
    yylhs.value.as < abstract_astnode* > ()->print();
}
#line 1706 "parser.tab.cc"
    break;

  case 69:
#line 275 "parser.yy"
                    {
}
#line 1713 "parser.tab.cc"
    break;

  case 70:
#line 279 "parser.yy"
                           {
}
#line 1720 "parser.tab.cc"
    break;

  case 71:
#line 281 "parser.yy"
                                {
}
#line 1727 "parser.tab.cc"
    break;

  case 72:
#line 285 "parser.yy"
                   {
}
#line 1734 "parser.tab.cc"
    break;

  case 73:
#line 287 "parser.yy"
     {
}
#line 1741 "parser.tab.cc"
    break;

  case 74:
#line 289 "parser.yy"
     {
}
#line 1748 "parser.tab.cc"
    break;

  case 75:
#line 291 "parser.yy"
     {
}
#line 1755 "parser.tab.cc"
    break;

  case 76:
#line 295 "parser.yy"
                                                                   {
}
#line 1762 "parser.tab.cc"
    break;

  case 77:
#line 299 "parser.yy"
                                                       {
}
#line 1769 "parser.tab.cc"
    break;

  case 78:
#line 301 "parser.yy"
                                                                                      {
}
#line 1776 "parser.tab.cc"
    break;

  case 79:
#line 305 "parser.yy"
                             {
}
#line 1783 "parser.tab.cc"
    break;

  case 80:
#line 307 "parser.yy"
                              {
}
#line 1790 "parser.tab.cc"
    break;

  case 81:
#line 311 "parser.yy"
                                               {
}
#line 1797 "parser.tab.cc"
    break;

  case 82:
#line 315 "parser.yy"
                           {
}
#line 1804 "parser.tab.cc"
    break;

  case 83:
#line 317 "parser.yy"
                                {
}
#line 1811 "parser.tab.cc"
    break;


#line 1815 "parser.tab.cc"

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


  const signed char Parser::yypact_ninf_ = -69;

  const signed char Parser::yytable_ninf_ = -1;

  const short
  Parser::yypact_[] =
  {
     102,   -69,   -69,   -69,    -2,    88,   -69,   -69,    10,     5,
     -69,   -69,   -69,    21,    32,   116,    24,   121,   -69,    69,
      19,   -69,    40,   -69,   -20,   -69,    40,    39,   -69,   -69,
     -69,    67,    70,    81,     6,   -69,   -69,     6,   300,   -69,
     -69,   -69,   -69,   195,   -69,    31,   -69,   -69,    54,    28,
     -69,     6,   -69,   -69,   160,   -69,    74,   -69,   -69,    40,
      97,   -69,    34,   -69,   116,   -69,   305,     6,     6,     6,
      93,     7,   123,    65,    42,    60,   -69,    68,    43,   230,
     -69,   -69,   -69,     6,   -69,   129,     6,   132,   -69,   -69,
     265,   -69,   -69,   137,    40,   -69,   -69,   105,   138,    71,
      49,    53,   109,   337,     6,   -69,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     6,   -69,   -69,   138,
     -69,    -5,   -69,   -69,   117,   -69,   -69,   111,     6,   300,
     300,     6,   -69,    78,   123,    65,    42,    42,    60,    60,
      60,    60,    68,    68,   -69,   -69,   -69,   -69,   -69,   138,
     136,   -69,     8,   -69,   300,     6,   -69,   126,   300,   -69
  };

  const signed char
  Parser::yydefact_[] =
  {
       0,     8,     9,    10,     0,     0,     2,     3,     0,    11,
       1,     4,     5,     0,     0,     0,     0,     0,     7,     0,
       0,    79,     0,    13,     0,    14,     0,    65,    66,    67,
      68,     0,     0,     0,     0,    72,    75,     0,     0,    21,
      73,    74,    27,     0,    25,     0,    31,    32,     0,    53,
      58,     0,    29,    30,     0,    11,     0,    80,    17,     0,
      19,    82,     0,    12,     0,    16,     0,     0,     0,     0,
      65,     0,    38,    40,    42,    45,    55,    50,     0,     0,
      22,    26,    35,     0,    64,     0,     0,     0,    54,    23,
       0,     6,    20,     0,     0,    81,    15,    60,    70,     0,
       0,     0,     0,     0,     0,    33,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    69,    28,    34,
      63,     0,    62,    24,     0,    83,    36,    61,     0,     0,
       0,     0,    60,     0,    39,    41,    43,    44,    48,    49,
      46,    47,    51,    52,    56,    57,    59,    18,    37,    71,
       0,    77,     0,    61,     0,     0,    76,     0,     0,    78
  };

  const short
  Parser::yypgoto_[] =
  {
     -69,   -69,   155,   156,   -69,   -69,   112,   -69,   -24,   -69,
      23,   -40,   -68,   -69,   -69,   -27,    73,    72,     9,    62,
     -17,    20,   -69,   -69,    77,   -69,   -69,   -69,   158,   -12,
     -69,     4
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,     5,     6,     7,    14,    24,    25,    60,    61,    18,
      43,    44,    45,    46,    47,    98,    72,    73,    74,    75,
      76,    77,    49,    50,    99,    51,    52,    53,    20,    21,
      62,    22
  };

  const unsigned char
  Parser::yytable_[] =
  {
      48,   102,    65,    81,     8,     9,   104,    71,    57,     8,
      78,    63,    64,    70,    28,    29,    30,    13,   104,   104,
      26,    48,     1,     2,     3,    19,    48,     1,     2,     3,
      19,   146,    35,    36,    88,    92,    37,    48,    15,    81,
     100,   101,    57,    40,    41,    84,    85,    58,   105,   155,
      81,    16,    48,    56,   104,    23,   119,   109,   110,   121,
     104,    79,    48,    86,   104,    17,    94,    59,    26,    66,
     125,    87,    82,    48,   117,    95,    55,    90,   107,   108,
     129,   111,   112,    83,   130,   113,   114,   157,    10,   150,
     151,     1,     2,     3,     4,   115,   116,    67,   144,   145,
      68,   149,   127,   128,   152,     1,     2,     3,     4,   153,
     128,    69,    48,    48,   156,    91,   136,   137,   159,     1,
       2,     3,    19,   103,     1,     2,     3,    19,    27,    28,
      29,    30,    93,   142,   143,   106,   120,    48,    48,   122,
      31,    48,    32,    33,    34,   124,   126,    35,    36,   104,
     131,    37,   148,   147,    38,    39,   154,   158,    40,    41,
      11,    12,    42,     1,     2,     3,    19,    27,    28,    29,
      30,   138,   139,   140,   141,    54,    96,   134,   135,    31,
     133,    32,    33,    34,     0,     0,    35,    36,     0,     0,
      37,     0,     0,    38,    89,     0,     0,    40,    41,     0,
       0,    42,    27,    28,    29,    30,     0,     0,     0,     0,
       0,     0,     0,     0,    31,     0,    32,    33,    34,     0,
       0,    35,    36,     0,     0,    37,     0,     0,    38,    80,
       0,     0,    40,    41,     0,     0,    42,    27,    28,    29,
      30,     0,     0,     0,     0,     0,     0,     0,     0,    31,
       0,    32,    33,    34,     0,     0,    35,    36,     0,     0,
      37,     0,     0,    38,   118,     0,     0,    40,    41,     0,
       0,    42,    27,    28,    29,    30,     0,     0,     0,     0,
       0,     0,     0,     0,    31,     0,    32,    33,    34,     0,
       0,    35,    36,     0,     0,    37,     0,     0,    38,   123,
       0,     0,    40,    41,     0,     0,    42,    27,    28,    29,
      30,     0,    70,    28,    29,    30,     0,     0,     0,    31,
       0,    32,    33,    34,     0,     0,    35,    36,     0,     0,
      37,    35,    36,    38,     0,    37,    97,    40,    41,     0,
       0,    42,    40,    41,    70,    28,    29,    30,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    35,    36,     0,     0,    37,   132,     0,
       0,     0,     0,     0,    40,    41
  };

  const short
  Parser::yycheck_[] =
  {
      17,    69,    26,    43,     0,     7,    11,    34,    20,     5,
      37,    31,    32,     7,     8,     9,    10,     7,    11,    11,
      16,    38,     3,     4,     5,     6,    43,     3,     4,     5,
       6,    36,    26,    27,    51,    59,    30,    54,    33,    79,
      67,    68,    54,    37,    38,    17,    18,     7,    41,    41,
      90,    30,    69,    34,    11,    31,    83,    15,    16,    86,
      11,    38,    79,    35,    11,    33,    32,    27,    64,    30,
      94,    43,    41,    90,    31,    41,     7,    54,    13,    14,
      31,    39,    40,    29,    31,    25,    26,   155,     0,   129,
     130,     3,     4,     5,     6,    27,    28,    30,   115,   116,
      30,   128,    31,    32,   131,     3,     4,     5,     6,    31,
      32,    30,   129,   130,   154,    41,   107,   108,   158,     3,
       4,     5,     6,    30,     3,     4,     5,     6,     7,     8,
       9,    10,    35,   113,   114,    12,     7,   154,   155,     7,
      19,   158,    21,    22,    23,     8,    41,    26,    27,    11,
      41,    30,    41,    36,    33,    34,    20,    31,    37,    38,
       5,     5,    41,     3,     4,     5,     6,     7,     8,     9,
      10,   109,   110,   111,   112,    17,    64,   104,   106,    19,
     103,    21,    22,    23,    -1,    -1,    26,    27,    -1,    -1,
      30,    -1,    -1,    33,    34,    -1,    -1,    37,    38,    -1,
      -1,    41,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    -1,    21,    22,    23,    -1,
      -1,    26,    27,    -1,    -1,    30,    -1,    -1,    33,    34,
      -1,    -1,    37,    38,    -1,    -1,    41,     7,     8,     9,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      -1,    21,    22,    23,    -1,    -1,    26,    27,    -1,    -1,
      30,    -1,    -1,    33,    34,    -1,    -1,    37,    38,    -1,
      -1,    41,     7,     8,     9,    10,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    -1,    21,    22,    23,    -1,
      -1,    26,    27,    -1,    -1,    30,    -1,    -1,    33,    34,
      -1,    -1,    37,    38,    -1,    -1,    41,     7,     8,     9,
      10,    -1,     7,     8,     9,    10,    -1,    -1,    -1,    19,
      -1,    21,    22,    23,    -1,    -1,    26,    27,    -1,    -1,
      30,    26,    27,    33,    -1,    30,    31,    37,    38,    -1,
      -1,    41,    37,    38,     7,     8,     9,    10,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    26,    27,    -1,    -1,    30,    31,    -1,
      -1,    -1,    -1,    -1,    37,    38
  };

  const signed char
  Parser::yystos_[] =
  {
       0,     3,     4,     5,     6,    45,    46,    47,    75,     7,
       0,    46,    47,     7,    48,    33,    30,    33,    53,     6,
      72,    73,    75,    31,    49,    50,    75,     7,     8,     9,
      10,    19,    21,    22,    23,    26,    27,    30,    33,    34,
      37,    38,    41,    54,    55,    56,    57,    58,    64,    66,
      67,    69,    70,    71,    72,     7,    34,    73,     7,    27,
      51,    52,    74,    31,    32,    52,    30,    30,    30,    30,
       7,    59,    60,    61,    62,    63,    64,    65,    59,    54,
      34,    55,    41,    29,    17,    18,    35,    43,    64,    34,
      54,    41,    52,    35,    32,    41,    50,    31,    59,    68,
      59,    59,    56,    30,    11,    41,    12,    13,    14,    15,
      16,    39,    40,    25,    26,    27,    28,    31,    34,    59,
       7,    59,     7,    34,     8,    52,    41,    31,    32,    31,
      31,    41,    31,    68,    60,    61,    62,    62,    63,    63,
      63,    63,    65,    65,    64,    64,    36,    36,    41,    59,
      55,    55,    59,    31,    20,    41,    55,    56,    31,    55
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    44,    45,    45,    45,    45,    46,    47,    75,    75,
      75,    75,    48,    48,    49,    49,    50,    51,    51,    52,
      52,    53,    53,    53,    53,    54,    54,    55,    55,    55,
      55,    55,    55,    55,    56,    57,    58,    58,    59,    59,
      60,    60,    61,    61,    61,    62,    62,    62,    62,    62,
      63,    63,    63,    64,    64,    65,    65,    65,    66,    66,
      66,    66,    66,    66,    66,    67,    67,    67,    67,    67,
      68,    68,    69,    69,    69,    69,    70,    71,    71,    72,
      72,    73,    74,    74
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     1,     2,     2,     6,     3,     1,     1,
       1,     2,     4,     3,     1,     3,     2,     1,     4,     1,
       2,     2,     3,     3,     4,     1,     2,     1,     3,     1,
       1,     1,     1,     3,     3,     2,     4,     5,     1,     3,
       1,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     2,     1,     3,     3,     1,     4,
       3,     4,     3,     3,     2,     1,     1,     1,     1,     3,
       1,     3,     1,     1,     1,     1,     7,     5,     9,     1,
       2,     3,     1,     3
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
  "translation_unit", "struct_specifier", "function_definition",
  "fun_declarator", "parameter_list", "parameter_declaration",
  "declarator_arr", "declarator", "compound_statement", "statement_list",
  "statement", "assignment_expression", "assignment_statement",
  "procedure_call", "expression", "logical_and_expression",
  "equality_expression", "relational_expression", "additive_expression",
  "unary_expression", "multiplicative_expression", "postfix_expression",
  "primary_expression", "expression_list", "unary_operator",
  "selection_statement", "iteration_statement", "declaration_list",
  "declaration", "declarator_list", "type_specifier", YY_NULLPTR
  };


  const short
  Parser::yyrline_[] =
  {
       0,    88,    88,    91,    94,    97,   102,   105,   108,   110,
     112,   114,   118,   120,   124,   126,   130,   134,   136,   140,
     142,   146,   148,   150,   152,   156,   158,   162,   164,   166,
     168,   170,   172,   174,   178,   182,   186,   188,   192,   194,
     198,   200,   204,   206,   208,   212,   214,   216,   218,   220,
     224,   226,   228,   232,   234,   238,   240,   242,   246,   248,
     250,   252,   254,   256,   258,   262,   265,   268,   271,   275,
     279,   281,   285,   287,   289,   291,   295,   299,   301,   305,
     307,   311,   315,   317
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
#line 2314 "parser.tab.cc"

#line 321 "parser.yy"

//grammar definition.
void IPL::Parser::error( const location_type &l, const std::string &err_message )
{
   std::cerr << "Error: " << err_message << " at " << l << "\n";
}

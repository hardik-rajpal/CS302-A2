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
      case 48: // function_definition
      case 49: // fun_declarator
      case 50: // parameter_list
      case 51: // parameter_declaration
      case 52: // declarator_arr
      case 53: // declarator
      case 54: // compound_statement
      case 55: // statement_list
      case 56: // statement
      case 57: // assignment_expression
      case 58: // assignment_statement
      case 59: // procedure_call
      case 60: // expression
      case 61: // logical_and_expression
      case 62: // equality_expression
      case 63: // relational_expression
      case 64: // additive_expression
      case 65: // unary_expression
      case 66: // multiplicative_expression
      case 67: // postfix_expression
      case 68: // primary_expression
      case 69: // expression_list
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
      case 76: // unary_operator
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
      case 45: // begin_nterm
      case 46: // translation_unit
      case 47: // struct_specifier
      case 48: // function_definition
      case 49: // fun_declarator
      case 50: // parameter_list
      case 51: // parameter_declaration
      case 52: // declarator_arr
      case 53: // declarator
      case 54: // compound_statement
      case 55: // statement_list
      case 56: // statement
      case 57: // assignment_expression
      case 58: // assignment_statement
      case 59: // procedure_call
      case 60: // expression
      case 61: // logical_and_expression
      case 62: // equality_expression
      case 63: // relational_expression
      case 64: // additive_expression
      case 65: // unary_expression
      case 66: // multiplicative_expression
      case 67: // postfix_expression
      case 68: // primary_expression
      case 69: // expression_list
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
      case 76: // unary_operator
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
      case 45: // begin_nterm
      case 46: // translation_unit
      case 47: // struct_specifier
      case 48: // function_definition
      case 49: // fun_declarator
      case 50: // parameter_list
      case 51: // parameter_declaration
      case 52: // declarator_arr
      case 53: // declarator
      case 54: // compound_statement
      case 55: // statement_list
      case 56: // statement
      case 57: // assignment_expression
      case 58: // assignment_statement
      case 59: // procedure_call
      case 60: // expression
      case 61: // logical_and_expression
      case 62: // equality_expression
      case 63: // relational_expression
      case 64: // additive_expression
      case 65: // unary_expression
      case 66: // multiplicative_expression
      case 67: // postfix_expression
      case 68: // primary_expression
      case 69: // expression_list
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
      case 76: // unary_operator
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
      case 45: // begin_nterm
      case 46: // translation_unit
      case 47: // struct_specifier
      case 48: // function_definition
      case 49: // fun_declarator
      case 50: // parameter_list
      case 51: // parameter_declaration
      case 52: // declarator_arr
      case 53: // declarator
      case 54: // compound_statement
      case 55: // statement_list
      case 56: // statement
      case 57: // assignment_expression
      case 58: // assignment_statement
      case 59: // procedure_call
      case 60: // expression
      case 61: // logical_and_expression
      case 62: // equality_expression
      case 63: // relational_expression
      case 64: // additive_expression
      case 65: // unary_expression
      case 66: // multiplicative_expression
      case 67: // postfix_expression
      case 68: // primary_expression
      case 69: // expression_list
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
      case 76: // unary_operator
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
      case 45: // begin_nterm
      case 46: // translation_unit
      case 47: // struct_specifier
      case 48: // function_definition
      case 49: // fun_declarator
      case 50: // parameter_list
      case 51: // parameter_declaration
      case 52: // declarator_arr
      case 53: // declarator
      case 54: // compound_statement
      case 55: // statement_list
      case 56: // statement
      case 57: // assignment_expression
      case 58: // assignment_statement
      case 59: // procedure_call
      case 60: // expression
      case 61: // logical_and_expression
      case 62: // equality_expression
      case 63: // relational_expression
      case 64: // additive_expression
      case 65: // unary_expression
      case 66: // multiplicative_expression
      case 67: // postfix_expression
      case 68: // primary_expression
      case 69: // expression_list
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
      case 76: // unary_operator
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
      case 45: // begin_nterm
      case 46: // translation_unit
      case 47: // struct_specifier
      case 48: // function_definition
      case 49: // fun_declarator
      case 50: // parameter_list
      case 51: // parameter_declaration
      case 52: // declarator_arr
      case 53: // declarator
      case 54: // compound_statement
      case 55: // statement_list
      case 56: // statement
      case 57: // assignment_expression
      case 58: // assignment_statement
      case 59: // procedure_call
      case 60: // expression
      case 61: // logical_and_expression
      case 62: // equality_expression
      case 63: // relational_expression
      case 64: // additive_expression
      case 65: // unary_expression
      case 66: // multiplicative_expression
      case 67: // postfix_expression
      case 68: // primary_expression
      case 69: // expression_list
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
      case 76: // unary_operator
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
      case 45: // begin_nterm
      case 46: // translation_unit
      case 47: // struct_specifier
      case 48: // function_definition
      case 49: // fun_declarator
      case 50: // parameter_list
      case 51: // parameter_declaration
      case 52: // declarator_arr
      case 53: // declarator
      case 54: // compound_statement
      case 55: // statement_list
      case 56: // statement
      case 57: // assignment_expression
      case 58: // assignment_statement
      case 59: // procedure_call
      case 60: // expression
      case 61: // logical_and_expression
      case 62: // equality_expression
      case 63: // relational_expression
      case 64: // additive_expression
      case 65: // unary_expression
      case 66: // multiplicative_expression
      case 67: // postfix_expression
      case 68: // primary_expression
      case 69: // expression_list
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
      case 76: // unary_operator
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
#line 816 "parser.tab.cc"
        break;

      case 4: // INT
#line 17 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 822 "parser.tab.cc"
        break;

      case 5: // FLOAT
#line 18 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 828 "parser.tab.cc"
        break;

      case 6: // STRUCT
#line 19 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 834 "parser.tab.cc"
        break;

      case 7: // IDENTIFIER
#line 20 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 840 "parser.tab.cc"
        break;

      case 8: // INT_CONSTANT
#line 21 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 846 "parser.tab.cc"
        break;

      case 9: // FLOAT_CONSTANT
#line 22 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 852 "parser.tab.cc"
        break;

      case 10: // STRING_LITERAL
#line 23 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 858 "parser.tab.cc"
        break;

      case 11: // OR_OP
#line 24 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 864 "parser.tab.cc"
        break;

      case 12: // AND_OP
#line 25 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 870 "parser.tab.cc"
        break;

      case 13: // EQ_OP
#line 26 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 876 "parser.tab.cc"
        break;

      case 14: // NE_OP
#line 27 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 882 "parser.tab.cc"
        break;

      case 15: // LE_OP
#line 28 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 888 "parser.tab.cc"
        break;

      case 16: // GE_OP
#line 29 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 894 "parser.tab.cc"
        break;

      case 17: // INC_OP
#line 30 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 900 "parser.tab.cc"
        break;

      case 18: // PTR_OP
#line 31 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 906 "parser.tab.cc"
        break;

      case 19: // IF
#line 32 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 912 "parser.tab.cc"
        break;

      case 20: // ELSE
#line 33 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 918 "parser.tab.cc"
        break;

      case 21: // WHILE
#line 34 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 924 "parser.tab.cc"
        break;

      case 22: // FOR
#line 35 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 930 "parser.tab.cc"
        break;

      case 23: // RETURN
#line 36 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 936 "parser.tab.cc"
        break;

      case 24: // OTHERS
#line 37 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 942 "parser.tab.cc"
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
      case 48: // function_definition
      case 49: // fun_declarator
      case 50: // parameter_list
      case 51: // parameter_declaration
      case 52: // declarator_arr
      case 53: // declarator
      case 54: // compound_statement
      case 55: // statement_list
      case 56: // statement
      case 57: // assignment_expression
      case 58: // assignment_statement
      case 59: // procedure_call
      case 60: // expression
      case 61: // logical_and_expression
      case 62: // equality_expression
      case 63: // relational_expression
      case 64: // additive_expression
      case 65: // unary_expression
      case 66: // multiplicative_expression
      case 67: // postfix_expression
      case 68: // primary_expression
      case 69: // expression_list
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
      case 76: // unary_operator
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
#line 1244 "parser.tab.cc"
    break;

  case 3:
#line 92 "parser.yy"
                                  {
}
#line 1251 "parser.tab.cc"
    break;

  case 4:
#line 94 "parser.yy"
                     {
}
#line 1258 "parser.tab.cc"
    break;

  case 5:
#line 96 "parser.yy"
                                   {
}
#line 1265 "parser.tab.cc"
    break;

  case 6:
#line 98 "parser.yy"
                                      {
}
#line 1272 "parser.tab.cc"
    break;

  case 7:
#line 102 "parser.yy"
                                                                {
}
#line 1279 "parser.tab.cc"
    break;

  case 8:
#line 105 "parser.yy"
                                                                     {
}
#line 1286 "parser.tab.cc"
    break;

  case 9:
#line 108 "parser.yy"
                    {
}
#line 1293 "parser.tab.cc"
    break;

  case 10:
#line 110 "parser.yy"
     {
}
#line 1300 "parser.tab.cc"
    break;

  case 11:
#line 112 "parser.yy"
       {
}
#line 1307 "parser.tab.cc"
    break;

  case 12:
#line 114 "parser.yy"
                   {
}
#line 1314 "parser.tab.cc"
    break;

  case 13:
#line 118 "parser.yy"
                                                 {
}
#line 1321 "parser.tab.cc"
    break;

  case 14:
#line 120 "parser.yy"
                    {
}
#line 1328 "parser.tab.cc"
    break;

  case 15:
#line 124 "parser.yy"
                                     {
}
#line 1335 "parser.tab.cc"
    break;

  case 16:
#line 126 "parser.yy"
                                          {
}
#line 1342 "parser.tab.cc"
    break;

  case 17:
#line 130 "parser.yy"
                                                {
}
#line 1349 "parser.tab.cc"
    break;

  case 18:
#line 134 "parser.yy"
                          {
}
#line 1356 "parser.tab.cc"
    break;

  case 19:
#line 136 "parser.yy"
                                     {
}
#line 1363 "parser.tab.cc"
    break;

  case 20:
#line 140 "parser.yy"
                          {
}
#line 1370 "parser.tab.cc"
    break;

  case 21:
#line 142 "parser.yy"
                {
}
#line 1377 "parser.tab.cc"
    break;

  case 22:
#line 146 "parser.yy"
                           {
}
#line 1384 "parser.tab.cc"
    break;

  case 23:
#line 148 "parser.yy"
                        {
}
#line 1391 "parser.tab.cc"
    break;

  case 24:
#line 150 "parser.yy"
                           {
}
#line 1398 "parser.tab.cc"
    break;

  case 25:
#line 152 "parser.yy"
                                         {
}
#line 1405 "parser.tab.cc"
    break;

  case 26:
#line 156 "parser.yy"
                         {
}
#line 1412 "parser.tab.cc"
    break;

  case 27:
#line 158 "parser.yy"
                          {
}
#line 1419 "parser.tab.cc"
    break;

  case 28:
#line 162 "parser.yy"
              {
}
#line 1426 "parser.tab.cc"
    break;

  case 29:
#line 164 "parser.yy"
                        {
}
#line 1433 "parser.tab.cc"
    break;

  case 30:
#line 166 "parser.yy"
                     {
}
#line 1440 "parser.tab.cc"
    break;

  case 31:
#line 168 "parser.yy"
                     {
}
#line 1447 "parser.tab.cc"
    break;

  case 32:
#line 170 "parser.yy"
                      {
}
#line 1454 "parser.tab.cc"
    break;

  case 33:
#line 172 "parser.yy"
                {
}
#line 1461 "parser.tab.cc"
    break;

  case 34:
#line 174 "parser.yy"
                       {
}
#line 1468 "parser.tab.cc"
    break;

  case 35:
#line 178 "parser.yy"
                                                      {
}
#line 1475 "parser.tab.cc"
    break;

  case 36:
#line 182 "parser.yy"
                                               {
}
#line 1482 "parser.tab.cc"
    break;

  case 37:
#line 186 "parser.yy"
                                      {
}
#line 1489 "parser.tab.cc"
    break;

  case 38:
#line 188 "parser.yy"
                                        {
}
#line 1496 "parser.tab.cc"
    break;

  case 39:
#line 192 "parser.yy"
                                  {
}
#line 1503 "parser.tab.cc"
    break;

  case 40:
#line 194 "parser.yy"
                                         {
}
#line 1510 "parser.tab.cc"
    break;

  case 41:
#line 198 "parser.yy"
                                           {
}
#line 1517 "parser.tab.cc"
    break;

  case 42:
#line 200 "parser.yy"
                                                   {
}
#line 1524 "parser.tab.cc"
    break;

  case 43:
#line 204 "parser.yy"
                                          {
}
#line 1531 "parser.tab.cc"
    break;

  case 44:
#line 206 "parser.yy"
                                                  {
    yylhs.value.as < abstract_astnode* > () = new op_binary_astnode("EQ?", yystack_[2].value.as < abstract_astnode* > (), yystack_[0].value.as < abstract_astnode* > ());
}
#line 1539 "parser.tab.cc"
    break;

  case 45:
#line 209 "parser.yy"
                                                 {
    yylhs.value.as < abstract_astnode* > () = new op_binary_astnode("NE?", yystack_[2].value.as < abstract_astnode* > (), yystack_[0].value.as < abstract_astnode* > ());
}
#line 1547 "parser.tab.cc"
    break;

  case 46:
#line 214 "parser.yy"
                                          {
}
#line 1554 "parser.tab.cc"
    break;

  case 47:
#line 216 "parser.yy"
                                               {
    yylhs.value.as < abstract_astnode* > () = new op_binary_astnode("LT?", yystack_[2].value.as < abstract_astnode* > (), yystack_[0].value.as < abstract_astnode* > ());
}
#line 1562 "parser.tab.cc"
    break;

  case 48:
#line 219 "parser.yy"
                                               {
    yylhs.value.as < abstract_astnode* > () = new op_binary_astnode("GT?", yystack_[2].value.as < abstract_astnode* > (), yystack_[0].value.as < abstract_astnode* > ());
}
#line 1570 "parser.tab.cc"
    break;

  case 49:
#line 222 "parser.yy"
                                                 {
    yylhs.value.as < abstract_astnode* > () = new op_binary_astnode("LE?", yystack_[2].value.as < abstract_astnode* > (), yystack_[0].value.as < abstract_astnode* > ());
}
#line 1578 "parser.tab.cc"
    break;

  case 50:
#line 225 "parser.yy"
                                                 {
    yylhs.value.as < abstract_astnode* > () = new op_binary_astnode("GE?", yystack_[2].value.as < abstract_astnode* > (), yystack_[0].value.as < abstract_astnode* > ());
}
#line 1586 "parser.tab.cc"
    break;

  case 51:
#line 230 "parser.yy"
                                              {
}
#line 1593 "parser.tab.cc"
    break;

  case 52:
#line 232 "parser.yy"
                                                   {
    yylhs.value.as < abstract_astnode* > () = new op_binary_astnode("PLUS?", yystack_[2].value.as < abstract_astnode* > (), yystack_[0].value.as < abstract_astnode* > ());
}
#line 1601 "parser.tab.cc"
    break;

  case 53:
#line 235 "parser.yy"
                                                   {
    yylhs.value.as < abstract_astnode* > () = new op_binary_astnode("MINUS?", yystack_[2].value.as < abstract_astnode* > (), yystack_[0].value.as < abstract_astnode* > ());
}
#line 1609 "parser.tab.cc"
    break;

  case 54:
#line 240 "parser.yy"
                                    {
}
#line 1616 "parser.tab.cc"
    break;

  case 55:
#line 242 "parser.yy"
                                 {
    yylhs.value.as < abstract_astnode* > () = new op_unary_astnode(yystack_[1].value.as < std::string > (), yystack_[0].value.as < abstract_astnode* > ());
}
#line 1624 "parser.tab.cc"
    break;

  case 56:
#line 247 "parser.yy"
                                           {
}
#line 1631 "parser.tab.cc"
    break;

  case 57:
#line 249 "parser.yy"
                                                {
    yylhs.value.as < abstract_astnode* > () = new op_binary_astnode("MULT?", yystack_[2].value.as < abstract_astnode* > (), yystack_[0].value.as < abstract_astnode* > ());
}
#line 1639 "parser.tab.cc"
    break;

  case 58:
#line 252 "parser.yy"
                                                {
    yylhs.value.as < abstract_astnode* > () = new op_binary_astnode("DIV?", yystack_[2].value.as < abstract_astnode* > (), yystack_[0].value.as < abstract_astnode* > ());
}
#line 1647 "parser.tab.cc"
    break;

  case 59:
#line 257 "parser.yy"
                                      {
}
#line 1654 "parser.tab.cc"
    break;

  case 60:
#line 259 "parser.yy"
                                       {
}
#line 1661 "parser.tab.cc"
    break;

  case 61:
#line 261 "parser.yy"
                    {
}
#line 1668 "parser.tab.cc"
    break;

  case 62:
#line 263 "parser.yy"
                                    {
}
#line 1675 "parser.tab.cc"
    break;

  case 63:
#line 265 "parser.yy"
                                   {
}
#line 1682 "parser.tab.cc"
    break;

  case 64:
#line 267 "parser.yy"
                                      {
}
#line 1689 "parser.tab.cc"
    break;

  case 65:
#line 269 "parser.yy"
                           {
}
#line 1696 "parser.tab.cc"
    break;

  case 66:
#line 273 "parser.yy"
                              {
    yylhs.value.as < abstract_astnode* > () = new identifier_astnode(yystack_[0].value.as < std::string > ());
}
#line 1704 "parser.tab.cc"
    break;

  case 67:
#line 276 "parser.yy"
              {
    yylhs.value.as < abstract_astnode* > () = new intconst_astnode(yystack_[0].value.as < std::string > ());
}
#line 1712 "parser.tab.cc"
    break;

  case 68:
#line 279 "parser.yy"
                {
    yylhs.value.as < abstract_astnode* > () = new floatconst_astnode(yystack_[0].value.as < std::string > ());
}
#line 1720 "parser.tab.cc"
    break;

  case 69:
#line 282 "parser.yy"
                {
    yylhs.value.as < abstract_astnode* > () = new stringconst_astnode(yystack_[0].value.as < std::string > ());
    yylhs.value.as < abstract_astnode* > ()->print();
}
#line 1729 "parser.tab.cc"
    break;

  case 70:
#line 286 "parser.yy"
                    {
}
#line 1736 "parser.tab.cc"
    break;

  case 71:
#line 290 "parser.yy"
                           {
}
#line 1743 "parser.tab.cc"
    break;

  case 72:
#line 292 "parser.yy"
                                {
}
#line 1750 "parser.tab.cc"
    break;

  case 73:
#line 296 "parser.yy"
                   {
    yylhs.value.as < std::string > () = std::string("UMINUS?");
}
#line 1758 "parser.tab.cc"
    break;

  case 74:
#line 299 "parser.yy"
     {
    yylhs.value.as < std::string > () = std::string("NOT");
}
#line 1766 "parser.tab.cc"
    break;

  case 75:
#line 302 "parser.yy"
     {
    yylhs.value.as < std::string > () = std::string("ADDRESS");
}
#line 1774 "parser.tab.cc"
    break;

  case 76:
#line 305 "parser.yy"
     {
    yylhs.value.as < std::string > () = std::string("DEREF");
}
#line 1782 "parser.tab.cc"
    break;

  case 77:
#line 310 "parser.yy"
                                                                   {
}
#line 1789 "parser.tab.cc"
    break;

  case 78:
#line 314 "parser.yy"
                                                       {
}
#line 1796 "parser.tab.cc"
    break;

  case 79:
#line 316 "parser.yy"
                                                                                      {
}
#line 1803 "parser.tab.cc"
    break;

  case 80:
#line 320 "parser.yy"
                             {
}
#line 1810 "parser.tab.cc"
    break;

  case 81:
#line 322 "parser.yy"
                              {
}
#line 1817 "parser.tab.cc"
    break;

  case 82:
#line 326 "parser.yy"
                                               {
}
#line 1824 "parser.tab.cc"
    break;

  case 83:
#line 330 "parser.yy"
                           {
}
#line 1831 "parser.tab.cc"
    break;

  case 84:
#line 332 "parser.yy"
                                {
}
#line 1838 "parser.tab.cc"
    break;


#line 1842 "parser.tab.cc"

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
     102,   -70,   -70,   -70,    15,    17,   102,   -70,   -70,    60,
      -1,   -70,   -70,   -70,    58,    36,   116,    71,   121,   -70,
      73,    10,   -70,     4,   -70,   -12,   -70,     4,    62,   -70,
     -70,   -70,    67,    81,    93,    56,   -70,   -70,    56,   300,
     -70,   -70,   -70,   -70,   195,   -70,    74,   -70,   -70,   107,
      25,   -70,   -70,   -70,   160,    56,   -70,    98,   -70,   -70,
       4,    68,   -70,    59,   -70,   116,   -70,    20,    56,    56,
      56,   126,    -7,   145,    82,    39,    84,   -70,    57,    14,
     230,   -70,   -70,   -70,    56,   -70,   153,    56,   154,   -70,
     265,   -70,   -70,   -70,   163,     4,   -70,   -70,   131,   162,
      85,    42,    50,   133,   305,    56,   -70,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,   -70,   -70,
     162,   -70,    -3,   -70,   -70,   139,   -70,   -70,   135,    56,
     300,   300,    56,   -70,   114,   145,    82,    39,    39,    84,
      84,    84,    84,    57,    57,   -70,   -70,   -70,   -70,   -70,
     162,   157,   -70,     7,   -70,   300,    56,   -70,   147,   300,
     -70
  };

  const signed char
  Parser::yydefact_[] =
  {
       0,     9,    10,    11,     0,     0,     2,     3,     4,     0,
      12,     1,     5,     6,     0,     0,     0,     0,     0,     8,
       0,     0,    80,     0,    14,     0,    15,     0,    66,    67,
      68,    69,     0,     0,     0,     0,    73,    76,     0,     0,
      22,    74,    75,    28,     0,    26,     0,    32,    33,     0,
      54,    59,    30,    31,     0,     0,    12,     0,    81,    18,
       0,    20,    83,     0,    13,     0,    17,     0,     0,     0,
       0,    66,     0,    39,    41,    43,    46,    56,    51,     0,
       0,    23,    27,    36,     0,    65,     0,     0,     0,    24,
       0,    55,     7,    21,     0,     0,    82,    16,    61,    71,
       0,     0,     0,     0,     0,     0,    34,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    70,    29,
      35,    64,     0,    63,    25,     0,    84,    37,    62,     0,
       0,     0,     0,    61,     0,    40,    42,    44,    45,    49,
      50,    47,    48,    52,    53,    57,    58,    60,    19,    38,
      72,     0,    78,     0,    62,     0,     0,    77,     0,     0,
      79
  };

  const short
  Parser::yypgoto_[] =
  {
     -70,   -70,   -70,   174,   178,   -70,   -70,   120,   -70,   -25,
     -70,   -30,   -41,   -69,   -70,   -70,   -28,    83,    88,    41,
      22,   -18,    38,   -70,   -70,    87,   -70,   -70,   171,   -16,
     -70,     6,   -70
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,     5,     6,     7,     8,    15,    25,    26,    61,    62,
      19,    44,    45,    46,    47,    48,    99,    73,    74,    75,
      76,    77,    78,    50,    51,   100,    52,    53,    21,    22,
      63,    23,    55
  };

  const unsigned char
  Parser::yytable_[] =
  {
      49,   103,    66,    82,   105,    58,     9,    72,   105,    80,
      79,    59,     9,     1,     2,     3,    20,    11,   105,    64,
      65,    49,    10,    27,    90,   105,    49,    71,    29,    30,
      31,    60,    16,   147,   106,    93,    49,    91,    58,    82,
     101,   102,    85,    86,    57,   118,    36,    37,   156,    82,
      38,    98,    49,   105,   110,   111,   120,    41,    42,   122,
      87,   105,    49,    71,    29,    30,    31,    14,    88,    18,
     126,    27,    49,   130,     1,     2,     3,    20,   112,   113,
      56,   131,    36,    37,   116,   117,    38,   158,    17,   151,
     152,    95,    67,    41,    42,   108,   109,    68,   145,   146,
      96,   150,    24,    94,   153,     1,     2,     3,     4,   114,
     115,    69,    49,    49,   157,    83,   128,   129,   160,     1,
       2,     3,    20,    70,     1,     2,     3,    20,    28,    29,
      30,    31,   139,   140,   141,   142,    84,    49,    49,    92,
      32,    49,    33,    34,    35,   154,   129,    36,    37,   137,
     138,    38,   143,   144,    39,    40,   104,   107,    41,    42,
     121,   123,    43,     1,     2,     3,    20,    28,    29,    30,
      31,   125,   127,   105,   132,   148,   149,   155,   159,    32,
      12,    33,    34,    35,    13,    97,    36,    37,   135,    54,
      38,   134,     0,    39,    89,   136,     0,    41,    42,     0,
       0,    43,    28,    29,    30,    31,     0,     0,     0,     0,
       0,     0,     0,     0,    32,     0,    33,    34,    35,     0,
       0,    36,    37,     0,     0,    38,     0,     0,    39,    81,
       0,     0,    41,    42,     0,     0,    43,    28,    29,    30,
      31,     0,     0,     0,     0,     0,     0,     0,     0,    32,
       0,    33,    34,    35,     0,     0,    36,    37,     0,     0,
      38,     0,     0,    39,   119,     0,     0,    41,    42,     0,
       0,    43,    28,    29,    30,    31,     0,     0,     0,     0,
       0,     0,     0,     0,    32,     0,    33,    34,    35,     0,
       0,    36,    37,     0,     0,    38,     0,     0,    39,   124,
       0,     0,    41,    42,     0,     0,    43,    28,    29,    30,
      31,     0,    71,    29,    30,    31,     0,     0,     0,    32,
       0,    33,    34,    35,     0,     0,    36,    37,     0,     0,
      38,    36,    37,    39,     0,    38,   133,    41,    42,     0,
       0,    43,    41,    42
  };

  const short
  Parser::yycheck_[] =
  {
      18,    70,    27,    44,    11,    21,     0,    35,    11,    39,
      38,     7,     6,     3,     4,     5,     6,     0,    11,    31,
      32,    39,     7,    17,    54,    11,    44,     7,     8,     9,
      10,    27,    33,    36,    41,    60,    54,    55,    54,    80,
      68,    69,    17,    18,    34,    31,    26,    27,    41,    90,
      30,    31,    70,    11,    15,    16,    84,    37,    38,    87,
      35,    11,    80,     7,     8,     9,    10,     7,    43,    33,
      95,    65,    90,    31,     3,     4,     5,     6,    39,    40,
       7,    31,    26,    27,    27,    28,    30,   156,    30,   130,
     131,    32,    30,    37,    38,    13,    14,    30,   116,   117,
      41,   129,    31,    35,   132,     3,     4,     5,     6,    25,
      26,    30,   130,   131,   155,    41,    31,    32,   159,     3,
       4,     5,     6,    30,     3,     4,     5,     6,     7,     8,
       9,    10,   110,   111,   112,   113,    29,   155,   156,    41,
      19,   159,    21,    22,    23,    31,    32,    26,    27,   108,
     109,    30,   114,   115,    33,    34,    30,    12,    37,    38,
       7,     7,    41,     3,     4,     5,     6,     7,     8,     9,
      10,     8,    41,    11,    41,    36,    41,    20,    31,    19,
       6,    21,    22,    23,     6,    65,    26,    27,   105,    18,
      30,   104,    -1,    33,    34,   107,    -1,    37,    38,    -1,
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
      -1,    41,    37,    38
  };

  const signed char
  Parser::yystos_[] =
  {
       0,     3,     4,     5,     6,    45,    46,    47,    48,    75,
       7,     0,    47,    48,     7,    49,    33,    30,    33,    54,
       6,    72,    73,    75,    31,    50,    51,    75,     7,     8,
       9,    10,    19,    21,    22,    23,    26,    27,    30,    33,
      34,    37,    38,    41,    55,    56,    57,    58,    59,    65,
      67,    68,    70,    71,    72,    76,     7,    34,    73,     7,
      27,    52,    53,    74,    31,    32,    53,    30,    30,    30,
      30,     7,    60,    61,    62,    63,    64,    65,    66,    60,
      55,    34,    56,    41,    29,    17,    18,    35,    43,    34,
      55,    65,    41,    53,    35,    32,    41,    51,    31,    60,
      69,    60,    60,    57,    30,    11,    41,    12,    13,    14,
      15,    16,    39,    40,    25,    26,    27,    28,    31,    34,
      60,     7,    60,     7,    34,     8,    53,    41,    31,    32,
      31,    31,    41,    31,    69,    61,    62,    63,    63,    64,
      64,    64,    64,    66,    66,    65,    65,    36,    36,    41,
      60,    56,    56,    60,    31,    20,    41,    56,    57,    31,
      56
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    44,    45,    46,    46,    46,    46,    47,    48,    75,
      75,    75,    75,    49,    49,    50,    50,    51,    52,    52,
      53,    53,    54,    54,    54,    54,    55,    55,    56,    56,
      56,    56,    56,    56,    56,    57,    58,    59,    59,    60,
      60,    61,    61,    62,    62,    62,    63,    63,    63,    63,
      63,    64,    64,    64,    65,    65,    66,    66,    66,    67,
      67,    67,    67,    67,    67,    67,    68,    68,    68,    68,
      68,    69,    69,    76,    76,    76,    76,    70,    71,    71,
      72,    72,    73,    74,    74
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
  "begin_nterm", "translation_unit", "struct_specifier",
  "function_definition", "fun_declarator", "parameter_list",
  "parameter_declaration", "declarator_arr", "declarator",
  "compound_statement", "statement_list", "statement",
  "assignment_expression", "assignment_statement", "procedure_call",
  "expression", "logical_and_expression", "equality_expression",
  "relational_expression", "additive_expression", "unary_expression",
  "multiplicative_expression", "postfix_expression", "primary_expression",
  "expression_list", "selection_statement", "iteration_statement",
  "declaration_list", "declaration", "declarator_list", "type_specifier",
  "unary_operator", YY_NULLPTR
  };


  const short
  Parser::yyrline_[] =
  {
       0,    88,    88,    92,    94,    96,    98,   102,   105,   108,
     110,   112,   114,   118,   120,   124,   126,   130,   134,   136,
     140,   142,   146,   148,   150,   152,   156,   158,   162,   164,
     166,   168,   170,   172,   174,   178,   182,   186,   188,   192,
     194,   198,   200,   204,   206,   209,   214,   216,   219,   222,
     225,   230,   232,   235,   240,   242,   247,   249,   252,   257,
     259,   261,   263,   265,   267,   269,   273,   276,   279,   282,
     286,   290,   292,   296,   299,   302,   305,   310,   314,   316,
     320,   322,   326,   330,   332
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
#line 2339 "parser.tab.cc"

#line 336 "parser.yy"

//grammar definition.
void IPL::Parser::error( const location_type &l, const std::string &err_message )
{
   std::cerr << "Error: " << err_message << " at " << l << "\n";
}

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
#line 44 "parser.yy"

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
      case 44: // primary_expression
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
      case 44: // primary_expression
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
      case 44: // primary_expression
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
      case 44: // primary_expression
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
      case 44: // primary_expression
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
      case 44: // primary_expression
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
      case 44: // primary_expression
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
#line 18 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 599 "parser.tab.cc"
        break;

      case 4: // INT
#line 19 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 605 "parser.tab.cc"
        break;

      case 5: // FLOAT
#line 20 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 611 "parser.tab.cc"
        break;

      case 6: // STRUCT
#line 21 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 617 "parser.tab.cc"
        break;

      case 7: // IDENTIFIER
#line 22 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 623 "parser.tab.cc"
        break;

      case 8: // INT_CONSTANT
#line 23 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 629 "parser.tab.cc"
        break;

      case 9: // FLOAT_CONSTANT
#line 24 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 635 "parser.tab.cc"
        break;

      case 10: // STRING_LITERAL
#line 25 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 641 "parser.tab.cc"
        break;

      case 11: // OR_OP
#line 26 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 647 "parser.tab.cc"
        break;

      case 12: // AND_OP
#line 27 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 653 "parser.tab.cc"
        break;

      case 13: // EQ_OP
#line 28 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 659 "parser.tab.cc"
        break;

      case 14: // NE_OP
#line 29 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 665 "parser.tab.cc"
        break;

      case 15: // LE_OP
#line 30 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 671 "parser.tab.cc"
        break;

      case 16: // GE_OP
#line 31 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 677 "parser.tab.cc"
        break;

      case 17: // INC_OP
#line 32 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 683 "parser.tab.cc"
        break;

      case 18: // PTR_OP
#line 33 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 689 "parser.tab.cc"
        break;

      case 19: // IF
#line 34 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 695 "parser.tab.cc"
        break;

      case 20: // ELSE
#line 35 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 701 "parser.tab.cc"
        break;

      case 21: // WHILE
#line 36 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 707 "parser.tab.cc"
        break;

      case 22: // FOR
#line 37 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 713 "parser.tab.cc"
        break;

      case 23: // RETURN
#line 38 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 719 "parser.tab.cc"
        break;

      case 24: // OTHERS
#line 39 "parser.yy"
                 { std::cerr << yysym.value.template as < std::string > (); }
#line 725 "parser.tab.cc"
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
      case 44: // primary_expression
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
#line 94 "parser.yy"
          {
    yylhs.value.as < abstract_astnode* > () = new identifier_astnode(yystack_[0].value.as < std::string > ());
    yylhs.value.as < abstract_astnode* > ()->print();
}
#line 997 "parser.tab.cc"
    break;

  case 3:
#line 98 "parser.yy"
              {
    yylhs.value.as < abstract_astnode* > () = new intconst_astnode(yystack_[0].value.as < std::string > ());
    yylhs.value.as < abstract_astnode* > ()->print();
}
#line 1006 "parser.tab.cc"
    break;

  case 4:
#line 102 "parser.yy"
                {
    yylhs.value.as < abstract_astnode* > () = new floatconst_astnode(yystack_[0].value.as < std::string > ());
    yylhs.value.as < abstract_astnode* > ()->print();
}
#line 1015 "parser.tab.cc"
    break;

  case 5:
#line 106 "parser.yy"
                {
    yylhs.value.as < abstract_astnode* > () = new stringconst_astnode(yystack_[0].value.as < std::string > ());
    yylhs.value.as < abstract_astnode* > ()->print();
}
#line 1024 "parser.tab.cc"
    break;


#line 1028 "parser.tab.cc"

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


  const signed char Parser::yypact_ninf_ = -8;

  const signed char Parser::yytable_ninf_ = -1;

  const signed char
  Parser::yypact_[] =
  {
      -7,    -8,    -8,    -8,    -8,     4,    -8
  };

  const signed char
  Parser::yydefact_[] =
  {
       0,     2,     3,     4,     5,     0,     1
  };

  const signed char
  Parser::yypgoto_[] =
  {
      -8,    -8
  };

  const signed char
  Parser::yydefgoto_[] =
  {
      -1,     5
  };

  const signed char
  Parser::yytable_[] =
  {
       1,     2,     3,     4,     6
  };

  const signed char
  Parser::yycheck_[] =
  {
       7,     8,     9,    10,     0
  };

  const signed char
  Parser::yystos_[] =
  {
       0,     7,     8,     9,    10,    44,     0
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    43,    44,    44,    44,    44
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     1,     1,     1,     1
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
  "'!'", "'&'", "'<'", "'>'", "';'", "'\\n'", "$accept",
  "primary_expression", YY_NULLPTR
  };


  const signed char
  Parser::yyrline_[] =
  {
       0,    94,    94,    98,   102,   106
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
      30,    31,    27,    25,    32,    26,     2,    28,     2,     2,
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
#line 1369 "parser.tab.cc"

#line 111 "parser.yy"

//grammar definition.
void IPL::Parser::error( const location_type &l, const std::string &err_message )
{
   std::cerr << "Error: " << err_message << " at " << l << "\n";
}

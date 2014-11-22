/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.7.12-4996"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "sql.y"

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>  
#include <stdarg.h>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "sqltree.hpp"
#include "error.h"

Parse_Node * root_stmt;

std::stringstream ss;
std::string all_s;

extern int yylex();
void yyerror(char *s, ...);
void emit(char *s, ...);
extern std::string now_db;

/* Line 371 of yacc.c  */
#line 91 "sql.cpp"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "sql.hpp".  */
#ifndef YY_YY_SQL_HPP_INCLUDED
# define YY_YY_SQL_HPP_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NAME = 258,
     STRING = 259,
     INTNUM = 260,
     APPROXNUM = 261,
     OR = 262,
     ANDOP = 263,
     NOT = 264,
     COMPARISON = 265,
     UMINUS = 266,
     AND = 267,
     CREATE = 268,
     DATABASE = 269,
     DATABASES = 270,
     DELETE = 271,
     DROP = 272,
     FLOAT = 273,
     FROM = 274,
     INDEX = 275,
     INSERT = 276,
     INT = 277,
     INTO = 278,
     KEY = 279,
     ON = 280,
     PRIMARY = 281,
     SELECT = 282,
     SHOW = 283,
     USE = 284,
     TABLE = 285,
     TABLES = 286,
     UNIQUE = 287,
     VALUES = 288,
     VARCHAR = 289,
     WHERE = 290,
     EXIT = 291,
     QUIT = 292
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 25 "sql.y"

 
  int intval;
  double floatval;
  char * strval;
  int subtok;
  bool boolval;

  std::string * str;

  std::vector<std::string> *string_list;
  std::vector< std::vector<std::string> > *string_vec;
  Parse_Node* node_p;

  std::vector<Parse_Node*> *node_list;



/* Line 387 of yacc.c  */
#line 190 "sql.cpp"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_SQL_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 218 "sql.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif


/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  36
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   162

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNRULES -- Number of states.  */
#define YYNSTATES  148

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   292

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     9,     2,     2,     2,     2,     2,     2,
      44,    45,    14,    12,    46,    13,     2,    15,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    43,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,    10,    11,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,     8,    10,    12,    14,    16,    18,
      20,    22,    24,    27,    30,    33,    35,    37,    43,    51,
      52,    55,    57,    61,    63,    68,    73,    79,    83,    89,
      91,    95,    97,    99,   101,   103,   107,   116,   123,   125,
     129,   135,   140,   145,   147,   151,   153,   157,   162,   163,
     166,   167,   171,   173,   175,   177,   186,   190,   194,   200,
     202,   204,   206,   208,   212,   216,   220,   224,   227,   231,
     235,   239,   243,   246
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      48,     0,    -1,    49,    43,    -1,    50,    -1,    53,    -1,
      54,    -1,    58,    -1,    59,    -1,    68,    -1,    70,    -1,
      69,    -1,    71,    -1,    34,     3,    -1,    33,    20,    -1,
      33,    36,    -1,    41,    -1,    42,    -1,    32,    52,    24,
       3,    51,    -1,    32,    52,    24,    44,    50,    45,    51,
      -1,    -1,    40,    72,    -1,     3,    -1,    52,    46,     3,
      -1,    14,    -1,    21,    24,     3,    51,    -1,    21,    14,
      24,     3,    -1,    26,    28,     3,    38,    55,    -1,    44,
      56,    45,    -1,    55,    46,    44,    56,    45,    -1,    57,
      -1,    56,    46,    57,    -1,     3,    -1,     4,    -1,     5,
      -1,     6,    -1,    18,    19,     3,    -1,    18,    35,     3,
      44,    63,    46,    60,    45,    -1,    18,    35,     3,    44,
      63,    45,    -1,    61,    -1,    60,    46,    61,    -1,    31,
      29,    44,    62,    45,    -1,    29,    44,    62,    45,    -1,
      25,    44,    62,    45,    -1,     3,    -1,    62,    46,     3,
      -1,    64,    -1,    63,    46,    64,    -1,     3,    67,    66,
      65,    -1,    -1,    65,    37,    -1,    -1,    44,     5,    45,
      -1,    27,    -1,    23,    -1,    39,    -1,    18,    25,     3,
      30,     3,    44,     3,    45,    -1,    22,    19,     3,    -1,
      22,    35,     3,    -1,    22,    25,     3,    30,     3,    -1,
       3,    -1,     4,    -1,     5,    -1,     6,    -1,    72,    12,
      72,    -1,    72,    13,    72,    -1,    72,    14,    72,    -1,
      72,    15,    72,    -1,    13,    72,    -1,    72,     8,    72,
      -1,    72,     7,    72,    -1,    72,    11,    72,    -1,    44,
      72,    45,    -1,    10,    72,    -1,     9,    72,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   129,   129,   135,   140,   141,   142,   143,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   163,   197,   222,
     223,   229,   230,   231,   241,   262,   276,   291,   292,   295,
     297,   300,   301,   302,   309,   319,   328,   351,   370,   375,
     378,   392,   399,   408,   409,   413,   418,   421,   431,   432,
     435,   436,   453,   454,   455,   461,   474,   483,   492,   501,
     504,   505,   508,   511,   512,   513,   514,   515,   516,   517,
     518,   524,   525,   526
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NAME", "STRING", "INTNUM", "APPROXNUM",
  "OR", "ANDOP", "'!'", "NOT", "COMPARISON", "'+'", "'-'", "'*'", "'/'",
  "UMINUS", "AND", "CREATE", "DATABASE", "DATABASES", "DELETE", "DROP",
  "FLOAT", "FROM", "INDEX", "INSERT", "INT", "INTO", "KEY", "ON",
  "PRIMARY", "SELECT", "SHOW", "USE", "TABLE", "TABLES", "UNIQUE",
  "VALUES", "VARCHAR", "WHERE", "EXIT", "QUIT", "';'", "'('", "')'", "','",
  "$accept", "stmt_list", "stmt", "select_stmt", "opt_where",
  "select_expr_list", "delete_stmt", "insert_stmt", "insert_vals_list",
  "insert_vals", "term", "create_database_stmt", "create_table_stmt",
  "create_sp_list", "create_sp", "column_list", "create_col_list",
  "create_definition", "column_atts", "opt_length", "data_type",
  "create_index_stmt", "drop_db_stmt", "drop_table_stmt",
  "drop_index_stmt", "expr", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,    33,
     264,   265,    43,    45,    42,    47,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,    59,    40,    41,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    47,    48,    49,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    50,    50,    51,
      51,    52,    52,    52,    53,    53,    54,    55,    55,    56,
      56,    57,    57,    57,    57,    58,    59,    59,    60,    60,
      61,    61,    61,    62,    62,    63,    63,    64,    65,    65,
      66,    66,    67,    67,    67,    68,    69,    70,    71,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     1,     1,     5,     7,     0,
       2,     1,     3,     1,     4,     4,     5,     3,     5,     1,
       3,     1,     1,     1,     1,     3,     8,     6,     1,     3,
       5,     4,     4,     1,     3,     1,     3,     4,     0,     2,
       0,     3,     1,     1,     1,     8,     3,     3,     5,     1,
       1,     1,     1,     3,     3,     3,     3,     2,     3,     3,
       3,     3,     2,     2
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,    15,    16,
       0,     0,     3,     4,     5,     6,     7,     8,    10,     9,
      11,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      21,    23,     0,    13,    14,    12,     1,     2,    35,     0,
       0,     0,    19,    56,     0,    57,     0,     0,     0,     0,
       0,    25,     0,    24,     0,     0,    19,     0,    22,     0,
       0,     0,    45,    59,    60,    61,    62,     0,     0,     0,
       0,    20,    58,     0,    26,    17,     0,     0,    53,    52,
      54,    50,    37,     0,    73,    72,    67,     0,     0,     0,
       0,     0,     0,     0,     0,    31,    32,    33,    34,     0,
      29,     0,    19,     0,     0,    48,     0,     0,     0,     0,
      38,    46,    71,    69,    68,    70,    63,    64,    65,    66,
      27,     0,     0,    18,    55,     0,    47,     0,     0,     0,
      36,     0,    30,     0,    51,    49,    43,     0,     0,     0,
      39,    28,    42,     0,    41,     0,    44,    40
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    10,    11,    12,    53,    32,    13,    14,    74,    99,
     100,    15,    16,   109,   110,   137,    61,    62,   126,   105,
      81,    17,    18,    19,    20,    71
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -88
static const yytype_int16 yypact[] =
{
      44,   -10,    29,     4,    -7,    37,    -6,    21,   -88,   -88,
      28,     6,   -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,
     -88,    45,    51,    92,    73,   110,   115,   116,   117,   118,
     -88,   -88,   -14,   -88,   -88,   -88,   -88,   -88,   -88,    39,
      78,   120,    84,   -88,    95,   -88,    88,     3,   124,   125,
     126,   -88,    -2,   -88,   127,    87,    84,   100,   -88,    89,
      -1,    18,   -88,   -88,   -88,   -88,   -88,    -2,    -2,    -2,
      -2,    60,   -88,    96,    90,   -88,    93,   131,   -88,   -88,
     -88,    97,   -88,     2,    68,    68,   -88,     5,    -2,    -2,
      -2,    -2,    -2,    -2,    -2,   -88,   -88,   -88,   -88,    48,
     -88,    98,    84,    94,   130,   -88,    99,   101,   108,    62,
     -88,   -88,   -88,    76,    68,    91,    30,    30,   -88,   -88,
     -88,    96,    96,   -88,   -88,   102,   103,   141,   141,   104,
     -88,    67,   -88,    64,   -88,   -88,   -88,    66,    69,   141,
     -88,   -88,   -88,   143,   -88,    71,   -88,   -88
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -88,   -88,   -88,   105,   -56,   -88,   -88,   -88,   -88,    27,
      31,   -88,   -88,   -88,    19,   -87,   -88,    70,   -88,   -88,
     -88,   -88,   -88,   -88,   -88,   -33
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      75,    63,    64,    65,    66,    60,    56,    67,    68,    21,
      47,    69,    88,    89,    33,    22,    90,    91,    92,    93,
      94,    29,    78,    26,    35,    23,    79,   106,    36,    27,
      34,   107,    48,   108,    84,    85,    86,    87,    80,    28,
      30,   138,    70,    24,    93,    94,   123,    57,    38,    37,
     112,    31,   145,    25,    39,   113,   114,   115,   116,   117,
     118,   119,     1,    82,    83,     2,     3,    88,    89,    49,
       4,    90,    91,    92,    93,    94,     5,     6,     7,    90,
      91,    92,    93,    94,    89,     8,     9,    90,    91,    92,
      93,    94,   106,   120,   121,    40,   107,    41,   108,    95,
      96,    97,    98,    91,    92,    93,    94,   130,   131,   141,
     121,   142,   143,    42,   144,   143,   147,   143,    43,    44,
      45,    46,    50,    51,    52,    54,    55,    58,    59,    60,
      72,    73,     5,    77,   103,   125,   101,   129,   102,   124,
     135,   104,   122,   127,   136,   128,   146,   134,   139,   133,
     140,     0,   132,   111,     0,     0,     0,     0,     0,     0,
       0,     0,    76
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-88)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      56,     3,     4,     5,     6,     3,     3,     9,    10,    19,
      24,    13,     7,     8,    20,    25,    11,    12,    13,    14,
      15,    28,    23,    19,     3,    35,    27,    25,     0,    25,
      36,    29,    46,    31,    67,    68,    69,    70,    39,    35,
       3,   128,    44,    14,    14,    15,   102,    44,     3,    43,
      45,    14,   139,    24,     3,    88,    89,    90,    91,    92,
      93,    94,    18,    45,    46,    21,    22,     7,     8,    30,
      26,    11,    12,    13,    14,    15,    32,    33,    34,    11,
      12,    13,    14,    15,     8,    41,    42,    11,    12,    13,
      14,    15,    25,    45,    46,     3,    29,    24,    31,     3,
       4,     5,     6,    12,    13,    14,    15,    45,    46,    45,
      46,    45,    46,     3,    45,    46,    45,    46,     3,     3,
       3,     3,    44,     3,    40,    30,    38,     3,     3,     3,
       3,    44,    32,    44,     3,     5,    46,    29,    45,    45,
      37,    44,    44,    44,     3,    44,     3,    45,    44,   122,
     131,    -1,   121,    83,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    57
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    18,    21,    22,    26,    32,    33,    34,    41,    42,
      48,    49,    50,    53,    54,    58,    59,    68,    69,    70,
      71,    19,    25,    35,    14,    24,    19,    25,    35,    28,
       3,    14,    52,    20,    36,     3,     0,    43,     3,     3,
       3,    24,     3,     3,     3,     3,     3,    24,    46,    30,
      44,     3,    40,    51,    30,    38,     3,    44,     3,     3,
       3,    63,    64,     3,     4,     5,     6,     9,    10,    13,
      44,    72,     3,    44,    55,    51,    50,    44,    23,    27,
      39,    67,    45,    46,    72,    72,    72,    72,     7,     8,
      11,    12,    13,    14,    15,     3,     4,     5,     6,    56,
      57,    46,    45,     3,    44,    66,    25,    29,    31,    60,
      61,    64,    45,    72,    72,    72,    72,    72,    72,    72,
      45,    46,    44,    51,    45,     5,    65,    44,    44,    29,
      45,    46,    57,    56,    45,    37,     3,    62,    62,    44,
      61,    45,    45,    46,    45,    62,     3,    45
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YYUSE (yytype);
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
/* Line 1787 of yacc.c  */
#line 129 "sql.y"
    {root_stmt=(yyvsp[(1) - (2)].node_p);YYACCEPT;}
    break;

  case 3:
/* Line 1787 of yacc.c  */
#line 135 "sql.y"
    {
        (yyval.node_p)=new SELECT_NODE;*(yyval.node_p)=*(yyvsp[(1) - (1)].node_p);
        //std::cout<<"in select stmt"<<std::endl;
        //std::cout<<$$->select_list[0]<<std::endl;
    }
    break;

  case 4:
/* Line 1787 of yacc.c  */
#line 140 "sql.y"
    {(yyval.node_p)=new DELETE_NODE;*(yyval.node_p)=*(yyvsp[(1) - (1)].node_p);}
    break;

  case 5:
/* Line 1787 of yacc.c  */
#line 141 "sql.y"
    {(yyval.node_p)=new INSERT_NODE;*(yyval.node_p)=*(yyvsp[(1) - (1)].node_p);}
    break;

  case 6:
/* Line 1787 of yacc.c  */
#line 142 "sql.y"
    {(yyval.node_p)=new CREATE_DATABASE_NODE;*(yyval.node_p)=*(yyvsp[(1) - (1)].node_p);}
    break;

  case 7:
/* Line 1787 of yacc.c  */
#line 143 "sql.y"
    {
        (yyval.node_p)=new CREATE_TABLE_NODE;
        *(yyval.node_p)=*(yyvsp[(1) - (1)].node_p);
        //std::cout<<$$->attr_list[0]->attr_name<<std::endl;
        //std::cout<<$$->attr_list[0]->char_length<<std::endl;
        //std::cout<<$$->sp_list[0]->key_type<<std::endl;
        //std::cout<<$$->sp_list[0]->key_attr[0]<<std::endl;
   }
    break;

  case 8:
/* Line 1787 of yacc.c  */
#line 151 "sql.y"
    {(yyval.node_p)=new CREATE_INDEX_NODE;*(yyval.node_p)=*(yyvsp[(1) - (1)].node_p);}
    break;

  case 9:
/* Line 1787 of yacc.c  */
#line 152 "sql.y"
    {(yyval.node_p)=new DROP_TABLE_NODE;*(yyval.node_p)=*(yyvsp[(1) - (1)].node_p);}
    break;

  case 10:
/* Line 1787 of yacc.c  */
#line 153 "sql.y"
    {(yyval.node_p)=new DROP_DATABASE_NODE;*(yyval.node_p)=*(yyvsp[(1) - (1)].node_p);}
    break;

  case 11:
/* Line 1787 of yacc.c  */
#line 154 "sql.y"
    {(yyval.node_p)=new DROP_INDEX_NODE;*(yyval.node_p)=*(yyvsp[(1) - (1)].node_p);}
    break;

  case 12:
/* Line 1787 of yacc.c  */
#line 155 "sql.y"
    {(yyval.node_p)=new USE_DATABASE_NODE;(yyval.node_p)->now_db=std::string((yyvsp[(2) - (2)].strval));}
    break;

  case 13:
/* Line 1787 of yacc.c  */
#line 156 "sql.y"
    {(yyval.node_p)=new SHOW_DATABASE_NODE;(yyval.node_p)->show_flag=true;}
    break;

  case 14:
/* Line 1787 of yacc.c  */
#line 157 "sql.y"
    {(yyval.node_p)=new SHOW_TABLE_NODE;(yyval.node_p)->show_flag=true;}
    break;

  case 15:
/* Line 1787 of yacc.c  */
#line 158 "sql.y"
    {Exit exit;throw exit;}
    break;

  case 16:
/* Line 1787 of yacc.c  */
#line 159 "sql.y"
    {Exit exit;throw exit;}
    break;

  case 17:
/* Line 1787 of yacc.c  */
#line 165 "sql.y"
    {
      (yyval.node_p)=new SELECT_NODE;
      (yyval.node_p)->select_list=*(yyvsp[(2) - (5)].string_list);
      free((yyvsp[(2) - (5)].string_list));

      //std::cout<<$$->select_list[0]<<std::endl;
      //std::cout<<$$->select_list[1]<<std::endl;
      //std::cout<<<<std::endl;

      //std::cout<<$4->select_tbl_list[0]<<std::endl;
      //std::cout<<$4->select_tbl_list[1]<<std::endl;

      std::string all_s((yyvsp[(4) - (5)].strval));NAME_NODE *n=new NAME_NODE(all_s);
      (yyval.node_p)->select_from_clause.push_back(n);
      //std::cout<<$$->select_from_clause[0]->kind<<std::endl;
      //std::cout<<$$->select_from_clause[0]->name<<std::endl;
      free((yyvsp[(4) - (5)].strval));
      //std::cout<<$$->select_tbl_list[0]<<std::endl;
      //std::cout<<$$->select_tbl_list[1]<<std::endl;
      

      //std::cout<<$5->cmp<<std::endl;
      if((yyvsp[(5) - (5)].node_p)==NULL){
        //std::cout<<"null"<<std::endl;
        (yyval.node_p)->select_where_clause=NULL;
      }
      else{
        (yyval.node_p)->select_where_clause=(yyvsp[(5) - (5)].node_p);
        //std::cout<<$$->select_where_clause->cmp<<std::endl;
        //std::cout<<$$->select_where_clause->l->name<<std::endl;
      } 
    }
    break;

  case 18:
/* Line 1787 of yacc.c  */
#line 199 "sql.y"
    {
        (yyval.node_p)=new SELECT_NODE;
        (yyval.node_p)->select_list=*(yyvsp[(2) - (7)].string_list);
        free((yyvsp[(2) - (7)].string_list));

        //std::cout<<"begin"<<std::endl;
        (yyval.node_p)->select_from_clause.push_back((yyvsp[(5) - (7)].node_p));
        //std::cout<<$$->select_from_clause[0]->kind<<std::endl;
        //std::cout<<$$->select_from_clause[0]->select_list[0]<<std::endl;

        if((yyvsp[(7) - (7)].node_p)==NULL)
        {
            //std::cout<<"null"<<std::endl;
            (yyval.node_p)->select_where_clause=NULL;
        }
        else
        {
            (yyval.node_p)->select_where_clause=(yyvsp[(7) - (7)].node_p);
        }

     }
    break;

  case 19:
/* Line 1787 of yacc.c  */
#line 222 "sql.y"
    {(yyval.node_p)=NULL;}
    break;

  case 20:
/* Line 1787 of yacc.c  */
#line 223 "sql.y"
    {(yyval.node_p)=(yyvsp[(2) - (2)].node_p);
    //std::cout<<$$->cmp<<std::endl;
    }
    break;

  case 21:
/* Line 1787 of yacc.c  */
#line 229 "sql.y"
    {(yyval.string_list)=new std::vector<std::string>;(yyval.string_list)->push_back((yyvsp[(1) - (1)].strval));}
    break;

  case 22:
/* Line 1787 of yacc.c  */
#line 230 "sql.y"
    {(yyval.string_list)->push_back((yyvsp[(3) - (3)].strval));}
    break;

  case 23:
/* Line 1787 of yacc.c  */
#line 231 "sql.y"
    {(yyval.string_list)=new std::vector<std::string>;(yyval.string_list)->push_back("select_all_flag");}
    break;

  case 24:
/* Line 1787 of yacc.c  */
#line 242 "sql.y"
    {
      //emit("hello");
      (yyval.node_p)=new DELETE_NODE;

      (yyval.node_p)->del_tbl_name=std::string((yyvsp[(3) - (4)].strval));
      free((yyvsp[(3) - (4)].strval));
      //std::cout<<$$->select_tbl_list[0]<<std::endl;
      //std::cout<<$$->select_tbl_list[1]<<std::endl;
      //std::cout<<"parse_delete"<<std::endl;
      //std::cout<<$4->cmp<<std::endl;
      if((yyvsp[(4) - (4)].node_p)==NULL){
        Error error(18,"expected where clause!");
        throw error;
      }
      else{
        (yyval.node_p)->del_where_clause=(yyvsp[(4) - (4)].node_p);
        //std::cout<<$$->del_where_clause->cmp<<std::endl;
        //std::cout<<$$->del_where_clause->l->name<<std::endl;
      }  
    }
    break;

  case 25:
/* Line 1787 of yacc.c  */
#line 262 "sql.y"
    {
        //emit("wtf!");
        (yyval.node_p)=new DELETE_NODE;

        (yyval.node_p)->del_tbl_name=std::string((yyvsp[(4) - (4)].strval));
        free((yyvsp[(4) - (4)].strval));

        //std::cout<<$$->del_tbl_list[0]<<std::endl;

        (yyval.node_p)->star_flag=true;
    }
    break;

  case 26:
/* Line 1787 of yacc.c  */
#line 277 "sql.y"
    {
        (yyval.node_p)=new INSERT_NODE;

        (yyval.node_p)->insert_tbl_name=std::string((yyvsp[(3) - (5)].strval));
        //std::cout<<$$->insert_tbl_list[0]<<std::endl;
        free((yyvsp[(3) - (5)].strval));

        (yyval.node_p)->insert_value_list=*(yyvsp[(5) - (5)].string_vec);
        //std::cout<<$$->value_list[0][0]<<std::endl;
        //std::cout<<$$->value_list[1][0]<<std::endl;
        free((yyvsp[(5) - (5)].string_vec));
    }
    break;

  case 27:
/* Line 1787 of yacc.c  */
#line 291 "sql.y"
    {(yyval.string_vec)=new std::vector<std::vector<std::string> >;(yyval.string_vec)->push_back(*(yyvsp[(2) - (3)].string_list));delete (yyvsp[(2) - (3)].string_list);}
    break;

  case 28:
/* Line 1787 of yacc.c  */
#line 292 "sql.y"
    {(yyval.string_vec)->push_back(*(yyvsp[(4) - (5)].string_list));free((yyvsp[(4) - (5)].string_list));}
    break;

  case 29:
/* Line 1787 of yacc.c  */
#line 295 "sql.y"
    {(yyval.string_list)=new std::vector<std::string>;
    (yyval.string_list)->push_back(*(yyvsp[(1) - (1)].str));}
    break;

  case 30:
/* Line 1787 of yacc.c  */
#line 297 "sql.y"
    {(yyval.string_list)->push_back(*(yyvsp[(3) - (3)].str));}
    break;

  case 31:
/* Line 1787 of yacc.c  */
#line 300 "sql.y"
    {(yyval.str)=new std::string((yyvsp[(1) - (1)].strval));}
    break;

  case 32:
/* Line 1787 of yacc.c  */
#line 301 "sql.y"
    {(yyval.str)=new std::string((yyvsp[(1) - (1)].strval));}
    break;

  case 33:
/* Line 1787 of yacc.c  */
#line 302 "sql.y"
    {
    std::stringstream ss;
    (yyval.str)=new std::string;
    ss<<(yyvsp[(1) - (1)].intval);
    ss>>*(yyval.str);
    //std::cout<<*$$<<std::endl;
   }
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 309 "sql.y"
    {
    std::stringstream ss;
    (yyval.str)=new std::string;
    ss<<(yyvsp[(1) - (1)].floatval);ss>>*(yyval.str);
    //std::cout<<*$$<<std::endl;
    }
    break;

  case 35:
/* Line 1787 of yacc.c  */
#line 319 "sql.y"
    {
        (yyval.node_p)=new CREATE_DATABASE_NODE;
        (yyval.node_p)->create_db_name=std::string((yyvsp[(3) - (3)].strval));
        //std::cout<<$$->db_name<<std::endl;
        free((yyvsp[(3) - (3)].strval));
    }
    break;

  case 36:
/* Line 1787 of yacc.c  */
#line 330 "sql.y"
    {
        (yyval.node_p)=new CREATE_TABLE_NODE; 
        (yyval.node_p)->create_tbl_name=std::string((yyvsp[(3) - (8)].strval));

        if((yyvsp[(5) - (8)].node_list)->size()>32)
        {
          Error error(18,"More than 32 attributes!");
          throw error;
          
        }
        (yyval.node_p)->attr_list=*(yyvsp[(5) - (8)].node_list);
        //std::cout<<$$->attr_list[0]->attr_name<<std::endl;
        //std::cout<<$$->attr_list[0]->char_length<<std::endl;

        (yyval.node_p)->sp_list=*(yyvsp[(7) - (8)].node_list);
        //std::cout<<$$->sp_list[0]->key_type<<std::endl;
        //std::cout<<$$->sp_list[0]->key_attr[0]<<std::endl;

        free((yyvsp[(7) - (8)].node_list));
        free((yyvsp[(5) - (8)].node_list));
    }
    break;

  case 37:
/* Line 1787 of yacc.c  */
#line 352 "sql.y"
    {
        (yyval.node_p)=new CREATE_TABLE_NODE; 
        (yyval.node_p)->create_tbl_name=std::string((yyvsp[(3) - (6)].strval));

        if((yyvsp[(5) - (6)].node_list)->size()>32)
        {
          Error error(18,"More than 32 attributes!");
          throw error;
          
        }
        (yyval.node_p)->attr_list=*(yyvsp[(5) - (6)].node_list);
        //std::cout<<$$->attr_list[0]->attr_name<<std::endl;
        //std::cout<<$$->attr_list[0]->char_length<<std::endl;

        free((yyvsp[(5) - (6)].node_list));
    }
    break;

  case 38:
/* Line 1787 of yacc.c  */
#line 371 "sql.y"
    {
            (yyval.node_list)=new std::vector<Parse_Node *>;
            (yyval.node_list)->push_back((yyvsp[(1) - (1)].node_p));
        }
    break;

  case 39:
/* Line 1787 of yacc.c  */
#line 375 "sql.y"
    {(yyval.node_list)->push_back((yyvsp[(3) - (3)].node_p));}
    break;

  case 40:
/* Line 1787 of yacc.c  */
#line 379 "sql.y"
    {
        (yyval.node_p)=new SPECIAL_ATTR_NODE;
        (yyval.node_p)->key_type=0;
        (yyval.node_p)->key_attr=*(yyvsp[(4) - (5)].string_list);
        //emit("primary key %d",$$->key_attr.size());
        if((yyval.node_p)->key_attr.size()>1)
        {
          Error error(18,"More than 2 primary keys");
          throw error;
          
        }
        free((yyvsp[(4) - (5)].string_list));
    }
    break;

  case 41:
/* Line 1787 of yacc.c  */
#line 393 "sql.y"
    {
        (yyval.node_p)=new SPECIAL_ATTR_NODE;
        (yyval.node_p)->key_type=1;
        (yyval.node_p)->key_attr=*(yyvsp[(3) - (4)].string_list);
        free((yyvsp[(3) - (4)].string_list));
    }
    break;

  case 42:
/* Line 1787 of yacc.c  */
#line 400 "sql.y"
    {   
        (yyval.node_p)=new SPECIAL_ATTR_NODE;
        (yyval.node_p)->key_type=2;
        (yyval.node_p)->key_attr=*(yyvsp[(3) - (4)].string_list);
        free((yyvsp[(3) - (4)].string_list));
    }
    break;

  case 43:
/* Line 1787 of yacc.c  */
#line 408 "sql.y"
    {(yyval.string_list)=new std::vector<std::string>;(yyval.string_list)->push_back((yyvsp[(1) - (1)].strval)); }
    break;

  case 44:
/* Line 1787 of yacc.c  */
#line 409 "sql.y"
    {(yyval.string_list)->push_back((yyvsp[(3) - (3)].strval)); }
    break;

  case 45:
/* Line 1787 of yacc.c  */
#line 414 "sql.y"
    {
        (yyval.node_list)=new std::vector<Parse_Node *>;
        (yyval.node_list)->push_back((yyvsp[(1) - (1)].node_p));
    }
    break;

  case 46:
/* Line 1787 of yacc.c  */
#line 418 "sql.y"
    {(yyval.node_list)->push_back((yyvsp[(3) - (3)].node_p));}
    break;

  case 47:
/* Line 1787 of yacc.c  */
#line 422 "sql.y"
    {
                (yyval.node_p)=new ATTR_NODE;
                (yyval.node_p)->attr_name=std::string((yyvsp[(1) - (4)].strval));
                (yyval.node_p)->type=(yyvsp[(2) - (4)].intval);
                (yyval.node_p)->char_length=(yyvsp[(3) - (4)].intval);
                (yyval.node_p)->unique_flag=(yyvsp[(4) - (4)].boolval);
            }
    break;

  case 48:
/* Line 1787 of yacc.c  */
#line 431 "sql.y"
    {(yyval.boolval)=false;}
    break;

  case 49:
/* Line 1787 of yacc.c  */
#line 432 "sql.y"
    {(yyval.boolval)=true;}
    break;

  case 50:
/* Line 1787 of yacc.c  */
#line 435 "sql.y"
    {(yyval.intval)=0;}
    break;

  case 51:
/* Line 1787 of yacc.c  */
#line 437 "sql.y"
    {   
      if((yyvsp[(2) - (3)].intval)>=1&&(yyvsp[(2) - (3)].intval)<=255)
      {
        (yyval.intval) = (yyvsp[(2) - (3)].intval); 
      }
      else
      {
        Error error(18,"out of char range(1~255)!");
        throw error;
        
        //Error error(6);
        //throw error;
      }
    }
    break;

  case 52:
/* Line 1787 of yacc.c  */
#line 453 "sql.y"
    { (yyval.intval) = 0; }
    break;

  case 53:
/* Line 1787 of yacc.c  */
#line 454 "sql.y"
    { (yyval.intval) = 1; }
    break;

  case 54:
/* Line 1787 of yacc.c  */
#line 455 "sql.y"
    { (yyval.intval) = 2; }
    break;

  case 55:
/* Line 1787 of yacc.c  */
#line 461 "sql.y"
    {
        (yyval.node_p)=new CREATE_INDEX_NODE;
        (yyval.node_p)->create_index_name=std::string((yyvsp[(3) - (8)].strval));
        (yyval.node_p)->create_index_tbl=std::string((yyvsp[(5) - (8)].strval));
        (yyval.node_p)->create_index_attr=std::string((yyvsp[(7) - (8)].strval));
        //dropstd::cout<<$$->create_index_name<<std::endl;
        free((yyvsp[(3) - (8)].strval));
        free((yyvsp[(5) - (8)].strval));
        free((yyvsp[(7) - (8)].strval));
    }
    break;

  case 56:
/* Line 1787 of yacc.c  */
#line 474 "sql.y"
    {
        (yyval.node_p)=new DROP_DATABASE_NODE;
        (yyval.node_p)->drop_db_name=std::string((yyvsp[(3) - (3)].strval));
        //std::cout<<$$->drop_db_name<<std::endl;
        free((yyvsp[(3) - (3)].strval));
    }
    break;

  case 57:
/* Line 1787 of yacc.c  */
#line 483 "sql.y"
    {
        (yyval.node_p)=new DROP_TABLE_NODE;
        (yyval.node_p)->drop_tbl_name=std::string((yyvsp[(3) - (3)].strval));
        std::cout<<(yyval.node_p)->drop_tbl_name<<std::endl;
        free((yyvsp[(3) - (3)].strval));
    }
    break;

  case 58:
/* Line 1787 of yacc.c  */
#line 492 "sql.y"
    {
        (yyval.node_p)=new DROP_INDEX_NODE;
        (yyval.node_p)->drop_index_name=std::string((yyvsp[(3) - (5)].strval));
        (yyval.node_p)->drop_index_tbl=std::string((yyvsp[(5) - (5)].strval));
        //std::cout<<$$->drop_index_name<<std::endl;
    }
    break;

  case 59:
/* Line 1787 of yacc.c  */
#line 501 "sql.y"
    {std::string all_s((yyvsp[(1) - (1)].strval));(yyval.node_p)=new NAME_NODE(all_s);
    //std::cout<<$$->name<<std::endl;
    }
    break;

  case 60:
/* Line 1787 of yacc.c  */
#line 504 "sql.y"
    {std::string all_s((yyvsp[(1) - (1)].strval));(yyval.node_p)=new STRING_NODE(all_s);}
    break;

  case 61:
/* Line 1787 of yacc.c  */
#line 505 "sql.y"
    {(yyval.node_p)=new INT_NODE((yyvsp[(1) - (1)].intval));
    //std::cout<<$$->int_num<<std::endl;
    }
    break;

  case 62:
/* Line 1787 of yacc.c  */
#line 508 "sql.y"
    {(yyval.node_p)=new FLOAT_NODE((yyvsp[(1) - (1)].floatval));}
    break;

  case 63:
/* Line 1787 of yacc.c  */
#line 511 "sql.y"
    {(yyval.node_p)=new FORMULA_NODE(7,(yyvsp[(1) - (3)].node_p),(yyvsp[(3) - (3)].node_p));}
    break;

  case 64:
/* Line 1787 of yacc.c  */
#line 512 "sql.y"
    {(yyval.node_p)=new FORMULA_NODE(8,(yyvsp[(1) - (3)].node_p),(yyvsp[(3) - (3)].node_p));}
    break;

  case 65:
/* Line 1787 of yacc.c  */
#line 513 "sql.y"
    {(yyval.node_p)=new FORMULA_NODE(9,(yyvsp[(1) - (3)].node_p),(yyvsp[(3) - (3)].node_p));}
    break;

  case 66:
/* Line 1787 of yacc.c  */
#line 514 "sql.y"
    {(yyval.node_p)=new FORMULA_NODE(10,(yyvsp[(1) - (3)].node_p),(yyvsp[(3) - (3)].node_p));}
    break;

  case 67:
/* Line 1787 of yacc.c  */
#line 515 "sql.y"
    {(yyval.node_p)=new FORMULA_NODE(11,(yyvsp[(2) - (2)].node_p),NULL);}
    break;

  case 68:
/* Line 1787 of yacc.c  */
#line 516 "sql.y"
    {(yyval.node_p)=new FORMULA_NODE(12,(yyvsp[(1) - (3)].node_p),(yyvsp[(3) - (3)].node_p));}
    break;

  case 69:
/* Line 1787 of yacc.c  */
#line 517 "sql.y"
    {(yyval.node_p)=new FORMULA_NODE(13,(yyvsp[(1) - (3)].node_p),(yyvsp[(3) - (3)].node_p));}
    break;

  case 70:
/* Line 1787 of yacc.c  */
#line 518 "sql.y"
    {
    //$$=new FORMULA_NODE;//do not must
    (yyval.node_p)=new FORMULA_NODE((yyvsp[(2) - (3)].subtok),(yyvsp[(1) - (3)].node_p),(yyvsp[(3) - (3)].node_p));
    //std::cout<<$$->cmp<<std::endl;
    //std::cout<<$$->l->name<<std::endl;
  }
    break;

  case 71:
/* Line 1787 of yacc.c  */
#line 524 "sql.y"
    {(yyval.node_p)=(yyvsp[(2) - (3)].node_p);}
    break;

  case 72:
/* Line 1787 of yacc.c  */
#line 525 "sql.y"
    {(yyval.node_p)=new FORMULA_NODE(14,(yyvsp[(2) - (2)].node_p),NULL);}
    break;

  case 73:
/* Line 1787 of yacc.c  */
#line 526 "sql.y"
    {(yyval.node_p)=new FORMULA_NODE(14,(yyvsp[(2) - (2)].node_p),NULL);}
    break;


/* Line 1787 of yacc.c  */
#line 2210 "sql.cpp"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2050 of yacc.c  */
#line 529 "sql.y"


void
emit(char *s, ...)
{
  extern int yylineno;

  va_list ap;
  va_start(ap, s);

  vfprintf(stdout, s, ap);
  printf("\n");
}

void
yyerror(char *s, ...)
{
  extern int yylineno;

  //va_list ap;
  //va_start(ap, s);

  //fprintf(stderr, "%d: error: ", yylineno);
  //vfprintf(stderr, s, ap);
  //fprintf(stderr, "\n");
}


Parse_Node *
yyy_parse(char *av="std")
{
  extern FILE *yyin;
  if (av!="std")
  {
    if((yyin = fopen(av, "r")) == NULL) {
      perror(av);
      exit(1);
    }
  }
  if(!yyparse())
  {
    //printf("SQL parse worked\n");
    return root_stmt;
  }
  else
  {
    printf("SQL parse failed\n");
    return NULL;                      
  }
}  
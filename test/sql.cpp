/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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
     SHIFT = 266,
     MOD = 267,
     UMINUS = 268,
     AND = 269,
     CREATE = 270,
     DATABASE = 271,
     DATABASES = 272,
     DELETE = 273,
     DROP = 274,
     FLOAT = 275,
     FROM = 276,
     INDEX = 277,
     INSERT = 278,
     INT = 279,
     INTO = 280,
     KEY = 281,
     ON = 282,
     PRIMARY = 283,
     SELECT = 284,
     SHOW = 285,
     TABLE = 286,
     UNIQUE = 287,
     VALUES = 288,
     VARCHAR = 289,
     WHERE = 290
   };
#endif
/* Tokens.  */
#define NAME 258
#define STRING 259
#define INTNUM 260
#define APPROXNUM 261
#define OR 262
#define ANDOP 263
#define NOT 264
#define COMPARISON 265
#define SHIFT 266
#define MOD 267
#define UMINUS 268
#define AND 269
#define CREATE 270
#define DATABASE 271
#define DATABASES 272
#define DELETE 273
#define DROP 274
#define FLOAT 275
#define FROM 276
#define INDEX 277
#define INSERT 278
#define INT 279
#define INTO 280
#define KEY 281
#define ON 282
#define PRIMARY 283
#define SELECT 284
#define SHOW 285
#define TABLE 286
#define UNIQUE 287
#define VALUES 288
#define VARCHAR 289
#define WHERE 290




/* Copy the first part of user declarations.  */
#line 11 "sql.y"

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>  
#include <stdarg.h>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "sqltree.hpp"


std::stringstream ss;
std::string all_s;

extern int yylex();
void yyerror(char *s, ...);
void emit(char *s, ...);


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 32 "sql.y"
{
 
  int intval;
  double floatval;
  char * strval;
  int subtok;

  std::string * str;

  std::vector<std::string> *string_list;
  std::vector< std::vector<std::string> > *string_vec;
  node* node_p;
 
  //INT_NODE * int_node_p;
  //FLOAT_NODE * float_node_p;
  //NAME_NODE * name_node_p;
  //STRING_NODE * str_node_p;
  //FORMULA_NODE * formula_node_p;
  //vector <node> name_list;  
}
/* Line 193 of yacc.c.  */
#line 207 "sql.cpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 220 "sql.cpp"

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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
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
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  29
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   164

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNRULES -- Number of states.  */
#define YYNSTATES  150

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   290

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     9,     2,     2,     2,    19,    13,     2,
      46,    47,    17,    15,    48,    16,     2,    18,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    45,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    21,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    12,     2,     2,     2,     2,     2,
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
       5,     6,     7,     8,    10,    11,    14,    20,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,    10,    12,    18,    26,    27,    30,
      32,    36,    38,    40,    44,    46,    51,    56,    58,    64,
      68,    74,    76,    80,    82,    84,    86,    88,    90,    94,
      96,   103,   105,   109,   110,   115,   121,   126,   131,   132,
     138,   142,   146,   149,   151,   155,   156,   160,   161,   163,
     165,   168,   170,   179,   181,   185,   187,   191,   193,   199,
     201,   203,   205,   207,   211,   215,   219,   223,   227,   231,
     234,   238,   242,   246,   249
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      50,     0,    -1,    51,    45,    -1,    50,    51,    45,    -1,
      52,    -1,    38,    54,    30,    55,    53,    -1,    38,    54,
      30,    46,    52,    47,    53,    -1,    -1,    44,    74,    -1,
       3,    -1,    54,    48,     3,    -1,    17,    -1,     3,    -1,
      55,    48,     3,    -1,    56,    -1,    27,    30,    55,    53,
      -1,    27,    17,    30,    55,    -1,    57,    -1,    32,    34,
      55,    42,    58,    -1,    46,    59,    47,    -1,    58,    48,
      46,    59,    47,    -1,    60,    -1,    59,    48,    60,    -1,
       3,    -1,     4,    -1,     5,    -1,     6,    -1,    61,    -1,
      24,    25,     3,    -1,    62,    -1,    24,    40,     3,    46,
      63,    47,    -1,    64,    -1,    63,    48,    64,    -1,    -1,
      65,     3,    69,    66,    -1,    37,    35,    46,    67,    47,
      -1,    35,    46,    67,    47,    -1,    31,    46,    67,    47,
      -1,    -1,    66,    41,    46,    67,    47,    -1,    66,    41,
      35,    -1,    66,    37,    35,    -1,    66,    35,    -1,     3,
      -1,    67,    48,     3,    -1,    -1,    46,     5,    47,    -1,
      -1,    33,    -1,    29,    -1,    43,    68,    -1,    70,    -1,
      24,    31,     3,    36,     3,    46,     3,    47,    -1,    71,
      -1,    28,    40,     3,    -1,    72,    -1,    28,    25,     3,
      -1,    73,    -1,    28,    31,     3,    36,     3,    -1,     3,
      -1,     4,    -1,     5,    -1,     6,    -1,    74,    15,    74,
      -1,    74,    16,    74,    -1,    74,    17,    74,    -1,    74,
      18,    74,    -1,    74,    19,    74,    -1,    74,    20,    74,
      -1,    16,    74,    -1,    74,     8,    74,    -1,    74,     7,
      74,    -1,    74,    11,    74,    -1,    10,    74,    -1,     9,
      74,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   128,   128,   129,   133,   138,   171,   199,   200,   206,
     207,   208,   211,   213,   218,   221,   243,   256,   259,   274,
     275,   278,   280,   283,   284,   285,   292,   301,   305,   314,
     317,   320,   321,   324,   324,   327,   328,   329,   332,   333,
     334,   335,   336,   339,   340,   343,   344,   348,   349,   350,
     351,   355,   358,   371,   374,   383,   385,   394,   397,   408,
     411,   412,   415,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   433,   434
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NAME", "STRING", "INTNUM", "APPROXNUM",
  "OR", "ANDOP", "'!'", "NOT", "COMPARISON", "'|'", "'&'", "SHIFT", "'+'",
  "'-'", "'*'", "'/'", "'%'", "MOD", "'^'", "UMINUS", "AND", "CREATE",
  "DATABASE", "DATABASES", "DELETE", "DROP", "FLOAT", "FROM", "INDEX",
  "INSERT", "INT", "INTO", "KEY", "ON", "PRIMARY", "SELECT", "SHOW",
  "TABLE", "UNIQUE", "VALUES", "VARCHAR", "WHERE", "';'", "'('", "')'",
  "','", "$accept", "stmt_list", "stmt", "select_stmt", "opt_where",
  "select_expr_list", "table_reference", "delete_stmt", "insert_stmt",
  "insert_vals_list", "insert_vals", "term", "create_database_stmt",
  "create_table_stmt", "create_col_list", "create_definition", "@1",
  "column_atts", "column_list", "opt_length", "data_type",
  "create_index_stmt", "drop_table_stmt", "drop_db_stmt",
  "drop_index_stmt", "expr", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,    33,
     264,   265,   124,    38,   266,    43,    45,    42,    47,    37,
     267,    94,   268,   269,   270,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   282,   283,   284,   285,
     286,   287,   288,   289,   290,    59,    40,    41,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    50,    51,    52,    52,    53,    53,    54,
      54,    54,    55,    55,    51,    56,    56,    51,    57,    58,
      58,    59,    59,    60,    60,    60,    60,    51,    61,    51,
      62,    63,    63,    65,    64,    64,    64,    64,    66,    66,
      66,    66,    66,    67,    67,    68,    68,    69,    69,    69,
      69,    51,    70,    51,    71,    51,    72,    51,    73,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     3,     1,     5,     7,     0,     2,     1,
       3,     1,     1,     3,     1,     4,     4,     1,     5,     3,
       5,     1,     3,     1,     1,     1,     1,     1,     3,     1,
       6,     1,     3,     0,     4,     5,     4,     4,     0,     5,
       3,     3,     2,     1,     3,     0,     3,     0,     1,     1,
       2,     1,     8,     1,     3,     1,     3,     1,     5,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     2,
       3,     3,     3,     2,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     0,     4,    14,
      17,    27,    29,    51,    53,    55,    57,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     9,    11,     0,     1,
       0,     2,    28,     0,     0,     0,    12,     7,    56,     0,
      54,     0,     0,     0,     3,     0,    33,    16,     0,     0,
      15,     0,     0,     0,     7,    10,     0,     0,     0,     0,
       0,    31,     0,    59,    60,    61,    62,     0,     0,     0,
       8,    13,    58,     0,    18,     0,     5,     0,     0,     0,
       0,    30,    33,    47,    74,    73,    69,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    23,    24,    25,    26,
       0,    21,     0,     7,     0,    43,     0,     0,     0,    32,
      49,    48,    45,    38,    71,    70,    72,    63,    64,    65,
      66,    67,    68,    19,     0,     0,     6,    52,    37,     0,
      36,     0,     0,    50,    34,    22,     0,    44,    35,     0,
      42,     0,     0,    20,    46,    41,    40,     0,     0,    39
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,     8,    50,    28,    37,     9,    10,    74,
     100,   101,    11,    12,    60,    61,    62,   134,   106,   133,
     113,    13,    14,    15,    16,    70
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -80
static const yytype_int16 yypact[] =
{
      37,   -20,    -5,   -16,   -24,     4,     3,     6,   -80,   -80,
     -80,   -80,   -80,   -80,   -80,   -80,   -80,    23,    70,    87,
      78,    97,   125,   126,   127,    97,   -80,   -80,   -26,   -80,
      22,   -80,   -80,    74,    85,    97,   -80,   -31,   -80,    96,
     -80,    24,    -1,   130,   -80,   131,     9,    88,    33,   132,
     -80,   134,    92,   101,   -31,   -80,    94,    95,    98,   108,
       0,   -80,   139,   -80,   -80,   -80,   -80,    33,    33,    33,
      63,   -80,   -80,   117,   100,   102,   -80,   142,   143,   143,
     104,   -80,     9,   -15,    86,    86,   -80,    33,    33,    33,
      33,    33,    33,    33,    33,    33,   -80,   -80,   -80,   -80,
      15,   -80,   105,   103,   106,   -80,    29,    38,   143,   -80,
     -80,   -80,   109,   -80,    76,    86,    99,   107,   107,   -80,
     -80,   -80,   -80,   -80,   117,   117,   -80,   -80,   -80,   149,
     -80,    41,   151,   -80,    72,   -80,    51,   -80,   -80,   110,
     -80,   119,   -27,   -80,   -80,   -80,   -80,   143,    64,   -80
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -80,   -80,   152,   111,   -53,   -80,   -19,   -80,   -80,   -80,
      34,    36,   -80,   -80,   -80,    79,   -80,   -80,   -79,   -80,
     -80,   -80,   -80,   -80,   -80,   -35
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
     107,    76,    36,    29,    42,    17,    41,    26,   146,    22,
      25,    18,    20,    48,   110,    23,    47,    49,   111,   147,
      19,    27,    43,    54,    24,    21,    32,     1,   112,   131,
       2,     3,    84,    85,    86,     4,    63,    64,    65,    66,
      57,     5,    67,    68,    58,    53,    59,    81,    82,    69,
     126,    31,   114,   115,   116,   117,   118,   119,   120,   121,
     122,     1,   123,   124,     2,     3,    52,    44,   148,     4,
      87,    88,    49,    33,    89,     5,   128,   129,    90,    91,
      92,    93,    94,    95,    88,   130,   129,    89,   138,   129,
      34,    90,    91,    92,    93,    94,    95,    89,   143,   124,
      36,    90,    91,    92,    93,    94,    95,   140,    35,   141,
      45,   149,   129,   142,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,    92,    93,    94,    95,    38,    39,
      40,    46,    51,    55,    56,    71,    49,    72,    73,     5,
      77,    78,    83,    80,    79,   104,   105,    48,   102,   103,
     108,   125,   137,   127,   145,   132,   139,   144,    30,   136,
     135,   109,     0,     0,    75
};

static const yytype_int16 yycheck[] =
{
      79,    54,     3,     0,    30,    25,    25,     3,    35,    25,
      34,    31,    17,    44,    29,    31,    35,    48,    33,    46,
      40,    17,    48,    42,    40,    30,     3,    24,    43,   108,
      27,    28,    67,    68,    69,    32,     3,     4,     5,     6,
      31,    38,     9,    10,    35,    46,    37,    47,    48,    16,
     103,    45,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    24,    47,    48,    27,    28,    42,    45,   147,    32,
       7,     8,    48,     3,    11,    38,    47,    48,    15,    16,
      17,    18,    19,    20,     8,    47,    48,    11,    47,    48,
       3,    15,    16,    17,    18,    19,    20,    11,    47,    48,
       3,    15,    16,    17,    18,    19,    20,    35,    30,    37,
      36,    47,    48,    41,    15,    16,    17,    18,    19,    20,
       3,     4,     5,     6,    17,    18,    19,    20,     3,     3,
       3,    46,    36,     3,     3,     3,    48,     3,    46,    38,
      46,    46,     3,    35,    46,     3,     3,    44,    48,    47,
      46,    46,     3,    47,    35,    46,     5,    47,     6,   125,
     124,    82,    -1,    -1,    53
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    24,    27,    28,    32,    38,    50,    51,    52,    56,
      57,    61,    62,    70,    71,    72,    73,    25,    31,    40,
      17,    30,    25,    31,    40,    34,     3,    17,    54,     0,
      51,    45,     3,     3,     3,    30,     3,    55,     3,     3,
       3,    55,    30,    48,    45,    36,    46,    55,    44,    48,
      53,    36,    42,    46,    55,     3,     3,    31,    35,    37,
      63,    64,    65,     3,     4,     5,     6,     9,    10,    16,
      74,     3,     3,    46,    58,    52,    53,    46,    46,    46,
      35,    47,    48,     3,    74,    74,    74,     7,     8,    11,
      15,    16,    17,    18,    19,    20,     3,     4,     5,     6,
      59,    60,    48,    47,     3,     3,    67,    67,    46,    64,
      29,    33,    43,    69,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    47,    48,    46,    53,    47,    47,    48,
      47,    67,    46,    68,    66,    60,    59,     3,    47,     5,
      35,    37,    41,    47,    47,    35,    35,    46,    67,    47
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
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
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
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
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
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
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
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
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

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

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



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

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
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

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
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

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

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
        case 4:
#line 133 "sql.y"
    { 
        emit("STMT"); 
      ;}
    break;

  case 5:
#line 140 "sql.y"
    {
      (yyval.node_p)=new SELECT_NODE;
      (yyval.node_p)->select_list=*(yyvsp[(2) - (5)].string_list);
      free((yyvsp[(2) - (5)].string_list));

      //std::cout<<$$->select_list[0]<<std::endl;
      //std::cout<<$$->select_list[1]<<std::endl;
      //std::cout<<<<std::endl;

      //std::cout<<$4->select_tbl_list[0]<<std::endl;
      //std::cout<<$4->select_tbl_list[1]<<std::endl;

      (yyval.node_p)->select_tbl_list=*(yyvsp[(4) - (5)].string_list);
      free((yyvsp[(4) - (5)].string_list));
      //std::cout<<$$->select_tbl_list[0]<<std::endl;
      //std::cout<<$$->select_tbl_list[1]<<std::endl;
      

      //std::cout<<$5->cmp<<std::endl;
      if((yyvsp[(5) - (5)].node_p)==NULL){
        //std::cout<<"null"<<std::endl;
        (yyval.node_p)->select_where_clause=NULL;
      }
      else{
        (yyval.node_p)->select_where_clause=new FORMULA_NODE;//must new 
        *((yyval.node_p)->select_where_clause)=*(yyvsp[(5) - (5)].node_p);
        free((yyvsp[(5) - (5)].node_p));
        //std::cout<<$$->select_where_clause->cmp<<std::endl;
        //std::cout<<$$->select_where_clause->l->name<<std::endl;
      } 
    ;}
    break;

  case 6:
#line 173 "sql.y"
    {
        (yyval.node_p)=new SELECT_NODE;
        (yyval.node_p)->select_list=*(yyvsp[(2) - (7)].string_list);
        free((yyvsp[(2) - (7)].string_list));

        //std::cout<<"begin"<<std::endl;
        (yyval.node_p)->nested_tbl=new SELECT_NODE;
        *((yyval.node_p)->nested_tbl)=*(yyvsp[(5) - (7)].node_p);
        //std::cout<<$$->nested_tbl->select_list[0]<<std::endl;
        free((yyvsp[(5) - (7)].node_p));

        if((yyvsp[(7) - (7)].node_p)==NULL)
        {
            //std::cout<<"null"<<std::endl;
            (yyval.node_p)->select_where_clause=NULL;
        }
        else
        {
            (yyval.node_p)->select_where_clause=new FORMULA_NODE;//must new 
            *((yyval.node_p)->select_where_clause)=*(yyvsp[(7) - (7)].node_p);
            free((yyvsp[(7) - (7)].node_p));
        }

     ;}
    break;

  case 7:
#line 199 "sql.y"
    {(yyval.node_p)=NULL;;}
    break;

  case 8:
#line 200 "sql.y"
    {(yyval.node_p)=new FORMULA_NODE;*(yyval.node_p)=*(yyvsp[(2) - (2)].node_p);free((yyvsp[(2) - (2)].node_p));
    //std::cout<<$$->cmp<<std::endl;
    ;}
    break;

  case 9:
#line 206 "sql.y"
    {(yyval.string_list)=new std::vector<std::string>;(yyval.string_list)->push_back((yyvsp[(1) - (1)].strval));;}
    break;

  case 10:
#line 207 "sql.y"
    {(yyval.string_list)->push_back((yyvsp[(3) - (3)].strval));;}
    break;

  case 11:
#line 208 "sql.y"
    {(yyval.string_list)=new std::vector<std::string>;(yyval.string_list)->push_back("select_all_flag");;}
    break;

  case 12:
#line 211 "sql.y"
    {(yyval.string_list)=new std::vector<std::string>;
    (yyval.string_list)->push_back((yyvsp[(1) - (1)].strval));;}
    break;

  case 13:
#line 213 "sql.y"
    {(yyval.string_list)->push_back((yyvsp[(3) - (3)].strval));;}
    break;

  case 14:
#line 218 "sql.y"
    { emit("STMT"); ;}
    break;

  case 15:
#line 222 "sql.y"
    {
      (yyval.node_p)=new DELETE_NODE;

      (yyval.node_p)->del_tbl_list=*(yyvsp[(3) - (4)].string_list);
      free((yyvsp[(3) - (4)].string_list));
      //std::cout<<$$->select_tbl_list[0]<<std::endl;
      //std::cout<<$$->select_tbl_list[1]<<std::endl;
      

      //std::cout<<$4->cmp<<std::endl;
      if((yyvsp[(4) - (4)].node_p)==NULL){
        yyerror("expected where clause!");
      }
      else{
        (yyval.node_p)->del_where_clause=new DELETE_NODE;//must new 
        *((yyval.node_p)->del_where_clause)=*(yyvsp[(4) - (4)].node_p);
        free((yyvsp[(4) - (4)].node_p));
        //std::cout<<$$->del_where_clause->cmp<<std::endl;
        //std::cout<<$$->del_where_clause->l->name<<std::endl;
      }  
    ;}
    break;

  case 16:
#line 243 "sql.y"
    {
        (yyval.node_p)=new DELETE_NODE;

        (yyval.node_p)->del_tbl_list=*(yyvsp[(4) - (4)].string_list);
        free((yyvsp[(4) - (4)].string_list));

        //std::cout<<$$->del_tbl_list[0]<<std::endl;

        (yyval.node_p)->star_flag=1;
    ;}
    break;

  case 17:
#line 256 "sql.y"
    {;}
    break;

  case 18:
#line 260 "sql.y"
    {
        (yyval.node_p)=new INSERT_NODE;

        (yyval.node_p)->insert_tbl_list=*(yyvsp[(3) - (5)].string_list);
        //std::cout<<$$->insert_tbl_list[0]<<std::endl;
        free((yyvsp[(3) - (5)].string_list));

        (yyval.node_p)->insert_value_list=*(yyvsp[(5) - (5)].string_vec);
        //std::cout<<$$->value_list[0][0]<<std::endl;
        //std::cout<<$$->value_list[1][0]<<std::endl;
        free((yyvsp[(5) - (5)].string_vec));
    ;}
    break;

  case 19:
#line 274 "sql.y"
    {(yyval.string_vec)=new std::vector<std::vector<std::string> >;(yyval.string_vec)->push_back(*(yyvsp[(2) - (3)].string_list));delete (yyvsp[(2) - (3)].string_list);;}
    break;

  case 20:
#line 275 "sql.y"
    {(yyval.string_vec)->push_back(*(yyvsp[(4) - (5)].string_list));free((yyvsp[(4) - (5)].string_list));;}
    break;

  case 21:
#line 278 "sql.y"
    {(yyval.string_list)=new std::vector<std::string>;
    (yyval.string_list)->push_back(*(yyvsp[(1) - (1)].str));;}
    break;

  case 22:
#line 280 "sql.y"
    {(yyval.string_list)->push_back(*(yyvsp[(3) - (3)].str));;}
    break;

  case 23:
#line 283 "sql.y"
    {(yyval.str)=new std::string((yyvsp[(1) - (1)].strval));;}
    break;

  case 24:
#line 284 "sql.y"
    {(yyval.str)=new std::string((yyvsp[(1) - (1)].strval));;}
    break;

  case 25:
#line 285 "sql.y"
    {
    std::stringstream ss;
    (yyval.str)=new std::string;
    ss<<(yyvsp[(1) - (1)].intval);
    ss>>*(yyval.str);
    //std::cout<<*$$<<std::endl;
   ;}
    break;

  case 26:
#line 292 "sql.y"
    {
    std::stringstream ss;
    (yyval.str)=new std::string;
    ss<<(yyvsp[(1) - (1)].floatval);ss>>*(yyval.str);
    //std::cout<<*$$<<std::endl;
    ;}
    break;

  case 27:
#line 301 "sql.y"
    { emit("STMT"); ;}
    break;

  case 28:
#line 305 "sql.y"
    {
        (yyval.node_p)=new CREATE_DATABASE_NODE;
        (yyval.node_p)->create_db_name=std::string((yyvsp[(3) - (3)].strval));
        //std::cout<<$$->db_name<<std::endl;
        free((yyvsp[(3) - (3)].strval));
    ;}
    break;

  case 29:
#line 314 "sql.y"
    { emit("STMT"); ;}
    break;

  case 30:
#line 318 "sql.y"
    { emit("CREATETABLE %s %d", (yyvsp[(3) - (6)].strval), (yyvsp[(5) - (6)].intval));  ;}
    break;

  case 31:
#line 320 "sql.y"
    { (yyval.intval) = 1; ;}
    break;

  case 32:
#line 321 "sql.y"
    { (yyval.intval) = (yyvsp[(1) - (3)].intval) + 1; ;}
    break;

  case 33:
#line 324 "sql.y"
    { emit("STARTCOL"); ;}
    break;

  case 34:
#line 325 "sql.y"
    { emit("COLUMNDEF %d %s", (yyvsp[(3) - (4)].intval), (yyvsp[(2) - (4)].strval)); free((yyvsp[(2) - (4)].strval)); ;}
    break;

  case 35:
#line 327 "sql.y"
    { emit("PRIKEY"); ;}
    break;

  case 36:
#line 328 "sql.y"
    { emit("KEY"); ;}
    break;

  case 37:
#line 329 "sql.y"
    { emit("KEY"); ;}
    break;

  case 38:
#line 332 "sql.y"
    { (yyval.intval) = 0; ;}
    break;

  case 39:
#line 333 "sql.y"
    { emit("ATTR UNIQUEKEY"); (yyval.intval) = (yyvsp[(1) - (5)].intval) + 1; ;}
    break;

  case 40:
#line 334 "sql.y"
    { emit("ATTR UNIQUEKEY"); (yyval.intval) = (yyvsp[(1) - (3)].intval) + 1; ;}
    break;

  case 41:
#line 335 "sql.y"
    { emit("ATTR PRIKEY"); (yyval.intval) = (yyvsp[(1) - (3)].intval) + 1; ;}
    break;

  case 42:
#line 336 "sql.y"
    { emit("ATTR PRIKEY"); (yyval.intval) = (yyvsp[(1) - (2)].intval) + 1; ;}
    break;

  case 43:
#line 339 "sql.y"
    { emit("COLUMN %s", (yyvsp[(1) - (1)].strval)); free((yyvsp[(1) - (1)].strval)); (yyval.intval) = 1; ;}
    break;

  case 44:
#line 340 "sql.y"
    { emit("COLUMN %s",(yyvsp[(3) - (3)].strval)); free((yyvsp[(3) - (3)].strval)); (yyval.intval) = (yyvsp[(1) - (3)].intval) + 1; ;}
    break;

  case 45:
#line 343 "sql.y"
    { (yyval.intval) = 0; ;}
    break;

  case 46:
#line 344 "sql.y"
    { (yyval.intval) = (yyvsp[(2) - (3)].intval); ;}
    break;

  case 48:
#line 349 "sql.y"
    { (yyval.intval) = 40000; ;}
    break;

  case 49:
#line 350 "sql.y"
    { (yyval.intval) = 90000; ;}
    break;

  case 50:
#line 351 "sql.y"
    { (yyval.intval) = 130000; ;}
    break;

  case 51:
#line 355 "sql.y"
    { emit("STMT"); ;}
    break;

  case 52:
#line 358 "sql.y"
    {
        (yyval.node_p)=new CREATE_INDEX_NODE;
        (yyval.node_p)->create_index_name=std::string((yyvsp[(3) - (8)].strval));
        (yyval.node_p)->create_index_tbl=std::string((yyvsp[(5) - (8)].strval));
        (yyval.node_p)->create_index_attr=std::string((yyvsp[(7) - (8)].strval));
        std::cout<<(yyval.node_p)->create_index_name<<std::endl;
        free((yyvsp[(3) - (8)].strval));
        free((yyvsp[(5) - (8)].strval));
        free((yyvsp[(7) - (8)].strval));
    ;}
    break;

  case 53:
#line 371 "sql.y"
    { emit("STMT"); ;}
    break;

  case 54:
#line 374 "sql.y"
    {
        (yyval.node_p)=new DROP_TABLE_NODE;
        (yyval.node_p)->drop_tbl_name=std::string((yyvsp[(3) - (3)].strval));
        std::cout<<(yyval.node_p)->drop_tbl_name<<std::endl;
        free((yyvsp[(3) - (3)].strval));
    ;}
    break;

  case 55:
#line 383 "sql.y"
    { emit("STMT"); ;}
    break;

  case 56:
#line 385 "sql.y"
    {
        (yyval.node_p)=new DROP_TABLE_NODE;
        (yyval.node_p)->drop_db_name=std::string((yyvsp[(3) - (3)].strval));
        std::cout<<(yyval.node_p)->drop_db_name<<std::endl;
        free((yyvsp[(3) - (3)].strval));
    ;}
    break;

  case 57:
#line 394 "sql.y"
    { emit("STMT"); ;}
    break;

  case 58:
#line 397 "sql.y"
    {
        (yyval.node_p)=new DROP_INDEX_NODE;
        (yyval.node_p)->drop_index_name=std::string((yyvsp[(3) - (5)].strval));
        (yyval.node_p)->drop_index_tbl=std::string((yyvsp[(5) - (5)].strval));
        std::cout<<(yyval.node_p)->drop_index_name<<std::endl;
    ;}
    break;

  case 59:
#line 408 "sql.y"
    {std::string all_s((yyvsp[(1) - (1)].strval));(yyval.node_p)=new_name(all_s);
    //std::cout<<$$->name<<std::endl;
    ;}
    break;

  case 60:
#line 411 "sql.y"
    {std::string all_s((yyvsp[(1) - (1)].strval));(yyval.node_p)=new_name(all_s);;}
    break;

  case 61:
#line 412 "sql.y"
    {(yyval.node_p)=new_int((yyvsp[(1) - (1)].intval));
    //std::cout<<$$->int_num<<std::endl;
    ;}
    break;

  case 62:
#line 415 "sql.y"
    {(yyval.node_p)=new_float((yyvsp[(1) - (1)].floatval));;}
    break;

  case 63:
#line 418 "sql.y"
    {(yyval.node_p)=new_formula(7,(yyvsp[(1) - (3)].node_p),(yyvsp[(3) - (3)].node_p));;}
    break;

  case 64:
#line 419 "sql.y"
    {(yyval.node_p)=new_formula(8,(yyvsp[(1) - (3)].node_p),(yyvsp[(3) - (3)].node_p));;}
    break;

  case 65:
#line 420 "sql.y"
    {(yyval.node_p)=new_formula(9,(yyvsp[(1) - (3)].node_p),(yyvsp[(3) - (3)].node_p));;}
    break;

  case 66:
#line 421 "sql.y"
    {(yyval.node_p)=new_formula(10,(yyvsp[(1) - (3)].node_p),(yyvsp[(3) - (3)].node_p));;}
    break;

  case 67:
#line 422 "sql.y"
    {(yyval.node_p)=new_formula(11,(yyvsp[(1) - (3)].node_p),(yyvsp[(3) - (3)].node_p));;}
    break;

  case 68:
#line 423 "sql.y"
    {(yyval.node_p)=new_formula(11,(yyvsp[(1) - (3)].node_p),(yyvsp[(3) - (3)].node_p));;}
    break;

  case 69:
#line 424 "sql.y"
    {(yyval.node_p)=new_formula(12,(yyvsp[(2) - (2)].node_p),NULL);;}
    break;

  case 70:
#line 425 "sql.y"
    {(yyval.node_p)=new_formula(13,(yyvsp[(1) - (3)].node_p),(yyvsp[(3) - (3)].node_p));;}
    break;

  case 71:
#line 426 "sql.y"
    {(yyval.node_p)=new_formula(14,(yyvsp[(1) - (3)].node_p),(yyvsp[(3) - (3)].node_p));;}
    break;

  case 72:
#line 427 "sql.y"
    {
    //$$=new FORMULA_NODE;//do not must
    (yyval.node_p)=new_formula((yyvsp[(2) - (3)].subtok),(yyvsp[(1) - (3)].node_p),(yyvsp[(3) - (3)].node_p));
    //std::cout<<$$->cmp<<std::endl;
    //std::cout<<$$->l->name<<std::endl;
  ;}
    break;

  case 73:
#line 433 "sql.y"
    {(yyval.node_p)=new_formula(15,(yyvsp[(2) - (2)].node_p),NULL);;}
    break;

  case 74:
#line 434 "sql.y"
    {(yyval.node_p)=new_formula(15,(yyvsp[(2) - (2)].node_p),NULL);;}
    break;


/* Line 1267 of yacc.c.  */
#line 2047 "sql.cpp"
      default: break;
    }
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
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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

  /* Else will try to reuse look-ahead token after shifting the error
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
      if (yyn != YYPACT_NINF)
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

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


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

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
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


#line 437 "sql.y"


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

  va_list ap;
  va_start(ap, s);

  fprintf(stderr, "%d: error: ", yylineno);
  vfprintf(stderr, s, ap);
  fprintf(stderr, "\n");
}
int
main(int ac, char **av)
{
  extern FILE *yyin;
 // extern int yydebug;
 // if(ac > 1 && !strcmp(av[1], "-d")) {
 //   yydebug = 1; ac--; av++;
 // }

  if(ac > 1 && (yyin = fopen(av[1], "r")) == NULL) {
    perror(av[1]);
    exit(1);
  }
  if(!yyparse())
    printf("SQL parse worked\n");
  else
    printf("SQL parse failed\n");
  return 0;
} /* main */


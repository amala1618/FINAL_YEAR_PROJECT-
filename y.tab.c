/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "stage7.1_exprtree.y" /* yacc.c:339  */

	#include <stdlib.h>
	#include <stdio.h>
        #include <string.h>
	#include "stage7.1_exprtree.h"
	#include "stage7.1_exprtree.c"
	int yylex(void);
        FILE* fp;
        FILE* yyin;
        extern int yylineno;

#line 78 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    CLASS = 258,
    ENDCLASS = 259,
    SELF = 260,
    EXTENDS = 261,
    NEW = 262,
    DELETE = 263,
    NUM = 264,
    PLUS = 265,
    MINUS = 266,
    MUL = 267,
    DIV = 268,
    ID = 269,
    READ = 270,
    WRITE = 271,
    BEGIN1 = 272,
    END = 273,
    EQUALSTO = 274,
    IF = 275,
    then = 276,
    ENDIF = 277,
    Else = 278,
    WHILE = 279,
    ENDWHILE = 280,
    DO = 281,
    EQ = 282,
    NE = 283,
    LT = 284,
    GT = 285,
    LE = 286,
    GE = 287,
    DECL = 288,
    ENDDECL = 289,
    INT = 290,
    STR = 291,
    RETURN = 292,
    MAIN = 293,
    TYPE = 294,
    ENDTYPE = 295,
    INITIALIZE = 296,
    ALLOC = 297,
    FREE = 298,
    NUL = 299,
    VOID = 300,
    MOD = 301
  };
#endif
/* Tokens.  */
#define CLASS 258
#define ENDCLASS 259
#define SELF 260
#define EXTENDS 261
#define NEW 262
#define DELETE 263
#define NUM 264
#define PLUS 265
#define MINUS 266
#define MUL 267
#define DIV 268
#define ID 269
#define READ 270
#define WRITE 271
#define BEGIN1 272
#define END 273
#define EQUALSTO 274
#define IF 275
#define then 276
#define ENDIF 277
#define Else 278
#define WHILE 279
#define ENDWHILE 280
#define DO 281
#define EQ 282
#define NE 283
#define LT 284
#define GT 285
#define LE 286
#define GE 287
#define DECL 288
#define ENDDECL 289
#define INT 290
#define STR 291
#define RETURN 292
#define MAIN 293
#define TYPE 294
#define ENDTYPE 295
#define INITIALIZE 296
#define ALLOC 297
#define FREE 298
#define NUL 299
#define VOID 300
#define MOD 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 12 "stage7.1_exprtree.y" /* yacc.c:355  */

	struct tnode *no;
        struct Paramstruct *pno;
        struct Gsymbol *gno;
        int number;
        char *ch;
        struct Typetable *Type_Table;
        struct Fieldlist *Field_List;
        struct Typeholder *Th;
        

#line 222 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 239 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
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
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

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
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   505

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  127
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  292

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   301

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    57,     2,
      51,    52,    47,     2,    53,     2,    56,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    50,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    54,     2,    55,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,     2,    49,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    37,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    50,    51,    53,    54,    56,    58,    59,
      61,    62,    64,    66,    67,    69,    70,    72,    73,    77,
      80,    81,    84,    84,    87,    88,    91,    94,    95,    96,
      97,    99,   100,   103,   104,   106,   119,   120,   123,   125,
     127,   128,   132,   133,   136,   154,   172,   189,   210,   212,
     215,   216,   217,   219,   221,   222,   226,   230,   231,   234,
     237,   238,   241,   242,   244,   245,   246,   251,   252,   254,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   267,
     269,   272,   273,   276,   277,   279,   282,   283,   284,   285,
     286,   287,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   298,   299,   300,   302,   303,   312,   321,   323,
     333,   355,   376,   377,   379,   380,   381,   382
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CLASS", "ENDCLASS", "SELF", "EXTENDS",
  "NEW", "DELETE", "NUM", "PLUS", "MINUS", "MUL", "DIV", "ID", "READ",
  "WRITE", "BEGIN1", "END", "EQUALSTO", "IF", "then", "ENDIF", "Else",
  "WHILE", "ENDWHILE", "DO", "EQ", "NE", "LT", "GT", "LE", "GE", "DECL",
  "ENDDECL", "INT", "STR", "RETURN", "MAIN", "TYPE", "ENDTYPE",
  "INITIALIZE", "ALLOC", "FREE", "NUL", "VOID", "MOD", "'*'", "'{'", "'}'",
  "';'", "'('", "')'", "','", "'['", "']'", "'.'", "'&'", "$accept",
  "Program", "ClassDefBlock", "ClassDefList", "ClassDef", "Cname",
  "Fieldlists", "Fld", "MethodDecl", "MDecl", "MethodDefns",
  "TypeDefBlock", "TypeDefList", "TypeDef", "$@1", "FieldDeclList",
  "FieldDecl", "TypeName", "GdeclBlock", "GdeclList", "GDecl", "GidList",
  "Gid", "FdefBlock", "Fdef", "ReturnStmt", "MainBlock", "Body",
  "ParamList", "PList", "Param", "LDecList", "LDecl", "IdList",
  "LdeclBlock", "Type", "Slist", "Stmt", "InputStmt", "OutputStmt",
  "AsgStmt", "Ifstmt", "Whilestmt", "E", "FieldFunction", "Field",
  "ArgList", "Var", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,    42,   123,   125,
      59,    40,    41,    44,    91,    93,    46,    38
};
# endif

#define YYPACT_NINF -158

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-158)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     305,  -158,   227,  -158,  -158,    -3,    22,   373,   368,  -158,
       5,  -158,   328,  -158,    47,    32,    59,  -158,  -158,    60,
     398,   393,  -158,   393,   393,  -158,  -158,    37,    49,  -158,
    -158,   135,   -37,  -158,  -158,  -158,  -158,  -158,   137,   111,
    -158,    50,   393,  -158,   393,  -158,   393,  -158,  -158,  -158,
      97,    98,    41,   163,  -158,    47,   298,   166,  -158,  -158,
     169,   393,  -158,  -158,  -158,    87,   142,  -158,   175,   167,
    -158,   207,   174,  -158,  -158,  -158,  -158,  -158,   161,  -158,
     225,  -158,  -158,  -158,   194,   192,   231,  -158,   393,  -158,
    -158,  -158,  -158,   210,   298,   -12,   228,   404,   257,  -158,
    -158,  -158,   391,  -158,   266,   104,   233,   257,   -12,  -158,
     407,  -158,   293,   237,   393,  -158,   302,    63,   232,    12,
     267,   271,   284,   294,   226,   299,   345,   342,    92,  -158,
     311,   329,   336,   339,   363,   -11,   369,  -158,   366,   371,
     257,  -158,  -158,  -158,   162,  -158,   116,  -158,   405,   372,
    -158,   124,   408,   226,   410,    -8,   226,   226,   226,   374,
    -158,    80,  -158,   226,   364,  -158,   376,  -158,    48,  -158,
    -158,  -158,   419,  -158,  -158,  -158,  -158,  -158,  -158,   226,
     421,   157,  -158,  -158,   401,  -158,   437,  -158,  -158,   402,
     403,  -158,   262,  -158,   399,   406,   274,   300,   326,   440,
     186,   442,   338,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,  -158,   443,    88,   409,  -158,   370,
    -158,   411,   412,   413,   370,  -158,  -158,  -158,   415,   414,
    -158,  -158,   438,   434,   416,  -158,   370,   201,   418,  -158,
     220,   220,   417,  -158,  -158,   105,   105,   105,   105,   220,
     417,   420,   422,   423,   452,   424,   425,  -158,   226,   189,
     189,   226,  -158,   226,   214,   226,  -158,  -158,   426,   429,
     430,   268,    24,   168,   204,   370,  -158,   216,   272,   431,
    -158,  -158,  -158,  -158,   189,  -158,  -158,  -158,  -158,  -158,
     202,  -158
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    76,     0,    74,    75,     0,     0,     0,     0,     7,
       0,    42,     0,    44,     0,     0,     0,    31,     1,     0,
       0,     0,     4,     0,     0,    53,     6,     0,     0,    41,
      43,    48,     0,    47,    32,    29,    30,    14,    18,     0,
      16,     0,     0,    10,     0,     3,     0,    12,    52,     5,
       0,     0,     0,     0,    45,     0,     0,     0,    13,    15,
       0,     0,     9,     2,    11,     0,     0,    51,     0,    63,
      65,     0,     0,    46,    40,    37,    38,    39,     0,    35,
       0,    19,    21,     8,     0,     0,     0,    50,     0,    66,
      49,    33,    34,     0,     0,     0,     0,     0,     0,    64,
      36,    20,     0,    24,     0,     0,     0,     0,     0,    73,
       0,    68,     0,     0,     0,    23,     0,     0,     0,   124,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    78,
       0,     0,     0,     0,     0,     0,     0,    57,     0,     0,
       0,    72,    67,    71,     0,    59,     0,    28,     0,     0,
      22,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     108,   124,   114,     0,     0,   113,   112,   109,     0,   127,
      62,    61,     0,    77,    79,    80,    81,    82,    83,     0,
       0,     0,    56,    55,     0,    69,     0,    17,    27,     0,
       0,   121,     0,   120,   124,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    58,     0,     0,     0,    60,    92,
     119,     0,     0,     0,    91,    54,    70,    26,     0,   125,
      89,    90,     0,     0,   121,   110,   123,     0,   120,   107,
      96,    97,    99,   106,   105,   101,   102,   103,   104,   100,
      98,   119,     0,     0,     0,     0,     0,    25,     0,     0,
       0,     0,   111,     0,     0,     0,    87,    88,     0,     0,
       0,     0,     0,     0,     0,   122,   117,     0,     0,     0,
      84,    85,   126,    94,     0,    95,   115,   116,   118,    86,
       0,    93
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -158,  -158,   462,  -158,   435,  -158,  -158,  -158,  -158,   380,
    -158,  -158,  -158,   459,  -158,  -158,   427,   -82,     8,  -158,
     471,  -158,   432,   213,   -20,   356,    10,   -29,   -55,  -158,
     397,  -158,   378,  -158,   -38,     7,  -157,  -127,  -158,  -158,
    -158,  -158,  -158,  -121,  -158,  -103,   -87,  -105
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,    20,    39,    40,    41,    94,   101,   102,   103,
     146,     7,    16,    17,    56,    78,    79,    80,     8,    12,
      13,    32,    33,    24,    25,   127,     9,   106,    68,    69,
      70,   110,   111,   144,    98,    27,   128,   129,   130,   131,
     132,   133,   134,   236,   165,   166,   237,   167
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     136,   173,   135,   164,    48,   105,   194,    10,   179,    14,
      85,    15,   104,    54,    10,    21,    55,    22,    26,    14,
     116,    97,    18,   136,    48,   135,    48,    10,    42,   118,
      43,    45,   192,    47,    49,   196,   197,   198,   119,   120,
     121,    48,   202,    28,   122,   180,   283,   284,   123,   126,
     195,    50,    62,   118,    63,     1,    64,   107,   219,    71,
     224,    31,   119,   217,    37,   216,   153,   125,   154,   113,
     140,    83,    71,    15,    38,    28,     3,     4,   138,   139,
      34,   126,   240,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,    67,   147,    71,   190,   118,    60,    35,
      51,     1,   272,   273,   112,   126,   119,   120,   121,   118,
     171,   184,   122,   150,   151,    58,   123,   112,   119,   120,
     121,   148,     3,     4,   122,    38,   188,   290,   123,   124,
       1,   200,   206,   207,   153,   125,   201,   271,     1,    84,
     252,   124,   275,    57,   180,   173,   173,   125,    65,   126,
      66,     3,     4,   148,   136,   136,   135,   135,    71,     3,
       4,   126,   159,   173,   221,   187,   160,   136,   136,   135,
     135,   161,    72,   118,   274,    74,   189,   277,   278,   136,
      81,   135,   119,   120,   121,   136,    52,   135,   122,    53,
      86,   159,   123,   285,   118,   160,    75,    76,   222,   223,
     161,   162,    82,   119,   120,   121,    77,   118,   163,   122,
      91,   125,   185,   123,   126,   186,   119,   120,   121,   159,
      88,    89,   122,   160,   291,   126,   123,    87,   161,    90,
     162,   159,   125,   205,    44,   160,    46,   163,   235,    93,
     161,     1,    95,   126,    96,   125,   126,   206,   207,   208,
     209,   210,   211,   262,   263,    61,   286,   263,   162,   126,
     100,    11,     3,     4,    97,   163,   276,   213,   287,   263,
     162,   126,   203,   204,   105,   205,   108,   163,   203,   204,
     117,   205,   137,   126,   203,   204,   145,   205,   152,   206,
     207,   208,   209,   210,   211,   206,   207,   208,   209,   210,
     211,   206,   207,   208,   209,   210,   211,   143,   212,   213,
     203,   204,    74,   205,   212,   213,   149,   229,   155,     1,
     212,   213,   156,   282,   288,   263,   231,   206,   207,   208,
     209,   210,   211,    75,    76,   157,   203,   204,     2,   205,
       3,     4,     1,    77,     5,   158,   212,   213,   203,   204,
     168,   205,   232,   206,   207,   208,   209,   210,   211,   169,
     170,   174,    29,     3,     4,   206,   207,   208,   209,   210,
     211,    19,   212,   213,   203,   204,    19,   205,   233,   175,
     203,   204,     1,   205,   212,   213,   176,     1,   181,   177,
     239,   206,   207,   208,   209,   210,   211,   206,   207,   208,
     209,   210,   211,     3,     4,    74,     2,     1,     3,     4,
     212,   213,     1,   178,   214,   182,   212,   213,     1,    50,
     183,     1,   191,   151,   193,   114,    75,    76,     3,     4,
     199,     2,   215,     3,     4,   220,    77,   218,   109,     3,
       4,   141,     3,     4,   206,   207,   208,   209,   210,   211,
     225,   226,   227,   153,   234,   228,   238,   251,   230,   259,
     260,   253,   254,   255,   256,   257,   268,   261,   258,   264,
      23,   265,   266,   267,    59,    36,   269,   270,   279,   280,
     281,   289,   115,    30,   172,    99,     0,    73,   142,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    92
};

static const yytype_int16 yycheck[] =
{
     105,   128,   105,   124,    24,    17,    14,     0,    19,     2,
      65,    14,    94,    50,     7,     7,    53,     7,     8,    12,
     102,    33,     0,   128,    44,   128,    46,    20,    20,     5,
      20,    21,   153,    23,    24,   156,   157,   158,    14,    15,
      16,    61,   163,    38,    20,    56,    22,    23,    24,    57,
     155,    14,    42,     5,    44,    14,    46,    95,   179,    52,
     181,    14,    14,   168,     4,   168,    54,    43,    56,    98,
     108,    61,    65,    14,    14,    38,    35,    36,   107,   108,
      48,    57,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,    52,   114,    88,   151,     5,    48,    40,
      51,    14,   259,   260,    97,    57,    14,    15,    16,     5,
      18,   140,    20,    50,    51,     4,    24,   110,    14,    15,
      16,   114,    35,    36,    20,    14,   146,   284,    24,    37,
      14,    51,    27,    28,    54,    43,    56,   258,    14,    52,
      52,    37,   263,     6,    56,   272,   273,    43,    51,    57,
      52,    35,    36,   146,   259,   260,   259,   260,   151,    35,
      36,    57,     5,   290,     7,    49,     9,   272,   273,   272,
     273,    14,     9,     5,   261,    14,    52,   264,   265,   284,
      14,   284,    14,    15,    16,   290,    51,   290,    20,    54,
      48,     5,    24,    25,     5,     9,    35,    36,    41,    42,
      14,    44,    33,    14,    15,    16,    45,     5,    51,    20,
      49,    43,    50,    24,    57,    53,    14,    15,    16,     5,
      53,    14,    20,     9,    22,    57,    24,    52,    14,    55,
      44,     5,    43,    13,    21,     9,    23,    51,    52,    14,
      14,    14,    48,    57,    52,    43,    57,    27,    28,    29,
      30,    31,    32,    52,    53,    42,    52,    53,    44,    57,
      50,    34,    35,    36,    33,    51,    52,    47,    52,    53,
      44,    57,    10,    11,    17,    13,    48,    51,    10,    11,
      14,    13,    49,    57,    10,    11,    49,    13,    56,    27,
      28,    29,    30,    31,    32,    27,    28,    29,    30,    31,
      32,    27,    28,    29,    30,    31,    32,    14,    46,    47,
      10,    11,    14,    13,    46,    47,    14,    55,    51,    14,
      46,    47,    51,    55,    52,    53,    52,    27,    28,    29,
      30,    31,    32,    35,    36,    51,    10,    11,    33,    13,
      35,    36,    14,    45,    39,    51,    46,    47,    10,    11,
      51,    13,    52,    27,    28,    29,    30,    31,    32,    14,
      18,    50,    34,    35,    36,    27,    28,    29,    30,    31,
      32,     3,    46,    47,    10,    11,     3,    13,    52,    50,
      10,    11,    14,    13,    46,    47,    50,    14,    19,    50,
      52,    27,    28,    29,    30,    31,    32,    27,    28,    29,
      30,    31,    32,    35,    36,    14,    33,    14,    35,    36,
      46,    47,    14,    50,    50,    49,    46,    47,    14,    14,
      49,    14,    14,    51,    14,    34,    35,    36,    35,    36,
      56,    33,    56,    35,    36,    14,    45,    18,    34,    35,
      36,    34,    35,    36,    27,    28,    29,    30,    31,    32,
      49,    14,    50,    54,    14,    52,    14,    14,    52,    21,
      26,    52,    51,    51,    51,    50,    14,    51,    54,    51,
       8,    51,    50,    50,    39,    16,    52,    52,    52,    50,
      50,    50,   102,    12,   128,    88,    -1,    55,   110,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    78
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    14,    33,    35,    36,    39,    59,    69,    76,    84,
      93,    34,    77,    78,    93,    14,    70,    71,     0,     3,
      60,    76,    84,    60,    81,    82,    84,    93,    38,    34,
      78,    14,    79,    80,    48,    40,    71,     4,    14,    61,
      62,    63,    76,    84,    81,    84,    81,    84,    82,    84,
      14,    51,    51,    54,    50,    53,    72,     6,     4,    62,
      48,    81,    84,    84,    84,    51,    52,    52,    86,    87,
      88,    93,     9,    80,    14,    35,    36,    45,    73,    74,
      75,    14,    33,    84,    52,    86,    48,    52,    53,    14,
      55,    49,    74,    14,    64,    48,    52,    33,    92,    88,
      50,    65,    66,    67,    75,    17,    85,    92,    48,    34,
      89,    90,    93,    85,    34,    67,    75,    14,     5,    14,
      15,    16,    20,    24,    37,    43,    57,    83,    94,    95,
      96,    97,    98,    99,   100,   103,   105,    49,    85,    85,
      92,    34,    90,    14,    91,    49,    68,    82,    93,    14,
      50,    51,    56,    54,    56,    51,    51,    51,    51,     5,
       9,    14,    44,    51,   101,   102,   103,   105,    51,    14,
      18,    18,    83,    95,    50,    50,    50,    50,    50,    19,
      56,    19,    49,    49,    85,    50,    53,    49,    82,    52,
      86,    14,   101,    14,    14,   105,   101,   101,   101,    56,
      51,    56,   101,    10,    11,    13,    27,    28,    29,    30,
      31,    32,    46,    47,    50,    56,   103,   105,    18,   101,
      14,     7,    41,    42,   101,    49,    14,    50,    52,    55,
      52,    52,    52,    52,    14,    52,   101,   104,    14,    52,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,    14,    52,    52,    51,    51,    51,    50,    54,    21,
      26,    51,    52,    53,    51,    51,    50,    50,    14,    52,
      52,   101,    94,    94,   104,   101,    52,   104,   104,    52,
      50,    50,    55,    22,    23,    25,    52,    52,    52,    50,
      94,    22
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    58,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    60,    60,    61,    61,    62,    63,    63,
      64,    64,    65,    66,    66,    67,    67,    68,    68,    69,
      70,    70,    72,    71,    73,    73,    74,    75,    75,    75,
      75,    76,    76,    77,    77,    78,    79,    79,    80,    80,
      80,    80,    81,    81,    82,    82,    82,    82,    83,    84,
      85,    85,    85,    86,    87,    87,    88,    89,    89,    90,
      91,    91,    92,    92,    93,    93,    93,    94,    94,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    96,
      97,    98,    98,    99,    99,   100,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   102,   102,   102,   102,   103,
     103,   103,   104,   104,   105,   105,   105,   105
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     3,     2,     3,     2,     1,     5,     4,
       3,     4,     3,     3,     2,     2,     1,     8,     1,     3,
       2,     0,     3,     2,     1,     6,     5,     2,     1,     3,
       2,     1,     0,     5,     2,     1,     3,     1,     1,     1,
       1,     3,     2,     2,     1,     3,     3,     1,     1,     4,
       4,     3,     2,     1,     9,     8,     8,     7,     3,     8,
       4,     3,     3,     1,     3,     1,     2,     2,     1,     3,
       3,     1,     3,     2,     1,     1,     1,     2,     1,     2,
       2,     2,     2,     2,     6,     6,     7,     5,     5,     4,
       4,     3,     3,     9,     7,     7,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       3,     4,     1,     1,     1,     6,     6,     5,     6,     3,
       3,     3,     3,     1,     1,     4,     7,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

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
      yychar = yylex ();
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
     '$$ = $1'.

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
#line 37 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.number)=1;exit(1);}
#line 1559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 38 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.number)=1;exit(1);}
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 39 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.number)=1;exit(1);}
#line 1571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 40 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.number)=1;exit(1);}
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 41 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.number)=1;exit(1);}
#line 1583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 42 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.number)=1;exit(1);}
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 43 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.number)=1;exit(1);}
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 44 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.number)=1;exit(1);}
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 45 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.number)=1;exit(1);}
#line 1607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 46 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.number)=1;exit(1);}
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 47 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.number)=1;exit(1);}
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 50 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {printf("HI CLASS DEF DONE,ABOUT TO PRINT CLASS TABLE STAY TUNED!!");printclasstable();}
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 56 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {CFindex = 0; CMindex = 0;Cptr=NULL;}
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 58 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {Cptr = CInstall((yyvsp[0].no)->varname,NULL);(yyval.no)=(yyvsp[0].no);}
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 59 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {Cptr = CInstall((yyvsp[-2].no)->varname,(yyvsp[0].no)->varname);(yyval.no)=(yyvsp[-2].no);}
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 64 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {printf("Attribute Declaration in Progress!!");Class_Finstall(Cptr,(yyvsp[-2].Type_Table)->name,(yyvsp[-1].no)->varname);}
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 69 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {Class_Minstall(Cptr,(yyvsp[-4].no)->varname,TLookup((yyvsp[-5].Type_Table)->name),(yyvsp[-2].pno));Lsymbol_rst();headsymb_p=NULL;}
#line 1655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 70 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {Class_Minstall(Cptr,(yyvsp[-3].no)->varname,TLookup((yyvsp[-4].Type_Table)->name),NULL);Lsymbol_rst();headsymb_p=NULL;}
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 77 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {print_Typetable();printf("type declaration done");}
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 81 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {printf("Type 1 stroed as typeDefList");}
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 84 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {Tinstall((yyvsp[-1].no)->varname,0,NULL);}
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 84 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {struct Typetable *t=TLookup((yyvsp[-4].no)->varname);t->fields=Fhead;t->size=GetSize(t);Fhead=NULL;FieldNo=0;Findex=0; }
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 87 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyvsp[0].Field_List)->next = (yyvsp[-1].Field_List);(yyval.Field_List) = (yyvsp[0].Field_List); Fhead=(yyvsp[0].Field_List); FieldNo++;}
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 88 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.Field_List)=(yyvsp[0].Field_List);}
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 91 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {size=size+1;(yyval.Field_List)=Finstall((yyvsp[-1].no)->varname,(yyvsp[-2].Type_Table)->name);}
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 94 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.Type_Table)=TLookup("INT"); }
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 95 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.Type_Table)=TLookup("STR"); }
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 96 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.Type_Table)=TLookup("VOID"); }
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 97 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.Type_Table)=TLookup((yyvsp[0].no)->varname); }
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 99 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {curr=headsymb;print_symbol_table();fprintf(fp,"MOV SP, %d\n",bind+1);fprintf(fp,"CALL F0\n");fprintf(fp,"INT 10\n");}
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 106 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {            curr=headsymb;
	       						while((yyvsp[-1].gno) != NULL) {
                                                        curr=headsymb;
			     				struct Gsymbol* temp = GLookup((yyvsp[-1].gno)->name);
							temp->type = (yyvsp[-2].Th)->Ttype;
                                                        temp->Ctype = (yyvsp[-2].Th)->Ctype;
							//$2 = $2->next;
							(yyvsp[-1].gno)=(yyvsp[-1].gno)->left;}
                                                        
                                                       
					}
#line 1749 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 119 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyvsp[0].gno)->left=(yyvsp[-2].gno);(yyval.gno)=(yyvsp[0].gno);}
#line 1755 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 120 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyvsp[0].gno)->left=NULL;(yyval.gno)=(yyvsp[0].gno);}
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 123 "stage7.1_exprtree.y" /* yacc.c:1646  */
    { GInstall((yyvsp[0].no)->varname,curr_type,1,1,1,NULL,0,NULL);curr=headsymb;(yyval.gno)=GLookup((yyvsp[0].no)->varname);}
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 125 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {GInstall((yyvsp[-3].no)->varname,curr_type,(yyvsp[-1].no)->val,(yyvsp[-1].no)->val,1,NULL,0,NULL);curr=headsymb;(yyval.gno)=GLookup((yyvsp[-3].no)->varname);}
#line 1773 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 127 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {GInstall((yyvsp[-3].no)->varname,curr_type, 1,1,1,(yyvsp[-1].pno),getFlabel(),NULL);curr=headsymb;(yyval.gno)=GLookup((yyvsp[-3].no)->varname);}
#line 1779 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 128 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {GInstall((yyvsp[-2].no)->varname,curr_type, 1,1,1,NULL,0,NULL);curr=headsymb;(yyval.gno)=GLookup((yyvsp[-2].no)->varname);}
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 136 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {/*fucn_check_name($1->Ttype,$2->varname,$4); struct Paramstruct *ptemp;

     							if(Cptr!=NULL){
								ptemp=PInstall_each("self",TLookup("VOID"),headsymb_p);
								ptemp=PInstall($4,ptemp);}
							else{ptemp=$4;}
							createLsymbolEntries(ptemp);*/
                                                        //local_binding_stored_here=-3;
                                                        //createLsymbolEntries($4);
							if(Cptr!=NULL){
									struct Lsymbol *ltemp=LLookup("self");
									ltemp->binding=local_binding_stored_here;
                                                        printf("%d",LLookup("self")->binding);//exit(1);
							}
                                                        local_binding_stored_here=-3;
							codeGen_f((yyvsp[-1].no),(yyvsp[-7].no)->varname,fp);
							Lsymbol_rst();
							activate=0;}
#line 1808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 154 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {/*fucn_check_name($1->Ttype,$2->varname,$4);
                                                         struct Paramstruct *ptemp;
                                                        if(Cptr!=NULL){
								ptemp=PInstall_each("self",TLookup("VOID"),headsymb_p);
								ptemp=PInstall($4,ptemp);}
							else{ptemp=$4;}
							createLsymbolEntries(ptemp);*/
							//local_binding_stored_here=-3;


                                                        //createLsymbolEntries($4);
							if(Cptr!=NULL){
									struct Lsymbol *ltemp=LLookup("self");
									ltemp->binding=local_binding_stored_here;}
                                                        local_binding_stored_here=-3;

							 //printf("%d",LLookup("self")->binding);//exit(1);
							codeGen_f((yyvsp[-1].no),(yyvsp[-6].no)->varname,fp);Lsymbol_rst();activate=0;}
#line 1831 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 172 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {/*fucn_check_name($1->Ttype,$2->varname,NULL);
							 struct Paramstruct *ptemp; 
							if(Cptr!=NULL){
								ptemp=PInstall_each("self",TLookup("VOID"),headsymb_p);
								ptemp=PInstall(NULL,ptemp);}
							else{ptemp=NULL;}
							createLsymbolEntries(ptemp);*/
                                                        //local_binding_stored_here=-3;
							//createLsymbolEntries($1);
 							if(Cptr!=NULL){
									struct Lsymbol *ltemp=LLookup("self");
									ltemp->binding=local_binding_stored_here;}
                                                        //printf("%d",LLookup("self")->binding);//exit(1);
							 local_binding_stored_here=-3;

							codeGen_f((yyvsp[-1].no),(yyvsp[-6].no)->varname,fp);
						        Lsymbol_rst();activate=0;}
#line 1853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 189 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {/*fucn_check_name($1->Ttype,$2->varname,NULL);
                                                         struct Paramstruct *ptemp;
							 if(Cptr!=NULL){
								ptemp=PInstall_each("self",TLookup("VOID"),headsymb_p);
								ptemp=PInstall(NULL,ptemp);}
							else{ptemp=NULL;}
							createLsymbolEntries(ptemp);*/
							//local_binding_stored_here=-3;
                                                        //createLsymbolEntries($1); 
							if(Cptr!=NULL){
									struct Lsymbol *ltemp=LLookup("self");
									ltemp->binding=local_binding_stored_here;
                                                        printf("%d",LLookup("self")->binding);//exit(1);
								}
							 local_binding_stored_here=-3;

							codeGen_f((yyvsp[-1].no),(yyvsp[-5].no)->varname,fp);
							Lsymbol_rst();activate=0;}
#line 1876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 210 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.no)=createTree(0,TLookup("NULL"),NULL,23,(yyvsp[-1].no),NULL,NULL);}
#line 1882 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 212 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {printf("Hi in mainblock");if((yyvsp[-7].Th)->Ttype!=TLookup("INT")){
	                                                      printf("Function main expects integer return type");exit(1);};codeGen_f((yyvsp[-1].no),"main",fp);Lsymbol_rst(); }
#line 1889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 215 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {activate=1;(yyval.no)=createTree(0,TLookup("NULL"),NULL,2,(yyvsp[-2].no),(yyvsp[-1].no),NULL);}
#line 1895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 216 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {activate=1;(yyval.no)=createTree(0,TLookup("NULL"),NULL,2,(yyvsp[-1].no),NULL,NULL);}
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 217 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {activate=1;(yyval.no)=createTree(0,TLookup("NULL"),NULL,2,(yyvsp[-1].no),NULL,NULL);}
#line 1907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 219 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.pno)=(yyvsp[0].pno);createLsymbolEntries((yyvsp[0].pno));}
#line 1913 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 221 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.pno)=PInstall((yyvsp[-2].pno),(yyvsp[0].pno));}
#line 1919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 222 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.pno)=(yyvsp[0].pno);}
#line 1925 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 226 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.pno)=PInstall_each((yyvsp[0].no)->varname,(yyvsp[-1].Th)->Ttype,headsymb_p);}
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 230 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {}
#line 1937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 231 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {}
#line 1943 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 234 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {}
#line 1949 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 237 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {LInstall((yyvsp[0].no)->varname,curr_type);}
#line 1955 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 238 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {LInstall((yyvsp[0].no)->varname,curr_type);}
#line 1961 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 241 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {activate=1;if(Cptr!=NULL){LInstall("self",TLookup("VOID"));}/*if(Cptr!=NULL){struct Paramstruct *Ptemp=PInstall_each("self",TLookup("VOID"),headsymb_p);createLsymbolEntries(Ptemp);}*/}
#line 1967 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 242 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {activate=1;if(Cptr!=NULL){LInstall("self",TLookup("VOID"));}/*if(Cptr!=NULL){struct Paramstruct *Ptemp=PInstall_each("self",TLookup("VOID"),headsymb_p);createLsymbolEntries(Ptemp);}*/}
#line 1973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 244 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.Th)->Ttype=TLookup("INT");curr_type=(yyval.Th)->Ttype;(yyval.Th)->Ctype=NULL;}
#line 1979 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 245 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.Th)->Ttype=TLookup("STR");curr_type=(yyval.Th)->Ttype;(yyval.Th)->Ctype=NULL;}
#line 1985 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 246 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {struct Typetable *Ttemp=TLookup((yyvsp[0].no)->varname);if(Ttemp==NULL){
			  struct Classtable *Ctemp = CLookup((yyvsp[0].no)->varname);
         		  (yyval.Th)->Ctype = Ctemp;(yyval.Th)->Ttype = NULL;}
                          else{(yyval.Th)->Ttype = Ttemp;(yyval.Th)->Ctype = NULL;}curr_type=Ttemp;}
#line 1994 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 251 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.no)=createTree(0,TLookup("NULL"),NULL,2,(yyvsp[-1].no),(yyvsp[0].no),NULL);}
#line 2000 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 252 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.no)=(yyvsp[0].no);}
#line 2006 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 254 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.no)=(yyvsp[-1].no);}
#line 2012 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 255 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.no)=(yyvsp[-1].no);}
#line 2018 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 256 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.no)=(yyvsp[-1].no);}
#line 2024 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 257 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.no)=(yyvsp[-1].no);}
#line 2030 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 258 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.no)=(yyvsp[-1].no);}
#line 2036 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 259 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.no)=createTree(0,TLookup("INT"),NULL,27,(yyvsp[-5].no),NULL,NULL);}
#line 2042 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 260 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.no)=createTree(0,TLookup("INT"),NULL,25,(yyvsp[-5].no),NULL,NULL);}
#line 2048 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 261 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {if(CLookup((yyvsp[-2].no)->varname)==NULL){printf("Only CLass objs can be allocated this way!");exit(1);}else{(yyvsp[-6].no)->Ctype=CLookup((yyvsp[-2].no)->varname);(yyval.no)=createTree(0,TLookup("INT"),NULL,25,(yyvsp[-6].no),NULL,NULL);}}
#line 2054 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 262 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.no)=createTree(0,TLookup("INT"),NULL,26,(yyvsp[-2].no),NULL,NULL);}
#line 2060 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 263 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.no)=createTree(0,TLookup("INT"),NULL,26,(yyvsp[-2].no),NULL,NULL);}
#line 2066 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 267 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.no)=createTree(0,TLookup("NULL"),NULL,0,(yyvsp[-1].no),NULL,NULL);}
#line 2072 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 269 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.no)=createTree(0,TLookup("NULL"),NULL,1,(yyvsp[-1].no),NULL,NULL);}
#line 2078 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 272 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.no)=createTree(0,TLookup("NULL"),NULL,9,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 2084 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 273 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.no)=createTree(0,TLookup("NULL"),NULL,9,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 2090 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 276 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.no)=createTree(0,TLookup("NULL"),NULL,19,(yyvsp[-6].no),(yyvsp[-3].no),(yyvsp[-1].no));}
#line 2096 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 277 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.no)=createTree(0,TLookup("NULL"),NULL,18,(yyvsp[-4].no),(yyvsp[-1].no),NULL);}
#line 2102 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 279 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.no)=createTree(0,TLookup("NULL"),NULL,17,(yyvsp[-4].no),(yyvsp[-1].no),NULL);}
#line 2108 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 282 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.no) = createTree(0,TLookup("NULL"),NULL,3,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 2114 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 283 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.no) = createTree(0,TLookup("NULL"),NULL,4,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 2120 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 284 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.no) = createTree(0,TLookup("NULL"),NULL,5,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 2126 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 285 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.no) = createTree(0,TLookup("NULL"),NULL,6,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 2132 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 286 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.no) = createTree(0,TLookup("NULL"),NULL,29,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 2138 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 287 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.no)=createTree(0,TLookup("NULL"),NULL,11,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 2144 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 288 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.no)=createTree(0,TLookup("NULL"),NULL,12,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 2150 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 289 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.no)=createTree(0,TLookup("NULL"),NULL,13,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 2156 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 290 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.no)=createTree(0,TLookup("NULL"),NULL,14,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 2162 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 291 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.no)=createTree(0,TLookup("NULL"),NULL,15,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 2168 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 292 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.no)=createTree(0,TLookup("NULL"),NULL,16,(yyvsp[-2].no),(yyvsp[0].no),NULL);}
#line 2174 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 293 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.no) = (yyvsp[-1].no);}
#line 2180 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 294 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.no) = (yyvsp[0].no);}
#line 2186 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 295 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.no)=(yyvsp[0].no);}
#line 2192 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 296 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.no)=createTree(0,TLookup("NULL"),(yyvsp[-2].no)->varname,22,NULL,NULL,NULL);}
#line 2198 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 297 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.no)=createTree(0,TLookup("NULL"),(yyvsp[-3].no)->varname,22,(yyvsp[-1].no),NULL,NULL);}
#line 2204 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 298 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.no)=(yyvsp[0].no);}
#line 2210 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 299 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.no)=(yyvsp[0].no);}
#line 2216 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 300 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.no)=createTree(0,TLookup("NULL"),NULL,28,NULL,NULL,NULL);}
#line 2222 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 302 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.no)=createTree(0,TLookup("NULL"),NULL,28,NULL,NULL,NULL);}
#line 2228 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 303 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {curr=headsymb;struct Gsymbol *Gtemp=GLookup((yyvsp[-5].no)->varname);if(Gtemp->Ctype==NULL){
						printf("No Object is declared!!");
						exit(1);} 
					struct Memberfunclist *Mtemp=Class_Mlookup(Gtemp->Ctype,(yyvsp[-3].no)->varname);
				    	if(Mtemp==NULL){
						printf("No such Methods are avaible !!");
						exit(1);}
					(yyval.no)=createTree(Mtemp->Flabel,TLookup("NULL"),NULL,31,(yyvsp[-5].no),(yyvsp[-3].no),(yyvsp[-1].no));}
#line 2241 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 312 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {curr=headsymb;struct Gsymbol *Gtemp=GLookup((yyvsp[-4].no)->varname);if(Gtemp->Ctype==NULL){
						printf("No Object is declared!!");
						exit(1);} 
					struct Memberfunclist *Mtemp=Class_Mlookup(Gtemp->Ctype,(yyvsp[-2].no)->varname);
				    	if(Mtemp==NULL){
						printf("No such Methods are avaible !!");
						exit(1);}
					(yyval.no)=createTree(Mtemp->Flabel,TLookup("NULL"),NULL,31,(yyvsp[-4].no),(yyvsp[-2].no),NULL);}
#line 2254 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 321 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.no)=createTree(0,TLookup("NULL"),NULL,28,NULL,NULL,NULL);}
#line 2260 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 323 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {struct tnode* temp = (yyvsp[-2].no); 			
                                        while(temp->right!=NULL){temp = temp->right;}
				        struct Fieldlist *Ftemp = FLookup(temp->type, (yyvsp[0].no)->varname);
                         		if(Ftemp == NULL){
						printf("Field is not a member of the datatype");exit(1);}
                                        (yyvsp[0].no)->type = Ftemp->type;
	                		(yyvsp[0].no)->val = Ftemp->fieldIndex;
					(yyvsp[-2].no)->type = Ftemp->type;
					(yyvsp[-2].no)->nodetype = 24;
					temp->right = (yyvsp[0].no); (yyval.no) =  (yyvsp[-2].no);}
#line 2275 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 333 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {                         (yyvsp[-2].no)->right = (yyvsp[0].no); curr=headsymb;	
				        struct Gsymbol *Gtemp = GLookup((yyvsp[-2].no)->varname);
				        struct Lsymbol *Ltemp = LLookup((yyvsp[-2].no)->varname);
				        if(Ltemp==NULL){
						if(Gtemp==NULL){printf("Variable not declared\n"); exit(1); }
					(yyvsp[-2].no)->type = Gtemp->type;	(yyvsp[-2].no)->Gentry= Gtemp;(yyvsp[-2].no)->Lentry= NULL;}	
				        else{struct Lsymbol* Ltemp = LLookup((yyvsp[-2].no)->varname);
						(yyvsp[-2].no)->type = Ltemp->type;
	                        		(yyvsp[-2].no)->Gentry = NULL;
	                        		(yyvsp[-2].no)->Lentry = Ltemp;	}	
					struct Fieldlist *Ftemp = FLookup((yyvsp[-2].no)->type, (yyvsp[0].no)->varname);
                               		// printf("%s %s \n",$1->type,$3->varname);
					if(Ftemp==NULL){
						printf("Field is not a member of the datatype\n");exit(1); }
					(yyvsp[-2].no)->type = Ftemp->type;
					(yyvsp[0].no)->type = Ftemp->type;
					(yyvsp[0].no)->val = Ftemp->fieldIndex;
					(yyvsp[-2].no)->nodetype = 24;
					(yyval.no) = (yyvsp[-2].no);printf("Type of %s is %s\n",(yyvsp[-2].no)->type->name,(yyvsp[-2].no)->varname);
                                	printf("Type of %s is %s\n",(yyvsp[0].no)->type->name,(yyvsp[0].no)->varname);}
#line 2300 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 355 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {
					if(Cptr == NULL){
						printf("Self cannot be used outside a class");	exit(1);}
					(yyval.no) = createTree(0, TLookup("NULL"),NULL, 30, NULL, (yyvsp[0].no),NULL);
					if(Cptr!=NULL){
									struct Lsymbol *ltemp=LLookup("self");
									ltemp->binding=local_binding_stored_here-1;}
                                        printf("\nSELF BINDING IS !!%d\n",LLookup("self")->binding);//exit(1);
					(yyval.no)->Lentry = LLookup("self");
					struct Fieldlist * Ftemp = Class_Flookup(Cptr, (yyvsp[0].no)->varname);
					if(Ftemp == NULL){
							printf("Variable not a memberfield\n");exit(1);	}
					(yyval.no)->type = Ftemp->type;
					(yyvsp[0].no)->type = Ftemp->type;
					(yyvsp[0].no)->Ctype = Ftemp->Ctype;
					(yyvsp[0].no)->val = Ftemp->fieldIndex;
					(yyval.no)->val = Ftemp->fieldIndex;

                }
#line 2324 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 376 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {/*$3->next=$1;$$=$3;*/struct tnode* temp=(yyvsp[-2].no);while((yyvsp[-2].no)->next!=NULL){(yyvsp[-2].no)=(yyvsp[-2].no)->next;}(yyvsp[-2].no)->next=(yyvsp[0].no);(yyval.no)=temp;}
#line 2330 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 377 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.no)=(yyvsp[0].no);}
#line 2336 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 379 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.no)=createTree(0,TLookup("NULL"),(yyvsp[0].no)->varname,8,NULL,NULL,NULL);}
#line 2342 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 380 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.no)=createTree(0,TLookup("NULL"),(yyvsp[-3].no)->varname,10,(yyvsp[-1].no),NULL,NULL);}
#line 2348 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 381 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.no)=createTree(0,TLookup("NULL"),(yyvsp[-6].no)->varname,10,(yyvsp[-4].no),(yyvsp[-1].no),NULL);}
#line 2354 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 382 "stage7.1_exprtree.y" /* yacc.c:1646  */
    {(yyval.no)=createTree(0,(yyvsp[0].no)->type,(yyvsp[0].no)->varname,21,(yyvsp[0].no),NULL,NULL);}
#line 2360 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2364 "y.tab.c" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 386 "stage7.1_exprtree.y" /* yacc.c:1906  */

/*        ;

|E EQ ALLOC'('')'     {$$=createTree(0,TLookup("INT"),NULL,26,$1,NULL,NULL);}
          |FREE'('E')'     {$$=createTree(0,TLookup("INT"),NULL,27,$3,NULL,NULL);}
          |E EQ INITIALIZE'('')'{$$=createTree(0,TLookup("INT"),NULL,28,$1,NULL,NULL);}

TypeDefBlock  : TYPE TypeDefList ENDTYPE
	      |                                               
              ;

TypeDefList   : TypeDefList TypeDef
	      | TypeDef
              ;

TypeDef       : ID '{' FieldDeclList '}'   { Tptr = TInstall($1->varname,size,$3); }
	                    ;

FieldDeclList : FieldDeclList FieldDecl
	      | FieldDecl
              ;

FieldDecl    : TypeName ID 
	     ;

TypeName     : INT                               
	     | STR
             | ID       
       	    ;
G*/
yyerror(char const *s)

{
    printf("yyerror %s",s);
}

int main(int argc,char* argv[]) {
	if(argc>1) {
        FILE *fp_1 = fopen(argv[1], "r");
        if(fp_1)
            yyin = fp_1;
    }

	TypeTableCreate();
        fp=fopen("Sample1.xsm","w");
        fprintf(fp,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,1,0);
        yyparse();
	return 0;
}

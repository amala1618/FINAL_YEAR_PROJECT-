/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 12 "stage7.1_exprtree.y" /* yacc.c:1909  */

	struct tnode *no;
        struct Paramstruct *pno;
        struct Gsymbol *gno;
        int number;
        char *ch;
        struct Typetable *Type_Table;
        struct Fieldlist *Field_List;
        struct Typeholder *Th;
        

#line 158 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

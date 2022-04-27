
%{
	#include <stdlib.h>
	#include <stdio.h>
	#include "y.tab.h"
	#include "stage3_exprtree.h"

	int number;
        char *variable;

%}

%%

[0-9]+	{number = atoi(yytext); yylval.no = createTree(number,0,NULL,7,NULL,NULL); return NUM;}
"+"	{return PLUS;}
"-"	{return MINUS;}
"*"	{return MUL;}
"/"	{return DIV;}
"=="    {return EQ;}
"!="    {return NE;}
"<"     {return LT;}
">"     {return GT;}
"<="    {return LE;}
">="    {return GE;}
"="    {return EQUALSTO;}
"read"  {return READ;}
"write" {return WRITE;}
"begin" {return BEGIN1;}
"end"   {return END;}
"if"    {return IF;}
"else"  {return Else;}
"then"  {return then;}
"endif" {return ENDIF;}
"while" {return WHILE;}
"do"    {return DO;}
"endwhile" {return ENDWHILE;}
[a-z]   {variable=strdup(yytext); yylval.no=createTree(0,0,variable,8,NULL,NULL);return ID;}
[ \t]	{}
[()]	{return *yytext;}
[\n]	{return NEWLINE;}
.	{yyerror("unknown character\n");exit(1);}

%%

int yywrap(void) {
	return 1;
}

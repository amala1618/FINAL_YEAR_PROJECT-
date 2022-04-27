
%{
	#include <stdlib.h>
	#include <stdio.h>
	#include "y.tab.h"
	#include "stage4_exprtree.h"

	int number;
        char *variable;

%}
%%

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
"decl"  {return DECL;}
"enddecl" {return ENDDECL;}
"int"   {return INT;}
"str"   {return STR;}
[a-zA-Z][a-zA-Z0-9]*   {variable=strdup(yytext);yylval.no=createTree(0,0,variable,8,NULL,NULL);return ID;}
[0-9]+	{number = atoi(yytext); yylval.no = createTree(number,0,NULL,7,NULL,NULL); return NUM;}

"&"     {return *yytext;}
"+"     {return PLUS;}
"-"	{return MINUS;}
"*"	{printf("MUL DETECTED");return *yytext;}
"/"	{return DIV;}
"="    {printf("= DETECTED\n");return EQUALSTO;}
"<"     {return LT;}
">"     {return GT;}
"<="    {return LE;}
">="    {return GE;}
"=="    {return EQ;}
"!="    {return NE;}
","     {return COMMA;}
[ \t]	{}
[\(\)]	{return *yytext;}
[\[\]]	{return *yytext;}
[\n]	{return NEWLINE;}
.	{printf("%s",strdup(yytext));yyerror("unknown character\n");exit(1);}

%%

int yywrap(void) {
	return 1;
}

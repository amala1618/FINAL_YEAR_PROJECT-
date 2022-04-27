
%{
	#include <stdlib.h>
	#include <stdio.h>
	#include "y.tab.h"
	#include "stage7.1_exprtree.h"

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
"return" {return RETURN;}
"main"   {return MAIN;}
"type"   {return TYPE;}
"endtype" {return ENDTYPE;}
"initialize" {return INITIALIZE;}
"alloc"      {return ALLOC;}
"free"       {return FREE;}
"null"       {return NUL;}
"void"       {return VOID;}

"class"      {return CLASS;}
"endclass"   {return ENDCLASS;}
"self"       {return SELF;}
"extends"    {return EXTENDS;}
"new"        {return NEW;}
"delete"     {return DELETE;}


[a-zA-Z][a-zA-Z0-9]*   {activate=0;variable=strdup(yytext);yylval.no=createTree(0,TLookup("NULL"),variable,8,NULL,NULL,NULL);activate=1;return ID;}
[0-9]+	{number = atoi(yytext); yylval.no = createTree(number,TLookup("INT"),NULL,7,NULL,NULL,NULL); return NUM;}
"%"     {return MOD;}
"&"     {return *yytext;}
"+"     {return PLUS;}
"-"	{return MINUS;}
"*"	{/*printf("MUL DETECTED");*/return *yytext;}
"/"	{return DIV;}
"="    {printf("= DETECTED\n");return EQUALSTO;}
"<"     {return LT;}
">"     {return GT;}
"<="    {return LE;}
">="    {return GE;}
"=="    {return EQ;}
"!="    {return NE;}
","     {return *yytext;}
"{"      {return *yytext;}
"}"       {return *yytext;}
"."      {return *yytext;}
";"      {return *yytext;}
" "+     {}
[ \t]+	{}
[\(\)]	{return *yytext;}
[\[\]]	{return *yytext;}
[\n]+	{}
.	{printf("Unknown char is %s",strdup(yytext));yyerror("unknown character is %s");exit(1);}

%%

int yywrap(void) {
	return 1;
}

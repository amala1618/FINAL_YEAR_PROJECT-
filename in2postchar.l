%{
#include<stdio.h> 
#include "y.tab.h"
%}

%%
[a-zA-z]*   {yylval.cha=strdup(yytext);return ALPHA;}
"+"	    {return *yytext;}
"-"	    {return *yytext;}
[()]	    {return *yytext;}
[\n]        {return NEWLINE;}

%%

yywrap()
{
	return 1;
}



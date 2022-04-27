%{
#include <stdio.h>
#include "y.tab.h"
%}

number  [0-9]+

%%

{number}   {yylval = atoi(yytext);return DIGIT; }
.	   {return *yytext;}

%%
int yywrap()
{
	return 1;
}

%{
#include<stdio.h>
int l=0, s=0, c=0;
%}
%%
\n l++;
([ ])+ s++; 
. c++;

%%

int yywrap()
{if(yytext=="STOP")
  return 1;
else
  return 0;
}
 
int main()
{
    yylex();
     
    printf("\nNo. of lines=%d", l); 
    printf("\nNo. of spaces=%d", s);
    printf("\nNo. of other characters=%d", c);
     
}

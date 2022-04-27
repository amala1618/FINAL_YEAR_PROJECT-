
%{
#include<stdio.h>
int i;
%}
  
%%
  
([a-zA-Z])*[0-9]+([a-zA-Z0-9])*     {i=atoi(yytext);
          if(i%2==0) 
               printf("Numbers Present");
          else
         printf("Numbers Absent");}
%%
   
int yywrap(){}
   
/* Driver code */
int main()
{
   
    yylex();
    return 0;
}

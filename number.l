%{
#include<stdio.h>
#include<string.h>
int i = 0;
int j=0;
int k=0;
%}
  
/* Rules Section*/
%%
([a-zA-Z0-9])*    {i++;}
"\n" 		  {k++;}
"STOP"            {printf("Words:%d\n",i);
		   printf("lines:%d\n",j);
                   printf("chara:%d\n",k);
%%
  
int yywrap(void){}
  
int main()
{   
    // The function that starts the analysis
    yylex();
    return 0;
}

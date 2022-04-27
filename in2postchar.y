%{
#include<stdio.h>
#include<stdlib.h>
%}

%token ALPHA NEWLINE
%union{
		           char *cha;
		      };
%type <cha> ALPHA
%%

start : expr NEWLINE  {
                              printf("\nComplete\n");
                        exit(1);
                      }
  ;

expr:  expr '+' expr        {printf("+ ");}
      | expr '-' expr     {printf("- ");}
  | '(' expr ')'
  | ALPHA             {printf("%c",*($<cha>1));}
  ;

%%

void yyerror(char const *s)
{
    printf("yyerror  %s\n",s);
    return ;
}
int main()
{
  yyparse();
  return 1;
}

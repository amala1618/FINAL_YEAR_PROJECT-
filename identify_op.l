%{
 
#include <stdlib.h>
#include <stdio.h>
 
char str[50] ;
 
%}
 
 
number_sequence [0-9]*
 
%%
 
[+] {
                                printf("PLUS DETECTED\n");
                             }
 
[-] {
                                printf("MINUS DETECTED\n");
                              }
[*] {
                                printf("MULTIPLICATION DETECTED\n");
                              }
[/] {
                                printf("DIVISION OPERATOR DETECTED\n");
                              }
. ;
%%

int yywrap(void){}
 
int main()
{
  printf("\nEnter Calculation");
  yylex();
}

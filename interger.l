%{
     /* Definition section */
    int intege_r=0;
    int float_s=0;
%}
  
/* Rule Section */
DIGIT [0-9]
%%
  
\+?{DIGIT}+            { intege_r++;}  
{DIGIT}*\.{DIGIT}+   {float_s++;}
. ;   
%%
int yywrap(void){}
int main()
{
    yylex();
    printf("\nNo. of Integers: %d", intege_r);
    printf("\nNo. of Floating Numbers: %d", float_s);
    return 0;
}

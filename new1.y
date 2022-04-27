%{

#include <ctype.h>
#include<stdio.h>
#include<stdlib.h>

/* Custom function to print an operator*/
void print_operator(char op);
void yyerror(const char *s);
int yylex();
/* Variable to keep track of the position of the number in the input */
int pos=0;

%}

 /*** YACC Declarations section ***/
%token IF
%token ALPHA
%%

/*** Rules Section ***/
start : expr '\n'		{exit(1);}
      ;

expr: IF INSIDE    {pos++;}
    | ALPHA             {printf("ALPHA ENCOUNTERED,count= %d ",pos);}
    ;
INSIDE:'('ALPHA')''{'ALPHA'}'    {printf("inside")}
      ;
%%


/*** Auxiliary functions section ***/

void print_operator(char c){
    switch(c){
        case '+'  : printf("PLUS ");
                    break;
        case '*'  : printf("MUL ");
                    break;
    }
    return;
}

void yyerror(const char *s)
{
    printf("yyerror");
}

int yylex(){
    char c;
    c = getchar();
    if(c=='i'){c=getchar();if(c=='f'){
         printf("hey If encountered");
	 return IF;
    }}
    else if(c == ' '){
        yylex();         /*This is to ignore whitespaces in the input*/
    }
    else { if(isalpha(c)){return ALPHA;}
	   else{return c;}
    }
}

int main()
{
	yyparse();
	return 1;


}

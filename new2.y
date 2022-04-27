%{

#include<stdio.h>
#include<stdlib.h>

/* Custom function to print an operator*/
void print_operator(char op);

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

expr: IF'('expr')''{'expr'}'     {pos++;print_operator('+');}
    | ALPHA             {printf("NUM%d ",pos);}
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

yyerror(char const *s)
{
    printf("Its an error dude %s",s);
}

yylex(){
    char c;
    c = getchar();
    if(isalpha(c)){
        return ALPHA;
    }
    else if(c == ' '){
        yylex();         /*This is to ignore whitespaces in the input*/
    }
    else {
	if(c=='I'){if(c=='F'){	return IF;}}
        else{

        return c;}
    }

int main()
{
	yyparse();
	return 1;
}

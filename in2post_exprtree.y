%{
	#include <stdlib.h>
	#include <stdio.h>
	#include "in2post_exprtree.h"
	#include "in2post_exprtree.c"
	int yylex(void);
        FILE* fp;
%}

%union{
	struct tnode *no;
	
}
%type <no> expr NUM program END
%token NUM PLUS MINUS MUL DIV END
%left PLUS MINUS
%left MUL DIV

%%

program : expr END	{
					$$ = $2;
                                
				printf("Answer : %d\n",evaluate($1));
				in2post($1);
				exit(1);
			}
		;

expr : expr PLUS expr		{$$ = makeOperatorNode('+',$1,$3);}
     	 | expr MINUS expr  	{$$ = makeOperatorNode('-',$1,$3);}
	 | expr MUL expr	{$$ = makeOperatorNode('*',$1,$3);}
	 | expr DIV expr	{$$ = makeOperatorNode('/',$1,$3);}
	 | '(' expr ')'		{$$ = $2;}
	 | NUM			{$$ = $1;}
	 ;

%%

yyerror(char const *s)
{
    printf("yyerror %s",s);
}


int main(void) {
        int reg=0;
        fp=fopen("Sample1.xsm","w");
	yyparse();
	
	return 0;
}

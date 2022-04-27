%{
	#include <stdlib.h>
	#include <stdio.h>
	#include "stage2_exprtree.h"
	#include "stage2_exprtree.c"
	int yylex(void);
        FILE* fp;
        FILE* yyin;
%}

%union{
	struct tnode *no;
	
}
%type <no> E NUM Program END Slist InputStmt OutputStmt AsgStmt Stmt ID 
%token NUM PLUS MINUS MUL DIV ID READ WRITE BEGIN1 END NEWLINE EQUALSTO
%left PLUS MINUS
%left MUL DIV

%%
Program : BEGIN1 Slist END {$$=$3;codeGen($2,fp);exit(1);}
	| BEGIN1 END       {$$=$2;exit(1);}
        ;

Slist : Slist Stmt        {$$=createTree(0,0,NULL,2,$1,$2);}
      | Stmt             {$$=$1;}
      ;
Stmt : InputStmt          {$$=$1;}
     | OutputStmt      {$$=$1;}
     | AsgStmt        {$$=$1;}
     ;

InputStmt : READ'('ID')'     {$$=createTree(0,0,NULL,0,$3,NULL);}
          ;
OutputStmt : WRITE'('E')'    {$$=createTree(0,0,NULL,1,$3,NULL);}
           ; 
AsgStmt : ID EQUALSTO E        {$$=createTree(0,0,NULL,9,$1,$3);}
	;
E :     E PLUS E        	{$$ = createTree(0,0,NULL,3,$1,$3);}
     	 | E MINUS E  		{$$ = createTree(0,0,NULL,4,$1,$3);}
	 | E MUL E            	{$$ = createTree(0,0,NULL,5,$1,$3);}
	 | E DIV E      	{$$ = createTree(0,0,NULL,6,$1,$3);}
	 | '(' E ')'		{$$ = $2;}
	 | NUM			{$$ = $1;}
         | ID                   {$$= $1;}
	 ;

%%

yyerror(char const *s)
{
    printf("yyerror %s",s);
}

/*main(int argc, char* argv[])
{
    if(argc > 1)
    {
        FILE *fp = fopen(argv[1], "r");
        if(fp)
            yyin = fp;
    }
    yylex();
    return 1;
}*/
int main(int argc,char* argv[]) {
	if(argc>1) {
        FILE *fp = fopen(argv[1], "r");
        if(fp)
            yyin = fp;
    }

	
        int reg=0;
        fp=fopen("Sample1.xsm","w");
        yyparse();
	return 0;
}

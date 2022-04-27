%{
	#include <stdlib.h>
	#include <stdio.h>
	#include "stage3_label_translator.h"
	#include "stage3_label_translator.c"
	int yylex(void);
        FILE* fp;
        FILE* yyin;
%}

%union{
	struct lnode *no;
	
}
%type <no> LABEL 
%token LABEL JMP JNZ JZ CALL NEWLINE

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
E : JMP' ''R'NUM' '  {}
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
        FILE *fpn = fopen(argv[1], "r");
        if(fpn)
            yyin = fpn;
    }
        
	
        int reg=0;
        fp=fopen("Sample1.xsm","w");
        yyin=fp;
        yyparse();
	return 0;
}

/*label append linkedlist*/

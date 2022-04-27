%{
	#include <stdlib.h>
	#include <stdio.h>
	#include "stage3_exprtree.h"
	#include "stage3_exprtree.c"
	int yylex(void);
        FILE* fp;
        FILE* yyin;
%}

%union{
	struct tnode *no;
	

%type <no> E NUM Program END Slist InputStmt OutputStmt AsgStmt Stmt ID Ifstmt Whilestmt
%token NUM PLUS MINUS MUL DIV ID READ WRITE BEGIN1 END NEWLINE EQUALSTO IF then ENDIF Else WHILE ENDWHILE DO EQ NE LT GT LE GE
%left PLUS MINUS
%left MUL DIV LT GT LE GE EQ NE

%%
Program   : BEGIN1 Slist END {$$=$3;codeGen($2,fp);exit(1);}
	  | BEGIN1 END       {$$=$2;exit(1);}
          ;

Slist     : Slist Stmt        {$$=createTree(0,-1,NULL,2,$1,$2);}
          | Stmt             {$$=$1;}
          ;
Stmt      : InputStmt          {$$=$1;}
          | OutputStmt      {$$=$1;}
          | AsgStmt        {$$=$1;}
          |Ifstmt           {$$=$1;}
          |Whilestmt        {$$=$1;}
          ;

InputStmt : READ'('ID')'     {$$=createTree(0,-1,NULL,0,$3,NULL);}
          ;
OutputStmt: WRITE'('E')'    {$$=createTree(0,-1,NULL,1,$3,NULL);}
          ; 
AsgStmt   : ID EQUALSTO E        {$$=createTree(0,-1,NULL,9,$1,$3);}
	  ;
Ifstmt    :IF'('E')' then Slist Else Slist ENDIF {struct tnode *M=createTree(0,-1,NULL,18,$3,$6);$$=createTree(0,-1,NULL,19,M,$8);}
          | IF'('E')' then Slist ENDIF           {$$=createTree(0,-1,NULL,18,$3,$6);}
          ;
Whilestmt :WHILE'('E')' DO Slist ENDWHILE      {$$=createTree(0,-1,NULL,17,$3,$6);}
	  ;
E         : E PLUS E        	{$$ = createTree(0,-1,NULL,3,$1,$3);}
     	  | E MINUS E  		{$$ = createTree(0,-1,NULL,4,$1,$3);}
	  | E MUL E            	{$$ = createTree(0,-1,NULL,5,$1,$3);}
	  | E DIV E      	{$$ = createTree(0,-1,NULL,6,$1,$3);}
          | E LT E               {$$=createTree(0,-1,NULL,11,$1,$3);}
          | E GT E             {$$=createTree(0,-1,NULL,12,$1,$3);}
          | E LE E              {$$=createTree(0,-1,NULL,13,$1,$3);}
          | E GE E   {$$=createTree(0,-1,NULL,14,$1,$3);}
         | E NE E    {$$=createTree(0,-1,NULL,15,$1,$3);}
          | E EQ E    {$$=createTree(0,-1,NULL,16,$1,$3);}
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

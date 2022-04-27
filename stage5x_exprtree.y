%{
	#include <stdlib.h>
	#include <stdio.h>
        #include <string.h>
	#include "stage4_exprtree.h"
	#include "stage4_exprtree.c"
	int yylex(void);
        FILE* fp;
        FILE* yyin;
        extern int yylineno;
%}
%union{
	struct tnode *no;
	
}

%type <no> E NUM Program END Slist InputStmt OutputStmt AsgStmt Stmt ID Ifstmt Whilestmt Entire_Program Var
%token NUM PLUS MINUS MUL DIV ID READ WRITE BEGIN1 END NEWLINE EQUALSTO IF then ENDIF Else WHILE ENDWHILE DO EQ NE LT GT LE GE DECL ENDDECL INT STR COMMA 
%left PLUS MINUS
%left '*' DIV 
%left LT GT LE GE 
%left EQ NE
%%

Entire_Program: Declarations Program  {$$=$2;fprintf(fp,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\nMOV SP, %d\n",0,2056,0,0,0,0,1,0,bind+1);codeGen($2,fp);fprintf(fp,"INT 10\n");exit(1);}
	      ;
Declarations : DECL DeclList ENDDECL      {curr=headsymb;print_symbol_table();activate=1;}
	     | DECL ENDDECL               {}
	     ;

DeclList     :DeclList Decl              {}
	     | Decl                      {}
	     ;

Decl         :Type VarList               {}
	     ;

Type         :INT                        {curr_type=0;}
	     |STR                        {curr_type=1;}
             ;

VarList      :VarList COMMA ID                {Install($3->varname,curr_type,1,1,1);}
	     |VarList COMMA '*' ID                                {Install($4->varname,curr_type,1,-1,-1);}
             |VarList COMMA ID '['NUM']'            {Install($3->varname,curr_type,1,$5->val,1);}
             |VarList COMMA ID '[' NUM ']' '[' NUM ']'       {Install($3->varname,curr_type,1,$5->val,$8->val);}

	     |ID                          {Install(($1->varname),curr_type,1,1,1);}
             |'*' ID                                {Install($2->varname,curr_type,1,-1,-1);}
             |ID '[' NUM ']'                  {Install($1->varname,curr_type,1,$3->val,1);}
             |ID '[' NUM ']' '[' NUM ']'    {Install($1->varname,curr_type,1,$3->val,$6->val);}

             ;

Program   : Slist {$$=$1;}
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

InputStmt :READ'('Var')'     {$$=createTree(0,-1,NULL,0,$3,NULL);}
	  ;
OutputStmt: WRITE'('E')'    {$$=createTree(0,-1,NULL,1,$3,NULL);}
          ;

AsgStmt   : Var EQUALSTO E        {$$=createTree(0,-1,NULL,9,$1,$3);}
          ;

Ifstmt    :IF'('E')' then Slist Else Slist ENDIF {struct tnode *M=createTree(0,-1,NULL,18,$3,$6);$$=createTree(0,-1,NULL,19,M,$8);}
          | IF'('E')' then Slist ENDIF           {$$=createTree(0,-1,NULL,18,$3,$6);}
          ;
Whilestmt :WHILE'('E')' DO Slist ENDWHILE      {$$=createTree(0,-1,NULL,17,$3,$6);}
	  ;

E         : E PLUS E        	{$$ = createTree(0,-1,NULL,3,$1,$3);}
     	  | E MINUS E  		{$$ = createTree(0,-1,NULL,4,$1,$3);}
	  | E '*' E            	{$$ = createTree(0,-1,NULL,5,$1,$3);}
	  | E DIV E      	{$$ = createTree(0,-1,NULL,6,$1,$3);}
          | E LT E               {$$=createTree(0,-1,NULL,11,$1,$3);}
          | E GT E             {$$=createTree(0,-1,NULL,12,$1,$3);}
          | E LE E              {$$=createTree(0,-1,NULL,13,$1,$3);}
          | E GE E   {$$=createTree(0,-1,NULL,14,$1,$3);}
          | E NE E    {$$=createTree(0,-1,NULL,15,$1,$3);}
          | E EQ E    {$$=createTree(0,-1,NULL,16,$1,$3);}
	  | '(' E ')'		{$$ = $2;}
	  | NUM			{$$ = $1;}
          |Var        {$$=$1;}
          ;

Var	  : ID                            {$$=$1;}
          |ID '['E ']'                     {$$=createTree(0,-1,$1->varname,10,$3,NULL);}
          |ID '['E ']' '[' E ']'       {$$=createTree(0,-1,$1->varname,10,$3,$6);}
          |'&' ID                   {$$=createTree(0,$2->type,$2->varname,21,$2,NULL);}
          ;


%%

yyerror(char const *s)
{  
    printf("yyerror %s",s);
}

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

%{
	#include <stdlib.h>
	#include <stdio.h>
        #include <string.h>
	#include "stage5_exprtree.h"
	#include "stage5_exprtree.c"
	int yylex(void);
        FILE* fp;
        FILE* yyin;
        extern int yylineno;
%}
%union{
	struct tnode *no;
        struct Paramstruct *pno;
        struct Gsymbol *gno;
        int number;
        
}
%type <pno> Param ParamList
%type <number> Type Program
%type <gno> Gid GidList
%type <no> E NUM END Slist InputStmt OutputStmt AsgStmt Stmt ID Ifstmt Whilestmt Var ArgList Body ReturnStmt
%token NUM PLUS MINUS MUL DIV ID READ WRITE BEGIN1 END NEWLINE EQUALSTO IF then ENDIF Else WHILE ENDWHILE DO EQ NE LT GT LE GE DECL ENDDECL INT STR RETURN MAIN
%left PLUS MINUS
%left '*' DIV  
%left LT GT LE GE 
%left EQ NE
%%
Program :GdeclBlock FdefBlock MainBlock {$$=1;printf("Hi in program with function declaration an d definition");/*fprintf(fp,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\nMOV SP, %d\n",0,2056,0,0,0,0,1,0,bind+1);codeGen($3,fp);fprintf(fp,"INT 10\n")*/;exit(1);}
	| GdeclBlock MainBlock {$$=1;printf("Hi in Program");/*fprintf(fp,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\nMOV SP, %d\n",0,2056,0,0,0,0,1,0,bind+1);codeGen($2,fp);fprintf(fp,"INT 10\n")*/exit(1);}
        | MainBlock        {$$=1;/*fprintf(fp,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\nMOV SP, %d\n",0,2056,0,0,0,0,1,0,bind+1);codeGen($1,fp);fprintf(fp,"INT 10\n");*/exit(1);}
        ;

GdeclBlock :DECL GdeclList ENDDECL {curr=headsymb;print_symbol_table();fprintf(fp,"MOV SP, %d\n",bind+1);fprintf(fp,"CALL F0\n");fprintf(fp,"INT 10\n");}
	   | DECL ENDDECL
           ;

GdeclList :GdeclList GDecl 
	  | GDecl
          ;
GDecl     :Type GidList                 {               curr=headsymb;
	       						while($2 != NULL) {
                                                        curr=headsymb;
			     				struct Gsymbol* temp = GLookup($2->name);
							temp->type = $1;
							$2 = $2->next;}
                                                       
					}
          ;

GidList :GidList',' Gid {$$=$3;}
	| Gid           {$$=$1;}
        ;

Gid     : ID          { GInstall($1->varname,curr_type,1,1,1,NULL,0);curr=headsymb;$$=GLookup($1->varname);}

	| ID'['NUM']'  {GInstall($1->varname,curr_type,$3->val,$3->val,1,NULL,0);curr=headsymb;$$=GLookup($1->varname);}

        | ID'('ParamList')'{GInstall($1->varname,curr_type, 1,1,1,$3,getFlabel());curr=headsymb;$$=GLookup($1->varname);}
        | ID'('')'{GInstall($1->varname,curr_type, 1,1,1,NULL,0);curr=headsymb;$$=GLookup($1->varname);}

        ;

FdefBlock :FdefBlock Fdef
	  | Fdef
          ;

Fdef :Type ID '(' ParamList ')''{' LdeclBlock Body '}' {fucn_check_name($1,$2->varname,$4);codeGen_f($8,$2->varname,fp);Lsymbol_rst();activate=0;}
     |Type ID '('ParamList')''{'Body'}'                {printf("HI in fdef paramlist body");fucn_check_name($1,$2->varname,$4);codeGen_f($7,$2->varname,fp);Lsymbol_rst();activate=0;}
     |Type ID '(' ')''{' LdeclBlock Body '}'           {fucn_check_name($1,$2->varname,NULL);codeGen_f($7,$2->varname,fp);Lsymbol_rst();activate=0;}
     |Type ID '('')''{'Body'}'                         {fucn_check_name($1,$2->varname,NULL);codeGen_f($6,$2->varname,fp);Lsymbol_rst();activate=0;}

     ;

ReturnStmt	:RETURN E  {$$=createTree(0,-1,NULL,23,$2,NULL,NULL);}
	;
MainBlock : Type MAIN '(' ')'  '{'LdeclBlock Body '}'	{printf("Hi in mainblock");if($1!=0){
	                                                      printf("Function main expects integer return type");exit(1);};codeGen_f($7,"main",fp);Lsymbol_rst(); }
          ;
Body : BEGIN1 Slist ReturnStmt END  {$$=createTree(0,-1,NULL,2,$2,$3,NULL);}
     |BEGIN1 Slist END                 {$$=createTree(0,-1,NULL,2,$2,NULL,NULL);}
     |BEGIN1 ReturnStmt END              {$$=createTree(0,-1,NULL,2,$2,NULL,NULL);}
     ;

ParamList :ParamList ',' Param {$$=PInstall($1,$3);createLsymbolEntries($3);}
          |Param               {$$=$1;createLsymbolEntries($1);}

          ;

Param : Type ID       {$$=PInstall_each($2->varname,$1,headsymb_p);}
      ;

LdeclBlock :DECL LDecList ENDDECL {printf("Hi in local declaration");activate=1;}
	   | DECL ENDDECL         {activate=1;}
           ;

LDecList :LDecList LDecl 
	 | LDecl 
         ;

LDecl :Type IdList 
      ;

IdList :IdList','ID      {LInstall($3->varname,curr_type);} 
       | ID              {LInstall($1->varname,curr_type);}
       ;

Type : INT               {$$=0;curr_type=0;}
     | STR               {$$=1;curr_type=1;}
     ;

Slist     : Slist Stmt        {$$=createTree(0,-1,NULL,2,$1,$2,NULL);}
          | Stmt             {$$=$1;}
          ;
Stmt      : InputStmt          {$$=$1;}
          | OutputStmt      {$$=$1;}
          | AsgStmt        {$$=$1;}
          |Ifstmt           {$$=$1;}
          |Whilestmt        {$$=$1;}
          ;

InputStmt :READ'('Var')'     {$$=createTree(0,-1,NULL,0,$3,NULL,NULL);}
	  ;
OutputStmt: WRITE'('E')'    {$$=createTree(0,-1,NULL,1,$3,NULL,NULL);}
          ;

AsgStmt   : Var EQUALSTO E        {$$=createTree(0,-1,NULL,9,$1,$3,NULL);}
          ;

Ifstmt    :IF'('E')' then Slist Else Slist ENDIF {$$=createTree(0,-1,NULL,19,$3,$6,$8);}
          | IF'('E')' then Slist ENDIF           {$$=createTree(0,-1,NULL,18,$3,$6,NULL);}
          ;
Whilestmt :WHILE'('E')' DO Slist ENDWHILE      {$$=createTree(0,-1,NULL,17,$3,$6,NULL);}
	  ;

E         : E PLUS E        	{$$ = createTree(0,-1,NULL,3,$1,$3,NULL);}
     	  | E MINUS E  		{$$ = createTree(0,-1,NULL,4,$1,$3,NULL);}
	  | E '*' E            	{$$ = createTree(0,-1,NULL,5,$1,$3,NULL);}
	  | E DIV E      	{$$ = createTree(0,-1,NULL,6,$1,$3,NULL);}
          | E LT E               {$$=createTree(0,-1,NULL,11,$1,$3,NULL);}
          | E GT E             {$$=createTree(0,-1,NULL,12,$1,$3,NULL);}
          | E LE E              {$$=createTree(0,-1,NULL,13,$1,$3,NULL);}
          | E GE E   {$$=createTree(0,-1,NULL,14,$1,$3,NULL);}
          | E NE E    {$$=createTree(0,-1,NULL,15,$1,$3,NULL);}
          | E EQ E    {$$=createTree(0,-1,NULL,16,$1,$3,NULL);}
	  | '(' E ')'		{$$ = $2;}
	  | NUM			{$$ = $1;}
          |Var        {$$=$1;}
          |ID'('')' {$$=createTree(0,-1,$1->varname,22,NULL,NULL,NULL);} 
          | ID'('ArgList')'  {$$=createTree(0,-1,$1->varname,22,$3,NULL,NULL);}
          ;

ArgList  :ArgList',' E                   {$1->next=$3;$$=$1;}
          | E                             {$$=$1;}
          ;
Var	  : ID                            {$$=$1;}
          |ID '['E ']'                     {$$=createTree(0,-1,$1->varname,10,$3,NULL,NULL);}
          |ID '['E ']' '[' E ']'       {$$=createTree(0,-1,$1->varname,10,$3,$6,NULL);}
          |'&' ID                   {$$=createTree(0,$2->type,$2->varname,21,$2,NULL,NULL);}
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
        fprintf(fp,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,1,0);
        yyparse();
	return 0;
}

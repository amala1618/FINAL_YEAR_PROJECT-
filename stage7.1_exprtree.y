%{
	#include <stdlib.h>
	#include <stdio.h>
        #include <string.h>
	#include "stage7.1_exprtree.h"
	#include "stage7.1_exprtree.c"
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
        char *ch;
        struct Typetable *Type_Table;
        struct Fieldlist *Field_List;
        struct Typeholder *Th;
        
}
%type <Field_List> FieldDeclList FieldDecl
%type <Type_Table> TypeDef TypeName
%type <Th> Type
%type <pno> Param PList ParamList
%type <number> Program
%type <gno> Gid GidList
%type <no> E NUM END Slist InputStmt OutputStmt AsgStmt Stmt ID Ifstmt Whilestmt Var ArgList Body ReturnStmt Field NUL FieldFunction Cname
%token CLASS ENDCLASS SELF EXTENDS NEW DELETE NUM PLUS MINUS MUL DIV ID READ WRITE BEGIN1 END EQUALSTO IF then ENDIF Else WHILE ENDWHILE DO EQ NE LT GT LE GE DECL ENDDECL INT STR RETURN MAIN TYPE ENDTYPE INITIALIZE ALLOC FREE NUL VOID MOD
%left PLUS MINUS MOD
%left '*' DIV  
%left LT GT LE GE 
%left EQ NE
%%

Program :TypeDefBlock GdeclBlock FdefBlock MainBlock {$$=1;exit(1);}
	| TypeDefBlock GdeclBlock MainBlock {$$=1;exit(1);}
        | TypeDefBlock MainBlock       {$$=1;exit(1);}
        |GdeclBlock FdefBlock MainBlock {$$=1;exit(1);}
	| GdeclBlock MainBlock {$$=1;exit(1);}
        | MainBlock        {$$=1;exit(1);}
        |TypeDefBlock ClassDefBlock GdeclBlock FdefBlock MainBlock {$$=1;exit(1);}
	| TypeDefBlock ClassDefBlock GdeclBlock MainBlock {$$=1;exit(1);}
        | TypeDefBlock ClassDefBlock MainBlock       {$$=1;exit(1);}
        |GdeclBlock ClassDefBlock FdefBlock MainBlock {$$=1;exit(1);}
	| GdeclBlock ClassDefBlock MainBlock {$$=1;exit(1);}

        ;
ClassDefBlock : CLASS ClassDefList ENDCLASS {printf("HI CLASS DEF DONE,ABOUT TO PRINT CLASS TABLE STAY TUNED!!");printclasstable();}
      |CLASS ENDCLASS
	      ;
ClassDefList  : ClassDefList ClassDef
	      | ClassDef
              ;
ClassDef      : Cname '{'DECL Fieldlists MethodDecl ENDDECL MethodDefns '}' {CFindex = 0; CMindex = 0;Cptr=NULL;}
	      ;
Cname         : ID       	{Cptr = CInstall($1->varname,NULL);$$=$1;}         
	      | ID EXTENDS ID	{Cptr = CInstall($1->varname,$3->varname);$$=$1;}
	      ;
Fieldlists	: Fieldlists Fld   
	      |
              ;     
Fld         : TypeName ID ';'		{printf("Attribute Declaration in Progress!!");Class_Finstall(Cptr,$1->name,$2->varname);} 
	    ;
MethodDecl : MethodDecl MDecl 
	   | MDecl 
           ;
MDecl      : TypeName ID '(' ParamList ')' ';' {Class_Minstall(Cptr,$2->varname,TLookup($1->name),$4);Lsymbol_rst();headsymb_p=NULL;}
	    |TypeName ID '(' ')' ';' {Class_Minstall(Cptr,$2->varname,TLookup($1->name),NULL);Lsymbol_rst();headsymb_p=NULL;} 
           ;
MethodDefns : MethodDefns Fdef
	    | Fdef
            ;


TypeDefBlock  : TYPE TypeDefList ENDTYPE  {print_Typetable();printf("type declaration done");}	                                               
              ;

TypeDefList   : TypeDefList TypeDef
	      | TypeDef                    {printf("Type 1 stroed as typeDefList");}
              ;

TypeDef       : ID '{'{Tinstall($1->varname,0,NULL);} FieldDeclList '}'   {struct Typetable *t=TLookup($1->varname);t->fields=Fhead;t->size=GetSize(t);Fhead=NULL;FieldNo=0;Findex=0; }
	                    ;

FieldDeclList : FieldDeclList FieldDecl {$2->next = $1;$$ = $2; Fhead=$2; FieldNo++;}
	      | FieldDecl                {$$=$1;}
              ;

FieldDecl    : TypeName ID  ';'         {size=size+1;$$=Finstall($2->varname,$1->name);}
	     ;

TypeName     : INT                   {$$=TLookup("INT"); }	     
	     | STR                   {$$=TLookup("STR"); }
             |VOID                   {$$=TLookup("VOID"); }
             | ID                    {$$=TLookup($1->varname); }
       	     ;
GdeclBlock :DECL GdeclList ENDDECL {curr=headsymb;print_symbol_table();fprintf(fp,"MOV SP, %d\n",bind+1);fprintf(fp,"CALL F0\n");fprintf(fp,"INT 10\n");}
	   | DECL ENDDECL
           ;

GdeclList :GdeclList GDecl 
	  | GDecl
          ;
GDecl     :Type GidList        ';'         {            curr=headsymb;
	       						while($2 != NULL) {
                                                        curr=headsymb;
			     				struct Gsymbol* temp = GLookup($2->name);
							temp->type = $1->Ttype;
                                                        temp->Ctype = $1->Ctype;
							//$2 = $2->next;
							$2=$2->left;}
                                                        
                                                       
					}
          ;

GidList :GidList',' Gid {$3->left=$1;$$=$3;}
	| Gid           {$1->left=NULL;$$=$1;}
        ;

Gid     : ID          { GInstall($1->varname,curr_type,1,1,1,NULL,0,NULL);curr=headsymb;$$=GLookup($1->varname);}

	| ID'['NUM']'  {GInstall($1->varname,curr_type,$3->val,$3->val,1,NULL,0,NULL);curr=headsymb;$$=GLookup($1->varname);}

        | ID'('ParamList')'{GInstall($1->varname,curr_type, 1,1,1,$3,getFlabel(),NULL);curr=headsymb;$$=GLookup($1->varname);}
        | ID'('')'{GInstall($1->varname,curr_type, 1,1,1,NULL,0,NULL);curr=headsymb;$$=GLookup($1->varname);}

        ;

FdefBlock :FdefBlock Fdef
	  | Fdef
          ;

Fdef :Type ID '(' ParamList ')''{' LdeclBlock Body '}' {/*fucn_check_name($1->Ttype,$2->varname,$4); struct Paramstruct *ptemp;

     							if(Cptr!=NULL){
								ptemp=PInstall_each("self",TLookup("VOID"),headsymb_p);
								ptemp=PInstall($4,ptemp);}
							else{ptemp=$4;}
							createLsymbolEntries(ptemp);*/
                                                        //local_binding_stored_here=-3;
                                                        //createLsymbolEntries($4);
							if(Cptr!=NULL){
									struct Lsymbol *ltemp=LLookup("self");
									ltemp->binding=local_binding_stored_here;
                                                        printf("%d",LLookup("self")->binding);//exit(1);
							}
                                                        local_binding_stored_here=-3;
							codeGen_f($8,$2->varname,fp);
							Lsymbol_rst();
							activate=0;}
     |Type ID '('ParamList')''{'Body'}'     {/*fucn_check_name($1->Ttype,$2->varname,$4);
                                                         struct Paramstruct *ptemp;
                                                        if(Cptr!=NULL){
								ptemp=PInstall_each("self",TLookup("VOID"),headsymb_p);
								ptemp=PInstall($4,ptemp);}
							else{ptemp=$4;}
							createLsymbolEntries(ptemp);*/
							//local_binding_stored_here=-3;


                                                        //createLsymbolEntries($4);
							if(Cptr!=NULL){
									struct Lsymbol *ltemp=LLookup("self");
									ltemp->binding=local_binding_stored_here;}
                                                        local_binding_stored_here=-3;

							 //printf("%d",LLookup("self")->binding);//exit(1);
							codeGen_f($7,$2->varname,fp);Lsymbol_rst();activate=0;}
     |Type ID '(' ')''{' LdeclBlock Body '}'           {/*fucn_check_name($1->Ttype,$2->varname,NULL);
							 struct Paramstruct *ptemp; 
							if(Cptr!=NULL){
								ptemp=PInstall_each("self",TLookup("VOID"),headsymb_p);
								ptemp=PInstall(NULL,ptemp);}
							else{ptemp=NULL;}
							createLsymbolEntries(ptemp);*/
                                                        //local_binding_stored_here=-3;
							//createLsymbolEntries($1);
 							if(Cptr!=NULL){
									struct Lsymbol *ltemp=LLookup("self");
									ltemp->binding=local_binding_stored_here;}
                                                        //printf("%d",LLookup("self")->binding);//exit(1);
							 local_binding_stored_here=-3;

							codeGen_f($7,$2->varname,fp);
						        Lsymbol_rst();activate=0;}
     |Type ID '('')''{'Body'}'                         {/*fucn_check_name($1->Ttype,$2->varname,NULL);
                                                         struct Paramstruct *ptemp;
							 if(Cptr!=NULL){
								ptemp=PInstall_each("self",TLookup("VOID"),headsymb_p);
								ptemp=PInstall(NULL,ptemp);}
							else{ptemp=NULL;}
							createLsymbolEntries(ptemp);*/
							//local_binding_stored_here=-3;
                                                        //createLsymbolEntries($1); 
							if(Cptr!=NULL){
									struct Lsymbol *ltemp=LLookup("self");
									ltemp->binding=local_binding_stored_here;
                                                        printf("%d",LLookup("self")->binding);//exit(1);
								}
							 local_binding_stored_here=-3;

							codeGen_f($6,$2->varname,fp);
							Lsymbol_rst();activate=0;}

     ;

ReturnStmt	:RETURN E ';' {$$=createTree(0,TLookup("NULL"),NULL,23,$2,NULL,NULL);}
	;
MainBlock : Type MAIN '(' ')'  '{'LdeclBlock Body '}'	{printf("Hi in mainblock");if($1->Ttype!=TLookup("INT")){
	                                                      printf("Function main expects integer return type");exit(1);};codeGen_f($7,"main",fp);Lsymbol_rst(); }
          ;
Body : BEGIN1 Slist ReturnStmt END  {activate=1;$$=createTree(0,TLookup("NULL"),NULL,2,$2,$3,NULL);}
     |BEGIN1 Slist END                 {activate=1;$$=createTree(0,TLookup("NULL"),NULL,2,$2,NULL,NULL);}
     |BEGIN1 ReturnStmt END              {activate=1;$$=createTree(0,TLookup("NULL"),NULL,2,$2,NULL,NULL);}
     ;
ParamList:PList             {$$=$1;createLsymbolEntries($1);}

PList :PList ',' Param {$$=PInstall($1,$3);}
          |Param               {$$=$1;}

          ;

Param : Type ID       {$$=PInstall_each($2->varname,$1->Ttype,headsymb_p);}
      ;


LDecList :LDecList LDecl {} 
	 | LDecl         {}
         ;

LDecl :Type IdList ';'     {}
      ;

IdList :IdList','ID      {LInstall($3->varname,curr_type);} 
       | ID              {LInstall($1->varname,curr_type);}
       ;

LdeclBlock :DECL LDecList ENDDECL {activate=1;if(Cptr!=NULL){LInstall("self",TLookup("VOID"));}/*if(Cptr!=NULL){struct Paramstruct *Ptemp=PInstall_each("self",TLookup("VOID"),headsymb_p);createLsymbolEntries(Ptemp);}*/}
      | DECL ENDDECL  {activate=1;if(Cptr!=NULL){LInstall("self",TLookup("VOID"));}/*if(Cptr!=NULL){struct Paramstruct *Ptemp=PInstall_each("self",TLookup("VOID"),headsymb_p);createLsymbolEntries(Ptemp);}*/}
      ;
Type : INT               {$$->Ttype=TLookup("INT");curr_type=$$->Ttype;$$->Ctype=NULL;}
     | STR               {$$->Ttype=TLookup("STR");curr_type=$$->Ttype;$$->Ctype=NULL;}
     |ID                 {struct Typetable *Ttemp=TLookup($1->varname);if(Ttemp==NULL){
			  struct Classtable *Ctemp = CLookup($1->varname);
         		  $$->Ctype = Ctemp;$$->Ttype = NULL;}
                          else{$$->Ttype = Ttemp;$$->Ctype = NULL;}curr_type=Ttemp;}
    ;
Slist     : Slist Stmt        {$$=createTree(0,TLookup("NULL"),NULL,2,$1,$2,NULL);}
          | Stmt             {$$=$1;}
          ;
Stmt      : InputStmt  ';'     {$$=$1;}
          | OutputStmt ';'     {$$=$1;}
          | AsgStmt    ';'     {$$=$1;}
          |Ifstmt      ';'     {$$=$1;}
          |Whilestmt   ';'     {$$=$1;}
          |Var EQUALSTO INITIALIZE'('')' ';' {$$=createTree(0,TLookup("INT"),NULL,27,$1,NULL,NULL);}
          |Var EQUALSTO ALLOC'('')'  ';'   {$$=createTree(0,TLookup("INT"),NULL,25,$1,NULL,NULL);}
          |Var EQUALSTO NEW'('ID')'';' {if(CLookup($5->varname)==NULL){printf("Only CLass objs can be allocated this way!");exit(1);}else{$1->Ctype=CLookup($5->varname);$$=createTree(0,TLookup("INT"),NULL,25,$1,NULL,NULL);}}
          |FREE'('Field')'  ';'   {$$=createTree(0,TLookup("INT"),NULL,26,$3,NULL,NULL);}
          |FREE'('Var')'    ';'    {$$=createTree(0,TLookup("INT"),NULL,26,$3,NULL,NULL);}
          ;


InputStmt :READ'('Var')'     {$$=createTree(0,TLookup("NULL"),NULL,0,$3,NULL,NULL);}
	  ;
OutputStmt: WRITE'('E')'    {$$=createTree(0,TLookup("NULL"),NULL,1,$3,NULL,NULL);}
          ;

AsgStmt   : Var EQUALSTO E        {$$=createTree(0,TLookup("NULL"),NULL,9,$1,$3,NULL);}
	  | Field EQUALSTO E      {$$=createTree(0,TLookup("NULL"),NULL,9,$1,$3,NULL);}
          ;

Ifstmt    :IF'('E')' then Slist Else Slist ENDIF {$$=createTree(0,TLookup("NULL"),NULL,19,$3,$6,$8);}
          | IF'('E')' then Slist ENDIF           {$$=createTree(0,TLookup("NULL"),NULL,18,$3,$6,NULL);}
          ;
Whilestmt :WHILE'('E')' DO Slist ENDWHILE      {$$=createTree(0,TLookup("NULL"),NULL,17,$3,$6,NULL);}
	  ;

E         : E PLUS E        	{$$ = createTree(0,TLookup("NULL"),NULL,3,$1,$3,NULL);}
     	  | E MINUS E  		{$$ = createTree(0,TLookup("NULL"),NULL,4,$1,$3,NULL);}
	  | E '*' E            	{$$ = createTree(0,TLookup("NULL"),NULL,5,$1,$3,NULL);}
	  | E DIV E      	{$$ = createTree(0,TLookup("NULL"),NULL,6,$1,$3,NULL);}
          | E MOD E      	{$$ = createTree(0,TLookup("NULL"),NULL,29,$1,$3,NULL);}
          | E LT E               {$$=createTree(0,TLookup("NULL"),NULL,11,$1,$3,NULL);}
          | E GT E             {$$=createTree(0,TLookup("NULL"),NULL,12,$1,$3,NULL);}
          | E LE E              {$$=createTree(0,TLookup("NULL"),NULL,13,$1,$3,NULL);}
          | E GE E   {$$=createTree(0,TLookup("NULL"),NULL,14,$1,$3,NULL);}
          | E NE E    {$$=createTree(0,TLookup("NULL"),NULL,15,$1,$3,NULL);}
          | E EQ E    {$$=createTree(0,TLookup("NULL"),NULL,16,$1,$3,NULL);}
	  | '(' E ')'		{$$ = $2;}
	  | NUM			{$$ = $1;}
          |Var        {$$=$1;}
          |ID'('')' {$$=createTree(0,TLookup("NULL"),$1->varname,22,NULL,NULL,NULL);} 
          | ID'('ArgList')'  {$$=createTree(0,TLookup("NULL"),$1->varname,22,$3,NULL,NULL);}
          |Field {$$=$1;}
          |FieldFunction {$$=$1;}
          |NUL   {$$=createTree(0,TLookup("NULL"),NULL,28,NULL,NULL,NULL);}
          ;
FieldFunction : SELF '.' ID '(' ArgList ')'  {$$=createTree(0,TLookup("NULL"),NULL,28,NULL,NULL,NULL);}
	      |ID '.'ID '('ArgList ')'  {curr=headsymb;struct Gsymbol *Gtemp=GLookup($1->varname);if(Gtemp->Ctype==NULL){
						printf("No Object is declared!!");
						exit(1);} 
					struct Memberfunclist *Mtemp=Class_Mlookup(Gtemp->Ctype,$3->varname);
				    	if(Mtemp==NULL){
						printf("No such Methods are avaible !!");
						exit(1);}
					$$=createTree(Mtemp->Flabel,TLookup("NULL"),NULL,31,$1,$3,$5);}

              |ID '.'ID '(' ')'         {curr=headsymb;struct Gsymbol *Gtemp=GLookup($1->varname);if(Gtemp->Ctype==NULL){
						printf("No Object is declared!!");
						exit(1);} 
					struct Memberfunclist *Mtemp=Class_Mlookup(Gtemp->Ctype,$3->varname);
				    	if(Mtemp==NULL){
						printf("No such Methods are avaible !!");
						exit(1);}
					$$=createTree(Mtemp->Flabel,TLookup("NULL"),NULL,31,$1,$3,NULL);}

	      |Field '.' ID '(' ArgList ')'  {$$=createTree(0,TLookup("NULL"),NULL,28,NULL,NULL,NULL);}
              ;	
Field:Field'.'ID                        {struct tnode* temp = $1; 			
                                        while(temp->right!=NULL){temp = temp->right;}
				        struct Fieldlist *Ftemp = FLookup(temp->type, $3->varname);
                         		if(Ftemp == NULL){
						printf("Field is not a member of the datatype");exit(1);}
                                        $3->type = Ftemp->type;
	                		$3->val = Ftemp->fieldIndex;
					$1->type = Ftemp->type;
					$1->nodetype = 24;
					temp->right = $3; $$ =  $1;}
     |ID'.'ID {                         $1->right = $3; curr=headsymb;	
				        struct Gsymbol *Gtemp = GLookup($1->varname);
				        struct Lsymbol *Ltemp = LLookup($1->varname);
				        if(Ltemp==NULL){
						if(Gtemp==NULL){printf("Variable not declared\n"); exit(1); }
					$1->type = Gtemp->type;	$1->Gentry= Gtemp;$1->Lentry= NULL;}	
				        else{struct Lsymbol* Ltemp = LLookup($1->varname);
						$1->type = Ltemp->type;
	                        		$1->Gentry = NULL;
	                        		$1->Lentry = Ltemp;	}	
					struct Fieldlist *Ftemp = FLookup($1->type, $3->varname);
                               		// printf("%s %s \n",$1->type,$3->varname);
					if(Ftemp==NULL){
						printf("Field is not a member of the datatype\n");exit(1); }
					$1->type = Ftemp->type;
					$3->type = Ftemp->type;
					$3->val = Ftemp->fieldIndex;
					$1->nodetype = 24;
					$$ = $1;printf("Type of %s is %s\n",$1->type->name,$1->varname);
                                	printf("Type of %s is %s\n",$3->type->name,$3->varname);}
    

    | SELF'.'ID {
					if(Cptr == NULL){
						printf("Self cannot be used outside a class");	exit(1);}
					$$ = createTree(0, TLookup("NULL"),NULL, 30, NULL, $3,NULL);
					if(Cptr!=NULL){
									struct Lsymbol *ltemp=LLookup("self");
									ltemp->binding=local_binding_stored_here-1;}
                                        printf("\nSELF BINDING IS !!%d\n",LLookup("self")->binding);//exit(1);
					$$->Lentry = LLookup("self");
					struct Fieldlist * Ftemp = Class_Flookup(Cptr, $3->varname);
					if(Ftemp == NULL){
							printf("Variable not a memberfield\n");exit(1);	}
					$$->type = Ftemp->type;
					$3->type = Ftemp->type;
					$3->Ctype = Ftemp->Ctype;
					$3->val = Ftemp->fieldIndex;
					$$->val = Ftemp->fieldIndex;

                }
    ;

ArgList  :ArgList',' E                   {/*$3->next=$1;$$=$3;*/struct tnode* temp=$1;while($1->next!=NULL){$1=$1->next;}$1->next=$3;$$=temp;}
          | E                            {$$=$1;}
          ;
Var	  : ID                            {$$=createTree(0,TLookup("NULL"),$1->varname,8,NULL,NULL,NULL);}
          |ID '['E ']'                     {$$=createTree(0,TLookup("NULL"),$1->varname,10,$3,NULL,NULL);}
          |ID '['E ']' '[' E ']'       {$$=createTree(0,TLookup("NULL"),$1->varname,10,$3,$6,NULL);}
          |'&' ID                   {$$=createTree(0,$2->type,$2->varname,21,$2,NULL,NULL);}
          ;


%%
/*        ;

|E EQ ALLOC'('')'     {$$=createTree(0,TLookup("INT"),NULL,26,$1,NULL,NULL);}
          |FREE'('E')'     {$$=createTree(0,TLookup("INT"),NULL,27,$3,NULL,NULL);}
          |E EQ INITIALIZE'('')'{$$=createTree(0,TLookup("INT"),NULL,28,$1,NULL,NULL);}

TypeDefBlock  : TYPE TypeDefList ENDTYPE
	      |                                               
              ;

TypeDefList   : TypeDefList TypeDef
	      | TypeDef
              ;

TypeDef       : ID '{' FieldDeclList '}'   { Tptr = TInstall($1->varname,size,$3); }
	                    ;

FieldDeclList : FieldDeclList FieldDecl
	      | FieldDecl
              ;

FieldDecl    : TypeName ID 
	     ;

TypeName     : INT                               
	     | STR
             | ID       
       	    ;
G*/
yyerror(char const *s)

{
    printf("yyerror %s",s);
}

int main(int argc,char* argv[]) {
	if(argc>1) {
        FILE *fp_1 = fopen(argv[1], "r");
        if(fp_1)
            yyin = fp_1;
    }

	TypeTableCreate();
        fp=fopen("Sample1.xsm","w");
        fprintf(fp,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",0,2056,0,0,0,0,1,0);
        yyparse();
	return 0;
}

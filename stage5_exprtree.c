int get_index=0;
int activ_ate=0;
int variable_array[26];
int newlabel=0;
int bind=4096;
int curr_type=-1;
int activate=0;
int loc=0;
int curr_type_store;
int flabel=0;
int local_binding=1;
#define inttype 0
#define strtype 1
#define READ_TYPE 0
#define WRITE_TYPE 1
#define CONNEC_TYPE 2
#define ADDTN 3
#define SUBTN 4
#define MULTPN 5
#define DIVSN 6
#define LEAF_CONST 7
#define LEAF_VAR 8
#define ASSIGNMENT 9
#define LT_TYPE 11
#define GT_TYPE 12
#define LE_TYPE 13
#define GE_TYPE 14
#define NE_TYPE 15
#define EQ_TYPE 16
#define WHILE_TYPE 17
#define IF_TYPE 18
#define ELSE_TYPE 19

struct Lsymbol *Lsymbol_table_head=NULL;
struct Gsymbol *headsymb=NULL;
struct Gsymbol *curr=NULL;
struct Lsymbol *headsymb_l=NULL;
struct Lsymbol *curr_l=NULL;
struct Paramstruct *headsymb_p=NULL;
struct Paramstruct *curr_p=NULL;

void GInstall(char *name, int type, int size,int rows, int coloumns,struct Paramstruct *param,int fl){
	//printf("variable name inside install is %s and size of name is %lu and size of char is %lu",name,sizeof(name) ,sizeof(char));
        curr=headsymb;
	if(GLookup(name)==NULL){
		struct Gsymbol *symb;
		symb=(struct Gsymbol*)malloc(sizeof(struct Gsymbol));
	        symb->name=(char *) malloc(sizeof(name));
		if(name!=NULL){
	        strcpy(symb->name,name);
	       // (symb->name[1]) = '\0' ;
		symb->type=type;
		symb->size=size;
		symb->paramlist=param;
		symb->flabel=fl;
		symb->binding=bind;
		if(rows==-1 & coloumns==-1){bind=bind+1;}
		else{
		bind=bind+rows*coloumns;}
		symb->next=headsymb;
		symb->rows=rows;
		symb->coloumns=coloumns;
		headsymb=symb;
	        curr=symb;}
	        else{printf("Variable name is NULL, Unable to Install a new variable");}}
	else{
		printf("The variable is already declared!!");}
}
/*
struct Paramstruct *PInstall(struct Paramstruct *headsymb_pl, struct Paramstruct *new){
	
	if(headsymb_pl==NULL){
		printf("headsymb_pl is null");
		headsymb_p=new;
		headsymb_pl=new;
	}
	else{   struct Paramstruct *temp;
		temp=headsymb_pl;
		while(temp->next!=NULL){temp=temp->next;}
		temp->next=new;
	        
	}
	return headsymb_pl;
	}*/

struct Paramstruct *PInstall(struct Paramstruct *head,struct Paramstruct *new){
	struct Paramstruct *temp;
	if(head==NULL){
		head=new;}
	else	{
		if(PLookup(head,new->name)!=NULL){
			printf("parameter %s redefined is same function defnition!!\n",new->name);
			exit(1);}
		else
		{
			temp=head;
													
			while(temp->next!=NULL)
	
			{
				temp=temp->next;
			}
			temp->next=new;
		}

	}
	return head;
}
struct Paramstruct *PInstall_each(char *name, int type,struct Paramstruct *headsymb_p){
        curr_p=headsymb_p;
	if(PLookup(NULL,name)==NULL){
		struct Paramstruct *symb;
		symb=(struct Paramstruct*)malloc(sizeof(struct Paramstruct));
	        symb->name=(char *) malloc(sizeof(name));
		if(name!=NULL){
	        strcpy(symb->name,name);
	       // (symb->name[1]) = '\0' ;
	        symb->next=NULL;
		symb->type=type;return symb;}
	        else{printf("Variable name is NULL, Unable to Install a new variable");}}
	else{
		printf("The variable is already declared!!");}
}
void Install(char *name, int type, int size,int rows, int coloumns){
	//printf("variable name inside install is %s and size of name is %lu and size of char is %lu",name,sizeof(name) ,sizeof(char));
        curr=headsymb;
	if(GLookup(name)==NULL){
		struct Gsymbol *symb;
		symb=(struct Gsymbol*)malloc(sizeof(struct Gsymbol));
	        symb->name=(char *) malloc(sizeof(name));
		if(name!=NULL){
	        strcpy(symb->name,name);
	       // (symb->name[1]) = '\0' ;
		symb->type=type;
		symb->size=size;
		symb->binding=bind;
		if(rows==-1 & coloumns==-1){bind=bind+1;}
		else{
		bind=bind+rows*coloumns;}
		symb->next=headsymb;
		symb->rows=rows;
		symb->coloumns=coloumns;
		headsymb=symb;
	        curr=symb;}
	        else{printf("Variable name is NULL, Unable to Install a new variable");}}
	else{
		printf("The variable is already declared!!");}
}
void LInstall(char *name,int type)
{
	struct Lsymbol *temp ,*newnode,*tem;
	printf("Local Variables so far\n");
	tem=Lsymbol_table_head;
	while(tem!=NULL){printf("temi name is %s\n",tem->name);tem=tem->next;}
	if(LLookup(name)!=NULL)
	{
		printf("variable %s redefined in Local scope!!\n",name);
		//exit(1);
	}

	newnode=(struct Lsymbol *)malloc(sizeof(struct Lsymbol));
	newnode->name=(char *)malloc((strlen(name)+2)*sizeof(char));
	strcpy(newnode->name,name);	
	newnode->type=type;
	newnode->binding=local_binding;
	local_binding++;
	newnode->next=NULL;

	if(Lsymbol_table_head==NULL)
	{
		Lsymbol_table_head=newnode;	
	}
	else
	{       struct Lsymbol *temp1=Lsymbol_table_head;
		while(temp1->next!=NULL){temp1=temp1->next;}
		temp1->next=newnode;
	}

}
struct Lsymbol *LLookup(char *name)
{
	struct Lsymbol *temp;
	temp=Lsymbol_table_head;
	while(temp!=NULL)
	{
		if(strcmp(name,temp->name)==0)
			return temp;
		temp=temp->next;
	}
	return temp;
} 
void Lsymbol_rst()
{
		
	Lsymbol_table_head=NULL;
	local_binding=1;
}

void createLsymbolEntries(struct Paramstruct *paramlist)
{
	struct Paramstruct *temp;
	temp=paramlist;

	int x=0;
	while(temp!=NULL)
	{
		x=x+1;
		local_binding=-(2+x);
		LInstall(temp->name,temp->type);
		temp=temp->next;

	}
	local_binding=1;

}
struct Gsymbol *GLookup(char * name){
	if(name!=NULL){
	if(curr==NULL){return curr;}
	else{
	int cmp=strcmp(name,curr->name);
	if(cmp==0){
		return curr;}
	else{
		curr=curr->next;GLookup(name);} }}
	else {return NULL;}
}
struct Paramstruct *PLookup(struct Paramstruct *head,char * name){
	if(head==NULL){return head;}
	else{
	int cmp=strcmp(name,head->name);
	if(cmp==0){
		return head;}
	else{
		head=head->next;PLookup(head,name);} }
}
void print_symbol_table(){
    if(curr!=NULL){
	    printf("\nName %s\n",curr->name);
	    printf("Type is %d\n",curr->type);
	    printf("Size is %d\n",curr->size);
	    printf("Binding %d\n",curr->binding);
	    if(curr->paramlist!=NULL){
            struct Paramstruct *temp=curr->paramlist;
	    printf("\n-----------Param list of above function----------\n");
	    while(temp!=NULL){
	    printf("Name variable in Paramlist %s\n",temp->name);
	    printf("Type is %d\n",temp->type);
	    temp=temp->next;
	    }

	    }
	    curr=curr->next;
	    print_symbol_table();
    }

}
void print_Lsymbol_table(char *name)
{
	struct Lsymbol *temp;
	temp=Lsymbol_table_head;
	printf("\n\nLOCAL SYMBOL TABLE FOR %s FUNCTION\n",name);
	printf("--------------------------------------------\n");
	printf("Name\t\t\tType\tBinding\t\n");
	printf("---------------------------------\n");
	while(temp!=NULL)
	{
		printf("%s\t\t\t%d\t%d\t\n",temp->name,temp->type,temp->binding);
		temp=temp->next;
	}
}
struct tnode* createTree(int v, int t, char* vn, int nt, struct tnode *l, struct tnode *r,struct tnode *next ){
        struct tnode *temp;
	temp = (struct tnode*)malloc(sizeof(struct tnode));
	temp->val=v;
	temp->type=t;
	if(vn!=NULL){
		temp->varname=(char *) malloc(sizeof(vn));//*(temp->varname)=*vn;//(temp->varname[1]) = '\0' ;}
	        strcpy(temp->varname,vn);}
	else{
	temp->varname=NULL;}
        temp->nodetype=nt;
	temp->left=l;
	temp->right=r;
	temp->next=next;
	curr=headsymb;//temp->Gentry=(struct Gsymbol*)malloc(sizeof(struct Gsymbol));
        //printf("Variable name (for node type %d) inside createTree: %s\n",temp->nodetype, (temp->varname));
        temp->Gentry=GLookup(vn);
	if(activate==1){
                printf("Variable name (for node type %d) inside createTree: %s\n",temp->nodetype, (temp->varname));
		curr=headsymb;
		if(vn!=NULL){
		temp->Lentry=LLookup(vn);
		temp->Gentry=GLookup(vn);
		if(temp->Gentry==NULL && temp->Lentry==NULL){
			printf("Variable name <%s> hasnt declared",vn);exit(1);}
		else if(temp->Lentry!=NULL){   
			temp->type=(temp->Lentry)->type; }
	        else{
			temp->type=temp->Gentry->type;
		}
		}}
		temp=type_checking(temp);
		return temp;
	

}

struct tnode *type_checking(struct tnode *node){
switch (node->nodetype){
	case 0: return node;
	case 1: return node;
	case 2: return node;
	case 3:	if(((node->right)->type != 0) || ((node->left)->type != 0)) {
			printf("ERROR MISMATCH %d and %d",node->right->type,node->left->type);
			exit(1);}
		else{
			node->type=0;}
	        return node;
	case 4:	if(((node->right)->type != 0) || ((node->left)->type != 0)) {
			printf("ERROR MISMATCH %d and %d",node->right->type,node->left->type);
			exit(1);}
		else{
			node->type=0;}
		return node;
	case 5:	if(((node->right)->type != 0) || ((node->left)->type != 0)) {
			printf("ERROR MISMATCH %d and %d",node->right->type,node->left->type);
			exit(1);}
		else{
			node->type=0;}
		return node;
	case 6:	if(((node->right)->type != 0) || ((node->left)->type != 0)) {
			printf("ERROR MISMATCH %d and %d",node->right->type,node->left->type);
			exit(1);}
		else{
			node->type=0;}
		return node;
	case 7: return node;
	case 8:return node;

	case 9:	if(((node->right)->type!=node->left->type)) {
			printf("ERROR MISMATCH %d and %d",node->right->type,node->left->type);
			exit(1);}
		else{
			node->type=node->right->type;}
		return node;
	case 10: return node;
	case 11:if(((node->right)->type != 0) || ((node->left)->type != 0)) {
			printf("ERROR MISMATCH %d and %d",node->right->type,node->left->type);
			exit(1);}
		else{
			node->type=0;}
		return node;
	case 12:if(((node->right)->type != 0) || ((node->left)->type != 0)) {
			printf("ERROR MISMATCH %d and %d",node->right->type,node->left->type);
			exit(1);}
		else{
			node->type=0;}
		return node;
	case 13:if(((node->right)->type != 0) || ((node->left)->type != 0)) {
			printf("ERROR MISMATCH %d and %d",node->right->type,node->left->type);
			exit(1);}
		else{
			node->type=0;}
		return node;
	case 14:if(((node->right)->type != 0) || ((node->left)->type != 0)) {
			printf("ERROR MISMATCH %d and %d",node->right->type,node->left->type);
			exit(1);}
		else{
			node->type=0;}
                return node;
	
	case 15:if(((node->right)->type!=node->left->type)) {
			printf("ERROR MISMATCH %d and %d",node->right->type,node->left->type);
			exit(1);}
		else{
			node->type=node->right->type;}
		return node;

	case 16:if(((node->right)->type!=node->left->type)) {
			printf("ERROR MISMATCH %d and %d",node->right->type,node->left->type);
			exit(1);}
		else{
			node->type=node->right->type;}
		return node;
        case 17: return node;
	case 18:return node;
	case 19:return node;
	case 20:return node;
	case 21:return node;
	case 22://function
		//printf("left of node in fuct node is %s\n",node->left->varname);
		func_check(node->varname,node->left);
                struct Gsymbol *gl=GLookup(node->varname);
		node->type=gl->type;
		return node;
	default:return node;



}
}
void func_check(char *varn,struct tnode *left){
        curr=headsymb;
	if(GLookup(varn)==NULL){
		printf("Function not declared!!");exit(1);}  
	int count=0;
	struct Paramstruct *def_param_list;
	def_param_list=GLookup(varn)->paramlist;
	struct tnode *left_store=left;
	while(left!=NULL){
		printf("Hi count is %d\n",count);
		count++;
		if(def_param_list==NULL){
			printf("More arguments!! ");
		        exit(1);}
		else if(left->type!=def_param_list->type){
			printf("Parameter Mistmatch at Argument %d of Function %s\n",count,varn);
			printf("Pptype:%d,Gptype:%d",left->type,def_param_list->type);
			exit(1);
		  
		}
		else{left=left->next; def_param_list=def_param_list->next;}

	}
	if(def_param_list!=NULL)
	{
		printf("few arguments in the Function call for %s\n",varn);
		exit(1);
	}
}
void fucn_check_name(int rettype,char *name,struct Paramstruct *paramlist)
{
	struct Paramstruct *temp,*plist;
	struct Gsymbol *dummy;
	int count=0;
	curr=headsymb;
	dummy=GLookup(name);
	if(dummy==NULL)
	{
		printf("Function defnition %s without a previous declaration\n",name);
		exit(1);
	}
	if(dummy->type!=rettype)
	{
		printf("Return type of function \"%s\" does not match in the declaration and defnition\n",name);
		exit(1);
	}
	temp=dummy->paramlist;
	plist=paramlist;
	while(plist!=NULL)
	{
		count++;
		if(temp==NULL)
		{
			printf("Too many arguments for the Function %s\n",name);
			exit(1);
		}
		else if(!((strcmp(plist->name,temp->name)==0) && plist->type==temp->type))
		{
			printf("Ppname:%s,Gpname:%s\n",plist->name,temp->name);
			printf("Pptype:%d,Gptype:%d\n",plist->type,temp->type);
			printf("Conflict at Parameter %d of Function %s\n",count,name);
			exit(1);
		}

		else
		{
			plist=plist->next;
			temp=temp->next;
		}
	}
	if(temp!=NULL)
	{
		printf("Too few arguments for the Function %s\n",name);
		exit(1);
	}
}
int Loc_In_Reg(struct tnode* t, FILE *fptr){
	printf("varname is %s, and val is %d",t->varname,t->val);
	if(t->Lentry!=NULL){
		switch(t->nodetype){
			case 8:{
				       int loc = t->Lentry->binding;
				       int reg = getReg();
				       fprintf(fptr, "MOV R%d, BP\n", reg);
				       fprintf(fptr, "ADD R%d, %d\n",reg, loc);
				       return reg;
			       }
		}
	}
	else{   if(t->Gentry!=NULL){
		int loc = t->Gentry->binding;
		switch(t->nodetype){
			case 8:{
				       int reg = getReg();
				       fprintf(fptr,"MOV R%d, %d\n",reg, loc);
				       return reg;


			       }
			case 10:if(t->right==NULL) {
					     int offset = codeGen(t->left, fptr);
					     fprintf(fptr, "ADD R%d, %d\n",offset, loc);
					     return offset;


				     }else {
					      int offset_1 = codeGen(t->left, fptr);
					      int offset_2 = codeGen(t->right, fptr);
					      int offset = offset_1*t->Gentry->coloumns+ offset_2;
					      fprintf(fptr,"MUL R%d, %d\n", offset_1, t->Gentry->coloumns);
					      fprintf(fptr, "ADD R%d, R%d\n",  offset_1, offset_2);
					      fprintf(fptr, "ADD R%d, %d\n", offset_1, loc);
					      return offset_1;			
				      }}
		}
		else{printf("There is some problem coz Lentry is NULL and Gentry is NULL!!");exit(1);}

	}
}
int evaluate(struct tnode *t){
	    if(t->nodetype == 7)
		        {
				return t->val;
		    	}
	    else if(t->nodetype==8){int index=(int)*(t->varname)-97;return variable_array[index];}
	    else{
		    switch((t->nodetype)){
			    case 3 : return evaluate(t->left) + evaluate(t->right);
				       break;
			    case 4 : return evaluate(t->left) - evaluate(t->right);
				       break;
			    case 5 : return evaluate(t->left) * evaluate(t->right);
				       break;
			    case 6 : return evaluate(t->left) / evaluate(t->right);
				       break;
		    }
	    }
}

int getReg(){
	if(get_index<19){
	   get_index++;
	   return get_index;}
	else{get_index++;return get_index;printf("Error no more Registers are left");}

}

void freeReg(){if(get_index>0){
	   get_index--; 
}
}
int getFlabel(){
	flabel++;
	return flabel;
}
int getLabel(){return newlabel++;}

void write_console(int reg_ind,FILE*fp){
int reg=reg_ind;
int temp = getReg();
fprintf(fp,"PUSH R0\nMOV R0,R%d\n",reg);
fprintf(fp,"MOV R%d, \"Write\"\nPUSH R%d\nMOV R%d, -2\nPUSH R%d\nPUSH R%d\nPUSH R0\nPUSH R0\nCALL 0\nPOP R%d\nPOP R%d\nPOP R%d\nPOP R%d\nPOP R%d\n",temp,temp,temp,temp,0,temp,temp,temp,temp,temp);
fprintf(fp,"POP R%d\n",reg);
freeReg();
}
void read_console(int regval,FILE *fp,int normal){
int location=regval;
int temp = getReg();
fprintf(fp,"MOV R%d, \"Read\"\n",temp);
fprintf(fp,"PUSH R%d\n",temp);
fprintf(fp,"MOV R%d, -1\n",temp);
fprintf(fp,"PUSH R%d\n",temp);
if(normal==0){
fprintf(fp,"MOV R%d, %d\n",temp,location);}
else{fprintf(fp,"MOV R%d, R%d\n",temp,location);}
fprintf(fp,"PUSH R%d\n",temp);
fprintf(fp,"PUSH R0\nPUSH R0\nCALL 0\nPOP R%d\nPOP R%d\nPOP R%d\nPOP R%d\nPOP R%d\n",temp,temp,temp,temp,temp);
freeReg();
}


int codeGen(struct tnode *t, FILE *target_file) {
	    int p,q,eval,left,right,n0,n1,n2;
	    int n,x,i,j,l;
	    struct tnode *arglist;
	    struct Gsymbol *global;
            if(t!=NULL){
	    printf("type from Code Gen %d\n",t->nodetype);
	    switch(t->nodetype){
		    case 0:p=getReg();
                            			    
			    left=Loc_In_Reg(t->left,target_file);
                            read_console(left,target_file,1);
			    freeReg();
			    /* p=getReg();       			    
			   // fprintf(target_file,"READ\n");
			    int regval=codeGen(t->left,target_file);
			    if(t->left->nodetype==8){
			    read_console(loc,target_file,0);}
			    else{read_console(loc,target_file,1);}*/
                            return -1;
			    break;
		    case 1 :// fprintf(target_file,"WRITE IN CONSOLE\n");
                             left=codeGen(t->left,target_file);
			     write_console(left,target_file);
                             freeReg();
			     return -1;
			     break;
		    case 2 : left=codeGen(t->left,target_file);
			     right=codeGen(t->right,target_file);
			     freeReg();
			     freeReg();
			     return -1;
			     break;
		    case 3 : left=codeGen(t->left,target_file);
			     right=codeGen(t->right,target_file);
			     fprintf(target_file, "ADD R%d, R%d\n", left,right);
			     freeReg();
        		     return left;
		             break;
		   case 4 :  left=codeGen(t->left,target_file);
			     right=codeGen(t->right,target_file);
			     fprintf(target_file, "SUB R%d, R%d\n", left,right);
		             freeReg();
			     return left;
       	                     break;
      		   case 5 :  left=codeGen(t->left,target_file);
			     right=codeGen(t->right,target_file);
			     fprintf(target_file, "MUL R%d, R%d\n", left,right);
			     freeReg();
			     return left;
			     break;
		   case 6 :  left=codeGen(t->left,target_file);
			     right=codeGen(t->right,target_file);
                             fprintf(target_file, "DIV R%d, R%d\n", left,right);
			     freeReg(); 
			     return left;
			     break;
	           case 7: p=getReg();
			   fprintf(target_file,"MOV R%d, %d\n",p,t->val); 
			   return p;
			   break;
		   case 8: p=getReg();
                           printf("VAR NAME is :%s",(t->varname));
			   loc=Loc_In_Reg(t, target_file);
			   freeReg();
			   fprintf(target_file,"MOV R%d,[R%d]\n",p,(loc));
			   return p;
			   break;
                   case 9:  left=Loc_In_Reg(t->left,target_file);
			   right=codeGen(t->right,target_file);
			   fprintf(target_file,"MOV [R%d],R%d\n",left,right);
			   freeReg();
			   //freeReg();
			   //printf("\nReturning value is %d\n",left);
			   return left;
			   break;/*if(t->left->nodetype==10){
				    left=codeGen(t->left->left,target_file);
				    if(t->left->right!=NULL){
					    right=codeGen(t->left->right,target_file);
					    p=getReg();
					    fprintf(target_file,"MOV R%d, %d\n",p,t->left->Gentry->coloumns);
					    fprintf(target_file,"MUL R%d ,R%d\n",left,p);
					    fprintf(target_file,"ADD R%d, R%d\n",left,right);freeReg();}
				    right=codeGen(t->right,target_file); 
				    fprintf(target_file,"ADD R%d,%d\n",left,t->left->Gentry->binding);
				    fprintf(target_file,"MOV [R%d], R%d\n",left,right);}
			    else if(t->left->nodetype==22){fprintf(target_file,"Func");}
			    else{   if(t->left->Lentry==NULL){
				    left=(t->left)->Gentry->binding;
				    right=codeGen(t->right,target_file); 
				    fprintf(target_file,"MOV [%d], R%d\n",left,right);
				    freeReg();}
			            else{
				   int loc= Loc_In_Reg(t->left,target_file);
				   right=codeGen(t->right,target_file);
				   fprintf(target_file,"MOV [R%d],R%d",loc,right);
				    }
			    }
			    return left;*/
	           case 10:left=Loc_In_Reg(t,target_file);
			   fprintf(target_file,"MOV R%d,[R%d]\n",left,left);
			   //printf("\nReturning value is %d\n",left);
			   loc=left;
			   return left;
			   break;/* p=getReg();
			    left=codeGen(t->left,target_file);
			    if(t->right!=NULL){
				    right=codeGen(t->right,target_file);
				    p=getReg();
				    fprintf(target_file,"MOV R%d, %d\n",p,t->Gentry->coloumns);
				    fprintf(target_file,"MUL R%d ,R%d\n",left,p);
				    fprintf(target_file,"ADD R%d, R%d\n",left,right);
				    freeReg();}
                            fprintf(target_file,"ADD R%d,%d\n",left,t->Gentry->binding);
			    fprintf(target_file,"MOV R%d, [R%d]\n",p,left);
			    loc=left;
			    return p;*/
		   case 11 :  left=codeGen(t->left,target_file);
			     right=codeGen(t->right,target_file);
                             fprintf(target_file, "LT R%d, R%d\n", left,right);
			     freeReg(); 
			     return left;
			     break;
	           case 12 :  left=codeGen(t->left,target_file);
			     right=codeGen(t->right,target_file);
                             fprintf(target_file, "GT R%d, R%d\n", left,right);
			     freeReg(); 
			     return left;
			     break;
	            case 13 :  left=codeGen(t->left,target_file);
			     right=codeGen(t->right,target_file);
                             fprintf(target_file, "LE R%d, R%d\n", left,right);
			     freeReg(); 
			     return left;
			     break;
                  case 14 :  left=codeGen(t->left,target_file);
			     right=codeGen(t->right,target_file);
                             fprintf(target_file, "GE R%d, R%d\n", left,right);
			     freeReg(); 
			     return left;
			     break;
                   case 15 :  left=codeGen(t->left,target_file);
			     right=codeGen(t->right,target_file);
                             fprintf(target_file, "NE R%d, R%d\n", left,right);
			     freeReg(); 
			     return left;
			     break;
	           case 16 :  left=codeGen(t->left,target_file);
			     right=codeGen(t->right,target_file);
                             fprintf(target_file, "EQ R%d, R%d\n", left,right);
			     freeReg(); 
			     return left;
			     break;
                    case 17 :n0=getLabel();
			     fprintf(target_file,"L%d:",n0);
			     left=codeGen(t->left,target_file);
			     n1=getLabel();
			     fprintf(target_file,"JZ R%d,L%d\n",left,n1);
			     right=codeGen(t->right,target_file);
                             fprintf(target_file, "JMP L%d\n", n0);
			     fprintf(target_file,"L%d:",n1);
			     freeReg(); 
			     return left;
			     break;
		 case 18 :  left=codeGen(t->left,target_file);
			     n2=getLabel();
			     fprintf(target_file,"JZ R%d,L%d\n",left,n2);
			     right=codeGen(t->right,target_file);
                             fprintf(target_file, "L%d:", n2);
			     freeReg(); 
			     return left;
			     break;
	        case 19 :    left=codeGen(t->left,target_file);
			     n2=getLabel();
			     fprintf(target_file,"JZ R%d, L%d\n",left,n2);
			     right=codeGen(t->right,target_file);
			     int n3=getLabel();
			     fprintf(target_file,"JMP L%d\n",n3);
                             fprintf(target_file, "L%d:", n2);
			     int nex=codeGen(t->next,target_file);
                             fprintf(target_file, "L%d:", n3);
			     freeReg();
			     freeReg(); 
			     return left; 
			     break;

		case 20 : p=getReg();
			  fprintf(target_file,"Hi in 20th Node");
			  fprintf(target_file,"MOV R%d,[%d]",p,t->left->val);
		          return p;

                case 21 :    printf("Node type is %d",t->left->nodetype);
		      if(t->left->nodetype==8){p=getReg();
			       fprintf(target_file,"MOV R%d,%d\n",p,t->left->Gentry->binding);
			       return p;}
		      else if(t->left->nodetype==10){
			      printf("HI INSIDE 21 and Inside 10");
			       left=codeGen(t->left->left,target_file); 
			       if(t->left->right!=NULL){
				    right=codeGen(t->left->right,target_file);
				    p=getReg();
				    fprintf(target_file,"MOV R%d, %d\n",p,t->left->Gentry->coloumns);
				    fprintf(target_file,"MUL R%d ,R%d\n",left,p);
				    fprintf(target_file,"ADD R%d, R%d\n",left,right);
                                    fprintf(target_file,"ADD R%d,%d\n",left,t->left->Gentry->binding);

				    freeReg();return left;}
		     else{ 
                            fprintf(target_file,"ADD R%d,%d\n",left,t->left->Gentry->binding);
                            fprintf(target_file,"MOV R%d,R%d\n",p,left);return p;}}


                 case 22: for(n=0;n<=get_index;n++){
				   fprintf(target_file,"PUSH R%d\n",n);
				   bind=bind+1; 
			   }
			   arglist=t->left;
			   while(arglist!=NULL)
			   {
				   x=codeGen(arglist,target_file);
				   fprintf(target_file,"PUSH R%d\n",x);
				   freeReg();
				   arglist=arglist->next;
			   

			   fprintf(target_file,"PUSH R0\n");
			   curr=headsymb;
			   global=t->Gentry;
			   fprintf(target_file,"CALL F%d\n",global->flabel);}
			  // if(global->flabel==0){fprintf(target_file,"INT 10\n");}

			   i=getReg();
			   fprintf(target_file,"POP R%d\n",i);

			   arglist=t->left;
			   
			   j=getReg();
		
			   while(arglist!=NULL)
			   {
				   fprintf(target_file,"POP R%d\n",j);
				   arglist=arglist->next;
			   }
			   freeReg();

			   for(n=i-1;n>=0;n--)
		   	   {				
	
				   fprintf(target_file,"POP R%d\n",n);
				   bind=bind-1;
			   }
			   return i;
		case 23: //rettype
			 l=codeGen(t->left,target_file);
		
			 i=getReg();
			 fprintf(target_file,"MOV R%d,BP\n",i);
			 fprintf(target_file,"SUB R%d,2\n",i);
			 fprintf(target_file,"MOV [R%d],R%d\n",i,l);

			 for(n=1;n<local_binding;n++)
			 {
				 fprintf(target_file,"POP R%d\n",i);
			 }
			 freeReg();
			 freeReg();

			 fprintf(target_file,"POP BP\n");
		 	 fprintf(target_file,"RET\n");
			 return l;

	    }      }
}
void codeGen_f(struct tnode *t,char *fname, FILE *fp)
{
	int fl;
	int i;
	int x;
	if(strcmp(fname,"main")==0)
	{
		fl=0;
	}
	else
	{
		fl=GLookup(fname)->flabel;
	}
	fprintf(fp,"F%d:",fl);
	fprintf(fp,"PUSH BP\n");
	fprintf(fp,"MOV BP,SP\n");
	for(i=1;i<local_binding;i++){
												
		fprintf(fp,"PUSH R0\n");
		
	}
	x=codeGen(t,fp);}

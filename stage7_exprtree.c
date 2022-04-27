int get_index=0;
int activ_ate=0;
int variable_array[26];
int newlabel=0;
int bind=4096;
struct Typetable* curr_type=NULL;
int activate=0;
int loc=0;
int curr_type_store;
int flabel=0;
int Findex = 0;
int local_binding=1;
int size=0;
int FieldNo=0;
int Cindex=0;
int CFindex=0;
int CMindex=0;
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

struct Classtable* Cptr;
struct Memberfunclist* Mhead=NULL;
struct Classtable* Chead=NULL;
struct Lsymbol *Lsymbol_table_head=NULL;
struct Gsymbol *headsymb=NULL;
struct Gsymbol *curr=NULL;
struct Lsymbol *headsymb_l=NULL;
struct Lsymbol *curr_l=NULL;
struct Paramstruct *headsymb_p=NULL;
struct Paramstruct *curr_p=NULL;
struct Fieldlist * Fhead = NULL;
struct Typetable * Thead = NULL;

struct Classtable* CInstall(char *name,char *parent_class_name){
	struct Classtable * temp;
	temp = (struct Classtable*)malloc(sizeof(struct Classtable));
	temp ->name = name;
	temp ->Parentptr = CLookup(parent_class_name);
	temp->Class_index = Cindex ++;
	temp->Fieldcount = 0;
	temp->Methodcount = 0;
	temp->next = Chead;
	Chead = temp;	
	return temp;
}

struct Classtable* CLookup(char *name){
	struct Classtable *temp=Chead;
	while(temp!=NULL){
	
	if(strcmp(temp->name,name)==0){
		return temp;}
	temp=temp->next;}
	return NULL;
}

void Class_Finstall(struct Classtable *cptr, char *typename, char *name){
	struct Fieldlist * Fhead = cptr->MemberField;
	struct Fieldlist *temp;
	temp = (struct Fieldlist*)malloc(sizeof(struct Fieldlist));
	temp->name = name;
	temp->fieldIndex = CFindex++;
	temp->type = TLookup(typename);
	temp->Ctype = CLookup(typename);
	temp->next = Fhead;
	cptr->MemberField = temp;
	cptr->Fieldcount++;
}
void Class_Minstall(struct Classtable *cptr, char *name, struct Typetable *type, struct Paramstruct *Paramlist){
	struct Memberfunclist *Mhead = cptr->Vfuncptr;
	struct Memberfunclist *temp;
	temp = (struct Memberfunclist*)malloc(sizeof(struct Memberfunclist));
	temp->name = name;
	temp->type = type;
	temp->Funcposition = CMindex++;
	temp->Flabel = getFlabel();
	temp->paramlist = Paramlist;
	temp->next = Mhead;
	cptr->Vfuncptr = temp;
	cptr->Methodcount++;
																									
}

struct Memberfunclist *Class_Mlookup(struct Classtable *cptr, char *name){
	struct Memberfunclist *Mhead = cptr->Vfuncptr;
	while(Mhead!=NULL){
		if(strcmp(Mhead->name, name)==0){
			return Mhead;
		}
		Mhead = Mhead->next;

	}
	return NULL;
}

struct Fieldlist *Class_Flookup(struct Classtable *cptr, char *name){
	struct Fieldlist *Fhead = cptr->MemberField;
	while(Fhead!=NULL){
		if(strcmp(Fhead->name, name)==0){
			return Fhead;

		}
		Fhead = Fhead->next;
	}
	return NULL;
}

void printclasstable(){
	struct Classtable *Cheadtemp = Chead;
	while(Cheadtemp!=NULL){
		printf("%s, %d, %d",Cheadtemp->name, Cheadtemp->Fieldcount, Cheadtemp->Methodcount);
		Cheadtemp = Cheadtemp->next;

	}

}
void GInstall(char *name, struct Typetable *type, int size,int rows, int coloumns,struct Paramstruct *param,int fl, struct Gsymbol *left){
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
		symb->Ctype=NULL;
		symb->binding=bind;
		symb->left=left;
		//bind=bind+1;
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
struct Paramstruct *PInstall_each(char *name, struct Typetable* type,struct Paramstruct *headsymb_p){
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
void Install(char *name, struct Typetable *type, int size,int rows, int coloumns){
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
void LInstall(char *name,struct Typetable* type)
{
	struct Lsymbol *temp ,*newnode,*tem;
	//printf("Local Variables so far\n");
	tem=Lsymbol_table_head;
	while(tem!=NULL){
		//printf("temi name is %s\n",tem->name);
		tem=tem->next;
	}
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
	local_binding=local_binding+1;
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
	    if(curr->type!=NULL){
	    printf("Type is %s\n",curr->type->name);}
	    if(curr->Ctype!=NULL){ printf("Class Type is %s\n",curr->Ctype->name);}


	    printf("Size is %d\n",curr->size);
	    printf("Binding %d\n",curr->binding);
	    if(curr->paramlist!=NULL){
            struct Paramstruct *temp=curr->paramlist;
	    printf("\n-----------Param list of above function----------\n");
	    while(temp!=NULL){
	    printf("Name variable in Paramlist %s\n",temp->name);
	    printf("Type is %s\n",temp->type->name);
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
		printf("%s\t\t\t%s\t%d\t\n",temp->name,temp->type->name,temp->binding);
		temp=temp->next;
	}
}

void TypeTableCreate(){
		
	Tinstall("INT", 1, NULL);
	Tinstall("STR", 1, NULL);
	Tinstall("BOOL ",1, NULL);
	Tinstall("VOID", 0, NULL);
	Tinstall("NULL",0,NULL);
						
}
void  Tinstall(char *name, int size, struct Fieldlist *fields){
	struct Typetable *temp;
	temp = (struct Typetable*)malloc(sizeof(struct Typetable));
	temp->name = name;
	temp->size = size;
	temp-> fields = fields;
	temp->next = Thead;
	Thead = temp;
}
struct Typetable *TLookup(char *name){
	struct Typetable* temp = Thead;
	while(temp!=NULL){
	if(strcmp(temp->name, name)==0)
		return temp;
	temp = temp->next;}
	return NULL;
}

struct Fieldlist *  Finstall(char *name, char* temp_type){
	struct Fieldlist *temp;
	temp = (struct Fieldlist*)malloc(sizeof(struct Fieldlist));
	temp->name = name;
	temp->fieldIndex = Findex++;
	temp->type = TLookup(temp_type);
	temp->next = NULL;
	return temp;
}	

int GetSize(struct Typetable *type){
	/*struct Fieldlist *temp=Tentry->fields;
	int size=0;
	while(temp!=NULL){

		size = size + temp->type->size;
		temp = temp->next;
	}
	return size;*/
	int size=0;
	struct Fieldlist *temp;
	if(strcmp(type->name,"NULL")==0||strcmp(type->name,"VOID")==0)
		return 0;
	if(strcmp(type->name,"INT")==0||strcmp(type->name,"STR")==0 || strcmp(type->name,"BOOL")==0)
		return 1;
	temp=type->fields;
	while(temp!=NULL)
	{	
		size++;
		temp=temp->next;
	}
	return size;
						
}
struct Typetable * checkvalidfieldandType(struct Typetable *ttemp, struct tnode* Node){
	struct Fieldlist *Flist = ttemp->fields;
	while(Flist!=NULL){
		if(strcmp(Node->varname, Flist->name)==0){										
			return	Flist->type;
		}
		Flist = Flist->next;
	}
	printf("Field not member of the datatype ");
	//exit(1);
	return NULL;
}

struct Fieldlist * FLookup(struct Typetable *type, char *name){
	struct Fieldlist *field = type->fields;
	while(field!=NULL){
		if(strcmp(name, field->name)==0){
			return field;
		}
		field = field->next;
	}
	return NULL;
}

void print_Typetable()
{
	struct Typetable *temp=Thead; 
	struct Fieldlist *ftemp;
	printf("-------------------TYPE TABLE--------------------\n");
	printf("NAME		SIZE		FIELDS		\n");
	while(temp!=NULL)
	{
		ftemp=temp->fields;
		if(ftemp==NULL)
			printf("%s\t\t%d\t\tNULL\t\n",temp->name,temp->size);
		else
		{
			printf("%s\t\t%d\t\t--->\t\n",temp->name,temp->size);
			printf("---------FIELDLIST OF %s---------\n",temp->name);
			printf("FIELDINDEX		TYPE		NAME		\n");
			while(ftemp!=NULL)
			{
				
				printf("%d\t\t%s\t\t%s\t\n",ftemp->fieldIndex,ftemp->type->name,ftemp->name);
				ftemp=ftemp->next;
			}
			printf("-------------------------------------------------------\n");

		}
		temp=temp->next;

	}
	printf("-------------------END OF TYPE TABLE--------------------\n");
}	

struct tnode* createTree(int v, struct Typetable *t, char* vn, int nt, struct tnode *l, struct tnode *r,struct tnode *next ){
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
	temp->Ctype=NULL;
	curr=headsymb;//temp->Gentry=(struct Gsymbol*)malloc(sizeof(struct Gsymbol));
        //printf("Variable name (for node type %d) inside createTree: %s\n",temp->nodetype, (temp->varname));
        temp->Gentry=GLookup(vn);
	if(activate==1){
                printf("Variable name (for node type %d) inside createTree: %s\n",temp->nodetype, (temp->varname));
		curr=headsymb;
		if(vn!=NULL){
		temp->Lentry=LLookup(vn);
		temp->Gentry=GLookup(vn);
		if(temp->Gentry==NULL && temp->Lentry==NULL && temp->nodetype!=24){
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
	case 3:	if(((node->right)->type !=TLookup("INT") ) || ((node->left)->type!= TLookup("INT"))) {
			printf("ERROR MISMATCH %s and %s",node->right->type->name,node->left->type->name);
			exit(1);}
		else{
			node->type=TLookup("INT");}
	        return node;
	case 4:	if(((node->right)->type != TLookup("INT")) || ((node->left)->type != TLookup("INT"))) {
				printf("ERROR MISMATCH %s and %s",node->right->type->name,node->left->type->name);
				//printf("ERROR MISMATCH %d and %d",node->right->type,node->left->type);
			exit(1);}
		else{
			node->type=TLookup("INT");}
		return node;
	case 5:	if(((node->right)->type != TLookup("INT")) || ((node->left)->type != TLookup("INT"))) {
			printf("ERROR MISMATCH %s and %s",node->right->type->name,node->left->type->name);
			//printf("ERROR MISMATCH %d and %d",node->right->type,node->left->type);
			exit(1);}
		else{
			node->type=TLookup("INT"); }
		return node;
	case 6:	if(((node->right)->type != TLookup("INT") ) || ((node->left)->type !=  TLookup("INT") )) {
			printf("ERROR MISMATCH %s and %s",node->right->type->name,node->left->type->name);
			//printf("ERROR MISMATCH %d and %d",node->right->type,node->left->type);
			exit(1);}
		else{
			node->type= TLookup("INT") ;}
		return node;
	case 7: return node;
	case 8:return node;

	case 9:	if(((node->right)->type!=node->left->type)) {
		        if(node->right->type == TLookup("NULL")|| node->left->type == TLookup("NULL")){node->type=node->left->type;}
		        else{	
			printf("ERROR MISMATCH %s and %s varnames are %s and %s resp.",node->right->type->name,node->left->type->name,node->right->varname,node->left->varname);
			//printf("ERROR MISMATCH %d and %d",node->right->type,node->left->type);
			}}
		else{
			node->type=node->right->type;}
		return node;
	case 10: return node;
	case 11:if(((node->right)->type !=  TLookup("INT") ) || ((node->left)->type !=  TLookup("INT") )) {
				printf("ERROR MISMATCH %s and %s",node->right->type->name,node->left->type->name);
				//printf("ERROR MISMATCH %d and %d",node->right->type,node->left->type);
			exit(1);}
		else{
			node->type= TLookup("INT") ;}
		return node;
	case 12:if(((node->right)->type !=  TLookup("INT") ) || ((node->left)->type !=  TLookup("INT") )) {
				printf("ERROR MISMATCH %s and %s",node->right->type->name,node->left->type->name);
				//printf("ERROR MISMATCH %d and %d",node->right->type,node->left->type);
			exit(1);}
		else{
			node->type= TLookup("INT") ;}
		return node;
	case 13:if(((node->right)->type !=  TLookup("INT") ) || ((node->left)->type !=  TLookup("INT") )) {
				printf("ERROR MISMATCH %s and %s",node->right->type->name,node->left->type->name);
				//printf("ERROR MISMATCH %d and %d",node->right->type,node->left->type);
			exit(1);}
		else{
			node->type= TLookup("INT") ;}
		return node;
	case 14:if(((node->right)->type !=  TLookup("INT") ) || ((node->left)->type !=  TLookup("INT") )) {
				printf("ERROR MISMATCH %s and %s",node->right->type->name,node->left->type->name);
//printf("ERROR MISMATCH %d and %d",node->right->type,node->left->type);
			exit(1);}
		else{
			node->type= TLookup("INT") ;}
                return node;
	
	case 15:if(((node->right)->type!=node->left->type)) {
			//	printf("ERROR MISMATCH %s and %s",node->right->type->name,node->left->type->name);
			//exit(1);}
		//else{
		//	node->type=node->right->type;}
		if(node->right->type == TLookup("NULL")|| node->left->type == TLookup("NULL")){node->type=node->left->type;}
		        else{	
			printf("ERROR MISMATCH %s and %s",node->right->type->name,node->left->type->name);
			//printf("ERROR MISMATCH %d and %d",node->right->type,node->left->type);
			exit(1);}}
		else{
			node->type=node->right->type;}return node;

	case 16:if(((node->right)->type!=node->left->type)) {
		//		printf("ERROR MISMATCH %s and %s",node->right->type->name,node->left->type->name);
//printf("ERROR MISMATCH %d and %d",node->right->type,node->left->type);
		//	exit(1);}
		//else{
		//	node->type=node->right->type;}
		if(node->right->type == TLookup("NULL")|| node->left->type == TLookup("NULL")){node->type=node->left->type;}
		        else{	
			printf("ERROR MISMATCH %s and %s",node->right->type->name,node->left->type->name);
			//printf("ERROR MISMATCH %d and %d",node->right->type,node->left->type);
			exit(1);}}
		else{
			node->type=node->right->type;}return node;
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
		//printf("Hi count is %d\n",count);
		count++;
		if(def_param_list==NULL){
			printf("Too many arguments in ");
		        exit(1);}
		else if(left->type!=def_param_list->type){
			printf("Parameter Type Mistmatch at Argument %d of Function %s\n",count,varn);
			printf("Pptype:%s,Gptype:%s",left->type->name,def_param_list->type->name);
			left=left->next; def_param_list=def_param_list->next;//exit(1);
		  
		}
		else{left=left->next; def_param_list=def_param_list->next;}

	}
	if(def_param_list!=NULL)
	{
		printf("Too few arguments in the Function call for %s\n",varn);
		exit(1);
	}
}
void fucn_check_name(struct Typetable *rettype,char *name,struct Paramstruct *paramlist)
{
	struct Paramstruct *temp,*plist;
	struct Gsymbol *dummy;
	int count=0;
	curr=headsymb;
	dummy=GLookup(name);

	if(dummy==NULL)
	{     
		printf("Function defnition %s without a previous declaration\n",name);
		//exit(1);
	}
	if(dummy->type!=rettype)
	{
		printf("Return type of function \"%s\" does not match in the declaration and defnition\n",name);
	//	exit(1);
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
			printf("Pptype:%s,Gptype:%s\n",plist->type->name,temp->type->name);
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
				      // fprintf(fptr,"HI IN LOC IN REG");
				       fprintf(fptr, "MOV R%d, BP\n", reg);
				       fprintf(fptr, "ADD R%d, %d\n",reg, loc);
				       return reg;
			       }
			case 24: {int loc = t->Lentry->binding;
						int reg=getReg();
						fprintf(fptr, "MOV R%d, BP\n",reg);
						fprintf(fptr, "ADD R%d, %d\n",reg,loc);
						fprintf(fptr, "MOV R%d, [R%d]\n", reg, reg);
						struct Typetable *Ttemp = t->type;
						t=t->right;
						while(t->right!=NULL){
							fprintf(fptr, "ADD R%d, %d\n",reg,t->val);
							fprintf(fptr, "MOV R%d, [R%d]\n",reg,reg);
							t=t->right;
						}
						fprintf(fptr, "ADD R%d, %d\n",reg,t->val);
						return reg;
					}
		       case 30://selfnode
				  {
				  	  int loc = t->Lentry->binding;
	
					  int reg = getReg();
					  fprintf(fptr, "MOV R%d, BP\n",reg);
					  fprintf(fptr, "ADD R%d, %d\n",reg,loc);
					  t = t->right;
					  while(t->right!=NULL && t->nodetype != 31){
						  fprintf(fptr, "MOV R%d, [R%d]\n",reg,reg);
						  fprintf(fptr, "ADD R%d, %d\n", reg, t->val);
						  t=t->right;
					  }
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
				      }
			case 24:{
					int reg = getReg();
					fprintf(fptr, "MOV R%d, %d\n",reg,loc);
					fprintf(fptr, "MOV R%d, [R%d]\n",reg, reg);
					struct Typetable *Ttemp = t->type;
					t=t->right;
					while(t->right!=NULL){
						fprintf(fptr, "ADD R%d, %d\n",reg,t->val);
						fprintf(fptr, "MOV R%d, [R%d]\n",reg,reg);
						t=t->right;

					}
					fprintf(fptr, "ADD R%d, %d\n",reg,t->val);
					return reg;}
		}
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
	else{printf("Error no more Registers are left");exit(1);}

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

int Alloc_Node(FILE *fptr){
	int reg_1 = getReg();
	fprintf(fptr, "MOV R%d, \"Alloc\"\n", reg_1);
	fprintf(fptr, "PUSH R%d\n", reg_1);
	fprintf(fptr, "MOV R%d, %d\n", reg_1, 8);
	fprintf(fptr, "PUSH R%d\n",reg_1);
	fprintf(fptr, "PUSH R%d\n",reg_1);				
	fprintf(fptr, "PUSH R%d\n",reg_1);				
	fprintf(fptr, "PUSH R%d\n",reg_1);				
	fprintf(fptr, "CALL 0\n");
	fprintf(fptr, "POP R%d\n",reg_1	);
	int reg_2 = getReg();
	fprintf(fptr, "POP R%d\n",reg_2);
	fprintf(fptr, "POP R%d\n",reg_2);
	fprintf(fptr, "POP R%d\n",reg_2);
	fprintf(fptr, "POP R%d\n",reg_2);
	fprintf(fptr, "MOV R%d, %d\n",reg_2, -1);
	fprintf(fptr, "EQ R%d, R%d\n",reg_2, reg_1);
	int label_1 = getLabel();
	fprintf(fptr, "JZ R%d, L%d\n",reg_2, label_1);
	fprintf(fptr, "INT 10\n");
	fprintf(fptr, "L%d:",label_1);
	freeReg();
	return reg_1;
}

void Free_Heap(struct tnode *t,FILE *fptr){
        int reg_1 = getReg();
	fprintf(fptr, "MOV R%d, \"Free\"\n", reg_1);
	int reg_2 = Loc_In_Reg(t->left, fptr);
	fprintf(fptr, "MOV R%d, [R%d]\n",reg_1, reg_2);
	fprintf(fptr, "PUSH R%d\n", reg_1);
	fprintf(fptr, "PUSH R%d\n", reg_1);
	fprintf(fptr, "PUSH R%d\n", reg_1);
	fprintf(fptr, "CALL 0\n");
	fprintf(fptr, "POP R%d\n",reg_1);
	fprintf(fptr, "POP R%d\n",reg_1);
	fprintf(fptr, "POP R%d\n",reg_1);
	fprintf(fptr, "POP R%d\n",reg_1);
	fprintf(fptr, "POP R%d\n",reg_1);
}

int Initialize_Heap(FILE *fptr){
	int reg_1 = getReg();
	fprintf(fptr, "MOV R%d, \"Heapset\"\n", reg_1);
	fprintf(fptr, "PUSH R%d\n", reg_1);
	fprintf(fptr, "MOV R%d, %d\n", reg_1, 8);
	fprintf(fptr, "PUSH R%d\n",reg_1);
	fprintf(fptr, "PUSH R%d\n",reg_1);
	fprintf(fptr, "PUSH R%d\n",reg_1);
	fprintf(fptr, "PUSH R%d\n",reg_1);

	fprintf(fptr, "CALL 0\n");
	fprintf(fptr, "POP R%d\n",reg_1 );
	int reg_2 = getReg();
	fprintf(fptr, "POP R%d\n",reg_2);
	fprintf(fptr, "POP R%d\n",reg_2);
	fprintf(fptr, "POP R%d\n",reg_2);
	fprintf(fptr, "POP R%d\n",reg_2);
	return reg_1;
}
int codeGen(struct tnode *t, FILE *target_file) {
	    int p,q,eval,left,right,n0,n1,n2;
	    int n,x,i,j,l,n_reg,reg_1,reg_2, temp_count;
	    struct tnode *arglist;
	    struct Gsymbol *global;
            if(t!=NULL){
	    printf("type from Code Gen %d\n",t->nodetype);
	    switch(t->nodetype){
		    case 0:p=getReg();
                            			    
			    left=Loc_In_Reg(t->left,target_file);
                            read_console(left,target_file,1);
			    //freeReg();
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
                             //freeReg();
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
	           case 29 :  left=codeGen(t->left,target_file);
			     right=codeGen(t->right,target_file);
                             fprintf(target_file, "MOD R%d, R%d\n", left,right);
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


                 case 22: //fprintf(target_file,"Saving Machine state\n");
			  temp_count=-1;
			  for(n=0;n<=get_index;n++){
				   fprintf(target_file,"PUSH R%d\n",n);
				  temp_count=temp_count+1; 
			   }
			   //fprintf(target_file,"Evaluating Arguments and Pushing to stack\n");
			   arglist=t->left;
			   while(arglist!=NULL)
			   {
				   x=codeGen(arglist,target_file);
				   fprintf(target_file,"PUSH R%d\n",x);
				   freeReg();
				   arglist=arglist->next;
			   }
                          //fprintf(target_file,"Allocating stack to store return value\n");
			   fprintf(target_file,"PUSH R0\n");
			   curr=headsymb;
			   global=t->Gentry;
			   fprintf(target_file,"CALL F%d\n",global->flabel);
                          // fprintf(target_file,"Popping and saving return value\n");
			  // if(global->flabel==0){fprintf(target_file,"INT 10\n");}

			   i=getReg();
			   fprintf(target_file,"POP R%d\n",i);
                           // fprintf(target_file,"Saving arguments\n");

			   arglist=t->left;
			   
			   j=getReg();
		
			   while(arglist!=NULL)
			   {
				   fprintf(target_file,"POP R%d\n",j);
				   arglist=arglist->next;
			   }
			   freeReg();
                          // fprintf(target_file,"Restroring Machine state\n");

			   for(n=temp_count;n>=0;n--)
		   	   {				
	
				   fprintf(target_file,"POP R%d\n",n);
				   temp_count=temp_count-1;
			   }
			   return i;
		case 23: //rettype
			 l=codeGen(t->left,target_file);
		         //fprintf(target_file,"Return Start\n");

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
		case 24: p= getReg();
			 fprintf(target_file, "MOV R%d, [R%d]\n",p, Loc_In_Reg(t,target_file));
	 		 return p;
		case 25:n_reg = -1;
			for(int i=0; i<get_index; i++){
				fprintf(target_file, "PUSH R%d\n",i);
				n_reg++;
			}
                         int reg1=Alloc_Node(target_file);
			 for(int j=n_reg; j>=0; j--){
				fprintf(target_file, "POP R%d\n",j);
			}
			reg_2 = Loc_In_Reg(t->left, target_file);
			fprintf(target_file, "MOV [R%d], R%d\n",reg_2, reg1);
			freeReg();
			return -1;
		case 26:n_reg = -1;
			for(int i=0; i<get_index; i++){
				fprintf(target_file, "PUSH R%d\n",i);
				n_reg++;
			}
		Free_Heap(t,target_file);
			for(int j=n_reg; j>=0; j--){
				fprintf(target_file, "POP R%d\n",j);
			}

			freeReg();
			return -1;

		case 27:n_reg = -1;
			for(int i=0; i<get_index; i++){
				fprintf(target_file, "PUSH R%d\n",i);
				n_reg++;
			}
			reg_1=Initialize_Heap(target_file);
			for(int j=n_reg; j>=0; j--){
				fprintf(target_file, "POP R%d\n",j);
			}

			reg_2 = Loc_In_Reg(t->left, target_file);
			fprintf(target_file, "MOV [R%d], R%d\n",reg_2, reg_1);
			freeReg();
		       	return -1;
		case 28://NULLTYPE
			i=getReg();
			fprintf(target_file,"MOV R%d, 0\n",i);
			return i;
			break;
		case 30://self.length type
			reg_1 = loc_in_reg(t, target_file);
			fprintf(target_file, "mov r%d, [r%d]\n", reg_1, reg_1);
			return reg_1;
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
	else if(Cptr!=NULL)
	{
		struct Memberfunclist *mfunc;
		mfunc=Class_Mlookup(Cptr,fname);
		fl=mfunc->Flabel;
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

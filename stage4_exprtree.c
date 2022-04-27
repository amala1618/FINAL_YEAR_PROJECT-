int get_index=-1;
int variable_array[26];
int newlabel=0;
int bind=4096;
int curr_type=-1;
int activate=0;
int loc=0;
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

struct Gsymbol *headsymb=NULL;
struct Gsymbol *curr=NULL;

void Install(char *name, int type, int size,int rows, int coloumns){
	//printf("variable name inside install is %s and size of name is %lu and size of char is %lu",name,sizeof(name) ,sizeof(char));
        curr=headsymb;
	if(Lookup(name)==NULL){
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

struct Gsymbol *Lookup(char * name){
	if(curr==NULL){return curr;}
	else{
	int cmp=strcmp(name,curr->name);
	if(cmp==0){
		return curr;}
	else{
		curr=curr->next;Lookup(name);} }
}

void print_symbol_table(){
    if(curr!=NULL){
	    printf("\nName %s\n",curr->name);
	    printf("Type is %d\n",curr->type);
	    printf("Size is %d\n",curr->size);
	    printf("Binding %d\n",curr->binding);
	    curr=curr->next;
	    print_symbol_table();
    }
}
struct tnode* createTree(int v, int t, char* vn, int nt, struct tnode *l, struct tnode *r,struct tnode *nxt){
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
	temp->next=nxt;
	curr=headsymb;//temp->Gentry=(struct Gsymbol*)malloc(sizeof(struct Gsymbol));
        printf("Variable name (for node type %d) inside createTree: %s\n",temp->nodetype, (temp->varname));

	if(activate==1 & (temp->nodetype==8 || temp->nodetype==10)){
		curr=headsymb;
		temp->Gentry=Lookup(vn);
		if(temp->Gentry==NULL){
			printf("Variable name <%s> hasnt declared",vn);exit(1);}
		else{
			temp->type=(temp->Gentry)->type;}
		//printf("Variable name (for node type %d) inside createTree: %s\n",temp->nodetype, (temp->varname));
		return temp;}
	else{
		if(temp->nodetype==3 || temp->nodetype==4 || temp->nodetype==5 || temp->nodetype==6 || temp->nodetype==9|| temp->nodetype==11 || temp->nodetype==12||temp->nodetype==13 || temp->nodetype==14 || temp->nodetype==15|| temp->nodetype==16||temp->nodetype==24){
			if(((temp->right)->type != 0) || ((temp->left)->type != 0)) {
				printf("ERROR MISMATCH %d and %d",temp->right->type,temp->left->type);
				exit(1);
		} 
		else {
			temp->type = 0;}}
		return temp;}
	

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
	  // printf("Hi i am taking new reg index is %d",get_index);
	   get_index++;
	   return get_index;}
	else{get_index++;return get_index;printf("Error no more Registers are left");}

}

void freeReg(){if(get_index>0){
	   get_index--; 
}
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
int Loc_In_Reg(struct tnode* t, FILE *fptr){
//	printf("varname is %s, and val is %d",t->varname,t->val);
	if(t->Gentry!=NULL){
		int loc = t->Gentry->binding;
		switch(t->nodetype){
			case 8:{
				       int reg = getReg();
				       fprintf(fptr,"MOV R%d, %d\n",reg, loc);
				       return reg;


			       }
			case 10:if(t->right==NULL) {
					      printf("Hi in Loc in reg single dim array");
					     int offset = codeGen(t->left, fptr);
					     fprintf(fptr, "ADD R%d, %d\n",offset, loc);
					     return offset;


				     }else { // printf("Hi in Loc in reg single dim array");
					      int offset_1 = codeGen(t->left, fptr);
					      int offset_2 = codeGen(t->right, fptr);
					      int offset = offset_1*t->Gentry->coloumns+ offset_2;
					      fprintf(fptr,"MUL R%d, %d\n", offset_1, t->Gentry->coloumns);
					      fprintf(fptr, "ADD R%d, R%d\n",  offset_1, offset_2);
					      fprintf(fptr, "ADD R%d, %d\n", offset_1, loc);
					      //freeReg();
					     // freeReg();
					      return offset_1;			
				      }}
		}
		else{printf("There is some problem coz Gentry is NULL!!");exit(1);}

	}


int codeGen(struct tnode *t, FILE *target_file) {
	    int p,q,eval,left,right,n0,n1,n2,loc;
	    printf("type from Code Gen %d\n",t->nodetype);
	    switch(t->nodetype){
		    case 0:p=getReg();
                            			    
			   // fprintf(target_file,"READ\n");
			    left=Loc_In_Reg(t->left,target_file);
			    //for(n=0;n<=c;n++)	{
			//	    fprintf(target_file,"PUSH R%d\n",n);
			//	    sp=sp+1;
			  //  }
                            read_console(left,target_file,1);
			    freeReg();
			    /*
                            
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
			   fprintf(target_file,"MOV R%d,[%d]\n",p,(t->Gentry)->binding);
			   return p;
			   break;
                   case 9: left=Loc_In_Reg(t->left,target_file);
			   right=codeGen(t->right,target_file);
			   fprintf(target_file,"MOV [R%d],R%d\n",left,right);
			   freeReg();
			   //freeReg();
			   //printf("\nReturning value is %d\n",left);
			   return left;
			   break;/*
			   if(t->left->nodetype==10){
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
			  else{
			    left=(t->left)->Gentry->binding;
				    right=codeGen(t->right,target_file); 
				    fprintf(target_file,"MOV [%d], R%d\n",left,right);
				    freeReg();}
			return left;*/
	           case 10:left=Loc_In_Reg(t,target_file);
			   fprintf(target_file,"MOV R%d,[R%d]\n",left,left);
			   //printf("\nReturning value is %d\n",left);
			   loc=left;
			   return left;
			   break;/*
			   p=getReg();
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
		   case 11 : left=codeGen(t->left,target_file);
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
			     fprintf(target_file,"JZ R%d, L%d\n",left,n1);
			     right=codeGen(t->right,target_file);
                             fprintf(target_file, "JMP L%d\n", n0);
			     fprintf(target_file,"L%d:",n1);
			     freeReg();
			     //freeReg(); 
			     return left;
			     break;
		 case 18 :   left=codeGen(t->left,target_file);
			     n2=getLabel();
			     fprintf(target_file,"JZ R%d, L%d\n",left,n2);
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
		case 24:     left=codeGen(t->left,target_file);
			     right=codeGen(t->right,target_file);
			     fprintf(target_file, "MOD R%d, R%d\n", left,right);
			     freeReg();
			     return left;
			     break;






	    }      
}


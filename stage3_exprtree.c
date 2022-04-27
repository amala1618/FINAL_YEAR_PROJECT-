int get_index=0;
int variable_array[26];
int newlabel=0;
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

struct tnode* createTree(int v, int t, char* vn, int nt, struct tnode *l, struct tnode *r){
        struct tnode *temp;
	temp = (struct tnode*)malloc(sizeof(struct tnode));
	temp->val=v;
	temp->type=t;
	if(vn!=NULL){
	temp->varname=(char *) malloc(2*sizeof(char));
	*(temp->varname)=*vn;
	(temp->varname[1]) = '\0' ;}
	else{temp->varname=NULL;}
        temp->nodetype=nt;
	temp->left=l;
	temp->right=r;
        if(temp->nodetype==3 || temp->nodetype==4 || temp->nodetype==5 || temp->nodetype==6 || temp->nodetype==9){
		if(((temp->right)->type != inttype) || ((temp->left)->type != inttype)) {
			printf("ERROR MISMATCH");
			error("type mismatch");

			exit(1);
		} 
		else {
			temp->type = inttype;}}
	printf("Variable name (for node type %d) inside createTree: %s\n",temp->nodetype, (temp->varname));
	return temp;
	

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
	else{printf("Error no more Registers are left");}

}

void freeReg(){if(get_index>0){
	   get_index--; 
}
else{printf("Error cannot free less than get");}
}

int getLabel(){return newlabel++;}

void write_console(int reg_ind,FILE*fp){
     fprintf(fp,"MOV SP,4095\n");
     fprintf(fp,"MOV R1,\"Write\"\n");
     fprintf(fp,"PUSH R1\n");

     fprintf(fp,"MOV R1,-2\n");

     fprintf(fp,"PUSH R1\n");
     fprintf(fp,"PUSH R%d\n",reg_ind);
     fprintf(fp,"PUSH R1\n");
     fprintf(fp,"PUSH R1\n");
     fprintf(fp,"CALL 0\n");
     fprintf(fp,"POP R%d\n",reg_ind);
     fprintf(fp,"POP R1\n");
     fprintf(fp,"POP R1\n");
     fprintf(fp,"POP R1\n");
     fprintf(fp,"POP R1\n");}
void read_console(int regval,FILE *fp){
fprintf(fp,"MOV SP,4121\n");	
fprintf(fp,"MOV R1,\"Read\"\n");
fprintf(fp,"PUSH R1\n");
fprintf(fp,"MOV R1, 1\n");
fprintf(fp,"PUSH R1\n");
fprintf(fp,"MOV R0, %d\n",regval);
fprintf(fp,"PUSH R0\n");
fprintf(fp,"PUSH R1\n");
fprintf(fp,"PUSH R1\n");
fprintf(fp,"CALL 0\n");
fprintf(fp,"POP R0\n");
fprintf(fp,"MOV R0, [%d]\n",regval);
fprintf(fp,"POP R1\n");
fprintf(fp,"POP R1\n");
fprintf(fp,"POP R1\n");
fprintf(fp,"POP R1\n");




}
int codeGen(struct tnode *t, FILE *target_file) {
	    int p,q,eval,left,right,n0,n1,n2;
	    printf("type from Code Gen %d\n",t->nodetype);
	    switch(t->nodetype){
		    case 0: p=getReg();
                            			    
			    fprintf(target_file,"READ\n");
			    int regval=4096+*((t->left)->varname);
			    read_console(regval,target_file);
                            return -1;    
			    break;
		    case 1 :// fprintf(target_file,"WRITE IN CONSOLE\n");
                             left=codeGen(t->left,target_file);
			     write_console(left,target_file);
			     return -1;
			     break;
		    case 2 : left=codeGen(t->left,target_file);
			     right=codeGen(t->right,target_file);
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
                           printf("VAR NAME is :%d",3999+*(t->varname));
			   fprintf(target_file,"MOV R%d,[%d]\n",p,(3999+*(t->varname)));
			   return p;
			   break;
                   case 9: left=4096+(*(t->left)->varname);
                           right=codeGen(t->right,target_file); 
			   fprintf(target_file,"MOV [%d], R%d\n",left,right);
			   freeReg();
			   return left;
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
			     fprintf(target_file,"L%d:\n",n0);
			     left=codeGen(t->left,target_file);
			     n1=getLabel();
			     fprintf(target_file,"JZ R%d L%d\n",left,n1);
			     right=codeGen(t->right,target_file);
                             fprintf(target_file, "JMP L%d,\n", n0);
			     fprintf(target_file,"L%d:\n",n1);
			     freeReg(); 
			     return left;
			     break;
		 case 18 :  left=codeGen(t->left,target_file);
			     n2=getLabel();
			     fprintf(target_file,"JZ R%d L%d\n",left,n2);
			     right=codeGen(t->right,target_file);
                             fprintf(target_file, "L%d:", n2);
			     freeReg(); 
			     return left;
			     break;
	        case 19 :    left=codeGen(t->left,target_file);
			     right=codeGen(t->right,target_file);
                             //fprintf(target_file, "DIV R%d, R%d\n", left,right);
			     freeReg(); 
			     return left;
			     break;








	    }      
}


int get_index=-1;
int variable_array[26];
int newlabel=0;
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

void write_console(int reg_ind,FILE*fp){
     fprintf(fp,"\nMOV SP,4095\n");
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
fprintf(fp,"\nMOV SP,4121\n");	
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
	    int p,q,eval,left,right;
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
                           printf("VAR NAME is :%d",4096+*(t->varname));
			   fprintf(target_file,"MOV R%d,[%d]\n",p,(4096+*(t->varname)));
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
	           case 17 : //while 
			     fprintf(target_file,"L%d",newlabel);
			     left=codeGen(t->left,target_file);
			     newlabel++
                             fprintf(target_file, "JZ R%d, L%d\n", left,newlabel);
			     right=codeGen(t->right,target_file);
			     fprintf(target_file,"JMP L%d",newlabel-1);
			     fprintf(target_file,"L%d:",newlabel);
			     freeReg(); 
			     return left;
			     break;
	
	          case 18 :  //if
			     left=codeGen(t->left,target_file);
			     newlabel++
                             fprintf(target_file, "JZ R%d, L%d\n", left,right);
			     right=codeGen(t->right,target_file);
			     fprintf("L%d:",newlabel);
			     freeReg();
			     fprintf(target_file,"PUSH R%d",left); 
			     return left;
			     break;
	           
                  case 19: //else
	           
	           
	           
	           
	           
	             
	   
	    }      
}
         

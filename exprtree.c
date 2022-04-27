struct tnode* makeLeafNode(int n)
{
	    struct tnode *temp;
	    temp = (struct tnode*)malloc(sizeof(struct tnode));
	    temp->op = NULL;
	    temp->val = n;
	    temp->left = NULL;
	    temp->right = NULL;
	    return temp;
}

struct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r){
	    struct tnode *temp;
	    temp = (struct tnode*)malloc(sizeof(struct tnode));
	    temp->op = malloc(sizeof(char));
	    *(temp->op) = c;
	    temp->left = l;
	    temp->right = r;
	    return temp;
}

int evaluate(struct tnode *t){
	    if(t->op == NULL)
		        {
				return t->val;
		    	}
	    else{
		    switch(*(t->op)){
			    case '+' : return evaluate(t->left) + evaluate(t->right);
				       break;
			    case '-' : return evaluate(t->left) - evaluate(t->right);
				       break;
			    case '*' : return evaluate(t->left) * evaluate(t->right);
				       break;
			    case '/' : return evaluate(t->left) / evaluate(t->right);
				       break;
		    }
	    }
}


int get_index=1;

int getReg(){
	   get_index++;
	   return get_index;

}

void freeReg(){
	   get_index--; 
}
int codeGen(struct tnode *t, FILE *target_file) {
	          
	    if(t->op == NULL)
		        {   int p=getReg();
	                    fprintf(target_file, "MOV R%d, %d\n", p,t->val);
		            return p;
						    }
	   else{
		   int left=codeGen(t->left,target_file);
		   int right=codeGen(t->right,target_file);
		   switch(*(t->op)){
		                     case '+' : fprintf(target_file, "ADD R%d, R%d\n", left,right);
			                        freeReg();
			       		        return left;
					        break;
		                     case '-' : fprintf(target_file, "SUB R%d, R%d\n", left,right);
				                freeReg();
				 	       return left;
				               break;
				     case '*' : fprintf(target_file, "MUL R%d, R%d\n", left,right);
					       freeReg();
				               return left;
				               break;
				     case '/' : fprintf(target_file, "DIV R%d, R%d\n", left,right);
				               freeReg(); 
				               return left;
					       break;
	          }
	    }
}
         


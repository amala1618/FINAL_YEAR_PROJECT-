typedef struct tnode { 
	int val;	// value of a number for NUM nodes.
	int type;	//type of variable
	char* varname;	//name of a variable for ID nodes  
	int nodetype;  // information about non-leaf nodes - read/write/connector/+/* etc.  
	struct tnode *left,*right;	//left and right branches   
}tnode;
 
	
struct tnode* createTree(int v, int t, char* vn,int nt,struct tnode *l,struct tnode *r);



int evaluate(struct tnode *t);
int codeGen(struct tnode *t, FILE *target_file);

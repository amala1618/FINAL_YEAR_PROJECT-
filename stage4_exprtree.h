typedef struct tnode { 
	int val;	// value of a number for NUM nodes.
	int type;	//type of variable
	char* varname;	//name of a variable for ID nodes  
	int nodetype;  // information about non-leaf nodes - read/write/connector/+/* etc. 
	struct Gsymbol *Gentry;
	struct tnode *left,*right,*next;	//left and right branches   
}tnode;
typedef struct Gsymbol {
	char* name;
	int type;
	int size;
	int binding;
	int rows;
	int coloumns;
	struct Gsymbol *next;
}Gsymbol; 
	
struct tnode* createTree(int v, int t, char* vn,int nt,struct tnode *l,struct tnode *r,struct tnode *nxt);
struct Gsymbol *Lookup(char * name); // Returns a pointer to the symbol table entry for the variable, returns NULL otherwise.

void Install(char *name, int type, int size , int rows, int coloumns); // Creates a symbol table entry. 

int Loc_In_Reg(struct tnode* t, FILE *fptr);
int evaluate(struct tnode *t);
int codeGen(struct tnode *t, FILE *target_file);

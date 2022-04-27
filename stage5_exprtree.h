typedef struct tnode { 
	int val;	// value of a number for NUM nodes.
	int type;	//type of variable
	char* varname;	//name of a variable for ID nodes  
	int nodetype;  // information about non-leaf nodes - read/write/connector/+/* etc. 
	struct Gsymbol *Gentry;
	struct Lsymbol *Lentry;
	struct tnode *left,*right,*next;	//left and right branches   
}tnode;
typedef struct Lsymbol {
	char* name;
	int type;
	int binding;
	int rows;
	int coloumns;
	struct Lsymbol *next;
}Lsymbol; 
typedef struct Gsymbol{
	 char *name;
	 int type;
	 int size;
	 int binding;
	 int rows;
	 int coloumns;
	 struct Paramstruct *paramlist;
	 int flabel;
	 struct Gsymbol *next;
 }Gsymbol;
typedef struct Paramstruct {
	char* name;
	int type;
	struct Paramstruct *next;
}Paramstruct; 

void codeGen_f(struct tnode *t,char *fname, FILE *fp);
int Loc_In_Reg(struct tnode* t, FILE *fptr);
void LInstall(char *name,int type);
void Lsymbol_rst();
struct Lsymbol *LLookup(char *name);
void fucn_check_name(int rettype,char *name,struct Paramstruct *paramlist);
struct tnode *type_checking(struct tnode *node);
void func_check(char *varn,struct tnode *left);
struct tnode* createTree(int v, int t, char* vn,int nt,struct tnode *l,struct tnode *r,struct tnode *next);
struct Gsymbol *GLookup(char * name); // Returns a pointer to the symbol table entry for the variable, returns NULL otherwise.

struct Paramstruct *PLookup(struct Paramstruct *head,char * name);
struct Paramstruct *PInstall_each(char *name, int type,struct Paramstruct *headsymb_p);
struct Paramstruct *PInstall(struct Paramstruct *headsymb_pl, struct Paramstruct *new);
void GInstall(char *name, int type, int size,int rows, int coloumns,struct Paramstruct *param,int fl);
void Install(char *name, int type, int size , int rows, int coloumns); // Creates a symbol table entry. 

int getReg();
void freeReg();
int evaluate(struct tnode *t);
int codeGen(struct tnode *t, FILE *target_file);

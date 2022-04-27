typedef struct tnode { 
	int val;	// value of a number for NUM nodes.
	struct Typetable *type;	//type of variable
	char* varname;	//name of a variable for ID nodes  
	int nodetype;  // information about non-leaf nodes - read/write/connector/+/* etc. 
	struct Gsymbol *Gentry;
	struct Lsymbol *Lentry;
	struct tnode *left,*right,*next;	//left and right branches   
}tnode;
typedef struct Lsymbol {
	char* name;
	struct Typetable* type;
	int binding;
	int rows;
	int coloumns;
	struct Lsymbol *next;
}Lsymbol; 
typedef struct Gsymbol{
	 char *name;
	 struct Typetable* type;
	 int size;
	 int binding;
	 int rows;
	 int coloumns;
	 struct Paramstruct *paramlist;
	 int flabel;
	 struct Gsymbol *next;
	 struct Gsymbol *left;
 }Gsymbol;
typedef struct Paramstruct {
	char* name;
	struct Typetable* type;
	struct Paramstruct *next;
}Paramstruct; 
struct Typetable{
       	char *name;                 //type name
	int size;                   //size of the type
	struct Fieldlist *fields;   //pointer to the head of fields list
	struct Typetable *next;     // pointer to the next type table entry
}Typetable;
struct Fieldlist{
	char *name;              //name of the field
    	int fieldIndex;          //the position of the field in the field list
	struct Typetable *type;  //pointer to type table entry of the field's type
	struct Fieldlist *next;  //pointer to the next field
}Fieldlist;

void print_Typetable();
void TypeTableCreate();
void Tinstall(char *name, int size, struct Fieldlist *fields);
struct Typetable *TLookup(char *name);
struct Fieldlist *  Finstall(char *name, char* temp_type);
int GetSize(struct Typetable *Tentry);
struct Fieldlist * FLookup(struct Typetable *type, char *name);
//struct Typetable * checkvalidfieldandType(struct Typetable *ttemp, struct tnode* Node);
int Alloc_Node(FILE *fptr);
void Free_Heap(struct tnode *t, FILE *fptr);
int Initialize_Heap(FILE *fptr);

void codeGen_f(struct tnode *t,char *fname, FILE *fp);
int Loc_In_Reg(struct tnode* t, FILE *fptr);
void LInstall(char *name,struct Typetable* type);
void Lsymbol_rst();
struct Lsymbol *LLookup(char *name);
void func_check(char *varn,struct tnode *left);
void fucn_check_name(struct Typetable* rettype,char *name,struct Paramstruct *paramlist);
struct tnode *type_checking(struct tnode *node);
void func_check(char *varn,struct tnode *left);
struct tnode* createTree(int v, struct Typetable* t, char* vn,int nt,struct tnode *l,struct tnode *r,struct tnode *next);
struct Gsymbol *GLookup(char * name); // Returns a pointer to the symbol table entry for the variable, returns NULL otherwise.

struct Paramstruct *PLookup(struct Paramstruct *head,char * name);
struct Paramstruct *PInstall_each(char *name, struct Typetable* type,struct Paramstruct *headsymb_p);
struct Paramstruct *PInstall(struct Paramstruct *headsymb_pl, struct Paramstruct *new);
void GInstall(char *name, struct Typetable* type, int size,int rows, int coloumns,struct Paramstruct *param,int fl, struct Gsymbol *left);
void Install(char *name, struct Typetable* type, int size , int rows, int coloumns); // Creates a symbol table entry. 

int getReg();
void freeReg();
int evaluate(struct tnode *t);
int codeGen(struct tnode *t, FILE *target_file);
extern int activate;

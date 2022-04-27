 typedef struct lnode { 
	int address;
	char* labelname; 
	struct lnode *next;	//left and right branches   
}lnode;

struct lnode* createLinkedlist(char * labelname,int address,struct lnode *next);

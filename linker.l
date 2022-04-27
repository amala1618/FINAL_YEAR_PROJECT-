%{
	#include <stdlib.h>
	#include <stdio.h>
    #include <string.h>
    int iter = 1;
    int label = 0;
	int address = 2048;
    int a;
    char str[20];
    FILE *inFile, *outFile;
    typedef struct node{
        char* labelName;
        int labelAddress;
        struct node*next;
    }Node;
    Node* head = NULL;
    void addNode(char* labelName, int labelAddress);
    int getAddress(char* instruction);
    int getResultReg(char* instruction);
%}

label [a-zA-Z][a-zA-Z0-9_:]*

%%

{label}[ ]*:        {if(iter == 1) addNode(yytext,address);}
"JMP "{label}       {if(iter == 1) address+=2; if(iter == 2) fprintf(outFile,"JMP %d\n",getAddress(yytext));}
"CALL "{label}      {if(iter == 1) address+=2; if(iter == 2) fprintf(outFile,"CALL %d\n",getAddress(yytext));}
"JZ ".*             {if(iter == 1) address+=2; if(iter == 2) fprintf(outFile,"JZ R%d, %d\n",getResultReg(yytext),getAddress(yytext));}
"JNZ ".*            {if(iter == 1) address+=2; if(iter == 2) fprintf(outFile,"JNZ R%d, %d\n",getResultReg(yytext),getAddress(yytext));}
[0-9]+              {if(iter == 1) address+=1; else fprintf(outFile,"%s\n",yytext);}
.*                  {if(iter == 1) address+=2; else fprintf(outFile,"%s\n",yytext);}
\n                  {}

%%

int yywrap(void) {
    if (iter == 1){
        iter++;
        if(inFile){
            rewind(inFile);
		    yyin = inFile;
        }
        return 0;
    }
    else
	    return 1;
}


void addNode(char* labelName, int labelAddress){
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node -> labelName = (char*)malloc((yyleng+1)*sizeof(char));
    char* ptr = new_node -> labelName;
    while (*labelName != ':'){
        *(ptr) = *labelName;
        ptr++;
        labelName++;
    }
    *ptr = '\0';
    new_node -> labelAddress = labelAddress;
    new_node -> next = head;
    head = new_node;
}

int getAddress(char* instruction){
    char* name = (char*)malloc((yyleng+1)*sizeof(char));
    name = strcpy(name, instruction);
    name = strtok(name," ,");
    char* c;
    while (name != NULL)
    {
        c = name;
        name = strtok (NULL, " ,");
    }
    name = c;
    Node* ptr = head;
    while (ptr!= NULL){
        if (strcmp(ptr->labelName, name) == 0)
        {
             //printf("%s : %d\n",ptr->labelName, ptr->labelAddress);
             return ptr -> labelAddress;
        }
        ptr = ptr -> next;
    }
}

int getResultReg(char* instruction){
    char* regNum = (char*)malloc((yyleng+1)*sizeof(char));
    regNum = strcpy(regNum, instruction);
    regNum = strtok(regNum," ,");
    regNum = strtok(NULL," ,");
    regNum++;
    int r = atoi(regNum);
    return r;
}

int main(int argc, char* argv[]){
	if(argc > 1)
	{
		inFile = fopen(argv[1], "r");
		if(inFile) yyin = inFile;
	}
    if(argc > 2) outFile = fopen(argv[2], "w");
    else outFile = fopen("exec.xsm","w");
	yylex();
    fclose(outFile);
    if(argc > 2) printf("Generated executable : %s\n", argv[2]);
    else printf("Generated executable : %s\n", "exec.xsm");
	return 1;
}

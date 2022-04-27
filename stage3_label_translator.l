
%{
	#include <stdlib.h>
	#include <stdio.h>
	#include "stage3_label_translator.h"
        #include "stage3_label_translator.c"
        int count=0;
	int addr=2040;
        char *name;
        int addrs;
        char *variable;
        int linenumber;
        struct lnode *head=NULL;
        FILE *fp;

%}

%%

[a-zA-Z][a-zA-Z0-9]*[:] {if(count==0){variable=strdup(yytext);head=createLinkedlist(variable,addr,head);}}
[L|F][0-9]+ {if(count==1){printf("Hi\n");name=strdup(yytext);addrs=search(head,name,count);printf("\nAddress of %s is %d\n",name,addrs);}}
[\n]	{fprintf(yyout, "%s", yytext);/*printf("%d\n",addr);*/addr=addr+2;}
.	{ fprintf(yyout, "%s", yytext);}

%%

int yywrap(){
        if(count==0){
        count++;
         if(fp){
            rewind(fp);
		    yyin = fp;
        }
	printf("\nInside if of count\n");
        //fp=fopen("Output1.xsm","r");
        //if(fp){yyin=fp;}
        yyout=fopen("Output2.xsm","w");
        return 0;}
        else{return 1;}
}

int main()
{
extern FILE *yyin, *yyout,*fp;
    fp = fopen("Sample1.xsm", "r");
    yyin=fp;
    yyout = fopen("Output1.xsm", "w");
 
    yylex();
    fclose(yyin);
    fclose(yyout);
    return 0;
}

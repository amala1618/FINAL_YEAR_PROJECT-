
struct lnode* createLinkedlist(char* labelname, int address, struct lnode *head){
        struct lnode *temp;
	temp = (struct lnode*)malloc(sizeof(struct lnode));
	temp->address=address;
	labelname[strlen(labelname)-1] = '\0';
        temp->labelname=(char *) malloc(sizeof(labelname));
        
	if(labelname!=NULL){
	        strcpy(temp->labelname,labelname);}

        struct lnode *curr_node=head;
        if(head==NULL){
	head=temp;}
	else{
	while(curr_node->next!=NULL){curr_node=curr_node->next;}
	curr_node->next=temp;}
	printf("Linkedlist node created for label name is %s  and ",labelname);
	printf("Address name %d\n",temp->address);
	return head;
}
int search(struct lnode *head,char *name,int count){
printf("Name in search %s and its address is \n",name);
if(count==1){
if(head==NULL){return -1;}
else if(strcmp(name,head->labelname)==0 ){fprintf(yyout,"%d",head->address);printf("%d\n",head->address);
	return head->address;}
else{
printf("Label name in head is %s and addresss is %d\n",head->labelname,head->address);return search(head->next,name,count);
}
}
else{fprintf(yyout,"%s",yytext);}
}


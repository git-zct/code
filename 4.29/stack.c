#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int date;
	struct node *next; 
}Stack;
int Push(Stack *st,int e){
	Stack *newst=(Stack *)malloc(sizeof(Stack));
	if(newst!=NULL){
		
		newst->next=st->next;
		newst->date=e;
		st->next=newst; 
		return 1;//forget
	}
	printf("no place to store]\n");
	return -1;
}
int Pop(Stack *st,int *e){
	if(st->next==NULL)
		return -1;
	Stack *temp=st->next;
	st->next=temp->next;
	*e=temp->date;
	free(temp);
	return 1; 
}
int main()
{
	Stack *st=(Stack *)malloc(sizeof(Stack));
	st->next=NULL;
	Push(st,1);
	Push(st,2);
	Push(st,3);
	int ret,k;
	while((k=Pop(st,&ret))!=-1) printf("%d ",ret);
	free(st);
	 
}

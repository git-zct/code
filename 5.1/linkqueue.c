#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
typedef struct node{
	char a[10];
	struct node *next;
}Queue;
typedef struct list{
	Queue *head;
	Queue *tail;
}List;
int EnQ(List *list,char *name){
	Queue *newq=(Queue*)malloc(sizeof(Queue));
	newq->next=NULL;
	strcpy(newq->a,name);
	if(list->tail){
		list->tail->next=newq;
		list->tail=newq;
		return 1;
	}else{
		list->head=newq;
		list->tail=newq;
		return 1 ;
	}
} 
int DeQ(List *list,char *name){
	if(list->head==NULL){
		return -1;
	}
	strcpy(name,list->head->a);
	Queue *q=list->head;
	list->head=list->head->next;
	free(q);
	return 1;	
}
int main()
{
	List list;
	list.head=NULL;
	list.tail=NULL;
	char name[20];
	while(~scanf("%s",name)){
		EnQ(&list,name);
	}
	int k=0;
	while((k=DeQ(&list,name))!=-1) printf("%s\n",name);
	
}

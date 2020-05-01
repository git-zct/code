#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
	char name[20];
	struct node *next;
} Node;
typedef struct list{
	Node *head;
	Node* tail;
}List;
//void node_add(List *list,char* name){
//	Node *p=(Node *)malloc(sizeof(Node));
//	p->next=NULL;
//	strcpy(p->name,name);
//	if(list->head==NULL){
//		list->head=p;
//		return ;
//	}
//	p->next=list->head;
//	list->head=p;
//	return ;
//}
void node_add(List *list,char *name){
	Node *q=(Node *)malloc(sizeof(Node));
	strcpy(q->name,name);
	q->next=NULL;
	if(list->tail){
		list->tail->next=q;
		list->tail=q;
		return ;
	}
	else{
		list->head=q;
		list->tail=q;
		return ;
	}
}

void node_print(List *list)
{
	Node *p=list->head;
	for(;p!=list;p=p->next){
		printf("%s\n",p->name);
	} 
} 
int node_insert(List *list,int i,char *name){
	int j=1;
	if(i==1){
		Node *q=(Node*)malloc(sizeof(Node));
		strcpy(q->name,name);
		q->next=list->head;
		list->head=q; 
		return ;
	}		
	Node *p=list->head;
	while(p&&j++<i-1){
		p=p->next;
	}
	if(!p||j>i){
		return -1;
	}
	printf("ok");
	Node *q=(Node*)malloc(sizeof(Node));
	strcpy(q->name,name);
	q->next=p->next;
	p->next=q;
	return 1;
}
int main()
{
	List list;
	list.head=NULL;
	list.tail=NULL;
	char name[20];
	while(~scanf("%s",name)){
		node_add(&list,name);
	}
	list.tail->next=list->head;
	node_print(&list);
	int k;
	printf("输入插入的元素和位置\n");
	scanf("%s %d",name,&k);
	node_insert(&list,k,name);
	printf("插入后\n");
	node_print(&list);
	Node *p=list.head,*q=NULL;
	for(;p;p=q){
		q=p->next;
		free(p);
	}
}



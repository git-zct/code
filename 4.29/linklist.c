#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
	char name[20];
	struct node *next;
}Node;
typedef struct list{
	Node *head;
	Node *tail;
}List;
void node_add(List *list,char* );
void node_print(List *list);
void node_dele(List *list,char *);
void invert(List *list);
int main()
{
	char name[30];
	List list;
	list.head=NULL;
	list.tail=NULL;
	while(~scanf("%s",name)){
		node_add(&list,name);
	}
	node_print(&list);
	printf("输入删除姓名:\n");
	scanf("%s",name);
	node_dele(&list,name);
	node_print(&list);
	printf("————invert__\n");
	invert(&list);
	node_print(&list);
	Node *p=list.head,*q=NULL;
	int cnt=0;
	for(;p;p=q){
		q=p->next;
		free(p);
		cnt++;
	} 
	printf("删除了%d",cnt);
}
void node_add(List *list ,char *name){
	Node *q=(Node *)malloc(sizeof(Node));
	q->next=NULL;
	strcpy(q->name,name);
	if(list->tail){
		list->tail->next=q;
		list->tail=q;
		return;
		printf("ok");
	}else{
		list->head=q;
		list->tail=q;
		return ;
	}
}
void node_print(List *list){
	Node *q=list->head;
	for(;q;q=q->next){
		printf("%s\n",q->name);
	}
}
void node_dele(List *list,char *name){
	Node *q=list->head,*p=NULL;
	for(;q;q=q->next){
		if(strcmp(q->name,name)==0){
			if(p==NULL){
				
				list->head=list->head->next;
				free(q);
			}else{
				p->next=q->next;
				free(q);
				return ;
			}
		}
		p=q;
	} 
}
void invert(List *list){
	Node *p=list->head,*nw=NULL,*tmp=NULL;
	while(p){
		tmp=p->next;
		p->next=nw;
		nw=p;
		p=tmp;
	}
	list->head=nw;//忘了 
}

#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int a;
	struct node *prior; 
	struct node *next;
}Node;
void node_add(Node **head,int e){
	Node *p=(Node *)malloc(sizeof(Node));
	p->a=e;
	p->next=NULL;
	p->prior=*head;
	(*head)->next=p; 
	*head=p;	
}
void node_print(Node *head,int choice){
	if(choice==1){
	Node *p=head->next;
	printf("ok"); 
		for(;p;p=p->next){
	//		printf("te");
			printf("%d ",p->a);
		}
	}else if(choice == 2){
		Node *p=head;
		for(;p;p=p->prior){
			printf("%d ",p->a);
		} 
	}
}
void node_insert(Node **head,int i,int e){
	Node *p=(*head)->next;
	for(;i-1;i--){
		p=p->next;
	}
	Node *news=(Node *)malloc(sizeof(Node));
	news->a=e; 
	
	news->prior=p->prior;
	news->next=p;
	p->prior=news;
	news->prior->next=news;
}

int main()
{
	Node *A=(Node *)malloc(sizeof(Node));
	A->prior=NULL;
	A->next=NULL;
	Node *head=A;
	int a;
	while(~scanf("%d",&a)){
		node_add(&A,a);
	} 
	node_print(head,1);
	printf("方过来\n");
	node_print(A,2);
	printf("输入插入元素和位置\n");
	int where;
	scanf("%d %d",&a,&where); 
	Node *temp=A;
	A=head;
	printf("&&%d\n",A->next->a);
	node_insert(&A,where,a);
	printf("插入好了\n");
	node_print(head,1);
	printf("方过来\n");
	node_print(temp,2);

}

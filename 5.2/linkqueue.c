#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int a;
	struct node *next;
}Queue;
int EnQ(Queue *Q,int a){
	Queue *p=(Queue *)malloc(sizeof(Queue));
	p->a=a;
	p->next=Q->next;
	Q->next=p; 
}
int DeQ(Queue *Q,int *a){
	if(Q->next==NULL){
		printf("Empty\n");
		return -1;
	}
	*a=Q->next->a;
	Queue *temp=Q->next;
	Q->next=temp->next;
	free(temp);
}
int main(){
	Queue Q;
	Q.next=NULL;
	EnQ(&Q,1);
	EnQ(&Q,2);
	EnQ(&Q,3);
	int ret;
	DeQ(&Q,&ret);printf("%d ",ret);
	DeQ(&Q,&ret);printf("%d ",ret);
	DeQ(&Q,&ret);printf("%d ",ret);
	
}



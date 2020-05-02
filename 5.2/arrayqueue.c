#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
typedef struct node{
	int a[SIZE];
	int top; 
	int rear;
}Queue; 
int EnQ(Queue *Q,int e){
	if((Q->rear+1)%SIZE==Q->top){
		printf("full");return -1;
	}
	Q->a[Q->rear]=e;
	Q->rear=(Q->rear+1)%SIZE;
}
int length(Queue *Q){
	return (SIZE-Q->top+Q->rear)%SIZE;
}
int DeQ(Queue *Q,int *e){
	if(Q->rear==Q->top){
		printf("Empty");
		return -1;
	}
	*e=Q->a[Q->top];
	Q->top=(Q->top+1)%SIZE;
	return 1;
}
int main()
{
	 Queue A;
	 A.top=0;
	 A.rear=0;
	 int a;
	 while(~scanf("%d",&a)){
	 	EnQ(&A,a);
	 }
	 DeQ(&A,&a);
	 DeQ(&A,&a); 
	 EnQ(&A,1);
	 int k;
	 printf("length=%d\n",length(&A));
	 //while((k=DeQ(&A,&a))!=-1) printf("%d ",a);
	 
	 
} 

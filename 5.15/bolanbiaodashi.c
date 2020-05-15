#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
	int *date;
	int top;
	int size;	
}Stack;
int Push(Stack *st,int e){
	if(st->top==st->size-1){
		printf("full");
		return -1;
	}
	st->date[++st->top]=e;
}
int Pop(Stack *st){
	if(st->top==-1){
		printf("Empty");
	}
return	st->date[st->top--];
	
}
int fun(char **tokens,int tokensSize){
	Stack *st=(Stack *)malloc(sizeof(Stack));
	st->top=-1;
	st->size=100;
	char x,y,temp;
	st->date=(int *)malloc(sizeof(int)*st->size);
	for(int i=0;i<tokensSize;++i){
		if(!strcmp("+",tokens[i])){
			y=Pop(st);x=Pop(st);
			Push(st,x+y);
		}else if(!strcmp("-",tokens[i])){
			y=Pop(st);x=Pop(st);
		
			Push(st,x-y);
		}else if(!strcmp("*",tokens[i])){
			y=Pop(st);x=Pop(st);
		
			Push(st,x*y);
		}else if(!strcmp("/",tokens[i])){
			y=Pop(st);x=Pop(st);
			Push(st,x/y);
		}else{
			Push(st,atoi(tokens[i]));
		}
	}
	return st->date[0];
}
int main()
{
	int *a[20];
	a[0]=(int *)malloc(sizeof(int)*20);
	int j=0;
	while(~scanf("%s",a[j++])){
	a[j]=(int *)malloc(sizeof(int)*20);
	}
	int k=fun(a,j);
	printf("%d",k);
}

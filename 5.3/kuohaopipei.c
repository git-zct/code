#include<stdio.h>
#include<stdlib.h>	
typedef struct node{
	char a;
	struct node *next;	
}Stack;
void Push(Stack *st,char a){
	Stack *p=(Stack *)malloc(sizeof(Stack));
	p->a=a;
	p->next=st->next;
	st->next=p;
}
void Pop(Stack *st,char *a){
	if(st->next==NULL){
		return ;	
	}
	*a=st->next->a;
	Stack *p=st->next;
	st->next=st->next->next;
	free(p);
}
int IsEmpty(Stack *st){
	return (st->next==NULL);
}
int main()
{
	Stack *A=(Stack *)malloc(sizeof(Stack));
	A->next=NULL;
	char str[20];
	scanf("%s",str);
	int i=0,flag=0;
	char e;
	while(str[i]!='\0'){
		switch(str[i]){
			case '(':Push(A,'(');break;
			case '{':Push(A,'{');break;
			case '<':Push(A,'<');break;
			case ')':Pop(A,&e);
						if(e!='(')
							flag=1;
					break;
			case '>':Pop(A,&e);
						if(e!='<')
							flag=1;
					break;
			case '}':Pop(A,&e);
						if(e!='{')
							flag=1;
					break;
		}
		i++;
	}
	if(IsEmpty(A)&&flag==0){
		printf("yes");
	}else{
		printf("no");
	}
}



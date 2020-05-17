#include<stdio.h>//先序转后续怎么转 
#include<stdlib.h>
#include<string.h>
void fun(char **a,int );
int isnum(char *a){
	if(*a=='*'||*a=='+'||*a=='/')
		return 0;
	if(*a=='-'&&strlen(a)==1)
		return 0;
//	printf("*a=%c\n",*a);
	return 1;
}

int main(){
	char *a[20];
	a[0]=(char*)malloc(sizeof(char)*3);
	int i=0;
	while(~scanf("%s",a[i++])){
		a[i]=(char *)malloc(sizeof(char)*10);
	}
	fun(a,i-1);//i-1
}
void fun(char **a,int len){
	int *st=(int *)malloc(sizeof(int)*20);
	int top=-1;
	int x,y;
	for(int i=0;i<len;++i){
		if(isnum(a[i])){
			st[++top]=atoi(a[i]);
			//printf("^%d %d\n",atoi(a[i]),st[top]);
		}else{
			y=st[top--];
			x=st[top--];
			char c=a[i][0];//为什么c=a[i]就是乱码，因为不匹配 
			switch(c){
				case '+':st[++top]=x+y;break;
				case '-':st[++top]=x-y;break;
				case '*':st[++top]=x*y;break;
				case '/':st[++top]=x/y;break;
			}
		}
	}
	printf("%d",st[0]);
}

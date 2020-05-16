#include<stdio.h>//计算器后续波兰 
#include<string.h>
#include<stdlib.h>
char* fun(char *a);
int main()
{
	char a[100];
	scanf("%s",a);
	printf("%s",fun(a));
}
char* fun(char *a)
{
	int len=(int)strlen(a);
	char *st=(char*)malloc(sizeof(char)*100);
	int top=-1;
	for(int i=0;i<len;++i){
		if(a[i]!=']'){
			st[++top]=a[i];
		}else{
			int k=0;
			char temp[100];
			while(st[top]!='['){
				temp[k++]=st[top--];
			}
			top--;
			int num=0;
			while(st[top]>='0'&&st[top]<='9'){
				num=num*10+(st[top--]-'0');//top--
			}
			for(int i=0;i<num;++i){//注意内部函数 
				for(int j=k-1;j>=0;--j){
					st[++top]=temp[j];
				}
			}
		}
	}
	st[++top]='\0';
	return st;
}
//2[c]*
//c[c]/

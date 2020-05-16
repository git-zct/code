#include<stdio.h>
#include<stdlib.h>
int fun(char **a,int );
int main()
{
	char *s[30];
	s[0]=(char *)malloc(sizeof(char)*2);
	int i=0;
	while(~scanf("%s",s[i++])){
		s[i]=(char *)malloc(sizeof(char)*2);
	}
	for(int j=0;j<i-1;++j){
		printf("%s\n",s[j]);
	}
	printf("%d",fun(s,i));
}
int fun(char **a,int k){
	char *st=(char *)malloc(sizeof(char)*k);
	int top=-1;
	while(int i=0;i<k;++i){
		if(strcmp(a[i],"]")){
			st[++top]=a[i];
		}else{
			int temptop=-1;
			char *tst=(char*)malloc(sizeof(char)*(top+1));
			while(st[top]!='['){
				tst[++]
			}
		}
	}
} 

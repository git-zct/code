//11.17
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
char *fun(char *);
int main()
{
	char s[100];
	scanf("%s",s);
	printf("%s",fun(s));
}
char *fun(char *s){
	int len=(int)strlen(s);
	char *stack=(char *)malloc(sizeof(char)*100);
	char c;
	int top=-1;
	for(int i=0;i<len;++i){
		c=s[i];
		if(c!=']'){
			stack[++top]=c;
		}else{
			int temptop=-1;
			char *tempstack=(char *)malloc(sizeof(char)*100);
			while(stack[top]!='['){
				tempstack[++temptop]=stack[top--];				
			}
			top--;
			char *cpyStr=(char *)malloc(sizeof(char)*(temptop+2));
			int k=0;
			while(temptop!=-1){
				cpyStr[k++]=tempstack[temptop--];
			} 
			cpyStr[k]='\0';
			
			int cpyNum=0;
			int p=0;
			while(top>=0&&stack[top]>='0'&&stack[top]<='9'){
				cpyNum+=(stack[top--]-'0')*pow(10,p++);
				//top--;
			}
			
			for(int i=0;i<cpyNum;++i){
				for(int j=0;j<strlen(cpyStr);++j){
					stack[++top]=cpyStr[j];
				}
			}
			free(tempstack);//在一个作用区间 
		}
		
	}
	char *result=realloc(stack,(top+2)*sizeof(char));
		result[++top]='\0';
		return result;
}

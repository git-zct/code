#include<stdio.h>
void fun(int *,int *e,int *r,int,int);
int main()
{
	int a[9]={1,7,4,2,5,3,9,6,8};
	int le,ri;

	int key;
	scanf("%d",&key);
	fun(a,&le,&ri,9,key);
	printf("a[%d-1]:%d a[%d-1]:%d\n",le,a[le-1],ri,a[ri-1]);
}
void fun(int *a,int *e,int *r,int len,int key){
	int book[100]={0};
	for(int i=0;i<=len;++i){
		if(key<=a[i]||book[key-a[i]]==0){
			book[a[i]]=i+1;
		}else{
			*r=i+1;
			*e=book[key-a[i]];
			return ;
		}
	}
}

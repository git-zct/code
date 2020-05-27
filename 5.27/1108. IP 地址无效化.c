char * defangIPaddr(char * address){
    char* a=(char*)malloc(sizeof(char)*40);
    int top=-1,i=0;
    while(address[i]){
        if(address[i]!='.'){
            a[++top]=address[i++];
        }else{
            if(top<37){
            a[++top]='[';
            a[++top]='.';
            a[++top]=']';
            }
            i++;//忘了成死循环
        }
    }
    a[++top]='\0';
    return a;
}

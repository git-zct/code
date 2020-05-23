//注意；如果字符串带空格则用      get/fgets , scanf遇到空格就停止读入
char* replaceSpace(char* s){
   
   char *st=(char*)malloc(sizeof(char)*(10000));
    int top=-1;
    int i=0;
    while(s[i]!='\0'){
    
        if(s[i]!=' '){//s[i]>='a'||s[i]<='z'是 且 不是 或 
            st[++top]=s[i];
        }else{
            st[++top]='%';
            st[++top]='2';
            st[++top]='0';
          
        }
        i++;
    }
    st[++top]='\0';

    return st;
}

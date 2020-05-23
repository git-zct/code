
	bool backspaceCompare(char * S, char * T){
		char st[1100];
	int top=-1;
	char st2[1000];
	int top2=-1;
	char ch;
	int i=0;
	while(ch=S[i++]){
		if(ch!='#'){
			st[++top]=ch;
		}else{
			if('#'==ch&&top!=-1){
				top--;
			}
		}
	}
	st[++top]='\0';

	i =0;
		while(ch=T[i++]){
		if(ch!='#'){
			st2[++top2]=ch;
		}else{
			if('#'==ch&&top2!=-1){
				top2--;
			}
		}
	}
	st2[++top2]='\0';

//	printf("%s %s",st,st2);
	if(top!=top2){
      
		return false;
//	}else{
//		
//		while(top>-1){//这不是top=0结束 是投票=-1结束 
//		
//			if(st[top--]!=st2[top2--]){
//			
//				return false;
//			}
//			
//		}
//		return true;
	}
    
    return strcmp(st,st2)==0; 
}

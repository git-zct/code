int reverse(int x){
    if(!x){
        return 0;
    }
    int flag=0;
    long temp=0;
  if(x<0){
      if(x==-2147483648){
          return 0;
      }
      x=-x;
      flag=1;
  }
    while(x){
        temp*=10;
        temp+=x%10;
        x/=10;
    }
    if(temp!=(int)temp){
        return 0;
    }
    if(flag){
        return -1*(int)temp;
    }else{
        return (int)temp;
    }
}
// #define isOverLength 0

// int reverse(int x){
//     long lRet = 0;
//     while(0 != x)
//     {
//         lRet = lRet * 10 + x % 10;
//         x = x / 10;
//     }

//     if((int)lRet != lRet)
//     {
//         return isOverLength;
//     }

//     return (int)lRet;
// }

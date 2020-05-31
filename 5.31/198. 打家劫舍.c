int rob(int* nums, int numsSize){
    if(numsSize<=0){
        return 0;
    }
    int dp[numsSize][2];
    dp[0][1]=nums[0];
    dp[0][0]=0;
    for(int i=1;i<numsSize;++i){
        dp[i][1]=nums[i]+dp[i-1][0];
        dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
    }
    return max(dp[numsSize-1][1],dp[numsSize-1][0]);
}
int max(int a,int b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}

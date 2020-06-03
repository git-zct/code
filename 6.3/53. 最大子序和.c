int maxSubArray(int* nums, int numsSize){
    int max=INT_MIN,temp=0;
    for(int i=0;i<numsSize;++i){
        temp+=nums[i];
        if(temp>max){
            max=temp;
        }
        if(temp<0) temp=0;
    }
    return max;
}

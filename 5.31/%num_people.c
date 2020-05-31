/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* distributeCandies(int candies, int num_people, int* returnSize){
    *returnSize=num_people;
    int *p=(int  *)malloc(sizeof(int)*(num_people+10));
    memset(p,0,sizeof(int)*(num_people+10));
    int k=0,i=1;
    while(candies>i){
        p[k]+=i;
        candies-=i;
        i++;
        k=(k+1)%num_people;
    }
    p[k]+=candies;
    return p;
}

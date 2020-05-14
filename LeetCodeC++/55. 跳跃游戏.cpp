//408ms
bool canJump(int* nums, int numsSize) {
    int n=numsSize;
    int* tmp=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        tmp[i]=0;
    for(int j=0;j<=nums[0];j++)
    {tmp[j]=1;if(j==n-1)return true;}
    for(int i=1;i<n-1;i++)
        if(tmp[i]>0)
        for(int j=0;j<=nums[i];j++){
            tmp[i+j]=1;
            if(i+j==n-1)return true;
        }
     return false;
}
//24ms
bool canJump(int* nums, int numsSize) {
int dp[numsSize];//必须要初始化
for(int i = 0; i < numsSize; ++i) dp[i] = 0;
for (int i = 1; i < numsSize; ++i) {
    dp[i] = dp[i - 1]<nums[i - 1]?nums[i - 1]- 1:dp[i - 1]-1;
    if (dp[i] < 0 && i !=numsSize-1) return false;
    }
    return dp[numsSize - 1] >= 0;
}

//思路 维护一个数组 代表到i位置时候剩余的步数，到在最后位置时候>0即可 bool canJump(int* nums, int numsSize) { int dp[numsSize];//必须要初始化 for(int i = 0; i < numsSize; ++i) dp[i] = 0; for (int i = 1; i < numsSize; ++i) { dp[i] = dp[i - 1]<nums[i - 1]?nums[i - 1]- 1:dp[i - 1]-1; if (dp[i] < 0 && i !=numsSize-1) return false; } return dp[numsSize - 1] >= 0; }

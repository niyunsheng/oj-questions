/**
 * @Date:   2018-08-04
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-04
 */
 //与最场递增子序列不同点在于这个问题的处理稍微复杂，不仅要保存最长子序列的长度，还要保存其个数
 struct node{
     int len;//最长子序列的长度
     int num;//最长子序列的个数
 };
 class Solution {
 public:
     int findNumberOfLIS(vector<int>& nums) {
         int n=nums.size();
         if(n==0)return 0;
         vector<node> dp(n);//dp[i]表示已i结尾的最长递增子序列的长度
         dp[0].len=1;
         dp[0].num=1;
         int mxlen=1;//记录最长递增子序列的长度
         int sum=1;//最长递增子序列的个数

         for(int i=1;i<n;i++){
             dp[i].len=1;dp[i].num=1;
             for(int j=0;j<i;j++){
                 if(nums[i]>nums[j]){
                     if(dp[j].len+1>dp[i].len){
                         dp[i].len=1+dp[j].len;
                         dp[i].num=dp[j].num;
                     }else if(dp[j].len+1==dp[i].len){
                         dp[i].num+=dp[j].num;
                     }
                 }
             }
             if(dp[i].len>mxlen){mxlen=dp[i].len;sum=dp[i].num;}
             else if(dp[i].len==mxlen){sum+=dp[i].num;}
             //printf("dp[%d] len:%d num:%d sum:%d\n",i,dp[i].len,dp[i].num,sum);
         }
         return sum;
     }
 };

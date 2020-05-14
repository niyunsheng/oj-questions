/**
 * @Date:   2018-08-01
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-02
 */
 ////最长不下降子序列longest Increasing Sequence
 class Solution {
 public:
     int lengthOfLIS(vector<int>& nums) {
         int n=nums.size();
         if(n==0)return 0;
         int* dp=new int[n];
         dp[0]=1;
         int m=1;
         for(int i=1;i<n;i++){
             dp[i]=1;
             for(int j=0;j<i;j++){
                 if(nums[i]>nums[j])dp[i]=max(dp[j]+1,dp[i]);
             }
             m=max(m,dp[i]);
         }
         return m;
     }
 };

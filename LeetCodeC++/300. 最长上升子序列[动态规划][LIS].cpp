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

//// 上述算法是O(n*n)的， 用dp[i]表示以数组中第i个元素结尾的最长子序列的长度
//// 下面的算法是O(n*logn)的，用dp[i]表示最长子序列长度为i的序列的最后一个数字的最小值

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        int maxlength = 1;
        dp[0] = nums[0];
        for(int i=1;i<nums.size();i++){
            cout << nums[i];
            auto tmp = lower_bound(dp.begin(),dp.begin()+maxlength,nums[i]);
            *tmp = nums[i];
            if(tmp == (dp.begin()+maxlength))
                maxlength+=1;
        }
        return maxlength;
    }
};

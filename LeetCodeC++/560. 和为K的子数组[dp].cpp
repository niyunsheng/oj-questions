/**
 * @Date:   2018-08-22
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-23
 */
//答案用map记录出现的次数，非常简洁明了
//我写的O(n^2)答案，太慢了
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size(),cnt=0;
        if(n==0)return 0;
        vector<int> dp(n);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            dp[i]=dp[i-1]+nums[i];
        }
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(dp[j]-dp[i]+nums[i]==k)
                    cnt++;
            }
        }
        return cnt;
    }
};
//O(n)的答案
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> result;
        result[0] = 1;
        int sum = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (result.find(sum - k) != result.end()) {
                count += result[sum - k];
            }
            ++result[sum];
        }
        return count;
    }
};

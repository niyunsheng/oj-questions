/**
 * @Date:   2018-08-23
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-23
 */
//答案是用map实现的O(n)的方法，自己写的O(n2)太慢了
//答案
class Solution {
public:
    bool checkSubarraySum(vector<int> &nums, int k) {
        if (k == 0){
            for (int i = 0; i < nums.size() - 1; ++i) {
                if (nums[i] == 0 && nums[i + 1] == 0){
                    return true;
                }
            }
        } else{
            map<int, int> tmap;
            int runningSum = 0;
            for (int i = 0; i < nums.size(); ++i) {
                runningSum += nums[i];
                if (runningSum % k == 0 && i > 0){
                    return true;
                }
                if (tmap.find(runningSum % k) != tmap.end()){
                    if (i - tmap[runningSum % k] >= 1){
                        return true;
                    }
                } else{
                    tmap[runningSum % k] = i;
                }
            }
        }
        return false;
    }
};
//自己写的
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==0)return 0;
        vector<int> dp(n);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            dp[i]=dp[i-1]+nums[i];
        }
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(k==0){
                    if(dp[j]-dp[i]+nums[i]==0&&i<j)
                        return true;
                }else if((dp[j]-dp[i]+nums[i])%k==0&&i<j)
                    return true;
            }
        }
        return false;
    }
};

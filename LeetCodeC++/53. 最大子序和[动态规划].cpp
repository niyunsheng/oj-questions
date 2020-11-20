// dp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxnum = 0x80000000;
        int dp=0;
        for(int i=0;i<nums.size();i++){
            dp = max(dp+nums[i],nums[i]);
            maxnum = max(maxnum, dp);
        }
        return maxnum;
    }
};
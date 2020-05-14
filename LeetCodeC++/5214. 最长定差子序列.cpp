/***
动态规划：
用dp[i]表示以i结尾的数字的最长定差子序列的长度，由于数字的范围有限，所以采用数组和偏移来实现，也可以用map实现。
***/

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        vector<int> dp(20005,0); //dp[i]表示以i结尾的序列最大长度，默认为1，偏差是10000
        int A=1;
        for(int i=0;i<arr.size();i++){
            dp[arr[i]+10000] = 1;
            if(arr[i]-difference>=-10000 && arr[i]-difference<=10000){
                printf("%d %d\n",arr[i]+10000,arr[i]-difference+10000);
                dp[arr[i]+10000]=max(dp[arr[i]+10000],dp[arr[i]-difference+10000]+1);
            }
            A = max(A,dp[arr[i]+10000]);
            // printf("%d\n",A);
        }
        return A;
    }
};

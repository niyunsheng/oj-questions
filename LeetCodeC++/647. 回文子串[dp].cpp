/**
 * @Date:   2018-08-17
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-17
 */
class Solution {
public:
    //动态规划，dp[i][j]表示[i,j]是否是回文串,1表示是，2表示不是
	//经典方法
    int countSubstrings(string s) {
        int n=s.size();
        int sum=n;
        vector<vector<int>> dp(n,vector<int>(n));
        for(int i=0;i<n;i++)dp[i][i]=1;
        for(int i=0;i<n-1;i++)if(s[i]==s[i+1]){dp[i][i+1]=1;sum++;}else dp[i][i+1]=0;
        for(int i=2;i<n;i++){//间距的变化，初始化过0,1，这里从2开始
            for(int j=0;j+i<n;j++)
                if(s[j]==s[j+i]&&dp[j+1][j+i-1]){
                    dp[j][j+i]=1;sum++;
                }else{
                    dp[j][j+i]=0;
                }
        }
        return sum;
    }
};

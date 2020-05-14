/**
 * @Date:   2018-08-14
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-14
 */
class Solution {
public:
    //dp[i][j]表示从该点到达终点（右下角）所需的最小血量，此题的优点在于反其道而行之，将dp定义为从该点到终点，而不是从起点到该点，定义不同，遍历顺序不同，问题迎刃而解
    /*递归方程
        dp[i][j]+dungeon[i][j]>=dp[i+1][j]
        dp[i][j]+dungeon[i][j]>=dp[i][j+1]
        两者有一个成立即可，即dp[i][j]=max(min(dp[i+1][j],dp[i][j+1])-dungeon[i][j],1)
    */
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m=dungeon.size(),n=dungeon[0].size();
        vector<vector<int>> dp(m,vector<int>(n));
        dp[m-1][n-1]=max(1-dungeon[m-1][n-1],1);
        for(int i=m-2;i>=0;i--)dp[i][n-1]=max(dp[i+1][n-1]-dungeon[i][n-1],1);
        for(int i=n-2;i>=0;i--)dp[m-1][i]=max(dp[m-1][i+1]-dungeon[m-1][i],1);
        for(int i=m-2;i>=0;i--)
            for(int j=n-2;j>=0;j--){
                dp[i][j]=max(min(dp[i+1][j],dp[i][j+1])-dungeon[i][j],1);
            }
        return dp[0][0];
    }
};

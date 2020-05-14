/**
 * @Date:   2018-08-14
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-14
 */
class Solution {
public:
    //应该能感觉到，暴力肯定是要超时的，这个题目具有dp的特性，暴力的缺点就是由大量的重复子，应用dp迭代算法
    int mx,m,n;
    void DFS(int x,int y,int tmp,vector<vector<int>>& grid){
        if((x==m-1)&&(y==n-1)&&tmp<mx)mx=tmp;
        if(x+1<m)DFS(x+1,y,tmp+grid[x+1][y],grid);
        if(y+1<n)DFS(x,y+1,tmp+grid[x][y+1],grid);

    }
    int minPathSum(vector<vector<int>>& grid) {
        mx=0x7fffffff;
        m=grid.size();n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n));
        //DFS(0,0,grid[0][0],grid); return mx;

        //dp算法
        dp[0][0]=grid[0][0];
        for(int i=1;i<n;i++)dp[0][i]=grid[0][i]+dp[0][i-1];
        for(int i=1;i<m;i++)dp[i][0]=grid[i][0]+dp[i-1][0];
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++){
                dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
            }
        return dp[m-1][n-1];

    }

};

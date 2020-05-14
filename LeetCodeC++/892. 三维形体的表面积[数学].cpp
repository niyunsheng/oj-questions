/**
 * @Date:   2018-08-26
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-26
 */
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {

    //行最大值，列最大值，哪一格有数字不为0，遍历一遍标记即可
        int cnt=0,n=grid.size(),cnt1=0,cnt2=0;
        if(n==0)return 0;
        vector<vector<int> > hang=grid,lie=grid;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0)cnt++;
                if(i!=0)hang[i][j]=abs(grid[i][j]-grid[i-1][j]);
                if(j!=0)lie[i][j]=abs(grid[i][j]-grid[i][j-1]);
            }
        }



        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                cnt1+=hang[i][j];
                cnt2+=lie[i][j];
            }
        for(int i=0;i<n;i++){cnt1+=grid[n-1][i];cnt2+=grid[i][n-1];}
        return cnt*2+cnt1+cnt2;
    }
};

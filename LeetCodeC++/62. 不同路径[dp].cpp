/**
 * @Date:   2018-08-14
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-14
 */
class Solution {
    //处于节省空间的考虑，也可以考虑一位数组，一行一行的刷新
    //此题也有很数学的解法，实际相当于机器人总共走了m + n - 2步，其中m - 1步向下走，n - 1步向右走，那么总共不同的方法个数就相当于在步数里面m - 1和n - 1中较小的那个数的取法，实际上是一道组合数的问题
public:
    int uniquePaths(int m, int n) {
        int ans[m][n];
        for(int i=0;i<n;i++)ans[0][i]=1;
        for(int i=1;i<m;i++)ans[i][0]=1;
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++)
                ans[i][j]=ans[i][j-1]+ans[i-1][j];
        return ans[m-1][n-1];
    }
};

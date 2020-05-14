/**
 * @Date:   2018-08-01
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-01
 */
 /*
 思路：这个题目看起来和斐波那契数列的动态规划是同样的，改自上而下递归（含无穷多重复计算）为自下而上迭代
 最初看到这个题目是在北大OJ上，那么，这个题目和背包有什么关系呢？
 
 */
 class Solution {
 public:
     int minimumTotal(vector<vector<int>>& triangle) {
         int n=triangle.size();
         for(int i=n-2;i>=0;i--){
             for(int j=0;j<=i;j++){
                 triangle[i][j]+=min(triangle[i+1][j],triangle[i+1][j+1]);
             }
         }
         return triangle[0][0];
     }
 };

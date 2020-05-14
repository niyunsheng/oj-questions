/**
 * @Date:   2018-09-02
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-02
 */

/*
dp[i][j]表示A[i]|..|A[j]的值
如果直接Dp的话，O(N^2)，会超时
注意到每一行最多有30个不同的值，所以存在大量的重复，如果每一行的值是在上一行的值之上进行更新，每一行的值的个数均小于30个，就可以保证复杂度是O(30N)
第i行表示以i结尾的所有的连续子序列和的或值的个数，则第i+1行的值为i行的每一个结果与元素j或运算，再加上元素j本身。
即：
dp[0][0]
dp[0][1] dp[1][1]
dp[0][2] dp[0][2] dp[2][2]
...
dp[0][n-1] dp[1][n-1] ...dp[n-1][n-1]
关键点在于用set存储每一行的值，然后下一行直接与set里面的所有值或运算即可，将结果再存入存放结果的set当中
*/
class Solution {
public:
    int subarrayBitwiseORs(vector<int> A) {
        unordered_set<int> res, cur, cur2;
        for (int i: A) {
            cur2 = {i};
            for (int j: cur) cur2.insert(i|j);
            cur = cur2;
            for (int j: cur) res.insert(j);
        }
        return res.size();
    }
};

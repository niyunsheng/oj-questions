/**
 * @Date:   2018-08-16
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-16
 */
//总结：leetcode题目二十分钟思路还不清楚就看答案吧
/*本题开始用的贪心思想（不去证明的贪心很容易是错的），即找到连续正值最大的车站即为初始车站，但在调试的时候发现，这个想法是不对的，比如remain为3，-4,2,0，不仅需要考虑当前累计量，还得考虑后面的消耗
其实这个题目和贪心基本没啥关系，准确的解法应该是叫做双指针遍历+剪枝
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        vector<int> remain;
        for(int i=0;i<gas.size();i++){remain.push_back(gas[i]-cost[i]);}
        int n=gas.size();
        int lo=0,hi;//双指针遍历
        while(lo<n){//从i点出发尝试
            int sum=0;
            for(hi=lo;hi<n+lo;hi++){
                sum+=remain[hi%n];
                if(sum<0)break;
            }
            //cout<<"lo="<<lo<<" hi="<<hi<<endl;
            if(hi==n+lo)return lo;
            lo=hi+1;
        }
        return -1;
    }
};

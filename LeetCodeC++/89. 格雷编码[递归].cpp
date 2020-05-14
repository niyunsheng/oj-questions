/**
 * @Date:   2018-09-12
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-12
 */
#define bit(i) (1<<i)
//2^i
//利用格雷码的镜面排列的性质，如果知道了n-1位格雷码的排列，那么，在前面分别加0，加1反向，即为答案
class Solution {
public:
    vector<int> ans;
    vector<int> grayCode(int n) {
        DFS(n,0);
        return ans;
    }
    void DFS(int step,int tsum){
        if(step==0){
            ans.push_back(tsum);
            return;
        }
        DFS(step-1,tsum);
        int n=ans.size();
        for(int i=0;i<bit(step-1);i++){
            ans.push_back(ans[n-1-i]+bit(step-1));
        }

    }
};

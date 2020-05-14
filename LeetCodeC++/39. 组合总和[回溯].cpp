/**
 * @Date:   2018-09-03
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-03
 */
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> tmp;
    void solve(int step,int sum,int target,vector<int>& candidates){
        if(sum==target){
            ans.push_back(tmp);
            return;
        }
        //printf("%d %d\n",step,sum);
        if(step>=candidates.size())return;
        if(candidates[step]+sum<=target){
            tmp.push_back(candidates[step]);
            solve(step,candidates[step]+sum,target,candidates);
            tmp.pop_back();
        }
        solve(step+1,sum,target,candidates);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        solve(0,0,target,candidates);
        return ans;
    }

};

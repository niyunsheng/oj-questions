/**
 * @Date:   2018-09-12
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-12
 */


//很常见的利用DFS和数组回溯的求所有子集的例子
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> tmp;
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        DFS(1,n,nums);
        return ans;
    }
    void DFS(int step,int n,vector<int>& nums){
        if(step>n){
            ans.push_back(tmp);
        }else{
            DFS(step+1,n,nums);
            tmp.push_back(nums[step-1]);
            DFS(step+1,n,nums);
            tmp.pop_back();
        }
    }
};

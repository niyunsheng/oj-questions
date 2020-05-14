/**
 * @Date:   2018-07-21
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-07-28
 */



//503. 下一个更大元素 II
//99%
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        stack<int> s;
        vector<int> ans;
        if(nums.empty())return ans;
        int link[10000],maxnum=nums[0];

        s.push(0);
        for(int i=1;i<nums.size();i++){
            int t;
            maxnum=max(maxnum,nums[i]);
            while(!s.empty()&&nums[i]>nums[t=s.top()]){
                s.pop();
                link[t]=i;
            }
            s.push(i);
        }
		for(int i=0;i<nums.size();i++){
            int t;
            while(!s.empty()&&nums[i]>nums[t=s.top()]){
                s.pop();
                link[t]=i;
            }
            while(!s.empty()&&nums[t=s.top()]==maxnum){
                s.pop();
                link[t]=-1;
            }
        }
        for(int i=0;i<nums.size();i++){
            ans.push_back(link[i]==-1?-1:nums[link[i]]);
        }
        return ans;
    }
};

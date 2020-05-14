/**
 * @Date:   2018-07-21
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-07-28
 */



//496. 下一个更大元素 I
//利用Map和Stack，找到nums2中每个元素右边比自己大的数，存放到Map中，键存放自身，值存放比自己大的元素，找不到不存放；然后遍历nuns1寻找即可
//要注意这种预处理思想的运用，或者说是动态规划思想，避免了很多重复计算
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        map<int,int> m;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            int j=i+1;
            while(j<nums.size()){
                if(nums[j]>nums[i]){m[nums[i]]=nums[j];break;}
                j++;
            }
            if(j==nums.size())m[nums[i]]=-1;
        }
        for(int i=0;i<findNums.size();i++)
            ans.push_back(m[findNums[i]]);
        return ans;
    }
};

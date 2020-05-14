/**
 * @Date:   2018-08-22
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-22
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return 0;
        //双指针遍历
        int lo=0,hi=0,k=0;
        while(lo<n){
            hi=lo+1;
            nums[k++]=nums[lo];
            if(hi==n)break;
            if(nums[lo]!=nums[hi]){
                lo++;hi++;
            }else{
                nums[k++]=nums[lo];
                hi++;
                while(hi<n&&nums[hi]==nums[lo])hi++;
                lo=hi;
            }
        }
        return k;
    }
};

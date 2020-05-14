/**
 * @Date:   2018-08-22
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-22
 */
//答案方法更像是在考二分法，而自己的方法有点取巧了
//答案的这种方法是更应该掌握的
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 0)
            return -1;
        int low = 0, high = nums.size()-1;
        while(low <= high)
        {
            int mid = (low+high)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid]>nums[high])
            {
                if(nums[mid]>target && nums[low]<=target)
                    high = mid-1;
                else
                    low = mid+1;
            }
            else
            {
                if(nums[mid] <target && nums[high]>=target)
                    low = mid+1;
                else
                    high = mid-1;
            }
        }
        return -1;
    }
};
//我的方法
class Solution {
public:
    int search(vector<int>& nums, int target) {
        //直接找到反转的位置，再给反转回去，坐标变换输出
        int n=nums.size(),r=0;//r是数列最小元素的位置
        if(n==0)return -1;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){r=i+1;break;}
        }
        if(r!=0&&r!=n){
            reverse(nums.begin(),nums.begin()+r);
            reverse(nums.begin()+r,nums.end());
            reverse(nums.begin(),nums.end());
        }
        int ans=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(ans>=n||nums[ans]!=target)return -1;
        else return (ans+r)%n;
    }
};

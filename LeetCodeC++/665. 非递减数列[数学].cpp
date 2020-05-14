/**
 * @Date:   2018-08-14
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-14
 */
class Solution {
public:
    /*思路是这样的，首先考虑什么样的数组能够只改变一个元素就变成有序的呢，通常的情况是这样的就是两端都是有序的并且前端段的最右边和后段的最左边还是有序的，就中间出现了一个烦人的非有序的元素，比如1  2  3  8  5  6  7
    但是有两种特殊情况，就是第一个元素或者最后一个元素是非有序的，其他元素是有序的，这样的数列也是满足条件的数组。
    特殊情况处理，增加头尾哨兵，头部为无穷小，尾部为无穷大。
    将遇到的第一对递减元素，然后判断这对递减元素能否通过改变符合条件
    */
    bool checkPossibility(vector<int>& nums) {
        bool flag=false;//表示已经找到失配元素
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                if(i!=0&&(i+2)<nums.size()&&!((nums[i-1]<=nums[i]&&nums[i]<=nums[i+2])||(nums[i-1]<=nums[i+1]&&nums[i+1]<=nums[i+2])))return false;
                if(!flag)flag=true;
                else return false;
            }
        }
        return true;
    }
};

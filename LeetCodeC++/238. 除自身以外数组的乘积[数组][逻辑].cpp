/**
 * @Date:   2018-09-12
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-12
 */
//用数组分别记录该点左边元素的乘积和右边元素的成绩，为了省空间，右边元素不需要数组记录，用单变量记录即可
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> v(n);//v[i]表示nums[i]左边元素的乘积
        v[0]=1;
        for(int i=1;i<n;i++){
            v[i]=v[i-1]*nums[i-1];
        }
        int right=1;//依次计算nums[i]右边元素的成绩
        for(int i=n-1;i>=0;i--){
            v[i]*=right;
            right*=nums[i];
            //cout<<v[i];
        }
        return v;
    }
};

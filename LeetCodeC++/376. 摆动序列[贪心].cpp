/**
 * @Date:   2018-08-16
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-16
 */
/*题目要求O（n）解决。。
其实直接遍历一遍，保留上一次有效的差异（就是不相等时的情况），如果遇到一次有效的交替就计数+1就可以了
*/
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int cnt=1,n=nums.size(),state=0;//state为0表示未发现上升下降，1表示上升，0表示下降
        if(n<=1)return n;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]&&state<=0){
                state=1;cnt++;
            }else if(nums[i]<nums[i-1]&&state>=0){
                state=-1;cnt++;
            }
        }
        return cnt;
    }
};

/**
 * @Date:   2018-08-22
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-22
 */
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n=nums.size(),id;
        if(n==0)return -1;
        if(n==1)return 0;
        int n1=-1,n2=-1;//第一大、第二大的数
        if(nums[0]<nums[1]){n1=nums[1];n2=nums[0];id=1;}
        else{n1=nums[0];n2=nums[1];id=0;}
        for(int i=2;i<n;i++){
            if(nums[i]>=n2){
                if(nums[i]>=n1){
                    n2=n1;n1=nums[i];id=i;
                }else{
                    n2=nums[i];
                }
            }
        }
        if(n1>=2*n2)return id;
        else return -1;
    }
};

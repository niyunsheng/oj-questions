/**
 * @Date:   2018-07-22
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-07-28
 */



//42. 接雨水
class Solution {
public:
    int trap(vector<int>& height) {
        int sum=0;
        int i=0,j=height.size()-1;
        int k;
        while(i+1<=j)if(height[i]<=height[i+1])i++;else break;//定位到左侧第一个有效值
        while(j-1>=i)if(height[j]<=height[j-1])j--;else break;//定位到右侧第一个有效值
        while(i<j){
            for(k=i+1;k<=j;k++)
                if(height[k]>=height[i])break;
            if(k<=j){
                for(int m=i+1;m<k;m++)
                    sum+=height[i]-height[m];
                i=k;
            }else break;//退出循环表明i是向量中最大的数
        }
        while(i<j){
            for(k=j-1;k>=i;k--)
                if(height[k]>=height[j])break;
            if(k>=i){
                for(int m=j-1;m>k;m--)
                    sum+=height[j]-height[m];
                j=k;
            }
        }
        /*
        //下面这个解法避免不了重复计算的问题，所以改用双指针中间夹的方法
        //计算所有左边柱子为限的水域
        int i=0,j=0;
        while(i<height.size()){
            for(j=i+1;j<height.size();j++){
                if(height[j]>=height[i])
                    break;
            }
            if(j==height.size()){i++;}
            else{
                for(int k=i+1;k<j;k++)
                    sum+=height[i]-height[k];
                i=j;
            }
        }
        //计算右边柱子为限的水域
        i=height.size()-1;
        while(i>=0){
            for(j=i-1;j>=0;j--){
                if(height[j]>height[i])
                    break;
            }
            if(j<0){i--;}
            else{
                for(int k=i-1;k>j;k--)
                    sum+=height[i]-height[k];
                i=j;
            }
        }*/
        return sum;

    }
};

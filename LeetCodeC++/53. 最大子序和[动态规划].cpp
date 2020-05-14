/**
 * @Date:   2018-08-01
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-01
 */
 #include<iostream>
 #include"stdio.h"
 using namespace std;
 /*53. 最大子序和
 两种思路：
 思路1：第一种是根据最大子序列的特点，从头开始往后遍历
 如果碰到和为负数的情况即开始下一次遍历，此次失败的节点为hi，则下次从hi+1节点开始遍历
 过程中记录序列最大值
 思路2：DP分治法，果然有了好的定义，思路2的实现更加简洁
 关键在于定义f[j]，表示以A[j]结尾的最大连续子序列和
 显然f[0]=nums[0];
 if(f[i-1]>=0)
     f[i]=nums[i]+f[i-1];
 else f[i]=nums[i];

 */

 /*思路1

     int maxSubArray(vector<int>& nums) {
         int sum=0,m=nums[0];
         int lo=0,hi=0;
         while(hi<nums.size()){
             //while(nums[lo]<0)lo++;//注意数列中有全部为负数的情况，如果没有负数的话可以加上这句
             sum=nums[lo];hi=lo+1;m=max(sum,m);
             while(sum>=0&&hi<nums.size()){
                 sum+=nums[hi++];
                 m=max(sum,m);
             }
             lo=hi;
         }
         return m;
     }
 */
 /*思路2实现：
     int maxSubArray(vector<int>& nums) {
         int f[nums.size()];
         f[0]=nums[0];
         int m=f[0];
         for(int i=1;i<nums.size();i++){
             if(f[i-1]>=0)
                 f[i]=nums[i]+f[i-1];
             else f[i]=nums[i];
             m=max(m,f[i]);
         }
         printf("%d",m);

         return m;
     }

 */

int maxSubArray(vector<int>& nums) {
    int maxendinghere = 0;
    int maxsofar = 0;
    int maxnum = 0x80000000;
    for(int i=0;i<nums.size();i++){
        maxendinghere = max(maxendinghere+nums[i],0);
        maxsofar = max(maxsofar,maxendinghere);
        maxnum = max(maxnum,nums[i]);
    }
    return maxnum<0?maxnum:maxsofar;
}
 }

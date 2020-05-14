/**
 * @Date:   2018-07-28
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-07-28
 */
 /*
 同类型的需要用到本方法的题目还有
 31. 下一个排列
 60. 第k个排列【此题采用next_permutaion方法效率不高，应该用逆康托展开更快】
 */
 class Solution {
 public:
     //方法：自己实现next_permutation，此种方法也可以应对全排列中存在重复元素的请款
     /*思路：采用了康托展开的排序方法，顺序最小，逆序最大，康托展开是字符串全排列到自然数的一个双射，通常用于构建哈希表时空间压缩
     1.首先从最尾端开始往前寻找两个相邻元素，令第一元素为*i,第二元素为*ii,且满足*i<*ii。
     2.找到这样一组相邻元素后，再从最尾端开始往前检验，找出第一个大于*i的元素，令为*j，将i,j元素对调(swap)。
     3.再将ii(包括)及之后的所有元素颠倒(reverse)排序。
     思路参考：https://blog.csdn.net/c18219227162/article/details/50301513
     康托展开参考：https://blog.csdn.net/wbin233/article/details/72998375
     */
     bool next_permutation(vector<int>& nums,int lo,int hi){
         int i=hi-2,j=hi-1;
         //step1
         while(i>=lo){
             if(nums[i]<nums[i+1])break;
             i--;
         }
         if(i<lo)return false;
         //step2
         for(j=hi-1;j>i;j--){
             if(nums[j]>nums[i])break;
         }
         swap(nums[i],nums[j]);
         //step3
         reverse(nums.begin()+i+1,nums.end());
         return true;
     }
     vector<vector<int>> permuteUnique(vector<int>& nums) {
         vector<vector<int>> ans;
         int n=nums.size();
         if(n==0)return ans;
         sort(nums.begin(),nums.end());
         do{
             ans.push_back(nums);
         }while(next_permutation(nums,0,n));
         return ans;
     }
 };

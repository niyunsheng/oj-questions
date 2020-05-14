/**
 * @Date:   2018-07-28
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-07-28
 */
 /*
1   DFS，注意要点，答案只有在交换后才加入，交换后将其复原，以便下次循环
2   DFS，不用交换，而采用数组实现链表的方式，用flag记录元素是否在数组内，交换后复原
3   STL库中next_permutation
4   DFS，用set避免重复元素加入，最后通过迭代器将set转化为向量
5   自己实现STL库中next_permutation
 */
 class Solution {
 public:
     //方法一：递归,深度优先搜索，自己采用的这个方法是从后向前深度优先搜索，而方法四采用的是从前向后深度优先搜索
     vector<vector<int>> ans;//存放答案
     //秩index元素与前面元素互换，然后再对前面元素进行深度优先互换，将每一次互换后得到的全排列加入答案
     //遇到的问题：在函数内部何时将排列加入答案：应该是交换后才加入，不交换就不加入
     void permute(vector<int>& nums,int index){//注意参数传引用即可，因为深度优先是基于栈的，而在每一次深入优先搜索交换后，都令原数组恢复
         if(index==0)return;//递归基
         for(int i=0;i<index;i++){//分别于秩0-(index-1)的元素互换
             swap(nums[i],nums[index]);//互换
             ans.push_back(nums);//加入答案
             permute(nums,index-1);//进入递归
             swap(nums[i],nums[index]);//重新换回来，不影响下一次循环
         }
         permute(nums,index-1);
     }
     vector<vector<int>> permute(vector<int>& nums) {
         int n=nums.size();
         if(n==0)return ans;
         ans.push_back(nums);
         permute(nums,n-1);//排列倒数n个数结果写到ans里面
         return ans;
     }
 };
 class Solution {
 public:
	 //递归法二：用path数组来模拟路径，flag数组表示该节点是否已在路径中，每次循环新建path、flag数组，相当于复制数组。
     vector<vector<int>> ans;
     void process(int index, const vector<int>& nums){
         static int path[1000];
         static bool flag[1000];
         if(index == nums.size()){
             vector<int> tmp;
             for(int i=0; i<nums.size(); i++){
                 tmp.push_back(path[i]);
             }
             ans.push_back(tmp);
             return;
         }

         for(int i=0; i<nums.size(); i++){
             if(!flag[i]){
                 path[index] = nums[i];
                 flag[i] = true;
                 process(index+1, nums);
                 flag[i] = false;

             }
         }
     }
     vector<vector<int>> permute(vector<int>& nums) {
         process(0, nums);
         return ans;
     }
 };
class Solution {
public:
	//方法三：STL中下一个全排列算法next_permutation,注意用之前需要将nums排序，此方法也可用于带有重复元素的全排列
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        if(n==0)return ans;
        sort(nums.begin(),nums.end());
        do{
            ans.push_back(nums);
        }while(next_permutation(nums.begin(),nums.end()));
        return ans;
    }
};
class Solution {
public:
    //方法四：深度优先搜索，最快，这里居然用了set来避免重复元素的加入，总的来说，还是自己的方法好点
    set<vector<int>> result;
    void dfs(vector<int>& nums, int index){
        result.insert(nums);
        for(int i = index; i < nums.size(); ++ i){
            swap(nums[index],nums[i]);
            dfs(nums,index+1);
            swap(nums[index],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums,0);
        return vector<vector<int>>(result.begin(),result.end());
    }
};
class Solution {
public:
    //方法五：自己实现next_permutation，此种方法也可以应对全排列中存在重复元素的请款
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

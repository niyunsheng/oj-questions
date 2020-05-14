//解法一二用动态规划，通不过最后一个算例，解法三用贪心算法，OK
//解法一：动态规划，但是最后一个算例超时过不了
//自己最初写的方法，从前到后每一步都计算到最远可以跳到的位置，然后更新跳到该位置的步数，自己写这个和网上的动态规划解法虽然不同，但是复杂度是一样的
class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> ans(nums.size(),26000);
        ans[0]=0;
        for(int i=0;i<nums.size();i++){
            for(int j=1;j<=nums[i]&&i+j<nums.size();j++){
                if(ans[i]+1<ans[i+j])ans[i+j]=ans[i]+1;
            }
            //if(ans[nums.size()-1]<=i+1)break;
        }
        return ans[nums.size()-1];
    }
};

//解法二：动态规划，定义数组dp，dp[i]表示到达i处的最小跳跃次数。关键在确定dp[i]的值，我们可以遍历i之前的元素值，找到第一次能跳到或跳过i的下标，然后在其基础上加1即可。代码如下：

//从前到后依次更新dp[i]的值，最差O(n2)
class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),0);
        if(nums.size()==0)    return 0;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;++j){
                if(nums[j]+j>=i){
                    dp[i]=dp[j]+1;
                    break;
                }
            }
        }
        return dp[nums.size()-1];
    }
};

//解法三：贪心算法，其实和第一种我写的动态规划差不多，只是内循环判断的时候，省去了多余的步骤.i，j都当做绝对坐标，内循环判断省去多余步骤，并且适时剪枝

static auto x = [](){
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();//添加这一段就超过了100%的提交记录！
class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> ans(nums.size());//跳到每一格需要的步数
        ans[0]=0;
        int j,k=1;//i绝对坐标，j绝对坐标
        for(int i=0;i<nums.size();i++){
            for(j=k;j-i<=nums[i]&&j<nums.size();j++){
                ans[j]=ans[i]+1;
            }
            k=j;
            if(k==nums.size())break;
        }
        return ans[nums.size()-1];
    }
};

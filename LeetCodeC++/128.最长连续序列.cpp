
//只有这个节点是序列的开头的时候才去遍历，所以说，每个节点最多遍历一次，所以虽然是两层循环，但是复杂度还是O(n)

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hs;
        for(int i=0;i<nums.size();i++){
            hs.insert(nums[i]);
        }
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            if(hs.find(nums[i]-1)==hs.end()){
                int tmp=0,t=nums[i];
                while(hs.find(t)!=hs.end()){
                    t++;
                    tmp++;
                }
                ans = max(ans,tmp);
            }
        }
        return ans;
    }
};

// 时间复杂度：O(n)
// 尽管在 for 循环中嵌套了一个 while 循环，时间复杂度看起来像是二次方级别的。但其实它是线性的算法。因为只有当 currentNum 遇到了一个序列的开始， while 循环才会被执行（也就是 currentNum-1 不在数组 nums 里）， while 循环在整个运行过程中只会被迭代 nn 次。这意味着尽管看起来时间复杂度为 O(n \cdot n)O(n⋅n) ，实际这个嵌套循环只会运行 O(n + n) = O(n)O(n+n)=O(n) 次。所有的计算都是线性时间的，所以总的时间复杂度是 O(n)O(n) 的。
// 空间复杂度：O(n)
// 为了实现 O(1) 的查询，我们对哈希表分配线性空间，以保存 nums 数组中的 O(n)O(n) 个数字。除此以外，所需空间与暴力解法一致。

// 作者：LeetCode
// 链接：https://leetcode-cn.com/problems/longest-consecutive-sequence/solution/zui-chang-lian-xu-xu-lie-by-leetcode/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
/**
 * @Date:   2018-08-17
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-17
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums,int lo,int hi){
        if(lo==hi)return NULL;
        int mi=(lo+hi)/2;
        TreeNode* tmp=new TreeNode(nums[mi]);
        tmp->left=sortedArrayToBST(nums,lo,mi);
        tmp->right=sortedArrayToBST(nums,mi+1,hi);
        return tmp;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(!nums.size())return NULL;
        int lo=0,hi=nums.size(),mi=(lo+hi)/2;
        TreeNode* root=new TreeNode(nums[mi]);
        root->left=sortedArrayToBST(nums,lo,mi);
        root->right=sortedArrayToBST(nums,mi+1,hi);
        return root;
    }
};

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
    void travel(TreeNode* root,int& ans,int tmp){
        tmp = tmp*10+root->val;
        if(root->left==NULL && root->right==NULL){
            ans+=tmp;
        }
        if(root->left)travel(root->left,ans,tmp);
        if(root->right)travel(root->right,ans,tmp);
    }
    int sumNumbers(TreeNode* root) {
        int ans=0;
        if(root)
            travel(root,ans,0);
        return ans;
    }
};
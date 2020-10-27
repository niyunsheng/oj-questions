// 迭代算法
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode* > s;
        s.push(root);
        vector<int> ans;
        while(!s.empty()){
            TreeNode* t = s.top();
            s.pop();
            while(t!=nullptr){
                ans.push_back(t->val);
                // cout<<t->val<<endl;
                if(t->right)s.push(t->right);
                t = t->left;
            }
        }
        return ans;
    }
};
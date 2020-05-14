/**
 * @Date:   2018-08-20
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-20
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
 //自己的写法，很不简洁啊！应学习答案的写法！
class Solution {
public:
    bool has1(TreeNode* cur){
        bool flag=false;//不包含1
        if(cur==NULL)return false;
        if(cur->val==1)flag=true;
        flag|=has1(cur->left);
        flag|=has1(cur->right);
        return flag;
    }
    TreeNode* preorder(TreeNode* cur){
        if(cur==NULL)return cur;
        if(has1(cur->left))preorder(cur->left);
        else cur->left=NULL;
        if(has1(cur->right))preorder(cur->right);
        else cur->right=NULL;
        return cur;
    }
    TreeNode* pruneTree(TreeNode* root) {
        preorder(root);
        return root;
    }
};
//答案：
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(root==NULL)return NULL;
        root->left=pruneTree(root->left);
        root->right=pruneTree(root->right);
        if(!root->left&&!root->right&&root->val==0)return NULL;
        return root;
    }
};

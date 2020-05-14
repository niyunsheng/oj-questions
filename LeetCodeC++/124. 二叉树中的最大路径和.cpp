/**
 * @Date:   2018-09-11
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-11
 */
//DFS的过程中，注意判断值和返回值的不同
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
    int maxlen,maxnode;
    int DFS(TreeNode* root) {
        if(root==NULL)return 0;
        int t1=DFS(root->left),t2=DFS(root->right);
        maxnode=max(maxnode,root->val);
        //cout<<t1<<t2<<endl;
       // cout<<root->val<<endl;
        if(root->val>=0){
            if(root->val+t1+t2>maxlen)maxlen=root->val+t1+t2;
            //cout<<"max"<<maxlen<<endl;
            return root->val+max(t1,t2);
        }else{
            if(root->val+t1+t2>0){
                if(root->val+t1+t2>maxlen)maxlen=root->val+t1+t2;
            }
            if(root->val+max(t1,t2)>0)return root->val+max(t1,t2);
            else return 0;
        }
    }
    int maxPathSum(TreeNode* root) {
        maxnode=maxlen=root->val;
        DFS(root);
        if(maxlen>0)
            return maxlen;
        else return maxnode;
    }
};

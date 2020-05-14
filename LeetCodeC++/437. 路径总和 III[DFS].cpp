/**
 * @Date:   2018-08-16
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-16
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
//437. 路径总和 III
//DFS，递归回溯法,此种递归方法存在很多重复计算，好的方法是先序遍历，每个开头只计算一次。
//这个题目看似很难，首先想到的是递归时候增加分支，但是在调试的时候发现重复计算和计数的问题，所以改为每个节点为头进行一次以该节点为头的DFS
class Solution {
public:
    int target,i;

    void DFS(TreeNode* root, int sum,int& cnt){
        if(root==NULL)return;
        i++;
        //cout<<"i="<<i<<"   root->val="<<root->val<<"   sum="<<sum<<endl;
        if(root->val==sum){cnt++;}

        DFS(root->left,sum-root->val,cnt);
        DFS(root->right,sum-root->val,cnt);
        /*DFS中应该只计算一次开头元素
        sum=target;
        DFS(root->left,sum,cnt);
        DFS(root->right,sum,cnt);
        */
    }
    void preTrav(TreeNode* root, int sum,int& cnt){
        if(root==NULL)return;
        DFS(root,sum,cnt);
        preTrav(root->left,sum,cnt);
        preTrav(root->right,sum,cnt);
    }
    int pathSum(TreeNode* root, int sum) {
        int cnt=0;
        i=0;
        target=sum;
        preTrav(root,sum,cnt);
        return cnt;
    }
};

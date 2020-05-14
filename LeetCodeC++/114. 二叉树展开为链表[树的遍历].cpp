/**
 * @Date:   2018-08-15
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-15
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
    TreeNode* head,*tail;
	//注意这里要设为全局变量作为链表的头和尾，如果是局部变量的话不能在全局使指针后移，不能实现使链表增长的效果
    void preTrav(TreeNode* root){
        if(root==NULL)return;
		//注意在这里root的右子树改变了，所以，要保存下原值，递归使调用原值
		TreeNode* tmpR=root->right;
        tail->right=root;tail=tail->right;//cout<<root->val<<endl;
        preTrav(root->left);root->left=NULL;
        preTrav(tmpR);
    }
    //仔细观察可以发现，每一个节点的右孩子是前序遍历的下一个节点
    void flatten(TreeNode* root) {
        head=new TreeNode(0);
        tail=head;//初始化链表的头尾
        //前序遍历把发现的节点不断的加入到链表当中来
        preTrav(root);
        root=head->right;
        delete head;
    }
};

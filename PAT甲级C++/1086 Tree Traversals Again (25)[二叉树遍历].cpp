/**
 * @Date:   2018-07-31
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-07-31
 */
 #include<iostream>
 #include<queue>
 using namespace std;
 /*
 本题思路：pushpop操作与先序遍历加中序遍历是等同的，所以，先转化为先序中序遍历数组
 然后建树
 然后递归后序遍历输出到后序遍历数组
 最后输出答案
 */
 struct TreeNode{
     int data;
     TreeNode* lchild;
     TreeNode* rchild;
     TreeNode(int e,TreeNode* l=NULL,TreeNode* r=NULL):data(e),lchild(l),rchild(r){}
 };
 int* preorder,*inorder,*postorder,*_s;
 int postrank;
 int _find(int e,int lo,int hi){
     for(int i=lo;i<hi;i++)
         if(inorder[i]==e)return i;
     return 0;
 }
 TreeNode* createTree(int prelo,int prehi,int inlo,int inhi){
     if(inlo>=inhi)return NULL;
     TreeNode* cur=new TreeNode(preorder[prelo]);
     int inmi=_find(preorder[prelo],inlo,inhi);
     cur->lchild=createTree(prelo+1,prelo+inmi-inlo+1,inlo,inmi);
     cur->rchild=createTree(prehi+inmi+1-inhi,prehi,inmi+1,inhi);
     return cur;
 }
 void postTravel(TreeNode* root){
     if(root==NULL)return;
     postTravel(root->lchild);
     postTravel(root->rchild);
     postorder[postrank++]=root->data;
 }
 int main(){
     freopen("d:\\CodeBlockSpace\\input.txt","r",stdin);
     char str[5];
     int n,tmp;
     scanf("%d",&n);
     preorder=new int[n];int i=0,top=0;
     inorder=new int[n];int j=0;
     postorder=new int[n];
     _s=new int[n];
     for(int k=0;k<2*n;k++){
         scanf("%s",str);
         if(str[1]=='u'){//Push操作,先序遍历
             scanf("%d",&tmp);
             preorder[i++]=tmp;
             _s[top++]=tmp;
         }else{//pop操作，中序遍历
             inorder[j++]=_s[--top];
         }
     }
     TreeNode* root;
     root=createTree(0,n,0,n);
     postrank=0;
     postTravel(root);
     for(int i=0;i<n-1;i++)
         printf("%d ",postorder[i]);
     printf("%d",postorder[n-1]);
     return 0;
 }

/**
 * @Date:   2018-08-03
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-03
 */
//1043 Is It a Binary Search Tree (25)
//做这个题目忽略了重要的一点，对于BST，构造的顺序和先序遍历的顺序使一致的
//自己建一颗只需要插入操作的二叉树需要多久？建树20min搞定，调试及其他30min

 #include<iostream>
 #include<vector>
 #include<algorithm>
 using namespace std;
 class node{
 public:
     int data;
     node* lchild;
     node* rchild;
     node(int d,node* l=NULL,node* r=NULL):data(d),lchild(l),rchild(r){}

 };
 node* search(node* cur,int e){
     if(cur->lchild==NULL&&cur->data>e)return cur;
 	if(cur->rchild==NULL&&cur->data<=e)return cur;
     if(cur->data>e)return search(cur->lchild,e);
     else return search(cur->rchild,e);
 }

 void pretravel(node* cur,vector<int>& preorder){
     if(cur==NULL)return;
     preorder.push_back(cur->data);
     pretravel(cur->lchild,preorder);
     pretravel(cur->rchild,preorder);
 }

 void pretravelMirror(node* cur,vector<int>& preorder){
     if(cur==NULL)return;
     preorder.push_back(cur->data);

     pretravelMirror(cur->rchild,preorder);
 	pretravelMirror(cur->lchild,preorder);
 }
 void posttravel(node* cur,vector<int>& postorder){
     if(cur==NULL)return;
     posttravel(cur->lchild,postorder);
     posttravel(cur->rchild,postorder);
 	postorder.push_back(cur->data);
 }
 void posttravelMirror(node* cur,vector<int>& postorder){
     if(cur==NULL)return;
 	posttravelMirror(cur->rchild,postorder);
     posttravelMirror(cur->lchild,postorder);

 	postorder.push_back(cur->data);
 }
 bool equal(vector<int>& a,vector<int>& b){
 	if(a.size()!=b.size())return false;
 	for(int i=0;i<a.size();i++)
 		if(a[i]!=b[i])return false;
 	return true;
 }
 int main(){
     //freopen("D:\\input.txt","r",stdin);
     int n,e;
     scanf("%d",&n);
 	vector<int> start(n);
     vector<int> preorder;
     vector<int> inorder;
     vector<int> postorder;
 	vector<int> preorderMirror;
 	for(int i=0;i<n;i++)scanf("%d",&start[i]);
     node root(start[0]);
     for(int i=1;i<n;i++){
         e=start[i];
         node* t=search(&root,e);
         node* ne=new node(e);
         if(t->data>ne->data)t->lchild=ne;
         else t->rchild=ne;
     }
     pretravel(&root,preorder);
 	pretravelMirror(&root,preorderMirror);



 	if(equal(start,preorder)){
 		printf("YES\n");
 		posttravel(&root,postorder);
 		for(int i=0;i<postorder.size()-1;i++)printf("%d ",postorder[i]);
 		printf("%d",postorder[postorder.size()-1]);
 	}else if(equal(start,preorderMirror)){
 		printf("YES\n");
 		posttravelMirror(&root,postorder);
 		for(int i=0;i<postorder.size()-1;i++)printf("%d ",postorder[i]);
 		printf("%d",postorder[postorder.size()-1]);
 	}else{
 		printf("NO");
 	}
     //for(int i=0;i<preorder.size();i++)printf("%d ",preorder[i]);
     return 0;
 }

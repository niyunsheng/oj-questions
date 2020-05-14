/**
 * @Date:   2018-08-28
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-28
 */
/*
思路：因为是BST，所以排序后的节点序就是中序遍历，然后就可以根据中序遍历和先序遍历构造BST
然后就是找公共祖先了，首先排序节点不存在的情况
然后从根节点开始找，因为是BST，所以当两个节点分别属于左右两个分支时，即找到了最低公共祖先
*/
#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
void printvec(vector<int>& vec){
	printf("%d",vec[0]);
	_for(i,1,vec.size()){printf(" %d",vec[i]);}
	printf("\n");
}
struct node{
	int val;
	node *lc,*rc;
	node(int v,node* l=NULL,node* r=NULL):val(v),lc(l),rc(r){}
};

node* buildtree(vector<int>& preorder,int prelo,int prehi,vector<int>& inorder,int inlo,int inhi){

	if(prehi-prelo<=0)return NULL;
	int val=preorder[prelo];
	node* cur=new node(val);
	int r=lower_bound(inorder.begin()+inlo,inorder.begin()+inhi,val)-inorder.begin();

	cur->lc=buildtree(preorder,prelo+1,prelo+1+r-inlo,inorder,inlo,r);
	cur->rc=buildtree(preorder,prehi-(inhi-r-1),prehi,inorder,r+1,inhi);
	return cur;
}

int LCA(node* cur,int n1,int n2){//返回公共祖先的值
	if(cur->val==n1)return n1;
	if(cur->val==n2)return n2;
	if((cur->val-n1)*(cur->val-n2)<0)return cur->val;
	if(cur->val<n1)return LCA(cur->rc,n1,n2);
	if(cur->val>n1)return LCA(cur->lc,n1,n2);
}

int main(){
    //freopen("d:\\input.txt","r",stdin);
	int M,N;
	cin>>M>>N;
	vector<int> preorder(N),inorder(N);
	_for(i,0,N){cin>>inorder[i];preorder[i]=inorder[i];}
	sort(inorder.begin(),inorder.end());
	node* root;
	root=buildtree(preorder,0,N,inorder,0,N);

	int n1,n2;
	_for(i,0,M){
		cin>>n1>>n2;
		bool f1=true,f2=true;

		int r1=lower_bound(inorder.begin(),inorder.end(),n1)-inorder.begin();
		int r2=lower_bound(inorder.begin(),inorder.end(),n2)-inorder.begin();
		if(r1>=N||inorder[r1]!=n1)f1=false;
		if(r2>=N||inorder[r2]!=n2)f2=false;

		if(f1){
			if(f2){
				int f=LCA(root,n1,n2);
				if(f==n1)printf("%d is an ancestor of %d.\n",n1,n2);
				else if(f==n2)printf("%d is an ancestor of %d.\n",n2,n1);
				else printf("LCA of %d and %d is %d.\n",n1,n2,f);
			}else{
				printf("ERROR: %d is not found.\n",n2);
			}
		}else{
			if(f2){
				printf("ERROR: %d is not found.\n",n1);
			}else{
				printf("ERROR: %d and %d are not found.\n",n1,n2);
			}
		}
	}

	return 0;
}

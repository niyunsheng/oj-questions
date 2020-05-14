/**
 * @Date:   2018-09-01
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-01
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)

const int MAXN=30;
struct node{
	int val;
	node *lc,*rc;
	node(int v):val(v),lc(NULL),rc(NULL){}
};
vector<int> preorder(MAXN),inorder(MAXN);
node* root;
bool flag;
int blackheight=-1;
node* buildtree(int prelo,int prehi,int inlo,int inhi,int num,bool is_red){//黑节点数目
	if(prelo>=prehi){
		if(blackheight==-1)
			blackheight=num;
		else{
			if(num!=blackheight)
				flag=false;
		}
		return NULL;
	}
	node* cur=new node(preorder[prelo]);
	if(is_red&&cur->val<0){
		flag=false;return NULL;
	}
	if(cur->val>0){num++;is_red=false;}
	else is_red=true;
	int r=inlo;
	while(inorder[r]!=preorder[prelo])r++;
	cur->lc=buildtree(prelo+1,prelo+1+r-inlo,inlo,r,num,is_red);
	cur->rc=buildtree(prehi-inhi+r+1,prehi,r+1,inhi,num,is_red);
	return cur;
}
bool cmp(int a,int b){
	return abs(a)<abs(b);
}
int main(){
    //freopen("d:\\input.txt","r",stdin);
	int N,M,K,nv;
	int c1,c2;
	cin>>K;
	_for(i,0,K){
		cin>>N;
		_for(j,0,N){cin>>preorder[j];inorder[j]=preorder[j];}
		sort(inorder.begin(),inorder.begin()+N,cmp);
		flag=true;
		blackheight=-1;
		root=buildtree(0,N,0,N,0,true);
		//if(root->val<0)flag=false;
		if(flag)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}

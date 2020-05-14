/**
 * @Date:   2018-09-01
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-01
 */
#include<iostream>
#include<string>
#include<cstring>
#include<set>
#include<map>
#include<queue>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
int getint(){int x;scanf("%d",&x);return x;}
void printvec(vector<int>& vec){
	cout<<vec[0];
	_for(i,1,vec.size()){
		cout<<" "<<vec[i];
	}
	cout<<endl;
}
int N,flag;
const int MAXN=30;
vector<int> preorder(MAXN),postorder(MAXN),inorder;
struct node{
	int val;
	node *lc,*rc;
	node(int x):val(x),lc(NULL),rc(NULL){}
};
node* root;
node* buildtree(int prelo,int prehi,int postlo,int posthi){
	if(prelo>=prehi)return NULL;
	node* cur=new node(preorder[prelo]);
	if(prehi-prelo==1)return cur;
	if(preorder[prelo+1]==postorder[posthi-2]){
		flag=1;
		cur->lc=buildtree(prelo+1,prehi,postlo,posthi-1);
	}else{
		int r=prelo;
		while(preorder[r]!=postorder[posthi-2])r++;
		cur->lc=buildtree(prelo+1,r,postlo,postlo+r-1-prelo);
		cur->rc=buildtree(r,prehi,posthi-1-prehi+r,posthi-1);
	}
	return cur;
}
void inTrav(node* cur){
	if(cur==NULL)return;
	inTrav(cur->lc);
	inorder.push_back(cur->val);
	inTrav(cur->rc);
}
int main(){
    //freopen("d:\\input.txt","r",stdin);
	cin>>N;
	_for(i,0,N)cin>>preorder[i];
	_for(i,0,N)cin>>postorder[i];
	flag=0;
	root=buildtree(0,N,0,N);
	if(flag==0)printf("Yes\n");
	else printf("No\n");
	inTrav(root);
	printvec(inorder);
	return 0;
}

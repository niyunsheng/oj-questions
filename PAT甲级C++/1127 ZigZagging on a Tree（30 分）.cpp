/**
 * @Date:   2018-08-31
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-31
 */
#include<iostream>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)

void printvec(vector<int>& vec){
	cout<<vec[0];
	_for(i,1,vec.size())cout<<" "<<vec[i];
	cout<<endl;
}
vector<int> inorder(35),postorder(35),tmp,ans;
struct node{
	int val;
	node *lc,*rc;
	node(int v):val(v),lc(NULL),rc(NULL){}
};
node* buildTree(int inlo,int inhi,int postlo,int posthi){
	if(inlo>=inhi)return NULL;
	node* cur=new node(postorder[posthi-1]);
	int r=inlo;
	while(inorder[r]!=postorder[posthi-1])r++;
	cur->lc=buildTree(inlo,r,postlo,postlo+r-inlo);
	cur->rc=buildTree(r+1,inhi,posthi-inhi+r,posthi-1);
	return cur;
}

int main(){
    //freopen("d:\\input.txt","r",stdin);
	int N;
	cin>>N;
	_for(i,0,N)cin>>inorder[i];
	_for(i,0,N)cin>>postorder[i];
	node* root;
	node* tag=new node(-1);//每一层遍历结束的标志
	root=buildTree(0,N,0,N);
	queue<node*> q;
	q.push(root);q.push(tag);
	bool flag=false;//每一层遍历的标志顺序,false表示逆序
	while(!q.empty()){
		node* cur=q.front();
		q.pop();
		if(cur->val==-1){
			if(!flag)reverse(tmp.begin(),tmp.end());
			_for(i,0,tmp.size())ans.push_back(tmp[i]);
			tmp.clear();
			flag=!flag;
			if(q.empty())break;
			else{
				q.push(tag);
			}
		}else{
			tmp.push_back(cur->val);
			if(cur->lc!=NULL)q.push(cur->lc);
			if(cur->rc!=NULL)q.push(cur->rc);
		}
	}
	printvec(ans);
	return 0;
}

/**
 * @Date:   2018-08-30
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-30
 */
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
struct node{
	int val;
	node *lc,*rc;
	node(int v):val(v),lc(NULL),rc(NULL){}
};
node* root;
void insert(int v){
	node* t=new node(v);
	node* cur=root;
	while(1){
		if(cur->val<v){
			if(cur->rc==NULL){
				cur->rc=t;
				return;
			}else
				cur=cur->rc;
		}else{
			if(cur->lc==NULL){
				cur->lc=t;
				return;
			}else
				cur=cur->lc;
		}
	}
}
int main() {
	//freopen("d:\\input.txt","r",stdin);
	int n,t;
    cin>>n;
	cin>>t;
	root=new node(t);
	_for(i,1,n){
		cin>>t;
		insert(t);
	}
	int sum1=0,sum2=0;
	queue<node*> q;
	node* tag=new node(2018);//每一行结束的标志
	q.push(root);
	q.push(tag);
	node* cur;
	while(!q.empty()){
		cur=q.front();
		q.pop();
		if(cur->val==2018){//行末标志
			if(q.empty())
				break;
			q.push(tag);
			sum1=sum2;
			sum2=0;
		}else{
			sum2++;
			if(cur->lc!=NULL)q.push(cur->lc);
			if(cur->rc!=NULL)q.push(cur->rc);
		}
	}
	printf("%d + %d = %d\n",sum2,sum1,sum1+sum2);
	return 0;
}

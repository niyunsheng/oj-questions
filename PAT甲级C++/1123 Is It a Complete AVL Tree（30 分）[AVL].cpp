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
using namespace std;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
struct node{
	int val,height;
	node *lc,*rc,*p;
	node(int v):val(v),height(0),lc(NULL),rc(NULL),p(NULL){}
};
node* root;
int getheight(node* c){return c==NULL?0:c->height;}
bool is_balanced(node* c){if(abs(getheight(c->lc)-getheight(c->rc))>1)return false;return true;}
void updateheight(node* cur){
	while(cur!=NULL){
		cur->height=max(getheight(cur->lc),getheight(cur->rc))+1;
		cur=cur->p;
	}
}
#define fromPto(cur) (cur->p==NULL?root:\
	cur->p->lc==cur?cur->p->lc:cur->p->rc)
#define tallerChild(cur) (getheight(cur->lc)>getheight(cur->rc)?cur->lc:cur->rc);
node* connect34(node* a,node* b,node* c,node* T1,node* T2,node* T3,node* T4){
	b->lc=a;a->p=b;
	b->rc=c;c->p=b;
	a->lc=T1;if(T1)T1->p=a;
	a->rc=T2;if(T2)T2->p=a;
	c->lc=T3;if(T3)T3->p=c;
	c->rc=T4;if(T4)T4->p=c;
	updateheight(a);
	updateheight(c);
	return b;
}
void rotateAt(node* cur){
	node* father=cur->p;
	fromPto(cur);
	node* p=tallerChild(cur);
	node* son=tallerChild(p);
	if(p==cur->lc){
		if(son==p->lc){
			fromPto(cur)=p;
			p->p=father;
			connect34(son,p,cur,son->lc,son->rc,p->rc,cur->rc);
		}else{
			fromPto(cur)=son;
			son->p=father;
			connect34(p,son,cur,p->lc,son->lc,son->rc,cur->rc);
		}
	}else{
		if(son==p->lc){
			fromPto(cur)=son;
			son->p=father;
			connect34(cur,son,p,cur->lc,son->lc,son->rc,p->rc);
		}else{
			fromPto(cur)=p;
			p->p=father;
			connect34(cur,p,son,cur->lc,p->lc,son->lc,son->rc);
		}
	}
}
void rotate(node* cur){
	while(cur!=NULL&&is_balanced(cur)){
		cur=cur->p;
	}
	if(cur!=NULL){
		rotateAt(cur);
	}

}
void insert(int x){
	//printf("insert %d\n",x);
	if(root==NULL){
		root=new node(x);
		root->height=1;
		return;
	}
	node* cur=root;
	while(1){
		if(cur->val>x){
			if(cur->lc==NULL){
				cur->lc=new node(x);
				cur->lc->p=cur;
				cur=cur->lc;
				break;
			}else{
				cur=cur->lc;
			}
		}else{
			if(cur->rc==NULL){
				cur->rc=new node(x);
				cur->rc->p=cur;
				cur=cur->rc;
				break;
			}else{
				cur=cur->rc;
			}
		}
	}
	updateheight(cur);
	rotate(cur);
}
int getint(){int x;scanf("%d",&x);return x;}
int n;
vector<int> levelorder;
bool levelTrav(){
	queue<node*> q;
	q.push(root);
	int flag=0;
	while(!q.empty()){
		node* cur=q.front();
		q.pop();
		if(cur==NULL){
			if(flag==0){
				if(levelorder.size()==n)
					flag=1;
				else
					flag=2;
			}

			continue;
		}
		levelorder.push_back(cur->val);
		//判断是不是满二叉树，只要让空节点也入队，并且遍历到第一个空节点的时候已经遍历完所有元素
		q.push(cur->lc);
		q.push(cur->rc);
	}
	return flag==1;
}
void printvec(vector<int>& vec){
	cout<<vec[0];
	_for(i,1,vec.size()){
		cout<<" "<<vec[i];
	}
	cout<<endl;
}
int main(){
    //freopen("d:\\input.txt","r",stdin);

	cin>>n;
	_for(i,0,n)
		insert(getint());
	bool flag=levelTrav();
	//cout<<levelorder.size()<<endl;
	printvec(levelorder);
	if(flag)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}

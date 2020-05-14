/**
 * @Date:   2018-09-08
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-08
 */
/*我在考场写的方法：建树
第一步：建树。首先是用中序遍历序列和先序遍历序列建树。（与之前的此类题目不同的话，为了求小公共祖先，应保存下节点高度）
第二步：判断节点不存在的情况。然后是用set存储所有的节点以判断两个节点中有一个或两个不在树中的情况。
第三步：找最小公共祖先。先写findnode函数，找到节点位置，采用DFS递归即可。如果两个节点的高度不一致，先令高度较高的节点上升（因为此前建树的时候维护了父节点），就可以判断某个节点是另一个节点的父节点的情况。如果两个节点高度相同但是不相等，就令两个节点同时降低高度，直至相等。

PS：当然，如果不用set的话，令findnode函数的返回值为空也可以判断。如果时间不够的话，只用set判断节点不存在的情况，不建树也不搜索节点，能过一个算例，得四分（哈哈，总比0分强）
*/
#include<cstdio>
#include<iostream>
#include<set>
using namespace std;

#define MAXN 10005
#define INF 0x7fffffff
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
int preorder[MAXN],inorder[MAXN];
int N,M,K;
struct node{
	int val,height;
	node *lc,*rc,*p;
	node(int v):val(v),height(0),lc(NULL),rc(NULL),p(NULL){}
};
node* root;
node* buildTree(int prelo,int prehi,int inlo,int inhi,int h){
	if(prelo>=prehi)return NULL;
	int tmp=preorder[prelo];
	//cout<<tmp<<endl;
	node* cur=new node(tmp);
	cur->height=h;
	int rank=inlo;
	while(inorder[rank]!=tmp){
		rank++;
	}
	cur->lc=buildTree(prelo+1,prelo+1+rank-inlo,inlo,rank,h+1);
	cur->rc=buildTree(prehi-(inhi-rank-1),prehi,rank+1,inhi,h+1);
	if(cur->lc)cur->lc->p=cur;
	if(cur->rc)cur->rc->p=cur;
	return cur;
}
set<int> sset;

node* findnode(int x,node* cur){
	if(!cur)return NULL;
	if(x==cur->val)return cur;
	node* t1=findnode(x,cur->lc);
	if(t1)return t1;
	node* t2=findnode(x,cur->rc);
	if(t2)return t2;

	return NULL;
}
int main(){
	//freopen("d:\\input.txt","r",stdin);
	cin>>M>>N;
	_for(i,0,N){cin>>inorder[i];sset.insert(inorder[i]);}
	_for(i,0,N)cin>>preorder[i];
	root=buildTree(0,N,0,N,0);
	if(root->lc)root->lc->p=root;
	if(root->rc)root->rc->p=root;
	int c1,c2;
	_for(i,0,M){
		cin>>c1>>c2;
		bool flag1=true,flag2=true;
		if(sset.count(c1)==0)flag1=false;
		if(sset.count(c2)==0)flag2=false;
		if(flag1&&flag2){
			node* t1=findnode(c1,root);
			node* t2=findnode(c2,root);
			while(t1->height>t2->height)t1=t1->p;
			if(t1->val==t2->val){
				printf("%d is an ancestor of %d.\n",c2,c1);
				continue;
			}
			while(t1->height<t2->height)t2=t2->p;
			if(t1->val==t2->val){
				printf("%d is an ancestor of %d.\n",c1,c2);
				continue;
			}
			while(t1->val!=t2->val){
				t1=t1->p;t2=t2->p;
			}
			printf("LCA of %d and %d is %d.\n",c1,c2,t1->val);
		}else if(flag1){
			printf("ERROR: %d is not found.\n",c2);
		}else if(flag2){
			printf("ERROR: %d is not found.\n",c1);
		}else{
			printf("ERROR: %d and %d are not found.\n",c1,c2);
		}
	}
	return 0;
}
//柳神非建树做法：不用建树～已知某个树的根结点，若a和b在根结点的左边，则a和b的最近公共祖先在当前子树根结点的左子树寻找，如果a和b在当前子树根结点的两边，在当前子树的根结点就是a和b的最近公共祖先，如果a和b在当前子树根结点的右边，则a和b的最近公共祖先就在当前子树的右子树寻找。中序加先序可以唯一确定一棵树，在不构建树的情况下，在每一层的递归中，可以得到树的根结点，在此时并入lca算法可以确定两个结点的公共祖先～

#include <iostream>
#include <vector>
#include <map>
using namespace std;
map<int, int> pos;
vector<int> in, pre;
void lca(int inl, int inr, int preRoot, int a, int b) {
    if (inl > inr) return;
    int inRoot = pos[pre[preRoot]], aIn = pos[a], bIn = pos[b];
    if (aIn < inRoot && bIn < inRoot)
        lca(inl, inRoot-1, preRoot+1, a, b);
    else if ((aIn < inRoot && bIn > inRoot) || (aIn > inRoot && bIn < inRoot))
        printf("LCA of %d and %d is %d.\n", a, b, in[inRoot]);
    else if (aIn > inRoot && bIn > inRoot)
        lca(inRoot+1, inr, preRoot+1+(inRoot-inl), a, b);
    else if (aIn == inRoot)
            printf("%d is an ancestor of %d.\n", a, b);
    else if (bIn == inRoot)
            printf("%d is an ancestor of %d.\n", b, a);
}
int main() {
    int m, n, a, b;
    scanf("%d %d", &m, &n);
    in.resize(n + 1), pre.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &in[i]);
        pos[in[i]] = i;
    }
    for (int i = 1; i <= n; i++) scanf("%d", &pre[i]);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &a, &b);
        if (pos[a] == 0 && pos[b] == 0)
            printf("ERROR: %d and %d are not found.\n", a, b);
        else if (pos[a] == 0 || pos[b] == 0)
            printf("ERROR: %d is not found.\n", pos[a] == 0 ? a : b);
        else
            lca(1, n, 1, a, b);
    }
    return 0;
}

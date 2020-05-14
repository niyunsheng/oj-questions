/**
 * @Date:   2018-08-13
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-13
 */
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
//1099 Build A Binary Search Tree (30)
/*思路：
	根据输入内容直接建树，然后用队列实现层次遍历，用数组存储原始数据
	*/

#define _for(i,a,b) for(int i=(a);i<(b);i++)
int getint(){
	int x;scanf("%d",&x);return x;
}
vector<int> levelorder,inorder,nodedata;
vector<int> indata;
vector<int> lc,rc;
int size_N;//输入元素的个数
void printvec(vector<int>& vec){
	printf("%d",vec[0]);
	_for(i,1,vec.size()){
		printf(" %d",vec[i]);
	}
	printf("\n");
}
void inorderTral(int root){
	if(lc[root]!=-1)inorderTral(lc[root]);
	inorder.push_back(root);
	nodedata[root]=inorder.size()-1;
	if(rc[root]!=-1)inorderTral(rc[root]);
}
int main(){
	//freopen("D:\\codeBlockSpace\\input.txt","r",stdin);
	scanf("%d",&size_N);
	indata.resize(size_N);lc.resize(size_N);rc.resize(size_N);nodedata.resize(size_N);
	_for(i,0,size_N){
		lc[i]=getint();
		rc[i]=getint();
	}
	//给出中序遍历的秩的序列
	inorderTral(0);
	_for(i,0,size_N){
		indata[i]=getint();
	}
	//printvec(inorder);
	sort(indata.begin(),indata.end());

	queue<int> q;
	q.push(0);
	int cur;
	while(!q.empty()){
		cur=q.front();q.pop();
		levelorder.push_back(indata[nodedata[cur]]);
		if(lc[cur]!=-1)q.push(lc[cur]);
		if(rc[cur]!=-1)q.push(rc[cur]);
	}
	printvec(levelorder);
	return 0;
}
//9月4日更：
直接中序遍历得到秩的序列，输入元素排序后和中序序列对应起来，即可得到各个节点的值，然后对树进行层次遍历即可
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
void printvec(vector<int>& vec){
	printf("%d",vec[0]);
	_for(i,1,vec.size()){printf(" %d",vec[i]);}
	printf("\n");
}
int getint(){int x;scanf("%d",&x);return x;}
int M,N;
int lc[100],rc[100];
vector<int> inorder;
void DFS(int cur){
	if(lc[cur]!=-1)DFS(lc[cur]);
	inorder.push_back(cur);
	if(rc[cur]!=-1)DFS(rc[cur]);
}

int main(){
	//freopen("D:\\input.txt","r",stdin);
	cin>>N;
	vector<int> data(N),ans(N),levelorder;
	_for(i,0,N){
		cin>>lc[i]>>rc[i];
	}
	_for(i,0,N)cin>>data[i];
	sort(data.begin(),data.end());
	DFS(0);
	_for(i,0,N){
		ans[inorder[i]]=data[i];
	}
	queue<int> q;
	q.push(0);
	while(!q.empty()){
		int cur=q.front();q.pop();
		levelorder.push_back(ans[cur]);
		if(lc[cur]!=-1)q.push(lc[cur]);
		if(rc[cur]!=-1)q.push(rc[cur]);
	}
	printvec(levelorder);
	return 0;
}

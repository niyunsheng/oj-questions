

https://blog.csdn.net/xl2015190026/article/details/51927559
//下面这个代码超时是必然的了，每次找逗号是O(n)
//#include<bits/stdc++.h>//包含全部头文件 POJ不支持
#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>
#include <map>
using namespace std;

#define MAXN 1002
#define PII pair<int,int>
#define mp make_pair
#define pb push_back
#define M 100
#define inf 0x7fffffff
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
typedef long long LL;


map<string,int> msi;
vector<string> int2str;

map<int,int> m;

int _rank;
int ID(const string& s){
	if(msi.count(s)==0){
		msi[s]=_rank;
		int2str.push_back(s);
		return _rank++;
	}else return msi[s];
}

struct node{
	int data,tag;
	node *lc,*rc;
	node(int i,int t=0):data(i),lc(NULL),rc(NULL),tag(t){};
};


node* buildTree(const string& s,int& rank,int lo,int hi){//[lo,hi)
	int p=0,mid=-1;
	int head=lo;
	m[ID(s.substr(lo,hi-lo))]=rank++;
	while(s[lo]!='('&&lo<hi)lo++;

	node* t=new node(ID(s.substr(head,lo-head)));

	if(lo==hi)return t;
	lo++;hi--;
	_for(i,lo,hi){
		switch(s[i]){
			case '(':p++;break;
			case ')':p--;break;
			case ',':if(!p)mid=i;break;
		}
	}
	int r=ID(s.substr(lo,mid-lo));

	if(m.count(r)!=0){
		t->lc=new node(m[r],1);
	}else t->lc=buildTree(s,rank,lo,mid);

	r=ID(s.substr(mid+1,hi-mid-1));
	if(m.count(r)!=0){
		t->rc=new node(m[r],1);
	}else t->rc=buildTree(s,rank,mid+1,hi);
	return t;
}

void printTree(node* root){
	if(!root)return;
	if(root->tag) cout<<root->data;
	else cout<<int2str[root->data];
	if(root->lc){
		cout<<"(";
		printTree(root->lc);
		cout<<",";
		printTree(root->rc);
		cout<<")";
	}
}
int main(){
	//freopen("d:\\input.txt","r",stdin);
	int t;
	cin>>t;
	string s;
	while(t--){
		cin>>s;
		//先构造表达式树，并用集合栈计算机的思想消除重复
		node* root;
		msi.clear();
		m.clear();
		int2str.clear();
		_rank=0;
		int rank=1;
		root=buildTree(s,rank,0,s.size());


		//打印生成的表达式树
		printTree(root);
		cout<<endl;
	}
	return 0;
}

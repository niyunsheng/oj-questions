/**
 * @Date:   2018-09-10
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-10
 */
//最小生成树总结，最好用Kruskal，方法最简单，也不用建图，其次采用Prime，并且要注意到堆优化与Dijkstra的不同，只能用标志数组。不过，用Dijkstra时，最好也是用vis数组进行堆优化过程中的冗余判断。
#include<cstdio>
#include<iostream>
#include<set>
#include<vector>
#include<queue>
#include<map>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

//201412-4 最优灌溉
//156ms，时间没问题，答案错误，只有10分,错误的原因在于prime的堆优化的判断步骤必须得用vis数组标记，不能用dist《现在的dist来判断
const int MAXN=1005;
#define inf 0x7fffffff
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
int getint(){int x;scanf("%d",&x);return x;}
struct node{
	int id,len;
	node(int i,int l):id(i),len(l){}
};

vector<bool> vis(MAXN,false);
vector<int> dist(MAXN,inf);
vector<vector<node> > grid(MAXN);
int N,M,cnt=0;

struct pqnode{
	int id,dis;
	pqnode(int i,int d):id(i),dis(d){}
	bool operator<(const pqnode& b)const{
		return dis>b.dis;
	}
};
void Prime(){
	dist[1]=0;
	priority_queue<pqnode> pq;
	pq.push(pqnode(1,0));
	while(!pq.empty()){
		pqnode tnode=pq.top();pq.pop();
		if(vis[tnode.id])continue;
		cnt+=tnode.dis;
		vis[tnode.id]=true;
		//printf("%d\n",cnt);
		_for(i,0,grid[tnode.id].size()){
			int next=grid[tnode.id][i].id,len=grid[tnode.id][i].len;
			//printf("%d %d\n",next,len);
			if(dist[next]>len){
				dist[next]=len;
				pq.push(pqnode(next,dist[next]));
			}
		}
	}
}
int main(){
	//freopen("d:\\input.txt","r",stdin);
	//freopen("d:\\output.txt","w",stdout);
	cin>>N>>M;
	int c1,c2,t;
	_for(i,0,M){
		scanf("%d %d %d",&c1,&c2,&t);
		grid[c1].push_back(node(c2,t));
		grid[c2].push_back(node(c1,t));
	}
	Prime();
	printf("%d\n",cnt);
	return 0;
}


//201412-4 	最优灌溉
//Krustra最小生成树
#define MAXN 1005
#define inf 0x7fffffff
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
int getint(){int x;scanf("%d",&x);return x;}
vector<vector<int> > grid(MAXN,vector<int>(MAXN,0));
vector<vector<bool> > vis(MAXN,vector<bool>(MAXN,false));
//bool vis[MAXN][MAXN]={0};
int N,M,K,D,custom=0;
struct node{
	int c1,c2,v;
	node(int cc1,int cc2,int vv):c1(cc1),c2(cc2),v(vv){}
	bool operator<(const node& b)const{return v<b.v;}
};
int fa[MAXN];
vector<node> vec;
int findroot(int x){
	return fa[x]==0?x:fa[x]=findroot(fa[x]);
}
int main(){
	//freopen("d:\\input.txt","r",stdin);
	cin>>N>>M;
	int c1,c2,v;
	memset(fa,0,sizeof(fa));
	_for(i,0,M){
		cin>>c1>>c2>>v;
		vec.push_back(node(c1,c2,v));
	}
	sort(vec.begin(),vec.end());
	int sum=0;
	_for(i,0,M){
		c1=vec[i].c1,c2=vec[i].c2,v=vec[i].v;
		int f1=findroot(c1),f2=findroot(c2);
		if(f1!=f2){
			sum+=v;
			fa[f1]=f2;
		}
	}
	printf("%d\n",sum);
	return 0;
}

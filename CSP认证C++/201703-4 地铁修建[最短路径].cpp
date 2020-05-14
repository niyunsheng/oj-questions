/**
 * @Date:   2018-09-13
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-13
 */
//201703-4 地铁修建
//方法一：DFS剪枝，超时，只有20分
//方法二：Dijkstra
//方法三：最下生成树
#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<set>
#include<map>
#include<stack>
#include<sstream>
#include<vector>
#include<queue>
using namespace std;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
const int MAXN=100005;
const int inf=0x3f3f3f3f;
struct node{
	int id,len;
	node(int i,int l):id(i),len(l){}
};
vector<node> grid[MAXN];
vector<bool> vis(MAXN);//防止环路
int minday=inf;
int M,N;
//方法一：DFS剪枝，超时，只有20分
void DFS(int c,int tmpday){
	//printf("%d %d\n",c,tmpday);
	if(c==N){
		minday=min(tmpday,minday);
		return;
	}
	_for(i,0,grid[c].size()){
		int id=grid[c][i].id,len=grid[c][i].len;
		//printf("nx: %d %d\n",id,len);
		if(!vis[id]){
			vis[id]=true;
			if(max(tmpday,len)<minday)
				DFS(id,max(tmpday,len));
			vis[id]=false;
		}
	}
}
int main(){
	//freopen("d:\\input.txt","r",stdin);
	cin>>N>>M;
	int c1,c2,t;
	_for(i,0,M){
		scanf("%d %d %d",&c1,&c2,&t);
		grid[c1].push_back(node(c2,t));
		grid[c2].push_back(node(c1,t));
	}
	vis[1]=true;
	//DFS(1,0);
	cout<<minday<<endl;
	return 0;
}
//方法二：Dijkstra，只需要将dist数组的值改为该路径上的最长节点距离即可，不得不说，得把思路理清楚了，否则很容易出错，而且没有数据的话，很难检查出来。出队列时相当于确定了到达该节点的路程上的线段最大值，每个节点入队时的距离是当前节点的路程上的最大值和下个节点的距离两者的较大者
int N,M;

struct edge{
	int id,len;
	edge(int i,int l):id(i),len(l){}
	bool operator<(const edge& b)const{return len>b.len;}
};
vector<int> dist(MAXN,0);
vector<bool> vis(MAXN,false);
vector<edge> G[MAXN];

int main(){
	//freopen("d:\\input.txt","r",stdin);
	//freopen("d:\\output.txt","w",stdout);
	cin>>N>>M;

	int a,b,c;
	_for(i,0,M){
		cin>>a>>b>>c;
		G[a].push_back(edge(b,c));
		G[b].push_back(edge(a,c));
	}
	priority_queue<edge> pq;
	pq.push(edge(1,0));
	while(!pq.empty()){
		edge e=pq.top();pq.pop();
		int nc=e.id;

		if(vis[nc])continue;
		//printf("%d %d\n",e.id,e.len);
		vis[nc]=true;dist[nc]=e.len;
		if(nc==N)break;
		_for(i,0,G[nc].size()){
			int nx=G[nc][i].id,len=G[nc][i].len;
			if(vis[nx])continue;
			pq.push(edge(nx,max(len,dist[nc])));
		}
	}

	cout<<dist[N]<<endl;
	return 0;
}

//方法三：kruskal
int N,M;
struct edge{
	int from,to,len;
	edge(int f,int t,int l):from(f),to(t),len(l){}
	bool operator<(const edge& b)const{return len<b.len;}
};
vector<int> fa(MAXN,0);
vector<edge> E;
int findroot(int x){
	return fa[x]==0?x:fa[x]=findroot(fa[x]);
}
int main(){
	//freopen("d:\\input.txt","r",stdin);
	//freopen("d:\\output.txt","w",stdout);
	cin>>N>>M;

	int a,b,c;
	_for(i,0,M){
		cin>>a>>b>>c;
		E.push_back(edge(a,b,c));
	}
	sort(E.begin(),E.end());
	//_for(i,0,M)printf("%d ",E[i].len);
	int minans;
	_for(i,0,M){
		//_for(i,1,N)printf("%d ",findroot(i));printf("\n");
		int c1=E[i].from,c2=E[i].to;
		int f1=findroot(c1),f2=findroot(c2);
		//printf("%d %d\n",f1,f2);
		if(f1!=f2)fa[f1]=f2;
		else continue;
		if(findroot(1)==findroot(N)){
			minans=E[i].len;
			break;
		}
	}
	cout<<minans<<endl;
	return 0;
}

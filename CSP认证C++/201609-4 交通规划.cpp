/**
 * @Date:   2018-09-10
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-10
 */
#include<cstdio>
#include<iostream>
#include<set>
#include<vector>
#include<map>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

//201609-4 交通规划
//没有AC，超时，80分
#define MAXN 10005
#define inf 0x7fffffff
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
int getint(){int x;scanf("%d",&x);return x;}
int N,M,cnt=0;
struct node{
	int id,len;
	node(int i,int l):id(i),len(l){}
};
vector<vector<node> > grid(MAXN);
vector<int> path(MAXN,-1);
vector<int> dist(MAXN,inf);
vector<int> prelen(MAXN);//i节点到达path[i]节点的线路长度
vector<bool> vis(MAXN,false);
void Dijkstra(){
	while(1){
		int minid=-1,mindist=inf;
		_for(i,1,N+1){
			if(!vis[i]&&dist[i]<mindist){
				minid=i;mindist=dist[i];
			}
		}
		//printf("minid=%d\n",minid);
		if(minid==-1)break;

		vis[minid]=true;
		cnt+=prelen[minid];
		_for(i,0,grid[minid].size()){
			int next=grid[minid][i].id,len=grid[minid][i].len;
			if(!vis[next]){
				if(dist[next]>dist[minid]+len){
					dist[next]=dist[minid]+len;
					path[next]=minid;
					prelen[next]=len;
				}else if(dist[next]==dist[minid]+len){
					if(prelen[next]>len){
						path[next]=minid;
						prelen[next]=len;
					}
				}
			}
		}
	}
}
int main(){
	//freopen("d:\\input.txt","r",stdin);
	cin>>N>>M;
	int c1,c2,len;
	_for(i,0,M){
		scanf("%d %d %d",&c1,&c2,&len);
		grid[c1].push_back(node(c2,len));
		grid[c2].push_back(node(c1,len));
	}
	dist[1]=0;prelen[0]=0;
	Dijkstra();
	printf("%d\n",cnt);
	return 0;
}

//采用堆优化之后就顺利通过了，一定要注意堆优化的写法，要多联系
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

//201609-4 交通规划
//加入堆优化，满分
#define MAXN 10005
#define inf 0x7fffffff
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
int getint(){int x;scanf("%d",&x);return x;}
int N,M,cnt=0;
struct node{
	int id,len;
	node(int i,int l):id(i),len(l){}
};
vector<node> grid[MAXN];
vector<int> path(MAXN,-1);
vector<int> dist(MAXN,inf);
vector<int> prelen(MAXN);//i节点到达path[i]节点的线路长度
vector<bool> vis(MAXN,false);
struct pqnode{
	int id,dist;
	pqnode(int i,int d):id(i),dist(d){}
	bool operator<(const pqnode& b)const{
		return dist>b.dist;
	}
};
priority_queue<pqnode> pq;
void Dijkstra(){
	while(!pq.empty()){
		pqnode minnode=pq.top();
		pq.pop();
		if(dist[minnode.id]<minnode.dist)continue;
		cnt+=prelen[minnode.id];
		_for(i,0,grid[minnode.id].size()){
			int next=grid[minnode.id][i].id,len=grid[minnode.id][i].len;
			if(!vis[next]){
				if(dist[next]>dist[minnode.id]+len){
					dist[next]=dist[minnode.id]+len;
					path[next]=minnode.id;
					prelen[next]=len;
					pq.push(pqnode(next,dist[next]));
				}else if(dist[next]==dist[minnode.id]+len){
					if(prelen[next]>len){
						path[next]=minnode.id;
						prelen[next]=len;
					}
				}
			}
		}
	}
}
int main(){
	//freopen("d:\\input.txt","r",stdin);
	cin>>N>>M;
	int c1,c2,len;
	_for(i,0,M){
		scanf("%d %d %d",&c1,&c2,&len);
		grid[c1].push_back(node(c2,len));
		grid[c2].push_back(node(c1,len));
	}
	dist[1]=0;prelen[0]=0;
	//_for(i,1,N+1)pq.push(i);
	pq.push(pqnode(1,0));
	Dijkstra();
	printf("%d\n",cnt);
	return 0;
}
//堆优化简洁版
//201703-4 地铁修建
const int MAXN=10005;
#define inf 0x7fffffff
typedef long long LL;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
int N,M;

struct edge{
	int id,len;
	edge(int i,int l):id(i),len(l){}
	bool operator<(const edge& b)const{return len>b.len;}
};
vector<int> dist(MAXN,inf);
vector<int> w(MAXN,inf);
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
	int cnt=0;
	priority_queue<edge> pq;
	pq.push(edge(1,0));
	dist[1]=0;w[1]=0;
	while(!pq.empty()){
		edge e=pq.top();pq.pop();
		int nc=e.id;
		if(vis[nc])continue;
		//printf("%d %d\n",e.id,e.len);
		vis[nc]=true;
		cnt+=w[nc];
		_for(i,0,G[nc].size()){
			int nx=G[nc][i].id,len=G[nc][i].len;
			if(vis[nx])continue;
			if(dist[nx]>dist[nc]+len){
				w[nx]=len;
				dist[nx]=dist[nc]+len;
				pq.push(edge(nx,dist[nx]));//居然粗心到把这里nx写成nc
			}else if(dist[nx]==dist[nc]+len){
				if(w[nx]>len)w[nx]=len;
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}

/**
 * @Date:   2018-09-14
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-14
 */
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

//201712-4 行车路线
//没考虑小路连续的情况，得70足矣
const int MAXN=505;
#define inf 0x7fffffff
typedef long long LL;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
int N,M;

struct edge{
	int id,len,type;
	edge(int a,int b,int c):id(a),len(b),type(c){}
};
vector<edge> G[MAXN];
vector<int> dist(MAXN,inf);
vector<bool> vis(MAXN,false);
struct node{
	int id,dist;
	node(int a,int b):id(a),dist(b){}
	bool operator<(const node& b)const{
		return dist>b.dist;
	}
};
vector<edge> tmp;
int minans=inf;
int fun(vector<edge>& tmp){
	vector<int> t;
	int lo=0,hi;
	while(lo<tmp.size()){
		int cnt=0,hi=lo;
		while(tmp[hi].type==tmp[lo].type){
			cnt+=tmp[hi].len;hi++;
		}
		if(tmp[lo].type==1)t.push_back(-cnt);
		else t.push_back(cnt);
		lo=hi;
	}
	int cnt=0;
	_for(i,0,t.size()){
		if(t[i]<0)t[i]*=t[i];
		cnt+=t[i];
	}
	return cnt;
}
void DFS(int nc){
	if(nc==N){
		minans=min(minans,fun(tmp));
		return;
	}
	vis[nc]=true;
	_for(i,0,G[nc].size()){
		int nx=G[nc][i].id,len=G[nc][i].len,type=G[nc][i].type;
		if(vis[nx])continue;
		tmp.push_back(G[nc][i]);
		DFS(nx);
		tmp.pop_back();
	}
	vis[nc]=false;
}
int main(){
	//freopen("d:\\input.txt","r",stdin);
	//freopen("d:\\output.txt","w",stdout);
	cin>>N>>M;
	int t,a,b,c;
	_for(i,0,M){
		cin>>t>>a>>b>>c;
		G[b].push_back(edge(a,c,t));
		G[a].push_back(edge(b,c,t));
	}
	if(N<50){
		DFS(1);
		cout<<minans<<endl;
	}else{
		dist[1]=0;
		priority_queue<node> pq;
		pq.push(node(1,0));
		while(!pq.empty()){
			node nc=pq.top();pq.pop();
			if(vis[nc.id])continue;
			vis[nc.id]=true;
			if(vis[N])break;
			_for(i,0,G[nc.id].size()){
				int nx=G[nc.id][i].id,len=G[nc.id][i].len,type=G[nc.id][i].type;
				if(vis[nx])continue;
				if(type)len*=len;
				if(dist[nx]>dist[nc.id]+len){
					dist[nx]=dist[nc.id]+len;
					pq.push(node(nx,dist[nx]));
				}
			}
		}
		cout<<dist[N]<<endl;
	}
	return 0;
}

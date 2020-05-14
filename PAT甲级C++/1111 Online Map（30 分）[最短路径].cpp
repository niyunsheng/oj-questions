//两次Dijkstra即可，题目非常简单，是标准的只有第二边权的问题，设置一个第二边权的数组即可。
//相比较1087 all road to rome,在第二边权的基础上还有第三边权，这个题目是十分easy的，根本用不着DFS，用了反而麻烦
//1111online map
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
#define MAXN 505
#define INF 0x7fffffff
int N,M;
struct node{
	int id,len,tim;
	node(int i,int l,int t):id(i),len(l),tim(t){}
};
vector<vector<node> > grid(MAXN);
//最短路径相关数组，最短距离，w1第二权值是时间，path1是路径
vector<int> dist(MAXN,INF),w1(MAXN,INF),path1(MAXN,-1);
vector<bool> vis1(MAXN,false);
//最近路径相关数组,最短时间，w2第二权值经过的中间节点数，path2是路径
vector<int>	_time(MAXN,INF),w2(MAXN,INF),path2(MAXN,-1);
vector<bool> vis2(MAXN,false);

void Dijkstra1(int s){
	while(1){
		int minid=-1,mindist=INF;
		_for(i,0,N){
			if(!vis1[i]&&dist[i]<mindist){
				minid=i;mindist=dist[i];
			}
		}
		if(minid==-1)break;
		vis1[minid]=true;
		_for(i,0,grid[minid].size()){
			int next=grid[minid][i].id,len=grid[minid][i].len,tim=grid[minid][i].tim;
			if(vis1[next])continue;
			if(dist[next]>dist[minid]+len){
				dist[next]=dist[minid]+len;
				path1[next]=minid;
				w1[next]=w1[minid]+tim;
			}else if(dist[next]==dist[minid]+len&&w1[next]>w1[minid]+tim){
				path1[next]=minid;
				w1[next]=w1[minid]+tim;
			}
		}
	}
}
void Dijkstra2(int s){
	while(1){
		int minid=-1,mintime=INF;
		_for(i,0,N){
			if(!vis2[i]&&_time[i]<mintime){
				minid=i;mintime=_time[i];
			}
		}
		if(minid==-1)break;
		vis2[minid]=true;
		_for(i,0,grid[minid].size()){
			int next=grid[minid][i].id,len=grid[minid][i].len,tim=grid[minid][i].tim;
			if(vis2[next])continue;
			if(_time[next]>_time[minid]+tim){
				_time[next]=_time[minid]+tim;
				path2[next]=minid;
				w2[next]=w2[minid]+1;
			}else if(_time[next]==_time[minid]+tim&&w2[next]>w2[minid]+1){
				path2[next]=minid;
				w2[next]=w2[minid]+1;
			}
		}
	}
}
void path2vec(vector<int>& path,vector<int>& vec,int d){
	while(path[d]!=-1){
		vec.push_back(d);
		d=path[d];
	}
}
bool is_equal(vector<int>& vec1,vector<int>& vec2){
	if(vec1.size()!=vec2.size())return false;
	_for(i,0,vec1.size())
		if(vec1[i]!=vec2[i])return false;
	return true;
}
void printpath(vector<int>& path,int d){
	stack<int> tmp;
	while(path[d]!=-1){
		tmp.push(d);
		d=path[d];
	}
	while(!tmp.empty()){
		int x=tmp.top();
		tmp.pop();
		printf(" -> %d",x);
	}
	printf("\n");
}

int main() {
	//freopen("d:\\input.txt","r",stdin);
    cin>>N>>M;
	int c1,c2,t,len,tim;
	_for(i,0,M){
		scanf("%d %d %d %d %d",&c1,&c2,&t,&len,&tim);
		grid[c1].push_back(node(c2,len,tim));
		if(t!=1)
			grid[c2].push_back(node(c1,len,tim));
	}
	int s,d;
	cin>>s>>d;
	dist[s]=0;w1[s]=0;
	Dijkstra1(s);//最短路径
	//printf("Distance = %d: %d",dist[d],s);printpath(path1,d);
	_time[s]=0;w2[s]=0;
	Dijkstra2(s);//最快路径
	//printf("Time = %d: %d",time[d],s);printpath(path2,d);
	vector<int> vec1,vec2;
	path2vec(path1,vec1,d);
	path2vec(path2,vec2,d);
	if(is_equal(vec1,vec2)){
		printf("Distance = %d; Time = %d: %d",dist[d],_time[d],s);
		printpath(path1,d);
	}else{
		printf("Distance = %d: %d",dist[d],s);printpath(path1,d);
		printf("Time = %d: %d",_time[d],s);printpath(path2,d);
	}
	return 0;
}

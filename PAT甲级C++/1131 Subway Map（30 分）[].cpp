/**
 * @Date:   2018-08-31
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-02
 */
//三个算例没过
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
void printvec(vector<int>& vec){
	cout<<vec[0];
	for(int i=1;i<vec.size();i++)
		printf(" %d",vec[i]);
	printf("\n");
}


#define MAXN 10005
#define INF 0x7fffffff
vector<vector<int> > grid(MAXN);
map<pair<int,int>,int> line;//每段路线对应的线路号
vector<int> dist(MAXN);
vector<bool> vis(MAXN);
vector<vector<int> > path(MAXN);
int stopSize;
set<int> stop_set;//节点的标记
vector<int> stop_vec;
void Dijkstra(){
	while(1){
		int minid=-1,mindist=INF;
		for(int i=0;i<stopSize;i++){
			if(!vis[stop_vec[i]]&&dist[stop_vec[i]]<mindist){
				minid=stop_vec[i];mindist=dist[stop_vec[i]];
			}
		}
		if(minid==-1)break;
		vis[minid]=true;
		for(int i=0;i<grid[minid].size();i++){
			int next=grid[minid][i];
			if(!vis[next]){
				if(dist[next]>dist[minid]+1){
					dist[next]=dist[minid]+1;
					path[next].clear();
					path[next].push_back(minid);
				}else if(dist[next]==dist[minid]+1){
					path[next].push_back(minid);
				}
			}
		}
	}
}
int trans_size(vector<int>& path){
	int cnt=0;
	for(int i=0;i<path.size()-2;i++){
		if(line[make_pair(path[i],path[i+1])]!=line[make_pair(path[i+1],path[i+2])])
			cnt++;
	}
	return cnt;
}
int min_trans;
vector<int> min_path,tmp_path;
void DFS(int c){
	if(path[c][0]==-1){
		int cnt=trans_size(tmp_path);
		if(cnt<min_trans){
			min_trans=cnt;
			min_path=tmp_path;
		}
		return;
	}
	for(int i=0;i<path[c].size();i++){
		int next=path[c][i];

		tmp_path.push_back(next);
		DFS(next);
		tmp_path.pop_back();

	}
}
int main(){
	freopen("D:\\input.txt","r",stdin);
	int N,m,K;
	int tmp[105];
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>m;
		for(int j=0;j<m;j++){
			scanf("%d",&tmp[j]);
			stop_set.insert(tmp[j]);
		}
		for(int j=0;j<m-1;j++){
			line[make_pair(tmp[j],tmp[j+1])]=i;
			line[make_pair(tmp[j+1],tmp[j])]=i;
			grid[tmp[j]].push_back(tmp[j+1]);
			grid[tmp[j+1]].push_back(tmp[j]);
		}
	}
	for(set<int>::iterator it=stop_set.begin();it!=stop_set.end();it++)
		stop_vec.push_back(*it);
	stopSize=stop_vec.size();
	scanf("%d",&K);
	int c1,c2;
	for(int i=0;i<K;i++){
		scanf("%d %d",&c1,&c2);
		fill(dist.begin(),dist.end(),INF);
		fill(vis.begin(),vis.end(),false);
		fill(path.begin(),path.end(),vector<int>(1,-1));
		dist[c1]=0;
		//Dijkstra最短路径，DFS找换成最少线路
		Dijkstra();
		//for(int i=0;i<stopSize;i++)printf("%d %d\n",stop_vec[i],dist[stop_vec[i]]);
		min_trans=INF;
		tmp_path.clear();
		tmp_path.push_back(c2);
		DFS(c2);
		//printvec(min_path);
		int cnt=min_path.size();
		printf("%d\n",cnt-1);
		int lastline=line[make_pair(min_path[cnt-2],min_path[cnt-1])],laststop=c1;
		for(int j=cnt-2;j>=0;j--){
			int curline=line[make_pair(min_path[j],min_path[j+1])];
			if(curline!=lastline){
				printf("Take Line#%d from %d to %d.\n",lastline,laststop,min_path[j+1]);
				lastline=curline;
				laststop=min_path[j+1];
			}
		}
		printf("Take Line#%d from %d to %d.\n",lastline,laststop,c2);
	}

	return 0;
}

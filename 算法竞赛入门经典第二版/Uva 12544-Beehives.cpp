//无向图最小环，用Floyd会TLE，用BFS并剪枝
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

#define MAXN 505
#define inf 0x7fffffff
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)

int main(){
	//freopen("d:\\input.txt","r",stdin);
	int T,n,m,u,v;
	cin>>T;
	_for(ii,1,T+1){
		scanf("%d %d",&n,&m);
		vector<int> grid[505];
		_for(i,0,m){
			scanf("%d %d",&u,&v);
			grid[u].push_back(v);
			grid[v].push_back(u);
		}
		int minnode=inf;
		_for(i,0,n){
			vector<bool> vis(n,false);
			int level[505]={0};
			vis[i]=true;
			queue<int> q;
			q.push(i);
			int minlevel=-1;
			while(!q.empty()){
				int r=q.front();q.pop();
				if(minlevel!=-1&&level[r]!=minlevel){goto loop;}
				_for(j,0,grid[r].size()){
					int nx=grid[r][j];
					if(!vis[nx]){
						level[nx]=level[r]+1;
						vis[nx]=true;
						q.push(nx);
					}else{
						if(level[nx]<level[r])continue;
						else if(level[nx]==level[r]){
							minnode=min(minnode,level[nx]*2+1);
							goto loop;
						}else{
							minnode=min(minnode,level[nx]+level[r]+1);
							minlevel=level[r];
						}
					}
				}
			}
			loop:;
			if(minnode==inf)break;
		}
		if(minnode==inf)printf("Case %d: impossible\n",ii);
		else printf("Case %d: %d\n",ii,minnode);
	}
	return 0;
}

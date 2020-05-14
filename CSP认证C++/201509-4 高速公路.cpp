/**
 * @Date:   2018-09-10
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-10
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

//201509-4 高速公路
//运行超时，60分
#define MAXN 10005
#define inf 0x7fffffff
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
int getint(){int x;scanf("%d",&x);return x;}
vector<vector<bool> > vis(MAXN,vector<bool>(MAXN,false));
vector<vector<int> > grid(MAXN);
int N,M;

int main(){
	//freopen("d:\\input.txt","r",stdin);
	//freopen("d:\\output.txt","w",stdout);
	cin>>N>>M;
	int c1,c2;
	_for(i,0,M){
		scanf("%d %d",&c1,&c2);
		grid[c1].push_back(c2);
	}
	_for(i,1,N+1){
		queue<int> q;
		q.push(i);
		while(!q.empty()){
			int cur=q.front();q.pop();
			_for(j,0,grid[cur].size()){
				int nx=grid[cur][j];
				if(!vis[i][nx]){
					vis[i][nx]=true;
					q.push(nx);
					//printf("%d\n",nx);
				}
			}
		}
	}
	int cnt=0;
	_for(i,1,N+1){
		_for(j,i+1,N+1){
			if(vis[i][j]&&vis[j][i])cnt++;
		}
	}
	printf("%d",cnt);
	return 0;
}

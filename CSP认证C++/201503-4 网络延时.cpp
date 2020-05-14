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

//201503-4 网络延时
//两次DFS即可，找到最深节点。终于碰到一个一次AC的题目了，可惜是PAT做过的原题
const int MAXN=20005;//1-10000表示交换机，10001-20000表示电脑
#define inf 0x7fffffff
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
int getint(){int x;scanf("%d",&x);return x;}
vector<bool> vis(MAXN);
vector<vector<int> > grid(MAXN);
int N,M,maxlevel,maxid;
void DFS(int cur,int H){
	if(H>maxlevel){
		maxlevel=H;maxid=cur;
	}
	_for(i,0,grid[cur].size()){
		int next=grid[cur][i];
		if(!vis[next]){
			vis[next]=true;
			DFS(next,H+1);
		}

	}
}
int main(){
	//freopen("d:\\input.txt","r",stdin);
	//freopen("d:\\output.txt","w",stdout);
	cin>>N>>M;
	int c1,c2;
	_for(i,2,N+1){
		scanf("%d",&c1);
		grid[c1].push_back(i);
		grid[i].push_back(c1);
	}
	_for(i,1,M+1){
		scanf("%d",&c1);
		grid[c1].push_back(i+10000);
		grid[i+10000].push_back(c1);
	}
	fill(vis.begin(),vis.end(),false);
	vis[1]=true;
	maxlevel=0;
	DFS(1,0);
	fill(vis.begin(),vis.end(),false);
	vis[maxid]=true;
	maxlevel=0;
	DFS(maxid,0);
	printf("%d",maxlevel);
	return 0;
}

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

//201512-4 送货
//欧拉路径充要条件：连通图，且只有出发点和终点的读数为奇数
//暴力法，运行超时，只有20分
const int MAXN=10005;
#define inf 0x7fffffff
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
vector<int> grid[MAXN];
int M,N,Q;
bool vis[MAXN][MAXN];
int degree[MAXN];
int fa[MAXN];
int findroot(int x){
	return fa[x]==0?x:fa[x]=findroot(fa[x]);
}
void combine(int x,int y){
	int fx=findroot(x),fy=findroot(y);
	if(fx!=fy)fa[fx]=fy;
}
int main(){
	//freopen("d:\\input.txt","r",stdin);
	//freopen("d:\\output.txt","w",stdout);
	memset(vis,0,sizeof(vis));
	memset(degree,0,sizeof(degree));
	memset(fa,0,sizeof(fa));
	cin>>N>>M;
	int c1,c2;
	_for(i,0,M){
		scanf("%d %d",&c1,&c2);
		grid[c1].push_back(c2);
		grid[c2].push_back(c1);
		degree[c1]++;
		degree[c2]++;
		combine(c1,c2);
	}
	int cnt=0,cnt2=0;//cnt2表示连通域个数
	if(fa[1]==0)cnt2++;
	_for(i,2,N+1){
		if(degree[i]%2)cnt++;
		if(fa[i]==0)cnt2++;
	}
	bool flag=true;
	if(degree[1]%2==1){
		if(cnt!=1)flag=false;
	}else{
		if(cnt!=0)flag=false;
	}
	if(cnt2>1)flag=false;

	if(!flag){
		printf("-1\n");return 0;
	}
	_for(i,1,N+1){
		sort(grid[i].begin(),grid[i].end());
	}
	cnt=0;//记录经过的道路的数目，达到M时退出循环
	int cur=1;//当前所在顶点
	printf("1");
	while(1){
		//printf("cur=%d\n",cur);
		_for(i,0,grid[cur].size()){
			int nx=grid[cur][i];
			if(!vis[cur][nx]){
				vis[nx][cur]=true;
				vis[cur][nx]=true;
				printf(" %d",nx);
				cur=nx;
				cnt++;
				if(cnt==M)break;
				break;
			}
		}
		if(cnt==M)break;
	}
	printf("\n");
	return 0;
}
//将grid改为set依然超时，还是20分

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

//201512-4 送货
//欧拉路径充要条件：连通图，且只有出发点和终点的读数为奇数
//暴力法，运行超时，只有20分
const int MAXN=10005;
#define inf 0x7fffffff
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
set<int> grid[MAXN];
int M,N,Q;
bool vis[MAXN][MAXN];
int fa[MAXN];
int findroot(int x){
	return fa[x]==0?x:fa[x]=findroot(fa[x]);
}
void combine(int x,int y){
	int fx=findroot(x),fy=findroot(y);
	if(fx!=fy)fa[fx]=fy;
}
int main(){
	//freopen("d:\\input.txt","r",stdin);
	//freopen("d:\\output.txt","w",stdout);
	//memset(vis,0,sizeof(vis));
	//memset(degree,0,sizeof(degree));
	memset(fa,0,sizeof(fa));
	cin>>N>>M;
	int c1,c2;
	_for(i,0,M){
		scanf("%d %d",&c1,&c2);
		grid[c1].insert(c2);
		grid[c2].insert(c1);
		combine(c1,c2);
	}
	int cnt=0,cnt2=0;//cnt2表示连通域个数
	if(fa[1]==0)cnt2++;
	_for(i,2,N+1){
		if(grid[i].size()%2)cnt++;
		if(fa[i]==0)cnt2++;
	}
	bool flag=true;
	if(grid[1].size()%2==1){
		if(cnt!=1)flag=false;
	}else{
		if(cnt!=0)flag=false;
	}
	if(cnt2>1)flag=false;

	if(!flag){
		printf("-1\n");return 0;
	}
	//_for(i,1,N+1){		sort(grid[i].begin(),grid[i].end());	}
	cnt=0;//记录经过的道路的数目，达到M时退出循环
	int cur=1;//当前所在顶点
	printf("1");
	while(1){
		//printf("cur=%d\n",cur);
		for(set<int>::iterator it=grid[cur].begin();it!=grid[cur].end();it++){
			int nx=*it;
			if(!vis[cur][nx]){
				vis[nx][cur]=true;
				vis[cur][nx]=true;
				printf(" %d",nx);
				cur=nx;
				cnt++;
				if(cnt==M)break;
				break;
			}
		}
		if(cnt==M)break;
	}
	printf("\n");
	return 0;
}

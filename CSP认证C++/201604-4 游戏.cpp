/**
 * @Date:   2018-09-15
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-15
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

//201604-4 游戏
//感觉BFS的话时间太长，因为没有标记，还可以回到走过的地方
//用DFS优先向右向下搜索，不行的话再向左向上
//意料之中的超时了，只有20分
const int MAXN=105;
#define inf 0x7fffffff
typedef long long LL;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)

int N,M,t;

struct node{
	int t1,t2;
	node(int tt1=inf,int tt2=inf):t1(tt1),t2(tt2){}
	//判断节点是否有毒时先判断当前时间大于等于t1，满足条件再判断小于等于t2
};
node G[MAXN][MAXN];
int _x[4]={1,0,-1,0},_y[4]={0,1,0,-1};
bool is_legal(int y,int x,int step){
	return x>=1&&x<=M&&y>=1&&y<=N&&(step<G[y][x].t1||step>G[y][x].t2);
}
//能不能保证这样DFS得到的是最短路径呢？保证不了的话就尴尬了，测试保证不了，只能用step来剪枝了
bool flag;//true表示已经到达终点，终止DFS
int minstep=inf;
void DFS(int y,int x,int step){
	if(step>minstep)return;
	if(y==N&&x==M){
		flag=true;
		minstep=min(step,minstep);
		return;
	}
	_for(i,0,4){
		int nx=x+_x[i],ny=y+_y[i];
		if(is_legal(ny,nx,step+1))
			DFS(ny,nx,step+1);
	}
}
int main(){
	//freopen("d:\\input.txt","r",stdin);
	//freopen("d:\\output.txt","w",stdout);
	cin>>N>>M>>t;
	int r,c,a,b;
	_for(i,0,t){
		scanf("%d %d %d %d",&r,&c,&a,&b);
		G[r][c].t1=a;
		G[r][c].t2=b;
	}
	flag=false;
	DFS(1,1,0);
	cout<<minstep<<endl;
	return 0;
}

//201604-4 游戏
//第二版，改用BFS
//依旧超时，20分
const int MAXN=105;
#define inf 0x7fffffff
typedef long long LL;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)

int N,M,t;

struct node{
	int t1,t2;
	node(int tt1=inf,int tt2=inf):t1(tt1),t2(tt2){}
	//判断节点是否有毒时先判断当前时间大于等于t1，满足条件再判断小于等于t2
};
node G[MAXN][MAXN];
int _x[4]={1,0,-1,0},_y[4]={0,1,0,-1};
bool is_legal(int y,int x,int step){
	return x>=1&&x<=M&&y>=1&&y<=N&&(step<G[y][x].t1||step>G[y][x].t2);
}
struct point{
	int y,x;
	point(int yy,int xx):y(yy),x(xx){}
};
int minstep=inf;
void BFS(){
	int step=0;
	queue<point> q;
	point tag(0,0);
	q.push(point(1,1));
	q.push(tag);
	while(1){

		point t=q.front();q.pop();
		int y=t.y,x=t.x;
		//printf("y=%d x=%d step=%d\n",y,x,step);
		if(y==0){step++;q.push(tag);continue;}
		if(y==N&&x==M)break;
		_for(i,0,4){
			int nx=x+_x[i],ny=y+_y[i];
			if(is_legal(ny,nx,step+1))
				q.push(point(ny,nx));
		}
	}
	minstep=step;
}
int main(){
	//freopen("d:\\input.txt","r",stdin);
	//freopen("d:\\output.txt","w",stdout);
	cin>>N>>M>>t;
	int r,c,a,b;
	_for(i,0,t){
		scanf("%d %d %d %d",&r,&c,&a,&b);
		G[r][c].t1=a;
		G[r][c].t2=b;
	}
	BFS();
	cout<<minstep<<endl;
	return 0;
}

//201604-4 游戏
//BFS海岛博主三位优化，设置访问向量的第三维step，防止在同一步到达同一顶点
//依旧超时，20分
const int MAXN=105;
#define inf 0x7fffffff
typedef long long LL;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)

int N,M,t;

struct node{
	int t1,t2;
	node(int tt1=inf,int tt2=inf):t1(tt1),t2(tt2){}
	//判断节点是否有毒时先判断当前时间大于等于t1，满足条件再判断小于等于t2
};
bool vis[MAXN][MAXN][305];
node G[MAXN][MAXN];
int _x[4]={1,0,-1,0},_y[4]={0,1,0,-1};
bool is_legal(int y,int x,int step){
	return x>=1&&x<=M&&y>=1&&y<=N&&(step<G[y][x].t1||step>G[y][x].t2);
}
struct point{
	int y,x;
	point(int yy,int xx):y(yy),x(xx){}
};
int minstep=inf;
void BFS(){
	memset(vis,0,sizeof(vis));
	int step=0;
	queue<point> q;
	point tag(0,0);
	vis[1][1][step]=1;
	q.push(point(1,1));
	q.push(tag);
	while(1){
		point t=q.front();q.pop();
		int y=t.y,x=t.x;
		//printf("y=%d x=%d step=%d\n",y,x,step);
		if(y==0){step++;q.push(tag);continue;}
		if(y==N&&x==M)break;
		_for(i,0,4){
			int nx=x+_x[i],ny=y+_y[i];
			if(is_legal(ny,nx,step+1)&&!vis[ny][nx][step+1]){
				q.push(point(ny,nx));
				vis[ny][nx][step+1]=true;
			}

		}
	}
	minstep=step;
}
int main(){
	//freopen("d:\\input.txt","r",stdin);
	//freopen("d:\\output.txt","w",stdout);
	cin>>N>>M>>t;
	int r,c,a,b;
	_for(i,0,t){
		scanf("%d %d %d %d",&r,&c,&a,&b);
		G[r][c].t1=a;
		G[r][c].t2=b;
	}
	BFS();
	cout<<minstep<<endl;
	return 0;
}

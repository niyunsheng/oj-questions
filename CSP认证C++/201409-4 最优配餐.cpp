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

//201409-4 最优配餐
//答案错误，80分，之前0分真是不应该啊，一是没有考虑到两个客户的坐标一样的情况，而是push的node坐标写成了node(c2,c2)，真是不细心造成大错误，而且居然过了算例，说明自己写算例是多么重要啊，至少得把所有情况走一遍。
#define MAXN 1005
#define inf 0x7fffffff
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
int getint(){int x;scanf("%d",&x);return x;}
vector<vector<int> > grid(MAXN,vector<int>(MAXN,0));
vector<vector<bool> > vis(MAXN,vector<bool>(MAXN,false));
//bool vis[MAXN][MAXN]={0};
int N,M,K,D,custom=0;
struct node{
	int x,y;
	node(int i,int j):x(i),y(j){}
};
queue<node> que;
int level=0,cnt=0,sum=0;
int _x[4]={1,-1,0,0},_y[4]={0,0,1,-1};
bool is_valid(int x,int y){
	return x>0&&x<=N&&y>0&&y<=N&&!vis[x][y]&&grid[x][y]>=0;
}
int main(){
	//freopen("d:\\input.txt","r",stdin);
	cin>>N>>M>>K>>D;
	int c1,c2,t;
	_for(i,0,M){
		scanf("%d %d",&c1,&c2);
		grid[c1][c2]=-1;//0表示空，-1表示店铺，-2表示不能通行，正数表示订餐量
		que.push(node(c1,c2));//居然是这里写成了node(c2,c2)，真是无语啊，这种错误
		vis[c1][c2]=true;
	}
	que.push(node(-1,-1));//每层结束的标志
	_for(i,0,K){
		scanf("%d %d %d",&c1,&c2,&t);
		if(grid[c1][c2]==0)custom++;
		grid[c1][c2]+=t;
	}
	_for(i,0,D){
		scanf("%d %d",&c1,&c2);
		grid[c1][c2]=-2;
	}
	while(!que.empty()){
		node tnode=que.front();que.pop();
		if(tnode.x==-1){
			level++;
			if(!que.empty())que.push(node(-1,-1));
			continue;
		}
		if(grid[tnode.x][tnode.y]>0){
			sum+=grid[tnode.x][tnode.y]*level;
			cnt++;
			if(cnt==custom)break;
		}
		_for(i,0,4){
			int nx=tnode.x+_x[i],ny=tnode.y+_y[i];
			if(is_valid(nx,ny)){
				vis[nx][ny]=true;
				que.push(node(nx,ny));
			}
		}
	}
	printf("%d\n",sum);
	return 0;
}

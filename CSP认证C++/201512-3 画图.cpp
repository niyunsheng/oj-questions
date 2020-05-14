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

//201512-3 画图
//AC
const int MAXN=105;
#define inf 0x7fffffff
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
int graph[MAXN][MAXN];//表示为graph[y][x]
int M,N,Q;
int _x[4]={1,-1,0,0},_y[4]={0,0,1,-1};
bool vis[MAXN][MAXN];
bool is_valid(int x,int y){
	return x>=0&&x<M&&y>=0&&y<N&&!vis[y][x]&&graph[y][x]>=0;
}
void DFS(int x,int y,char c){
	_for(i,0,4){
		int nx=x+_x[i],ny=y+_y[i];
		if(is_valid(nx,ny)){
			graph[ny][nx]=c;vis[ny][nx]=true;
			DFS(nx,ny,c);
		}
	}
}
int main(){
	//freopen("d:\\input.txt","r",stdin);
	//freopen("d:\\output.txt","w",stdout);
	memset(graph,0,sizeof(graph));
	cin>>M>>N>>Q;
	int t,x1,y1,x2,y2;
	char c;
	_for(i,0,Q){
		scanf("%d",&t);
		if(t==0){
			scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
			//printf("%d %d %d %d\n",x1,y1,x2,y2);
			//横边-1，竖边-2，交叉边-3
			if(x1==x2){
				if(y1>y2)swap(y1,y2);
				_for(j,y1,y2+1){
					if(graph[j][x1]==-1)graph[j][x1]=-3;
					else if(graph[j][x1]>=0)graph[j][x1]=-2;
				}
			}else{
				if(x1>x2)swap(x1,x2);
				_for(j,x1,x2+1){
					if(graph[y1][j]==-2)graph[y1][j]=-3;
					else if(graph[y1][j]>=0)graph[y1][j]=-1;
				}
			}
		}else{
			scanf("%d %d %c",&x1,&y1,&c);
			memset(vis,0,sizeof(vis));
			graph[y1][x1]=c;vis[y1][x1]=true;
			DFS(x1,y1,c);
		}
	}
	for(int i=N-1;i>=0;i--){
		_for(j,0,M){
			switch(graph[i][j]){
			case -3:printf("+");break;
			case -2:printf("|");break;
			case -1:printf("-");break;
			case 0:printf(".");break;
			default:printf("%c",graph[i][j]);break;
			}
		}
		printf("\n");
	}
	return 0;
}

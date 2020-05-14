/**
 * @Date:   2018-08-24
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-24
 */
//
//不知道哪个边界条件没考虑到，90分，懂得适当的放弃
#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<set>
#include<map>
#include<stack>
#include<sstream>
#include<vector>
#include<queue>
using namespace std;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
const int MAXN=100005;
const int inf=0x3f3f3f3f;
int G[15][10],P[4][4];
int g[10],p[4];//两个图形的边界
int x,y=15,px=3;
int main(){
	//freopen("d:\\input.txt","r",stdin);
	memset(G,0,sizeof(G));
	memset(P,0,sizeof(P));
	_for(i,0,15)g[i]=15;//上边界
	_for(i,0,4)p[i]=-1;//下边界
	_for(i,0,15)
	_for(j,0,10){
		scanf("%d",&G[i][j]);
		if(G[i][j]==1&&i<g[j])g[j]=i;
	}
	//_for(i,0,10)printf("%d ",g[i]);printf("\n");
	_for(i,0,4)
	_for(j,0,4){
		scanf("%d",&P[i][j]);
		if(P[i][j]==1){
			if(i>p[j])p[j]=i;
			px=min(px,j);
		}
	}
	//_for(i,0,4)printf("%d ",p[i]);printf("\n");
	scanf("%d",&x);
	x--;px=0;
	_for(i,0,4){
		if(px+i>=4||x+i>=10)break;
		y=min(y,g[x+i]-p[px+i]-1);
	}
	//顶点坐标为px,0,以及x,y
	_for(i,0,4){
		if(y+i>=15)break;
		_for(j,0,4){
			if(px+j>=4||x+j>=10)break;
			if(P[i][px+j])G[y+i][x+j]=1;
		}
	}
	_for(i,0,15){
		printf("%d",G[i][0]);
		_for(j,1,10){
			printf(" %d",G[i][j]);
		}
		printf("\n");
	}

	return 0;
}

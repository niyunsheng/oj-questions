/**
 * @Date:   2018-09-13
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-13
 */
//祭坛
//运行错误，30分
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
const int MAXN=5005;
int M,N;
bool grid[MAXN][MAXN];
int g1[MAXN][MAXN],g2[MAXN][MAXN];
string str;
int main(){
	//freopen("d:\\input.txt","r",stdin);
	cin>>N>>M;
	memset(grid,0,sizeof(grid));
	int c1,c2;
	_for(i,0,N){
		scanf("%d %d",&c1,&c2);
		grid[c1][c2]=1;
		//cout<<c1<<c2;
	}
	_for(i,1,MAXN)
		_for(j,1,MAXN){
			g1[i][j]=g1[i][j-1]+grid[i][j-1];
			g2[i][j]=g2[i-1][j]+grid[i-1][j];
		}
	int max1=0,max2=0;//最多的结节数量和方案数
	_for(i,1,MAXN)
		_for(j,0,MAXN-1){
			int t1=min(g1[i][j],g1[i][MAXN-1]-g1[i][j+1]);
			int t2=min(g2[i][j],g2[MAXN-1][j]-g2[i+1][j]);
			int t3=min(t1,t2);
			if(max1<t3){max1=t3;max2=1;}
			else if(max1==t3){max2++;}
		}
	if(M==1)cout<<max1;
	else cout<<max2;
	return 0;

}

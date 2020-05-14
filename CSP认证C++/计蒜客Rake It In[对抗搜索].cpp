/**
 * @Date:   2018-09-14
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-14
 */
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
int t,k,G[4][4];
int score=0;
void rotateA(int x,int y){//逆时针
	int t=G[y][x];
	G[y][x]=G[y][x+1];
	G[y][x+1]=G[y+1][x+1];
	G[y+1][x+1]=G[y+1][x];
	G[y+1][x]=t;
}
void rotateB(int x,int y){//顺时针
	int t=G[y][x];
	G[y][x]=G[y+1][x];
	G[y+1][x]=G[y+1][x+1];
	G[y+1][x+1]=G[y][x+1];
	G[y][x+1]=t;
}
int sum(int x,int y){
	return G[y][x]+G[y+1][x]+G[y][x+1]+G[y+1][x+1];
}
int DFS(int flag,int k){
	if(k==0)return 0;
	int tmp,ans;
	if(flag==0)ans=0;
	else ans=inf;
	_for(i,0,3)
	_for(j,0,3){
		int t=sum(i,j);
		rotateA(i,j);
		tmp=t+DFS(1-flag,k-1);
		rotateB(i,j);
		if(flag==0&&tmp>ans)ans=tmp;
		else if(flag==1&&tmp<ans)ans=tmp;
	}
	return ans;
}
int main(){
	//freopen("d:\\input.txt","r",stdin);
	cin>>t;
	while(t--){
		cin>>k;
		_for(i,0,4)
		_for(j,0,4)
			cin>>G[i][j];

		int score=DFS(0,2*k);//0表示先手操作，1表示后手操作
		printf("%d\n",score);
	}
	return 0;
}

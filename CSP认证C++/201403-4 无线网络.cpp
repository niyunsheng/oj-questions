/**
 * @Date:   2018-09-11
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-11
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

//201403-4 无线网络
//答案有错误，80分
const int MAXN=205;
#define inf 0x7fffffff
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
int N,M,K,R;
struct node{
	int step,x,y,k_val;
	bool vis;
	node(int a,int b,int c,bool d):step(a),x(b),y(c),vis(d){}
	node(){}
};
vector<node> grid(MAXN);
int main(){
	//freopen("d:\\input.txt","r",stdin);
	//freopen("d:\\output.txt","w",stdout);
	cin>>N>>M>>K>>R;

	int x,y;
	_for(i,1,N+1){
		scanf("%d %d",&x,&y);
		grid[i]=node(0,x,y,false);
	}
	_for(i,1,M+1){
		scanf("%d %d",&x,&y);
		grid[N+i]=node(0,x,y,false);
	}
	grid[1].vis=true;grid[1].step=0;grid[1].k_val=0;
	queue<int> q;
	q.push(1);
	while(1){
		if(grid[2].vis)break;
		int cur=q.front();q.pop();
		//cout<<cur<<endl;
		_for(i,1,N+1){
			if(!grid[i].vis){
				int t=(grid[i].x-grid[cur].x)*(grid[i].x-grid[cur].x)+(grid[i].y-grid[cur].y)*(grid[i].y-grid[cur].y);
				if(t<=R*R){
					grid[i].vis=true;
					grid[i].step=grid[cur].step+1;
					grid[i].k_val=grid[cur].k_val;
					q.push(i);
				}
			}
		}
		if(grid[cur].k_val==K)continue;
		_for(i,N+1,N+M+1){
			if(!grid[i].vis){
				int t=(grid[i].x-grid[cur].x)*(grid[i].x-grid[cur].x)+(grid[i].y-grid[cur].y)*(grid[i].y-grid[cur].y);
				if(t<=R*R){
					grid[i].vis=true;
					grid[i].step=grid[cur].step+1;
					grid[i].k_val=grid[cur].k_val+1;
					q.push(i);
				}
			}
		}
	}
	printf("%d\n",grid[2].step-1);
	return 0;
}

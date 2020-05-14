/**
 * @Date:   2018-09-12
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-12
 */
//保存两张图，对于每个顶点进行两次BFS，然后判断该定点是否可达其他任意顶点或者被其他顶点可达。
//from：https://blog.csdn.net/qq_36160277/article/details/81509390
//这个简单的没有剪枝的方法也许就是最优的了

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
vector<int>g1[1005];
vector<int>g2[1005];
int n,m;
int reached1[1005];
int reached2[1005];
int allReached[1005];
int main(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int a,b;cin>>a>>b;
		g1[a].push_back(b);
		g2[b].push_back(a);
	}
	int sum=0;
	for(int i=1;i<=n;i++){

		allReached[i]=i;

		queue<int>q;
		q.push(i);
		reached1[i]=i;//被便利过
		while(!q.empty()){
			int x=q.front();
			q.pop();
			for(int j=0;j<g1[x].size();j++){
				int y=g1[x][j];
				if(reached1[y]!=i){
					reached1[y]=i;
					q.push(y);
					allReached[y]=i;
				}
			}
		}
		q.push(i);
		reached2[i]=i;//被便利过
		while(!q.empty()){
			int x=q.front();
			q.pop();
			for(int j=0;j<g2[x].size();j++){
				int y=g2[x][j];
				if(reached2[y]!=i){
					reached2[y]=i;
					q.push(y);
					allReached[y]=i;
				}
			}
		}
		int num=0;
		for(int j=1;j<=n;j++){
			if(	allReached[j]==i)num++;
		}
		if(num==n)sum++;
	}
	cout<<sum;
	return 0;
}

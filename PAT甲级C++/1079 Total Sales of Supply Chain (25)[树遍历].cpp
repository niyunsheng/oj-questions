/**
 * @Date:   2018-08-11
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-11
 */
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
//1079 Total Sales of Supply Chain (25)
/*思路：仿照图的邻接表建树，然后遍历即可
本题遍历时用的是BFS，用了辅助数组存储节点的层数，用DFS递归的话，不用邻接表，而是定义节点结构体，包括数据域和孩子域，孩子域用vector<int>实现，然后传递参数时加上层数即可。也较为方便！
	*/
#define _for(i,a,b) for(int i=(a);i<(b);i++)
int main(){
	//freopen("D:\\codeBlockSpace\\input.txt","r",stdin);
	int n;
	double p,r;
	scanf("%d %lf %lf",&n,&p,&r);
	vector<vector<int>> grid(n);//存储树
	vector<int> vis(n,0);//值不为0表明该节点的产品数
	vector<int> level(n,0);//节点的层数，0节点层数为0；

	vector<double> frac(n,1);//(1+r)^i
	_for(i,1,n){	frac[i]=(1+r/100)*frac[i-1];}
	int m,t;//后继个数、临时变量
	_for(i,0,n){
		scanf("%d",&m);
		if(m!=0){
			_for(j,0,m){
				scanf("%d",&t);
				grid[i].push_back(t);
			}
		}else{
			scanf("%d",&vis[i]);
		}
	}
	//BFS
	queue<int> q;
	q.push(0);
	double sum=0;
	while(!q.empty()){
		int tt=q.front();q.pop();
		if(grid[tt].size()==0){
			sum+=vis[tt]*frac[level[tt]];
		}else{
			_for(i,0,grid[tt].size()){
				level[grid[tt][i]]=level[tt]+1;
				q.push(grid[tt][i]);
			}
		}
	}
	sum*=p;//乘上单位价格
	printf("%.1lf",sum);
	return 0;
}

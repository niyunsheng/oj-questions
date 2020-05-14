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
//1090 Highest Price in Supply Chain (25)
/*思路：仿照图的邻接表建树，然后遍历即可
比1079的内容少了，思路一致
	*/
#define _for(i,a,b) for(int i=(a);i<(b);i++)
int main(){
	//freopen("D:\\codeBlockSpace\\input.txt","r",stdin);
	int n;
	double p,r;
	scanf("%d %lf %lf",&n,&p,&r);
	vector<vector<int>> grid(n);//存储树
	vector<int> level(n,0);//节点的层数，0节点层数为0；
	vector<double> frac(n,1);//(1+r)^i
	_for(i,1,n){	frac[i]=(1+r/100)*frac[i-1];}
	int root,t;//后继个数、临时变量
	_for(i,0,n){
		scanf("%d",&t);
		if(t!=-1){
			grid[t].push_back(i);
		}else{
			root=i;
		}
	}
	//BFS
	queue<int> q;
	q.push(root);
	double maxN=0;//节点售价
	int sum=0,maxlevel=0;//最大节点个数
	while(!q.empty()){
		int tt=q.front();q.pop();
		if(grid[tt].size()!=0){
			_for(i,0,grid[tt].size()){
				level[grid[tt][i]]=level[tt]+1;
				q.push(grid[tt][i]);
			}
		}else{
			if(level[tt]>maxlevel){
				maxlevel=level[tt];sum=1;
			}else if(level[tt]==maxlevel){
				sum++;
			}
		}
	}
	maxN=frac[maxlevel]*p;//乘上单位价格
	printf("%.2lf %d\n",maxN,sum);
	return 0;
}

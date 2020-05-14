
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
//1004 Counting Leaves (30)
/*思路：每一层上的叶子节点数，用一个数组存储，DFS遍历即可
标准做法：全局变量开最大，DFS遍历
	*/
#define MAX 105
vector<vector<int> > grid(MAX);//存储树
vector<int> level(MAX,0);//节点的层数，0节点层数为0；
vector<int> levNum(MAX,0);//该层叶子结点数目
int maxLev;
#define _for(i,a,b) for(int i=(a);i<(b);i++)
int getint(){
	int x;scanf("%d",&x);return x;
}
void DFS(int id,int lev){
	if(grid[id].size()==0){
		levNum[level[id]]++;
	}else{
		if(lev+1>maxLev)maxLev=lev+1;
		_for(i,0,grid[id].size()){
			DFS(grid[id][i],level[grid[id][i]]=lev+1);
		}
	}
}
int main(){
	//freopen("D:\\input.txt","r",stdin);
	int n,m;
	scanf("%d %d",&n,&m);
	int id,k;//后继个数、临时变量
	_for(i,0,m){
		scanf("%d %d",&id,&k);
		if(k!=0){
			_for(j,0,k){
				grid[id].push_back(getint());
			}
		}
	}
	//DFS
	maxLev=1;level[1]=1;
	DFS(1,1);
	printf("%d",levNum[1]);
	_for(i,2,maxLev+1)
		printf(" %d",levNum[i]);
	return 0;
}

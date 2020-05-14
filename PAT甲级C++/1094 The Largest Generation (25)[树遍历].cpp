/**
 * @Date:   2018-08-11
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-11
 */
#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<string>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
//1094 The Largest Generation (25)
/*思路：前两个树遍历都是用的BFS，这个题目改用DFS传入层数来做，用数组存储每层节点总数并更新最大值。很明显，DFS的代码更简洁，只不过需要把数组都开成全局变量，开到最大

	*/
#define _for(i,a,b) for(int i=(a);i<(b);i++)
#define MAX 1005
vector<vector<int>> grid(MAX);//存储树
vector<int> level(MAX);//节点的层数，根节点1节点层数为1；
vector<int> levNum(MAX,0);//该层数中节点的数目
int maxLevel,maxLevNum;//人数最多的层，层号、人数
void DFS(int id,int lev){
	if(grid[id].size()!=0){
		_for(i,0,grid[id].size()){
			level[grid[id][i]]=lev+1;
			levNum[lev+1]++;
			if(levNum[lev+1]>maxLevNum){maxLevNum=levNum[lev+1];maxLevel=lev+1;}
			DFS(grid[id][i],lev+1);
		}
	}
}
int main(){
	//freopen("D:\\codeBlockSpace\\input.txt","r",stdin);
	int n,m;
	scanf("%d %d",&n,&m);

	level[1]=1;
	int id,k,t;//当前节点，孩子数目，临时变量
	_for(i,0,m){
		scanf("%d %d",&id,&k);
		_for(j,0,k){
			scanf("%d",&t);
			grid[id].push_back(t);
		}
	}
	//DFS
	levNum[1]=1;maxLevel=1;maxLevNum=1;
	DFS(1,1);
	printf("%d %d\n",maxLevNum,maxLevel);
	return 0;
}

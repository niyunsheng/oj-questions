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
//1106 Lowest Price in Supply Chain（25 分）
/*思路：与1090 Highest Price in Supply Chain (25)如出一辙,只不过改变了输入输出格式
本题采用了新的getint快捷方式和_for()宏定义，果然好用
	*/
#define _for(i,a,b) for(int i=(a);i<(b);i++)
int getint(){
	int x;scanf("%d",&x);return x;
}

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
		if(t!=0){
			_for(j,0,t){
				grid[i].push_back(getint());
			}
		}
	}
	//BFS
	queue<int> q;
	q.push(0);
	double minN=0;//节点售价
	int sum=0,minlevel=n;//最小节点个数,层数
	while(!q.empty()){
		int tt=q.front();q.pop();
		if(grid[tt].size()!=0){
			_for(i,0,grid[tt].size()){
				level[grid[tt][i]]=level[tt]+1;
				q.push(grid[tt][i]);
			}
		}else{
			if(level[tt]<minlevel){
				minlevel=level[tt];sum=1;
			}else if(level[tt]==minlevel){
				sum++;
			}
		}
	}
	minN=frac[minlevel]*p;//乘上单位价格
	printf("%.4lf %d\n",minN,sum);
	return 0;
}

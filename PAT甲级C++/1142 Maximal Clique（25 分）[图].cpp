/**
 * @Date:   2018-08-28
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-28
 */
#include<iostream>
#include<vector>
using namespace std;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
void printvec(vector<int>& vec){
	printf("%d",vec[0]);
	_for(i,1,vec.size()){printf(" %d",vec[i]);}
	printf("\n");
}
//想不出好的方法，还是暴力吧
#define MAXN 205
int grid[MAXN][MAXN]={0};
int main(){
    //freopen("d:\\input.txt","r",stdin);
	int Nv,Ne,v1,v2,M,K;
	scanf("%d %d",&Nv,&Ne);
	_for(i,0,Ne){
		scanf("%d %d",&v1,&v2);
		grid[v1][v2]=1;
		grid[v2][v1]=1;
	}
	scanf("%d",&M);
	vector<int> vec(Nv);
	vector<int> vis(Nv+1);
	_for(i,0,M){
		fill(vis.begin(),vis.end(),0);
		scanf("%d",&K);
		_for(j,0,K){scanf("%d",&vec[j]);vis[j]=1;}
		int flag=0;//0表示是clique，1表示不是clique，2表示虽然是，但不是最大
		//先检验是不是clique
		_for(j,0,K){
			_for(k,j+1,K){
				if(grid[vec[j]][vec[k]]==0){
					flag=1;break;
				}
			}
			if(flag==1)break;
		}
		if(flag==1){printf("Not a Clique\n");continue;}
		_for(i,1,Nv+1){
			if(vis[i]==0){
				int t=0;
				while(t<K&&grid[i][vec[t]]==1)t++;
				if(t==K){flag=2;break;}
			}
		}
		if(flag==2){printf("Not Maximal\n");continue;}
		if(flag==0){printf("Yes\n");continue;}
	}
	return 0;
}

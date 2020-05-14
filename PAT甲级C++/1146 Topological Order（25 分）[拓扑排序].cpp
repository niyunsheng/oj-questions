/**
 * @Date:   2018-08-28
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-28
 */
//思路：对于每一个需要判断是不是拓扑排序的数组而言，直接模拟拓扑排序判断即可。但是如果查询的次数非常多的话，单次查询的时间复杂度是O(E)，E是图中边的数目。如果采取标记节点层次的方法，单次查询的时间复杂度可以降到O(V)，V是图中节点的数目。但是，第二种方法暂时没有想到如何处理两个及以上非连通域的情况。

//方法一：模拟拓扑排序
#include<iostream>
#include<vector>
using namespace std;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
void printvec(vector<int>& vec){
	printf("%d",vec[0]);
	_for(i,1,vec.size()){printf(" %d",vec[i]);}
	printf("\n");
}
#define MAXN 1005
int MSize;
int cnt=0;//查询总次数
vector<vector<int> > grid(MAXN);
vector<int> inD(MAXN,0),tmp_inD(MAXN,0);//根据节点层次记录树的层次

int main(){
    //freopen("d:\\input.txt","r",stdin);
	int N,M,K,id,t;
    scanf("%d %d",&N,&M);
	_for(i,0,M){
		scanf("%d %d",&id,&t);
		grid[id].push_back(t);
		inD[t]++;
	}
	int cnt=0;
	vector<int> ans,vec(N);
	scanf("%d",&K);
	_for(i,0,K){
		tmp_inD=inD;
		_for(j,0,N)scanf("%d",&vec[j]);

		_for(j,0,N){
			if(tmp_inD[vec[j]]!=0){
				ans.push_back(i);
				break;
			}else{
				_for(k,0,grid[vec[j]].size())
					tmp_inD[grid[vec[j]][k]]--;
			}
		}
	}
	printvec(ans);
    return 0;
}

//方法二：标记节点层次，只适用于单连通域
#include<iostream>
#include<vector>
using namespace std;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
void printvec(vector<int>& vec){
	printf("%d",vec[0]);
	_for(i,1,vec.size()){printf(" %d",vec[i]);}
	printf("\n");
}
#define MAXN 1005
int MSize;
int cnt=0;//查询总次数
vector<vector<int> > grid(MAXN);
vector<int> inD(MAXN,0),level(MAXN,-1),vis(MAXN,0);//根据节点层次记录树的层次

int main(){
    //freopen("d:\\input.txt","r",stdin);
	int N,M,K,id,t;
    scanf("%d %d",&N,&M);
	_for(i,0,M){
		scanf("%d %d",&id,&t);
		grid[id].push_back(t);
		inD[t]++;
	}
	int cnt=0;
	vector<int> ans,vec(N);
	_for(i,1,N+1)
		if(inD[i]==0)level[i]=0;
	while(cnt<N){
		//cout<<cnt<<endl;
		_for(i,1,N+1){
			if(inD[i]==0&&vis[i]==0){
				vis[i]=1;
				cnt++;
				_for(j,0,grid[i].size()){
					inD[grid[i][j]]--;
					if(level[i]+1>level[grid[i][j]])
						level[grid[i][j]]=level[i]+1;
				}
			}
		}
	}

	scanf("%d",&K);
	_for(i,0,K){
		_for(j,0,N)scanf("%d",&vec[j]);
		//printvec(vec);
		_for(j,1,N){
			if(level[vec[j-1]]>level[vec[j]]){
				ans.push_back(i);
				break;
			}
		}
	}
	printvec(ans);
    return 0;
}

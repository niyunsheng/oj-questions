//A1018 Public Bike Management (30)
 /*
 思路：Dijkstra+DFS.如果只有Dijkstra是不可以的，因为minNeed和minBack在路径上的传递不满足最优子结构，不是简单的相加的过程，只有在所有路径都确定了之后才能区选择最小的need和最小的back
 易错点：
	返回过程中不调整，一个节点需要带来的数目和返回的数目没有关系，要分别将记录
	不能只用Dijkstra
	看清楚判断最有路径的条件，先选从0节点带走最少的，再选带到0节点最少的
 */
#include<iostream>
#include<vector>
#include<set>
#include"string.h"
using namespace std;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
int getint() {int x;scanf("%d",&x);return x;}
#define MAX 505
#define inf 0x7fffffff
struct node{int x,len;node(int xx,int ll):x(xx),len(ll){}};
vector<vector<node> > grid(MAX);//节点标号为1-N,从0出发
vector<vector<int> > path(MAX);
vector<int> vec,minpath;//记录中间路径,最短路径
int minwei=inf,minremain=inf;
int Cmax,N,Sp,M;//含义与题目同
vector<int> dist(MAX,inf),vis(MAX,false),weight(MAX);

void Dijkstra(){//x顶点到其他定点的单源最短路径
	int id,len,n;
	_for(k,0,N+1){
		id=-1;len=inf;
		//找到未发现的定点中的最近顶点，加入已发现集合
		_for(i,0,N+1){
			if(!vis[i]&&dist[i]<len){
				len=dist[i];
				id=i;
			}
		}
		if(id==-1)return;
		//从该定点更新状态数组
		vis[id]=true;
		n=grid[id].size();
		int nextid;
		_for(i,0,n){
			nextid=grid[id][i].x;len=grid[id][i].len;//分别表示顶点和长度
			if(!vis[nextid]){
				if(dist[nextid]>dist[id]+len){
					dist[nextid]=dist[id]+len;
					path[nextid].clear();
					path[nextid].push_back(id);
				}else if(dist[nextid]==dist[id]+len){
					path[nextid].push_back(id);
				}
			}
		}
	}
}
//遍历path向量，在最短路径中寻找
//这里每个节点需要两个标记，到达该节点需要带来的数目，从该节点需要带走的数目
//两者可能均不为0，比如前两个节点为-5，10，从0节点出发需要带5个，而从2节点返回时带10个，返回到0节点也要带上这10个
void DFS(int id,int wei,int remain){//Wei表示在id节点需要带来的数目，remain表示在id节点需要带走的数目
	if(id==0){
		if(wei<minwei){
			minwei=wei;
			minremain=remain;
			minpath=vec;
		}else if(wei==minwei&&remain<minremain){
			minremain=remain;
			minpath=vec;
		}
		return;
	}
	_for(i,0,path[id].size()){
		int next=path[id][i];
		vec.push_back(next);
		if(weight[next]>=0){
			if(weight[next]>=wei)
				DFS(next,0,remain+weight[next]-wei);
			else
				DFS(next,wei-weight[next],remain);
		}else{
			DFS(next,wei-weight[next],remain);
		}
		vec.pop_back();
	}
}

int main(){
    //freopen("d:\\input.txt","r",stdin);
    scanf("%d %d %d %d",&Cmax,&N,&Sp,&M);
	_for(i,1,N+1){
		weight[i]=getint()-Cmax/2;//输入时直接减去，后面可根据其正负判断
	}
    int c1,c2,len;
    for(int i=1;i<=M;i++){
        scanf("%d %d %d",&c1,&c2,&len);
        grid[c1].push_back(node(c2,len));
        grid[c2].push_back(node(c1,len));
    }
	//从0节点计算单源最短路径
	dist[0]=0;
	Dijkstra();
	//测试中居然还存在Sp节点不是问题节点的情况，所以，初始化进入DFS要分此两种情况
	if(weight[Sp]<0)
		DFS(Sp,-weight[Sp],0);
	else
		DFS(Sp,0,weight[Sp]);
	printf("%d ",minwei);
	for(int i=minpath.size()-1;i>=0;i--){
		printf("%d->",minpath[i]);
	}
	printf("%d ",Sp);
	printf("%d\n",minremain);
    return 0;
}



//最开始想仅用迪杰斯特拉就做出来，可是条件判断不清晰，最后还是选择更加简单明了的迪杰斯特拉+DFS，用迪杰斯特拉找到所有的最短路径，然后DFS遍历所有的最短路径找到最优答案
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
int getint() {int x;scanf("%d",&x);return x;}
#define MAX 505
struct node{int x,len;node(int xx,int ll):x(xx),len(ll){}};
vector<vector<node>> grid(MAX);//节点标号为1-N
int Cmax,N,Sp,M;//含义与题目同
//迪杰斯特拉最短路径解法专用数组
#define inf 0x7fffffff
vector<int> path(MAX,-1),dist(MAX,inf),vis(MAX,false),w(MAX,0),weight(MAX);
void DFS(){//x顶点到其他定点的单源最短路径
	int id,len,n;
	_for(k,0,N+1){
		id=-1;len=inf;
		//找到未发现的定点中的最近顶点，加入已发现集合
		_for(i,0,N+1){
			if(!vis[i]&&dist[i]<len){
				len=dist[i];
				id=i;
			}
		}
		if(id==-1)return;
		//从该定点更新状态数组
		vis[id]=true;
		n=grid[id].size();
		int nextid;
		_for(i,0,n){
			nextid=grid[id][i].x;len=grid[id][i].len;//分别表示顶点和长度
			if(!vis[nextid]){
				if(dist[nextid]>dist[id]+len){
					dist[nextid]=dist[id]+len;
					path[nextid]=id;
					w[nextid]=w[id]+Cmax/2-weight[nextid];
				}else if(dist[nextid]==dist[id]+len){
					if(w[nextid]>w[id]+Cmax/2-weight[nextid]){
						path[nextid]=id;
						w[nextid]=w[id]+Cmax/2-weight[nextid];
					}
				}
			}
		}
	}
}
void printpath(int x){
	if(path[x]!=-1)
		printpath(path[x]);
	printf("%d->",x);
}
int main(){
    //freopen("d:\\input.txt","r",stdin);

    scanf("%d %d %d %d",&Cmax,&N,&Sp,&M);
	_for(i,1,N+1){
		weight[i]=getint();
	}
    int c1,c2,len;
    for(int i=1;i<=M;i++){
        scanf("%d %d %d",&c1,&c2,&len);
        grid[c1].push_back(node(c2,len));
        grid[c2].push_back(node(c1,len));
    }
	//从0节点计算单源最短路径
	dist[0]=0;
	DFS();
	if(w[Sp]<0){
		printf("0 ",w[Sp]);
		printpath(path[Sp]);
		printf("%d ",Sp);
		printf("%d\n",-w[Sp]);
	}else{
		printf("%d ",w[Sp]);
		printpath(path[Sp]);
		printf("%d ",Sp);
		printf("0\n");
	}

    return 0;
}

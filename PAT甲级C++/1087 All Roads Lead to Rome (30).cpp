//1087 All Roads Lead to Rome (30)
/*思路：Dijkstra记录标志数组，并且明确状态转换条件，如果是最优子问题，那就优先选用数组标记的Dijkstra算法吧，但是，如果不是最优子，则必须用Dijkstra+DFS，两种方法都应该非常熟悉。

涉及到的有最短路径，第一权值是点权（获得更多的快感），第二权值是平均快感（即经过的城市最少）
也需要输出最短路径的条数，所以还要更新到达该点的最短路径条数向量
	*/
#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

#define inf 0x3fffffff
struct node{
	int c,len;
	node(int cc,int l):c(cc),len(l){}
};
void printpath(int end,vector<int>& path,vector<string>& int2str){
	if(path[end]!=-1){
		printpath(path[end],path,int2str);
	}
	if(end==0)cout<<int2str[0];
	else cout<<"->"<<int2str[end];
}
int main(){
    //freopen("D:\\input.txt","r",stdin);
	int n,k,t;
	string str,str1;
	cin>>n>>k>>str;
	vector<int> num(n,0);//记录到达该定点所经过的中间节点的个数
	vector<int> sum(n,0);//最短路径的数目
	vector<int> weight(n,0);//各个城市的点权
	vector<int> w(n,0);//第二权值
	vector<int> path(n,-1);
	vector<int> dist(n,inf);
	vector<bool> vis(n,false);
	vector<vector<node> > grid(n);
	map<string,int> str2int;
	vector<string> int2str(n);
	int top=0;
	str2int[str]=top;
	int2str[top]=str;//0位置存放的是起始城市
	top++;
	while(top<n){
		cin>>str>>t;
		weight[top]=t;
		str2int[str]=top;
		int2str[top]=str;
		top++;
	}
	for(int i=0;i<k;i++){
		cin>>str>>str1>>t;
		int c1=str2int[str],c2=str2int[str1];
		grid[c1].push_back(node(c2,t));
		grid[c2].push_back(node(c1,t));
	}
	dist[0]=0;sum[0]=1;
	for(int i=0;i<n;i++){
		int minlen=inf,minid=-1;
		for(int j=0;j<n;j++){
			if(!vis[j]&&dist[j]<minlen){
				minlen=dist[j];
				minid=j;
			}
		}
		//if(minid==-1){printf("error");return -1;}
		vis[minid]=true;
		for(int j=0;j<grid[minid].size();j++){
			int c=grid[minid][j].c,len=grid[minid][j].len;
			if(!vis[c]&&len!=inf){
				if(dist[c]>dist[minid]+len){
					path[c]=minid;
					num[c]=num[minid]+1;
					dist[c]=dist[minid]+len;
					w[c]=w[minid]+weight[minid];
					sum[c]=sum[minid];
				}else if(dist[c]==dist[minid]+len){
					sum[c]+=sum[minid];//路径数目
					if(w[c]<w[minid]+weight[minid]){
						path[c]=minid;
						num[c]=num[minid]+1;
						w[c]=w[minid]+weight[minid];
					}else if(w[c]==w[minid]+weight[minid]){
						if(num[c]>num[minid]+1){
							path[c]=minid;
							num[c]=num[minid]+1;
						}
					}
				}
			}
		}
	}
	int end=str2int["ROM"];
	printf("%d %d %d %d\n",sum[end],dist[end],w[end]+weight[end],(w[end]+weight[end])/(num[end]));

	printpath(end,path,int2str);
	return 0;
}

//9月7日更，思路一致，只不过代码稍微优化了点
//两次Dijkstra即可
//1111online map
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<stack>
#include<algorithm>
using namespace std;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
#define MAXN 205
#define INF 0x7fffffff
int N,K,M;//记录最短路径的条数
struct node{
	int id,len;
	node(int i,int l):id(i),len(l){}
};
map<string,int> ID;
vector<string> name;
int getID(string& str){
	if(ID.count(str))return ID[str];
	name.push_back(str);
	return ID[str]=name.size()-1;
}
vector<int> dist(MAXN,INF),weight(MAXN),w1(MAXN,0),w2(MAXN,INF),path(MAXN,-1),num(MAXN,0);//第一权值是获得的快感更多，第二权值是经过的城市更少
vector<bool> vis(MAXN,false);
vector<vector<node> > grid(MAXN);
void Dijkstra(int s){
	while(1){
		int minid=-1,mindist=INF;
		_for(i,0,N){
			if(!vis[i]&&dist[i]<mindist){
				minid=i;mindist=dist[i];
			}
		}
		if(minid==-1)break;
		vis[minid]=true;
		_for(i,0,grid[minid].size()){
			int next=grid[minid][i].id,len=grid[minid][i].len;
			if(vis[next])continue;
			if(dist[next]>dist[minid]+len){
				num[next]=num[minid];
				dist[next]=dist[minid]+len;
				w1[next]=w1[minid]+weight[next];
				w2[next]=w2[minid]+1;
				path[next]=minid;
			}else if(dist[next]==dist[minid]+len){
				num[next]+=num[minid];
				if(w1[next]<w1[minid]+weight[next]){
					w1[next]=w1[minid]+weight[next];
					w2[next]=w2[minid]+1;
					path[next]=minid;
				}else if(w1[next]==w1[minid]+weight[next]&&w2[next]>w2[minid]+1){
					w2[next]=w2[minid]+1;
					path[next]=minid;
				}
			}
		}
	}
}

int main() {
	//freopen("d:\\input.txt","r",stdin);
	string str1,str2;
	cin>>N>>K>>str1;
	int start=getID(str1),t;
	_for(i,1,N){
		cin>>str1>>t;
		weight[getID(str1)]=t;
	}
	_for(i,0,K){
		cin>>str1>>str2>>t;
		int c1=ID[str1],c2=ID[str2];
		grid[c1].push_back(node(c2,t));
		grid[c2].push_back(node(c1,t));
	}
	dist[start]=0;w1[start]=0;w2[start]=0;num[start]=1;
	Dijkstra(start);
	str1="ROM";
	int end=getID(str1);
	printf("%d %d %d %d\n",num[end],dist[end],w1[end],w1[end]/w2[end]);
	cout<<name[start];
	stack<int> ans;
	while(path[end]!=-1){
		ans.push(end);
		end=path[end];
	}
	while(!ans.empty()){
		cout<<"->"<<name[ans.top()];
		ans.pop();
	}
	cout<<endl;
	return 0;
}

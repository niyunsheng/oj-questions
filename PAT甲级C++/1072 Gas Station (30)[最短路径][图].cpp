//最好把迪杰斯特拉算法写成函数，把邻接表等参数定义为全局变量
#include<iostream>
#include<vector>
using namespace std;
#define inf 0x3fffffff
struct node{
	int c;
	int len;
	node(int cc,int l):c(cc),len(l){}
};
int char2int(char* c,int n){
	int id=0,lo=0,st=0;
	if(c[0]=='G'){lo=1;st=n;}
	while(c[lo]!='\0'){
		id=id*10+c[lo]-'0';
		lo++;
	}
	return id+st;
}
int main(){
    //freopen("D:\\input.txt","r",stdin);
    int n,m,K,D;
    scanf("%d %d %d %d",&n,&m,&K,&D);
	char s1[5],s2[5];
	vector<vector<node>> grid(n+m+1);
	int c1,c2,t;
	//这里的格式转换错了，因为k的取值范围是1-1000，应写成函数递归处理得到其值
	for(int i=0;i<K;i++){
		scanf("%s %s %d",s1,s2,&t);
		c1=char2int(s1,n);
		c2=char2int(s2,n);
		grid[c1].push_back(node(c2,t));
		grid[c2].push_back(node(c1,t));
	}
	//单元最短路径：迪杰斯特拉算法
	vector<bool> vis(n+m+1,false);
	vector<int> dist(n+m+1,inf);
	//vector<int> path(n+m+1,-1);
	vector<int> mindist;
	int solution=0;//记录可行方案数
	int length=inf,minid,lengthsub=0,minsum=inf;//所有方案中最短路径及其序号,及离加气站最近的距离
	int mxlen,minlen,sumlen;//一个方案中的最长路径和最短路径、路径和
	for(int i=n+1;i<=n+m;i++){//依次查询m个加油站到各个城市的最短路径是否符合题意，
		fill(vis.begin(),vis.end(),false);
		fill(dist.begin(),dist.end(),inf);
		dist[i]=0;
		for(int j=0;j<n+m;j++){
			int id=-1,mind=inf;//最小节点
			for(int k=1;k<=n+m;k++){
				if(!vis[k]&&dist[k]!=inf){
					if(dist[k]<mind){mind=dist[k];id=k;}
				}
			}
			if(id==-1){goto loop;}
			vis[id]=true;
			for(int k=0;k<grid[id].size();k++){
				int c=grid[id][k].c,len=grid[id][k].len;
				if(!vis[c]&&dist[c]>dist[id]+len){
					dist[c]=dist[id]+len;
				}
			}
		}
		mxlen=0;minlen=inf;sumlen=0;
		for(int j=1;j<=n;j++){
			sumlen+=dist[j];
			if(dist[j]>mxlen)mxlen=dist[j];
			if(dist[j]<minlen)minlen=dist[j];
		}

		if(mxlen<=D){
			solution++;
			if(lengthsub<minlen){length=mxlen;minid=i;lengthsub=minlen;mindist=dist;minsum=sumlen;}
			else if(lengthsub==minlen&&minsum>sumlen){minid=i;lengthsub=minlen;mindist=dist;minsum=sumlen;}
		}
		loop:;
	}
	if(solution==0)printf("No Solution");
	else{
		printf("G%d\n",minid-n);
		printf("%d.0 %.1f",lengthsub,(float)minsum/n);
	}
	return 0;
}

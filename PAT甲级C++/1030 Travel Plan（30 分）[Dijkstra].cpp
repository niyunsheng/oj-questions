
#include<iostream>
#include<vector>
using namespace std;
#define inf 0x3fffffff


void printpath(int c2,vector<int>& path){
    if(path[c2]!=-1)
        printpath(path[c2],path);
    printf("%d ",c2);
}

struct node{
     int r,dist,cost;//可到达的下一个顶点和边权
     node(int rr,int dd,int cc):r(rr),dist(dd),cost(cc){}
};

int main(){
    //freopen("D:\\input.txt","r",stdin);
    int n,m,c1,c2;
    scanf("%d %d %d %d",&n,&m,&c1,&c2);
    vector<int> w(n,0);//所有前驱节点的第二维度和
    vector<bool> vis(n,false);
    vector<int> path(n,-1);
    vector<int> dist(n,inf);
    vector<vector<node>> grid(n);
    vector<int> num(n,0);//记录最短路径的数目

    int t1,t2,t3,t4;
    for(int i=0;i<m;i++){
        scanf("%d %d %d %d",&t1,&t2,&t3,&t4);
        grid[t1].push_back(node(t2,t3,t4));
        grid[t2].push_back(node(t1,t3,t4));
    }
    dist[c1]=0;num[c1]=1;
    for(int i=0;i<n;i++){//每次循环，添加进一个节点，由于令dist[c1]为0，而其他均为inf，首先进入的节点必为c1
        int id=-1,dis=inf;//下一个最近节点的id和距离
        for(int j=0;j<n;j++){
            if(!vis[j]&&dist[j]<dis){dis=dist[j];id=j;}
        }
        if(id==-1)return 0;//说明非连通图
        vis[id]=true;
        for(int j=0;j<grid[id].size();j++){
            int r=grid[id][j].r,d=grid[id][j].dist,c=grid[id][j].cost;
            if(!vis[r]&&d!=inf){

                if(dist[id]+d<dist[r]){
                    path[r]=id;
                    dist[r]=dist[id]+d;
                    w[r]=w[id]+c;
                    num[r]=num[id];
                }else if(dist[id]+d==dist[r]){
                    if(w[r]>w[id]+c){
                        w[r]=w[id]+c;
                        path[r]=id;
                    }

                    num[r]+=num[id];//找到相同长度的线路
                }
            }
        }
    }
    printpath(c2,path);
    printf("%d %d",dist[c2],w[c2]);
    return 0;
}

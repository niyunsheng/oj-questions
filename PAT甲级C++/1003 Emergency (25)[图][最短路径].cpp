/**
 * @Date:   2018-08-05
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-05
 */
 #include<iostream>
 #include<vector>
 using namespace std;
//这个题目出的真好，迪杰斯特拉算法的三种特殊情况，用到了两种
//三种特殊情况分别是增加点权、增加第二边权、增加最短路径的种数，基本的处理方法是用新的矩阵来存储信息
 //1003 Emergency (25)
 //单源最短路径问题：迪杰斯特拉算法，set(vis)、path、dist数组更新，用邻接表存储图
 struct node{
     int r,dist;//可到达的下一个顶点和边权
     node(int rr,int dd):r(rr),dist(dd){}
 };
 #define inf 0x3fffffff
 int main(){
     //freopen("D:\\CodeBlockSpace\\input.txt","r",stdin);
     int n,m,c1,c2;
     scanf("%d %d %d %d",&n,&m,&c1,&c2);
     vector<int> weight(n);//保留原始信息
     vector<int> w(n,0);//所有前驱节点的第二维度和
     vector<bool> vis(n,false);
     vector<int> path(n,-1);
     vector<int> dist(n,inf);
     vector<vector<node>> grid(n);
     vector<int> num(n,0);//记录最短路径的数目
     for(int i=0;i<n;i++){
         scanf("%d",&weight[i]);
     }
     int t1,t2,t3;
     for(int i=0;i<m;i++){
         scanf("%d %d %d",&t1,&t2,&t3);
         grid[t1].push_back(node(t2,t3));
         grid[t2].push_back(node(t1,t3));
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
             int r=grid[id][j].r,d=grid[id][j].dist;
             if(!vis[r]&&d!=inf){

                 if(dist[id]+d<dist[r]){//因为这里weight均为正值，所以，不另写分支判断相等
                     path[r]=id;
                     dist[r]=dist[id]+d;
                     w[r]=w[id]+weight[id];
                     num[r]=num[id];
                 }else if(dist[id]+d==dist[r]){
                     if(w[r]<w[id]+weight[id])
                         w[r]=w[id]+weight[id];
                     num[r]+=num[id];//找到相同长度的线路
                 }
             }
         }
     }
     printf("%d %d",num[c2],w[c2]+weight[c2]);
     return 0;
 }

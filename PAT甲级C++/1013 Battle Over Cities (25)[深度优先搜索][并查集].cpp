/**
 * @Date:   2018-08-05
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-05
 */
//求解连通域个数，两种方法，深度优先搜索、并查集（注意路径压缩，否则超时）
//方法1：深度优先搜索
 #include<iostream>
 #include<vector>
 #include"string.h"
 using namespace std;
 vector<vector<int>> grid(1001);//节点标号为1-N
 bool finded[1001];

 void DFS(int i){
     for(int j=0;j<grid[i].size();j++){
         if(!finded[grid[i][j]]){
             finded[grid[i][j]]=true;
             DFS(grid[i][j]);
         }
     }
 }
 int main(){
     //freopen("d:\\codeBlockSpace\\input.txt","r",stdin);
     int N,M,K;
     scanf("%d %d %d",&N,&M,&K);//N个城市，M条边，K次查询
     //方法1：深度优先搜索
     int c1,c2;
     for(int i=0;i<M;i++){
         scanf("%d %d",&c1,&c2);
         grid[c1].push_back(c2);
         grid[c2].push_back(c1);
     }

     int r;
     for(int i=0;i<K;i++){
         memset(finded,false,sizeof(finded));
         scanf("%d",&r);

         finded[r]=true;
         int sum=0;//记录连通域个数
         for(int j=1;j<=N;j++){
             if(!finded[j]){
                 sum++;
                 finded[j]=true;
                 DFS(j);
             }
         }
         printf("%d\n",sum-1);
     }
     return 0;
 }

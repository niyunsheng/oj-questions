/**
 * @Date:   2018-08-04
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-06
 */
//本题注意点：当需要统计层次时，用广度优先搜索最佳，在每层末尾加标志元素以判断层数
//其实也可以给每个节点增加层数变量，用一个数组即可实现，BFS的过程中设置层数，如果层数超限，就结束BFS
//用标志节点也是可行的
 #include<iostream>
 #include<vector>
 #include<queue>
 using namespace std;

 //1076 Forwards on Weibo (30)
int main(){
    //freopen("D:\\input.txt","r",stdin);
    int N,L;
    scanf("%d %d",&N,&L);
     //定义邻接表
    vector<vector<int>> grid(N+1);
    vector<bool> finded(N+1,false);
    int m,t;
    for(int i=1;i<=N;i++){
        scanf("%d",&m);
        for(int j=0;j<m;j++){
            scanf("%d",&t);
            grid[t].push_back(i);
        }
    }
    int K;scanf("%d",&K);//共K次查询
    for(int i=0;i<K;i++){
        int cur;scanf("%d",&cur);
        for(int j=0;j<N+1;j++)finded[j]=false;
        queue<int> q;//BFS队列
        int sum=0;//记录答案
        int level=0;
        q.push(cur);finded[cur]=true;
        q.push(0);//以0作为各层之间的标志位
        while(!q.empty()){
            cur=q.front();q.pop();
            if(cur==0){
                if(++level==L)break;
                q.push(0);
            }else{
                for(int k=0;k<grid[cur].size();k++){
                    if(!finded[grid[cur][k]]){
                        finded[grid[cur][k]]=true;
                        q.push(grid[cur][k]);
                        sum++;
                    }
                }
            }
        }
		printf("%d\n",sum);
    }
    return 0;
}

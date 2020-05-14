/**
 * @Date:   2018-08-15
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-15
 */
//LeetCode这里的代码不容易调试，超时的话输不出中间结果，而向量的初始话有不容易
//这里居然因为内层循环的j++，写成了i++导致内层循环跳不出来，这么小的错误也要编写输入输出调试很久，很不应该啊！
#define inf 0x7fffffff
class Solution {
public:
    //标准的迪杰斯特拉最短路径算法
    struct node{int id;int len;node(int ii,int ll):id(ii),len(ll){}};
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<node>> grid(N+1);
        for(int i=0;i<times.size();i++)
            grid[times[i][0]].push_back(node(times[i][1],times[i][2]));
        vector<int> dist(N+1,inf);
        vector<bool> vis(N+1,false);
        dist[K]=0;
        int mxlen=-1;//全局最大传播时间
        for(int i=0;i<N;i++){//每轮找到一个最近点，需要N轮
            int id=-1,len=inf;
            for(int j=1;j<=N;j++)
                if(!vis[j]&&dist[j]<len){len=dist[j];id=j;}
            //cout<<i<<" "<<id<<endl;
            if(id==-1){return -1;}
            vis[id]=true;
            if(dist[id]>mxlen)mxlen=dist[id];
            for(int j=0;j<grid[id].size();j++){
                int nxid=grid[id][j].id,nxlen=grid[id][j].len;
                if(!vis[nxid]&&dist[nxid]>dist[id]+nxlen)dist[nxid]=dist[id]+nxlen;
            }
        }
        return mxlen;
    }
};

/**
 * @Date:   2018-09-14
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-14
 */
//这个题目出的非常好，类似Dijkstra，但是思想又是BFS，和Dijkstra不同，和SPFA也有点像
//自己答案：DFS+剪枝
struct node{
    int id,len;
};
#define inf 0x3f3f3f3f
class Solution {
public:
    void DFS(int src,int dst,int K,int cost){
        for(int i=0;i<grid[src].size();i++){
            int nx=grid[src][i].id,len=grid[src][i].len;
            if(nx==dst){
                mincost=min(mincost,cost+len);
                continue;
            }
            if(K==0)continue;
            if(!vis[nx]&&cost+len<mincost){//这里加上剪枝才能过，注意：DFS必加剪枝
                vis[nx]=true;
                DFS(nx,dst,K-1,cost+len);
                vis[nx]=false;
            }
        }
    }
    vector<vector<node>> grid;
    vector<bool> vis;
    int mincost;
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        grid.resize(n);vis.resize(n);fill(vis.begin(),vis.end(),false);
        for(int i=0;i<flights.size();i++)
            grid[flights[i][0]].push_back({flights[i][1],flights[i][2]});

        mincost=inf;
        DFS(src,dst,K,0);
        if(mincost==inf)return -1;
        else return mincost;
    }
};
//方法二：最快答案：SPFA
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        int N = n;
        vector<vector<int>> edges(N+1,vector<int>(N+1,-1));
        for(auto e:flights) edges[e[0]][e[1]] = e[2];
        vector<int> dist(N+1,INT_MAX);
        dist [src] = 0;
        queue<int> q;
        q.push(src);
        int k = 0;
        while(!q.empty() && k <= K)
        {
            vector<bool>visited (N+1,false);
            int len = q.size();
            for(int i = 0;i < len;i++)
            {
                int u = q.front();
                q.pop();
                for(int v = 0; v <= N;v++)
                {

                    if(edges[u][v] != -1 && dist[u]+edges[u][v] < dist[v])
                    {
                        if(k == K && v != dst) continue;
                        if(!visited[v])
                        {
                            visited[v] = true;
                            q.push(v);
                        }
                        dist[v] = dist[u]+edges[u][v];
                    }
                }
            }
            k++;
        }

        return dist[dst] == INT_MAX ? -1:dist[dst];

    }
};
//方法三：用bellmanford循环K次
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<int> dp(n, 1e9);
        dp[src] = 0;
        for (int i = 0; i <= K; ++i) {
            vector<int> t = dp;
            for (auto x : flights) {
                t[x[1]] = min(t[x[1]], dp[x[0]] + x[2]);
            }
            dp = t;
        }
        return (dp[dst] >= 1e9) ? -1 : dp[dst];
    }
};
//方法四：dp
class Solution {
public:
	int findCheapestPrice( int n, vector<vector<int>>& flights, int src, int dst, int K ) {
		vector<vector<int>> dp( K + 2, vector<int>( n, 1e7 ) );
		dp[0][src] = 0;
		for (int i = 1; i <= K + 1; i++) {
			dp[i][src] = 0;
			for (auto x : flights) {
				dp[i][x[1]] = min( dp[i][x[1]], dp[i - 1][x[0]] + x[2] );
			}
		}
		if (dp[K + 1][dst] == 1e7)
			return -1;
		return dp[K + 1][dst];
	}
};

/**
 * @Date:   2018-08-20
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-20
 */
//意识到对边进行遍历，遍历的过程中通过标记来区分不同的结合即可。
class Solution {
public:
    bool DFS(int r,vector<int>& vis,vector<vector<int>>& graph){
        bool flag=true;
        for(int i=0;i<graph[r].size();i++){
            if(vis[graph[r][i]]==0){
                vis[graph[r][i]]=-vis[r];
                flag&=DFS(graph[r][i],vis,graph);
            }else
                if(vis[graph[r][i]]==vis[r]){return false;}
        }
        return flag;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,0);//0表示未发现，1，-1分别表示两个集合
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                vis[i]=1;
                if(!DFS(i,vis,graph))return false;
            }
        }
        return true;
    }
};

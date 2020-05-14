/**
 * @Date:   2018-08-20
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-21
 */
class Solution {
public:
    //仿照最小生成树的kruskal算法
    vector<int> fa;
    void init(int n){
        fa.resize(n+1);
        for(int i=0;i<=n;i++)
            fa[i]=i;
    }
    int findfa(int r){
        return r==fa[r]?r:(fa[r]=findfa(fa[r]));//路径压缩
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        init(n);
        for(int i=0;i<n;i++){
            int f1=findfa(edges[i][0]),f2=findfa(edges[i][1]);
            if(f1!=f2){
                fa[f1]=f2;
            }else{
                return edges[i];
            }
        }
    }
};

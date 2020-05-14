class Solution {
public:
    //典型拓扑排序
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> grid(numCourses);
        vector<int> inDegree(numCourses,0);
        for(int i=0;i<prerequisites.size();i++){
            grid[prerequisites[i].first].push_back(prerequisites[i].second);
            inDegree[prerequisites[i].second]++;
        }
        queue<int> q;
        int cur,cnt=0;
        for(int i=0;i<numCourses;i++){
            if(inDegree[i]==0){
                q.push(i);
                cnt++;
            }
        }

        while(!q.empty()){
            cur=q.front();q.pop();
            for(int i=0;i<grid[cur].size();i++){
                inDegree[grid[cur][i]]--;
                if(inDegree[grid[cur][i]]==0){
                    q.push(grid[cur][i]);
                    cnt++;
                }
            }
        }
        if(cnt!=numCourses)
            return false;
        return true;
    }
};

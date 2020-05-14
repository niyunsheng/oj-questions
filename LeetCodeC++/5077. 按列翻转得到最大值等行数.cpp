//统计该行出现的次数，然后有多少行的模式形同，模式相同分为两种情况，可能是反转后全为0或者全为1
class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        map<string,int> tmap;
        int n=matrix.size(),m=matrix[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            string t1="",t2="";
            for(int j=0;j<m;j++){
                t1+=('0'+matrix[i][j]);
                t2+=('0'+1-matrix[i][j]);
            }
            if(tmap.count(t1)!=0)tmap[t1]++;
            else tmap[t1]=1;
            if(tmap.count(t2)!=0)tmap[t2]++;
            else tmap[t2]=1;
            ans=max(ans,tmap[t1]);
            ans=max(ans,tmap[t2]);
        }
        return ans;
    }
};

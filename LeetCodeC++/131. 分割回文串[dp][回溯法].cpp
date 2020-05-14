/**
 * @Date:   2018-08-30
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-30
 */
//思路：首先构造dp数组，dp[i][j]表示i-j是回文串，然后DFS回溯法输出结果
class Solution {
public:
    vector<string> tmp;
    vector<vector<string>> ans;
    void DFS(int lo,int hi,vector<vector<int> >& dp,string& s){
        if(lo>=hi){
            ans.push_back(tmp);
            return;
        }
        for(int r=lo;r<hi;r++){
            if(dp[lo][r]){
                tmp.push_back(s.substr(lo,r-lo+1));
                DFS(r+1,hi,dp,s);
                tmp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n=s.length();
        vector<vector<int> > dp(n,vector<int>(n,0));
        dp[0][0]=1;
        for(int i=1;i<n;i++){
            dp[i][i]=1;
            if(s[i-1]==s[i])dp[i-1][i]=1;
        }
        for(int r=2;r<n;r++){
            for(int i=0;i+r<n;i++){
                if(s[i]==s[i+r]&&dp[i+1][i+r-1]==1)dp[i][i+r]=1;
            }
        }
        DFS(0,n,dp,s);
        return ans;
    }
};

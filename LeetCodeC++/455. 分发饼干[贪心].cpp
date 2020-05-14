/**
 * @Date:   2018-08-16
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-16
 */
//455. 分发饼干
//贪心
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int gi=0,cnt=0;
        for(int si=0;gi<g.size()&&si<s.size();si++)
            if(s[si]>=g[gi]){cnt++;gi++;}
        return cnt;
    }
};

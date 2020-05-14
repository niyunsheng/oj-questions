//思路：一次遍历即可。对于A[i]+i，当然是越大越好，随着往后更新j的值，保存的A[i]+i的最大值也要随之更新。
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int res=-1;
        int max_i=A[0]+0;
        for(int j=1;j<A.size();j++){
            res=max(res,A[j]-j+max_i);
            max_i=max(max_i,A[j]+j);
        }
        return res;
    }
};

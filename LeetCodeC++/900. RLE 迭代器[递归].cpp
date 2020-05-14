/**
 * @Date:   2018-09-09
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-09
 */
class RLEIterator {
public:
    vector<int> dp;
    int len,lo;
    RLEIterator(vector<int> A) {
        len=A.size();lo=0;
        for(int i=0;i<len;i++)dp.push_back(A[i]);
    }

    int next(int n) {
        if(lo>=len)return -1;
        if(dp[lo]>=n){dp[lo]-=n;return dp[lo+1];}
        lo+=2;
        return next(n-dp[lo-2]);
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator obj = new RLEIterator(A);
 * int param_1 = obj.next(n);
 */

/**
 * @Date:   2018-09-09
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-09
 */
//先将数字存入numD,记录exp[i]=rank^i,dp[i]表示D中有几个数字小于num[i]，vis[i]表示D中有数字等于num[i]
class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        int sum=0,t=N,R=1,rank=D.size();
        vector<int> num;//exp[i]=rank^i,dp[i]表示D中有几个数字小于num[i]
        vector<int> numD(D.size());
        for(int i=0;i<D.size();i++)numD[i]=D[i][0]-'0';
        while(t>0){num.push_back(t%10);t/=10;}
        int len=num.size();
        vector<int> _exp(len),dp(len);
        vector<bool> vis(len,false);//vis[i]表示D中有数字等于num[i]
        for(int i=0;i<num.size();i++){
            _exp[i]=R;R*=rank;
            int lo=0;
            while(lo<numD.size()&&numD[lo]<num[i])lo++;
            dp[i]=lo;
            if(lo<numD.size()&&numD[lo]==num[i])vis[i]=true;
        }
        for(int i=1;i<len;i++)sum+=_exp[i];
        for(int i=len-1;i>=0;i--){
            sum+=dp[i]*_exp[i];
            if(!vis[i])break;
            if(i==0&&vis[i])sum++;
        }
        return sum;
    }
};

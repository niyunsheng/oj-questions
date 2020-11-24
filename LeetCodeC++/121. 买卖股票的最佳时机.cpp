class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int P=0, lowest=0x7fffffff;
        for(int i=0;i<prices.size();i++){
            P = max(P,prices[i]-lowest);
            lowest = min(prices[i], lowest);
            //printf("%d %d\n",dp[i],prices[i]);
        }
        return P;
    }
};
/**
 * @Date:   2018-09-09
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-09
 */
class StockSpanner {
public:
    vector<int> v,dp;
    StockSpanner() {

        v.push_back(0x7fffffff);
        dp.push_back(1);
    }

    int next(int price) {
        v.push_back(price);
        //cout<<v.size();
        int i=v.size()-2;
        int tmp=v[v.size()-1];

        while(i>=0){

            if(v[i]<=tmp){i=i-dp[i];}//cout<<i<<" "<<v[i]<<" "<<dp[i]<<endl;
            else break;
        }
        dp.push_back(v.size()-i-1);
        //cout<<v.size()-1<<" "<<dp[v.size()-1]<<endl;
        return v.size()-i-1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */

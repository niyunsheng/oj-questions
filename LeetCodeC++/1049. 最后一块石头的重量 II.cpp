//问题可以转换为分成两堆，然后两堆之差的最小值为多少。我们可以将此问题化为01背包问题，共30个不到的物品，总的重量作为背包的大小，具体见代码。
class Solution{
public:
    int lastStoneWeightII(vector<int>& A){
        //01背包问题
        int sum = accumulate(A.begin(),A.end(),0);
        cout<<sum<<endl;
        int n=A.size()+1,m=sum/2+1;
        vector<vector<int> > dp(n,vector<int>(m,0));

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(j>=A[i-1])dp[i][j]=max(dp[i-1][j-A[i-1]]+A[i-1],dp[i-1][j]);
                else dp[i][j]=dp[i-1][j];
                //printf("dp[%d][%d]=%d ",i,j,dp[i][j]);
            }
            //printf("\n");
        }
        for(int j=m-1;j>=0;j--){
            if(dp[n-1][j]==j)return sum-2*j;
        }

        return 0;
    }
};

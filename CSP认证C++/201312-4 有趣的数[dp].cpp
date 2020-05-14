/**
 * @Date:   2018-08-22
 * @Email:  ni-ys13@qq.com
 */
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
using namespace std;
/*
	当然还是dp了，不过，此前做过的题目当中，没有按照类似的根据设定状态转移的dp
	dp[i][j]表示填入第i个数字之后，集合的状态为j时的种类
	集合的状态共有六种(2)/(0,2)/(2,3)/(0,1,2)/(0,2,3)/(0,1,2,3)
	将这六个状态依次编号为0-5
	根据题意可以画出状态转移图，初始状态dp[1][0]=1;dp[1][1]=dp[1][2]=……dp[1][5]=0
	则最后输出的结果是dp[n][5]
	状态转移方程为(画出状态转化图后很容易写出来)
	dp[i][0]=dp[i-1][0];
	dp[i][1]=dp[i-1][1]*2+dp[i-1][0];
	dp[i][2]=dp[i-1][2]+dp[i-1][0];
	dp[i][3]=dp[i-1][3]*2+dp[i-1][1];
	dp[i][4]=dp[i-1][4]*2+dp[i-1][1]+dp[i-1][2];
	dp[i][5]=dp[i-1][5]+dp[i-1][3]+dp[i-1][4];
	注意取模即可
*/
#define M 1000000007
int main() {
	//freopen("d:\\input.txt","r",stdin);
	int n,cnt=0;
	long long dp[1005][6];
	dp[1][0]=1;dp[1][1]=dp[1][2]=dp[1][3]=dp[1][4]=dp[1][5]=0;
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		dp[i][0]=dp[i-1][0];
		dp[i][1]=(dp[i-1][1]*2+dp[i-1][0])%M;
		dp[i][2]=(dp[i-1][2]+dp[i-1][0])%M;
		dp[i][3]=(dp[i-1][3]*2+dp[i-1][1])%M;
		dp[i][4]=(dp[i-1][4]*2+dp[i-1][1]+dp[i-1][2])%M;
		dp[i][5]=(dp[i-1][5]*2+dp[i-1][3]+dp[i-1][4])%M;
	}
	printf("%d\n",dp[n][5]);
	return 0;
}

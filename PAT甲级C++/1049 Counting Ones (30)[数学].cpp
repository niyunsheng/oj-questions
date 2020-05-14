/**
 * @Date:   2018-08-10
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-29
 */
//一轮复习的时候，自主写出了和柳神一样的算法，每次枚举一位数组，加上该位置上1的个数
int main(){
	//freopen("d:\\input.txt","r",stdin);
	int n,div=1;
	long long cnt=0;
	cin>>n;
	//srand(time(NULL));n=rand();
	while(1){
		int hi=n/(10*div)+1,lo=n%div+1;
		if(n%(div*10)/div==0)cnt+=(hi-1)*div;
		else if(n%(div*10)/div==1)cnt+=lo+(hi-1)*div;
		else cnt+=hi*div;
		if(hi==1)break;
		div*=10;
	}
	printf("%lld\n",cnt);
	return 0;
}
//本以为自己的方法已经很快了，但是看了晴神的，还有有差距啊！
/*晴神法：pow[i]表示10^i，但是没有直接先求出数组，而是在从低位到高位计算的过程中不断乘10
		从低位到高位处理，比如1234
		第k位时，记left为k位的高位所代表的数字，now为k位的数字，right为k位的低位的数字
			比如k=2时，now=3，left=12，right=4
		根据k位值分为三种情况：
			now==0;sum+=left*pow[i]
			now==1;sum+=left*pow[i]+right+1;
			now>=2;sum+=(left+1)*pow[i];
//祭上柳神代码，这个方法有必要思考下
#include <iostream>
using namespace std;
int main() {
    int n, left = 0, right = 0, a = 1, now = 1, ans = 0;
    scanf("%d", &n);
    while(n / a) {
        left = n / (a * 10), now = n / a % 10, right = n % a;
        if(now == 0) ans += left * a;
        else if(now == 1) ans += left * a + right + 1;
        else ans += (left + 1) * a;
        a = a * 10;
    }
    printf("%d", ans);
    return 0;
}
*/
#include<iostream>
#include<vector>
using namespace std;
//1049 Counting Ones (30)
/*思路：描述很简单，但是枚举的话肯定超时，得用数学方法。
第一步：用数组记录0-9；0-99；0-999中1的个数
		dp[i]表示i位数中1的个数，dp[0]=0;dp[1]=1;dp[i+1]=dp[i]*10+10^i
第二步：比如1234=1000+200+30+4，其中1的个数为(1*dp[3]+min(1000,1000-999))+(2*dp[2]+min(100,200-99))+(3*dp[1]+min(10,30-9))+(4*dp[0]+min(1,4-1+1))
		这样就可以写程序了
		考虑有欠缺，比如考虑千位1的个数应该为(1*dp[3]+min(1000,1234-999))，这样就对了
		所以，这个题目应该先计算n的位数，然后从高位往低位计算
*/
int main(){
	//freopen("d:\\input.txt","r",stdin);
	int n;
	//while(1){
	scanf("%d",&n);
	//n最大是10位数，pow[i]=10^i;dp[i]表示i位数中1的个数，最高位运算用到dp[9]和pow[9]，int型可以存储，但是计算1的个数得用longlong，方便都用longlong算了
	long long pow[10],dp[10]={0};
	pow[0]=1;dp[0]=0;
	for(int i=1;i<10;i++){
		pow[i]=pow[i-1]*10;
		dp[i]=dp[i-1]*10+pow[i-1];
	}
	//先统计n的位数r
	int t=n,r=0;
	while(t>0){
		t/=10;r++;
	}
	//计算n中1的个数，从高位到低位
	long long sum=0;
	while(r--){
		t=n/pow[r];//t用来存当前位置的数
		if(t==0)continue;
		sum+=t*dp[r]+min(pow[r],n-pow[r]+1);
		n=n%pow[r];
	}
	printf("%lld\n",sum);
	//}
	return 0;
}

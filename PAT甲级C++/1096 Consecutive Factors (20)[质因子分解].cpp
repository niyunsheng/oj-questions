/**
 * @Date:   2018-08-10
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-30
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//1096 Consecutive Factors (20)
//思路：依次遍历，开方剪枝，注意边界情况（n为质数时，n为完全平方数，不如4,5），将最大的序列前后的值保存比较更新
//上面这个思路不对，是把n分解后的最长的序列，不是其因子的最长序列，两者不同，所以，该因子被选中后，n要除以该因子
//这个题目告诉我们，提交之前自己写几组测试数据测试下，是很重要的，测试数据能够快速的定位错误
int main(){
	//freopen("D:\\input.txt","r",stdin);
	//全部定义为longlong最省事
	long long n;
	scanf("%lld",&n);
	long long savelo=n,savehi=n+1;
	long long lo=2,hi=2,cnt=0;//最长因子序列的前后界[lo,hi)和长度

	//因为n不会被除自己以外的任何大于sqrt(n)的数整除，所以这里可以剪枝，不剪枝则最后一个算例超时
	while(lo*lo<=n){
		long long tmp=n;
		while(tmp%hi==0){tmp/=hi;hi++;}
		if(hi-lo>cnt){
			cnt=hi-lo;
			savelo=lo;savehi=hi;
		}
		lo++;hi=lo;
	}
	if(cnt==0)cnt=1;
	printf("%d\n",cnt);
	printf("%lld",savelo);
	for(long long i=savelo+1;i<savehi;i++)
		printf("*%lld",i);
	printf("\n");
	return 0;
}

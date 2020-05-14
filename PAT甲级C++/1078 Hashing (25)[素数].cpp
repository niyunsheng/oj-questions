/**
 * @Date:   2018-08-10
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-10
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//1078 Hashing (25)
/*思路：首先你得知道hashing的二次方试探法是怎么解决冲突的.二次方试探法：hash(n)=n%k->hash(n+1*1)->hash(n+2*2)
	1.找到第一个大的质数
	2.根据散列来模拟，问题，如何判断是永远冲突还是还没到？暂时先给定个最大散列次数吧
	理论：若装填因子小于50%，则平方试探必然可以找到空桶，可以将试探的次数上限设置为M，即取模的质数

	!!!###注意二次方试探法可以有两个方向，而本题表明了只考虑正向
	可以证明：如果j从0-(M-1)都无法找到位置，那么，就不可能找到位置，即循环节为M。此结论很容易证明。
*/
//答案虽然对了，但是有没有判断是否一定冲突的方法呢？
bool isPrime(int n){
	//这里边界条件写上，1可不是素数,
	//原来错误的出处是在这里，注意想筛选掉素数，可别把2也筛掉了后面i*i<=n;不要把等号忘记了
	if(n==2)return true;
	if(n%2==0||n<2)return false;
	for(long long i=3;i*i<=n;i+=2){
		if(n%i==0)return false;
	}
	return true;
}
int main(){
	//freopen("D:\\codeBlockSpace\\input.txt","r",stdin);
	int Msize,n;
	scanf("%d %d",&Msize,&n);
	while(!isPrime(Msize))Msize++;
	vector<bool> vis(Msize,false);
	int t;
	vector<int> ans(Msize);
	for(int i=0;i<n;i++){
		scanf("%d",&t);
		int t1=t,j=1,cnt=0;
		while(vis[t1%Msize]){t1=t+j*j;j++;cnt++;if(cnt==Msize)break;}
		if(cnt==Msize)ans[i]=-1;
		else{
			vis[t1%Msize]=true;
			ans[i]=t1%Msize;
		}
	}
	printf("%d",ans[0]);
	for(int i=1;i<n;i++){
		if(ans[i]==-1)printf(" -");
		else printf(" %d",ans[i]);
	}
	return 0;
}

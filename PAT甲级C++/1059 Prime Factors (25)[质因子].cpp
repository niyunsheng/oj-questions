//int可能不满足范围，要用long long
//特别注意输入的多样性，如果有一个算例不过，很可能是输入的特殊值自己没有考虑到，比如输入1
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
//1059 Prime Factors (25)
//思路，对于质数，看其是不是n的质因子，是的话就存入map，key是该质因子，value是其出现的次数，最后输出时遍历map即可
//当然，这里不用map的话，可以用两个数组，一个存放质因子，一个存放质因子的个数
//===注意，对于这种可能超范围的题目，毫不犹豫都用long long，快捷方式#define long long ll;
bool isPrime(ll n){
	if(n==2)return true;
	if(n%2==0||n<2)return false;
	for(ll i=3;i*i<n;i++){
		if(n%i==0)return false;
	}
	return true;
}
int main(){
	//freopen("D:\\codeBlockSpace\\input.txt","r",stdin);
	map<ll,ll> hashtable;
	ll n;
	scanf("%lld",&n);
	//单独判断n=1的情况
	if(n==1){printf("1=1");return 0;}
	ll saveN=n;
	for(ll i=2;i*i<=n;i++){
		if(isPrime(i)){
			while(n%i==0){
				n/=i;
				if(hashtable.count(i)==0)hashtable[i]=1;
				else hashtable[i]++;
			}

		}
	}
	//加上下面这句，就可以不用单独判断质数的情况，而且，因为大雨sqrt(n)的质因子最多只有一个，这里也把这种情况涵盖了
	if(n>1)hashtable[n]=1;
	map<ll,ll>::iterator it=hashtable.begin();
	if(it->second==1)printf("%lld=%lld",saveN,it->first);
	else printf("%lld=%lld^%lld",saveN,it->first,it->second);
	it++;
	for(;it!=hashtable.end();it++){
		if(it->second==1)printf("*%lld",it->first);
		else printf("*%lld^%lld",it->first,it->second);
	}
	return 0;
}

/**
 * @Date:   2018-08-31
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-31
 */
#include<iostream>
#include<cstring>
using namespace std;

#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
int getint() {int x;scanf("%d",&x);return x;}
#define MAX 505
typedef long long ll;
ll pow(int t){
	ll ans=1;
	while(t--){
		ans*=10;
	}
	return ans;
}
int main(){
    //freopen("d:\\input.txt","r",stdin);
	int N;
	cin>>N;
	char str[40];
	ll t,hi,lo,p;
	_for(i,0,N){
		scanf("%s",str);
		int len=strlen(str);
		ll p=pow(len/2);
		sscanf(str,"%lld",&t);
		hi=t/p;
		lo=t%p;
		if(hi*lo!=0&&t%(hi*lo)==0)printf("Yes\n");
		else printf("No\n");
	}
    return 0;
}

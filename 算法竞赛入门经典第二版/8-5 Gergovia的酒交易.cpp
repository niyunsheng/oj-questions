
#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <assert.h>

using namespace std;

#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
#define inf 0x3fffffff
#define pb push_back
typedef long long LL;
typedef pair<int,int> PII;
#define M 1000000007
#define N 5005


int main(int argc, char** argv) {
//	freopen("d:\\input.txt","r",stdin);
	int n;
	while(1){
		scanf("%d",&n);
		if(n==0)break;
		LL ans=0,t,last=0;
		_for(i,0,n){
			scanf("%lld",&t);
			ans+=abs(last);
			last+=t;
		}
		printf("%lld\n",ans);

	}
	return 0;
}

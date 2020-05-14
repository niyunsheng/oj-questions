//题解：先求出从第一个珠子左侧断开的逆序对数。每次将断开的位置向右移一格，那么在最左边的那个珠子会变成最右边,的那个珠子，那么逆序对会减去比他小的数字数，再加上比他大的数字数。
//自己初始的算法只是注意到了逆序对更新的O(n)方法，却没有观察到上述结论

//用mergeSort计算逆序对将代码的复杂度降到了nlogn，解决了超时问题，但是算例一组也没通过，可能是程序哪里的逻辑还是错的。

#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <stack>

using namespace std;

#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
#define inf 0x3fffffff
#define pb push_back
typedef long long LL;
#define M 1000000007
#define N 200005


LL r,y,g,n,k,t;
LL ans;

int main(int argc, char** argv) {
//	freopen("d:\\input.txt","r",stdin);
	scanf("%lld %lld %lld",&r,&y,&g);
	cin>>n;
	ans=0;
	_for(i,0,n){
		scanf("%lld %lld",&k,&t);
		switch(k){
			case 0:
				ans+=t;break;
			case 1:
				ans+=t;break;
			case 2:
				ans+=t+r;break;
			case 3:
				break;
		}
	}
	cout<<ans<<endl;
	return 0;
}

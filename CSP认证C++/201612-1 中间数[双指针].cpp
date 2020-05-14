/**
 * @Date:   2018-09-09
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-09
 */
//排序之后看中间数是否满足题意
#include<cstdio>
#include<iostream>
#include<set>
#include<vector>
#include<map>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

#define MAXN 1005
#define INF 0x7fffffff
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)

int main(){
	//freopen("d:\\input.txt","r",stdin);
	int N,t;
	cin>>N;
	vector<int> v(N);
	_for(i,0,N){
		scanf("%d",&v[i]);
	}
	sort(v.begin(),v.end());
	int lo=N/2,hi=N/2;
	while(lo>=0&&v[lo]==v[N/2])lo--;
	while(hi<N&&v[hi]==v[N/2])hi++;
	//printf("lo=%d hi=%d\n",lo,hi);
	if(lo+1==N-hi)printf("%d\n",v[N/2]);
	else printf("-1\n");
	return 0;
}

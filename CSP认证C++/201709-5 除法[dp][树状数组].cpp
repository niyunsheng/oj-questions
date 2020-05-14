/**
 * @Date:   2018-08-25
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-25
 */
#include<iostream>
#include<sstream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<ctime>
#include<algorithm>
using namespace std;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
#define lowbit(i) (i&(-i))

int n;
int  A[100005];//开始时把这里也定义为long long类型，所以最后一个算例过不了，只能得90
long long C[100005];
//A[x]加上v
void updata(int x,int v){
	if(v==0)return;
	for(int i=x;i<n+1;i+=lowbit(i)){
		C[i]+=v;
	}
}
//计算A[1]-A[x]的和
long long getsum(int x){
	long long sum=0;
	for(int i=x;i>0;i-=lowbit(i)){
		sum+=C[i];
	}
	return sum;
}

int main() {
	//freopen("D:\\input.txt","r",stdin);
	int m,opt;
	scanf("%d %d",&n,&m);
	memset(C,0,sizeof(C));
	//预处理，生成树状数组
	_for(i,1,n+1){scanf("%d",&A[i]);updata(i,A[i]);}

	//在线查询
	int l,r,v;
	_for(i,0,m){
		scanf("%d",&opt);
		if(opt==1){
			scanf("%d %d %d",&l,&r,&v);//本来50分
			if(v==1)continue;//加这一行优化，80分
			_for(j,l,r+1){
				if(A[j]>=v&&A[j]%v==0){//加上A[i]>=v90分
					updata(j,A[j]/v-A[j]);
					A[j]/=v;
				}
			}
		}else{
			scanf("%d %d",&l,&r);
			printf("%lld\n",getsum(r)-getsum(l-1));
		}
	}
	return 0;
}

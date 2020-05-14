//无难度，但自己要增加熟练度
#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>

using namespace std;

typedef long long LL;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
#define inf 0x3fffffff
#define MAXN 1005

int L,K;
char num[MAXN];

bool isPrime(LL x){
	if(x==1||x==2)return true;
	LL r=2;
	while(r*r<=x){
		if(x%r==0)return false;
		r++;
	}
	return true;
}

int main(){
//	freopen("d:\\input.txt","r",stdin);
	scanf("%d %d",&L,&K);
	scanf("%s",num);

	LL x=0,y=10;
	//初始化
	if(K-1<L){
		x=num[0]-'0';
		_for(i,1,K){
			x*=10;y*=10;
			x+=(int)(num[i]-'0');
		}
	}
//	printf("%d %d\n",x,y);

	for(int i=0;i+K<=L;i++){
		if(isPrime(x)){
			_for(j,0,K)printf("%c",num[i+j]);
			return 0;
		}else if(i+K<L){
			//更新x的值
			x*=10;x%=y;
			x+=num[i+K]-'0';
		}
	}
	printf("404");
	return 0;
}

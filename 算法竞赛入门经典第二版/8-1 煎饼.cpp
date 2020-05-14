
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

using namespace std;

#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
#define inf 0x3fffffff
#define pb push_back
typedef long long LL;
#define M 1000000007
#define N 1000005

int vec[50],sorted[50];
int n=0;
bool readNum(){//读取所有的煎饼值
	n=0;vec[n]=0;
	while(1){
		char c;
		if(scanf("%c",&c)==EOF)return false;
		if(c=='\n'){
			n++;
			return true;
		}
		if(isdigit(c)){
			vec[n]*=10;
			vec[n]+=c-'0';
		}else if(c==' '){
			n++;
			vec[n]=0;
		}
	}
	return false;
}

int main(int argc, char** argv) {
//	freopen("d:\\input.txt","r",stdin);
	while(readNum()){
		_for(i,0,n)sorted[i]=vec[i];
		_for(i,0,n){
			printf("%d ",sorted[i]);
		}
		printf("\n");
		sort(sorted,sorted+n);
		int r=n-1;
		while(1){
			if(r==0)break;
			if(sorted[r]==vec[r]){
				r--;
			}else{
				int t=r-1;
				while(vec[t]!=sorted[r])t--;
				if(t!=0){
					printf("%d ",n-t);//将该点翻到顶点
					reverse(vec,vec+t+1);
				}
				//将顶点翻到该位置
				printf("%d ",n-r);
				reverse(vec,vec+r+1);
			}
		}
		printf("0\n");

	}
	return 0;
}

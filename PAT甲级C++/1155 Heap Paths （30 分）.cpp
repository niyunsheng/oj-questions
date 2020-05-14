//没见过30分题如此简单
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
#define MAXN 10005

int N;
vector<int> vec(MAXN);

bool f1,f2=true;//f2为true表示这是一个堆，f1为true表示大顶堆

#define lc(x) (2*x+1)
#define rc(x) (2*x+2)
#define p(x) ((x-1)/2)

vector<int> path;

void travel(int x){
	if(x!=0){
		if(f2){
			if(f1){
				if(vec[p(x)]<vec[x])f2=false;
			}else{
				if(vec[p(x)]>vec[x])f2=false;
			}
		}
	}
	path.push_back(vec[x]);
	if(rc(x)<N){
		travel(rc(x));
		travel(lc(x));
	}else if(lc(x)<N){
		travel(lc(x));
	}else{
		printf("%d",path[0]);
		_for(i,1,path.size())printf(" %d",path[i]);
		printf("\n");
	}
	path.pop_back();
}

int main(){
//	freopen("d:\\input.txt","r",stdin);
	scanf("%d",&N);

	_for(i,0,N){
		scanf("%d",&vec[i]);
	}

	if(vec[0]>vec[0]||vec[0]>vec[2])f1=true;
	else f1=false;

	travel(0);

	if(f2){
		if(f1)printf("Max Heap\n");
		else printf("Min Heap\n");
	}else{
		printf("Not Heap\n");
	}
	return 0;
}

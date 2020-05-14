
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
struct node{
	int first,second;
	int id;
	int pos;
};
bool cmp1(node a,node b){
	if(a.first!=b.first){
		return a.first<b.first;
	}else{
		return a.second<b.second;
	}
}

bool cmp2(node a,node b){
	return a.id<b.id;
}

vector<node> v1(N),v2(N); //保存行、列
int n=0,x1,y1,x2,y2;

bool fun(vector<node>& v){
	sort(v.begin(),v.begin()+n,cmp1);
//	_for(i,0,n){
//		printf("%d %d %d\n",v[i].id,v[i].first,v[i].second);
//	}
	int threshhold=0;
	bool flag=true;
	_for(i,0,n){
		if(v[i].second>=threshhold){
			threshhold=max(threshhold,v[i].first)+1;
			v[i].pos=threshhold-1;
		}else{
			flag=false;break;
		}
//		printf("%d %d %d\n",v[i].first,v[i].second,a[i]);
	}
	return flag;
}

int main(int argc, char** argv) {
//	freopen("d:\\input.txt","r",stdin);
	while(1){
		scanf("%d",&n);
		if(n==0)break;
		_for(i,0,n){
			scanf("%d %d %d %d",&v1[i].first,&v2[i].first,&v1[i].second,&v2[i].second);
			v1[i].id=v2[i].id=i;
		}
		if(fun(v1)&&fun(v2)){
			sort(v1.begin(),v1.begin()+n,cmp2);
			sort(v2.begin(),v2.begin()+n,cmp2);
			_for(i,0,n){
				printf("%d %d\n",v1[i].pos,v2[i].pos);
			}
		}else{
			printf("IMPOSSIBLE\n");
		}
	}
	return 0;
}

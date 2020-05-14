//没有难度
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

int N,M,Q;
vector<pair<int,int> > edge(MAXN);
vector<int> vertex(MAXN);

int main(){
//	freopen("d:\\input.txt","r",stdin);
	scanf("%d %d",&N,&M);

	_for(i,0,M){
		scanf("%d %d",&edge[i].first,&edge[i].second);
	}

	scanf("%d",&Q);
	_for(i,0,Q){
		set<int> s;
		_for(j,0,N){
			scanf("%d",&vertex[j]);
			s.insert(vertex[j]);
		}
		bool flag=true;
		_for(j,0,M){
			if(vertex[edge[j].first]==vertex[edge[j].second]){
				printf("No\n");
				flag=false;
				break;
			}
		}
		if(flag){
			printf("%d-coloring\n",s.size());
		}
	}
	return 0;
}

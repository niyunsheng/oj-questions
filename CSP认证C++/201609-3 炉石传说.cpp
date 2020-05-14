/**
 * @Date:   2018-09-09
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-09
 */
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

//201609-3 炉石传说
//没有AC，答案错误，70分
#define MAXN 1005
#define INF 0x7fffffff
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
int getint(){int x;scanf("%d",&x);return x;}
int N;

char commd[10];
struct node{
	int Att,Life;//分别表示攻击力，生命值
	node(int a,int l):Att(a),Life(l){}
};
vector<node> role[2];
int main(){
	//freopen("d:\\input.txt","r",stdin);
	N=getint();
	int U[2]={30,30};
	int flag=0;//先手
	_for(i,0,N){
		scanf("%s",commd);
		if(commd[0]=='e'){
			flag=1-flag;
			continue;
		}
		if(commd[0]=='s'){
			int r,t1,t2;
			scanf("%d %d %d",&r,&t1,&t2);
			r--;
			if(r>=role[flag].size())role[flag].push_back(node(t1,t2));
			else role[flag].insert(role[flag].begin()+r,node(t1,t2));
		}else{
			int t1,t2;
			scanf("%d %d",&t1,&t2);
			if(t2==0){
				U[1-flag]-=role[flag][t1].Att;
				continue;
			}
			t1--;t2--;
			role[flag][t1].Life-=role[1-flag][t2].Att;
			role[1-flag][t2].Life-=role[flag][t1].Att;
			if(role[flag][t1].Life<=0)role[flag].erase(role[flag].begin()+t1);
			if(role[1-flag][t2].Life<=0)role[1-flag].erase(role[1-flag].begin()+t2);
		}
	}
	if(U[0]<=0)printf("-1\n");
	else if(U[1]<=0)printf("1\n");
	else printf("0\n");

	_for(j,0,2){
		printf("%d\n",U[j]);
		printf("%d",role[j].size());
		_for(i,0,role[j].size())printf(" %d",role[j][i].Life);
		printf("\n");
	}

	return 0;
}

/**
 * @Date:   2018-09-07
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-07
 */

 //这个题目的思想很好，要注意到各个团队的成员始终是排在一起的，所以，建立各个团队的队列，以及团队号的队列
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cctype>
#include<sstream>
using namespace std;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)

int getint(){int x;scanf("%d",&x);return x;}
int main(){
	//freopen("d:\\input.txt","r",stdin);
	//freopen("d:\\output.txt","w",stdout);

	int cnt=0,t,N,m;
	map<int,int> team;
	int teamid;
	while(1){
		int t=getint();
		if(!t)break;
		_for(i,0,t){
			cin>>m;
			_for(j,0,m){
				team[getint()]=i;
			}
		}
		printf("Scenario #%d\n",++cnt);
		string op;
		queue<int> q,tq[1000];
		while(cin>>op){
			if(op[0]=='S')break;
			if(op[0]=='E'){
				int x=getint(),y=team[x];
				if(tq[y].empty())q.push(y);
				tq[y].push(x);
			}
			if(op[0]=='D'){
				int y=q.front();
				if(tq[y].size()==1)q.pop();
				printf("%d\n",tq[y].front());
				tq[y].pop();
			}
		}
		printf("\n");
	}
	return 0;
}

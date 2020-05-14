/**
 * @Date:   2018-09-07
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-07
 */

 //从小到大生成各个丑数，放入优先级队列，注意对生成的丑数去重即可
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
#include<functional>
using namespace std;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
int getint(){int x;scanf("%d",&x);return x;}
typedef long long LL;
int main(){
	//freopen("d:\\input.txt","r",stdin);
	//freopen("d:\\output.txt","w",stdout);
	priority_queue<LL,vector<LL>,greater<LL> > pq;
	int rank=1;
	set<LL> s;
	pq.push(1);s.insert(1);
	int e[3]={2,3,5};
	while(1){
		LL t=pq.top();
		pq.pop();
		if(rank==1500){
			printf("The 1500'th ugly number is %lld.\n",t);
			break;
		}
		rank++;
		_for(i,0,3){
			LL x=t*e[i];
			if(x<0)break;
			if(!s.count(x)){
				pq.push(x);s.insert(x);
			}
		}
	}

	return 0;
}

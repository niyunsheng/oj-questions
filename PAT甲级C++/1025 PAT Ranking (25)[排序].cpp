/*思路：
两次排序，一次本地名次，一次总名次，但是没有必要存储两个序列，sort函数可以对特定区间排序，再对整体排序sort(it_lo,it_hi)
笔者第一次做的时候直接将数据存储了多个数组分别排序，每个数据存储了两边，浪费了空间，但是写法上较简单，不用考虑分段排序的下标
排序时注意数组下标即可，分段排序，记录名次
注意stdin要加头文件cstdio
*/
#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
#define inf 0x3fffffff
#define pb push_back
typedef long long LL;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct student{
	string name;
	int score;
	int location;
	int locationRank;
	int finalRank;
	student(){	}
	student(string name,int score,int location):name(name),score(score),location(location){	}

};
bool cmp(student a,student b){
	if(a.score!=b.score)return a.score>b.score;
	else return a.name<b.name;
}
int main(int argc, char** argv) {
	//freopen("d:\\input.txt","r",stdin);//注意这里要添加头文件cstdio
	vector<student> v;
	int N;
	cin>>N;
	int r=0;
	_for(i,1,N+1){
		int K;
		string name;
		int score;
		cin>>K;
		_for(j,0,K){
			cin>>name>>score;
			v.pb(student(name,score,i));
		}
		sort(v.begin()+r,v.begin()+r+K,cmp);
		v[r].locationRank=1;
		_for(j,1,K){
			v[r+j].locationRank=(v[r+j].score==v[r+j-1].score)?v[r+j-1].locationRank:j+1;
		}
		r+=K;
	}
	sort(v.begin(),v.end(),cmp);
	r=1;
	v[0].finalRank=1;
	_for(i,1,v.size()){
		v[i].finalRank=(v[i].score==v[i-1].score)?v[i-1].finalRank:i+1;
	}
	cout<<v.size()<<endl;
	_for(i,0,v.size()){
		cout<<v[i].name;
		printf(" %d %d %d\n",v[i].finalRank,v[i].location,v[i].locationRank);
	}
	return 0;
}

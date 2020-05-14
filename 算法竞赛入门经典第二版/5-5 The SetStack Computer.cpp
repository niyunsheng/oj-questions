/**
 * @Date:   2018-09-07
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-07
 */
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<cctype>
#include<sstream>
using namespace std;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
//这个题目的思想很好，集合的集合如何表示，将集合映射到整数，集合的集合仍然映射到整数
vector<set<int> > int2set;
map<set<int>,int> set2int;

int getID(set<int> s){//获得集合的ID,这里写引用会报错，不知道为什么？
	if(set2int.count(s))return set2int[s];
	int2set.push_back(s);
	return set2int[s]=int2set.size()-1;
}
#define ALL(x) x.begin(),x.end()
#define INS(x) inserter(x,x.begin())

int main(){
	//freopen("d:\\input.txt","r",stdin);
	//freopen("d:\\output.txt","w",stdout);
	string op;
	int t,N;
	cin>>t;
	while(t--){
		stack<int> S;
		cin>>N;
		while(N--){
			cin>>op;
			if(op[0]=='P')S.push(getID(set<int>()));
			else if(op[0]=='D')S.push(S.top());
			else{
				set<int> x1=int2set[S.top()];S.pop();
				set<int> x2=int2set[S.top()];S.pop();
				set<int> x;
				if(op[0]=='U')set_union(ALL(x1),ALL(x2),INS(x));
				if(op[0]=='I')set_intersection(ALL(x1),ALL(x2),INS(x));
				if(op[0]=='A'){x=x2;x.insert(getID(x1));}
				S.push(getID(x));
			}
			cout<<int2set[S.top()].size()<<endl;
		}
		cout<<"***"<<endl;
	}
	return 0;
}

/**
 * @Date:   2018-08-31
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-31
 */
#include<iostream>
#include<string>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
int main(){
    //freopen("d:\\input.txt","r",stdin);
	int M,N,S;
	cin>>M>>N>>S;
	set<string> winner;
	int rank=1;
	string tmp;
	int tar=S;
	_for(i,0,M){
		cin>>tmp;
		if(rank==tar){
			if(winner.count(tmp)==0){
				cout<<tmp<<endl;
				winner.insert(tmp);
				rank=1;
				tar=N;
			}
			continue;
		}
		rank++;
	}
	if(winner.size()==0)cout<<"Keep going..."<<endl;
	return 0;
}

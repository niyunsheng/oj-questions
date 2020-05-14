/**
 * @Date:   2018-08-31
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-31
 */
#include<iostream>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)

void printvec(vector<int>& vec){
	cout<<vec[0];
	_for(i,1,vec.size())cout<<" "<<vec[i];
	cout<<endl;
}
int fun(int x){
	int ans=0;
	while(x>0){
		ans+=x%10;
		x/=10;
	}
	return ans;
}
int main(){
    //freopen("d:\\input.txt","r",stdin);
	int N,t;
	cin>>N;
	set<int> s;
	vector<int> ans;
	_for(i,0,N){
		cin>>t;
		s.insert(fun(t));
	}
	for(set<int>::iterator it=s.begin();it!=s.end();it++){
		ans.push_back(*it);
	}
	cout<<ans.size()<<endl;
	printvec(ans);
	return 0;
}

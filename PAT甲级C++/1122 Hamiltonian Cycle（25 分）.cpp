/**
 * @Date:   2018-09-01
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-01
 */
#include<iostream>
#include<string>
#include<cstring>
#include<set>
#include<map>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
int N,M,K,n,c1,c2;
set<pair<int,int> > sset;
vector<int> vec(10000);
int cnt[250];
bool is_right(int n){
	if(vec[0]!=vec[n-1]||n!=N+1)return false;
	memset(cnt,0,sizeof(cnt));
	_for(i,1,n){
		if(sset.count(make_pair(vec[i],vec[i-1]))==0)return false;
		cnt[vec[i]]++;
		if(cnt[vec[i]]>1)return false;
	}
	return true;
}
//思路是没有一点问题的，耽误的时间也不知道是哪个地方出错了，重新把判断是不是环的写成函数放在外面，就没问题了，看来，以后尽量用函数
int main(){
    //freopen("d:\\input.txt","r",stdin);

	cin>>N>>M;

	_for(i,0,M){
		cin>>c1>>c2;
		sset.insert(make_pair(c1,c2));
		sset.insert(make_pair(c2,c1));
	}
	cin>>K;
	_for(i,0,K){
		memset(cnt,0,sizeof(cnt));
		cin>>n;
		//if(n!=N+1){cout<<"NO"<<endl;continue;}
		_for(j,0,n){
			cin>>vec[j];
		}
		if(!is_right(n)){
			cout<<"NO"<<endl;
		}else{
			cout<<"YES"<<endl;
		}
	}
	return 0;
}

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
int N,M;
void printvec(vector<int>& vec){
	cout<<vec[1];
	_for(i,2,N+1)cout<<" "<<vec[i];
	cout<<endl;
}
//居然还有不连通的情况，不说明根本看不出来啊
vector<int> vec(505),fa(505,-1);
int findroot(int x){
	return fa[x]==-1?x:fa[x]=findroot(fa[x]);
}
void combine(int c1,int c2){
	int r1=findroot(c1),r2=findroot(c2);
	if(r1!=r2)
		fa[r1]=r2;
}
int main(){
    //freopen("d:\\input.txt","r",stdin);

	cin>>N>>M;
	if(N==0)return 0;
	int c1,c2;

	_for(i,0,M){
		cin>>c1>>c2;
		vec[c1]++;vec[c2]++;
		combine(c1,c2);
	}
	int gra=0;//连通域个数
	_for(i,1,N+1){
		if(fa[i]==-1)gra++;
	}
	printvec(vec);
	if(gra>1){
		cout<<"Non-Eulerian"<<endl;
		return 0;
	}
	int cnt=0;
	_for(i,1,N+1){
		if(vec[i]%2==1)cnt++;
	}
	if(cnt==0){
		cout<<"Eulerian"<<endl;
	}else if(cnt==2){
		cout<<"Semi-Eulerian"<<endl;
	}else{
		cout<<"Non-Eulerian"<<endl;
	}
	return 0;
}

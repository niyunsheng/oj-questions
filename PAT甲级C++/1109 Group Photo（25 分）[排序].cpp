/**
 * @Date:   2018-08-30
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-02
 */
//根据题意模拟即可
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
struct node{
	string name;
	int h;
	bool operator<(node& b){
		if(h!=b.h)return h>b.h;
		else return name<b.name;
	}
};
int main() {
	//freopen("d:\\input.txt","r",stdin);
    int n,k;
    cin>>n>>k;
	vector<node> v(n);
	vector<string> ans(n);
	_for(i,0,n){
		cin>>v[i].name>>v[i].h;
	}
	sort(v.begin(),v.end());
	//题意别理解错了，是k排，每排人数是n/k
	int m=n/k;//每排人数
	int t=n-n/k*(k-1);//最后一排人数，其余各排都是m人
	int lo=0,hi=t;
	_for(i,0,k){
		ans[lo+(hi-lo)/2]=v[lo].name;
		_for(j,1,hi-lo){
			if(j%2==1){
				ans[lo+(hi-lo)/2-(j+1)/2]=v[lo+j].name;
			}else{
				ans[lo+(hi-lo)/2+(j+1)/2]=v[lo+j].name;
			}
		}
		cout<<ans[lo];
		_for(j,lo+1,hi){
			cout<<" "<<ans[j];
		}
		cout<<endl;
		lo=hi;hi=lo+m;
	}
	return 0;
}

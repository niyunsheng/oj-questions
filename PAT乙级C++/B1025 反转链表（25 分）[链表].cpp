/**
 * @Date:   2018-09-02
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-02
 */
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)

struct node{int val,addr;node(int a,int b):addr(a),val(b){}};
int main(){
	//freopen("d:\\input.txt","r",stdin);
	int A,N,K;
	cin>>A>>N>>K;
	int Next[100005],Data[100005];
	vector<node> ans;
	int addr,data,next;
	_for(i,0,N){
		cin>>addr>>data>>next;
		Next[addr]=next;
		Data[addr]=data;
	}
	while(A!=-1){
		ans.push_back(node(A,Data[A]));
		A=Next[A];
	}
	int hi=K;
	while(hi<=ans.size()){
		reverse(ans.begin()+hi-K,ans.begin()+hi);
		hi+=K;
	}
	_for(i,0,ans.size()-1){
		printf("%05d %d %05d\n",ans[i].addr,ans[i].val,ans[i+1].addr);
	}
	printf("%05d %d -1",ans[ans.size()-1].addr,ans[ans.size()-1].val);
	return 0;
}

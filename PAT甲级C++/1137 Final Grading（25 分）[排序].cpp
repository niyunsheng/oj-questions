/**
 * @Date:   2018-08-29
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-29
 */
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
struct node{
	string id;
	int Gp,Gm,Gf,G;
	bool operator<(node& b){
		if(G!=b.G)return G>b.G;
		else return id<b.id;
	}
	//node(int p,int m,int f){Gp=p;Gm=m;Gf=f;}
};
int main(){
	//freopen("d:\\input.txt","r",stdin);
	map<string,node> mmap;
	int P,M,N;
	cin>>P>>M>>N;
	string strid;
	int t;
	_for(i,0,P){
		cin>>strid>>t;
		if(t>=200){mmap[strid].id=strid;mmap[strid].Gp=t;mmap[strid].Gm=-1;mmap[strid].Gf=-1;}
	}
	_for(i,0,M){
		cin>>strid>>t;
		if(mmap.count(strid)!=0)
			mmap[strid].Gm=t;
	}
	_for(i,0,N){
		cin>>strid>>t;
		if(mmap.count(strid)!=0)
			mmap[strid].Gf=t;
	}
	vector<node> ans;
	for(map<string,node>::iterator it=mmap.begin();it!=mmap.end();it++)
		ans.push_back(it->second);
	_for(i,0,ans.size()){
		if(ans[i].Gm>ans[i].Gf)ans[i].G=((ans[i].Gm*4+ans[i].Gf*6)+5)/10;
		else ans[i].G=ans[i].Gf;
	}
	sort(ans.begin(),ans.end());
	_for(i,0,ans.size()){
		if(ans[i].G<60)break;
		printf("%s %d %d %d %d\n",ans[i].id.c_str(),ans[i].Gp,ans[i].Gm,ans[i].Gf,ans[i].G);
	}
	return 0;
}

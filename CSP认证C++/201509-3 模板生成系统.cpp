/**
 * @Date:   2018-09-10
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-10
 */
#include<cstdio>
#include<iostream>
#include<set>
#include<vector>
#include<queue>
#include<map>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

//201509-3 模板生成系统
//运行超时，90分
#define MAXN 105
#define inf 0x7fffffff
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
int getint(){int x;scanf("%d",&x);return x;}
vector<string> v(MAXN);
string str;
map<string,string> mmap;
int N,M;
string getmmap(string s){
	if(mmap.count(s)==0)return "";
	else return mmap[s];
}
void printstr(string str){
	while(1){
		int lo=str.find("{{ "),hi=str.find(" }}");
		if(lo==-1)break;
		str.replace(lo,hi-lo+3,getmmap(str.substr(lo+3,hi-lo-3)));
	}
	cout<<str<<endl;
}
int main(){
	//freopen("d:\\input.txt","r",stdin);
	//freopen("d:\\output.txt","w",stdout);
	cin>>M>>N;getchar();
	_for(i,0,M){
		getline(cin,str);
		v[i]=str;
		//cout<<v[i]<<endl;
	}
	string name,Tom;
	_for(i,0,N){
		cin>>name;
		//cout<<name;
		getline(cin,Tom);
		//cout<<Tom<<endl;
		mmap[name]=Tom.substr(2,Tom.size()-3);
		//cout<<mmap[name]<<endl;
	}
	_for(i,0,M){
		printstr(v[i]);
	}
	return 0;
}

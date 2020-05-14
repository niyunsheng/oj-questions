/**
 * @Date:   2018-09-06
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-06
 */
//VJudge超时，不知道什么原因
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
vector<vector<int> > v(30);//每一个数字所在的堆上的数字
vector<int> r(30);//每一个数字的位置
int n;

void fun(int x){//将x上方的数字全部归位
	while(v[r[x]].back()!=x){
		int c=v[r[x]].back();v[r[x]].pop_back();
		v[c].push_back(c);
		r[c]=c;
	}
}
void fun2(int x,int y){//将x上方的整体落到y上
	vector<int> tmp;
	while(v[r[x]].back()!=x){
		tmp.push_back(v[r[x]].back());
		v[r[x]].pop_back();
	}
	tmp.push_back(x);
	v[r[x]].pop_back();
	_for(i,0,tmp.size()){
		int c=tmp[tmp.size()-1-i];
		v[r[y]].push_back(c);
		r[c]=r[y];
	}
}
int main(){
	//freopen("d:\\input.txt","r",stdin);
	string s;

	cin>>n;
	getchar();
	_for(i,0,n){v[i].push_back(i);r[i]=i;}
	while(1){
		getline(cin,s);
		if(s[1]=='u')break;
		int a=s[5]-'0',b=s[12]-'0';
		if(r[a]==r[b])continue;
		if(s[1]=='o'){
			if(s[8]=='n'){
				fun(a);fun(b);
				v[r[a]].pop_back();
				v[r[b]].push_back(a);
				r[a]=r[b];
			}else{
				fun(a);
				v[r[a]].pop_back();
				v[r[b]].push_back(a);
				r[a]=r[b];
			}
		}else{
			if(s[8]=='n'){
				fun(b);
				fun2(a,b);
			}else{
				fun2(a,b);
			}
		}
	}
	_for(i,0,n){
		printf("%d:",i);
		_for(j,0,v[i].size())printf(" %d",v[i][j]);
		printf("\n");
	}
	return 0;
}

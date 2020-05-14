/**
 * @Date:   2018-09-06
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-06
 */
//注意之类引用ctype中的isalpha和tolower操作，以及sstream中的stringstream操作
#include<iostream>
#include<string>
#include<cstring>
#include<set>
#include<cctype>
#include<sstream>
using namespace std;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)

int main(){
	//freopen("d:\\input.txt","r",stdin);
	//freopen("d:\\output.txt","w",stdout);
	string s;
	set<string> dict;
	while(cin>>s){
		_for(i,0,s.size()){
			if(isalpha(s[i]))s[i]=tolower(s[i]);
			else s[i]=' ';
		}
		stringstream ss(s);
		while(ss>>s){
			dict.insert(s);
		}
	}
	for(set<string>::iterator it=dict.begin();it!=dict.end();it++){
		cout<<*it<<endl;
	}
	return 0;
}

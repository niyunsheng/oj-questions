/**
 * @Date:   2018-09-07
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-07
 */
//只要能想到将单词标准化，就好做了
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<cctype>
#include<sstream>
using namespace std;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
void stdalpha(string& s){
	_for(i,0,s.size())
		s[i]=tolower(s[i]);
	sort(s.begin(),s.end());
}
int main(){
	//freopen("d:\\input.txt","r",stdin);
	//freopen("d:\\output.txt","w",stdout);
	string s;
	vector<string> tmp,tmp1,ans;
	map<string,int> dict;
	while(cin>>s){
		if(s[0]=='#')break;
		tmp.push_back(s);
		stdalpha(s);
		tmp1.push_back(s);
		if(dict.count(s)==0)dict[s]=1;
		else dict[s]++;
	}
	_for(i,0,tmp1.size()){
		if(dict[tmp1[i]]==1)ans.push_back(tmp[i]);
	}
	sort(ans.begin(),ans.end());
	_for(i,0,ans.size()){
		cout<<ans[i]<<endl;
	}
	return 0;
}

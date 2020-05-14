/**
 * @Date:   2018-08-09
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-29
 */
 //1038 Recover the Smallest Number (30)
 /*思路：
 按照字符串排序，重写cmp函数：str1+str2<str2+str1
 */
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
bool cmp(string& str1,string& str2){
	return str1+str2<str2+str1;
}
int main(){
	//freopen("d:\\input.txt","r",stdin);
	int n;
	scanf("%d",&n);
	if(n==0)return 0;
	vector<string> str(n);
	for(int i=0;i<n;i++)
		cin>>str[i];
	sort(str.begin(),str.end(),cmp);
	string ans;
	for(int i=0;i<n;i++)
		ans+=str[i];
	int lo=0;
	while(lo<ans.size()&&ans[lo]=='0')lo++;
	if(lo==ans.size())cout<<"0";
	else
		cout<<ans.substr(lo,ans.size()-lo);
	return 0;
}

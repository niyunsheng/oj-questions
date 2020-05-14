/**
 * @Date:   2018-08-06
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-06
 */
#include<iostream>
#include<string>
using namespace std;

int main(){
    //freopen("D:\\CodeBlockSpace\\input.txt","r",stdin);
	string s,st;
	cin>>s;
	int n=s.size();
	int n1,n2,n3;
	n1=n3=(n+2)/3;n2=n+2-n1-n3;
	for(int i=0;i<n2-2;i++){
		st+=" ";
	}
	for(int i=0;i<n1-1;i++){
		cout<<s[i]<<st<<s[n-1-i]<<endl;
	}
	cout<<s.substr(n1-1,n2)<<endl;
	return 0;
}

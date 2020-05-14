/**
 * @Date:   2018-09-07
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-07
 */
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<stack>
#include<algorithm>
using namespace std;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
void print(const string& s,char c,int n){
	cout<<s;
	while(n--)cout<<c;
}
int main() {
	//freopen("d:\\input.txt","r",stdin);
	int n,M;
	while(cin>>n){
		M=0;
		vector<string> vec(n);
		_for(i,0,n){
			cin>>vec[i];
			M=max(M,(int)vec[i].size());
		}
		sort(vec.begin(),vec.end());
		int C=62/(M+2);
		int R=(n+C-1)/C;
		print("",'-',60);
		printf("\n");
		_for(i,0,R){
			int j=0;
			for(int j=0;j<C-1&&i+R*j<n;j++){
				print(vec[i+R*j],' ',M+2-vec[i+R*j].size());
			}
			if(i+R*(C-1)<n)print(vec[i+R*(C-1)],' ',M-vec[i+R*j].size());
			printf("\n");
		}
	}
	return 0;
}

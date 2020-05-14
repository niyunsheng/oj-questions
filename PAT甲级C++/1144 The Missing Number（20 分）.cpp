/**
 * @Date:   2018-08-28
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-28
 */
//水题，只需要考虑输入的数字时1-n时如何输出即可
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include"string.h"
using namespace std;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
int getint() {int x;scanf("%d",&x);return x;}
#define MAX 505
#define inf 0x7fffffff


int main(){
    //freopen("d:\\input.txt","r",stdin);
	int n,t;
	set<int> s;
    scanf("%d",&n);
	vector<int> vec;
	_for(i,0,n){
		cin>>t;
		s.insert(t);
	}
	_for(i,1,n+2){
		if(s.count(i)==0){
			printf("%d\n",i);
			return 0;
		}
	}
    return 0;
}

//题解：先求出从第一个珠子左侧断开的逆序对数。每次将断开的位置向右移一格，那么在最左边的那个珠子会变成最右边,的那个珠子，那么逆序对会减去比他小的数字数，再加上比他大的数字数。
//自己初始的算法只是注意到了逆序对更新的O(n)方法，却没有观察到上述结论

//用mergeSort计算逆序对将代码的复杂度降到了nlogn，解决了超时问题，但是算例一组也没通过，可能是程序哪里的逻辑还是错的。

#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <stack>

using namespace std;

#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
#define inf 0x3fffffff
#define pb push_back
typedef long long LL;
#define M 1000000007
#define N 1000005

struct ip{
	int a[4];//a[3] a[2] a[1] a[0]
	int len;
	unsigned int num;//整数表示
	ip(){a[3]=0;a[2]=0;a[1]=0;a[0]=0;len=0;num=0;}
};

bool cmp(ip a,ip b){
	for(int i=3;i>=0;i--){
		if(a.a[i]!=b.a[i])
			return a.a[i]<b.a[i];
	}
	return a.len<b.len;;
}

vector<ip> ips(N);

int readNum(string& s,int& r){
	int ans=0;
	while(isdigit(s[r])){
		ans*=10;
		ans+=s[r]-'0';
		r++;
	}
	return ans;
}

int judgeType(string& s,int& o,int& p){
	_for(i,0,s.size()){
		if(s[i]=='.')o++;
		else if(s[i]=='/')p++;
	}
	if(o==3&&p==1)return 1;
	else if(p==1)return 2;
	else return 3;
}

void fun(string& s,ip& v){
	int o=0,p=0;//o\p分别表示串中的小数点个数和斜杠个数
	int k=judgeType(s,o,p);//k表示ip地址的三种类型
	int r=0;
	switch(k){
		case 1:
			for(int i=3;i>=0;i--){
				v.a[i]=readNum(s,r);r++;
			}
			v.len=readNum(s,r);
			break;
		case 2:
			_for(i,0,o+1){
				v.a[3-i]=readNum(s,r);r++;
			}
			v.len=readNum(s,r);
			break;
		case 3:
			_for(i,0,o+1){
				v.a[3-i]=readNum(s,r);r++;
			}
			v.len=(o+1)*8;
			break;
	}
	for(int i=3;i>=0;i--){
		v.num*=256;
		v.num+=v.a[i];
	}
	printf("%d.%d.%d.%d/%d  %u\n",v.a[3],v.a[2],v.a[1],v.a[0],v.len,v.num);
}

int main(int argc, char** argv) {
	freopen("d:\\input.txt","r",stdin);
	int n;
	string s;
	cin>>n;
	getchar();
	_for(i,0,n){
		getline(cin,s);
		fun(s,ips[i]);
	}
//	sort(ips.begin(),ips.begin()+n,cmp);
	return 0;
}

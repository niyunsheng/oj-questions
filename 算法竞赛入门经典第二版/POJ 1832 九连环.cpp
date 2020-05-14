/*二进制与格雷码转换
由二进制数转换为格雷码：从右到左检查，如果某一数字左边是0，该数字不变；如果是1，该数字改变（0变为1，1变为0）。例，二进制数11011的格雷码是10110.

由格雷码表示变为二进制数：从右到左检查，如果某一数字的左边数字和是偶数，该数字不变；如果是奇数，该数字改变。例，格雷码11011表示为二进制数是10010.

以上可以用口诀帮助记忆：2G一改零不改，G2奇变偶不变。
*/
/*例
设九连环的初始状态是110100110，要求终止状态是001001111，简单解法与完整解法各需要多少步？过程如何？

解 初始状态110100110，格雷码是011001011，转换为二进制数是010001101，相应十进制数是141.终止状态是001001111，格雷码是111100100，转换为二进制数是101000111，相应十进制数是327.二者差326－141＝186，完整解法需要186步。
*/

//方法一：DFS模拟：超时
#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <stack>
#include <queue>
#include <assert.h>

using namespace std;

#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
#define inf 0x3fffffff
#define pb push_back
typedef long long LL;
typedef pair<int,int> PII;
#define M 127
#define N 130

vector<int> A(N),B(N);
int cnt=0,n;

void fun(int r,int type){//type=1装上r,type=0卸下r
	if(A[r]==type)return;
	if(r!=n-1){
		if(A[r+1]==0)fun(r+1,1);
		_for(i,r+2,n)fun(i,0);
	}
	A[r]=type;
	cnt++;
}


int main(int argc, char** argv) {
	freopen("d:\\input.txt","r",stdin);
	int m;
	scanf("%d",&m);
	_for(i,0,m){
		scanf("%d",&n);
		_for(i,0,n)scanf("%d",&A[i]);
		_for(i,0,n)scanf("%d",&B[i]);
		cnt=0;
		_for(i,0,n){
			fun(i,B[i]);
		}
		cout<<cnt<<endl;
	}

	return 0;
}

//方法二：初始状态变成格雷码，然后转换为热进制，即为初始状态到此状态的步数；两个状态步数相差即可
//之所以答案错误，格雷码的部分是正确的，但是高精度部分没有注意

#define M 127
#define N 130

vector<int> A(N),B(N);
int cnt=0,n;
int fun(vector<int>& V){//将格雷码转化为二进制
//	_for(i,0,n)cout<<V[i];
//	cout<<endl;
	int flag=V[0];
	_for(i,1,n){
		int tmp=V[i];
		if(flag&1)V[i]=1-V[i];
		flag+=tmp;
	}
//	_for(i,0,n)cout<<V[i];
//	cout<<endl;
	int ans=0;
	for(int i=n-1;i>=0;i--){
		ans*=2;
		ans+=V[i];
	}
	return ans;
}

int main(int argc, char** argv) {
	freopen("d:\\input.txt","r",stdin);
	int m;
	scanf("%d",&m);
	_for(i,0,m){
		scanf("%d",&n);
		_for(i,0,n)scanf("%d",&A[i]);
		_for(i,0,n)scanf("%d",&B[i]);
		int cnt1=fun(A),cnt2=fun(B);
		cout<<abs(cnt1-cnt2)<<endl;
	}

	return 0;
}

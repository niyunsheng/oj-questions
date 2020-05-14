/**
 * @Date:   2018-08-30
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-30
 */
//这个题太水了，本以为排序肯定超时，得用partition的第k大算法，然而，排序直接就AC了。
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
int main() {
	//freopen("d:\\input.txt","r",stdin);
	int n;
    cin>>n;
	vector<int> vec(n);
	_for(i,0,n)cin>>vec[i];
	sort(vec.begin(),vec.end());
	int sum1=0,sum2=0;
	_for(i,0,n/2)sum1+=vec[i];
	_for(i,n/2,n)sum2+=vec[i];
	printf("%d %d\n",n%2,sum2-sum1);
	return 0;
}

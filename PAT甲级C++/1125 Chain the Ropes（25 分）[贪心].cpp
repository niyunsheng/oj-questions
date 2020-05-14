/**
 * @Date:   2018-08-31
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-07
 */
 //注意，这个题目需要在每次平均时都取整，而不是最后才取整
#include<iostream>
#include<string>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
int main(){
    //freopen("d:\\input.txt","r",stdin);
	int N;
	cin>>N;
	vector<int> vec(N);
	_for(i,0,N)cin>>vec[i];
	sort(vec.begin(),vec.end());
	int ans=vec[0];
	_for(i,1,N){
		ans=(ans+vec[i])/2;
	}
	printf("%d\n",ans);
	return 0;
}

/**
 * @Date:   2018-09-01
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-07
 */
//在数组a中存储n天的公里数，对n个数据从大到小排序，i表示了骑车的天数，那么满足a[i] > i+1的最大i+1即为所求
//柳神
#include <iostream>
#include <algorithm>
using namespace std;
int a[1000000];
int main() {
    int n, e = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a+n, greater<int>());
    while(e < n && a[e] > e+1) e++;
    printf("%d", e);
    return 0;
}
//我写的
#define ALL(x) x.begin(),x.end()
int main(){
	//freopen("in.txt","r",stdin);
	int n;
	cin>>n;
	vector<int> v(n);
	_for(i,0,n)cin>>v[i];
	sort(ALL(v));
	_for(i,0,n){
		if(v[i]>n-i){
			printf("%d\n",n-i);
			return 0;
		}
	}
	printf("0\n");
	return 0;
}

/**
 * @Date:   2018-08-10
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-29
 */
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
//1104 Sum of Number Segments（20 分）
//思路：片段和，num[i]包含在几个片段当中呢？其左边有i个元素，右边n-i-1个元素，共(i+1)*(n-i)个片段

int main(){
	//freopen("d:\\input.txt","r",stdin);
	int n;
	scanf("%d",&n);
	double t,ans=0;
	for(int i=0;i<n;i++){
		scanf("%lf",&t);
		ans+=t*(i+1)*(n-i);
	}
	printf("%.2lf",ans);
	return 0;
}

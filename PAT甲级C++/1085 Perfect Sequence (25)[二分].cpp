/**
 * @Date:   2018-08-09
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-09
 */
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
//1085 Perfect Sequence (25)
/*本题两种思路：二分查找和双指针查找
其实理解题意后可以发现，就是求连续子序列的最大程度，要满足a[lo]*p>=a[hi-1]
所以，需要对于任一的a[lo]，二分查找满足条件的最大的hi，然后更新最大连续子序列的长度即可
双指针法，第一次寻找顺序寻找，然后每次寻找在前一次的基础上，充分利用了前面的经验
方法一：二分查找法
方法二：双指针法
*/
//二分法,[lo,hi)查找小于等于e的秩最大者
//注：最后一个算例不过是因为int型超范围了，改成longlong即可
int binsearch(vector<long long>& num,int lo,int hi,long long e){
	int mi=(lo+hi)/2;
	while(lo<hi){
		mi=(lo+hi)/2;
		if(num[mi]<=e)lo=mi+1;
		else hi=mi;
	}
	return lo-1;
}
int main(){
	//freopen("d:\\codeBlockSpace\\input.txt","r",stdin);
	int n,p;
	scanf("%d %d",&n,&p);
	vector<long long> num(n);
	for(int i=0;i<n;i++){
		scanf("%lld",&num[i]);
	}
	sort(num.begin(),num.end());
	int Amax=0;//最大元素区间
	//对于每一个i，寻找<=p*i的最大秩j，然后改集合的元素即为j-i+1
	for(int i=0;i<n;i++){
		int j=binsearch(num,i+1,n,num[i]*p);
		if(j-i+1>Amax)Amax=j-i+1;
	}
	printf("%d",Amax);
	return 0;
}

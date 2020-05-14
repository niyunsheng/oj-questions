/**
 * @Date:   2018-08-10
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-29
 */
//1散列法，直接用set即可；2用二分查找法；3用双指针
//本人采用双指针法，但是相比二分法+upper_bound函数略显复杂
//题目求区间和，则构造sum[i]=s[0]+s[1]+...+s[i]，则此序列递增，对比任意的i开头的子序列，相当于查找sum[j]-sum[i-1]=m,即在给定区间查找sum[j]=sum[i-1]+m,而等号右边都是已知的
//可以自己写二分查找来输出小于等于sum[i]+m的最大秩，最后再判断下是否相等即为正确答案
//更方便的是用upper_bound函数，upper_bound(it_lo,it_hi,val)返回的是第一个大于val的指针

#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	//freopen("d:\\input.txt","r",stdin);
	int n,m;
	scanf("%d %d",&n,&m);
	vector<int> dia(n);
	for(int i=0;i<n;i++)scanf("%d",&dia[i]);
	int lo=0,hi=0;//设区间是[lo,hi)，区间不断增长
	long long sum=0;//区间和
	bool flag=false;//记录有没有找到正确答案，可以用差值是否为0来判断
	int Amin=0x7fffffff;//记录未找到正确答案时的最小差值
	while(lo<n){
		while(hi<n&&sum<m)sum+=dia[hi++];
		if(sum==m){
			printf("%d-%d\n",lo+1,hi);
			flag=true;
		}
		if(sum<m)break;
		Amin=Amin<sum-m?Amin:sum-m;
		sum-=dia[lo];
		lo++;
	}
	if(Amin!=0){//
		lo=0;hi=0;sum=0;
		m+=Amin;
		while(lo<n){
			while(hi<n&&sum<m)sum+=dia[hi++];
			if(sum==m){
				printf("%d-%d\n",lo+1,hi);
				flag=true;
			}
			Amin=Amin<sum-m?Amin:sum-m;
			sum-=dia[lo];
			lo++;
		}
	}
	return 0;
}

/**
 * @Date:   2018-08-10
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-10
 */
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
//1089 Insert or Merge
//思路：对原始序列进行一次又一次的插入排序，若发现与中间序列相同，则为插入排序，并输出下一个序列；
//否则，对其进行归并排序，若发现与中间序列相同，则输出下一个序列
//注意练习插入和归并排序的写法，同时善于利用sort函数
//是个好题！
//判断归并排序需要按照题目要求进行模拟，中间归并排序可以用sort函数替代，同样，插入排序也可以用sort来替代，更简单的就是直接判断中间序列是不是和最初的序列后缀相同，不相同的前缀是升序，找到第一个相同但是不升序的后缀i，然后sort(0,i+1)输出就可以了
//==根本就不用自己写插入和归并的程序==
bool isSame(vector<int>& a,vector<int>& b){
	for(int i=0;i<a.size();i++)
		if(a[i]!=b[i])return false;
	return true;
}
void mergesort(vector<int>& vec,int lo,int hi,int mi){
	if(mi>=hi)return;
	vector<int> tmp;
	for(int i=lo;i<mi;i++)tmp.push_back(vec[i]);
	int i=mi,j=0,k=lo;//归并序列的位置
	while(1){
		while(j<mi-lo&&tmp[j]<=vec[i]){vec[k]=tmp[j];k++;j++;}
		if(j==mi-lo)break;
		while(i<hi&&tmp[j]>vec[i]){vec[k]=vec[i];k++;i++;}
		if(i==hi)while(j<mi-lo){vec[k]=tmp[j];k++;j++;}
	}
}
int main(){
	//freopen("d:\\codeBlockSpace\\input.txt","r",stdin);
	int n;
	scanf("%d",&n);
	vector<int> origin(n),tmp(n),target(n);
	for(int i=0;i<n;i++)scanf("%d",&origin[i]);
	for(int i=0;i<n;i++)scanf("%d",&target[i]);
	bool flag=false;//表示找到目标序列
	//插入排序试探
	for(int i=0;i<n;i++)tmp[i]=origin[i];
	for(int i=1;i<n;i++){//插入排序最多n轮
		int j=i-1,t=tmp[i];
		while(j>=0&&tmp[j]>tmp[i])j--;
		for(int k=i-1;k>j;k--)tmp[k+1]=tmp[k];
		tmp[j+1]=t;
		if(flag){
			printf("Insertion Sort\n");
			printf("%d",tmp[0]);
			for(int k=1;k<n;k++)printf(" %d",tmp[k]);
			return 0;
		}
		if(isSame(tmp,target)){
			flag=true;
		}
	}
	//归并排序试探
	for(int i=0;i<n;i++)tmp[i]=origin[i];
	int domin=2;//每次归并的元素个数
	int lo,hi;//每次归并的区间[lo,hi)
	while(1){
		lo=0;hi=min(lo+domin,n);
		while(lo<n){
			//这里的merge不同于一般的merge，需要给定上次的分解范围
			mergesort(tmp,lo,hi,lo+domin/2);
			//这里的归并也可以直接sort函数,更快更方便
			//sort(tmp.begin()+lo,tmp.begin()+hi);
			lo=hi;hi=min(lo+domin,n);
		}
		if(flag){
			printf("Merge Sort\n");
			printf("%d",tmp[0]);
			for(int k=1;k<n;k++)printf(" %d",tmp[k]);
			return 0;
		}
		if(isSame(tmp,target)){flag=true;}
		if(domin>=n)break;
		domin*=2;
	}
	return 0;
}

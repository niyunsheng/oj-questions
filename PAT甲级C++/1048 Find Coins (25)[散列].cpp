/**
 * @Date:   2018-08-09
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-09
 */
#include<iostream>
#include<algorithm>
using namespace std;
//1048 Find Coins (25)
/*本题目有三种解法：
1 散列法，最简单，但是有数字范围的限制
2 二分查找：将读入的所有数排序，然后对每一个i，二分查找m-i,如果两个数的下标不同，则是正确结果，若到最后也没有找到结果，则输出no solution
3 双指针法：适用所有的数据范围，一头一尾两个指针，然后根据其和不断向中间移动
*/
#define SOLU1
//散列法
#ifndef SOLU1
#define SOLU1
int main(){
	//freopen("d:\\codeBlockSpace\\input.txt","r",stdin);
	int N,M,tmp;
	int valid[501]={0};
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++){
		scanf("%d",&tmp);
		valid[tmp]++;
	}
	int i=1;
	for(;i<501;i++){
		if(valid[i]!=0&&M-i>=i){
			if(i!=M-i){
				if(M-i<501&&valid[M-i]>0)break;
			}else{
				if(valid[i]>1)break;
			}
		}
	}
	if(i==501)printf("No Solution");
	else printf("%d %d",i,M-i);
	return 0;
}
#endif

//双指针法
#ifndef SOLU3
#define SOLU3
int main(){
	//freopen("d:\\codeBlockSpace\\input.txt","r",stdin);
	int N,M,tmp;
	int data[100001]={0},top=0;
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++){
		scanf("%d",&tmp);
		data[top++]=tmp;
	}
	sort(data,data+N);
	int lo=0,hi=N-1;
	while(lo<hi){
		if(data[lo]+data[hi]!=M){
			if(data[lo]+data[hi]>M)hi--;
			else lo++;
		}else{
			break;
		}
	}
	if(lo>=hi)printf("No Solution");
	else printf("%d %d",data[lo],data[hi]);
	return 0;
}
#endif

/**
 * @Date:   2018-08-11
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-11
 */
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
//1017 A除以B
//思路：A有近千位，只能用数组存，B只有一位，然后利用数组来模拟除法，借助双指针
//高精度与低精度整数的除法操作，可以套用书中模板，只要遇到数组的秩必考虑越界
int main(){
	//freopen("D:\\codeBlockSpace\\input.txt","r",stdin);
	char strA[1050];
	int A[1050];
	int B;
	int ans[1005],top=0;
	scanf("%s %d",strA,&B);
	if(B==0){printf("%d %s",0,strA);return 0;}
	int n=strlen(strA);
	for(int i=0;i<n;i++)
		A[i]=strA[i]-'0';
	int a=0;//余数
	for(int i=0;i<n;i++){
		a=a*10+A[i];
		if(a<B){
			ans[i]=0;
		}else{
			ans[i]=a/B;
			a=a%B;
		}
	}
	int lo=0;
	//一个小问题没注意到，这里越界了导致错误
	while(lo<n&&ans[lo]==0)lo++;
	if(lo==n)printf("0");
	for(int i=lo;i<n;i++)printf("%d",ans[i]);
	printf(" %d",a);
	return 0;
}

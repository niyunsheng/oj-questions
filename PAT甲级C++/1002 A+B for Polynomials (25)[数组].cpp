/**
 * @Date:   2018-07-18
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-07-28
 */



//1002 A+B for Polynomials (25)
//将多项式表示为a*exp(b),因为最大1001项，所以用1001的数组分别存储
//这道题目的坑在于输入的系数中还有相等的，结果有0项的时候，只输出项数，这些题目中都没有说，难道让人去猜吗？
//PTA甲级都是这种没有难度，题目也不写清楚的题目吗？
#include"stdio.h"

int main(){
	int ta;
	float b[1001],tb;
	int k;
	for(int i=0;i<3;i++)for(int j=0;j<1001;j++)b[j]=0;
	for(int i=0;i<2;i++){
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			scanf(" %d %f",&ta,&tb);
			b[ta]+=tb;
		}
	}
	k=0;
	for(int i=0;i<1001;i++)
		if(b[i]!=0)k++;

	printf("%d",k);if(k==0)return 0;
	for(int i=1000;i>=0;i--)
		if(b[i]!=0)printf(" %d %0.1f",i,b[i]);
    return 0;
}

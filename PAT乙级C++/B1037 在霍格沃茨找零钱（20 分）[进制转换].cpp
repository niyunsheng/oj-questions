/**
 * @Date:   2018-08-06
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-06
 */
//1058 A+B in Hogwarts (20)与此题一模一样，只不过会有超出表示范围的情况，用longlong存储即可
#include<iostream>
using namespace std;

int main(){
    //freopen("D:\\CodeBlockSpace\\input.txt","r",stdin);
	int g1,s1,k1,g,s,k;
	scanf("%d.%d.%d %d.%d.%d",&g1,&s1,&k1,&g,&s,&k);
	int n1=g1*17*29+s1*29+k1,n=g*17*29+s*29+k;
	bool flag=n>=n1;
	if(flag)n-=n1;
	else{printf("-");n=n1-n;}
	k=n%29;
	s=(n/29)%17;
	g=n/(29*17);
	printf("%d.%d.%d",g,s,k);
	return 0;
}

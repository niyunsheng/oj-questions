/**
 * @Date:   2018-08-01
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-01
 */
//只需注意对输入的m取余即可
#include<iostream>
using namespace std;

int main(){
 //freopen("d:\\CodeBlockSpace\\input.txt","r",stdin);
 int n,m;
 if(n==0)return 0;
 scanf("%d %d",&n,&m);
 int* num=new int[n];
 m=m%n;//注意这里要取余，否则下面的n-m+i可能是负数，导致出错
 for(int i=0;i<n;i++)scanf("%d",num+i);
 for(int i=0;i<n-1;i++){
	 printf("%d ",num[(n-m+i)%n]);
 }
 printf("%d",num[(n-m+n-1)%n]);

 return 0;
}

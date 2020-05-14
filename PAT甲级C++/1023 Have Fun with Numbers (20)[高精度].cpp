/**
 * @Date:   2018-08-11
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-11
 */
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
//1023 Have Fun with Numbers (20)
//思路：高精度的乘法+hash元素个数
int main(){
	//freopen("D:\\codeBlockSpace\\input.txt","r",stdin);
	int A[30],B[30];//存储大整数实现A*2=B
	int bucket[10];//存储0-9十个数字的桶
	string ss;
	cin>>ss;
	int nA=ss.size(),nB;
	for(int i=nA-1;i>=0;i--)//把低位存储到秩小处
		A[nA-1-i]=ss[i]-'0';
	int c=0,d=0;//存储进位、部分和
	for(int i=0;i<nA;i++){//从低位到高位计算
		d=A[i]*2+c;
		B[i]=d%10;
		c=d/10;
	}
	bool flag=true;//判断A、B中数字是否一致
	if(c>0){B[nA]=c;nB=nA+1;flag=false;}
	else{
		nB=nA;
		fill(bucket,bucket+10,0);
		for(int i=0;i<nA;i++)
			bucket[A[i]]++;
		for(int i=0;i<nB;i++){
			bucket[B[i]]--;
			if(bucket[B[i]]<0){flag=false;break;}
		}
	}
	if(flag)printf("Yes\n");
	else printf("No\n");
	for(int i=nB-1;i>=0;i--)
		printf("%d",B[i]);
	return 0;
}

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
//1024 Palindromic Number (25)
//思路：高精度加法
int A[150],revA[150];//存储A及其反转，低位存低位数字，方便加法运算
bool isPalind(int n){//参数是元素的个数
	for(int i=0;i<n/2;i++)
		if(A[i]!=revA[i])
			return false;
	return true;

}
int main(){
	//freopen("D:\\codeBlockSpace\\input.txt","r",stdin);
	string ss;//原始数字
	int step;
	cin>>ss>>step;

	int n=ss.size();
	for(int i=0;i<n;i++){
		A[n-1-i]=ss[i]-'0';
		revA[i]=ss[i]-'0';
	}
	int cnt=0;//记录操作的次数,每次操作前判断上次操作后是否回文
	while(cnt<step){
		if(isPalind(n))break;
		int c=0,d=0;//存储进位、部分和
		for(int i=0;i<n;i++){
			d=A[i]+revA[i]+c;
			A[i]=d%10;
			c=d/10;
		}
		if(c>0){A[n]=c;n++;}
		for(int i=0;i<n;i++)
			revA[i]=A[n-i-1];
		cnt++;
	}
	for(int i=n-1;i>=0;i--)printf("%d",A[i]);
	printf("\n%d\n",cnt);
	return 0;
}

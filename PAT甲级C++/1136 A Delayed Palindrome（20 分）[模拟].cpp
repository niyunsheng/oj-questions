/**
 * @Date:   2018-08-29
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-29
 */
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
using namespace std;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
int vec[1020],ans[1020];
int n1=0,n2=0;
bool is_Pali(){
	_for(i,0,n1/2){
		if(vec[i]!=vec[n1-1-i])
			return false;
	}
	return true;
}
void printvec1(){
	_for(i,0,n1){
		printf("%d",vec[n1-1-i]);
	}
}
void printvec2(){
	_for(i,0,n1){
		printf("%d",vec[i]);
	}
}
int main(){
	//freopen("d:\\input.txt","r",stdin);
	n1=0,n2=0;
	string str;
	cin>>str;
	n1=str.size();
	_for(i,0,n1){vec[n1-1-i]=str[i]-'0';}
	if(n1==1){printf("%d is a palindromic number.\n",vec[0]);return 0;}
	if(is_Pali()){
		printvec1();
		printf(" is a palindromic number.\n");
		return 0;
	}
	int cnt=0;//计次
	while(cnt<10){

		int carry=0;
		_for(i,0,n1){
			int t=vec[i]+vec[n1-1-i]+carry;
			ans[i]=t%10;
			carry=t/10;
		}
		if(carry!=0){
			n2=n1+1;
			ans[n1]=carry;
		}else n2=n1;

		printvec1();
		printf(" + ");
		printvec2();
		printf(" = ");
		//复制向量
		n1=n2;
		_for(i,0,n1){vec[i]=ans[i];}
		printvec1();
		printf("\n");
		if(is_Pali()){
			printvec1();
			printf(" is a palindromic number.\n");
			return 0;
		}
		cnt++;
	}
	printf("Not found in 10 iterations.\n");
	return 0;
}

/**
 * @Date:   2018-08-06
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-06
 */
//这个题目是送分题啊，用库自带的string比较太容易了
#include<iostream>
#include<string>
using namespace std;

int main(){
    //freopen("D:\\CodeBlockSpace\\input.txt","r",stdin);
	string s1,s2,s3,n1,n2,t1="23:59:59",t2="00:00:00";
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		cin>>s1>>s2>>s3;
		if(s2<t1){n1=s1;t1=s2;}
		if(s3>t2){n2=s1;t2=s3;}
	}
	cout<<n1<<" "<<n2;
	return 0;
}

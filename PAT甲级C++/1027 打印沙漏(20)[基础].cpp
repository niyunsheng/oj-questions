/**
 * @Date:   2018-08-06
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-06
 */
//关键在于找到图形之间的数学关系即可
#include<iostream>
#include<cmath>
using namespace std;

int main(){
    //freopen("D:\\CodeBlockSpace\\input.txt","r",stdin);
	int n;
	char c;
	scanf("%d %c",&n,&c);
	int h=sqrt((n+1)/2);
	int remain=n-2*h*h+1;
	for(int i=0;i<h;i++){
		for(int j=0;j<i;j++)
			cout<<" ";
		for(int j=0;j<2*h-1-2*i;j++)
			cout<<c;
		cout<<endl;
	}
	for(int i=h-2;i>=0;i--){
		for(int j=0;j<i;j++)
			cout<<" ";
		for(int j=0;j<2*h-1-2*i;j++)
			cout<<c;
		cout<<endl;
	}
	cout<<remain<<endl;
	return 0;
}

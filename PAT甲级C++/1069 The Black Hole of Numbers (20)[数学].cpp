/**
 * @Date:   2018-08-10
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-29
 */
//A1069、B1019 数字黑洞 (20)
//思路：直接模拟，求出四位数的升序和降序数

#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	//freopen("d:\\input.txt","r",stdin);
	int n;
	scanf("%d",&n);
	int a,b;
	vector<int> tmp(4);
	if(n==6174)printf("%04d - %04d = %04d\n",7641,1467,6174);
	while(1){
		if(n==6174||n==0){break;}
		for(int i=0;i<4;i++){
			tmp[i]=n%10;
			n/=10;
		}
		sort(tmp.begin(),tmp.end());
		a=0;b=0;
		for(int i=3;i>=0;i--)a=a*10+tmp[i];
		for(int i=0;i<4;i++)b=b*10+tmp[i];
		n=a-b;
		printf("%04d - %04d = %04d\n",a,b,n);
	}
	return 0;
}

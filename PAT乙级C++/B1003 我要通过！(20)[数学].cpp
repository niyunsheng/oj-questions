/**
 * @Date:   2018-08-10
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-29
 */
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
//B1003 我要通过！
//思路：数学题，通过数学推导，可以得到正确的充要条件是a*b=c,分别表示a,b,c位置的‘A’的个数
int main(){
	//freopen("d:\\input.txt","r",stdin);
	int n;
	scanf("%d",&n);
	string ss;
	int a=0,b=0,c=0;//含义同思路提到的
	for(int i=0;i<n;i++){
		cin>>ss;
		int Ppos,Tpos,numP=0,numA=0,numT=0;//不直接表示三个位置A的个数，而是表示PAT三者的个数和PT的位置
		for(int i=0;i<ss.size();i++){
			switch(ss[i]){
			case 'P':numP++;Ppos=i;break;
			case 'A':numA++;break;
			case 'T':numT++;Tpos=i;break;
			default :printf("NO\n");goto loop;
			}
		}

		if(numP==1&&numT==1&&((Tpos-Ppos)!=1)&&(Ppos*(Tpos-Ppos-1)==(ss.size()-Tpos-1)))
			printf("YES\n");
		else
			printf("NO\n");
		loop:;
	}
	return 0;
}

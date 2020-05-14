/**
 * @Date:   2018-08-23
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-23
 */
#include<iostream>
#include<sstream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<ctime>
#include<algorithm>
using namespace std;
void printvec(vector<int>& vec){
	printf("%d",vec[0]);
	for(int i=1;i<vec.size();i++){
		printf(" %d",vec[i]);
	}
	printf("\n");
}
int main() {
	//freopen("d:\\input.txt","r",stdin);
	int n;
	cin>>n;
	int raise[6]={1500,4500,9000,35000,55000,80000};
	int tax_rate[7]={3,10,20,25,30,35,45};
	vector<int> tax(6),after_tax(6);
	tax[0]=raise[0]/100*3;
	after_tax[0]=raise[0]-tax[0]+3500;
	for(int i=1;i<6;i++){
		tax[i]=(raise[i]-raise[i-1])/100*tax_rate[i];
		tax[i]+=tax[i-1];
		after_tax[i]=raise[i]-tax[i]+3500;
	}
	//printvec(tax);	printvec(after_tax);
	if(n<=3500){cout<<n<<endl;return 0;}
	int r=0;
	int sum=0;
	while(r<6&&n>after_tax[r])r++;
	//cout<<r<<endl;
	if(r==0){
		sum=3500;
		sum+=(n-sum)/(100-tax_rate[r])*100;
	}else{
		sum=after_tax[r-1]+tax[r-1];
		sum+=(n+tax[r-1]-sum)/(100-tax_rate[r])*100;
	}
	cout<<sum<<endl;
	return 0;
}

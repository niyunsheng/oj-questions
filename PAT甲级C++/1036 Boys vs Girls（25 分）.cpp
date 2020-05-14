/**
 * @Date:   2018-09-07
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-07
 */
#include<iostream>
#include<string>
using namespace std;

int main(){
    //freopen("D:\\input.txt","r",stdin);
	string s1,s2,s3,n1,n2,t1,t2;
	int n,g,max=-1,min=101;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		cin>>s1>>s2>>s3>>g;
		if(s2=="M"&&g<min){n1=s1;t1=s3;min=g;}
		if(s2=="F"&&g>max){n2=s1;t2=s3;max=g;}
	}
	if(max==-1)cout<<"Absent"<<endl;
	else cout<<n2<<" "<<t2<<endl;
	if(min==101)cout<<"Absent"<<endl;
	else cout<<n1<<" "<<t1<<endl;

	if(min==101||max==-1)cout<<"NA";
	else cout<<max-min;
	return 0;
}

#include<iostream>
using namespace std;

int main(){
    //freopen("D:\\CodeBlockSpace\\input.txt","r",stdin);
	long long  g1,s1,k1,g,s,k;
	scanf("%lld.%lld.%lld %lld.%lld.%lld",&g1,&s1,&k1,&g,&s,&k);
	long long n1=g1*17*29+s1*29+k1,n=g*17*29+s*29+k;
	n+=n1;
	k=n%29;
	s=(n/29)%17;
	g=n/(29*17);
	printf("%lld.%lld.%lld",g,s,k);
	return 0;
}

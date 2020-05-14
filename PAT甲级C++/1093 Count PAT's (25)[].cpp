#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
//1093 Count PAT's (25)
//主要还是思路：任何的三个字母组合，只要有一个不同即视为不同组合，对于任意的A，其覆盖的PAT的个数为左边的P的个数*右边的T的个数，故可以用累计统计个数的方法，最后相加即可
//改进：减少不必要的运算的话，可以两轮循环来统计，第一轮统计P的个数，第二轮逆向统计T的个数，可以在统计t的个人的时候就计算ans的值
int main(){
	//freopen("d:\\codeBlockSpace\\input.txt","r",stdin);
	string ss;
	cin>>ss;
	int n=ss.size();
	long long ans=0;
	vector<int> Ps(n+1),As(n+1),Ts(n+1);//Ps[i]表示i位置以前有P的个数，则i位置后P的个数为Ps[n]-Ps[i+1]
	Ps[0]=0;As[0]=0,Ts[0]=0;
	for(int i=0;i<n;i++){
		switch(ss[i]){
		case 'P':Ps[i+1]=Ps[i]+1;As[i+1]=As[i];Ts[i+1]=Ts[i];break;
		case 'A':As[i+1]=As[i]+1;Ps[i+1]=Ps[i];Ts[i+1]=Ts[i];break;
		case 'T':Ts[i+1]=Ts[i]+1;Ps[i+1]=Ps[i];As[i+1]=As[i];break;
		}
	}
	for(int i=0;i<n;i++){
		if(ss[i]=='A'){
			ans+=Ps[i]*(Ts[n]-Ts[i+1]);
			ans%=1000000007;
		}

	}
	printf("%lld",ans);
	return 0;
}

//改进方法，降低了空间复杂度
#define M 1000000007

int main(int argc, char** argv) {
	//freopen("d:\\input.txt","r",stdin);
	string s;
	cin>>s;
	int countP=0,countT=0;
	if(s[0]=='P')countP++;
	_for(i,2,s.size()){
		if(s[i]=='T')countT++;
	}
	int cnt=0;
	_for(i,1,s.size()-1){
		if(s[i]=='A'){
			cnt+=countP*countT%M;
		}else if(s[i]=='P'){
			countP++;
		}
		if(s[i+1]=='T'){
			countT--;
		}
		cnt%=M;

	}
	cout<<cnt%M<<endl;
	return 0;
}

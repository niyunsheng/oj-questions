/**
 * @Date:   2018-08-10
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-29
 */
//其实更简单的办法就是用晴神的模板，无需给分数设置符号位，分子带符号位即可，每次运算后化简即可
//1081 Rational Sum (20)
//思路：建一个分数类，实现加减运算
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int GCD(int m,int n){
	if(m==0||n==0)return 1;
	if(m<n)swap(m,n);
	int t;
	while(m%n!=0){
		t=m;
		m=n;
		n=t%n;
	}
	return n;
}
struct ration{
	bool sign;//符号位,true表示正数
	int d1,d2;//分子分母
	ration operator+(ration& b){
		if(sign==b.sign){
			d1=d1*b.d2+d2*b.d1;
			d2=d2*b.d2;
		}else{
			d1=d1*b.d2-d2*b.d1;
			d2=d2*b.d2;
			if(!sign)d1=-d1;
			if(d1>0)sign=true;
			else {sign=false;d1=-d1;}
		}
		int m=GCD(d1,d2);//最大公约数
		d1/=m;d2/=m;
		if(d1==0){sign=true;d2=1;}
		return *this;
	}
	ration operator-(ration b){
		b.sign=!b.sign;
		return *this+b;
	}
	ration(bool ss,int dd1,int dd2):sign(ss),d1(dd1),d2(dd2){}
	ration(){}
};
int main(){
	//freopen("d:\\codeBlockSpace\\input.txt","r",stdin);
	int n;
	scanf("%d",&n);
	string ss;
	int d1,d2;
	vector<ration> vec;
	for(int i=0;i<n;i++){
		cin>>ss;
		if(ss[0]=='-'){
			sscanf(ss.c_str(),"-%d/%d",&d1,&d2);
			vec.push_back(ration(false,d1,d2));
		}else{
			sscanf(ss.c_str(),"%d/%d",&d1,&d2);
			vec.push_back(ration(true,d1,d2));
		}
	}
	ration ans(true,0,1);
	for(int i=0;i<n;i++)ans=ans+vec[i];
	if(!ans.sign)printf("-");

	int m=ans.d1/ans.d2;//整数部分
	if(m==0){
		if(ans.d2==1)printf("%d",ans.d1);
		else if(ans.d1==0)printf("0");
		else printf("%d/%d",ans.d1,ans.d2);
	}else{
		if(ans.d2==1)printf("%d",m);
		else printf("%d %d/%d",m,ans.d1%ans.d2,ans.d2);
	}

	return 0;
}

/**
 * @Date:   2018-08-15
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-15
 */
#include<iostream>
#include<vector>
#include<string>

#include<algorithm>
#include<cmath>
using namespace std;
//1073 Scientific Notation (20)
/*思路：找到E的位置，然后移动小数点的位置，分情况讨论的时候要细心准确不嫌复杂，其实做出来后，这个题目也不是很复杂

	*/
#define _for(i,a,b) for(int i=(a);i<(b);i++)
int getint(){
	int x;scanf("%d",&x);return x;
}
void printvec(vector<int>& vec){
	printf("%d",vec[0]);
	_for(i,1,vec.size()){
		printf(" %d",vec[i]);
	}
	printf("\n");
}

int main(){
	//freopen("D:\\codeBlockSpace\\input.txt","r",stdin);
	string num;
	cin>>num;
	int n=num.size(),rE=-1,rP;//E的位置，小数点的位置
	_for(i,0,n)if(num[i]=='.'){rP=i;break;}
	_for(i,0,n)if(num[i]=='E'){rE=i;break;}
	//提取指数位
	int frac;
	sscanf(num.substr(rE+2,n-rE-2).c_str(),"%d",&frac);
	if(rE==-1){cout<<num<<endl;return 0;}
	bool negE=false,negP=false;//表示指数的正负、底数的正负
	if(num[0]=='-'){negP=true;printf("%c",num[0]);}
	if(num[rE+1]=='-')negE=true;
	//首先理清楚各个数位位置
	//底数整数部分[1,rP)小数部分[rP+1,rE)
	//指数部分frac
	if(negE){
		if(rP-1>frac){//不需要补0
			cout<<num.substr(1,rP-1-frac);
			cout<<".";
			cout<<num.substr(rP-frac,frac);
			cout<<num.substr(rP+1,rE-1-rP);
		}else{//需补0
			cout<<"0.";
			while(frac>rP-1){
				cout<<"0";
				frac--;
			}
			cout<<num.substr(1,rP-1);
			cout<<num.substr(rP+1,rE-1-rP);
		}
	}else{
		cout<<num.substr(1,rP-1);
		if(frac<rE-1-rP){//不需补0
			cout<<num.substr(rP+1,frac);
			cout<<".";
			cout<<num.substr(rP+1+frac,rE-(rP+1+frac));
		}else {//补frac-(rE-2-rP)个0，无小数点
			cout<<num.substr(rP+1,rE-(rP+1));
			while(frac>rE-1-rP){cout<<"0";frac--;}
		}
	}
	return 0;
}

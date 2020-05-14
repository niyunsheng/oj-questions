/**
 * @Date:   2018-08-09
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-09
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;
//1092 To Buy or Not to Buy (20)
//题目挺简单，没什么特别注意的
int main(){
	//freopen("D:\\codeBlockSpace\\input.txt","r",stdin);
	string T,P;
	getline(cin,T);
	getline(cin,P);
	vector<int> hashtableP(256,0),hashtableT(256,0);

	for(int i=0;i<P.size();i++){
		hashtableP[P[i]]++;
	}
	for(int i=0;i<T.size();i++){
		hashtableT[T[i]]++;
	}
	int count1=0,count2=0;//分别记录多余和缺少的珠子
	bool flag=true;//记录是否缺少柱子
	for(int i=0;i<256;i++){
		if(hashtableP[i]<=hashtableT[i]){
			count1+=hashtableT[i]-hashtableP[i];
		}else{
			flag=false;
			count2+=hashtableT[i]-hashtableP[i];
		}
	}
	if(flag)printf("Yes %d\n",count1);
	else printf("No %d\n",-count2);
	return 0;
}

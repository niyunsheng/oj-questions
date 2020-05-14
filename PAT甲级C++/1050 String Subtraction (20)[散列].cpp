/**
 * @Date:   2018-08-09
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-09
 */
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
//1041 Be Unique (20)
//cin.getlin(a,10001)记住这个写法
//别在这个输入输出浪费时间了
int main(){
	//freopen("d:\\codeBlockSpace\\input.txt","r",stdin);

	char a[10001],b[10001];
	cin.getline(a,10001);
	cin.getline(b,10001);
	int na=strlen(a),nb=strlen(b);
	int Alph[256]={0};
	for(int i=0;i<nb;i++){
		Alph[b[i]]=1;
	}
	for(int i=0;i<na;i++){
		if(Alph[a[i]]==0)printf("%c",a[i]);
	}
	return 0;
}

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
//这个题目也没什么要注意的
bool isAlph(char a){
	return (a>='a'&&a<='z')||(a>='A'&&a<='Z');
}
char lower(char a){
	if(a>='A'&&a<='Z')return a-'A'+'a';
	else return a;
}
int main(){
	//freopen("D:\\codeBlockSpace\\input.txt","r",stdin);
	string T;
	getline(cin,T);
	vector<int> hashtableT(256,0);
	int sum=0;
	char Amax;
	for(int i=0;i<T.size();i++){
		hashtableT[lower(T[i])]++;
		if(isAlph(T[i])&&(hashtableT[lower(T[i])]>sum||(hashtableT[lower(T[i])]==sum&&lower(T[i])<Amax))){
			sum=hashtableT[lower(T[i])];
			Amax=lower(T[i]);
		}
	}
	printf("%c %d\n",Amax,sum);
	return 0;
}

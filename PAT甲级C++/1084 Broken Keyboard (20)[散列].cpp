/**
 * @Date:   2018-08-09
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-28
 */
 //其实本题考哈希，就是对应关系，用set大材小用了，用一个vector来存储改对应位置的字母是否出现过即可
 //哈希多用标志数组实现
#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;
//1084 Broken Keyboard (20)
//同B1029旧键盘
char upper(char a){
	if(a>='a'&&a<='z')return a+'A'-'a';
	else return a;
}
int main(){
	//freopen("D:\\input.txt","r",stdin);
	string T,P;
	set<char> alphabet;
	cin>>T;
	for(int i=0;i<T.size();i++){
		alphabet.insert(upper(T[i]));
	}
	cin>>P;
	for(int i=0;i<P.size();i++){
		alphabet.erase(upper(P[i]));
	}
	for(int i=0;i<T.size();i++){
		if(alphabet.count(upper(T[i]))!=0){
			cout<<upper(T[i]);
			alphabet.erase(upper(T[i]));
		}
	}
	return 0;
}

/**
 * @Date:   2018-08-09
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-09
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;
//B1033 旧键盘打字
//注意getline的应用和边界条件的判断，hashtable
char lower(char a){
	if(a>='A'&&a<='Z')return a+'a'-'A';
	else return a;
}
int main(){
	//freopen("D:\\codeBlockSpace\\input.txt","r",stdin);
	string T,P;
	vector<bool> hashtable(256,true);
	getline(cin,T);//注意，这里要用getline，即当没有字符坏的时候的情况
	for(int i=0;i<T.size();i++){
		hashtable[lower(T[i])]=false;
	}
	getline(cin,P);
	int count=0;
	for(int i=0;i<P.size();i++){
		if(P[i]>='A'&&P[i]<='Z'){
			if(hashtable['+']&&hashtable[lower(P[i])])
				cout<<P[i];
		}else{
			if(hashtable[P[i]])
				cout<<P[i];
		}
	}
	cout<<endl;
	return 0;
}

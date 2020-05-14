/**
 * @Date:   2018-08-09
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-09
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;
//1043 输出PATest（20 分）
//没什么要注意的
int main(){
	//freopen("D:\\codeBlockSpace\\input.txt","r",stdin);
	string T;
	getline(cin,T);
	vector<int> hashtableT(256,0);
	for(int i=0;i<T.size();i++){
		hashtableT[T[i]]++;
	}
	char A[6]={'P','A','T','e','s','t'}
	bool flag=true;
	while(flag){
		flag=false;
		for(int i=0;i<6;i++)
			if(hashtableT[A[i]]>0){printf("%c",A[i]);hashtableT[A[i]]--;flag=true;}
		/*这里重复写了六次，不妨开一个数组分别是这六个字符
		if(hashtableT['P']>0){printf("P");hashtableT['P']--;flag=true;}
		if(hashtableT['A']>0){printf("A");hashtableT['A']--;flag=true;}
		if(hashtableT['T']>0){printf("T");hashtableT['T']--;flag=true;}
		if(hashtableT['e']>0){printf("e");hashtableT['e']--;flag=true;}
		if(hashtableT['s']>0){printf("s");hashtableT['s']--;flag=true;}
		if(hashtableT['t']>0){printf("t");hashtableT['t']--;flag=true;}
		*/
	}
	return 0;
}

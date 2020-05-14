/**
 * @Date:   2018-08-23
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-23
 */
//正确答案，要掌握stringstream的写法，以及对一行数据的处理，用很原始的cin加getchar不知道为什么错了，不过，为了方便，还是尽量用stringstream吧
#include<iostream>
#include<sstream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	//freopen("d:\\input.txt","r",stdin);
	string strline;
	cin>>strline;
	int m=26;
	vector<int> para(m,0);//0表示不存在，1表示不带参数，2表示带参数
	for(int i=0;i<strline.size();i++){
		if(strline[i]==':'){para[strline[i-1]-'a']=2;}
		else  para[strline[i]-'a']=1;
	}
	int n;
	scanf("%d",&n);cin.ignore();
	vector<string> argu(m);
	for(int i=0;i<n;i++){
		getline(cin,strline);
		stringstream ss(strline);

		string str;
		ss>>str;
		while(ss>>str){
			if (str[0] == '-') {
				int r = str[1] - 'a';
				if (para[r] == 0) { // 非合法选项
					break;//没有这一句的话，输入无效命令并不会停止
				}
				else if (para[r] == 1) {
					argu[r]=" ";
				}
				else if (para[r] == 2) {
					if (ss.eof()) break; // 有参数选项没有输入参数
					ss >> str;
					argu[r] = str;
				}
			}
			else { // 非合法参数
				break;
			}
		}

		cout << "Case " << i+1<< ":";
		for (int j = 0; j<26; j++) {
			if (para[j] == 1 && argu[j] != "") {
				cout << " -" << char(j + 'a');
			}
			if (para[j] == 2 && argu[j] != "") {
				cout << " -" << char(j + 'a') <<" "<< argu[j];
			}
			argu[j] = "";
		}
		cout<<endl;
	}
	return 0;
}


//还是不知道自己写的哪里出错了
#include<iostream>
#include<sstream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	freopen("d:\\input.txt","r",stdin);
	string str;
	cin>>str;
	int m='z'-'a'+1;
	vector<int> para(m,0);//0表示不存在，1表示不带参数，2表示带参数
	for(int i=0;i<str.size();i++){
		if(str[i]==':'){para[str[i-1]-'a']=2;}
		else  para[str[i]-'a']=1;
	}
	int n;
	scanf("%d",&n);
	vector<string> ans(m);//各个选项的参数，如果有的话
	ans.resize(m);
	vector<int> vis(m,0);//该选项在结果中是否出现，0表示未出现，1表示出现
	char c;
	int flag,r;//表示这次是读命令还是参数。0表示命令，1表示参数 ;r表示上次命令的序号
	for(int i=0;i<n;i++){

		ans.clear();
		flag=0;
		fill(vis.begin(),vis.end(),0);
		cin>>str; //cout<<"@"<<str;
		while(1){
			c=getchar();
			if(c=='\n')break;
			cin>>str;
			//cout<<str;
			if(flag==0){
				r=str[1]-'a';
				if(str.size()==2&&str[0]=='-'&&str[1]>='a'&&str[1]<='z'&&para[r]!=0){
					if(para[r]==1)vis[r]=1;
					else if(para[r]==2)flag=1;
				}else{
					while(1){
						c=getchar();
						if(c=='\n')break;
						cin>>str;
					}
					break;
				}
			}else{
				if(str[0]=='-'){
					if(ans[r].size()==0)vis[r]=0;
					while(1){
						c=getchar();
						if(c=='\n')break;
						cin>>str;
					}
					break;
				}else{
					ans[r]=str;
					vis[r]=1;
					flag=0;
				}
			}
		}
		printf("Case %d:",i+1);
		for(int i=0;i<m;i++){
			if(vis[i]){
				if(para[i]==2)
					cout<<" -"<<(char)('a'+i)<<" "<<ans[i];
				else
					cout<<" -"<<(char)('a'+i);
			}
		}
		cout<<endl;
	}
	return 0;
}

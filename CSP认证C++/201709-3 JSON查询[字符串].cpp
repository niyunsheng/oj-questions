/**
 * @Date:   2018-09-13
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-13
 */
//201709-3 JSON查询
//不知道具体错误，80分，但是这种用栈实现的稍微复杂点
//海岛老师的做法是状态空间查询，而不直接存储各个结构体之间的嵌套关系。也是很好的办法。
#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<set>
#include<map>
#include<stack>
#include<sstream>
#include<vector>
#include<queue>
using namespace std;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
const int MAXN=1005;
int M,N;
string str;
struct node{
	map<string,pair<string,node*> > data;
	//节点数据的类型根据map值域中string的值来判断，非空表示值是字符串，空表示值是节点
	node(){}
};
void getstr(const string& str,string& st1,int& j){
	j++;
	while(str[j]!='"'){
		if(str[j]=='\\')j++;
		st1+=str[j];
		j++;
	}
	//cout<<st1<<endl;
}
void getstr2(const string& str,string& st2,int& j){
	st2.clear();
	while(j<str.size()&&str[j]!='.'){
		st2+=str[j];j++;
	}
	if(str[j]=='.')j++;
	//cout<<"getstr2:"<<st2<<endl;
}
int main(){
	//freopen("d:\\input.txt","r",stdin);
	cin>>N>>M;getchar();
	int cnt1=0,cnt2=0;//cnt1记录读取:的个数,0个表示输入键值，1表示输入值
	stack<node*> mystack;
	string name;

	_for(i,0,N){
		getline(cin,str);
		_for(j,0,str.size()){
			if(str[j]==' ')continue;

			if(str[j]=='{'){
				cnt1=0;
				node* cur=new node();
				if(mystack.size()>0){
					mystack.top()->data[name]=make_pair("",cur);
				}
				mystack.push(cur);
			}

			if(str[j]==':')cnt1=1;
			if(str[j]=='"'){
				string st1;
				getstr(str,st1,j);
				if(cnt1==0){
					name=st1;
				}else{
					mystack.top()->data[name].first=st1;
				}
			}
			if(str[j]==',')cnt1=0;
			if(str[j]=='}'){
				if(mystack.size()==1)break;
				else mystack.pop();
			}

		}
	}
	map<string,pair<string,node*> > cur=mystack.top()->data;
	string st2;
	_for(i,0,M){
		cur=mystack.top()->data;
		cin>>str;
		//cout<<str<<endl;
		int j=0;
		stack<string> sta;
		getstr2(str,st2,j);
		while(j!=str.size()){
			sta.push(st2);
			cur=cur[st2].second->data;
			getstr2(str,st2,j);
		}
		if(cur.count(st2)==0){
			cout<<"NOTEXIST\n";
			continue;
		}
		//printf("%d:   ",i);
		if(cur[st2].first=="")
			printf("OBJECT\n");
		else cout<<"STRING "<<cur[st2].first<<endl;

	}
	return 0;
}

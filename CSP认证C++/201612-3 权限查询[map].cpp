/**
 * @Date:   2018-09-09
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-09
 */
#include<cstdio>
#include<iostream>
#include<set>
#include<vector>
#include<map>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

//201612-3 权限查询
#define MAXN 1005
#define INF 0x7fffffff
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
int getint(){int x;scanf("%d",&x);return x;}
struct node{
	int id,level;
	node(int c,int l):id(c),level(l){}
};
int  P,R,U,Q;
map<int,int> privilege;
set<int> alluser;
map<int,vector<int> > user;
map<int,vector<node> > role;

map<string,int> ID;
vector<string> name;
int initP(string& str){
	int ans=str.find(":");
	if(ans!=-1){
		int t;
		sscanf(str.substr(ans+1,str.size()-ans-1).c_str(),"%d",&t);
		str=str.substr(0,ans);
		return t;
	}else return ans;
}
int getID(const string& str){
	if(ID.count(str)!=0)return ID[str];
	name.push_back(str);
	return ID[str]=name.size()-1;
}
int main(){
	//freopen("d:\\input.txt","r",stdin);
	P=getint();
	string commd;
	_for(i,0,P){
		cin>>commd;
		int tp=initP(commd);
		//cout<<tp<<commd<<endl;
		int tid=getID(commd);
		privilege[tid]=tp;
	}
	R=getint();
	_for(i,0,R){
		cin>>commd;
		int trole=getID(commd);
		int t=getint();
		_for(j,0,t){
			cin>>commd;
			int tp=initP(commd);
			int tid=getID(commd);
			role[trole].push_back(node(tid,tp));
		}
		//_for(j,0,t)cout<<name[role[trole][j].id]<<" "<<role[trole][j].level<<endl;
	}
	U=getint();
	_for(i,0,U){
		cin>>commd;
		int tuser=getID(commd);
		alluser.insert(tuser);
		int t=getint();
		_for(j,0,t){
			cin>>commd;
			user[tuser].push_back(getID(commd));
		}
		//_for(j,0,t)cout<<name[user[tuser][j]]<<endl;
	}
	Q=getint();
	string s1,s2;
	_for(i,0,Q){
		cin>>s1>>s2;
		//cout<<s1<<" "<<s2<<" ";
		int tuser=getID(s1);
		if(alluser.count(tuser)==0){printf("false\n");continue;}
		int tp=initP(s2);
		int tid=getID(s2);
		if(privilege.count(tid)==0){printf("false\n");continue;}
		if(tp==-1&&privilege[tid]!=-1){//输出最高权限等级的情况
			int maxp=-1;
			vector<int> v1=user[tuser];
			_for(j,0,v1.size()){
				vector<node> v2=role[v1[j]];
				_for(k,0,v2.size()){
					if(v2[k].id==tid)maxp=max(maxp,v2[k].level);
				}
			}
			if(maxp==-1)printf("false\n");
			else printf("%d\n",maxp);
			continue;
		}else{
			bool flag=false;
			vector<int> v1=user[tuser];
			_for(j,0,v1.size()){
				vector<node> v2=role[v1[j]];
				_for(k,0,v2.size()){
					if(v2[k].id==tid&&v2[k].level>=tp)flag=true;
				}
			}
			if(flag)printf("true\n");
			else printf("false\n");
			continue;
		}
	}
	return 0;
}

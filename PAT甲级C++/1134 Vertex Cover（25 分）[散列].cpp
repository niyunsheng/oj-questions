/**
 * @Date:   2018-09-01
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-01
 */
//根据数据范围，将边存储到set里，每次查询遍历一次边即可
#include<iostream>
#include<string>
#include<cstring>
#include<set>
#include<map>
#include<queue>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
int getint(){int x;scanf("%d",&x);return x;}
void printvec(vector<int>& vec){
	cout<<vec[0];
	_for(i,1,vec.size()){
		cout<<" "<<vec[i];
	}
	cout<<endl;
}

const int MAXN=10000;
vector<vector<int> > grid(MAXN);
set<pair<int,int> > edge;//边及其出现次数
int main(){
    //freopen("d:\\input.txt","r",stdin);
	int N,M,K,nv;
	int c1,c2;
	cin>>N>>M;
	_for(i,0,M){
		cin>>c1>>c2;
		//grid[c1].push_back(c2);
		//grid[c2].push_back(c1);
		edge.insert(make_pair(c1,c2));
		//edge.insert(make_pair(c2,c1));
	}
	cin>>K;
	_for(i,0,K){
		cin>>nv;
		set<int> vertex;
		_for(j,0,nv){
			cin>>c1;
			vertex.insert(c1);
			/*
			_for(k,0,grid[c1].size()){
				c2=grid[c1][k];
				edge[make_pair(c1,c2)]=1;
				edge[make_pair(c2,c1)]=1;
			}*/
		}
		int flag=0;
		for(auto it=edge.begin();it!=edge.end();it++)
			if(vertex.count(it->first)==0&&vertex.count(it->second)==0){
				flag=1;break;
			}
		if(flag==0)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}

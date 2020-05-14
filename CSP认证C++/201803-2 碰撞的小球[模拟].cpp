/**
 * @Date:   2018-08-23
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-23
 */
#include<iostream>
#include<sstream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
int main() {
	//根据题意模拟即可,由于t最大100，所以采用标记状态、步进的方法计算
	//freopen("d:\\input.txt","r",stdin);
	int n,L,t;
	scanf("%d %d %d",&n,&L,&t);
	map<int,int> tmap,mmap;//小球位置和id的映射
	vector<int> vec(n),statue(n,1);//statue=1表示向右,-1表示向左
	for(int i=0;i<n;i++){scanf("%d",&vec[i]);tmap[vec[i]]=i;}
	sort(vec.begin(),vec.end());
	for(int i=0;i<n;i++){
		mmap[tmap[vec[i]]]=i;
	}
	//更新0时刻的状态
	if(vec[n-1]==L)statue[n-1]=-1;

	for(int cur=1;cur<=t;cur++){
		//更新下一刻坐标值
		for(int i=0;i<n;i++)
			vec[i]+=statue[i];
		//更新下一时刻节点状态
		if(vec[0]==0)statue[0]=1;
		for(int i=0;i<n-1;i++){
			if(vec[i]==vec[i+1]){statue[i]=-1;statue[i+1]=1;}
		}
		if(vec[n-1]==L)statue[n-1]=-1;
	}
	printf("%d",vec[mmap[0]]);
	for(int i=1;i<n;i++)printf(" %d",vec[mmap[i]]);
	cout<<endl;
	return 0;
}

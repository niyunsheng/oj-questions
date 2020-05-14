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
#include<queue>
#include<map>
#include<set>
#include<ctime>
#include<algorithm>
using namespace std;
void printvec(vector<int>& vec){
	printf("%d",vec[1]);
	for(int i=2;i<vec.size();i++){
		printf(" %d",vec[i]);
	}
	printf("\n");
}
int main() {
	//freopen("d:\\input.txt","r",stdin);
	int n,m;
	cin>>n;
	vector<int> vec(n+1),vmap(n+1);//vec记录当前队列情况，vmap[i]=j记录i同学现在在j位置，均从1开始

	for(int i=0;i<n+1;i++){vec[i]=i;vmap[i]=i;}
	cin>>m;
	int id,dis;
	for(int i=0;i<m;i++){
		cin>>id>>dis;
		int r=vmap[id],tar=r+dis;
		if(dis>0){
			for(int j=r;j<tar;j++){
				vmap[vec[j+1]]--;
				vec[j]=vec[j+1];
			}
			vmap[id]=tar;
			vec[tar]=id;
		}else{
			for(int j=r;j>tar;j--){
				vmap[vec[j-1]]++;
				vec[j]=vec[j-1];
			}
			vmap[id]=tar;
			vec[tar]=id;
		}
		//printvec(vec);
	}

	printvec(vec);

	return 0;
}

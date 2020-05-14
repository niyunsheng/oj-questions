/**
 * @Date:   2018-08-24
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-24
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
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
void printvec(vector<int>& vec){
	printf("%d",vec[0]);
	for(int i=1;i<vec.size();i++){
		printf(" %d",vec[i]);
	}
	printf("\n");
}

int main() {
	//freopen("d:\\input.txt","r",stdin);
	//freopen("d:\\output.txt","w",stdout);
	int n;
	cin>>n;
	vector<int> ans;
	vector<vector<int> > vec(n,vector<int>(n));

	int statue=0;//当前移动的状态,0表示斜上方移动，1表示斜下方移动
	int pathx[2]={-1,1},pathy[2]={1,-1};
	_for(i,0,n){
		_for(j,0,n){
			cin>>vec[i][j];
		}
	}
	if(n==1){cout<<vec[0][0]<<endl;return 0;}
	int i=0,j=0;
	while(1){
		//printf("push i=%d j=%d\n",i,j);
		ans.push_back(vec[i][j]);
		while(i+pathx[statue]>=0&&i+pathx[statue]<n&&j+pathy[statue]>=0&&j+pathy[statue]<n){
			i+=pathx[statue];j+=pathy[statue];
			ans.push_back(vec[i][j]);
			//printf("push i=%d j=%d\n",i,j);
		}
		if(i+j==n-1){
			if(statue)j++;
			else i++;
			statue=1-statue;
			break;
		}else {
			if(statue)i++;
			else j++;
		}
		statue=1-statue;
	}
	while(1){
		//printf("push i=%d j=%d statue=%d\n",i,j,statue);
		ans.push_back(vec[i][j]);
		while(i+pathx[statue]>=0&&i+pathx[statue]<n&&j+pathy[statue]>=0&&j+pathy[statue]<n){
			i+=pathx[statue];j+=pathy[statue];
			ans.push_back(vec[i][j]);
			//printf("push i=%d j=%d\n",i,j);
		}
		if(i==n-1&&j==n-1){

			break;
		}else {
			if(statue)j++;
			else i++;
			statue=1-statue;
		}
	}
	printvec(ans);
	return 0;
}

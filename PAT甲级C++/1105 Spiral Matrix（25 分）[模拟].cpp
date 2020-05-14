/**
 * @Date:   2018-08-30
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-30
 */
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
bool cmp(int a,int b){
	return a>b;
}
bool is_legal(int x,int y,int m,int n,vector<vector<int> >& vis){
	return x>=0&&x<n&&y>=0&&y<m&&vis[y][x]==0;
}
void printvec(vector<int>& vec){
	cout<<vec[0];
	_for(i,1,vec.size()){
		cout<<" "<<vec[i];
	}
	cout<<endl;
}
int main() {
	//freopen("d:\\input.txt","r",stdin);
	int N,t,m=1,n;
    cin>>N;
	while(m*m<N)m++;
	while(N%m!=0)m++;
	n=N/m;
	vector<int> vec(N);
	vector<vector<int> > ans(m,vector<int>(n)),vis(m,vector<int>(n,0));//vis为0表示未填过数据
	_for(i,0,N){
		cin>>vec[i];
	}
	sort(vec.begin(),vec.end(),cmp);
	int x[4]={1,0,-1,0},y[4]={0,1,0,-1};
	int curx=0,cury=0,nx,ny;//x对应列坐标n,y对应列坐标m
	int top=0;//vec向量中的秩
	ans[cury][curx]=vec[top++];
	vis[cury][curx]=1;
	while(top<N){
		_for(i,0,4){
			while(is_legal(curx+x[i],cury+y[i],m,n,vis)){
				curx+=x[i];cury+=y[i];
				ans[cury][curx]=vec[top++];
				vis[cury][curx]=1;
			}
		}
	}
	_for(i,0,m){
		printvec(ans[i]);
	}
	return 0;
}

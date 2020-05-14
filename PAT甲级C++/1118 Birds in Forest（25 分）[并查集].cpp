/**
 * @Date:   2018-09-01
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-07
 */
//相比1107，本题并没有询问有多少张照片属于一棵树，那么，就不需要对照片进行处理，只需要将照片中的鸟纳入并查集即可。
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
const int MAXN=10002;
vector<int> fa(MAXN,-1),vis(MAXN,0);
int numsum=0,numset=0;
int findroot(int x){
	return fa[x]==-1?x:fa[x]=findroot(fa[x]);
}
void combine(int x,int y){
	int fx=findroot(x),fy=findroot(y);
	if(fx!=fy)
		fa[fx]=fy;
}

int main(){
    //freopen("d:\\input.txt","r",stdin);
	int N,K,Q,t1,t2;
	cin>>N;
	_for(i,0,N){
		cin>>K;
		cin>>t1;
		vis[t1]=1;
		_for(j,1,K){
			cin>>t2;
			vis[t2]=1;
			combine(t2,t1);
		}
	}
	_for(i,0,MAXN){
		if(vis[i]==1){
			numsum++;
			int r=findroot(i);
			if(r==i)numset++;
		}
	}
	printf("%d %d\n",numset,numsum);
	cin>>Q;
	_for(i,0,Q){
		cin>>t1>>t2;
		if(findroot(t1)==findroot(t2))
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
//9月4日更，类1107方法，麻烦且没有必要，但有必要记录

int n,k,t,fa[20005]={0},num[10001]={0};//图节点0-10000，鸟节点10001-19999
int findroot(int x){
	return fa[x]==0?x:fa[x]=findroot(fa[x]);
}
void combine(int x,int y){
	int fx=findroot(x);
	int fy=findroot(y);
	if(fx!=fy)fa[fx]=fy;
}
//每一只鸟属于一张图，每一张图属于另一张图

int main(){
	//freopen("in.txt","r",stdin);
	cin>>n;
	_for(i,1,n+1){
		cin>>k;
		_for(j,0,k){
			cin>>t;
			if(fa[10000+t]==0)fa[10000+t]=i;
			else combine(i,10000+t);
		}
	}
	int cnt=0,maxbird=1;
	while(fa[maxbird+10000]!=0){
		maxbird++;
		//printf("%d %d\n",maxbird,findroot(maxbird+10000));
	}
	_for(i,1,n+1){
		if(fa[i]==0)cnt++;
		maxbird=max(maxbird,num[i]);
	}
	printf("%d %d\n",cnt,maxbird-1);
	int q,c1,c2;
	cin>>q;
	while(q--){
		cin>>c1>>c2;
		if(findroot(c1+10000)==findroot(c2+10000))printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}

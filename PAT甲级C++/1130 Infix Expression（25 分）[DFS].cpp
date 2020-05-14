/**
 * @Date:   2018-08-31
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-31
 */
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
#define MAXN 25
string val[MAXN];
int lc[MAXN];
int rc[MAXN];
int vis[MAXN];
int root;
void DFS(int cur){
	if(cur==0)return;
	if(lc[cur]!=0||rc[cur]!=0){
		if(cur!=root)cout<<"(";
		DFS(lc[cur]);
		cout<<val[cur];
		DFS(rc[cur]);
		if(cur!=root)cout<<")";
	}else{
		cout<<val[cur];
	}
}

int main(){
	//freopen("D:\\input.txt","r",stdin);
	int N,c1,c2;
	memset(vis,0,sizeof(vis));//0表示未出现
	memset(lc,0,sizeof(lc));
	memset(rc,0,sizeof(rc));//0表示没有孩子
	vector<bool> vis(25,false);//未在孩子节点中出现过的是根节点
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>val[i]>>c1>>c2;
		if(c1!=-1){vis[c1]=1;lc[i]=c1;}
		if(c2!=-1){vis[c2]=1;rc[i]=c2;}
	}

	for(int i=1;i<=N;i++)if(vis[i]==0){root=i;break;}
	DFS(root);
	cout<<endl;
	return 0;
}

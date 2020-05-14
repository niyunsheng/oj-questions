/**
 * @Date:   2018-08-31
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-31
 */
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

bool vis[1005];//行出现过
bool hash1[2005];//正对角线
bool hash2[2005];//斜对角线
int vec[1005];//接收数据
int main(){
	//freopen("D:\\input.txt","r",stdin);
	int K,n;
	scanf("%d",&K);
	for(int i=0;i<K;i++){
		memset(vis,0,sizeof(vis));
		memset(hash1,0,sizeof(hash1));
		memset(hash2,0,sizeof(hash2));
		scanf("%d",&n);
		for(int j=1;j<=n;j++){
			scanf("%d",vec+j);
		}
		bool flag=true;
		for(int j=1;j<=n;j++){
			if(!vis[vec[j]])vis[vec[j]]=true;
			else{flag=false;break;}
			if(!hash1[vec[j]-j+1000]&&!hash2[vec[j]+j]){hash1[vec[j]-j+1000]=true;hash2[vec[j]+j]=true;}
			else{flag=false;break;}
		}
		if(flag)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

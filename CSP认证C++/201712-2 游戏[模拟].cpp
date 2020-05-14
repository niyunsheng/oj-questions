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
#include<ctime>
#include<algorithm>
using namespace std;
//原来是每看懂题意，自己以为是k倍数才除去，原来末尾是k也除去，这种简单题目丢分太可惜了
int main() {
	//freopen("d:\\input.txt","r",stdin);
	int n,k;
	long long rank=0,num=0;//小朋友编号及其报数
	cin>>n>>k;
	//srand(time(NULL));n=rand()%1000+1;k=rand()%9+1;
	//printf("n=%d k=%d\n",n,k);
	vector<int> vis(n,1);//0表示该小朋友出局
	int re=n;//剩余的小朋友个数；
	while(re>1){
		if(vis[rank%n]==1){
			num++;
			if(num%k==0||num%10==k){
				vis[rank%n]=0;
				re--;
			}
		}
		rank++;
	}
	for(int i=0;i<n;i++)if(vis[i]!=0){cout<<i+1<<endl;break;}
	return 0;
}

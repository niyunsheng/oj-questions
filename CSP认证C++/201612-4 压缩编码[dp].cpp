/**
 * @Date:   2018-09-09
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-09
 */
//201612-4 压缩编码
//第一版错误解法：建树,类似haffman编码树，只不过每次合并树的规则不同,每次选取相邻节点和最小的节点合并
//但是这个算法是不能用贪心的，因为不能满足无后效性，局部最优解并不是全局最优解。正确的解法是动态规划
#define MAXN 1005
#define INF 0x7fffffff
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
int N,cnt;

struct node{
	int v;
	node *lc,*rc;
	node(int x):v(x),lc(NULL),rc(NULL){}
};
vector<node*> leaf;
node* root;
int getint(){int x;scanf("%d",&x);return x;}

void DFS(node* cur,int h){
	if(cur->lc==NULL){
		//cout<<cur->v<<" "<<h<<endl;
		cnt+=h*(cur->v);
		return;
	}
	//printf("%d %d %d %d\n",cur->v,cur->lc->v,cur->rc->v,h);
	DFS(cur->lc,h+1);
	DFS(cur->rc,h+1);
}
int main(){
	//freopen("d:\\input.txt","r",stdin);
	scanf("%d",&N);
	_for(i,0,N){
		node* cur=new node(getint());
		leaf.push_back(cur);
	}
	while(leaf.size()!=1){
		//_for(i,0,leaf.size())cout<<leaf[i]->v<<" ";cout<<endl;
		int minf=INF;
		vector<int> minid;
		_for(i,0,leaf.size()-1){
			if(leaf[i]->v+leaf[i+1]->v<minf){
				minf=leaf[i]->v+leaf[i+1]->v;
				minid.clear();
				minid.push_back(i);minid.push_back(i+1);
			}else if(leaf[i]->v+leaf[i+1]->v==minf&&i!=minid.back()){
				minid.push_back(i);minid.push_back(i+1);
			}
		}
		for(int i=minid.size()-2;i>=0;i-=2){
			node* cur=new node(leaf[minid[i]]->v+leaf[minid[i+1]]->v);
			cur->lc=leaf[minid[i]];cur->rc=leaf[minid[i+1]];
			leaf[minid[i]]=cur;
			leaf.erase(leaf.begin()+minid[i+1]);
			//cout<<cur->v<<endl;
		}
	}
	cnt=0;
	DFS(leaf[0],0);
	printf("%d\n",cnt);
	return 0;
}
//第二版：动态规划解法
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

//201612-4 压缩编码
#define MAXN 1005
#define INF 0x7fffffff
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
int getint(){int x;scanf("%d",&x);return x;}
int N,cnt;
int dp[MAXN][MAXN];//dp[i][j]表示单词i-j之间所有单词的最小编码长度
int dpk[MAXN][MAXN];
int sum[MAXN];//表示0-i之间所有单词的频率和
int v[MAXN];
//dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]);
//用平行四边形优化，dpk[i][j]表示dp[i][j]所采用的中间的k值，由平行四边形优化可知，dpk[i][j-1]<=dpk[i][j]<=dpk[i+1][j]
int main(){
	//freopen("d:\\input.txt","r",stdin);
	//初始化
	N=getint();
	_for(i,0,N){
		cin>>v[i];
		dp[i][i]=0;
		dpk[i][i]=i;
		sum[i]=(i==0?v[i]:sum[i-1]+v[i]);
	}
	_for(d,1,N){
		_for(i,0,N){
			int j=i+d;
			dp[i][j]=INF;
			_for(k,i,j)
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+sum[j]-sum[i]+v[i]);

			/*
			//下面是采用平行四边形优化的代码，毫秒级别。上面不用平行四边形优化的只能得80分，有递归解法，可以的满分，2.9秒
			int mink;
			_for(k,dpk[i][j-1],dpk[i+1][j]+1){
				if(dp[i][k]+dp[k+1][j]+sum[i][j]<dp[i][j]){
					dp[i][j]=dp[i][k]+dp[k+1][j]+sum[j]-sum[i]+v[i]);
					mink=k;
				}
				dpk[i][j]=mink;
				//printf("%d %d %d\n",i,j,dpk[i][j]);
			}
			*/
		}
	}
	printf("%d\n",dp[0][N-1]);
	return 0;
}
//没有优化的递归解法，也可满分
/* CCF201612-4 压缩编码 */

#include <iostream>
#include <cstring>

using namespace std;

const int INT_MAX2 = 0x7F7F7F7F;
const int N = 1000;

int v[N+1];
int sum[N+1];
int dp[N+1][N+1];

int solve(int l, int r)
{
    if(dp[l][r] == INT_MAX2)
        for(int i = l; i < r; i++)
            dp[l][r] = min(dp[l][r], solve(l, i) + solve(i+1, r) + sum[r] - sum[l-1]);

    return dp[l][r];
}

int main()
{
    int n;

    // 变量初始化：置为最大值
    memset(dp, INT_MAX2, sizeof(dp));

    // 输入数据
    cin >> n;
    sum[0] = 0;
    for(int i=1; i<=n; i++) {
        cin >> v[i];

        sum[i] = sum[i-1] + v[i];
        dp[i][i] = 0;
    }

    // DP计算
    solve(1, n);

    // 输出结果
    cout << dp[1][n] << endl;

    return 0;
}

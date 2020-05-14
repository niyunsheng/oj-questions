
/*01背包解法，加入choice数组记录是否选择该物品，将物品从大到小排序
dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+w[i]),相等时，说明可以选择更小的元素，优先选择前者，即选当前元素
*/
#include<iostream>
#include<cstring>
#include<vector>
#include<stack>
#include<algorithm>
#include<functional>
using namespace std;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
#define MAXN 10004
#define MAXM 102
int dp[MAXN][MAXM];
bool choice[MAXN][MAXM];
int N,M;
vector<int> v(MAXN),ans;

int main(){
    //freopen("d:\\input.txt","r",stdin);
	cin>>N>>M;

	_for(i,1,N+1){
		scanf("%d",&v[i]);
	}
	sort(v.begin()+1,v.begin()+N+1,greater<int>() );
	_for(i,0,N+1)dp[i][0]=0;
	_for(j,0,M+1)dp[0][j]=0;
	_for(i,1,N+1){
		_for(j,1,M+1){
			if(j<v[i]){
				dp[i][j]=dp[i-1][j];
				choice[i][j]=false;
			}else{
				if(dp[i-1][j-v[i]]+v[i]>=dp[i-1][j]){
					choice[i][j]=true;
					dp[i][j]=dp[i-1][j-v[i]]+v[i];
				}else{
					choice[i][j]=false;
					dp[i][j]=dp[i-1][j];
				}
			}
		}
	}
	if(dp[N][M]!=M)printf("No Solution\n");
	else{
		int i=N,j=M;
		while(i>0&&j>0){
			if(choice[i][j]){
				ans.push_back(v[i]);
				j=j-v[i];i=i-1;
			}else{
				i--;
			}
		}
		printf("%d",ans[0]);
		_for(i,1,ans.size())printf(" %d",ans[i]);
		printf("\n");
	}
	return 0;
}




//DFS超时了快一半
#include<iostream>
#include<cstring>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
#define MAXN 10004
void printvec(vector<int>& v){
	printf("%d",v[0]);
	_for(i,1,v.size())printf(" %d",v[i]);
	printf("\n");
}
int N,M;
vector<int> vec(MAXN),ans;
bool flag;
void DFS(int step,int sum){
	_for(i,step,N){
		if(!flag){
			if(vec[step]==sum){
				ans.push_back(vec[step]);
				flag=true;
				break;
			}else{
				if(vec[step]>sum){
					break;
				}else{
					ans.push_back(vec[step]);
					DFS(step+1,sum-vec[step]);
					if(!flag){
						ans.pop_back();
						DFS(step+1,sum);
					}
				}
			}
		}
	}
}
int main(){
    //freopen("d:\\input.txt","r",stdin);

	cin>>N>>M;

	_for(i,0,N){
		scanf("%d",&vec[i]);
	}
	sort(vec.begin(),vec.begin()+N);
	flag=false;
	DFS(0,M);
	if(!flag)printf("No Solution\n");
	else printvec(ans);
	return 0;
}

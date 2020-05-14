/**
 * @Date:   2018-08-03
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-03
 */
 #include<iostream>
 #include<vector>
 #include<algorithm>
 using namespace std;
 //1103 Integer Factorization (30)
 /*思路：递归 深度优先搜索
 注意本题的初始化技巧，用fac数组保存元素的p次方
 DFS模板要十分熟悉，
 */



 int power(int k,int p){//k^p
     int ans=1;
     while(p--)ans*=k;
     return ans;
 }
 int sum=0;
 int maxsubsum=0;
 int fac[21];//预处理序列
 //vector<vector<int>> ans;
 vector<int> maxans;
 void DFS(int m,int N,int K,vector<int>& tmp,int subsum){
     //对于任何一个元素，入栈或者不入栈都对应着不同的情况，所以，此种递归没有重复子问题
     //可以总结经验：DFS不好想，但是有思路之后，借助递归，代码就几行，思路很清晰
     if(m<=0||K<=0||N<=0||K>N)return;
     if(K==1&&fac[m]==N){
         tmp.push_back(m);
         subsum+=m;
         if(subsum>maxsubsum){maxans=tmp;maxsubsum=subsum;}
         //ans.push_back(tmp);
         subsum-=m;
         tmp.pop_back();
     }
     tmp.push_back(m);
     subsum+=m;
     DFS(m,N-fac[m],K-1,tmp,subsum);
     subsum-=m;
     tmp.pop_back();

     DFS(m-1,N,K,tmp,subsum);
     sum++;

 }
 int main(){
     //freopen("D:\\CodeBlockSpace\\input.txt","r",stdin);
     int N,K,P;
     scanf("%d %d %d",&N,&K,&P);
     fac[0]=0;
     int m=1;
     while(1){
         int t=power(m,P);
         if(t>N)break;
         fac[m]=t;
         m++;
     }
     m--;
     //[1,m]为满足题意的指数的取值
     vector<int> tmp;
     int subsum=0;
     DFS(m,N,K,tmp,subsum);
     /*这里是记录了所有满足题意的答案，因为本来就是从大往小DFS的，自动满足字典序
     那么，就看数字之和是否更大，更大的话则替代之前的答案，由此可以得到唯一的答案
     for(int i=0;i<ans.size();i++){
         for(int j=0;j<K;j++)
             printf("%d ",ans[i][j]);
         printf("\n");
     }
     */
     if(maxsubsum==0){printf("Impossible");return 0;}
     printf("%d = ",N);
     for(int i=0;i<maxans.size()-1;i++)
         printf("%d^%d + ",maxans[i],P);
     printf("%d^%d",maxans[maxans.size()-1],P);
     //cout<<sum;//测试循环总共的次数

     return 0;
 }
//DFS模板法
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<algorithm>
#include<ctime>
#include<cassert>
#include<cmath>
using namespace std;


#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
int getchar(){int x;scanf("%d",&x);return x;}
void printvec(vector<int>& vec){
	printf("%d",vec[0]);
	_for(i,1,vec.size()){printf(" %d",vec[i]);}
	printf("\n");
}
int N,K,P;
int powP[22];
vector<int> tmp;
vector<int> ans;
int maxsum=0;
int getsum(vector<int>& v){
	int sum=0;
	_for(i,0,v.size())sum+=v[i];
	return sum;
}
void solve(int step,int sel,int sum){//sel表示当前可选的数字，对于DFS来说，对于该数字可选可不选
	if(step==K){
		if(sum!=0)return;
		int r=getsum(tmp);
		if(r>maxsum){r=maxsum;ans=tmp;}
		else if(r==maxsum){
			int flag=0;
			_for(i,0,K){
				if(tmp[i]>ans[i]){flag=1;break;}
				if(tmp[i]<ans[i]){break;}
			}
			if(flag==1)ans=tmp;
		}
		return;
	}
	if(sel<1)return;
	if(powP[sel]<=sum){
		tmp.push_back(sel);
		solve(step+1,sel,sum-powP[sel]);
		tmp.pop_back();
	}
	solve(step,sel-1,sum);
}
int main(){
	//freopen("D:\\input.txt","r",stdin);
	cin>>N>>K>>P;
	//powP[i]=i^p
	_for(i,1,22)powP[i]=pow(i,P);
	solve(0,20,N);
	int n=ans.size();
	if(n==0)printf("Impossible\n");
	else{
		printf("%d =",N);
		printf(" %d^%d",ans[0],P);
		_for(i,1,K)printf(" + %d^%d",ans[i],P);
	}
	return 0;
}

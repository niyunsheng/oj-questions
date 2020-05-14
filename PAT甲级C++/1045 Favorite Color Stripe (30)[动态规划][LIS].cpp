 #include<iostream>
 #include"string.h"
 using namespace std;
 //最长不下降子序列longest Increasing Sequence
 //1045 Favorite Color Stripe (30)
 int main(){
     //freopen("d:\\CodeBlockSpace\\input.txt","r",stdin);
     int n,m,l;
     scanf("%d",&n);
     scanf("%d",&m);
     int pri[201];memset(pri,0,201*sizeof(int));
     //设置排序大小，不在喜欢列表中的元素为0
     int t;
     for(int i=0;i<m;i++){scanf("%d",&t);pri[t]=i+1;}
     scanf("%d",&l);
     int* num=new int[l];
     for(int i=0;i<l;i++)scanf("%d",num+i);

     //dp[i]表示以i结尾的最长不降子序列的长度
     int dp[l];
     int i=0;
     while(num[i]==0)dp[i]=0;
     dp[i]=1;
     int _max=0;
     while(i<l){
         if(pri[num[i]]==0)dp[i]=0;
         else{
             dp[i]=1;
             for(int j=0;j<i;j++){
                 if(pri[num[i]]>=pri[num[j]])dp[i]=max(dp[i],dp[j]+1);
             }
         }
        _max=max(_max,dp[i]);
        i++;
     }
     printf("%d",_max);
     return 0;
 }
//只将合法元素插入到序列中
	//freopen("D:\\input.txt","r",stdin);
	int N,M,maxsum=1,t;
	vector<int> hashtable(205,0),v,dp(10005);//dp[i]表示以i为后缀的最长不下降子序列的长度
	cin>>N;
	map<int,int> mmap;
	cin>>M;
	_for(i,0,M){cin>>t;hashtable[t]=i+1;}
	cin>>M;
	//剔除掉不喜欢的元素，然后按照最大递增子序列来做最方便
	_for(i,0,M)	{cin>>t;if(hashtable[t]!=0)v.push_back(hashtable[t]);}
	if(v.size()==0){printf("0");return 0;}
	dp[0]=1;
	_for(i,1,v.size()){
		dp[i]=1;//这里一定要赋初值1，否则会错误很多
		_for(j,0,i){
			if(v[i]>=v[j])dp[i]=max(dp[i],dp[j]+1);
		}
		maxsum=max(dp[i],maxsum);
	}
	printf("%d\n",maxsum);

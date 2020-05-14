/**
 * @Date:   2018-08-01
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-06
 */
 #include<iostream>
 #include"stdio.h"
 using namespace std;
 /*1007 Maximum Subsequence Sum (25)
 动态规划问题，同LeetCode53最大子序和
 只需定义f[i]表示以i为后缀的最大子序和
 显然f[0]=nums[0]

PAT的试题，需要注意的就是按照要去进行输出
 */
 int main(){
     //freopen("d:\\CodeBlockSpace\\input.txt","r",stdin);
     int n,m;
     scanf("%d",&n);
     int* num=new int[n];
     for(int i=0;i<n;i++)scanf("%d",num+i);
     int* f=new int[n];
     //建一个数组存储子序列的开始元素
     int* st=new int[n];
     f[0]=num[0];m=f[0];st[0]=0;
     int lo=0,hi=0;
     for(int i=1;i<n;i++){
         if(f[i-1]>=0){
             f[i]=f[i-1]+num[i];
             st[i]=st[i-1];
         }else{
             f[i]=num[i];
             st[i]=i;
         }
         if(f[i]>m){
             m=f[i];
             lo=st[i];
             hi=i;
         }
     }
     if(m<0)printf("0 %d %d",num[0],num[n-1]);else
     printf("%d %d %d",m,num[lo],num[hi]);
     return 0;
 }

//用双指针方法更加简单
int main(){
	//freopen("D:\\input.txt","r",stdin);
	int N;
	vector<int> v(10005);
	cin>>N;
	_for(i,0,N)	cin>>v[i];
	int lo=0,hi,anslo,anshi,maxsum=-1;
	while(lo<N){
		while(lo<N&&v[lo]<0)lo++;
		int sum=0;
		hi=lo;
		while(hi<N&&sum>=0){
			sum+=v[hi];
			if(v[hi]>=0&&sum>maxsum){maxsum=sum;anslo=lo;anshi=hi;}
			hi++;
		}
		lo=hi;
	}
	if(maxsum==-1)printf("0 %d %d\n",v[0],v[N-1]);
	else printf("%d %d %d\n",maxsum,v[anslo],v[anshi]);
	return 0;
}

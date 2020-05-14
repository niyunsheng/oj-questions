/**
 * @Date:   2018-08-03
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-03
 */
 #include <iostream>
 #include<vector>
 #include<queue>
 using namespace std;
//两种预处理方法，O(n^2)的过不了最后一个测试，O(n)的没有问题
 int main(){
     freopen("D:\\CodeBlockSpace\\input.txt","r",stdin);
     int n;
     scanf("%d",&n);
     int dis[n];
     int sum=0;

     int dp[n];//表示第一个节点到底i个节点的距离
     dp[0]=0;
     for(int i=0;i<n;i++){scanf("%d",dis+i);sum+=dis[i];if(i+1<n)dp[i+1]=sum;}

     /*预处理，减少重复计算，复杂度O(n^2)
     int dp[n][n];
     for(int i=0;i<n;i++){
         for(int j=i+2;j<n;j++)
             dp[i][j]=dp[i][j-1]+dp[j-1][j];
     }*/
     //更简单的预处理是第一行就可以了，然后dp[i][j]=dp[j]-dp[i],这样的复杂度就是O(1)了
     int m;
     scanf("%d",&m);
     int lo,hi;
     for(int i=0;i<m;i++){
         scanf("%d %d",&lo,&hi);
         if(lo>hi)swap(lo,hi);
         printf("%d\n",min((dp[hi-1]-dp[lo-1]),sum-(dp[hi-1]-dp[lo-1])));
     }
     return 0;
 }

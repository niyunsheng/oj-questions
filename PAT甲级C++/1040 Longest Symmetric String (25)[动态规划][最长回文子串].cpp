/**
 * @Date:   2018-08-02
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-17
 */
 //动态规划的基本算法，用dp[i][j]表示i,j是不是回文子串，然后从间隔0到n-1一步步扩大间隔
 //注意，最后一个case段错误，说明程序基本是没有问题的，把字符串数组开大一点就行了
 //最长回文子串有三种解法，中心元素扩展法，本题的简单dp，还有马拉车算法O(n)，详见LeetCode中同样题目
 //不过，还是这个简单dp方法最容易处理，思路也最简单，但是复杂度也是O(n^2)，和中心元素扩展法相比，也就是流程上更加清晰简单，但本质上是一样的，递归的条件想同，都是在前一个串的基础上再检查边界的一对字符
 //所以，最长回文子串能掌握马拉车算法最好了
 #include"stdio.h"
 #include"string.h"
 //最长回文子串
 int main(){
     //freopen("d:\\CodeBlockSpace\\input.txt","r",stdin);
     char str[1010];
     gets(str);
     int n=strlen(str);
     //简单DP，O(n^2)从长度为0、1的元素逐步扩展到最长
     //dp[i][j]表示以i和j为边界的子串是否为回文，0表示不是，1表示是，状态转移方程dp[i][j]=dp[i+1][j-1]+1或0
     //初始化
     int dp[n][n];
     for(int i=0;i<n-1;i++){
         dp[i][i]=1;
         if(str[i]==str[i+1])dp[i][i+1]=1;
         else dp[i][i+1]=0;
     }
     dp[n-1][n-1]=0;
     int m=1;
     //开始dp
     for(int i=2;i<n;i++){//i表示两坐标之差，初始化过程中已经完成了i=0和i=1的工作
         for(int j=0;i+j<n;j++){
             if(str[j]==str[i+j]&&dp[j+1][i+j-1]==1){dp[j][i+j]=1;m=i+1;}
             else dp[j][i+j]=0;
         }
     }
     printf("%d",m);
     return 0;
 }

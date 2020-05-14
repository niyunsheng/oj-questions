/**
 * @Date:   2018-08-02
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-17
 */
 //该题目有两种方法，方法1是中心元素拓展法，方法2是动态规划，manacher算法(马拉车算法)的复杂度为O(n)
 //作为经典dp题目，常用dp方法为dp[i][j]表示[i,j]是否是回文子串，先初始化i=j和j-i=1的情况，然后扩大间距
 /*虽然在manacher算法上因为小小的bug浪费了近一小时时间，但是，对manacher算法也更加理解
    重点dp[i]表示以i为中心的最长子序列
    mx表示最长子序列的右边界（不包含）
    递归条件的 if(i<mx)dp[i]=min(dp[2*id-i],mx-i);
                else dp[i]=1;
    初始化之后的序列与原序列的对应关系要清楚，画好图，一劳永逸
    s[0]=$  s[n-1]=\0   这两个作为边界条件，计算i=1:n-2的dp
    substr的第一个参数是起始元素的秩，第二个参数是子串长度

 */

     //方法1，采用中心元素扩展法，O（n^2），这个比枚举强，枚举是O(n^3)，但是基本也不用
     string longestPalindrome(string s) {
         int j,n=s.size();
         int start=0,maxsize=1;

         for(int i=0;i<n-1;i++){
             //先判断最长奇数子串
             j=1;
             while(i-j>=0&&i+j<n)if(s[i-j]==s[i+j])j++;else break;
             if(2*j-1>maxsize){start=i-j+1;maxsize=2*j-1;}
             //判断最长偶数子串
             j=0;
             while(i-j>=0&&i+j+1<n)if(s[i-j]==s[i+j+1])j++;else break;
             if(2*j>maxsize){maxsize=2*j;start=i-j+1;}
         }
         string ans=s.substr(start,maxsize);
         return ans;
     }
     //方法2：马拉车manacher算法的复杂度为O(n)
     string longestPalindrome(string s) {
         if(s.size()==0)return s;
         string ss;
         ss.push_back('$');
         ss.push_back('#');
         for(int i=0;i<s.size();i++){
             ss.push_back(s[i]);ss.push_back('#');
         }
         ss.push_back('\0');
         cout<<ss<<endl;
         int n=ss.size();
         int m=0,mid=0;//记录子串长度最大值，中心，半径
         int dp[n+1];//dp[i]表示也就是以 i 为中心的最长回文半径，原字符串中的长度为dp[i]-1
         dp[0]=1;
         int mx=1,id=0;//mx是右边界，不包含
         //这里误把i的取值写为了<=n，正确的写法应该是i<n-1,因为ss[0]和ss[n-1]是当做边界条件来处理的，只计算之间的元素
         //这个小小的错误可不是很容易发现啊！
         for(int i=1;i<n-1;i++){
             if(i<mx)
                 dp[i]=min(dp[2*id-i],mx-i);
             else dp[i]=1;
             while(ss[i+dp[i]]==ss[i-dp[i]])dp[i]++;//不用考虑边界条件，因为左边有'$',右边有\0
             if(i+dp[i]>mx){
                 mx=i+dp[i];
                 id=i;
             }
             //当下面的判断为等号时，取最靠后的最大子串，当为大于号时，取最靠前的最大子串
             if(dp[i]-1>=m){m=dp[i]-1;mid=i;}
         }
         //求得新子串中的中心元素id和最长半径，换算到原子串
         int lo,hi;
         //注意这里substr的第一个参数是开始元素的秩，第二个元素时子串长度
         lo=(mid-dp[mid]+2)/2-1;hi=(mid+dp[mid]-3)/2;

         printf("s[mid]=%c mid=%d dp[mid]=%d lo=%d hi=%d\n",s[lo],mid,dp[mid],lo,hi);

         return s.substr(lo,dp[mid]-1);
     }

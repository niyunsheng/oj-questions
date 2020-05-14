/**
 * @Date:   2018-08-02
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-02
 */
 #include<iostream>
 using namespace std;
 //1042 Shuffling Machine (20)
 //题目没什么难度，注意从一行推到下一行按照怎样的顺序即可
 int main(){
     //freopen("d:\\CodeBlockSpace\\input.txt","r",stdin);
     int n;
     int order[55];
     scanf("%d",&n);
     for(int i=1;i<55;i++)scanf("%d",order+i);

     int ans[n+1][55];
     for(int i=1;i<55;i++)ans[0][i]=i;
     for(int i=1;i<n+1;i++){
         for(int j=1;j<55;j++)
             ans[i][order[j]]=ans[i-1][j];
     }
     //for(int i=1;i<55;i++)printf("%d ",ans[n][i]);
     //接下来将数字转化为对应的字符
     char c[5]={'S','H','C','D','J'};
     for(int i=1;i<54;i++){
         printf("%c%d ",c[(ans[n][i]-1)/13],ans[n][i]%13?ans[n][i]%13:13);
     }
     printf("%c%d",c[(ans[n][54]-1)/13],ans[n][54]%13?ans[n][54]%13:13);
     return 0;
 }

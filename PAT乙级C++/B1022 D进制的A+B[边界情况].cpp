/**
 * @Date:   2018-07-26
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-06
 */

 //注意对边界情况的处理，如m、n等于0的情况，自己做好边界处理和测试后再提交
 #include <iostream>
 using namespace std;
 int main()
 {
     freopen("d:\\codeBlockSpace\\input.txt","r",stdin);
     unsigned m,n,d;
     scanf("%d %d %d",&m,&n,&d);
     m+=n;
     if(m==0)printf("0");return 0;
     int s[32],top=0;
     while(m!=0){
         s[top++]=m%d;
         m/=d;
     }
     while(top>0){
         printf("%d",s[--top]);
     }


     return 0;
 }

/**
 * @Date:   2018-08-01
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-01
 */
 #include<iostream>
 #include"string.h"
 #include"stdio.h"
 using namespace std;
 //需要注意的点是ans【1】是交替加减，其结果为1并不一定不存在，所以要统计下其个数
 //从写程序的角度而言，不如都统计下个数，用个数来判断
 int main(){
     //freopen("d:\\CodeBlockSpace\\input.txt","r",stdin);
     int n;
     scanf("%d",&n);
     if(n==0){printf("N N N N N");return 0;}
     int* num=new int[n];
     for(int i=0;i<n;i++)scanf("%d",num+i);
     int ans[5];
     int t3=0;
     memset(ans,0,sizeof(ans));
     bool flag=true;
     for(int i=0;i<n;i++){
         switch(num[i]%5){
         case 0:
             if(num[i]%10==0)ans[0]+=num[i];break;
         case 1:
             if(flag==1){ans[1]+=num[i];flag=!flag;}
             else {ans[1]-=num[i];flag=!flag;}
             break;
         case 2:
             ans[2]++;break;
         case 3:
             ans[3]+=num[i];t3++;break;
         case 4:
             ans[4]=max(ans[4],num[i]);break;
         }
     }
     for(int i=0;i<3;i++){
         if(ans[i]==0)printf("N ");
         else printf("%d ",ans[i]);
     }
     if(ans[3]==0)printf("N ");
     else printf("%.1f ",(float)ans[3]/(float)t3);
     if(ans[4]==0)printf("N");
     else printf("%d",ans[4]);
     return 0;
 }

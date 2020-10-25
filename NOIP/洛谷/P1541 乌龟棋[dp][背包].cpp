/**
 * @Date:   2018-07-31
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-01
 */
 #include<iostream>
 #include"stdio.h"
 using namespace std;
 /*洛谷P1541乌龟棋【动态规划】【背包】
 */

 int* nums;
 /*这种递归方法类似斐波那契数列中递归，存在无数种重复计算，应该用数组将计算结果保存起来，从前向后计算
 int fun(int a,int b,int c,int d){
     if(a==0&&b==0&&c==0&&d==0)return nums[0];
     int max1=0,max2=0,max3=0,max4=0;
     if(a!=0)max1=fun(a-1,b,c,d)+nums[(a)+2*b+3*c+4*d];
     if(b!=0)max2=fun(a,b-1,c,d)+nums[a+2*(b)+3*c+4*d];
     if(c!=0)max3=fun(a,b,c-1,d)+nums[a+2*b+3*(c)+4*d];
     if(d!=0)max4=fun(a,b,c,d-1)+nums[a+2*b+3*c+4*(d)];
     return max(max1,max2,max3,max4);
 }*/
 #define MAX 41
 int F[MAX][MAX][MAX][MAX];
 int main(){
     //freopen("d:\\CodeBlockSpace\\input.txt","r",stdin);
     int m,n,t;
     int card[5];
     for(int i=1;i<5;i++)card[i]=0;
     scanf("%d %d",&n,&m);
     nums=new int[n];
     for(int i=0;i<n;i++){
         scanf("%d",nums+i);
     }
     for(int i=0;i<m;i++){
         scanf("%d",&t);
         card[t]++;
     }
     //int sum=fun1(card[1],card[2],card[3],card[4]);
     F[0][0][0][0]=nums[0];
     for(int i=0;i<=card[1];i++)
         for(int j=0;j<=card[2];j++)
             for(int k=0;k<=card[3];k++)
                 for(int l=0;l<=card[4];l++){
                     int r=i+2*j+3*k+4*l;
                     if(i!=0)F[i][j][k][l]=max(F[i][j][k][l],F[i-1][j][k][l]+nums[r]);
                     if(j!=0)F[i][j][k][l]=max(F[i][j][k][l],F[i][j-1][k][l]+nums[r]);
                     if(k!=0)F[i][j][k][l]=max(F[i][j][k][l],F[i][j][k-1][l]+nums[r]);
                     if(l!=0)F[i][j][k][l]=max(F[i][j][k][l],F[i][j][k][l-1]+nums[r]);
                     //printf("%d %d %d %d %d\n",i,j,k,l,F[i][j][k][l]);
                 }
     printf("%d",F[card[1]][card[2]][card[3]][card[4]]);
     return 0;
 }

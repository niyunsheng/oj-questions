/**
 * @Date:   2018-08-02
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-02
 */
 #include<iostream>
 #include"string.h"
 #include<map>
 using namespace std;
 //1018 锤子剪刀布 (20)，本题还是有必要保存的
 //刚开始看到这个题目，如何建立字母到数字的映射呢？建立映射之后就可以在数组中处理
 //用map就太大材小用了，定义简单的函数即可
 int str2rank(char c){
     if(c=='B')return 0;
     if(c=='C')return 1;
     if(c=='J')return 2;
 }
 //定义了这个映射之后，就可以看到a胜的条件是(a+1)%3=b
 int main(){
     //freopen("d:\\CodeBlockSpace\\input.txt","r",stdin);
     int n;
     char a[2],b[2];
     int m1=0,m2=0,m3=0;//分别甲胜、乙胜、平局
     int sa1=0,sa2=0,sa3=0,sb1=0,sb2=0,sb3=0;//表示甲乙胜最多的手势
     char sa,sb;
     scanf("%d",&n);
     for(int i=0;i<n;i++){
         scanf("%s %s",a,b);
         switch(a[0]-b[0]){
             case 0:m3++;break;
             case ('C'-'J'):sa2++;m1++;break;
             case ('J'-'B'):sa3++;m1++;break;
             case ('B'-'C'):sa1++;m1++;break;

             case ('J'-'C'):sb2++;m2++;break;
             case ('B'-'J'):sb3++;m2++;break;
             case ('C'-'B'):sb1++;m2++;break;

         }
     }
     printf("%d %d %d\n",m1,m3,m2);
     printf("%d %d %d\n",m2,m3,m1);
     if(sa1>=sa2&&sa1>=sa3)sa='B';
     else if(sa2>=sa1&&sa2>=sa3)sa='C';
     else if(sa3>=sa1&&sa3>=sa1)sa='J';

     if(sb1>=sb2&&sb1>=sb3)sb='B';
     else if(sb2>=sb1&&sb2>=sb3)sb='C';
     else if(sb3>=sb1&&sb3>=sb1)sb='J';
     printf("%c %c",sa,sb);
     return 0;
 }

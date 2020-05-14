/**
 * @Date:   2018-07-30
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-07-30
 */
 //这么简单的题目做了快一小时了，本来应该二十分钟搞定的！！
 #include<iostream>
 using namespace std;
 int main(){
     int m,n,k;
     int tmp[1000],pp;
     int sta[1000],top;
     //入栈sta[top++]=j;出栈top--;size=top;栈顶sta[top-1];非空top>0
     //freopen("d:\\codeBlockSpace\\input.txt","r",stdin);
     scanf("%d %d %d",&m,&n,&k);
     bool overflow;//栈溢出
     for(int i=0;i<k;i++){
         for(int j=0;j<n;j++)
             scanf("%d",tmp+j);
         top=0;//栈顶
         pp=0;//出队列秩
         overflow=false;
         for(int i=1;i<=n;i++){
             //入栈
             sta[top++]=i;
             if(top>m){overflow=true;break;}
             //相等出栈
             while(top>0&&sta[top-1]==tmp[pp]){top--;pp++;}
         }
         if(!overflow&&top==0)printf("YES\n");
         else printf("NO\n");
     }
     return 0;
 }

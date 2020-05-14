/**
 * @Date:   2018-07-29
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-31
 */
//方法一：由链表首地址遍历计算链表长度，然后长的先走过差值，然后一起步进至相等
//方法二：由于本题是自定义节点值，所以可以给节点增设flag变量，遍历链表1时将flag标记为1，然后遍历链表2时第一个遇到flag为1的数即为所求。
 #include<iostream>
 #include<map>
 using namespace std;
 int main(){
     //第二版：不用map，直接用向量列表实现,全部通过
     //freopen("d:\\input.txt","r",stdin);
     int link[100000];
     int start1,start2,n;
     int first,next;
     char c;
     scanf("%d %d %d",&start1,&start2,&n);
     for(int i=0;i<n;i++){
         scanf("%d %c %d",&first,&c,&next);
         link[first]=next;
     }
     int len1=0,len2=0;
     int t1=start1,t2=start2;
     while(t1!=-1){t1=link[t1];len1++;}
     while(t2!=-1){t2=link[t2];len2++;}
     t1=start1;t2=start2;
     while(len1>len2){
         t1=link[t1];
         len1--;
     }
     while(len1<len2){
         t2=link[t2];
         len2--;
     }
     while(t1!=t2){
         t1=link[t1];
         t2=link[t2];
     }
     if(t1<0)printf("-1");
     else printf("%05d",t1);
     return 0;
     return 0;
 }
 /*第一版：使用map，最后一个算例超时
 int main()
 {
     freopen("d:\\codeBlockSpace\\input.txt","r",stdin);
     map<int,int> m;
     int start1,start2,n;
     int first,next;
     char c;
     scanf("%d %d %d",&start1,&start2,&n);
     for(int i=0;i<n;i++){
         scanf("%d %c %d",&first,&c,&next);
         m[first]=next;
     }
     int len1=0,len2=0;
     int t1=start1,t2=start2;
     while(t1!=-1){t1=m[t1];len1++;}
     while(t2!=-1){t2=m[t2];len2++;}
     t1=start1;t2=start2;
     while(len1>len2){
         t1=m[t1];
         len1--;
     }
     while(len1<len2){
         t2=m[t2];
         len2--;
     }
     while(t1!=t2){
         t1=m[t1];
         t2=m[t2];
     }
     if(t1<0)printf("-1");
     else printf("%05d",t1);
     return 0;
 }
 */

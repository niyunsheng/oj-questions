/**
 * @Date:   2018-07-30
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-03
 */
 #include<iostream>
 #include<vector>
 #include<algorithm>
 using namespace std;
 //A1097
 struct node{
     int addr;
     int data;
     node(int a,int d):addr(a),data(d){}
 };
 int main(){
     //freopen("D:\\CodeBlockSpace\\input.txt","r",stdin);
     int data[100001];
     int next[100001];
     int flag[100001];
     vector<node> ls;
     vector<node> dedup;
     int start,n;
     scanf("%d %d",&start,&n);
     int addr;
     for(int i=0;i<n;i++){
         scanf("%d",&addr);
         scanf("%d %d",data+addr,next+addr);
     }
     int cur=start;
     while(cur!=-1){
         if(flag[abs(data[cur])]!=1){
             ls.push_back(node(cur,data[cur]));
             flag[abs(data[cur])]=1;
         }else{
             dedup.push_back(node(cur,data[cur]));
         }
         cur=next[cur];
     }
     int n1=ls.size(),n2=dedup.size();
     if(n1!=0){
         for(int i=0;i+1<n1;i++){
             printf("%05d %d %05d\n",ls[i].addr,ls[i].data,ls[i+1].addr);
         }
         printf("%05d %d -1\n",ls[n1-1].addr,ls[n1-1].data);
     }
     if(n2!=0){
         for(int i=0;i+1<n2;i++){
             printf("%05d %d %05d\n",dedup[i].addr,dedup[i].data,dedup[i+1].addr);
         }
         printf("%05d %d -1\n",dedup[n2-1].addr,dedup[n2-1].data);
     }
     return 0;
 }

/**
 * @Date:   2018-08-02
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-02
 */
 #include<iostream>
 #include"string.h"
 #include<queue>
 using namespace std;
 //哈夫曼编码树：既然懂得原理，就转化为计算机语言吧
 //用优先级队列中存放树节点，树节点的值为出现频次之和
 //洛谷P1090 合并果子

 int main(){
     //freopen("d:\\CodeBlockSpace\\input.txt","r",stdin);
     int n;
     cin>>n;
     priority_queue<int,vector<int>,greater<int> > pq;//注意这里有个空格
     int t,a,b,ans=0;
     for(int i=0;i<n;i++){cin>>t;pq.push(t);}
     while(pq.size()!=1){
         a=pq.top();pq.pop();
         b=pq.top();pq.pop();
         //printf("a=%d b=%d\n",a,b);
         a+=b;
         ans+=a;
         pq.push(a);
     }
     cout<<ans;
     return 0;
 }

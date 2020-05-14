/**
 * @Date:   2018-07-31
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-03
 */
 #include<iostream>
 #include<queue>
 using namespace std;
 //读懂题目花了半小时了，真是醉人，还是看了中文才理解题目意思
 //英文题目要多练习啊！！

 /*经验：这个题目本身不难，但是却花了这么多时间，很大原因在于写之前思路都不清晰
     做题前应该把思路一步一步搞清楚，把问题分解，一步一步写出结果
 本题的思路：
     将比较的元素入队
     每次取出ng个元素放在tmp数组，找出最大元素
     将非最大元素的名次写好
     将最大元素重新入队
     退出条件：队列中只剩下一个元素即退出
     程序写出，判断思路没有问题之后，debug，看哪一步跟自己的预想不一致
     这个过程应该很快！
     将思路固定化而不是边想边写边改变思路
 */


 int main(){
     int weight[1001];//体重
     int _rank[1001];//排名

     queue<int> q;
     //freopen("d:\\CodeBlockSpace\\input.txt","r",stdin);
     int np,ng;
     scanf("%d %d",&np,&ng);
     int t;
     for(int i=0;i<np;i++)scanf("%d",weight+i);
     for(int i=0;i<np;i++){scanf("%d",&t);q.push(t);}

     int* tmp=new int[ng];
     int r;//记录比赛的组数，开始排名，每一轮比赛，淘汰的选手的名次为前面比赛的组数
     while(!q.empty()){
         int sum=q.size();//该轮比赛的人数
         if(sum==1){_rank[q.front()]=1;break;}

         if(q.size()%ng==0)r=q.size()/ng;
         else r=q.size()/ng+1;
         int i=0;
         while(i<sum){
             int j=0;//每组比赛人数
             while(i<sum&&j<ng){tmp[j]=q.front();q.pop();j++;i++;}
             int _m=tmp[0];//记录该组最大的数的秩
             //遍历一遍找出最大值
             for(int k=1;k<j;k++){
                 if(weight[tmp[k]]>=weight[_m])_m=tmp[k];
             }
             for(int k=0;k<j;k++){
                 if(tmp[k]!=_m)_rank[tmp[k]]=r+1;
             }
             q.push(_m);
         }
     }
     for(int i=0;i<np-1;i++){
         printf("%d ",_rank[i]);
     }
     printf("%d",_rank[np-1]);
     return 0;
 }

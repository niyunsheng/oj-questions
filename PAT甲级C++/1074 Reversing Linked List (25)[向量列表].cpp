/**
 * @Date:   2018-07-30
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-07-30
 */
 //方法1，通过定义静态向量列表来把元素存储起来以方便读取，但是，对其的翻转操作应先将其存入列表当中去，然后用STL中的reverse函数
 //方法2，通过给节点定义order量，通过遍历列表时给order量赋值，然后根据order量给向量列表排序，进而在翻转
 //		方法2中用到的自定义量然后排序的方法与1052list sorting有相似之处，后者定义flag量，将未在列表中的元素移到最后，这里定义order量，将为在列表中的元素移到最后
 #include<iostream>
 #include<vector>
 #include<algorithm>
 using namespace std;
 //B1025/A1074
 struct node{
     int addr;
     int data;
     node(int a,int d):addr(a),data(d){}
 };
 int main(){
     //freopen("D:\\CodeBlockSpace\\input.txt","r",stdin);
     int data[100001];
     int next[100001];
     vector<node> ls;
     int start,n,np;//np表示每np个元素作为一个翻转单位
     scanf("%d %d %d",&start,&n,&np);
     int addr;
     for(int i=0;i<n;i++){
         scanf("%d",&addr);
         scanf("%d %d",data+addr,next+addr);
     }
     int cur=start;
     while(cur!=-1){
         ls.push_back(node(cur,data[cur]));
         cur=next[cur];
     }
     int sum=ls.size();
     if(sum==0){printf("-1");return 0;}
     int lo=0,hi=np;
     while(lo<sum&&hi<=sum){
         reverse(ls.begin()+lo,ls.begin()+hi);
         lo+=np;hi+=np;
     }
     for(int i=0;i+1<sum;i++){
         printf("%05d %d %05d\n",ls[i].addr,ls[i].data,ls[i+1].addr);
     }
     printf("%05d %d -1",ls[sum-1].addr,ls[sum-1].data);
     return 0;
 }

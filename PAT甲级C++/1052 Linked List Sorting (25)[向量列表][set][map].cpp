/**
 * @Date:   2018-07-29
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-31
 */
 #include<iostream>
 #include<list>
 #include<vector>
 #include<algorithm>
 using namespace std;

 /*题目总结：
版本1：用map或set实现，经过了两个多小时的折腾，还是发现，自定义类型的键值，即使定义了函数对象或者重载小于号，都编译不通过，该方法放弃。
    教训：map、set的键值为通用类型或string，为常量，也不能更改
版本2：用list存储节点，但是没有做出来的原因在于list不能寻秩访问找到下一个节点，因为输入时节点是乱序输入的，为此还得引入其他数据结构，麻烦
    教训，STLsort函数只用于vector、string和deque，set、map自身有序不能排序，list的成员函数中有sort，排序调用自己的成员函数即可
版本3：向量链表，虽然占用存储空间，但是方便易空控
本题中的陷阱：
    题目中的节点中有无效节点，即不在链表的节点
    可能没有一个节点
    格式化输入输出
 */
 //需要给list排序，这样用map应该可以通过,其实没必要用map，用set即可
 //遇到的另一个问题是，list不能使用自定义的排序类型，数组和向量试了都是没问题的，所以，这个题目最后用向量排序解决了
 //另一个问题是向量中的元素不一定都在列表中
 struct node{
     int first;
     int data;
     int next;
     bool flag;
     bool operator <(node& b){
         if(flag&&b.flag){
             return data<b.data;
         }else
             return flag;
     }
 };
 int main(){
     static node m[100000];
     for(int i=0;i<100000;i++)m[i].flag=false;

     //freopen("d:\\input.txt","r",stdin);
     int start,n;
     int first,data,next;
     scanf("%d %d",&n,&start);
     for(int i=0;i<n;i++){
         scanf("%d %d %d",&first,&data,&next);
         m[first].first=first;
         m[first].data=data;
         m[first].next=next;
     }
     int i=start;
     if(start==-1){printf("0 -1");return 0;}
     n=0;
     while(i!=-1){
         m[i].flag=true;n++;
         //printf("%05d %d %05d\n",m[i].first,m[i].data,m[i].next);
         i=m[i].next;
     }
     sort(m,m+100000);
     printf("%d %05d\n",n,m[0].first);
     for(i=0;i<n-1;i++){
         printf("%05d %d %05d\n",m[i].first,m[i].data,m[i+1].first);
     }
     printf("%05d %d -1\n",m[i].first,m[i].data);
     return 0;
 }
 /*第二版，采用list发现不能给自定义元素排序，改用向量，但是不能有效甄别出非数组元素，故还是得采用静态向量链表的方法
 int main(){
     //freopen("d:\\codeBlockSpace\\input.txt","r",stdin);
     vector<node> m;
     int start,n;
     node t;
     scanf("%d %d",&n,&start);
     for(int i=0;i<n;i++){
         scanf("%d %d %d",&(t.first),&(t.data),&(t.next));
         m.push_back(t);
     }
     sort(m.begin(),m.end());
     vector<node>::iterator it=m.begin();
     while((it+1)!=m.end()){
         it->next=(it+1)->first;
         it++;
     }
     it->next=-1;
     it=m.begin();
     printf("%d %05d\n",n,(*it).first);
     while(it!=m.end()){
         if((*it).next==-1)printf("%05d %d -1\n",(*it).first,(*it).data);
         else printf("%05d %d %05d\n",(*it).first,(*it).data,(*it).next);
         it++;
     }
     return 0;
 }
 */
 /*第一版：用map或set来做，想自动排序，但发现，map和set的key值都是常量，不能修改，不满足要求
 int main()
 {
     freopen("d:\\codeBlockSpace\\input.txt","r",stdin);
     set<node> m;
     int start,n;

     node t;
     scanf("%d %d",&n,&start);
     for(int i=0;i<n;i++){
         scanf("%d %d %d",&(t.first),&(t.data),&(t.next));
         m.insert(t);
     }
     //这里报错，原因在于iterator没有重载+运算符，那么，如何
     set<node>::iterator it=m.begin();
     set<node>::iterator it2=m.begin();it2++;
     while(it2!=m.end()){
         //赋值语句出错assignment of member 'node::next' in read-only object
         //通过查找资料发现，set里面key与排序有关，是不能修改的
         (*it).next=(*it2).first;
         it++;it2++;
     }
     (*it2).next=-1;
     it=m.begin();
     printf("%d %05d\n",n,(*it).first);
     while(it!=m.end()){
         if((*it).next==-1)printf("%05d %d -1\n",(*it).first,(*it).data);
         else printf("%05d %d %05d\n",(*it).first,(*it).data,(*it).next);
         it++;
     }
     return 0;
 }
 */

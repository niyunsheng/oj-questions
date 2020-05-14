/**
 * @Date:   2018-08-06
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-06
 */
 //由于准考证号14位，也可以用longlong来存，因为n<1000，所以用数组来存也是可以的，就不需要用map了
 //题目虽简单，但是要注意如果提示找不到默认构造函数，就再写一个空的构造函数即可
 //复制值构造函数这里可以不写，如果写，参数一定是const node& b，少了const可能报错
 #include<iostream>
 #include<map>
 #include<string>
 using namespace std;
 struct node{
     int r;
     string s;
 	node(){}
     node(int rr,string ss):r(rr),s(ss){}
 	node(const node& b):r(b.r),s(b.s){}
 };

 int main(){
     freopen("D:\\CodeBlockSpace\\input.txt","r",stdin);
     int n,m,t1,t2;
     scanf("%d",&n);
     string s;
     map<int,node> mmap;
     for(int i=0;i<n;i++){
         cin>>s>>t1>>t2;
         node nd(t2,s);
         mmap[t1]=nd;
     }
     scanf("%d",&m);
     for(int i=0;i<m;i++){
         scanf("%d",&t1);
         cout<<mmap[t1].s<<" "<<mmap[t1].r<<endl;
     }
     return 0;
 }

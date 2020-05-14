/**
 * @Date:   2018-07-27
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-30
 */

//做好本题要熟悉STL库中vector和set的用法
 #include <iostream>
 #include<vector>
 #include<set>
 using namespace std;
 float sim(set<int>& s1,set<int>& s2){
     int sam=0,sum1=s1.size(),sum2=s2.size();
     for(set<int>::iterator it=s1.begin();it!=s1.end();it++){
         if(s2.count(*it)==1)sam++;
     }
     return (float)sam/(sum1+sum2-sam);
 }
 int main()
 {
     freopen("d:\\codeBlockSpace\\input.txt","r",stdin);
     int n,m,t;
     vector<set<int>> vec;
     scanf("%d",&n);
     for(int i=0;i<n;i++){
         scanf("%d",&m);
         set<int> s;
         for(int j=0;j<m;j++){
             scanf("%d",&t);
             s.insert(t);
         }
         vec.push_back(s);
     }
     scanf("%d",&m);int s1,s2;
     for(int i=0;i<m;i++){
         scanf("%d %d",&s1,&s2);
         float f=sim(vec[s1-1],vec[s2-1]);
         printf("%2.1f%%\n",100*f);
     }

     return 0;
 }

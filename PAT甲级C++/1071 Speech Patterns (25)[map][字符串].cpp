/**
 * @Date:   2018-07-27
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-30
 */


 //注意对最后一个字符串的处理，开始时进入循环，不应该直接就判断跳出，而应该先处理已有的字符串。
 #include <iostream>
 #include<vector>
 #include<map>
 using namespace std;
 bool isAlp(char c){
     return ('0'<=c&&c<='9')||('a'<=c&&c<='z')||('A'<=c&&c<='Z');
 }
 #define alpha(x) (('A'<=x&&x<='Z')?(x+'a'-'A'):x)
 #define eql(x,y) ((x==y)||(('a'<=x&&x<='z')&&(x+'A'-'a'==y))||(('A'<=x&&x<='Z')&&(x+'a'-'A'==y)))
 int main()
 {
     //freopen("d:\\input.txt","r",stdin);
     char c;
     string str,maxstr;
     map<string,int> m;
     int maxnum=0;
     while(1){
         c=getchar();

         //printf("%c",c);
         if(!isAlp(c)){
             if(str.size()>0){
                 if(m.find(str)==m.end())m[str]=1;
                 else m[str]++;
                 if(m[str]>maxnum||(m[str]==maxnum&&str<maxstr)){
                     maxnum=m[str];
                     maxstr=str;
                 }
             str.clear();
             }
         }else{
             str+=alpha(c);
         }
         if(c=='\n')break;
     }
     printf("%s %d",maxstr.c_str(),maxnum);
     return 0;
 }

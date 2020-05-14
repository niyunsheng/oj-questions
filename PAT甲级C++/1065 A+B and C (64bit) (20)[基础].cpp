/**
 * @Date:   2018-07-26
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-02
 */
 //此种判断方法在不超范围内都有效，判断的原则是，同号不想加以避免溢出
 //1065 A+B and C (64bit) (20)只需将下面的&d改为%lld，等即可
  #include <iostream>
  using namespace std;
  int main()
  {
      freopen("d:\\codeBlockSpace\\input.txt","r",stdin);
      int n;
      long long a,b,c;
      scanf("%d",&n);
      for(int i=1;i<=n;i++){
          scanf("%lld %lld %lld",&a,&b,&c);
          if(a>0&&b>0){
              if(c>0&&a>c-b)printf("Case #%d: true\n",i);
              else if(c<=0)printf("Case #%d: true\n",i);
              else printf("Case #%d: false\n",i);
          }else if(a<0&&b<0){
              if(c<0&&a>c-b)printf("Case #%d: true\n",i);
              else printf("Case #%d: false\n",i);
          }else if(a+b>c)printf("Case #%d: true\n",i);
          else printf("Case #%d: false\n",i);

      }
      return 0;
  }




//B1011，本题目除了下面这种判断溢出的方法外，还可以用longlong来表示就不会溢出了
//此种判断方法在不超范围内都有效，判断的原则是，同号不想加以避免溢出
 #include <iostream>
 using namespace std;
 int main()
 {
     //freopen("d:\\codeBlockSpace\\input.txt","r",stdin);
     int n,a,b,c;
     scanf("%d",&n);
     for(int i=1;i<=n;i++){
         scanf("%d %d %d",&a,&b,&c);
         if(a>0&&b>0){
             if(c>0&&a>c-b)printf("Case #%d: true\n",i);
             else if(c<=0)printf("Case #%d: true\n",i);
             else printf("Case #%d: false\n",i);
         }else if(a<0&&b<0){
             if(c<0&&a>c-b)printf("Case #%d: true\n",i);
             else printf("Case #%d: false\n",i);
         }else if(a+b>c)printf("Case #%d: true\n",i);
         else printf("Case #%d: false\n",i);

     }
     return 0;
 }

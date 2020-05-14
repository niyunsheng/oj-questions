/**
 * @Date:   2018-08-29
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-29
 */
//注意：输出初始的分数的时候也要化成最简形式。
#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include<map>
#include<algorithm>
#include<ctime>
using namespace std;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)

typedef long long ll;
struct frac{
    ll a,b;//分子分母
    frac(ll aa,ll bb):a(aa),b(bb){}
    frac(){}
};
int gcd(ll x,ll y){
    return y==0?x:gcd(y,x%y);
}
void reduce(frac& c){
    if(c.a==0){c.b=1;return;}
    if(c.b==0){c.a=1;return;}
    if(c.b<0){c.a=-c.a;c.b=-c.b;}
    int r;
    if(c.a>0)r=gcd(c.a,c.b);
    else r=gcd(-c.a,c.b);
    c.a/=r;
    c.b/=r;
}
frac _add(frac f1,frac f2){
    frac ans;
    ans.a=f1.a*f2.b+f1.b*f2.a;
    ans.b=f1.b*f2.b;
    reduce(ans);
    return ans;
}
frac _minus(frac f1,frac f2){
    f2.a=-f2.a;
    return _add(f1,f2);
}
frac _prod(frac f1,frac f2){
    frac ans;
    ans.a=f1.a*f2.a;
    ans.b=f1.b*f2.b;
    reduce(ans);
    return ans;
}
frac _divi(frac f1,frac f2){
    swap(f2.a,f2.b);
    return _prod(f1,f2);
}
void printnode(frac f){
    if(f.b==0){printf("Inf");return;}
    if(f.a==0){printf("0");return;}
    int flag=0;
    if(f.a<0){flag=1;f.a=-f.a;printf("(-");}
    if(f.a>=f.b){
        printf("%lld",f.a/f.b);f.a%=f.b;
        if(f.a!=0)printf(" %lld/%lld",f.a,f.b);
    }else{
        printf("%lld/%lld",f.a,f.b);
    }
    if(flag)printf(")");
}
int main(){
    //freopen("d:\\input.txt","r",stdin);

    ll a,b,c,d;
    scanf("%lld/%lld %lld/%lld",&a,&b,&c,&d);
    //srand(time(NULL));    a=rand()%13-6;b=abs(rand()%10-5)+1;c=rand()%10-5;d=abs(rand()%10-5)+1;
    //printf("%lld %lld %lld %lld\n",a,b,c,d);
    frac f1=frac(a,b),f2=frac(c,d);
    reduce(f1);reduce(f2);
    printnode(f1);printf(" + ");printnode(f2);printf(" = ");printnode(_add(f1,f2));printf("\n");
    printnode(f1);printf(" - ");printnode(f2);printf(" = ");printnode(_minus(f1,f2));printf("\n");
    printnode(f1);printf(" * ");printnode(f2);printf(" = ");printnode(_prod(f1,f2));printf("\n");
    printnode(f1);printf(" / ");printnode(f2);printf(" = ");printnode(_divi(f1,f2));printf("\n");
    return 0;
}

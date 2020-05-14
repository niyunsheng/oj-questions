#include<cstdio>
int main(){
    long s=1,t=1,n;
    scanf("%ld",&n);
    for(int i=2;i<=n;i++){
        t*=i;
        s+=t;
    }
    printf("%ld\n",s);
    return 0;
}

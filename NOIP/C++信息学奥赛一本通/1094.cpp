#include<cstdio>
int main(){
    int n,s=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        if(i%10==7 || i/10==7 || i%7==0)continue;
        s+=i*i;
    }
    printf("%d\n",s);
    return 0;
}

#include<cstdio>
int main(){
    int x,y,z;
    scanf("%d %d %d",&x,&y,&z);
    long long a[55]={0};//成虫数量
    long long b[55]={0};//幼崽数量
    for(int i=0;i<=x;i++){a[i]=1;b[i]=0;}
    for(int i=x+1;i<=z+1;i++){
        b[i] = y*a[i-x];
        a[i] = b[i-2]+a[i-1];
    }
    printf("%lld\n",a[z+1]);
    return 0;
}

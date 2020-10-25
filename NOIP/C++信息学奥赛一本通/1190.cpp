#include<cstdio>
int main(){
    long v[100];
    v[1]=1;
    v[2]=2;
    v[3]=4;
    for(int i=4;i<100;i++)v[i]=v[i-1]+v[i-2]+v[i-3];
    int n;
    while(true){
        scanf("%d",&n);
        if(n==0)break;
        printf("%ld\n",v[n]);
    }
    return 0;
}

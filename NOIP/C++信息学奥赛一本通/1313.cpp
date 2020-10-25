#include<cstdio>
int main(){
    int n;
    scanf("%d",&n);
    int a[1005]; // 奇数个3的个数
    int b[1005]; // 偶数个3的个数
    a[1] = 1;
    b[1] = 8;
    for(int i=2;i<=n;i++){
        a[i] = (a[i-1]*9+b[i-1])%12345;
        b[i] = (b[i-1]*9+a[i-1])%12345;
    }
    printf("%d\n",b[n]);
    return 0;
}

#include<cstdio>
int main(){
    int b;
    scanf("%d",&b);
    printf("%d%d%d\n",b%10,b%100/10,b/100);
    return 0;
}

#include<cstdio>
int main(){
    double a,b;
    scanf("%lf %lf",&a,&b);
    printf("%.4lf",a-b*int(a/b));
    return 0;
}

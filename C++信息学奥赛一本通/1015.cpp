#include<cstdio>
using namespace std;
int main(){
    double r1,r2;
    scanf("%lf %lf",&r1,&r2);
    printf("%.2lf",r1*r2/(r1+r2));
    return 0;
}
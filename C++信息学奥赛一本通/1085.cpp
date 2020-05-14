#include<cstdio>
int main(){
    double h,s=0;
    scanf("%lf",&h);
    s+=h;
    for(int i=0;i<9;i++){
        h/=2;
        s+=h*2;
    }
    h/=2;
    printf("%.6lf\n%.6lf\n",s,h);
    return 0;
}

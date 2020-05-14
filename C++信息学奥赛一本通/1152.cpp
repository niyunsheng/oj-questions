#include<cstdio>
int max(int a,int b,int c){
    int m=a;
    if(b>m)m=b;
    if(c>m)m=c;
    return m;
}
int main(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    float m=(float)max(a,b,c)/(max(a+b,b,c)*max(a,b,b+c));
    printf("%.3f\n",m);
    return 0;
}

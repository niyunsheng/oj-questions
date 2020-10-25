#include<cstdio>
using namespace std;
int main(){
    int x,a,y,b;
    scanf("%d %d %d %d",&x,&a,&y,&b);
    printf("%.2f",float(b*y-a*x)/(b-a));
    return 0;
}
#include<cstdio>
int main(){
    int n,a[105],s=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        s+=a[i];
    }
    printf("%.2f\n",(float)s/n);
    return 0;
}

#include<cstdio>
int main(){
    int n,t,s=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&t);
        if(t>s)s=t;
    }
    printf("%d\n",s);
    return 0;
}

#include<cstdio>
int main(){
    int n,m;
    int v[105];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&v[i]);
    }
    scanf("%d",&m);
    int c=0;
    for(int i=0;i<n;i++){
        if(v[i]==m)c++;
    }
    printf("%d\n",c);
    return 0;
}

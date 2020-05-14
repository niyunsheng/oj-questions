#include<cstdio>
int main(){
    int n,m;
    int v[5005];
    scanf("%d %d",&n,&m);
    for(int j=1;j<=n;j++)v[j]=0;
    for(int i=2;i<=m;i++){
        for(int j=i;j<=n;j+=i){
            v[j]=1-v[j];
        }
    }
    bool f=true;
    for(int j=1;j<=n;j++){
        if(v[j]==0){
            if(f){
                printf("%d",j);
                f=false;
            }else{
                printf(",%d",j);
            }
        }
    }
    printf("\n");
    return 0;
}

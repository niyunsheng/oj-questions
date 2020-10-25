#include<cstdio>

int main(){
    int n;
    int v[105][105];
    int c=1;
    scanf("%d",&n);
    for(int i=0;i<=2*(n-1);i++){
        if(i%2==0){
            int a=0,b=i-a;
            for(;a<n;a++){
                b=i-a;
                if(b>=0&&b<n){
                    v[a][b]=c;
                    c++;
                }
            }
        }else{
            int b=0,a=i-b;
            for(;b<n;b++){
                a=i-b;
                if(a>=0&&a<n){
                    v[a][b]=c;
                    c++;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",v[i][j]);
        }
        printf("\n");
    }
    return 0;
}
#include<cstdio>
int main(){
    int n,i,j;
    scanf("%d %d %d",&n,&i,&j);
    printf("(%d,%d)",i,1);
    for(int k=2;k<=n;k++){
        printf(" (%d,%d)",i,k);
    }
    printf("\n");
    printf("(%d,%d)",1,j);
    for(int k=2;k<=n;k++){
        printf(" (%d,%d)",k,j);
    }
    printf("\n");
    if(j>=i){
        printf("(%d,%d)",1,j-i+1);
        for(int k=2;(j-i+k)<=n;k++){
            printf(" (%d,%d)",k,j-i+k);
        }
        printf("\n");
    }else{
        printf("(%d,%d)",i-j+1,1);
        for(int k=2;(i-j+k)<=n;k++){
            printf(" (%d,%d)",i-j+k,k);
        }
        printf("\n");
    }

    if(i+j<=n+1){
        printf("(%d,%d)",i+j-1,1);
        for(int k=2;(i+j-k)>=1;k++){
            printf(" (%d,%d)",i+j-k,k);
        }
        printf("\n");
    }else{
        printf("(%d,%d)",n,i+j-n);
        for(int k=n-1;(i+j-k)<=n;k--){
            printf(" (%d,%d)",k,i+j-k);
        }
        printf("\n");
    }
    return 0;
}

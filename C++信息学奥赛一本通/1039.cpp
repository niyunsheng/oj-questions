#include<cstdio>
int main(){
    int b;
    scanf("%d",&b);
    if(b>0){
        printf("positive\n");
    }else if(b==0){
        printf("zero\n");
    }else{
        printf("negative\n");
    }
    return 0;
}

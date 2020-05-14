#include<cstdio>
int main(){
    int a;
    scanf("%d",&a);
    bool flag = false;
    if(a%3==0){
        if(flag)printf(" ");
        printf("3");
        flag = true;
    }
    if(a%5==0){
        if(flag)printf(" ");
        printf("5");
        flag = true;
    }
    if(a%7==0){
        if(flag)printf(" ");
        printf("7");
        flag = true;
    }
    if(!flag)printf("n");
    printf("\n");
    return 0;
}

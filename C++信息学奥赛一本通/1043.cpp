#include<cstdio>
int main(){
    long a,b;
    scanf("%ld %ld",&a,&b);
    if(a>b){
        printf(">\n");
    }else if(a==b){
        printf("=\n");
    }else{
        printf("<\n");
    }
    return 0;
}

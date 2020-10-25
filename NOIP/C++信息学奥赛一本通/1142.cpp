#include<cstdio>
int main(){
    char c;
    int n=0;
    bool start = true;
    while(true){
        scanf("%c",&c);
        if(c=='\n'){
            if(n!=0)printf(",%d",n);
            break;
        }
        if(c==' '){
            if(n!=0 && start){
                printf("%d",n);
                start = false;
            }else if(n!=0){
                printf(",%d",n);
            }
            n=0;
        }else{
            n++;
        }
    }
    printf("\n");
    return 0;
}

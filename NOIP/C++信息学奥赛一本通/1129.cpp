#include<cstdio>
int main(){
    char c;
    int s=0;
    while(true){
        scanf("%c",&c);
        if(c=='\n')break;
        if(c>='0'&&c<='9')s++;
    }
    printf("%d\n",s);
    return 0;
}

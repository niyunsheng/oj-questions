#include<cstdio>
void fun(int n,char a,char b,char c){
    if(n==1){
        printf("%c->%d->%c\n",a,n,c);
    }else{
        fun(n-1,a,c,b);
        printf("%c->%d->%c\n",a,n,c);
        fun(n-1,b,a,c);
    }
}
int main(){
    int n;
    char a,b,c;
    scanf("%d %c %c %c",&n,&a,&b,&c);
    fun(n,a,c,b);
    return 0;
}

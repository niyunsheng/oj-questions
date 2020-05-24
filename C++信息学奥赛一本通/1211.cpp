#include<cstdio>
bool find = false;
void fun(int n,int x){
    if(n==x){
        find = true;
    }else if(n<x){
        if(!find)fun(2*n+1,x);
        if(!find)fun(3*n+1,x);
    }
}
int main(){
    int n,x;
    scanf("%d,%d",&n,&x);
    fun(n,x);
    if(find){
        printf("YES\n");
    }else{
        printf("NO\n");
    }
    return 0;
}

#include<cstdio>
bool prime(int a){
    for(int i=2;i*i<=a;i++){
        if(a%i==0)return false;
    }
    return true;
}
bool fun(int i){
    return (i/100)==(i%10);
}
int main(){
    for(int i=101;i<1000;i+=2){
        if(prime(i)&&fun(i))
            printf("%d\n",i);
    }
    return 0;
}

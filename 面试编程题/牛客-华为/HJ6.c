// https://www.nowcoder.com/ta/huawei
/*
知识点：
    * 模拟
*/
#include "stdio.h"
int main(){
    long x;
    scanf("%ld",&x);
    int i=2;
    while(x!=1){
        if(x%i==0){
            printf("%d ",i);
            x /= i;
        }else
            i++;
    }
}
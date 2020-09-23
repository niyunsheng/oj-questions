// https://www.nowcoder.com/ta/huawei
/*
知识点：
    * 如何计算1的个数?
*/
#include "stdio.h"
int main(){
    // freopen("in.txt","r",stdin);
    int n,sum=0;
    scanf("%d",&n);
    while(n!=0){
        if(n%2==1)
            sum++;
        n/=2;
    }
    printf("%d",sum);
}
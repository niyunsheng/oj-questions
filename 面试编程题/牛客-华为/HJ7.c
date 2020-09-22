// https://www.nowcoder.com/ta/huawei
/*
知识点：
    * int向下取整
*/
#include "stdio.h"
int main(){
    float x;
    scanf("%f",&x);
    printf("%d\n",(int)(x+0.5));
    // printf("%.0f\n",x+0.5); // 或者用这个语句输出
}
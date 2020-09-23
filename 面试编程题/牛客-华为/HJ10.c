// https://www.nowcoder.com/ta/huawei
/*
知识点：
    * 如何根据特定的输入停止
*/
#include "stdio.h"
#include "string.h" // memset函数
#include "stdbool.h" // bool类型
int main(){
    bool vis[128];
    // memset(vis,0,sizeof(vis));
    while(true){
        char c;
        c = getchar();
        if(c=='\n')break;
        vis[c] = true;
    }
    int sum=0;
    for(int i=0;i<128;i++){
        if(vis[i])sum++;
    }
    printf("%d",sum);
}
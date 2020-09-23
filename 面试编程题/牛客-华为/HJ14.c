// https://www.nowcoder.com/ta/huawei
/*
知识点：
    * 排序算法
    * 如何比较两个字符串的大小
        * 字典序
        * 从第一个字符依次比较
            * b,ac
            * acd,acb
            * acd,acdf
        * strcmp()
            * 字符串1=字符串2，返回0
            * 字符串1>字符串2，返回一个正整数
            * 字符串1<字符串2，返回一个负整数。
*/
#include "stdio.h"
#include "stdbool.h" // bool类型
#include "string.h"

bool lesser(char* a,char* b){
    //判断两个字符串的大小，a<b返回true
    for(int i=0;i<strlen(a)&&i<strlen(b);i++){
        if(a[i]==b[i])continue;
        if(a[i]>b[i])return false;
        else return true;
    }
    if(strlen(a)<=strlen(b))
        return true;
    else
        return false;
}
void swapstr(char* a,char* b){
    char tmp[105];
    strcpy(tmp,a);
    strcpy(a,b);
    strcpy(b,tmp);
}
int main(){
    // freopen("in.txt","r",stdin);
    int n;
    scanf("%d",&n);
    char str[1005][105];
    for(int i=0;i<n;i++){
        scanf("%s",str[i]);
    }
    // 冒泡排序
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(!lesser(str[j],str[j+1])){
                swapstr(str[j],str[j+1]);
            }
        }
    }
    // 输出
    for(int i=0;i<n;i++){
        printf("%s\n",str[i]);
    }
}
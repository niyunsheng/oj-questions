// https://www.nowcoder.com/ta/huawei
/*
知识点：
    * 字符串库"string.h"中的常见方法
        * strlen
        * strcpy //char *strcpy(char *destin, char *source);
        * strcat //char *strcat(char *destin, char *source);
*/
#include "stdio.h"
#include "string.h"
int main(){
    char s[100];
    for(int c=0;c<2;c++){
        scanf("%s",s);
        if(strlen(s)==0)continue;
        for(int i=0;i<strlen(s);i+=8){
            for(int j=0;j<8;j++){
                if(i+j>=strlen(s))
                    printf("0");
                else
                    printf("%c",s[i+j]);
            }
            printf("\n");
        }
    }
}
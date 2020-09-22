// https://www.nowcoder.com/ta/huawei
/*
知识点：
    * 如何处理循环多次输入
*/
#include "stdio.h"
#include "string.h"
int main(){
    // freopen("in.txt","r",stdin);
    char s[105];
    while(scanf("%s",s)!=EOF){
        int c=0;
        if(s[0]=='0'&&s[1]=='x'){
            for(int i=2;i<strlen(s);i++){
                int t;
                if(s[i]>='0'&&s[i]<='9')
                    t = s[i] - '0';
                else
                    t = s[i] - 'A' + 10;
                c = c*16 + t;
            }
        }
        printf("%d\n",c);
    }
}
/**
 * @Date:   2018-08-30
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-30
 */
//思路：直接用sscanf和ssprint函数来判断是否有效，自己写的判定不知道为什么最后一个算例不过，可能是有其他的未列出的非法情况自己没有枚举到
#include <iostream>
#include <string.h>
using namespace std;
int main() {
	//freopen("d:\\input.txt","r",stdin);
    int n, cnt = 0;
    char a[50], b[50];
    double temp, sum = 0.0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        scanf("%s", a);
        sscanf(a, "%lf", &temp);
        sprintf(b, "%.2lf",temp);
        int flag = 0;
        for(int j = 0; j < strlen(a); j++) {
            if(a[j] != b[j]) {
                flag = 1;
            }
        }
        if(flag || temp < -1000 || temp > 1000) {
            printf("ERROR: %s is not a legal number\n", a);
            continue;
        } else {
            sum += temp;
            cnt++;
        }
    }
    if(cnt == 1) {
        printf("The average of 1 number is %.2lf", sum);
    } else if(cnt > 1) {
        printf("The average of %d numbers is %.2lf", cnt, sum / cnt);
    } else {
        printf("The average of 0 numbers is Undefined");
    }
    return 0;
}

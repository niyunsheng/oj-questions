/**
 * @Date:   2018-07-17
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-07-30
 */



//PTA 1001:A+B Format (20)
//教训：格式化输入输出，scanf、printf。%m.nf表示整数和小数位数，%md不足补空格，%0md不足补0，%-md左对齐
//最开始用数组先把末尾三位存下来，然后访问数组，但是因为没有区分a=0的情况（此时数组不含任何元素，访问的话导致越界段错误）
#include<iostream>
#include<vector>
using namespace std;
int main(){
	int a=-1000000,b=0;
	cin>>a>>b;
	a+=b;
	bool flag=(a>=0);
	if(!flag)a=-a;
	if(!flag)printf("-");
	if(a<1000)printf("%d",a);
	else if(a>=1000&&a<1000000)printf("%d,%03d",a/1000,a%1000);
	else printf("%d,%03d,%03d",a/1000000,(a/1000)%1000,a%1000);
	return 0;
}

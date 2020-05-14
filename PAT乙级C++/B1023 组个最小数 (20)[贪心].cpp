/**
 * @Date:   2018-08-09
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-09
 */
#include<iostream>
using namespace std;
//1023 组个最小数 (20)
//此题也是非常简单了
int main(){
	//freopen("d:\\codeBlockSpace\\input.txt","r",stdin);
	int num[10];
	for(int i=0;i<10;i++)scanf("%d",num+i);
	for(int i=1;i<10;i++){
		if(num[i]!=0){
			printf("%d",i);
			num[i]--;
			break;
		}
	}
	for(int i=0;i<10;i++){
		while(num[i]>0){
			printf("%d",i);
			num[i]--;
		}
	}
	return 0;
}

/**
 * @Date:   2018-09-06
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-06
 */
#include<cstdio>
#include<cstring>
using namespace std;

#define MAX  100
char numstr[MAX];
int ans[4];
char num[10][10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
int main(){
	//freopen("D:\\codeBlockSpace\\input.txt","r",stdin);
	scanf("%s",numstr);
	int len=strlen(numstr);
	int sum=0;
	for(int i=0;i<len;i++){
		sum+=numstr[i]-'0';
	}
	//if(sum==0){printf("zero");return 0;}
	int top=0;
	while(sum>0){
		ans[top++]=sum%10;
		sum/=10;
	}
	while(top>1){
		printf("%s ",num[ans[--top]]);
	}
	printf("%s",num[ans[0]]);
	return 0;
}

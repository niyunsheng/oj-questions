/**
 * @Date:   2018-08-09
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-28
 */
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
//1005 继续(3n+1)猜想 (25)
//题目也没有什么难度
bool valid[101];
void callatz(int i){
	while(i!=1){
		if(i%2){
			i=(3*i+1)/2;if(i<=100)valid[i]=false;
		}else{
			i=i/2;if(i<=100)valid[i]=false;
		}
	}
}
int main(){
	//freopen("d:\\input.txt","r",stdin);
	memset(valid,0,sizeof(valid));
	valid[1]=true;
	int n,tmp;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&tmp);
		valid[tmp]=true;
	}
	for(int i=2;i<101;i++){
		if(valid[i])
			callatz(i);
	}
	int ans[100];int top=0;
	for(int i=100;i>1;i--){
		if(valid[i])
			ans[top++]=i;
	}
	printf("%d",ans[0]);
	for(int i=1;i<top;i++)
		printf(" %d",ans[i]);
	return 0;
}

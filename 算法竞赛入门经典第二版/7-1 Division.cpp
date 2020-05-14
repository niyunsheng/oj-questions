/**
 * @Date:   2018-08-21
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-21
 */
#include<iostream>
using namespace std;

bool is_diff(int x,int y){
	int book[10]={0};
	int i,j;
	for(int k=0;k<5;k++){
		i=x%10;j=y%10;
		if(book[i]==0)book[i]=1;
		else return false;
		if(book[j]==0)book[j]=1;
		else return false;
		x/=10;y/=10;
	}
	return true;
}
int main(){
	//freopen("d:\\input.txt","r",stdin);
	int n,x,y,flag,cnt=0;

	while(scanf("%d",&n)!=EOF){
		if(n==0)return 0;
		if(cnt++)printf("\n");
		y=1234;
		flag=0;
		while(1){
			x=n*y;
			if(x>98765)break;
			if(is_diff(x,y)){
				flag=1;
				printf("%05d / %05d = %d\n",x,y,n);
			}
			y++;
		}
		if(flag==0)printf("There are no solutions for %d.\n",n);

	}
	return 0;
}

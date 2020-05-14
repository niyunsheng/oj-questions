/**
 * @Date:   2018-09-06
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-06
 */
#include<iostream>
#include<vector>
using namespace std;

int main(){
    //freopen("D:\\CodeBlockSpace\\input.txt","r",stdin);
	int n,b;
	scanf("%d %d",&n,&b);
	if(n==0){printf("Yes\n0");return 0;}
	vector<int> s;
	int top=0;//模拟栈
	while(n>0){
		s.push_back(n%b);
		n/=b;
	}
	top=s.size();
	bool flag=true;
	for(int i=0;i*2<top-1;i++){
		if(s[i]!=s[top-1-i])flag=false;
	}
	if(flag)printf("Yes\n");else printf("No\n");
	for(int i=top-1;i>0;i--){
		printf("%d ",s[i]);
	}
	printf("%d",s[0]);
	return 0;
}

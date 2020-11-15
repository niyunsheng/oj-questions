#include<cstdio>
int cnt = 1;
void DFS(int n,char a,char b, char c){
	if(n==1){
		printf("%d.Move %d from %c to %c\n",cnt++,n,a,c);
	}else{
		DFS(n-1,a,c,b);
		printf("%d.Move %d from %c to %c\n",cnt++,n,a,c);
		DFS(n-1,b,a,c);
	}
}
int main() {
	int n;
	scanf("%d",&n);
	DFS(n,'a','b','c');
	return 0;
}

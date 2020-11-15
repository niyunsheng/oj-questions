#include<cstdio>

int main() {
	int n,max=-1,t;
	int max_rank;
	int v[105];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&v[i]);
	}
	for(int i=0;i<n;i++){
		if(v[i]>max){
			max=v[i];
			max_rank = i;
		}
	}
	max = -1;
	for(int i=0;i<n;i++){
		if(i == max_rank)
			continue;
		if(v[i]>max){
			max=v[i];
		}
	}
	printf("%d",max);
	return 0;
}

// 双指针法
#include<cstdio>
const int MAX=1000000005;
int T,N,A[MAX];
int fun(){
    if(N==1)return 1;
    int i=0,j=1,gap=A[j]-A[i],max_len=1;
    while(i<N&&j<N){
        while(j+1<N&&A[j+1]-A[j]==gap)j++;
        // printf("%d %d\n",i,j);
        max_len = (max_len>j-i)?max_len:j-i+1;
        i=j;j=i+1;gap=A[j]-A[i];
    }
    return max_len;
}
int main(){
    // freopen("in1.txt","r",stdin);
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        scanf("%d",&N);
        for(int j=0;j<N;j++)scanf("%d",&A[j]);
        int ans = fun();
        printf("Case #%d: %d\n",i,ans);
    }
    return 0;
}
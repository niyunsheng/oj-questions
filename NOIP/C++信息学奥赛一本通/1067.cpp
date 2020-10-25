#include<cstdio>
int main(){
    int n,t,t1=0,t2=0,t3=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&t);
        if(t==1)t1++;
        else if(t==5)t2++;
        else if(t==10)t3++;
    }
    printf("%d\n%d\n%d\n",t1,t2,t3);
    return 0;
}

#include<cstdio>
int main(){
    int n;
    bool v[50005];
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        v[i]=true;//表示是素数
    }
    for(int i=2;i*i<=n;i++){
        for(int j=i*i;j<=n;j+=i)
            v[j]=false;
    }
    int cnt=0;
    for(int i=2;i<=n;i++){
        if(v[i])cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}

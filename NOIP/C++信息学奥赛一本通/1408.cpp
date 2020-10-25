#include<cstdio>
int main(){
    int n,k;
    int v1[105];
    float v2[105];
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%d %f",&v1[i],&v2[i]);
    }
    for(int i=0;i<n-1;i++){
        for (int j=0;j<n-1-i;j++){
            if(v2[j]>v2[j+1]){
                int t=v1[j];
                v1[j] = v1[j+1];
                v1[j+1] = t;

                float tt=v2[j];
                v2[j] = v2[j+1];
                v2[j+1] = tt;
            }
        }
    }
    printf("%d %.2f\n",v1[n-k],v2[n-k]);
    return 0;
}

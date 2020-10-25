#include<cstdio>
int main(){
    int m,k;
    scanf("%d %d",&m,&k);
    if(m%19==0){
        int c=0;
        while(m!=0){
            if(m%10==3)c++;
            m/=10;
        }
        if(c==k)printf("YES\n");
        else printf("NO\n");
    }else{
        printf("NO\n");
    }
    return 0;
}

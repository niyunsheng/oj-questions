// https://www.nowcoder.com/ta/huawei
/*
知识点：
    * 动态规划：背包问题
    * 特殊点：有依赖的背包问题
    * 采用分组背包的方法
    * dp[i][j]表示前i个物体，背包容量为j的结果
    * 状态转移方程对第i个物体来说需要分四种情况
        * 主件
        * 主件+附件1
        * 主件+附件2
        * 主件+附件1+附件2
        * dp[i][j] = max(四种情况)
    * 每个物体保存时，需要保存这四种情况对应的价格和重要度，用二维数组表示，第二维为4，表示这四种状态转移的情况
*/
#include "stdio.h"
#define MAXN 65
int max(int a,int b){
    return a>b?a:b;
}
int main(){
    // freopen("in.txt","r",stdin);
    int N,m;
    int weight[MAXN][4],value[MAXN][4];
    for(int i=0;i<MAXN;i++)
        for(int j=0;j<4;j++){
            weight[i][j] = 0;
            value[i][j] = 0;
        }
    int dp[MAXN][3205];// 将价格都除以10，减小dp数组的规模
    // 输入
    scanf("%d %d",&N,&m);
    N /= 10;
    for(int i=1;i<=m;i++){// 从1开始编号
        int v,p,q;
        scanf("%d %d %d",&v,&p,&q);
        v /= 10; // 将价格都除以10
        if(q==0){ // 主件
            weight[i][0] = v;
            value[i][0] = p*v;
        }else{
            if(weight[q][1]==0){
                weight[q][1] = v+weight[q][0];
                value[q][1] = p*v+value[q][0];
            }else if(weight[q][2]==0){
                weight[q][2] = v+weight[q][0];
                value[q][2] = p*v+value[q][0];
                weight[q][3] = v+weight[q][1];
                value[q][3] = p*v+value[q][1];
            }
        }
    }
    // 测试代码
    // for(int i=1;i<=m;i++){
    //     printf("%d %d %d %d\n",weight[i][0],weight[i][1],weight[i][2],weight[i][3]);
    //     printf("%d %d %d %d\n",value[i][0],value[i][1],value[i][2],value[i][3]);
    // }
    // 动态规划
    for(int i=1;i<=m;i++){
        for(int j=N;j>=1;j--){
            int t=0;
            // 状态转移方程
            for(int k=0;k<4;k++){
                if(j>=weight[i][k]){
                    t = max(value[i][k]+dp[i-1][j-weight[i][k]],t);
                }
            }
            dp[i][j] = max(dp[i-1][j],t);
            // printf("%d ",dp[i][j]);
        }
        // printf("\n");
    }
    printf("%d",dp[m][N]*10);

}
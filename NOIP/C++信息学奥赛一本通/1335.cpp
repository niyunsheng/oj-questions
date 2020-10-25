#include<iostream>
#include<queue>
using namespace std; 
const int N = 110;
const int flag[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int a[N][N];
queue<int> qx,qy;
int n, m, ans;
bool p[N][N]={false};

void bfs(int x,int y){
    qx.push(x);
    qy.push(y);
    while (!qx.empty()){
        x = qx.front();qx.pop();
        y = qy.front();qy.pop();
        for (int i = 0;i < 4;++ i){
            int x1 = x + flag[i][0];
            int y1 = y + flag[i][1];
            if (x1 < 1 || y1 < 1 || x1 > n || y1 > m || !a[x1][y1] || p[x1][y1]) continue;
            p[x1][y1] = true;
            qx.push(x1);
            qy.push(y1);
       }
    }
}
int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j) cin >> a[i][j];
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j <= m; ++ j) 
           if (a[i][j] && !p[i][j]) 
           {
              ans++;
              bfs(i,j);
           }
    cout << ans << endl;
    return 0;
}

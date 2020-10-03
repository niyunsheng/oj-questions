/*
安卓手机的老版本密码要求在9个点之间不跨点划线来设置密码，注意，如果要连接的两个点之间经过的点没有被选中，则该点也会自动被选中。
请计算一下四位数及以上的安卓手机密码有多少个？
*/
// 计算安卓老版本手机密码个数
// 计算9!种，DFS试探回溯法剪枝
/* 答案
P[4]=1624
P[5]=7152
P[6]=26016
P[7]=72912
P[8]=140704
P[9]=140704
total=389112
*/
#include<cstdio>
#include<vector>
#include<map>
using namespace std;
bool vis[10] = {false};
int cnt[10] = {0};
vector<int> q;
map<int,int> _m;

bool is_true(){ //判断最后一个元素和前面的元素是否冲突
    if(q.size()<=1)
        return true;
    int a=q[q.size()-2],b=q[q.size()-1];
    if(a>b)swap(a,b);
    if(_m.find(a*10+b)!=_m.end()&&!vis[_m[a*10+b]])
        return false;
    return true;
}
void DFS(){
    for(int i=1;i<=9;i++){
        if(!vis[i]){
            vis[i] = true;
            q.push_back(i);
            if(is_true()){
                cnt[q.size()]++;
                DFS();
            }
            q.pop_back();
            vis[i] = false;
        }
    }
}

int main(){
    // 定义所有相邻节点的中间节点
    _m[13] = 2;
    _m[17] = 4;
    _m[19] = 5;
    _m[28] = 5;
    _m[37] = 5;
    _m[39] = 6;
    _m[46] = 5;
    _m[79] = 8;
    DFS();
    int total = 0;
    for(int i=4;i<=9;i++){
        printf("P[%d]=%d\n",i,cnt[i]);
        total += cnt[i];
    }
    printf("total=%d\n",total);
}

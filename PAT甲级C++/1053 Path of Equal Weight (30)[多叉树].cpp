//1053 Path of Equal Weight (30)
 /*本题需要注意的地方：两种方法，答案是方法一，自己首先想到了方法二
方法一：深度优先搜索，只设置一个辅助栈，空间效率高，函数参数为引用，递归实现
对于数组大小排列，这里提供了一种更加简洁的办法，即在孩子节点数组构建的时候，就给其按照权值大小排序，这里重构的比价函数也很新奇

方法二：广度优先搜索，每次深入复制向量，空间效率不高，另外，需注意二维向量的初始化定义
 1二维数组的定义vector<vector<int>> child(MAX)，这里就可以直接定义大小
 2数组大小比较自定义函数，sort中自定义函数
 */


//方法一：
//

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

//解法一：调用栈的深度优先搜索，可以节省很多空间了。果然是答案定义的这个结构体数组更加简洁

#define MAX 105

vector<vector<int>> ans;//记录答案

//直接在这里定义节点数组，对于内部的孩子节点vector,可调用sort对其进行排序
struct node{
    int w;//权值
    vector<int> child;
}Node[MAX];

void DFS(int cur,vector<int>& sta,int key){
    if(Node[cur].child.size()==0){
        if(Node[cur].w==key){
            sta.push_back(Node[cur].w);
            ans.push_back(sta);
            sta.pop_back();
        }
        return;
    }
    sta.push_back(Node[cur].w);
    for(int i=0;i<Node[cur].child.size();i++){
        if(key>=Node[cur].w)DFS(Node[cur].child[i],sta,key-Node[cur].w);
    }
    sta.pop_back();
}
bool cmp(int a,int b){return Node[a].w>Node[b].w;}

int main()
{
    //freopen("d:\\codeBlockSpace\\input.txt","r",stdin);
    int N,M,Key;
    scanf("%d %d %d",&N,&M,&Key);
    for(int i=0;i<N;i++)scanf("%d",&(Node[i].w));
    int r,m,t;
    while(scanf("%d",&r)!=EOF){
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            scanf("%d",&t);
            Node[r].child.push_back(t);
        }
        //因为这里是按照节点权值大小进行排序，所以要引入自定义排序函数cmp
        //这个引入方法好赞
        sort(Node[r].child.begin(),Node[r].child.end(),cmp);
    }
    int root=0;//根据题意，0节点为根节点

    vector<int> ch;//用向量模拟栈，进行深度优先搜索
    DFS(root,ch,Key);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size()-1;j++)
            printf("%d ",ans[i][j]);
        printf("%d\n",ans[i][ans[i].size()-1]);
    }
    return 0;
}





//方法二：
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MAX 100
//注意这里二维vector的定义，用二维数组记录各个节点的孩子
vector<vector<int>> child(MAX);
int w[MAX];//记录各节点权值
vector<vector<int>> ans;//记录答案

void travel(int cur,vector<int> t,int key){
    if(child[cur].size()==0){
        if(key==w[cur]){
            t.push_back(w[cur]);
            ans.push_back(t);
        }else return;
    }else{
        if(key>=w[cur]){
            t.push_back(w[cur]);
            for(int i=0;i<child[cur].size();i++){
                travel(child[cur][i],t,key-w[cur]);
            }
        }
    }
}
bool cmp(const vector<int>& a,const vector<int>& b){
    int i;
    for(i=0;i<a.size()&&i<b.size();i++){
        if(a[i]>b[i])return true;
        if(a[i]<b[i])return false;
    }
    if(i==a.size())return false;
}
int main()
{
    //freopen("d:\\codeBlockSpace\\input.txt","r",stdin);
    int N,M,Key;
    scanf("%d %d %d",&N,&M,&Key);

    //从根节点开始遍历，用p[N]数组记录其父亲节点
    int p[N];
    for(int i=0;i<N;i++)p[i]=i;

    for(int i=0;i<N;i++)scanf("%d",w+i);
    int node,m,t;
    while(scanf("%d",&node)!=EOF){
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            scanf("%d",&t);
            p[t]=node;
            child[node].push_back(t);
        }
    }
    //找到根节点，从这里开始遍历
    int root=0;
    while(p[root]!=root)root=p[root];
    vector<int> tt;
    travel(root,tt,Key);
    sort(ans.begin(),ans.end(),cmp);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size()-1;j++)
            printf("%d ",ans[i][j]);
        printf("%d\n",ans[i][ans[i].size()-1]);
    }
    return 0;
}

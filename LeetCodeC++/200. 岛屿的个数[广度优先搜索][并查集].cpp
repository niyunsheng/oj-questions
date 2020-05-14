/**
 * @Date:   2018-08-03
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-03
 */

 /*本题两种方法，一种是用广度优先搜索，另一种是并查集
 方法一：广度优先搜索
 思路是很简单的，但是碰到的几个问题却耽误了近一小时时间
 1.vector<vector<bool>> find(m,vector<bool>(n,false));注意这个写法
 2.又发现一个关于二维数组传递参数的大问题
 int a[m][n];这里的a的类型是int (*)[n];即行指针(每行n个元素)，a[0]表示第一行的指针，a[1]表示第二行的指针
 而函数的参数是add(int**,m,n)。调用时写add(a,m,n),就会出现类型不匹配的问题，即int (*)[n]不能转化为int** 型
 int (*p)[3];//定义一个指针变量，所指对象三个整型变量，是行指针。特别要注意这里行指针的类型，
 int *p[3];//这个定义一个指针数组，有三个元素，每个元素都是整型指针。
 但是，如果n的值不是宏定义的话，这样的函数参数是不允许的
 比如void add(int (*a)[n],int m,int n)会报错
 解决办法就是改用vector引用，但是一定要知道1中提到的二维vector的定义方法

 或者改用malloc为其分配空间，用指针来给二维数组分配空间m*n,二者都需要输入
 int** p=(int**)malloc(m*sizeof(int*));
 p[0]=(int*)malloc(n*sizeof(int));

 最简单易行的还是直接分配最大空间

 3.那么，二维指针是什么呢？二维指针就是指针数组的地址
 例如：
 	int a[3]={1,2,3};
    int b[3]={4,5,6};
    int* c[2]={a,b};
	a,b是int类型的指针，c中存放的元素时int类型的指针，所以，c是二维指针
	这是调用add(c,m,n)就没有问题，其中add的声明为，void add(int** a,int m,int n)

即要注意到二维指针和数组的行指针的区别，a[m][n]，a不是一个二维指针，本质上是一个一维指针，是一个行指针
4.vector构造的简单方法如下：
vector<vector<char>> grid;
char t1[5]={'1','1','0','0','0'};vector<char> a1(t1,t1+5);grid.push_back(a1);
 */
 #include <iostream>
 #include<vector>
 #include<queue>
 using namespace std;
     //初始化所有节点为未发现状态，对每一个节点用广度优先搜索，并把该节点置为已发现。
     //记录上下左右x，y的变化，便于循环向四个方向前进
     int xx[4]={0,0,-1,1};
     int yy[4]={1,-1,0,0};


     //记录区域的大小
     int m,n;
     //广度优先搜索，用队列实现
     struct node{
         int x,y;
         node(int xx=0,int yy=0):x(xx),y(yy){}
     };
     void BFS(vector<vector<char>>& grid,int i,int j,vector<vector<bool>>& find){

         find[i][j]=true;
         queue<node> q;
         q.push(node(i,j));
         node cur;
         int ni,nj;
         while(!q.empty()){
             cur=q.front();
             q.pop();
             for(int k=0;k<4;k++){
                 ni=cur.x+xx[k];nj=cur.y+yy[k];
 				//这里把m,n写反了，导致下标越界，真是不好检查啊！
                 if(ni>=0&&ni<m&&nj>=0&&nj<n&&!find[ni][nj]&&grid[ni][nj]=='1'){
                     find[ni][nj]=true;q.push(node(ni,nj));
                 }
             }
         }

     }
     int numIslands(vector<vector<char>>& grid) {
         m=grid.size();
         if(m==0)return 0;
         n=grid[0].size();
         //注意这里二维向量的初始化问题，已经栽了好几个跟头了
         vector<vector<bool>> find(m,vector<bool>(n,false));

         int mx=0;//记录发现岛屿的总数
         for(int i=0;i<m;i++){
             for(int j=0;j<n;j++){
                 if(!find[i][j]&&grid[i][j]=='1'){
                     mx++;BFS(grid,i,j,find);
                 }
             }
         }
         return mx;
     }
 int main(){
     //freopen("D:\\CodeBlockSpace\\input.txt","r",stdin);
     vector<vector<char>> grid;
     char t1[5]={'1','1','0','0','0'};vector<char> a1(t1,t1+5);grid.push_back(a1);
     char t2[5]={'1','1','0','0','0'};vector<char> a2(t2,t2+5);grid.push_back(a2);
     char t3[5]={'0','0','1','0','0'};vector<char> a3(t2,t2+5);grid.push_back(a3);
     char t4[5]={'0','0','0','1','1'};vector<char> a4(t2,t2+5);grid.push_back(a4);
     int m=numIslands(grid);
     cout << m << endl;
     return 0;
 }

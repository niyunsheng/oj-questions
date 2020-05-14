/**
 * @Date:   2018-08-03
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-03
 */
 #include<iostream>
 #include<vector>
 #include<queue>
 #include"string.h"
 using namespace std;
 //和二维广度优先搜索如出一辙，还是要注意二三维向量的写法，要么就写数组，给定最大值


 struct node{
     int i,j,k;
     node(int ii=0,int jj=0,int kk=0):i(ii),j(jj),k(kk){}
 };
 //设遍历方向为前后左右上下,i,j,k分别表示z、x、y方向
 int vec_i[6]={0,0,0,0,1,-1};
 int vec_j[6]={0,0,-1,1,0,0};
 int vec_k[6]={1,-1,0,0,0,0};
 int main(){
     //freopen("D:\\CodeBlockSpace\\input.txt","r",stdin);
     int M,N,L,T;
     scanf("%d %d %d %d",&M,&N,&L,&T);
     //这里两种定义数组的方法都是可以的，显然，两个维度都知道的话，c数组更简洁，当第一维已知，第二维未知时，比如图的邻接表表示，用向量更方便
     vector<vector<vector<int>>> brain(L,vector<vector<int>>(M,vector<int>(N,0)));
     //int brain[L][M][N];这种写法编译不通过，应该用指针的写法
     for(int i=0;i<L;i++){
         for(int j=0;j<M;j++){
             for(int k=0;k<N;k++){
                 scanf("%d",&brain[i][j][k]);
             }
         }
     }
 	vector<vector<vector<bool>>> finded(L,vector<vector<bool>>(M,vector<bool>(N,false)));
     //bool finded[L][M][N];//编译不通过//memset(finded,0,sizeof(finded));
     int sum=0;//记录所有块的大小之和
     for(int i=0;i<L;i++){
         for(int j=0;j<M;j++){
             for(int k=0;k<N;k++){
                 //BFS无需递归，用队列实现，为了避免传参数的麻烦，直接在这里实现
                 if(!(finded[i][j][k])&&brain[i][j][k]==1){
                     int subsum=0;//记录子块的大小
                     queue<node> q;
                     node t(i,j,k);
                     q.push(t);
                     finded[i][j][k]=true;subsum++;

                     while(!q.empty()){
                         t=q.front();q.pop();
                         int ci=t.i,cj=t.j,ck=t.k;//当前坐标
                         int ni,nj,nk;//下一个坐标
                         for(int a=0;a<6;a++){//6个方向分别搜索
                             ni=ci+vec_i[a];nj=cj+vec_j[a];nk=ck+vec_k[a];
                             if(ni>=0&&ni<L&&nj>=0&&nj<M&&nk>=0&&nk<N&&!finded[ni][nj][nk]&&brain[ni][nj][nk]==1){
                                 q.push(node(ni,nj,nk));finded[ni][nj][nk]=true;subsum++;
                             }
                         }
                     }
                     if(subsum>=T)sum+=subsum;
                 }
             }
         }
     }
     printf("%d",sum);
     return 0;
 }

//更加简便清晰的办法是定义全局变量，BFS单独写在外面

bool vis[1286][128][60]={0},data[1286][128][60];
int M,N,L,T,t;
int x[6]={1,-1,0,0,0,0},y[6]={0,0,1,-1,0,0},z[6]={0,0,0,0,1,-1};
#define legal(j,k,i) (j>=0&&j<M&&k>=0&&k<N&&i>=0&&i<L)
struct node{int j,k,i;node(int jj,int kk,int ii):j(jj),k(kk),i(ii){}};
int BFS(int j,int k,int i){
	int cnt=1;
	vis[j][k][i]=true;
	queue<node> q;
	q.push(node(j,k,i));
	while(!q.empty()){
		node cur=q.front();q.pop();
		_for(t,0,6){
			int nj=cur.j+x[t],nk=cur.k+y[t],ni=cur.i+z[t];
			if(legal(nj,nk,ni)&&data[nj][nk][ni]&&!vis[nj][nk][ni]){
				//printf("%d %d %d data=%d vis=%d\n",nj,nk,ni,data[nj][nk][ni],vis[nj][nk][ni]);
				cnt++;
				vis[nj][nk][ni]=true;
				q.push(node(nj,nk,ni));
			}
		}
	}
	//cout<<cnt<<endl;
	return cnt;
}
void printvec(vector<int>& vec){
	printf("%d",vec[0]);
	_for(i,1,vec.size()){printf(" %d",vec[i]);}
	printf("\n");
}

int main(){
	freopen("D:\\input.txt","r",stdin);

	cin>>M>>N>>L>>T;

	int cnt=0;
	_for(i,0,L){
		_for(j,0,M){
			_for(k,0,N){
				scanf("%d",&t);
				data[j][k][i]=t;
			}
		}
	}
	_for(i,0,L){
		_for(j,0,M){
			_for(k,0,N){
				if(data[j][k][i]&&!vis[j][k][i]){
					int t=BFS(j,k,i);
					if(t>=T)cnt+=t;
				}
			}
		}
	}
	printf("%d\n",cnt);
	return 0;
}

/**
 * @Date:   2018-08-22
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-22
 */
//真不如一开始就写两个DFS省事
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
/*
	出现编译错误的原因肯定是缺少了头文件，这里没有加csting，memset是其中函数
*/
char grid[55][55];
int vis[2][55][55];//vis[0]表示可以从起始点到达此位置，vis[1]表示可以由该位置到达终点
int m,n,cnt=0;
bool is_legal(int i,int j,int flag){
	return i>=0&&i<m&&j>=0&&j<n&&vis[flag][i][j]==0&&grid[i][j]!='#';
}
void DFS(int i,int j,int flag){//flag：0表示从起始点遍历，1表示从结尾遍历，因为两者遍历时对于'.'的解释不同
	//printf("%d %d flag=%d\n",i,j,flag);
	switch(grid[i][j]){
		case 'S':
		case 'T':
		case '+':
			if(is_legal(i,j-1,0)){vis[flag][i][j-1]=1;DFS(i,j-1,flag);}
			if(is_legal(i,j+1,0)){vis[flag][i][j+1]=1;DFS(i,j+1,flag);}
			if(is_legal(i-1,j,0)){vis[flag][i-1][j]=1;DFS(i-1,j,flag);}
			if(is_legal(i+1,j,0)){vis[flag][i+1][j]=1;DFS(i+1,j,flag);}
			break;
		case '|':
			if(is_legal(i-1,j,0)){vis[flag][i-1][j]=1;DFS(i-1,j,flag);}
			if(is_legal(i+1,j,0)){vis[flag][i+1][j]=1;DFS(i+1,j,flag);}
			break;
		case '-':
			if(is_legal(i,j-1,0)){vis[flag][i][j-1]=1;DFS(i,j-1,flag);}
			if(is_legal(i,j+1,0)){vis[flag][i][j+1]=1;DFS(i,j+1,flag);}
			break;
		case '.':
			if(is_legal(i+1,j,0)){vis[flag][i+1][j]=1;DFS(i+1,j,flag);}
			break;
		case '#':
			break;
	}

}
void DFS2(int i,int j,int flag){
	//这里要考虑的是分别判断从哪个节点可以走到当前节点，而不是从当前节点可以走到哪个节点
	//printf("%d %d flag=%d\n",i,j,flag);
	if(is_legal(i,j-1,1)){
		char c=grid[i][j-1];
		if(c=='S'||c=='T'||c=='+'||c=='-')
			{vis[flag][i][j-1]=1;DFS2(i,j-1,flag);}
	}
	if(is_legal(i,j+1,1)){
		char c=grid[i][j+1];
		if(c=='S'||c=='T'||c=='+'||c=='-')
			{vis[flag][i][j+1]=1;DFS2(i,j+1,flag);}
	}
	if(is_legal(i-1,j,1)){
		char c=grid[i-1][j];
		if(c=='S'||c=='T'||c=='+'||c=='|'||c=='.')
			{vis[flag][i-1][j]=1;DFS2(i-1,j,flag);}
	}
	if(is_legal(i+1,j,1)){
		char c=grid[i+1][j];
		if(c=='S'||c=='T'||c=='+'||c=='|')
			{vis[flag][i+1][j]=1;DFS2(i+1,j,flag);}
	}
}
int main() {
	//freopen("d:\\input.txt","r",stdin);

	scanf("%d %d",&m,&n);
	int str[2],end[2];//记录开始结束节点
	for(int i=0;i<m;i++){
		getchar();
		for(int j=0;j<n;j++){
			 grid[i][j]=getchar();
			 if(grid[i][j]=='S'){
			 	str[0]=i;str[1]=j;
			 }else if(grid[i][j]=='T'){
			 	end[0]=i;end[1]=j;
			 }
		}

	}
	//两次DFS，分别记录vis1\vis2数组
	memset(vis,0,2*55*55*sizeof(int));
	vis[0][str[0]][str[1]]=1;
	vis[1][end[0]][end[1]]=1;
	DFS(str[0],str[1],0);
	if(vis[0][end[0]][end[1]]==0){printf("I'm stuck!\n");return 0;}
	//从终点反向遍历的话，规则还是很多不同的，所以，需要重新写DFS函数
	DFS2(end[0],end[1],1);
	cnt=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			//printf("%d",vis[1][i][j]);
			if(vis[0][i][j]==1&&vis[1][i][j]==0){
				cnt++;
				//printf("%d %d\n",i,j);
			}

		}
		//printf("\n");
	}
	printf("%d\n",cnt);
	return 0;
}

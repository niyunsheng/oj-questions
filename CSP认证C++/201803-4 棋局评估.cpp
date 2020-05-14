/**
 * @Date:   2018-09-11
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-11
 */
#include<cstdio>
#include<iostream>
#include<set>
#include<vector>
#include<queue>
#include<map>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

//201803-4 棋局评估
//答案错误，0分，不知原因，实在看不出来哪里错了，感觉哪里都对，每一层的DFS判断也改成了局部变量
const int MAXN=205;
int chese[3][3];//chese[y][x]
#define inf 0x7fffffff
typedef long long LL;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
int N;
int tmpscore;
//返回-1说明游戏还没结束，分数说明游戏结束了，0表示平局，其他分数说明一方胜利,100-200说明甲胜利，200以上说明乙胜利
int gameover(){//tmpscore不能是全局变量，会导致错误，这里还没修改完的被其他地方修改了，可能是这个错误
	int flag=0;
	_for(i,0,3)
		if(chese[i][1]!=0&&chese[i][1]==chese[i][2]&&chese[i][3]==chese[i][2]){
			flag=chese[i][1];
		}
	if(flag==0)
	_for(i,0,3)
		if(chese[1][i]!=0&&chese[1][i]==chese[2][i]&&chese[3][i]==chese[2][i]){
			flag=chese[1][i];
		}
	if(flag==0&&chese[0][0]!=0&&chese[0][0]==chese[1][1]&&chese[1][1]==chese[2][2])
		flag=chese[1][1];
	if(flag==0&&chese[2][0]!=0&&chese[2][0]==chese[1][1]&&chese[1][1]==chese[0][2])
		flag=chese[1][1];
	//空格数
	int cnt=0;
	_for(i,0,3)
	_for(j,0,3)
	if(chese[i][j]==0)cnt++;

	if(flag==0){
		if(cnt==0){
			return 0;
		}else return -1;
	}else{
		if(flag==1)return 100+cnt+1;
		return 200+cnt+1;
	}
}
int maxMinDFS(int flag){//flag=1表示最大值搜索，flag=2表示最小值搜索
	int t=gameover();
	if(t!=-1){
		if(t>200)return 200-t;
		else if(t>100)return t-100;
		else return t;
	}
	int score;
	if(flag==1)score=-100;
	else score=100;
	_for(i,0,3)
	_for(j,0,3)
	if(chese[i][j]==0){
		chese[i][j]=flag;
		int tmp=maxMinDFS(3-flag);
		//printf("flag=%d tmpscore=%d score=%d\n",flag,tmpscore,score);
		if(flag==1&&tmp>score)score=tmp;
		else if(flag==2&&tmp<score)score=tmp;
		chese[i][j]=0;
	}
	//printf("flag=%d score=%d\n",flag,score);
	return score;
}
int main(){
	//freopen("d:\\input.txt","r",stdin);
	//freopen("d:\\output.txt","w",stdout);
	cin>>N;
	_for(i,0,N){
		_for(j,0,3){
			_for(k,0,3){
				cin>>chese[j][k];
			}
		}
		int score=maxMinDFS(1);
		printf("%d\n",score);
	}
	return 0;
}

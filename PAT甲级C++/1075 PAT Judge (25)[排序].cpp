/**
 * @Date:   2018-08-08
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-27
 */

/*
本题条件众多，应该考虑到：
1 只要有一个编译成功的就可以输出，注意编译错误的输出和编译正确0分的输出不同，只要有编译通过的该同学的成就就可以被输出
2 完美数量不能重复加
3 将无效点的总分记为-1，则排序时自动排在后面
*/
#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
struct node{
	int id,prefect,totalscore,rank;
	int score[6];
	bool flag;//记录该学生的成绩是否输出
	node():totalscore(0),prefect(0),flag(false){memset(score,0xff,6*sizeof(int));}
};
bool cmp(node& a,node& b){
	if(a.totalscore!=b.totalscore)return a.totalscore>b.totalscore;
	else if(a.prefect!=b.prefect)return a.prefect>b.prefect;
	else return a.id<b.id;
	//return a.totalscore>b.totalscore||(a.totalscore==b.totalscore&&a.prefect>b.prefect)||(a.totalscore==b.totalscore&&a.prefect==b.prefect&&a.id<b.id);
}
int main(){
	//freopen("D:\\input.txt","r",stdin);
	int N,K,M;
	scanf("%d %d %d",&N,&K,&M);
	int pp[6];//各个问题满分
	vector<node> stu(10001);
	for(int i=1;i<=K;i++)
		scanf("%d",&pp[i]);
	int id,kth,s;
	for(int i=0;i<M;i++){
		scanf("%d %d %d",&id,&kth,&s);
		stu[id].id=id;
		//最后一个答案错误是因为该提交之前通过，后来又提交编译没过
		if(s==-1){
			if(stu[id].score[kth]==-1)stu[id].score[kth]=0;
		}else stu[id].flag=true;//只要不是编译错误均可以被输出

		if(stu[id].score[kth]<s){
			stu[id].score[kth]=s;
			if(s==pp[kth])stu[id].prefect++;
		}

	}
	for(int i=1;i<=N;i++){
		if(stu[i].flag){
			for(int j=1;j<=K;j++)
				if(stu[i].score[j]!=-1)stu[i].totalscore+=stu[i].score[j];
		}else
			stu[i].totalscore=-1;
	}


	sort(stu.begin()+1,stu.begin()+N+1,cmp);
	stu[1].rank=1;
	printf("1 %05d %d",stu[1].id,stu[1].totalscore);
	for(int i=1;i<=K;i++){
		if(stu[1].score[i]!=-1)printf(" %d",stu[1].score[i]);
		else printf(" -");
	}
	printf("\n");
	for(int i=2;i<=N;i++){
		if(!stu[i].flag)break;//将排序处理好，有效点放在无效点前面，遇到无效点即退出
		else{
			if(stu[i].totalscore==stu[i-1].totalscore)stu[i].rank=stu[i-1].rank;
			else stu[i].rank=i;
			printf("%d %05d %d",stu[i].rank,stu[i].id,stu[i].totalscore);
			for(int j=1;j<=K;j++){
				if(stu[i].score[j]!=-1)printf(" %d",stu[i].score[j]);
				else printf(" -");
			}
		}
		printf("\n");
	}
	return 0;
}

/**
 * @Date:   2018-08-07
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-27
 */
/*
思路：
方法一：
本题本人采取的思路是利用堆排序和dp来确定任何一个分数的名次。结构体数组的规模是1000000，存储任何一个学号对应的成绩。结构体数组不排序，用下标作为id。名次的获得采用桶排序O(n)
方法一：
首先需要用结构体变量存储学生信息，然后计算每个学生各个科目的成绩排名，然后通过id查询最大的排名。
结构体应存储学生的id、四个科目的成绩，然后用sort排序，分别用不同的科目成绩作为排序的标准（具体实现用数组循环实现），这样就得到了成绩排名，然后把遍历排序后的数组，即可得到各个id对应的名次。
由于不清楚学号的范围（仅知道六位数），所以用rank[1000000][4]的数组记录学生各科目成绩。最后根据id即可在O(1)时间内得到最大排名。

注意：
题目没有说相同排名时如何计算，那就默认1,2,3,3,5.而不是1,2,3,3,4。
题目没有说平均分是向下取整还是四舍五入，可以直接存储总分来避免这个问题
*/
//方法一：
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int N,L,H;
struct stu{
	bool exist;
	int c,m,e,a;
	stu(int cc=0,int mm=0,int ee=0,int aa=0,bool xx=false):c(cc),m(mm),e(ee),a(aa),exist(xx){}
}STU[1000000];
int Cheap[101],Mheap[101],Eheap[101],Aheap[101];
int Cdp[101],Mdp[101],Edp[101],Adp[101];//表示分数为i的人的名次100分第一名，99分要看100分有几个人
int main(){
	//freopen("D:\\input.txt","r",stdin);
	int N,M;
	int id,c,m,e;
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++){
		scanf("%d %d %d %d",&id,&c,&m,&e);
		STU[id]=stu(c,m,e,(c+m+e)/3,true);
		Cheap[c]++;
		Mheap[m]++;
		Eheap[e]++;
		Aheap[(c+m+e)/3]++;
	}
	Cdp[100]=0;Mdp[100]=0;Edp[100]=0;Adp[100]=0;
	for(int i=99;i>=0;i--){
		Cdp[i]=Cdp[i+1]+Cheap[i+1];
		Mdp[i]=Mdp[i+1]+Mheap[i+1];
		Edp[i]=Edp[i+1]+Eheap[i+1];
		Adp[i]=Adp[i+1]+Aheap[i+1];
	}
	int rank[4],bestrank;
	char subj[4]={'A','C','M','E'};
	for(int i=0;i<M;i++){
		bestrank=0;
		scanf("%d",&id);
		if(STU[id].exist){
			rank[1]=Cdp[STU[id].c]+1;
			rank[2]=Mdp[STU[id].m]+1;
			rank[3]=Edp[STU[id].e]+1;
			rank[0]=Adp[STU[id].a]+1;
			for(int i=1;i<4;i++){
				if(rank[i]<rank[bestrank]){
					bestrank=i;
				}
			}
			printf("%d %c\n",rank[bestrank],subj[bestrank]);
		}else{
			printf("N/A\n");
		}
	}
}

//方法二
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
//1012 The Best Rank (25)
int N,L,H;
struct stu{
	int id;
	int grade[4];
	stu(int ii=0,int cc=0,int mm=0,int ee=0,int aa=0):id(ii){grade[1]=cc;grade[2]=mm;grade[3]=ee;grade[0]=aa;}
}STU[2001];//不超过两千个学生
int sortrank;
bool cmp(stu& a,stu& b){
	return a.grade[sortrank]>b.grade[sortrank];
}
//用数组记录排名信息，方便查找
int graderank[1000000][4];
int main(){
	//freopen("D:\\input.txt","r",stdin);
	int N,M;
	int id,c,m,e;
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++){
		scanf("%d %d %d %d",&id,&c,&m,&e);
		STU[i]=stu(id,c,m,e,(c+m+e)/3);
	}
	for(int i=0;i<4;i++){
		sortrank=i;
		sort(STU,STU+N,cmp);//这里不包含尾指针
		graderank[STU[0].id][i]=1;
		for(int j=1;j<N;j++){
			if(STU[j].grade[i]==STU[j-1].grade[i])
				graderank[STU[j].id][i]=graderank[STU[j-1].id][i];
			else
				graderank[STU[j].id][i]=j+1;
		}
	}
	int bestrank;
	char subj[4]={'A','C','M','E'};
	for(int i=0;i<M;i++){
		bestrank=0;
		scanf("%d",&id);
		if(graderank[id][0]!=0){
			for(int i=1;i<4;i++){
				if(graderank[id][i]<graderank[id][bestrank]){
					bestrank=i;
				}
			}
			printf("%d %c\n",graderank[id][bestrank],subj[bestrank]);
		}else{
			printf("N/A\n");
		}
	}
}

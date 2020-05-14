/**
 * @Date:   2018-08-08
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-27
 */
/*
> 思路：
> 1. 首先按照题目要求给学生排序，这是题目考察的第一点
> 2. 通过记录各个学校的剩余可录取人数和最后一个录取同学的分数，就可以判断申请的同学可不可以录取
> 3. 最后将各个学校的录取学生排序输出即可
*/
 //1080 Graduate Admission (30)
 //本题还是一次通过，用记录上一次录取同学成绩的方法来判断容量满时的录取情况
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
	int id,GE,GI;
	vector<int> prefer;
	node():GE(-1),GI(-1){}
};
bool cmp(node& a,node& b){
	if(a.GE+a.GI!=b.GE+b.GI)return a.GE+a.GI>b.GE+b.GI;
	else if(a.GE!=b.GE)return a.GE>b.GE;
	else return a.id<b.id;
}
int main(){
	//freopen("D:\\codeBlockSpace\\input.txt","r",stdin);
	int N,M,K;
	int tmp;
	scanf("%d %d %d",&N,&M,&K);
	vector<int> quota(M);//最多可以录取同学数量
	vector<int> capa(M,0);//已录取同学数量
	vector<node> last(M);//记录该学校最后一次录取的同学的成绩
	vector<node> stu(N);
	vector<int> statue(N);//记录该同学的录取状态，好像用不着这个数据
	vector<vector<int>> enrolled(M);//记录录取的同学序号，方便排序
	for(int i=0;i<M;i++)scanf("%d",&quota[i]);
	for(int i=0;i<N;i++){
		stu[i].id=i;
		scanf("%d %d",&stu[i].GE,&stu[i].GI);
		for(int j=0;j<K;j++){
			scanf("%d",&tmp);
			stu[i].prefer.push_back(tmp);
		}
	}
	sort(stu.begin(),stu.end(),cmp);
	for(int i=0;i<N;i++){
		for(int j=0;j<K;j++){
			if(capa[stu[i].prefer[j]]<quota[stu[i].prefer[j]]){
				capa[stu[i].prefer[j]]++;
				enrolled[stu[i].prefer[j]].push_back(stu[i].id);
				if(capa[stu[i].prefer[j]]==quota[stu[i].prefer[j]])
					last[stu[i].prefer[j]]=stu[i];
				break;
			}else{//这里判断虽然录取学校容量满了，但是成绩并列的情况
				if(stu[i].GE==last[stu[i].prefer[j]].GE&&stu[i].GI==last[stu[i].prefer[j]].GI){
					capa[stu[i].prefer[j]]++;
					enrolled[stu[i].prefer[j]].push_back(stu[i].id);
					break;
				}
			}
		}
	}
	for(int i=0;i<M;i++){
		if(enrolled[i].size()==0)printf("\n");
		else{
			sort(enrolled[i].begin(),enrolled[i].end());
			printf("%d",enrolled[i][0]);
			for(int j=1;j<enrolled[i].size();j++){
				printf(" %d",enrolled[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}

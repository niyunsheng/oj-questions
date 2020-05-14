/**
 * @Date:   2018-08-08
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-27
 */
/*思路：
每次按照不同年龄段分别排序，全部算例超时，时间复杂度太高。
正确的做法是只排序一次，然后从头到尾遍历，如果在题目要求的年龄段则输出。
但是这样也会有一个算例超时，注意到输出的总人数最多100人，所以，在排序后可以先进行预处理，每个年龄最多有100个人，将这些人加入到新的向量当中，然后每次查询在新的向量中遍历，把符合条件的人输出即可。
*/
#include<iostream>
#include"string.h"
#include<vector>
#include<algorithm>
using namespace std;
//1055 The World's Richest (25)
int N,K,M;
int Amin,Amax;
struct node{
	int age,worth;
	char name[10];
};
bool cmp(node& a,node& b){
	return a.worth>b.worth||(a.worth==b.worth&&a.age<b.age)||(a.worth==b.worth&&a.age==b.age&&strcmp(a.name,b.name)<0);
}
int main(){
	//freopen("D:\\input.txt","r",stdin);
	scanf("%d %d",&N,&K);
	vector<node> STU(100001);

	for(int i=0;i<N;i++){
		scanf("%s %d %d",STU[i].name,&STU[i].age,&STU[i].worth);
	}
	sort(STU.begin(),STU.begin()+N,cmp);
	//第二步是预处理，每个年龄段最多100人
	vector<node> valid(100001);int top=0;
	int agenum[201]={0};
	for(int i=0;i<N;i++){
		if(agenum[STU[i].age]<100){
			valid[top++]=STU[i];
			agenum[STU[i].age]++;
		}
	}
	int count=0;
	for(int i=1;i<=K;i++){
		count=0;
		scanf("%d %d %d",&M,&Amin,&Amax);
		printf("Case #%d:\n",i);
		for(int j=0;j<top&&count<M;j++){
			if(valid[j].age>=Amin&&valid[j].age<=Amax){
				printf("%s %d %d\n",valid[j].name,valid[j].age,valid[j].worth);
				count++;
			}
		}
		if(count==0){printf("None\n");}
	}
	return 0;
}

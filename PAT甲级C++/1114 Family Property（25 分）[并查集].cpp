/**
 * @Date:   2018-08-09
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-09
 */
//1114 Family Property（25 分）
//其实本题就是并查集的基本操作而已了，刚开始觉得好难是因为刚开始接触的原因
//人生感悟：困难的时候就是自己进步的时候，跨过这道坎，就是柳暗花明
//1114 Family Property (25)
//并查集的运用
//注意join的写法，刚开始就只写了最后一行那句，这样会导致出现了一个cluster有多个代表的情况出现。
//并查集，合并的时候编号小的作为父亲节点，最后父亲节点一样的即属于一个家庭，其它都是细节处理没啥好说了。
#include<iostream>
#include<algorithm>
using namespace std;

int fa[10000];//记录各个节点的父节点，最大1000，最小1
//并查集基本操作，要非常熟练
int find(int i){
	return i==fa[i]?i:(i=find(fa[i]));
}
void join(int i,int j){//将两节点合并，小的做的根节点
	int fi=find(i);
	int fj=find(j);
	if(fi>fj)fa[fi]=fj;
	else fa[fj]=fi;
}
bool same(int i,int j){
	return find(i)==find(j);
}
struct family{
	int id;
	int num;
	float set;
	float area;
	bool operator<(family& b){
		return (b.area<area)||(b.area==area&&b.id>id);
	}
};
int main(){
	//freopen("d:\\codeBloackSpace\\input.txt","r",stdin);
	bool people[10000]={0};//人的状态，即是否存在该编号
	int M_estate[10000]={0};
	int Area[10000]={0};
	int root[10000]={0};//记录该节点为根节点的家族成员总数
	int kid,k,n;//
	int tmp;//接收临时变量
	scanf("%d",&n);
	//题目并没有说id不能是0，看来，忽略了id=0这种情况导致两个算例出错
	for(int i=0;i<10000;i++){fa[i]=i;}
	for(int i=0;i<n;i++){
		scanf("%d",&kid);people[kid]=true;
		scanf("%d",&tmp);if(tmp!=-1){people[tmp]=true;join(tmp,kid);}
		scanf("%d",&tmp);if(tmp!=-1){people[tmp]=true;join(tmp,kid);}
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			scanf("%d",&tmp);
			people[tmp]=true;
			join(tmp,kid);
		}
		scanf("%d",&M_estate[kid]);
		scanf("%d",&Area[kid]);
	}
	for(int i=0;i<10000;i++){
		if(people[i]){
			int j=find(i);
			if(i!=j){M_estate[j]+=M_estate[i];Area[j]+=Area[i];}
			root[j]++;
		}
	}
	int sum=0;
	vector<family> ans;
	for(int i=0;i<10000;i++)
		if(people[i]&&find(i)==i){
			family fami;
			fami.id=i;fami.num=root[i];fami.set=(float)M_estate[i]/root[i];fami.area=(float)Area[i]/root[i];
			sum++;ans.push_back(fami);
		}
	sort(ans.begin(),ans.end());
	printf("%d\n",sum);
	for(int i=0;i<ans.size();i++){
		printf("%04d %d %.3f %.3f\n",ans[i].id,ans[i].num,ans[i].set,ans[i].area);
	}
    return 0;
}

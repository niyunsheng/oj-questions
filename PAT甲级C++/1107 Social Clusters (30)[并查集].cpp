/**
 * @Date:   2018-07-20
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-07
 */
//将hobby对应到人，将人也对应到人。相比1118只问了有几个并查集，那么，不需要对人进行处理，只处理hobby即可。而本题还问了有几个人属于一个并查集，那么就得把人也纳入并查集，就需要把人和hobby节点离散化处理

//1107 Social Clusters (30)
//并查集的运用
//注意join的写法，刚开始就只写了最后一行那句，这样会导致出现了一个cluster有多个代表的情况出现。
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool comp(int a,int b){
	return a>b;
}
int father[1001];//记录各个节点的父节点，最大1000，最小1
int findroot(int i){
	while(father[i]!=i)
		i=father[i];
	return i;
}
void join(int i,int j){
	int fi=findroot(i);
	int fj=findroot(j);
	if(fi!=fj)father[fi]=fj;
}
int main(){
	//freopen("d:\\input.txt","r",stdin);

	vector<int> root(1001);//记录该节点是否是代表，数字表示其代表的节点数

	int hobby[1001]={0};//爱好也用数字表示，1-1000,记录该爱好共有多少个人有
	int ki,hi,n;
	scanf("%d",&n);
	for(int i=0;i<1001;i++){father[i]=i;hobby[i]=0;}
	for(int i=1;i<=n;i++){
		scanf("%d:",&ki);
		for(int j=0;j<ki;j++){
			scanf("%d",&hi);
			if(hobby[hi]==0)hobby[hi]=i;
			else join(i,hobby[hi]);
		}
	}
	for(int i=1;i<=n;i++){
		root[findroot(i)]++;
	}
	int sum=0;
	for(int i=1;i<=n;i++)
		if(root[i]!=0)sum++;
	sort(root.begin()+1,root.begin()+n,comp);
	printf("%d\n",sum);
	if(sum==0)return 0;
	for(int i=1;i<=sum-1;i++)printf("%d ",root[i]);
	printf("%d",root[sum]);
    return 0;
}

//9月4日更：将所有的hobby先归类，这样相当于每个人只有唯一的一个hobby，然后记录各个hobby的人数即可
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
int fa[1001]={0},num[1001]={0};
int findroot(int x){
	return fa[x]==0?x:fa[x]=findroot(fa[x]);
}
void combine(int c1,int c2){
	int f1=findroot(c1),f2=findroot(c2);
	if(f1!=f2)
		fa[f2]=f1;
}
vector<vector<int> > grid(1001);
int main(){
	//freopen("D:\\input.txt","r",stdin);
	int N,K,t,c1,c2;
	cin>>N;
	_for(i,0,N){
		scanf("%d:",&K);
		cin>>t;
		grid[i].push_back(t);
		_for(j,1,K){
			cin>>t;
			grid[i].push_back(t);
			combine(grid[i][0],grid[i][j]);
		}
	}
	_for(i,0,N){
		num[findroot(grid[i][0])]++;
	}
	vector<int> ans;
	_for(i,0,1001){
		if(num[i]!=0)ans.push_back(num[i]);
	}
	cout<<ans.size()<<endl;
	sort(ans.begin(),ans.end(),greater<int>() );
	cout<<ans[0];
	_for(i,1,ans.size())printf(" %d",ans[i]);
	return 0;
}

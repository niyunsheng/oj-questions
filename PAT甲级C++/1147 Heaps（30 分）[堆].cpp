/**
 * @Date:   2018-08-28
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-28
 */
//一次AC。后续遍历迭代，注意到可以在遍历过程中判断是最大最小堆或者不是堆即可。
#include<iostream>
#include<vector>
using namespace std;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
void printvec(vector<int>& vec){
	printf("%d",vec[0]);
	_for(i,1,vec.size()){printf(" %d",vec[i]);}
	printf("\n");
}
#define lc(x) (2*x+1)
#define rc(x) (2*x+2)
int N;
int flag=0;//0表示未作判断，1表示最大堆，2表示最小堆，3表示不是堆
void postOrder(int cur,vector<int>& vec,vector<int>& postvec){
	if(cur>=N)return;
	//状态转换
	switch(flag){
	case 0:
		if(rc(cur)<N){
			if(vec[rc(cur)]<=vec[cur]&&vec[lc(cur)]<=vec[cur])flag=1;
			else if(vec[rc(cur)]>=vec[cur]&&vec[lc(cur)]>=vec[cur])flag=2;
			else flag=3;
		}else{
			if(vec[lc(cur)]<=vec[cur])flag=1;
			if(vec[lc(cur)]>=vec[cur])flag=2;
		}
		break;
	case 1:
		if(rc(cur)<N&&vec[rc(cur)]>vec[cur])flag=3;
		if(lc(cur)<N&&vec[lc(cur)]>vec[cur])flag=3;
		break;
	case 2:
		if(rc(cur)<N&&vec[rc(cur)]<vec[cur])flag=3;
		if(lc(cur)<N&&vec[lc(cur)]<vec[cur])flag=3;
		break;
	}

	postOrder(lc(cur),vec,postvec);
	postOrder(rc(cur),vec,postvec);
	postvec.push_back(vec[cur]);
}
int main(){
    //freopen("d:\\input.txt","r",stdin);
	int M;
	scanf("%d %d",&M,&N);
	vector<int> vec(N),postvec;

	_for(i,0,M){
		_for(j,0,N)scanf("%d",&vec[j]);
		postvec.clear();
		flag=0;
		postOrder(0,vec,postvec);
		switch(flag){
		case 1:printf("Max Heap\n");break;
		case 2:printf("Min Heap\n");break;
		case 3:printf("Not Heap\n");break;
		}
		printvec(postvec);
	}
    return 0;
}

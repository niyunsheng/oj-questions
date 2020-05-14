/**
 * @Date:   2018-08-28
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-28
 */
/*思路：
由于此题目所有的窗口大小均为1，所以仅需要用一个数组来表示各个窗口的结束服务时间即可，然后遍历合法顾客更新等待时间即可。
初始化使筛选掉来晚了的顾客
*/
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<algorithm>
#include<ctime>
#include<cassert>
#include<cctype>
using namespace std;

#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
struct node{
	int come,last;//到达时间，等待时间，持续时间，结束时间，均以秒记
	node(int c,int la):come(c),last(la){}
	bool operator<(node& b){
		return come<b.come;
	}
};
int main(){
	//freopen("d:\\input.txt","r",stdin);
	int N,K;
	scanf("%d %d",&N,&K);
	vector<node> guest;
	vector<vector<int> > myq(K,vector<int>(N,0)); //黄线以内的队列,为了记录历史队列信息，用数组模拟队
	vector<int> front(N,0),back(N,0);//记录各个队列的队首和队尾，[front,back)，队空是front==back,队中元素个数为back-front
	int hh,mm,ss,last;
	int daybegin=8*3600,dayend=17*3600;
	_for(i,0,N){
		scanf("%d:%d:%d %d",&hh,&mm,&ss,&last);
		int come=hh*3600+mm*60+ss;
		if(come>dayend)continue;
		guest.push_back(node(come,last*60));
	}
	sort(guest.begin(),guest.end());
	vector<int> window(K, daybegin);//表示每个窗口的结束时间
	int ans=0;//平均等待时间

	int id=0;//0号客户准备入队
	while(id<guest.size()){
		int minwin=0;//最早结束的窗口
		_for(i,1,K){
			if(window[i]<window[minwin])minwin=i;
		}
		//更新等待时间和窗口结束服务时间
		if(guest[id].come<window[minwin]){
			ans+=window[minwin]-guest[id].come;
			window[minwin]+=guest[id].last;
		}else
			window[minwin]=guest[id].come+guest[id].last;

		id++;
	}
	printf("%.1f\n",(float)ans/(60*guest.size()));
	return 0;
}

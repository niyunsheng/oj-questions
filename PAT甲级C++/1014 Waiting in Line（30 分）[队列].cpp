/*思路：
观察到每位顾客入队的时刻，就决定了其办理完业务的时间。
考虑到如果队列长度是1的话，入队的人找不到上一个人，所以，用数组表示队列来记录队中各个节点的时间
易错点：
Note that since the bank is closed everyday after 17:00, for those customers who cannot be served before 17:00, you must output Sorry instead.
这句话含义不清楚啊，导致三个算例没过，be servered原来指的是开始服务的时间，很容易当做是结束服务的时间，从而导致出错
其实用脑子想象也应该不是结束服务的时间，总不能服务一半吧
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

int main(){
	//freopen("d:\\input.txt","r",stdin);
	int N,M,K,Q;
	scanf("%d %d %d %d",&N,&M,&K,&Q);
	vector<int> process(K+1);//process[i]是id=i的顾客办理业务所花时间
	vector<int> time(K+1);//time[i]是id=i的顾客办理完业务的时间
	vector<bool> vis(K+1,false);//vis[i]表示id=i的顾客可以被服务
	_for(i,1,K+1)scanf("%d",&process[i]);
	vector<vector<int> > myq(N,vector<int>(1005,0)); //黄线以内的队列,为了记录历史队列信息，用数组模拟队
	vector<int> front(N,0),back(N,0);//记录各个队列的队首和队尾，[front,back)，队空是front==back,队中元素个数为back-front
	//初始化，所有黄线内队列入满
	int id=1;//1号客户准备入队
	while(back[0]-front[0]<M&&id<=K){
		_for(i,0,N){
			//printf("i=%d front=%d back=%d\n",i,front[i],back[i]);
			if(back[i]-front[i]<M&&id<=K){
				//一旦入队，办理业务的时间也就确定了
				int tmp=back[i]==0?0:time[myq[i][back[i]-1]];
				if(tmp<(17-8)*60)vis[id]=true;
				time[id]=tmp+process[id];
				//printf("time[%d]=%d\n",id,time[id]);
				myq[i][back[i]++]=id;
				//printf("i=%d id=%d\n",i,id);
				id++;
			}
		}
	}
	while(id<=K){//说明黄线外队列还有人，需要模拟出队
		//遍历队首，让最早办完的人出队
		int minque=0;
		_for(i,1,N){
			if(time[myq[i][front[i]]]<time[myq[minque][front[minque]]])minque=i;
		}
		front[minque]++;
		//printf("minque=%d\n",minque);
		int tmp=back[minque]==0?0:time[myq[minque][back[minque]-1]];
		if(tmp<(17-8)*60)vis[id]=true;
		time[id]=tmp+process[id];
		//printf("time[%d]=%d\n",id,time[id]);
		myq[minque][back[minque]++]=id;
		id++;
	}
	_for(i,0,Q){
		scanf("%d",&id);
		if(vis[id]){
			printf("%02d:%02d\n",time[id]/60+8,time[id]%60);
		}else printf("Sorry\n");
	}
	return 0;
}

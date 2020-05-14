/**
 * @Date:   2018-08-09
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-29
 */
/*
* 思路：关键在于贪心策略的选取
如果把终点也当做一个加油站处理，则代码可以简化很多
* 贪心策略详细描述，遍历在当前站点所能达到的所有站点，分两种情况讨论：
0.寻找比自己距离远的，到能够到达的最大距离之间的加油站，看他们的油价。如果找到了更低价格的油价，就加油到刚好能到达那个加油站的距离的油，然后去那个更低价格的加油站（有更低的我一分都不想多花在别的距离上，只加到刚好满足更低价格的加油站的距离就行，那样以后的路程我就可以以更低的价格行驶啦）
1.如果找不到更低的，就找尽可能低的油价的加油站，在当前加油站加满油之后过去。因为想要让路程上使用的尽可能是低价的油，既然没有比当前更低价格的了，就让油箱加到最大值，这样能保证利益最大化，保证最大的距离使用的是便宜的油。
from：[柳婼](https://www.liuchuo.net/archives/2461)
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct node{
	double dist,price;
	bool operator<(node& b){
		return dist<b.dist;
	}
};
int main(){
	//freopen("d:\\input.txt","r",stdin);
	int N;
	double Cmax,D,Davg;
	scanf("%lf %lf %lf %d",&Cmax,&D,&Davg,&N);
	vector<node> vec(N+1);//把目的地也看做加油站，方便处理
	for(int i=0;i<N;i++)
		scanf("%lf %lf",&vec[i].price,&vec[i].dist);
	vec[N].price=-1;vec[N].dist=D;
	sort(vec.begin(),vec.end());
	int curG=0;//当前加油站
	double curC=0;//当前油箱油量
	if(vec[0].dist!=0){printf("The maximum travel distance = 0.00");return 0;}
	double lowestP;
	int lowestG;//记录下一个区间的加油站最低价格和位置
	double sumprice=0;//记录全部花费

	while(vec[curG].dist<D){
		//遍历所能达到的所有加油站,找到价格更低的即停止
		int hi=curG+1;
		lowestP=100;//下一个区间的最低油价，这个题目没有给数据范围
		//遍历下一个区间
		while(hi<=N&&vec[hi].dist<=vec[curG].dist+Davg*Cmax&&vec[hi].dist<=D){
			if(vec[hi].dist==D){
				if(lowestP>=vec[curG].price)//直接到终点的情况
				{lowestP=0;lowestG=hi;}
			}else{
				//找区间内价格更低点
				if(vec[hi].price<vec[curG].price){
					lowestP=vec[hi].price;
					lowestG=hi;
					break;
				}else if(vec[hi].price<lowestP){
					lowestP=vec[hi].price;
					lowestG=hi;
				}
			}
			hi++;
		}
		if(lowestP==100){//说明下一个区间内没有节点
			printf("The maximum travel distance = %.2lf\n",vec[curG].dist+Davg*Cmax);
			return 0;
		}
		if(lowestP>=vec[curG].price){//加满油跑到下一个节点
			sumprice+=(Cmax-curC)*vec[curG].price;
			curC=Cmax-(vec[lowestG].dist-vec[curG].dist)/Davg;
			curG=lowestG;
			//printf("%d %lf %.2lf\n",curG,curC,sumprice);
		}else{//加油到能跑到下一个节点即可
			sumprice+=((vec[lowestG].dist-vec[curG].dist)/Davg-curC)*vec[curG].price;
			curC=0;
			curG=lowestG;
			//printf("%d %lf %.2lf\n",curG,curC,sumprice);
		}
	}
	printf("%.2lf\n",sumprice);
	return 0;
}

//第一版，没有把终点当做加油站，代码麻烦很多
struct node{
	float dist,price;
	bool operator<(node& b){
		return dist<b.dist;
	}
};
int main(){
	//freopen("d:\\codeBlockSpace\\input.txt","r",stdin);
	int N;
	float Cmax,D,Davg;
	scanf("%f %f %f %d",&Cmax,&D,&Davg,&N);
	vector<node> vec(N+1);//把目的地也看做加油站，方便处理
	for(int i=0;i<N;i++)
		scanf("%f %f",&vec[i].price,&vec[i].dist);
	vec[N].price=0;vec[N].dist=D;
	sort(vec.begin(),vec.end());
	int curG=0;
	float curD=0,curC=0;//当前加油站、当前距离和当前油箱油量
	if(vec[0].dist!=0){printf("The maximum travel distance = 0.00");return 0;}
	//
	float lowestP=100;
	int lowestG;//记录下一个区间的加油站最低价格和位置
	int i=1;//表示加油站的秩
	float sumprice=0;//记录全部花费
	while(curD<D){
		i=curG+1;
		lowestP=100;
		if(curG==N-1||vec[i].dist>=D){//在当前加油站加油到终点即可
			if(curD+Davg*Cmax>=D){//能跑到
				sumprice+=((D-curD)/Davg-curC)*vec[curG].price;
				printf("%.2f",sumprice);
				return 0;
			}else{//跑不到
				printf("The maximum travel distance = %.2f",curD+Davg*Cmax);
				return 0;
			}
		}
		if(vec[i].dist>curD+Davg*Cmax&&vec[i].dist<D){
			printf("The maximum travel distance = %.2f",curD+Davg*Cmax);
			return 0;
		}

		while(i<N&&vec[i].dist<=curD+Davg*Cmax&&vec[i].dist<=D){
			if(vec[i].price<vec[curG].price){lowestG=i;break;}//改正的策略只需要添加这么一句即可
			if(vec[i].price<lowestP){lowestP=vec[i].price;lowestG=i;}
			i++;
		}
		if(vec[curG].price>=vec[lowestG].price){
			if(curC*Davg+curD<vec[lowestG].dist){//将油量加到可以到下一个加油站就行了
				sumprice+=((vec[lowestG].dist-curD)/Davg-curC)*vec[curG].price;
				curC=(vec[lowestG].dist-curD)/Davg;
			}
			//过程中耗油，路途增加
			curC-=(vec[lowestG].dist-curD)/Davg;
			curD=vec[lowestG].dist;
			curG=lowestG;
		}else{
			//将油量加满，但是，要保证油量最多到达终点
			if(curD+Davg*Cmax>=D){
				sumprice+=((D-curD)/Davg-curC)*vec[curG].price;
				curC=(D-curD)/Davg;
			}else{
				sumprice+=(Cmax-curC)*vec[curG].price;
				curC=Cmax;
			}

			//过程中耗油，路途增加
			curC-=(vec[lowestG].dist-curD)/Davg;
			curD=vec[lowestG].dist;
			curG=lowestG;
		}
	}

	return 0;
}

/**
 * @Date:   2018-08-09
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-09
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;
//1047 编程团体赛（20 分）
//很简单
int main(){
	//freopen("D:\\codeBlockSpace\\input.txt","r",stdin);
	int n;
	scanf("%d",&n);
	vector<int> hashtable(1001,0);
	int team,tmp,score;
	int Tmax,Smax=0;
	for(int i=0;i<n;i++){
		scanf("%d-%d %d",&team,&tmp,&score);
		hashtable[team]+=score;
		if(hashtable[team]>Smax){
			Smax=hashtable[team];
			Tmax=team;
		}
	}
	printf("%d %d\n",Tmax,Smax);
	return 0;
}

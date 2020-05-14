/**
 * @Date:   2018-08-28
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-28
 */
/*
题目不难，模拟hash表平方试探法即可。但是坑的地方在于，怎么都看不出来2.8是怎么算出来的，后来还是看了其他人的答案，才发现，原来没有找到的话，试探的次数并不是记MSize，而是记为MSize+1
*/
#include<iostream>
#include<vector>
using namespace std;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
bool is_prime(int x){
	if(x<2)return false;
	if(x==2)return true;
	for(int i=2;i*i<=x;i++){
		if(x%i==0)return false;
	}
	return true;
}
int MSize;
int cnt=0;//查询总次数
vector<int> hashtable;
bool insert(int x){
	_for(i,0,MSize){//最多试探到(x+(MSize-1)^2)%MSize
		int r=(x+i*i)%MSize;
		if(hashtable[r]==-1){
			hashtable[r]=x;
			return true;
		}
	}
	return false;
}
//题意不清楚的地方，所有位置均冲突的数字，查找次数为MSize+1，而非MSize
void search(int x){
	_for(i,0,MSize+1){
		int r=(x+i*i)%MSize;
		cnt++;
		if(hashtable[r]==-1||hashtable[r]==x){
			break;
		}
	}
}
int main(){
    freopen("d:\\input.txt","r",stdin);
	int N,M,t;
    scanf("%d %d %d",&MSize,&N,&M);
	while(!is_prime(MSize))MSize++;
	hashtable.resize(MSize);
	fill(hashtable.begin(),hashtable.end(),-1);
	_for(i,0,N){
		scanf("%d",&t);
		if(!insert(t))printf("%d cannot be inserted.\n",t);
	}
	cnt=0;
	_for(i,0,M){
		scanf("%d",&t);
		search(t);
	}
	printf("%.1f\n",(float)cnt/M);
    return 0;
}

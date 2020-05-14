/**
 * @Date:   2018-09-01
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-01
 */
#include<iostream>
#include<string>
#include<cstring>
#include<set>
#include<map>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
int getint(){int x;scanf("%d",&x);return x;}
void printvec(vector<int>& vec){
	cout<<vec[0];
	_for(i,1,vec.size()){
		cout<<" "<<vec[i];
	}
	cout<<endl;
}
#define MAXN 10005
void init(vector<bool>& prime){
	for(int i=2;i*i<=MAXN;i++){
		if(prime[i]){
			int c=i*i;
			while(c<MAXN){
				prime[c]=false;
				c+=i;
			}
		}
	}
}

int main(){
    //freopen("d:\\input.txt","r",stdin);
	int N,id,r=1,K;
	vector<int> ranklist(MAXN),id2rank(MAXN,-1);
	vector<bool> prime(MAXN,true);
	init(prime);
	cin>>N;
	_for(i,0,N){
		cin>>id;
		ranklist[r]=id;
		id2rank[id]=r;
		r++;
	}
	cin>>K;
	set<int> ss;//去重
	_for(i,0,K){
		cin>>id;
		if(id2rank[id]==-1){
			printf("%04d: Are you kidding?\n",id);
		}else{
			if(ss.count(id)==0){
				ss.insert(id);
				if(id2rank[id]==1){
					printf("%04d: Mystery Award\n",id);
				}else if(prime[id2rank[id]]){
					printf("%04d: Minion\n",id);
				}else{
					printf("%04d: Chocolate\n",id);
				}
			}else{
				printf("%04d: Checked\n",id);
			}
		}
	}
	return 0;
}

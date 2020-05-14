/**
 * @Date:   2018-08-31
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-31
 */
#include<iostream>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)

//易错点：输出格式是5位数字，不足的前面补0。没有注意到这一点，基本上检查不出来，只有提前预警，把容易犯的错误总结下
int main(){
    //freopen("d:\\input.txt","r",stdin);
	int N,M,c1,c2;
	cin>>N;
	map<int,int> mmap;
	set<int> sset,ss;
	vector<int> ans;
	_for(i,0,N){
		cin>>c1>>c2;
		mmap[c1]=c2;
		mmap[c2]=c1;
	}
	cin>>M;
	_for(i,0,M){
		cin>>c1;
		if(ss.count(c1)!=0)continue;
		ss.insert(c1);
		if(mmap.count(c1)==0){
			sset.insert(c1);
		}else{
			if(sset.count(mmap[c1])==0)
				sset.insert(c1);
			else{
				sset.erase(mmap[c1]);
			}
		}
	}
	//注意输出格式是五位数字
	cout<<sset.size()<<endl;
	if(sset.size()==0)return 0;
	set<int>::iterator it=sset.begin();
	printf("%05d",*it);
	it++;
	while(it!=sset.end()){
		printf(" %05d",*it);
		it++;
	}
	cout<<endl;
	return 0;
}

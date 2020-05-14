/**
 * @Date:   2018-09-02
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-02
 */
#include<iostream>
#include<vector>
#include<cstring>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
void printvec(vector<int>& vec){
	printf("%d",vec[0]);
	_for(i,1,vec.size()){printf(" %d",vec[i]);}
	printf("\n");
}
struct node{
	int rank,tws,num;//名次，总分，学生人数
	double tmp_tws;
	string name;//学校名字
	node(){tmp_tws=0;num=0;}
	bool operator<(node& b){
		if(tws!=b.tws){
			return tws>b.tws;
		}else if(num!=b.num){
			return num<b.num;
		}else{
			return name<b.name;
		}
	}
};
map<string,node> mmap;
char strid[8];
int main(){
    //freopen("d:\\input.txt","r",stdin);
	int N;
	float score;
	string school;
	scanf("%d",&N);
	_for(i,0,N){
		scanf("%s %f",&strid,&score);
		cin>>school;
		_for(j,0,school.size())if(school[j]>='A'&&school[j]<='Z')school[j]=school[j]-'A'+'a';
		switch(strid[0]){
		case 'B':score/=1.5;break;
		case 'T':score*=1.5;break;
		}
		mmap[school].name=school;
		mmap[school].tmp_tws+=score;
		mmap[school].num++;
	}
	vector<node> vec(mmap.size());
	map<string,node>::iterator it=mmap.begin();
	_for(i,0,mmap.size()){
		vec[i]=it->second;
		vec[i].tws=(int)vec[i].tmp_tws;
		it++;
	}
	sort(vec.begin(),vec.end());
	int rank=1;
	vec[0].rank=1;
	_for(i,1,vec.size()){
		if(vec[i].tws==vec[i-1].tws)vec[i].rank=vec[i-1].rank;
		else vec[i].rank=i+1;
	}
	cout<<vec.size()<<endl;
	_for(i,0,vec.size()){
		cout<<vec[i].rank<<" "<<vec[i].name<<" "<<vec[i].tws<<" "<<vec[i].num<<endl;
	}
	return 0;
}

/**
 * @Date:   2018-08-08
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-27
 */
/*思路：
1. 两次排序，第一次按照车牌号排序，然后标记该项纪录是否有效，并且更新最长停留时间
2. 第二次排序按照时间排序，然后根据查询一次遍历O(n)即可
*/
#include<iostream>
#include<cstring>
#include<string>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
//1095 Cars on Campus (30)
//question：set<string>可以直接存放char数组
struct node{
	bool valied;
	char name[10],statue[4];
	string time;
	node():valied(false){}
};
bool cmpname(node& a,node& b){
	return strcmp(a.name,b.name)<0||(strcmp(a.name,b.name)==0&&a.time<b.time);
}
bool cmp(node& a,node& b){
	return a.time<b.time;
}
#define dd(a) (a-'0')
int countime(string& a,string& b){
	return (dd(b[0])*10+dd(b[1])-dd(a[0])*10-dd(a[1]))*3600+\
		   (dd(b[3])*10+dd(b[4])-dd(a[3])*10-dd(a[4]))*60+\
		   (dd(b[6])*10+dd(b[7])-dd(a[6])*10-dd(a[7]));
}
int main(){
	//freopen("D:\\input.txt","r",stdin);
	int N,K;
	scanf("%d %d",&N,&K);
	vector<node> lists(N);
	for(int i=0;i<N;i++){
		scanf("%s",lists[i].name);
		cin>>lists[i].time;
		scanf("%s",lists[i].statue);
	}
	//先标记各个节点的状态，即该记录是否有效
	sort(lists.begin(),lists.end(),cmpname);
	int lo=0,hi=1;
	int maxtime=0,tmptime=0;

	set<string> nameset;
	while(lo<N){
		tmptime=0;
		while(hi<N&&strcmp(lists[lo].name,lists[hi].name)==0)hi++;
		for(int i=lo;i<hi-1;i++){
			if(lists[i].statue[0]=='i'&&lists[i+1].statue[0]=='o'){
				lists[i].valied=true;lists[i+1].valied=true;
				//cout<<lists[i].time<<" "<<lists[i+1].time<<endl;
				tmptime+=countime(lists[i].time,lists[i+1].time);
				i++;
			}
		}
		if(tmptime>maxtime){
			maxtime=tmptime;
			nameset.clear();
			nameset.insert(lists[lo].name);
		}else if(tmptime==maxtime){
			nameset.insert(lists[lo].name);
		}
		lo=hi;hi=lo+1;
	}
	//查询车辆数
	sort(lists.begin(),lists.end(),cmp);
	int r=0;//记录车辆信息的位置
	int count=0;//学校内的车辆数
	string time;
	for(int i=0;i<K;i++){
		cin>>time;
		while(r<N&&lists[r].time<=time){
			if(lists[r].valied){
				if(lists[r].statue[0]=='i')count++;
				else count--;
			}
			r++;
		}
		printf("%d\n",count);
	}

	set<string>::iterator it=nameset.begin();
	cout<<(*it);
	//printf("%s",it->c_str);
	it++;
	while(it!=nameset.end()){
		cout<<" "<<*it;
		it++;
	}
	int ss=maxtime%60,mm=maxtime/60%60,hh=maxtime/3600;
	printf(" %02d:%02d:%02d\n",hh,mm,ss);

	return 0;
}

/*这种写法也是可以的
	set<string>nameset;
	char name[10];
	for(int i=0;i<5;i++){
		scanf("%s",name);
		nameset.insert(name);
	}
*/

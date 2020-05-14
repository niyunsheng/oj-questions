/**
 * @Date:   2018-08-08
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-27
 */
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//1016 Phone Bills (25)
/*思路：
第一点是确定排序规则，先根据字符串，这里需注意A65<a97，即大写字母均在小写字母之前
然后是双指针遍历同一个人的记录并根据要求输出，这里需要注意如何判断该条记录有效，即两条相邻记录分别是online和offline
本程序采用了记录有效数据的下标，读取的时候记录，然后统一输出，其实采用边读边输出的方式更好一些。
*/
struct node{
	string name,time,online;
	node(string nn,string tt,string oo):name(nn),time(tt),online(oo){}
	bool operator<(node& b){
		return name<b.name||(name==b.name&&time<b.time);
	}
};
int rate[24];
void countmoney(string& time1,string& time2,int& minute,int& money){
	int t1[4],t2[4];
	sscanf(time1.c_str(),"%d:%d:%d:%d",t1,t1+1,t1+2,t1+3);
	sscanf(time2.c_str(),"%d:%d:%d:%d",t2,t2+1,t2+2,t2+3);
	minute=0;//为了方便，避免繁琐计算，一个一个加
	money=0;
	while(t1[0]!=t2[0]||t1[1]!=t2[1]||t1[2]!=t2[2]||t1[3]!=t2[3]){
		t1[3]++;minute++;money+=rate[t1[2]];
		if(t1[3]==60){
			t1[3]=0;t1[2]++;
			if(t1[2]==24){
				t1[2]=0;t1[1]++;
			}
		}
	}
	return ;
}
int main(){
	//freopen("D:\\input.txt","r",stdin);

	for(int i=0;i<24;i++)scanf("%d",rate+i);
	int n;
	scanf("%d",&n);
	vector<node> bills;
	string name,time,online;
	int mm1,d1,h1,m1;
	for(int i=0;i<n;i++){
		cin>>name>>time>>online;
		bills.push_back(node(name,time,online));
	}
	sort(bills.begin(),bills.end());
	vector<node> ans;
	int lo=0,hi=0;//同一用户的账单范围[lo,hi)
	int count=0;//记录是否有通话记录
	int arrrecond[300];//记录该用户的通话记录的条目，假设最多30条
	int arrmoney[300];//该次通话的花费
	int arrtime[300];//该次通话的时间
	while(lo<bills.size()){
		count=0;
		hi=lo+1;
		while(hi<bills.size()&&bills[hi].name==bills[lo].name){
			if(bills[hi-1].online=="on-line"&&bills[hi].online=="off-line"){
				arrrecond[count]=hi-1;
				countmoney(bills[hi-1].time,bills[hi].time,arrtime[count],arrmoney[count]);
				count++;
			}
			hi++;
		}
		if(count==0)lo=hi;
		else{
			int summoney=0;
			cout<<bills[lo].name<<" "<<bills[lo].time.substr(0,2)<<endl;
			for(int i=0;i<count;i++){
				cout<<bills[arrrecond[i]].time.substr(3,11)<<" "<<bills[arrrecond[i]+1].time.substr(3,11)<<" "<<arrtime[i];
				printf(" $%.2f\n",(float)arrmoney[i]/100);
				summoney+=arrmoney[i];
			}
			printf("Total amount: $%.2f\n",(float)summoney/100);
			lo=hi;
		}
	}
	return 0;
}

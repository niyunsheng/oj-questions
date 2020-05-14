/**
 * @Date:   2018-08-23
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-23
 */
/*题目中后面这个条件容易忽略造成错误
购票时，一个人可能购一张或多张票，最多不超过5张。如果这几张票可以安排在同一排编号相邻的座位，则应该安排在编号最小的相邻座位。否则应该安排在编号最小的几个空座位中（不考虑是否相邻）。
*/
#include<iostream>
#include<sstream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<ctime>
#include<algorithm>
using namespace std;
void printvec(vector<int>& vec){
	printf("%d",vec[0]);
	for(int i=1;i<vec.size();i++){
		printf(" %d",vec[i]);
	}
	printf("\n");
}
//因为总共就20排，所以不需要二分法查找，直接记录每一排剩余座位数，然后从前向后遍历即可，满足条件即分配输出
int main() {
	//freopen("d:\\input.txt","r",stdin);
	int n,maxn=0;
	cin>>n;
	vector<int> vec(20,5);//初始时共20排，没拍剩余5个座位。
	for(int i=0;i<n;i++){
		int t,flag=0;
		cin>>t;
		for(int i=0;i<20;i++){
			if(t<=vec[i]){
				cout<<i*5+5-vec[i]+1;
				for(int j=1;j<t;j++)
					cout<<" "<<i*5+5-vec[i]+1+j;
				cout<<endl;
				vec[i]-=t;
				flag=1;
				break;
			}
		}
		if(flag==0){
			int i=0;
			while(vec[i]==0)i++;
			cout<<i*5+5-vec[i]+1;
			t--;vec[i]--;
			while(t>0){
				if(vec[i]>0){
					cout<<" "<<i*5+5-vec[i]+1;
					t--;vec[i]--;
				}else{
					i++;
				}
			}
			cout<<endl;
		}
	}
	return 0;
}

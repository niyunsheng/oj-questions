/**
 * @Date:   2018-08-25
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-25
 */
//CSP出日期增加判断的题目，都是用一天一天加，然后判断条件，这类题目简单，但是也不能掉以轻心。
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
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
int mon[2][13]={0,31,28,31,30,31,30,31,31,30,31,30,31,\
				0,31,29,31,30,31,30,31,31,30,31,30,31};
#define is_p(x) ((x%400==0||(x%100!=0&&x%4==0))?1:0)
struct today{
	int year,month,day,week;
	today(int y,int m,int d,int w):year(y),month(m),day(d),week(w){}
	void operator++(){
		day++;
		week++;
		if(week==8)week=1;
		int flag=is_p(year);
		if(day==mon[flag][month]+1){
			day=1;
			month++;
			//cout<<month<<" "<<day<<endl;
			if(month==13){
				month=1;year++;
			}
		}
	}
};
int main() {
	//freopen("D:\\input.txt","r",stdin);
	int a,b,c,y1,y2;
	cin>>a>>b>>c>>y1>>y2;
	today cur(1850,1,1,2);
	int flag=0;
	while(cur.year<=y2){
		++cur;
		if(cur.year>=y1&&cur.year<=y2&&cur.month==a&&((cur.day-1)/7+1==b)&&cur.week==c){
			printf("%4d/%02d/%02d\n",cur.year,cur.month,cur.day);
			flag=cur.year;
		}
		if(cur.year>=y1&&cur.year<=y2&&cur.month==12&&cur.day==31&&flag!=cur.year){
			printf("none\n");
		}
	}
	return 0;
}

/**
 * @Date:   2018-08-07
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-07
 */

 //重点在于理解题意，根据题意写大小判断函数
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int N,L,H;
struct stu{
	int id,d,c;
	stu(int ii,int dd,int cc):id(ii),d(dd),c(cc){}
	bool operator<(stu& b){
		if(d>=H&&c>=H){//甲属于第一类
			if(b.d>=H&&b.c>=H){
				return (d+c>b.c+b.d)||(d+c==b.c+b.d&&d>b.d)||(d+c==b.c+b.d&&d==b.d&&id<b.id);
			}
			return true;
		}
		if(c<H&&d>=H){//甲属于第二类
			if(b.d>=H&&b.c>=H)return false;
			if(b.c<H&&b.d>=H)return (d+c>b.c+b.d)||(d+c==b.c+b.d&&d>b.d)||(d+c==b.c+b.d&&d==b.d&&id<b.id);
			return true;
		}
		if(d>=c){//甲属于第三类
			if(b.d>=H&&b.c>=H)return false;
			if(b.c<H&&b.d>=H)return false;
			if(b.d>=b.c)return (d+c>b.c+b.d)||(d+c==b.c+b.d&&d>b.d)||(d+c==b.c+b.d&&d==b.d&&id<b.id);
			return true;
		}
		//甲属于第四类
		if(b.d>=H&&b.c>=H)return false;
		if(b.c<H&&b.d>=H)return false;
		if(b.d>=b.c)return false;
		return (d+c>b.c+b.d)||(d+c==b.c+b.d&&d>b.d)||(d+c==b.c+b.d&&d==b.d&&id<b.id);
	}
};
int main(){

	//freopen("D:\\codeBlockSpace\\input.txt","r",stdin);
	vector<stu> ans;
	scanf("%d %d %d",&N,&L,&H);
	int id,d,c;
	for(int i=0;i<N;i++){
		scanf("%d %d %d",&id,&d,&c);
		if(d>=L&&c>=L)
			ans.push_back(stu(id,d,c));
	}
	sort(ans.begin(),ans.end());
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)
		printf("%d %d %d\n",ans[i].id,ans[i].d,ans[i].c);
}

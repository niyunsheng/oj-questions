/**
 * @Date:   2018-08-15
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-15
 */
//题目：
/*思路：
*/
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<algorithm>
#include<ctime>
#include<cassert>
#include<cctype>
using namespace std;

#define MAX 100
#define inf 0x7fffffff
#define long long ll
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
int getchar(){int x;scanf("%d",&x);return x;}

void printvec(vector<int>& vec){
	printf("%d",vec[0]);
	_for(i,1,vec.size()){printf(" %d",vec[i]);}
	printf("\n");
}
char week[7][5]={"MON","TUE","WED","THU","FRI","SAT","SUN"};

int main(){
	//freopen("d:\\input.txt","r",stdin);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int flag=0,r1,r2;
	char r[2];

	_for(i,0,min(a.size(),b.size())){
		if(flag==1&&a[i]==b[i]){
			if(a[i]>='0'&&a[i]<='9'){
				r[flag++]=a[i]-'0'+'A';
				break;
			}

			if(a[i]>='A'&&a[i]<='N'){
				r[flag++]=a[i]+10;
				break;
			}
		}
		if(flag==0&&a[i]>='A'&&a[i]<='G'&&b[i]==a[i]){
			r[flag++]=a[i];
		}
	}
	_for(i,0,min(c.size(),d.size())){
		if(c[i]==d[i]&&isalpha(c[i])){
			r1=i;break;
		}
	}
	printf("%s %02d:%02d\n",week[r[0]-'A'],r[1]-'A',r1);
	return 0;
}

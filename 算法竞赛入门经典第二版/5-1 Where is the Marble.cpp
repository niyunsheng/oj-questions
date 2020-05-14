/**
 * @Date:   2018-08-20
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-06
 */
//思路：二分查找，用STL中的lower_bound则代码更加简洁
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
int getint(){int x;scanf("%d",&x);return x;}

int main(){
	//freopen("d:\\input.txt","r",stdin);
	int n,q,cnt=0,tmp;
	vector<int> vec;
	while(scanf("%d %d",&n,&q)!=EOF){
		if(n==0)break;
		cnt++;
		vec.clear();
		_for(i,0,n)vec.push_back(getint());
		sort(vec.begin(),vec.end());
		printf("CASE# %d:\n",cnt);
		_for(i,0,q){
			tmp=getint();
			int r=lower_bound(vec.begin(),vec.end(),tmp)-vec.begin();
			if(tmp==vec[r]){
				printf("%d found at %d\n",tmp,r+1);
			}else{
				printf("%d not found\n",tmp);
			}
		}
	}
	return 0;
}

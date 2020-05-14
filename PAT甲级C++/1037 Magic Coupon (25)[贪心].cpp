/**
 * @Date:   2018-08-09
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-09
 */
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//1037 Magic Coupon (25)
//贪心策略，排序，两边往中间找
//这个题目还是很容易想出来的，轻轻松松和晴神一样思路
int main(){
	//freopen("d:\\codeBlockSpace\\input.txt","r",stdin);
	int nc,np;
	scanf("%d",&nc);
	vector<int> coupon(nc);
	for(int i=0;i<nc;i++)scanf("%d",&coupon[i]);
	scanf("%d",&np);
	vector<int> product(np);
	for(int i=0;i<np;i++)scanf("%d",&product[i]);
	sort(coupon.begin(),coupon.end());
	sort(product.begin(),product.end());
	int loC=0,loP=0,hiC=nc-1,hiP=np-1;
	int sum=0;
	while(loC<nc&&coupon[loC]<0&&loP<np&&product[loP]<0){
		sum+=coupon[loC]*product[loP];
		loC++;loP++;
	}
	while(hiC>=0&&coupon[hiC]>0&&hiP>=0&&product[hiP]>0){
		sum+=coupon[hiC]*product[hiP];
		hiC--;hiP--;
	}
	printf("%d",sum);
	return 0;
}

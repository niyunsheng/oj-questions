/**
 * @Date:   2018-08-09
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-09
 */
 //刚开始第二个算例老是出错，但是，根据晴神书中所说，将能用double表示的都用了double，结果就正确了
#include<iostream>
#include<algorithm>
using namespace std;
//1070 Mooncake (25)	B1020 月饼 (25)
struct mooncake{
	double a,b;//分别表示库存和售价
	double mean;//平均售价
	bool operator<(mooncake& y){
		return mean>y.mean;
	}
};
int main(){
	//freopen("d:\\codeBlockSpace\\input.txt","r",stdin);
	int n;
	double m;
	mooncake cake[1001];
	scanf("%d %lf",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%lf",&cake[i].a);
	}
	for(int i=0;i<n;i++){
		scanf("%lf",&cake[i].b);
		cake[i].mean=cake[i].b/cake[i].a;
	}
	sort(cake,cake+n);
	double sum=0;
	for(int i=0;i<n;i++){
		if(cake[i].a<m){sum+=cake[i].b;m-=cake[i].a;}
		else{
			sum+=m*cake[i].mean;//
			break;
		}
	}
	printf("%.2lf",sum);
	return 0;
}

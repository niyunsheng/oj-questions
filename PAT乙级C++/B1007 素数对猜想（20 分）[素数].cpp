/**
 * @Date:   2018-08-10
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-10
 */
#include<iostream>
#include<algorithm>
using namespace std;
//1007 素数对猜想（20 分）
//简单，素数筛选法
#define NMAX 100000
int main(){
	//freopen("D:\\codeBlockSpace\\input.txt","r",stdin);
	//预处理
	bool prime[NMAX];//出错的原因在于没有初始化
	fill(prime,prime+NMAX,true);
	prime[0]=prime[1]=false;
	for(int i=2;i<NMAX;i++){
		if(prime[i]){
			for(int k=i*i;k<NMAX&&k>0;k+=i){//错误的原因是这里超int范围了
				prime[k]=false;
			}
		}
	}
	int n;
	//for(int i=0;i<1000;i++)if(prime[i])cout<<i<<endl;
	scanf("%d",&n);
	int count=0;
	for(int i=2;i+2<=n;i++){
		if(prime[i]&&prime[i+2])
			count++;
	}
	printf("%d\n",count);

	return 0;
}

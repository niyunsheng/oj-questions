/**
 * @Date:   2018-08-10
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-10
 */
//特别注意筛素数法中超范围的问题，把秩改为long long
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//1013 数素数 (20)
//简单，素数筛选法
#define NMAX 1000000
int main(){
	//freopen("D:\\codeBlockSpace\\input.txt","r",stdin);
	//预处理
	bool prime[NMAX];//出错的原因在于没有初始化
	fill(prime,prime+NMAX,true);
	prime[0]=prime[1]=false;
	for(long long i=2;i<NMAX;i++){
		if(prime[i]){
			for(long long k=i*i;k<NMAX&&k>0;k+=i){//错误的原因是这里超int范围了,换成long long就可以了
				prime[k]=false;
			}
		}
	}
	vector<int> vec;//保存质数
	for(int i=2;i<NMAX;i++)if(prime[i])vec.push_back(i);
	int m,n,count=0;
	scanf("%d %d",&m,&n);
	for(int i=m-1;i<n;i++){
		if(count==0){printf("%d",vec[i]);count++;}
		else if(count==9){printf(" %d\n",vec[i]);count=0;}
		else {printf(" %d",vec[i]);count++;}
	}

	return 0;
}

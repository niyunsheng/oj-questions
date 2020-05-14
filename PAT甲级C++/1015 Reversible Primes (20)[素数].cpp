/**
 * @Date:   2018-08-10
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-10
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//1015 Reversible Primes (20)
//还是筛素数法的基础上进行处理即可，另外，判断其有没有质因数也是判断是否素数的方法，更适用于本题
//一定要看清楚题目啊，题意理解错误，人家是说在d进制下颠倒看是不是素数
bool isPrime(int n){
	//这里边界条件写上，1可不是素数,
	//原来错误的出处是在这里，注意想筛选掉素数，可别把2也筛掉了后面i*i<=n;不要把等号忘记了
	if(n==2)return true;
	if(n%2==0||n<2)return false;
	for(long long i=3;i*i<=n;i+=2){
		if(n%i==0)return false;
	}
	return true;
}
//用栈一步到位完成转换:decimal->D>reverse->decimal
int revD(int n,int d){
	vector<int> tmp;
	while(n>0){
		tmp.push_back(n%d);
		n/=d;
	}
	int ans=0;
	for(int i=0;i<tmp.size();i++)ans=ans*d+tmp[i];
	return ans;
}
int main(){
	//freopen("D:\\codeBlockSpace\\input.txt","r",stdin);
	int d,n;
	while(1){
		scanf("%d",&n);
		if(n<0)break;
		scanf("%d",&d);
		//其实不需要先将10进制转化为d进制，然后再reverse，再转化为10进制，可以用栈一步到位
		//一步转换的好处还在于不会越界，比如10进制转化为2进制后用int显示的话很可能越界
		int m=revD(n,d);
		if(isPrime(m)&&isPrime(n))
			printf("Yes\n");
		else printf("No\n");
	}


	return 0;
}

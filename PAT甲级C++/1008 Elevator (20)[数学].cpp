/**
 * @Date:   2018-08-10
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-29
 */
#include<iostream>
#include<vector>
using namespace std;
//1008 Elevator (20)
//思路：这个题目就是模拟运算，一次通过，是少见的没有坑，没有边缘条件，没有越界的题目了
//注意：当下一个目的地和该层相同时，虽然不用花时间上下楼，但是仍然需要花时间停留
int main(){
	//freopen("d:\\input.txt","r",stdin);
	int n;
	scanf("%d",&n);
	vector<int> vec(n);
	for(int i=0;i<n;i++)
		scanf("%d",&vec[i]);
	int sum=vec[0]*6+5;
	for(int i=1;i<n;i++){
		if(vec[i]>vec[i-1])
			sum+=(vec[i]-vec[i-1])*6+5;
		else
			sum+=(vec[i-1]-vec[i])*4+5;
	}
	printf("%d",sum);
	return 0;
}

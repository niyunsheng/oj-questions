/**
 * @Date:   2018-08-09
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-09
 */
#include<iostream>
#include<string>
#include<vector>
using namespace std;
//B1038 统计同成绩学生(20)

int main(){
	//freopen("D:\\codeBlockSpace\\input.txt","r",stdin);
	int n,k,score;
	scanf("%d",&n);
	vector<int> hashtable(101,0);
	for(int i=0;i<n;i++){
		scanf("%d",&score);
		hashtable[score]++;
	}
	scanf("%d",&k);
	scanf("%d",&score);
	printf("%d",hashtable[score]);
	for(int i=1;i<k;i++){
		scanf("%d",&score);
		printf(" %d",hashtable[score]);
	}
	return 0;
}

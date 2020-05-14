/**
 * @Date:   2018-08-10
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-29
 */
//1101 Quick Sort（25 分）
//思路：统计位置i前面最大的数和i后面最小的数，然后一次遍历与i相比即可
//pre[i]表示i位置前面最大的数，初始化pre[0]=-1;递推公式：pre[i]=max(pre[i-1],num[i-1])
//post[i]表示i位置后面最小的数，初始化post[n-1]=0x7fffffff;递推公式：post[i]=min(post[i+1],num[i+1])
//出现段错误的原因绝对是向量个数为0，却访问了ans[0]
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	//freopen("d:\\codeBlockSpace\\input.txt","r",stdin);
	int n;
	scanf("%d",&n);
	vector<int> num(n),pre(n),post(n);
	for(int i=0;i<n;i++)
		scanf("%d",&num[i]);

	pre[0]=-1;
	for(int i=1;i<n;i++)
		pre[i]=max(pre[i-1],num[i-1]);
	post[n-1]=0x7fffffff;
	for(int i=n-2;i>=0;i--)
		post[i]=min(post[i+1],num[i+1]);
	vector<int> ans;//统计主元
	for(int i=0;i<n;i++)
		if(num[i]>pre[i]&&num[i]<post[i])
			ans.push_back(num[i]);
	printf("%d\n",ans.size());
	//真粗心啊，这里是ans.size(),而不是n
	if(ans.size()==0){printf("\n");return 0;}
	printf("%d",ans[0]);
	for(int i=1;i<ans.size();i++)
		printf(" %d",ans[i]);
	printf("\n");
	return 0;
}

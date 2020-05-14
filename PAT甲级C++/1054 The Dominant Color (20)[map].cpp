/**
 * @Date:   2018-08-11
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-11
 */
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
//1054 The Dominant Color (20)
//思路：直接map统计各个数字出现的次数即可
int main(){
	//freopen("D:\\codeBlockSpace\\input.txt","r",stdin);
	int m,n,t,maxNum=0,maxId;
	map<int,int> mmap;
	scanf("%d %d",&m,&n);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			scanf("%d",&t);
			if(mmap.count(t)==0)mmap[t]=1;
			else mmap[t]++;
			if(mmap[t]>maxNum){maxNum=mmap[t];maxId=t;}
		}
	printf("%d\n",maxId);
	return 0;
}

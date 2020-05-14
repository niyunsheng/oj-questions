/**
 * @Date:   2018-08-30
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-30
 */
//小河沟里翻船，这种错误是很难检查出来啊，自己测试的数据量太小，输入的都是个位数，而自己输入的只用了个位数，真是醉人啊！
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
int main() {
	//freopen("d:\\input.txt","r",stdin);
	int n;
    cin>>n;
	vector<int> p(n,-1),lc(n,-1),rc(n,-1);//父节点、左右孩子,不存在取-1
	char c1[5],c2[5];
	int flag=0;
	int t1,t2;
	_for(i,0,n){
		//注意输入的结点不一定是个位数，切记
		scanf("%s %s",&c1,&c2);
		if(c1[0]!='-'){
			sscanf(c1,"%d",&t1);
			p[t1]=i;lc[i]=t1;
		}
		if(c2[0]!='-'){
			sscanf(c2,"%d",&t2);
			p[t2]=i;rc[i]=t2;
		}
	}
	int root;
	_for(i,0,n)if(p[i]==-1){root=i;break;}//假设题目给的条件总是一棵树
	queue<int> q;
	q.push(root);
	int cur;//cur始终是队列中最后一个节点
	flag=0;//当前节点无孩子时标记为1,如果后面节点还有孩子，那就不是完全二叉树
	while(!q.empty()){
		cur=q.front();
		q.pop();
		if(lc[cur]==-1)flag=1;
		else{
			if(flag==1){
				printf("NO %d\n",root);
				return 0;
			}
			q.push(lc[cur]);
		}
		if(rc[cur]==-1)flag=1;
		else{
			if(flag==1){
				printf("NO %d\n",root);
				return 0;
			}
			q.push(rc[cur]);
		}
	}
	printf("YES %d\n",cur);
	return 0;
}

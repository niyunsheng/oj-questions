/**
 * @Date:   2018-08-29
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-29
 */
//时间主要消耗在中序数组查找上，本来想着如果超时就加一个hash表列出数组各个元素的位置，但直接就AC了
#include<iostream>
#include<vector>
using namespace std;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
//策略：一直向左，左子树没有再向右
int findtar(vector<int>& postOrder,int postlo,int posthi,vector<int>& inOrder,int inlo,int inhi){
	int t=postOrder[postlo];
	if(posthi-postlo==1)return t;
	int r=inlo;
	while(inOrder[r]!=t)r++;
	if(r>inlo)return findtar(postOrder,postlo+1,postlo+1+r-inlo,inOrder,inlo,r);
	else return findtar(postOrder,posthi-inhi+r+1,posthi,inOrder,r+1,inhi);
}
int main(){
	//freopen("d:\\input.txt","r",stdin);
	int n;
	cin>>n;
	vector<int> postOrder(n),inOrder(n);
	_for(i,0,n)scanf("%d",&postOrder[i]);
	_for(i,0,n)scanf("%d",&inOrder[i]);
	int ans=findtar(postOrder,0,n,inOrder,0,n);
	cout<<ans<<endl;
	return 0;
}

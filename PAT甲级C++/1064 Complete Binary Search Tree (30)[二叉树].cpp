/**
 * @Date:   2018-08-12
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-13
 */
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
using namespace std;
//1064 Complete Binary Search Tree (30)
/*思路：
	将数组排序即为中序遍历，然后如何转化为完全二叉树数组呢？将完全二叉树数组直接输出就是层次遍历
	本题其实就是中序遍历+完全二叉树，让你求树的结构，并输出层次遍历

柳神思路：加载cmath函数，利用完全二叉树的子树也是完全二叉树，不断的在区间内找根节点。
		  根节点的层数设为0，则每一层满的话元素数目为2^h，层高为h的完全二叉树的元素总数为2^h-1<n<=2^(h+1)-1
		  即2^h<=n<h^(h+1)，则h<=log2(n)<h+1，利用强制类型转换int即可得到h的值
		  然后用完全二叉树的性质，借用pow函数，来计算区间内的根节点的坐标
9月4日更：其实直接对CBT的节点编号进行中序遍历，可以得到节点编号的中序遍历，这些节点编号和输入的数据时一一对应的，这个方法更简单。柳神的方法虽然容易理解，但是计算量较大
	*/

#define _for(i,a,b) for(int i=(a);i<(b);i++)
int getint(){
	int x;scanf("%d",&x);return x;
}
#define lc(i) (2*i+1)
#define rc(i) (2*i+2)
#define fa(i) ((i-1)/2)
vector<int> inorder;
vector<int> BST;
int size_N;//输入元素的个数
void levelTral(int lo,int hi,int index){//求区间[lo,hi)内的完全二叉树的跟坐标
	if(lo>=hi)return;
	int n=hi-lo;
	int h=log(n)/log(2);
	int root=lo+min(n-(pow(2,h)-1),pow(2,h-1))+pow(2,h-1)-1;
	BST[index]=inorder[root];
	if(lc(index)<size_N)levelTral(lo,root,lc(index));
	if(rc(index)<size_N)levelTral(root+1,hi,rc(index));
}
void printvec(vector<int>& vec){
	printf("%d",vec[0]);
	_for(i,1,vec.size()){
		printf(" %d",vec[i]);
	}
	printf("\n");
}
int main(){
	//freopen("D:\\codeBlockSpace\\input.txt","r",stdin);
	scanf("%d",&size_N);
	inorder.resize(size_N);//存放原始输入，即中序遍历
	BST.resize(size_N);//存放层次遍历的结果
	_for(i,0,size_N){
		inorder[i]=getint();
	}
	sort(inorder.begin(),inorder.end());
	//printvec(inorder);
	levelTral(0,size_N,0);
	printvec(BST);
	return 0;
}
//更新递归方法：
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
void printvec(vector<int>& vec){
	printf("%d",vec[0]);
	_for(i,1,vec.size()){printf(" %d",vec[i]);}
	printf("\n");
}
int getint(){int x;scanf("%d",&x);return x;}
int M,N;
#define lc(x) (2*x+1)
#define rc(x) (2*x+2)
vector<int> inorder;
void DFS(int cur){
	if(lc(cur)<N)DFS(lc(cur));
	inorder.push_back(cur);
	if(rc(cur)<N)DFS(rc(cur));
}

int main(){
	//freopen("D:\\input.txt","r",stdin);

	cin>>N;
	vector<int> data(N),ans(N);

	_for(i,0,N){
		cin>>data[i];
	}
	sort(data.begin(),data.end());
	DFS(0);
	_for(i,0,N){
		ans[inorder[i]]=data[i];
	}
	printvec(ans);
	return 0;
}

/**
 * @Date:   2018-08-13
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-13
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//1098 Insertion or Heap Sort (25)
/*思路：
	模拟插入排序和堆排序，到了目标序列后输出下一个序列即可。
本题需要注意：
	建堆默认都是自下而上建堆，包括priority_queue也是
	自上而下建堆和自下而上建堆的结果是不一样的，很容易试出来
要清楚建堆的方法，从n/2位置开始建堆即可，先建堆，然后将第一个元素与最后一个元素交换，即实现了将堆中最大元素加入已排序队列的要求，然后对第一个元素下滤即可
	*/

int min(int x,int y){return x>y?y:x;}
#define _for(i,a,b) for(int i=(a);i<(b);i++)
int getint(){int x;scanf("%d",&x);return x;}
void printvec(vector<int>& vec){
	printf("%d",vec[0]);
	_for(i,1,vec.size()){
		printf(" %d",vec[i]);
	}
	printf("\n");
}
bool isEqual(vector<int>& vec1,vector<int>& vec2){
	_for(i,0,vec1.size()){
		if(vec1[i]!=vec2[i])
			return false;
	}
	return true;
}
#define lc(i) (2*i+1)
#define rc(i) (2*i+2)

//堆排序向下调整，调整的元素为lo，调整的区间是[lo,hi)
void downAdjust(vector<int>& vec,int lo,int hi){
	int son=lc(lo);
	if(rc(lo)<hi){//左右孩子均存在
		if(vec[lc(lo)]<vec[rc(lo)])son=rc(lo);
		if(vec[lo]<vec[son]){
			swap(vec[lo],vec[son]);
			downAdjust(vec,son,hi);
		}
	}else if(lc(lo)<hi){//左孩子存在
		if(vec[lo]<vec[son]){
			swap(vec[lo],vec[son]);
			downAdjust(vec,son,hi);
		}
	}
}
int main(){
	//freopen("D:\\codeBlockSpace\\input.txt","r",stdin);
	int n=getint();
	vector<int> indata(n),target(n),tmp(n);

	_for(i,0,n){
		indata[i]=getint();
	}
	_for(i,0,n){
		target[i]=getint();
	}
	bool flag=false;//上一轮是否相等
	tmp=indata;
	//模拟插入排序,这里如果要剪枝的话，只能判断已排序原始在target数组中是否是有序了，数据量不大的话，不用剪枝
	_for(i,1,n){
		int r=i-1,t=tmp[i];
		while(r>=0&&tmp[r]>tmp[i])r--;

		for(int j=i;j>r+1;j--){
			tmp[j]=tmp[j-1];
		}
		tmp[r+1]=t;

		if(flag){
			printf("Insertion Sort\n");
			printvec(tmp);
			return 0;

		}else{
			if(isEqual(tmp,target))
				flag=true;
		}
	}
	//模拟堆排序,先将原始数列存入优先级队列，然后不断取出首元素放到最后
	tmp=indata;
	//建堆，从下向上对每个元素进行向下调整(弗洛伊德建堆，默认的建堆方式)
	for(int i=n/2-1;i>=0;i--){
		downAdjust(tmp,i,n);
	}
	//堆排序
	_for(i,0,n){
		swap(tmp[0],tmp[n-1-i]);
		downAdjust(tmp,0,n-1-i);
		if(flag){
			printvec(tmp);
			return 0;
		}else{
			if(isEqual(tmp,target)){
				printf("Heap Sort\n");
				flag=true;
			}
		}
	}
	return 0;
}

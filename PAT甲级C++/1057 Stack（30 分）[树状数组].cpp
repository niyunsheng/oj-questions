//用排序或者Kth_element均超时，树状数组模板全部通过
#include<iostream>
#include<stack>
using namespace std;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)

const int MAXN=100005;
int A[MAXN],C[MAXN];
#define lowbit(i) (i&(-i))

//A[x]加上v
void updata(int x,int v){
	if(v==0)return;
	for(int i=x;i<MAXN;i+=lowbit(i)){
		C[i]+=v;
	}
}

//计算A[1]-A[x]的和
int getsum(int x){
	int sum=0;
	for(int i=x;i>0;i-=lowbit(i)){
		sum+=C[i];
	}
	return sum;
}
stack<int> s;
int getmid(){
	int k=(s.size()+1)/2;
	//求getsum(i)>=k的最小值
	int lo=1,hi=MAXN;
	while(lo<hi){//[lo,hi)
		int mid=(lo+hi)/2;
		if(getsum(mid)>=k){
			hi=mid;
		}else{
			lo=mid+1;
		}
	}
	return lo;
}
int main(){
    //freopen("d:\\input.txt","r",stdin);
	int N,t;

	cin>>N;
	char op[15];
	int top=0;
	_for(i,0,N){
		scanf("%s",op);
		switch(op[1]){
		case 'u':
			scanf("%d",&t);
			//A[t]++;
			updata(t,1);
			s.push(t);
			top++;
			break;
		case 'o':
			if(s.empty())printf("Invalid\n");
			else {
				t=s.top();
				//A[t]--;
				updata(t,-1);
				s.pop();
				printf("%d\n",t);
			}
			break;
		case 'e':
			if(s.empty())printf("Invalid\n");
			else{
				t=getmid();
				printf("%d\n",t);
			}
			break;
		}
	}
	return 0;
}




//Kth方法超时一半算例
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)

const int MAXN=100005;
int s[MAXN],tmp[MAXN];
int partition(int* tmp,int lo,int hi){
	//返回排序好元素的秩
	swap(tmp[lo],tmp[lo+rand()%(hi-lo)]);
	int t=tmp[lo];
	int i=lo,j=hi-1;
	while(i<j){
		while(i<j&&tmp[j]>=t)j--;
		tmp[i]=tmp[j];
		while(i<j&&tmp[i]<=t)i++;
		tmp[j]=tmp[i];
	}
	tmp[i]=t;
	return i;
}
int theKth(int* tmp,int lo,int hi,int K){//第K小元素
	if(hi-1==lo)return tmp[lo];
	int r=partition(tmp,lo,hi);
	if(r-lo+1==K)return tmp[r];
	if(r-lo+1<K)return theKth(tmp,r+1,hi,K-(r-lo+1));
	else return theKth(tmp,lo,r,K);
}
int main(){
    //freopen("d:\\input.txt","r",stdin);
	int N,t;
	cin>>N;
	char op[15];
	int top=0;
	_for(i,0,N){
		scanf("%s",op);
		switch(op[1]){
		case 'u':
			scanf("%d",&t);
			tmp[top]=s[top]=t;
			top++;
			break;
		case 'o':
			if(top==0)printf("Invalid\n");
			else printf("%d\n",s[--top]);
			break;
		case 'e':
			if(top==0)printf("Invalid\n");
			else{
				//第K大元素，就用partition算法O(logn)
				memcpy(tmp,s,top*sizeof(int));
				int t=theKth(tmp,0,top,(top+1)/2);
				//sort(tmp,tmp+top);
				printf("%d\n",t);
			}
			break;
		}
	}
	return 0;
}

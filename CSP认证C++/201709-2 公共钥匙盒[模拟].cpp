/**
 * @Date:   2018-08-23
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-23
 */
//CCF第二题基本都是模拟，但是近年来判断的条件越来越繁琐，不留神判断条件粗心的童靴很容易做错了，所以，如何自定义测试例子是CCF前四题保分的基础啊！
#include<iostream>
#include<sstream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<ctime>
#include<algorithm>
using namespace std;
struct node{
	int id,t1,t2,statue;//statue=0表示是借钥匙，1表示还钥匙
	friend bool operator<(const node& a,const node& b){
		if(a.t1!=b.t1){
			return a.t1>b.t1;
		}else if(a.statue!=b.statue){
			return a.statue<b.statue;
		}else{
			return a.id>b.id;
		}
	}
	node(){};
	node(int a,int b,int c,int d=0):id(a),t1(b),t2(c),statue(d){}
};
int main() {
	//freopen("d:\\input.txt","r",stdin);
	int n,k,a,b,c;
	cin>>n>>k;
	vector<int> key(n+1),hata(n+1);//hata[i]=j表示钥匙i放在j位置
	for(int i=0;i<n+1;i++){key[i]=i;hata[i]=i;}//保存钥匙的序列，-1表示为空


	priority_queue<node> pq;
	//srand(time(NULL));n=(rand()%30+1)*10;cout<<n<<endl;
	for(int i=0;i<k;i++){
		cin>>a>>b>>c;
		pq.push(node(a,b,c));
	}
	node tmp;
	while(!pq.empty()){
		tmp=pq.top();
		pq.pop();
		if(tmp.statue==0){
			key[hata[tmp.id]]=-1;
			tmp.t1+=tmp.t2;
			tmp.statue=1;
			pq.push(tmp);
		}else{
			for(int i=1;i<n+1;i++){
				if(key[i]==-1){
					key[i]=tmp.id;
					hata[tmp.id]=i;
					break;
				}
			}
		}
	//	cout<<key[1];	for(int i=2;i<n+1;i++)cout<<" "<<key[i];	cout<<endl;
	}
	cout<<key[1];
	for(int i=2;i<n+1;i++)cout<<" "<<key[i];
	cout<<endl;
	return 0;
}

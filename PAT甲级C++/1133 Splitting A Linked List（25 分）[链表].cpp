/**
 * @Date:   2018-09-02
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-02
 */
//笔者思路：重定义排序，但是有一个算例没过
//柳神思路，三次遍历，每次讲区间内的点加入答案
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
int getint() {int x;scanf("%d",&x);return x;}
#define MAX 505
struct node{
	int addr,data,rank;//rank表示原始队列中的序号
	node(int a,int d,int r):addr(a),data(d),rank(r){}
};
int head,N,K;
bool cmp(node& a,node& b){
	if((a.data<0&&b.data<0)||(a.data>=0&&a.data<=K&&b.data>=0&&b.data<=K)||(a.data>K&&b.data>K)){
		return a.rank<b.rank;
	}else{
		return a.data<b.data;
	}
}
int main(){
    //freopen("d:\\input.txt","r",stdin);
	cin>>head>>N>>K;
	int addr,data,next;
	vector<node> vec;
	map<int,int> m_id,m_data;//id->nextid,id->data
	_for(i,0,N){
		scanf("%d %d %d",&addr,&data,&next);
		m_id[addr]=next;
		m_data[addr]=data;
	}
	int top=0;
	while(head!=-1){
		vec.push_back(node(head,m_data[head],top));
		top++;
		head=m_id[head];
	}
	sort(vec.begin(),vec.end(),cmp);
	_for(i,0,N-1){
		printf("%05d %d %05d\n",vec[i].addr,vec[i].data,vec[i+1].addr);
	}
	printf("%05d %d -1\n",vec[N-1].addr,vec[N-1].data);
    return 0;
}

//三次遍历，将区间内节点入队
#include <iostream>
#include <vector>
using namespace std;
struct node {
    int id, data, next;
};
int main() {
    int begin, n, k, s, d, e;
    scanf("%d%d%d", &begin, &n, &k);
    node a[100010];
    vector<node> v, ans;
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &s, &d, &e);
        a[s] = {s, d, e};
    }
    for (; begin != -1; begin = a[begin].next)
        v.push_back(a[begin]);
    for (int i = 0; i < v.size(); i++)
        if (v[i].data < 0) ans.push_back(v[i]);
    for (int i = 0; i < v.size(); i++)
        if (v[i].data >= 0 && v[i].data <= k) ans.push_back(v[i]);
    for (int i = 0; i < v.size(); i++)
        if (v[i].data > k) ans.push_back(v[i]);
    for (int i = 0; i < ans.size() - 1; i++)
        printf("%05d %d %05d\n", ans[i].id, ans[i].data, ans[i + 1].id);
    printf("%05d %d -1\n", ans[ans.size() - 1].id, ans[ans.size() - 1].data);
    return 0;
}

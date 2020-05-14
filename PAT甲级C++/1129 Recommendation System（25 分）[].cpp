/**
 * @Date:   2018-08-31
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-01
 */
//自己用priority_queue,但一个算例没过
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
//是频率增加的部分出错了，只有上滤下滤的时候即重新插入的时候才会考虑排序，而改变了的频率并没有影响在原序列中的顺序，需要每次队首元素出队再入队即可
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
#define MAXN 500005
int freq[MAXN],N,K;
struct cmp{
	bool operator()(int a,int b){
		if(freq[a]!=freq[b]){
			return freq[a]<freq[b];
		}else{
			return a>b;
		}
	}
};
int main(){
    //freopen("d:\\input.txt","r",stdin);
	memset(freq,0,sizeof(freq));
	priority_queue<int,vector<int>,cmp> q;
	cin>>N>>K;
	int t;
	cin>>t;freq[t]++;
	q.push(t);
	vector<int> tmp;
	_for(i,1,N){
		scanf("%d",&t);
		printf("%d:",t);
		tmp.clear();

		for(int j=0;j<K&&!q.empty();j++){
			int r=q.top();q.pop();q.push(r);//原以为加上这一句就能过了，但是还是没过，问题依然悬着，不过，每次出队入队，不如直接用柳神那个set了，只用把频率改变的出来进去即可
			tmp.push_back(q.top());
			printf(" %d",q.top());
			q.pop();
		}
		printf("\n");

		if(freq[t]==0){tmp.push_back(t);}
		freq[t]++;
		_for(j,0,tmp.size())
			q.push(tmp[j]);
	}
	return 0;
}

//柳神set方法
#include <iostream>
#include <set>
using namespace std;
int book[50001];
struct node {
    int value, cnt;
    bool operator < (const node &a) const {
        return (cnt != a.cnt) ? cnt > a.cnt : value < a.value;
    }
};
int main() {
    int n, k, num;
    scanf("%d%d", &n, &k);
    set<node> s;
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        if (i != 0) {
            printf("%d:", num);
            int tempCnt = 0;
            for(auto it = s.begin(); tempCnt < k && it != s.end(); it++) {
                printf(" %d", it->value);
                tempCnt++;
            }
            printf("\n");
        }
        auto it = s.find(node{num, book[num]});
        if (it != s.end()) s.erase(it);
        book[num]++;
        s.insert(node{num, book[num]});
    }
    return 0;
}

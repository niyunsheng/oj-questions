/**
 * @Date:   2018-09-01
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-01
 */
//还是咩看出来问题所在，后面两个算例没过
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)

const int MAXN=10000;
vector<int> gender(MAXN,-1);//各个编号的性别，-1表示不存在，0表示男，1表示女
vector<vector<int> > grid(MAXN);

int main(){
	//freopen("d:\\input.txt","r",stdin);
	int N,M,K;
	cin>>N>>M;
	char str1[6],str2[6];
	int c1,c2;

	int id1,id2;
	_for(i,0,M){
		scanf("%s %s",str1,str2);
		sscanf(str1,"%d",&c1);
		sscanf(str2,"%d",&c2);
		if(str1[0]=='-'){c1=-c1;gender[c1]=1;}
		else gender[c1]=0;
		if(str2[0]=='-'){c2=-c2;gender[c2]=1;}
		else gender[c2]=0;

		grid[c1].push_back(c2);
		grid[c2].push_back(c1);
	}
	_for(i,0,MAXN){
		if(gender[i]!=-1)
			sort(grid[i].begin(),grid[i].end());
	}
	cin>>K;
	vector<int> ans;
	_for(i,0,K){
		scanf("%d %d",&c1,&c2);
		c1=abs(c1);c2=abs(c2);
		if(gender[c1]==-1||gender[c2]==-1){printf("0\n");continue;}
		ans.clear();
		_for(j,0,grid[c1].size()){
			int next1=grid[c1][j];
			if(next1!=c2&&gender[c1]==gender[next1]){
				_for(k,0,grid[next1].size()){
					int next2=grid[next1][k];
					if(next2!=c2&&gender[c2]==gender[next2]){
						_for(p,0,grid[next2].size()){
							if(grid[next2][p]==c2){
								ans.push_back(next1);
								ans.push_back(next2);
								break;
							}
						}
					}
				}
			}
		}
		printf("%d\n",ans.size()/2);
		_for(j,0,ans.size()/2){
			printf("%04d %04d\n",ans[2*j],ans[2*j+1]);
		}
	}
	return 0;
}
//柳神方法
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
unordered_map<int, bool> arr;
struct node {
    int a, b;
};
bool cmp(node x, node y) {
    return x.a != y.a ? x.a < y.a : x.b < y.b;
}
int main() {
    int n, m, k;
    scanf("%d%d", &n, &m);
    vector<int> v[10000];
    for (int i = 0; i < m; i++) {
        string a, b;
        cin >> a >> b;
        if (a.length() == b.length()) {
            v[abs(stoi(a))].push_back(abs(stoi(b)));
            v[abs(stoi(b))].push_back(abs(stoi(a)));
        }
        arr[abs(stoi(a)) * 10000 + abs(stoi(b))] = arr[abs(stoi(b)) * 10000 + abs(stoi(a))] = true;
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        int c, d;
        cin >> c >> d;
        vector<node> ans;
        for (int j = 0; j < v[abs(c)].size(); j++) {
            for (int k = 0; k < v[abs(d)].size(); k++) {
                if (v[abs(c)][j] == abs(d) || abs(c) == v[abs(d)][k]) continue;
                if (arr[v[abs(c)][j] * 10000 + v[abs(d)][k]] == true)
                    ans.push_back(node{v[abs(c)][j], v[abs(d)][k]});
            }
        }
        sort(ans.begin(), ans.end(), cmp);
        printf("%d\n", int(ans.size()));
        for(int j = 0; j < ans.size(); j++)
            printf("%04d %04d\n", ans[j].a, ans[j].b);
    }
    return 0;
}

// https://www.nowcoder.com/ta/huawei
/*
知识点：
    * map的基本用法
        * pair用法
            * pair<T1, T2> p;
            * pair<T1, T2> p(v1, v2);
            * make_pair(v1, v2)
            * p.first
            * p.second
        * map<k, v> m;
        * m.insert(e)
        * m.erase(k)
        * m.count(k)
        * C++中的map是从小到大排序的
*/
#include<cstdio>
#include<map>
using namespace std;

int main(){
    // freopen("1.txt","r",stdin);
    int x;
    scanf("%d",&x);
    int k,v;
    map<int,int> m;
    for(int i=0;i<x;i++){
        scanf("%d %d",&k,&v);
        if(m.count(k)==0)m[k] = v;
        else m[k] += v;
    }
    for(map<int, int>::iterator iter=m.begin();iter!=m.end();iter++){
        printf("%d %d\n",iter->first,iter->second);
    }
}
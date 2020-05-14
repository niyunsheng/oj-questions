/**
 * @Date:   2018-08-06
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-06
 */
//用map写的看起来很繁琐，大财小用了，其实保存两个结构体数组记录最大最小信息，然后实时更新即可。
#include<iostream>
#include<map>
#include<string>
using namespace std;
struct node{
    string s1;
	string s2;
	node(){}
    node(string ss1,string ss2):s1(ss1),s2(ss2){}
};

int main(){
    //freopen("D:\\CodeBlockSpace\\input.txt","r",stdin);
    int n;
    scanf("%d",&n);
	int t;
    string s1,s2;
    map<int,node> mmap;
    for(int i=0;i<n;i++){
        cin>>s1>>s2>>t;
        mmap[t]=node(s1,s2);
    }
    int mmin=100,mx=0;
	for(map<int,node>::iterator it=mmap.begin();it!=mmap.end();it++){
		if(it->first<mmin)mmin=it->first;
		if(it->first>mx)mx=it->first;
	}
    cout<<mmap[mx].s1<<" "<<mmap[mx].s2<<endl;
	cout<<mmap[mmin].s1<<" "<<mmap[mmin].s2<<endl;
    return 0;
}

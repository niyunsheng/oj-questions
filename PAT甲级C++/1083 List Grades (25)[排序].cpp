/**
 * @Date:   2018-08-08
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-08
 */
//1083 List Grades (25)
//此题太简单了，没有复杂的判断逻辑，就连成绩还告诉你都不同，还只有100个，直接用数组的秩表示分数，排序也不需要，直接按秩输出即可
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//1083 List Grades (25)
struct node{
	bool flag;
	string name,id;
	node():flag(false){}
};
int main(){
	//freopen("D:\\codeBlockSpace\\input.txt","r",stdin);
	int N;
	scanf("%d",&N);
	int grade;
	string name,id;
	vector<node> lists(101);//用grade当做向量的秩
	for(int i=0;i<N;i++){
		cin>>name>>id>>grade;
		lists[grade].name=name;
		lists[grade].id=id;
		lists[grade].flag=true;
	}
	int Lo,Hi;
	scanf("%d %d",&Lo,&Hi);
	int count=0;
	for(int i=Hi;i>=Lo;i--){
		if(lists[i].flag){
			cout<<lists[i].name<<" "<<lists[i].id<<endl;
			count++;
		}
	}
	if(count==0)cout<<"NONE"<<endl;
	return 0;
}

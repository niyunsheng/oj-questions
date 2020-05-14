/**
 * @Date:   2018-08-11
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-11
 */
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
//1039 Course List for Student (25)
//思路:首先建立学生姓名和id（假定1-N，也就是向量的秩）之间的映射，然后按照id存储课程，排序后输出
//采用map建立string到int的映射，最后一组数据过大，超内存限制，所以，应采用字符串hash，即把姓名当做是('Z'-'A'+1)进制,'A'表示0
//另外，数据庞大，不要用cin和cout,尽量不要用cout了
#define MAX (26*26*26*10+1)
int getID(char* ss){//注意，当做26进制也是从高位往低位映射
	int sum=0,r=26;
	for(int i=0;i<3;i++){
		sum=sum*r+ss[i]-'A';
	}
	sum=sum*10+ss[3]-'0';
	return sum;
}

int main(){
	//freopen("D:\\codeBlockSpace\\input.txt","r",stdin);
	int N,K;
	char name[5];
	scanf("%d %d",&N,&K);
	vector<vector<int>> lists(MAX);//每一个学生建立一个选课表,通过hash，每一个名字对应唯一的秩
	for(int i=0;i<K;i++){
		int r,n,id;//课程号、选课人数、学生id
		scanf("%d %d",&r,&n);
		for(int j=0;j<n;j++){
			scanf("%s",name);
			id=getID(name);
			lists[id].push_back(r);
		}
	}
	for(int i=0;i<N;i++){
		scanf("%s",name);
		int id=getID(name);
		sort(lists[id].begin(),lists[id].end());
		//超时的原因在于这里用了cin和cout
		//cout<<name<<" "<<lists[id].size();
		printf("%s %d",name,lists[id].size());
		for(int j=0;j<lists[id].size();j++)
			printf(" %d",lists[id][j]);
	printf("\n");
	}
	return 0;
}

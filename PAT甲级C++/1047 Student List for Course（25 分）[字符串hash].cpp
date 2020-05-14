/**
 * @Date:   2018-08-11
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-11
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//1047 Student List for Course（25 分）
//思路:hash下char[4]和int，这有个好处是字母序和hash序是对应的，所以排序的时候拍int型就好，输出的时候hash逆变换就好
#define MAX (26*26*26*10+1)
int getID(char* ss){//注意，当做26进制也是从高位往低位映射
	int sum=0,r=26;
	for(int i=0;i<3;i++){
		sum=sum*r+ss[i]-'A';
	}
	sum=sum*10+ss[3]-'0';
	return sum;
}
void getname(int n,char* name){//hash逆变换
	name[3]=n%10+'0';
	n/=10;
	for(int i=2;i>=0;i--){
		name[i]=n%26+'A';
		n/=26;
	}
}
int main(){
	//freopen("D:\\codeBlockSpace\\input.txt","r",stdin);
	int N,K;//学生数、课程数
	char name[5];
	scanf("%d %d",&N,&K);
	vector<vector<int>> lists(K+1);//每一个课程建立一个选课表，课程号1-K
	for(int i=0;i<N;i++){
		int r,n,id;//课程号、选课数、学生id
		scanf("%s %d",name,&n);
		id=getID(name);
		for(int j=0;j<n;j++){
			scanf("%d",&r);
			lists[r].push_back(id);
		}
	}
	//按照课程号输出
	for(int i=1;i<=K;i++){
		printf("%d %d\n",i,lists[i].size());
		sort(lists[i].begin(),lists[i].end());
		for(int j=0;j<lists[i].size();j++){
			getname(lists[i][j],name);
			printf("%s\n",name);
		}
	}
	return 0;
}

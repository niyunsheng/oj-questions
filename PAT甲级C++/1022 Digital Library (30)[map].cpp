/**
 * @Date:   2018-08-11
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-11
 */
#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
//1022 Digital Library (30)
/*两个关键点：
	1.用map<string,set<int>>
	2.读取关键词时用scanf(或cin)和getchar交替操作，当getchar收到换行符时，即结束关键词的读取。
	3.注意输出格式，id在读入的时候前面的0省略了，输出的时候加上
	*/
int main(){
	//freopen("D:\\codeBlockSpace\\input.txt","r",stdin);
	int n,m,id;
	vector<map<string,set<int>>> mmap(5);
	scanf("%d",&n);
	string tmp;
	char c;
	for(int i=0;i<n;i++){
		scanf("%d",&id);getchar();
		for(int j=0;j<5;j++){
			if(j==2){
				//注意这里对一行多数据的处理方式
				while(cin>>tmp){
					mmap[j][tmp].insert(id);
					c=getchar();
					if(c=='\n')break;
				}
			}else{
				getline(cin,tmp);
				mmap[j][tmp].insert(id);
			}
		}
	}
	scanf("%d",&m);getchar();
	set<int>::iterator it;
	int r;//查询编号
	string _s;//查询字段
	for(int i=0;i<m;i++){
		scanf("%d: ",&r);
		getline(cin,_s);
		printf("%d: %s\n",r,_s.c_str());
		if(mmap[r-1].count(_s)==0)
			printf("Not Found\n");
		else
			for(it=mmap[r-1][_s].begin();it!=mmap[r-1][_s].end();it++){
				printf("%07d\n",*it);
			}
	}
	return 0;
}

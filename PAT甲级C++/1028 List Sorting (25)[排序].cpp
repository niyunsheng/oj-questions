/**
 * @Date:   2018-08-08
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-27
 */
/*思路：
三个数据都用string存储会超时，改用不同的类型存储
特别注意，name.c_str()，这样就可以用%s输出了
改为并不都是string后还是超时，感觉是cin太慢，string如何用scanf读取：要预先分配空间string a;a.resize(100); //需要预先分配空间scanf("%s", &a[0]);
感觉这个预先分配空间太麻烦了，就用了两次scanf和一次cin，过了
最后，为了省心，还是直接用char字符串和strcmp函数最省事,注意strcmp(char* a,char* b),a<b时返回负值，相等返回0，a>b返回正值
如果编译找不到strcmp，注意包含cstring头文件
*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//1028 List Sorting (25)

int N,C;
struct node{
	int id,score;
	char name[10];
};
bool cmp(node& a,node& b){
	switch(C){
	case 1:return a.id<b.id;break;
	case 2:return strcmp(a.name,b.name)<0||(strcmp(a.name,b.name)==0&&a.id<b.id);
	case 3:return a.score<b.score||(a.score==b.score&&a.id<b.id);
	}
}
int main(){
	//freopen("D:\\input.txt","r",stdin);
	scanf("%d %d",&N,&C);
	vector<node> STU(100001);
	for(int i=0;i<N;i++){
		scanf("%d %s %d",&STU[i].id,STU[i].name,&STU[i].score);
		//cin>>STU[i].id>>STU[i].name>>STU[i].score;
	}
	sort(STU.begin(),STU.begin()+N,cmp);
	for(int i=0;i<N;i++)
		printf("%06d %s %d\n",STU[i].id,STU[i].name,STU[i].score);
	return 0;
}

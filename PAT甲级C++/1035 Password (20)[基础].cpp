/**
 * @Date:   2018-08-07
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-15
 */
//1035 Password (20)
//这个题目的坑在于没有修改的时候输出的单词居然还有单复数不同，刚开始没看到，错了不知道原因
#include<cstdio>
#include<cstring>
using namespace std;

#define MAX  1010
char name[MAX][12];
char password[MAX][12];
bool inllegal[MAX];
int ans[MAX];
int main(){
	//freopen("D:\\codeBlockSpace\\input.txt","r",stdin);
	int n,len;
	int top=0;//改变的密码总数
	scanf("%d",&n);
	memset(inllegal,0,sizeof(inllegal));
	for(int i=0;i<n;i++){
		scanf("%s %s",name+i,password+i);
		len=strlen(password[i]);
		for(int j=0;j<len;j++){
			switch(password[i][j]){
			case '1':inllegal[i]=true;password[i][j]='@';break;
			case '0':inllegal[i]=true;password[i][j]='%';break;
			case 'l':inllegal[i]=true;password[i][j]='L';break;
			case 'O':inllegal[i]=true;password[i][j]='o';break;
			default:break;
			}
		}
		if(inllegal[i])ans[top++]=i;
	}
	if(top==0){
		if(n==1)
			printf("There is 1 account and no account is modified");
		else
			printf("There are %d accounts and no account is modified",n);
	}else printf("%d\n",top);
	for(int i=0;i<top;i++){
		printf("%s %s\n",name[ans[i]],password[ans[i]]);
	}
	return 0;
}

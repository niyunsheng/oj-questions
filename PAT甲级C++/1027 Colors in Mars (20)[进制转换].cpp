/**
 * @Date:   2018-08-06
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-06
 */
//此题非常基础了
#include<iostream>
#include<vector>
using namespace std;

int main(){
    //freopen("D:\\CodeBlockSpace\\input.txt","r",stdin);
	int r[3];
	scanf("%d %d %d",r,r+1,r+2);
	char digit[13]={'0','1','2','3','4','5','6','7','8','9','A','B','C'};
	vector<vector<int>> s(3,vector<int>(2,0));
	for(int i=0;i<3;i++){
		int top=0;
		while(r[i]>0){
			s[i][top++]=(r[i]%13);
			r[i]/=13;
		}
	}
	printf("#");
	for(int i=0;i<3;i++)
		for(int j=1;j>=0;j--)
			printf("%c",digit[s[i][j]]);
	return 0;
}

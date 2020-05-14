/**
 * @Date:   2018-08-09
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-09
 */
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//1041 Be Unique (20)

int main(){
	//freopen("d:\\codeBlockSpace\\input.txt","r",stdin);
	int n;
	scanf("%d",&n);
	int people[100001]={0};
	int bets[10001]={0};//该数字还没有被猜过
	for(int i=0;i<n;i++){
		scanf("%d",people+i);
		bets[people[i]]++;
	}
	bool flag=false;
	for(int i=0;i<n;i++)
		if(bets[people[i]]==1){
			printf("%d\n",people[i]);
			flag=true;
			break;
		}
	if(!flag)printf("None\n");
	return 0;
}

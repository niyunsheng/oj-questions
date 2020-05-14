/**
 * @Date:   2018-08-09
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-29
 */
 //1067 Sort with Swap(0,*) (25)
/*思路：两种方法：
1.模拟交换，注意元素的存储是记录各个元素位置的方式
2.并查集：计算并查集的数目，注意分初试时0是否在原位置两个情况
*/

//方法一：模拟交换
#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	//freopen("d:\\input.txt","r",stdin);
    int n,cnt=0,t;
    scanf("%d",&n);
	vector<int> pos(n);
    for(int i=0;i<n;i++){cin>>t;pos[t]=i;}
    for(int i=1;i<n;i++) {
        while(pos[0]!=0) {
            swap(pos[0],pos[pos[0]]);
            cnt++;
        }
        if(i != pos[i]) {
            swap(pos[0],pos[i]);
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
//方法二：并查集
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	//freopen("d:\\input.txt","r",stdin);
	int n;
	scanf("%d",&n);
	vector<int> lists(n);
	for(int i=0;i<n;i++)
		scanf("%d",&lists[i]);
	vector<bool> vis(n,false);
	int sum=0;//并查集的数目
	int local=0;//在自己位置的元素数目
	int flag=false;//0是否在0位置
	if(lists[0]==0)flag=true;
	for(int i=0;i<n;i++){
		if(!vis[i]){
			if(lists[i]==i){local++;continue;}
			sum++;
			vis[i]=true;
			int next=lists[i];
			while(!vis[next]){
				vis[next]=true;
				next=lists[next];
			}
		}
	}
	if(flag){
		printf("%d",n-local+sum);
	}else{
		printf("%d",n-local+sum-2);
	}
	return 0;
}

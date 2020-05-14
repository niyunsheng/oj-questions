/**
 * @Date:   2018-08-10
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-09-03
 */
//1029 Median（25 分）
//不能直接排序，会超时，应该用双指针，模拟归并过程
//总结，只要思路清晰，本题还是很容易得满分的，归并的思路：小的先归并，如果某一方到达终点，只归并另一方即可
//如果在每一个序列后面添加inf，则可以方便流程控制，不用考虑一个序列输出完毕的情况。
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	//freopen("d:\\codeBlockSpace\\input.txt","r",stdin);
	int m,n,t;
	scanf("%d",&m);
	vector<int> vec;
	for(int i=0;i<m;i++){scanf("%d",&t);vec.push_back(t);}
	scanf("%d",&n);
	int i=0,j=0;//分别表示两个序列的指针
	int k=0,mi=((n+m)%2)?((n+m)/2):((n+m)/2-1);//归并开始指针、目标指针
	//对于奇数而言，中位数即为(n+m)/2,对于偶数而言，中位数为(n+m)/2-1，更简便的写法是(n+m-1)/2
	int target;
	if(n==0){
		target=vec[mi];
	}else{

		for(;j<n;j++){
			scanf("%d",&t);
			while(i<m&&t>=vec[i]&&k<=mi){//相等的情况必须归于其中一类
				if(k==mi){target=vec[i];break;}
				i++;k++;
			}
			if(i==m||t<vec[i]){
				if(k==mi){target=t;break;}
				k++;
			}
		}
		//缺少处理s2数列先读取完的情况
		while(j==n||(i<m&&t>=vec[i]&&k<=mi)){//相等的情况必须归于其中一类
			if(k==mi){target=vec[i];break;}
			i++;k++;
		}
	}

	cout<<target;
	return 0;
}
//有两个测试点内存超限，换了柳神的代码
#include <iostream>
using namespace std;
int k[200005];
int main(){
    int n, m, temp, count = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        scanf("%d", &k[i]);
    k[n + 1] = 0x7fffffff;
    cin >> m;
    int midpos = (n + m + 1) / 2, i = 1;
    for (int j = 1; j <= m; j++) {
        scanf("%d", &temp);
        while (k[i] < temp) {
            count++;
            if (count == midpos) cout << k[i];
            i++;
        }
        count++;
        if (count == midpos) cout << temp;
    }
    while (i <= n) {
        count++;
        if (count == midpos) cout << k[i];
        i++;
    }
    return 0;
}

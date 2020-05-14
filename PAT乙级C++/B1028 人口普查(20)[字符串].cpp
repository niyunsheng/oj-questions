/**
 * @Date:   2018-08-06
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-06
 */
//虽然答案不是字符串比较，而是存数字标记，显然，字符串比价更简洁
#include<iostream>
#include<string>
using namespace std;

int main(){
    //freopen("D:\\CodeBlockSpace\\input.txt","r",stdin);
    int n;
    scanf("%d",&n);
    string s1,s2;

	string lo="1814/09/06",hi="2014/09/06";
	string mmin=hi,mx=lo;
	string namelo,namehi;
	int sum=0;
	for(int i=0;i<n;i++){
        cin>>s1>>s2;
		if(s2<lo||s2>hi)continue;
		sum++;
		if(s2<mmin){mmin=s2;namelo=s1;}
		if(s2>mx){mx=s2;namehi=s1;}
    }
	if(sum==0)cout<<sum<<endl;
    else cout<<sum<<" "<<namelo<<" "<<namehi<<endl;
    return 0;
}

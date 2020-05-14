/**
 * @Date:   2018-08-10
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-29
 */
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
//1010 Radix (25)
//注意进制的取值范围，最小比字符串中最大字符大一，最大是字符串m1的值与36的最大值
int char2int(char c){
	if(c>='0'&&c<='9')return c-'0';
	else return c-'a'+10;
}
int main(){
	//freopen("d:\\input.txt","r",stdin);
	string s1,s2;
	int tag,radix;
	cin>>s1>>s2>>tag>>radix;
	//假设radix是n1的进制，如果tag=2就交换下n1,n2即可
	if(tag==2)swap(s1,s2);
	int n1=s1.size(),n2=s2.size();
	long long m1=0,m2=0;//分别表示两个数字的十进制的值
	for(int i=0;i<n1;i++)
		m1=m1*radix+char2int(s1[i]);
	//下面的lo不能为2，至少要是出现的最下字母大一,注意max_element的使用
	//注意了，这里的lo,mi,hi都得是longlong类型
	long long lo=char2int(*max_element(s2.begin(),s2.end()))+1,hi=(36>m1?36:m1)+1,mi;//表示进制，这里的hi并不是36，还可以更大，可以取m1和36中较大的数,注意了，这里要再加1，比如n1是345，n2是10，当n2是345进制时，n2的十进制数就是345
	bool flag=false;//表示未找到相同的
	//注意这里的进制还可能相同，比如一位数1，在任何进制下都是1，所以，要返回等于的最小值，并且等于时做标记
	while(lo<hi){
		//当lo<hi时进入循环，mid可以取到的范围是[lo,hi)，所以，之前的进制最大应该是m1,而hi的取值应该m1+1
		mi=(lo+hi)/2;
		m2=0;
		for(int i=0;i<n2;i++){
			m2=m2*mi+char2int(s2[i]);
			if(m2<0){
				break;
			}
		}
		//因为要输出小于等于，所以，等于不单独判断
		if(m2==m1){flag=true;}
		if(m2>=m1||m2<0)hi=mi;
		else lo=mi+1;
	}
	if(!flag)printf("Impossible");
	else printf("%lld",hi);
	return 0;
}

//重要：去除前导0，定位以一个有效数字，定位小数点，然后就是逻辑判断，仔细输出了
 /*
 容易出错的数据有：这种题目不给这种出错算例的话，可能根本想不到还会有这样的边界条件出现
 4 00 00.00
 4 0012.2300 001223
 4 12.23 122.34
 */
 #include <iostream>
 #include"string.h"
 using namespace std;
 int main()
 {
     //freopen("d:\\codeBlockSpace\\input.txt","r",stdin);
     int n,na=0,nb=0;
     string a,b;
     while(cin>>n>>a>>b){
     int* vec_a=new int[n];memset(vec_a,0,n*sizeof(int));
     int* vec_b=new int[n];memset(vec_b,0,n*sizeof(int));

     int i,k;//分别表示有效数字第一位、最后一位和小数点位置
     //定位到第一个有效数字
     i=0;while(i<a.size()&&(a[i]=='0'||a[i]=='.'))i++;
     if(i==a.size()){
             na=0;
     }else{
         //定位小数点
         k=0;while(k<a.size()&&a[k]!='.')k++;
         na=k-i;if(na<0)na++;
     }
     //将有效位数保存到数组
     for(int j=0;i<a.size()&&j<n;i++,j++)
         if(a[i]!='.')vec_a[j]=a[i]-'0';
         else j--;

     //定位到第一个有效数字
     i=0;while(i<b.size()&&(b[i]=='0'||b[i]=='.'))i++;
     if(i==b.size()){
         nb=0;
     }else{
         //定位小数点
         k=0;while(k<b.size()&&b[k]!='.')k++;
         nb=k-i;if(nb<0)nb++;
     }
     //将有效位数保存到数组
     for(int j=0;i<b.size()&&j<n;i++,j++)
         if(b[i]!='.')vec_b[j]=b[i]-'0';
         else j--;

     bool equal=true;
     for(int i=0;i<n;i++)
         if(vec_a[i]!=vec_b[i]){equal=false;break;}
     if(na!=nb||!equal){
         printf("NO 0.");
         for(int i=0;i<n;i++)printf("%d",vec_a[i]);
         printf("*10^%d 0.",na);
         for(int i=0;i<n;i++)printf("%d",vec_b[i]);
         printf("*10^%d\n",nb);
     }else{
         printf("YES 0.");
         for(int i=0;i<n;i++)printf("%d",vec_a[i]);
         printf("*10^%d\n",na);
     }

     }
     return 0;
 }

//新的代码，20190221，相比原代码采用数组和多个指针的方式，新的算法思路更加清晰简洁
#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

#define _for(i,lo,hi) for(int i=(lo);i<(hi);i++)
#define inf 0x3fffffff
#define pb push_back
typedef long long LL;
#define M 1000000007
#define N 100

int n;//表示科学计数法的位数
void fun(string& str,vector<int>& v,int& index){


	int i=0;
	while(i<str.size()&&str[i]=='0')i++;//去除前导0
	if(i==str.size()){//说明此数为0
		index=0;
	}else if(str[i]=='.'){//纯小数
		int t=i;
		i++;
		while(i<str.size()&&str[i]=='0')i++;
		if(i==str.size())index=0;
		else{
			index=t-i+1;
			for(;i<str.size()&&v.size()<n;i++)
				v.push_back(str[i]-'0');
		}
	}else{
		int node=str.find(".");
		if(node<0)node=str.size();
		index=node-i;
		for(;i<str.size()&&v.size()<n;i++){
			if(i==node)continue;
			v.push_back(str[i]-'0');
		}
	}
	while(v.size()<n)v.push_back(0);
}

bool equal(vector<int>& v1,int& index1,vector<int>& v2,int& index2){
	if(index1!=index2)return false;
	_for(i,0,n)if(v1[i]!=v2[i])return false;
	return true;
}
int main(int argc, char** argv) {
	//freopen("d:\\input.txt","r",stdin);

	string str1,str2;
	cin>>n>>str1>>str2;
	vector<int> v1,v2;//表示两个数字的小数位和指数位
	int index1,index2;
	fun(str1,v1,index1);
	fun(str2,v2,index2);
	if(equal(v1,index1,v2,index2)){
		printf("YES 0.");
		_for(i,0,n)printf("%d",v1[i]);
		printf("*10^%d",index1);
		printf("\n");
	}else{
		printf("NO");
		printf(" 0.");
		_for(i,0,n)printf("%d",v1[i]);
		printf("*10^%d",index1);

		printf(" 0.");
		_for(i,0,n)printf("%d",v2[i]);
		printf("*10^%d",index2);
	}
	return 0;
}

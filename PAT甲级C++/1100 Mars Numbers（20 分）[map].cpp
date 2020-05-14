/**
 * @Date:   2018-08-11
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-11
 */
#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
using namespace std;
//1100 Mars Numbers（20 分）
//思路:用map建立字符串到int的映射，用数组建立int到字符串的映射即可
//通过示例可知，火星文高低位是混在一块的
//本题解题关键在于读懂题目，PAT的很多示例需要自己去想，比如本题中末尾的0是不输出的
//晴神思路：由于只有169种情况，可以直接预处理把所有的情况存起来，即打表，然后查询时直接查表即可。两种特殊情况的处理：十位为0，个位为0.
char A[26][5]={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
int main(){
	//freopen("D:\\codeBlockSpace\\input.txt","r",stdin);
	int n;
	scanf("%d",&n);getchar();
	map<string,int> Amap;
	for(int i=0;i<26;i++){
		Amap[A[i]]=i;
	}
	string tmp;
	bool flag;//true表明接收到的是地球文
	int m;//接收到的字符串长度
	for(int i=0;i<n;i++){
		getline(cin,tmp);//cout<<tmp<<endl;
		m=tmp.size();
		if(tmp[0]>='0'&&tmp[0]<='9')flag=true;else flag=false;
		if(flag){
			int a,b;//高位、低位
			sscanf(tmp.c_str(),"%d",&a);
			if(a<13){
				printf("%s\n",A[a]);
			}else{
				b=a%13;
				a/=13;
				if(b==0)printf("%s\n",A[a+12]);
				else printf("%s %s\n",A[a+12],A[b]);
			}
		}else{
			switch(m){
			case 3:
			case 4:
				if(Amap[tmp]>12)printf("%d\n",(Amap[tmp]-12)*13);
				else printf("%d\n",Amap[tmp]);
				break;
			case 7:
				//cout<<tmp.substr(0,3)<<"###"<<tmp.substr(4,m-4)<<endl;
				//cout<<Amap[tmp.substr(0,3)]<<"##"<<Amap[tmp.substr(4,m-4)]<<endl;
				printf("%d\n",(Amap[tmp.substr(0,3)]-12)*13+Amap[tmp.substr(4,m-4)]);
				break;
			}
		}
	}

	return 0;
}

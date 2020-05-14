/**
 * @Date:   2018-08-15
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-27
 */
#include<iostream>
#include<cstring>
using namespace std;
//1082 Read Number in Chinese (25)
/*整体思路：每四位为一节，一节结束后要不要输出单位要看该节是否全部为0，因为只有9位，所以，只考虑‘万’节部分是否输出零或者单位。
此题目的输出规则复杂，想要正确得理解什么时候要输出中间0什么时候不需要
1每一节（亿万个节）某个非零位的高位为0，则需要多输出一个0，千位除外
2每节的末尾要视情况输出万或者亿
	

	本题需要不断的自己测试，找到漏洞，然后修补
	其实，自己最开始做不出来的原因在于对于什么时候输出0不明确，那就是是否有累计0的存在以及当前位不为0，要考虑万节全部为0的特殊情况。
*/
#define MAX 10
char digit[MAX][10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
char wei[3][5]={"Shi","Bai","Qian"};
char num[12];
int main(){
	//freopen("D:\\codeBlockSpace\\input.txt","r",stdin);
	//while(1){
	scanf("%s",num);
	int n=strlen(num);
	int lo=0,hi=n-1;//用做每一节的坐标[lo,hi]
	bool front=false;//表示首位未输出
	if(num[0]=='-'){printf("Fu");lo++;front=true;}
	//分三节分别写程序，处理亿单位节
	if(n-lo==9){
		if(front)printf(" ");
		printf("%s Yi",digit[num[lo]-'0']);
		front=true;
		lo++;
	}
	bool flag,hasnum;//表示不存在累计的0
	while(lo<=hi-4){hi-=4;}
	//处理万节
	if(n-hi==5){
		flag=false;//表示没有累计的0
		hasnum=false;//表示该节还没有数字输出
		while(lo<=hi){
			if(num[lo]=='0')
				flag=true;
			else{
				hasnum=true;

				if(front)printf(" ");
				front=true;
				if(flag){printf("ling ");flag=false;}
				if(hi==lo){printf("%s",digit[num[lo]-'0']);}
				else printf("%s %s",digit[num[lo]-'0'],wei[hi-lo-1]);

			}
			if(hi==lo){
				if(hasnum)printf(" Wan");
			}
			lo++;
		}
	}
	//处理最低节
	hi=n-1;
	//flag=false;//表示没有累计的0,注意，这里的flag并不需要更新，因为万位全部为0的情况下，个位有数字输出的话，也是要先输出0的
	while(lo<=hi){
		if(num[lo]=='0'){
			flag=true;
			if(!front)printf("ling");
		}else{
			if(front)printf(" ");
			front=true;
			if(flag){printf("ling ");flag=false;}
			if(hi==lo)printf("%s",digit[num[lo]-'0']);
			else printf("%s %s",digit[num[lo]-'0'],wei[hi-lo-1]);
		}
		lo++;
	}
	//}
	return 0;
}

/**
 * @Date:   2018-08-07
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-07
 */
//本题首先要注意的就是输入整行数据的方法
//VS不能输入输出string的原因在于没有包含<string>，而不是<cstring>，注意这三个头文件的区别
/*
<string.h>是C版本的头文件，包含比如strcpy、strcat之类的字符串处理函数。
<cstring>在C++标准化(1998年)过程中，为了兼容以前，标准化组织将所有这些文件都进行了新的定义，加入到了标准库中，加入后的文件名就新增了一个"c"前缀并且去掉了.h的后缀名，所以string.h头文件成了cstring头文件。但是其实现却是相同的或是兼容以前的，这就是<cstring>的来源，不要觉得又多了一个东西。相当于标准库组织给它盖了个章，说“你也是我的标准程序库的一份子了”。
<string>是C++标准定义的头文件，它定义了一个string的字符串类，里面包含了string类的各种操作，如s.size(), s.erase(), s.insert()等。但<string>又包含了老的C版本的字符串操作如strcpy、strcat等，这就相当于，在<string>的文件中除了定义自己的string类之外，还加了一个#include<string.h>一句包含了C版本的字符串操作。
*/
#include<iostream>
#include<cstring>
using namespace std;

int main(){
	//freopen("D:\\codeBlockSpace\\input.txt","r",stdin);
	int n,r1,r2;
	int top=0;
	string str1,str2;
	scanf("%d\n",&n);//这里加入\n才会把后面的回车录入

	getline(cin,str1);//输入带空格的方法
	//cout<<str1<<endl;
    int lo=-1;//以str1作为标准，各个字符串之间相同的值为(lo,hi)
    for(int i=1;i<n;i++){
        getline(cin,str2);
        //cout<<str2<<endl;
        r1=str1.size()-1;
        r2=str2.size()-1;
        while(r1>lo&&r2>=0&&str1[r1]==str2[r2]){r1--;r2--;}
        if(r1>lo)lo=r1;
    }
    if(r1==str1.size()-1)cout<<"nai";
    else cout<<str1.substr(r1+1,str1.size());
	return 0;
}

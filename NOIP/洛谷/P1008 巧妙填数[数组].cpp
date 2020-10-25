/**
 * @Date:   2018-07-30
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-01
 */
/*
题目描述
将 1,2,⋯,91,2, \cdots ,91,2,⋯,9 共 999 个数分成 333 组，分别组成 333 个三位数
且使这 333 个三位数构成 1:2:31:2:31:2:3 的比例，试求出所有满足条件的 333 个三位数。
*/
  #include <iostream>

  using namespace std;

  //为啥不用思路2：全排列需要用到“深度优先搜索”，这是《算法》部分
  //思路1：首先满足倍数关系，然后再判断是否数字都不同
  //思路2：首先数字都不同，相当于全排列，然后再判断是否满足倍数关系
  int main()
  {
      //三个数，123，1000
      int a=123;
      while(3*a<1000){
 		 //a 2a 3a
          //这里判断a是否符合条件：a\2a\3a数字都不相同
          //提取各位数字，a/100,a%100/10,a%10
          /*判断思路1：得到9个数字，存到num[9],写循环判断各不相同，写一个嵌套双重循环
 		 int flag=0;
          for(int i=0;i<9;i++){
 		 	if(num[i]==0){flag=1;break;}
 		 	for(int j=i+1;j<9;j++){
 				if(a[i]==a[j]){flag=1;break;}
 			}
 	 	}
 		if(flag==0)说明a满足条件,加入到答案当中
 		else 不满足
          */
 		 /*判断思路2：得到9个数字，存到num[9]；
 		 建一个判断数组，bool exist[10],初始化所有元素为false，当存在时置true,1是true，0是false
 		 //先初始化	exist[1]=false表示数字1不存在，=true表示存在
 		 &&与
 		 ||或
 		 ！取反
 		 int flag=0;
 		 for(int i=0;i<9;i++){
 		 	//判断num[i]是否存在
 			if(!exist[num[i]])exist[num[i]]=true;
 			else {flag=1;break;}
 	 	}

 		 */
          //123\124\125……
          a++;
      }

      return 0;
  }

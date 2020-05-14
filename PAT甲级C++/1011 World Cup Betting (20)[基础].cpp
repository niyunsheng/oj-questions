/**
 * @Date:   2018-08-06
 * @Email:  ni-ys13@qq.com
 * @Last modified time: 2018-08-06
 */
 #include<iostream>
 #include<vector>
 using namespace std;
 //题目很简单，可以说PAT甲级20分题目都是送分的，就是读题读了20分才基本读懂
 int main(){
     freopen("D:\\CodeBlockSpace\\input.txt","r",stdin);
 	float a,b,c;
 	float ans=0.65;
 	for(int i=0;i<3;i++){
 		scanf("%f %f %f",&a,&b,&c);
 		if(a>b&&a>c){printf("W ");ans*=a;}
 		if(a<b&&b>c){printf("T ");ans*=b;}
 		if(c>b&&a<c){printf("L ");ans*=c;}
 	}
 	printf("%.2f",(ans-1)*2+0.005);
 	return 0;
 }
